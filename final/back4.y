%{                          // SECCION 1 Declaraciones de C-Yacc

#include <stdio.h>
#include <ctype.h>            // declaraciones para tolower
#include <string.h>           // declaraciones para cadenas
#include <stdlib.h>           // declaraciones para exit ()

#define FF fflush(stdout);    // para forzar la impresion inmediata

int yylex () ;
int yyerror () ;
char *mi_malloc (int) ;
char *gen_code (char *) ;
char *int_to_string (int) ;
char *char_to_string (char) ;

char temp [2048] ;

// Abstract Syntax Tree (AST) Node Structure

typedef struct s_attr {
        int value ;
        char *code ;
} t_attr ;

// Tabla de símbolos para diferenciar entre variables locales y globales
struct symbol {
    char name[50];
    char scope[50];
};

#define YYSTYPE t_attr

%}

// Definitions for explicit attributes

%token NUMBER        
%token IDENTIF       // Identificador=variable
%token INTEGER       // identifica el tipo entero
%token STRING
%token SETQ SETF DEFUN MAIN LOOP WHILE DO IF ELSE THEN PROGN
%token PRINT PRIN1 AREF MOD AND OR NOT NEQ LEQ GEQ RETURN FROM



%right '='                    // es la ultima operacion que se debe realizar
%left OR
%left AND
%left EQ NEQ
%left '<' '>' LEQ GEQ
%left '+' '-'                 // menor orden de precedencia
%left '*' '/'                 // orden de precedencia intermedio
%left UNARY_SIGN              // mayor orden de precedencia

%%                            // Seccion 3 Gramatica - Semantico

axioma: programa_principal { ; };

programa_principal: declaracion programa_principal { ; }
    | funcion programa_principal { ; }
    | main_func programa_principal { ; }
    | /* lambda */ { ; }
    ;

declaracion: '(' SETQ IDENTIF valor ')' { printf("variable %s\n%s %s !\n", $3.code, $4.code, $3.code); $$.code = gen_code(temp) ; }
    | '(' SETQ IDENTIF '(' "make-arrayç" NUMBER ')' ')' { printf("variable %s\ncreate %s %s cells allot\n", $3.code, $3.code, $6.code) ; }
    ;

valor: NUMBER { sprintf(temp, "%d", $1.value); $$.code = gen_code(temp) ; }
    | STRING { $$.code = $1.code; }
    ;

funcion: '(' DEFUN IDENTIF '(' lista_parametros ')' cuerpo ')' { printf(": %s ( %s -- retorno )\n%s ;\n", $3.code, $5.code, $7.code); }
    ;

lista_parametros: /* lambda */ { $$.code = gen_code(""); }
    | IDENTIF lista_parametros { sprintf(temp, "%s %s", $1.code, $2.code); $$.code = gen_code(temp); }
    ;

main_func: '(' DEFUN MAIN '(' ')' cuerpo ')' '(' MAIN ')' { printf(": main\n%s ;\nmain\n", $6.code) ; }
    ;

cuerpo: sentencias { $$.code = $1.code; }
    ;

sentencias: sentencia sentencias { sprintf(temp, "%s\n%s", $1.code, $2.code); $$.code = gen_code(temp) ; }
    | sentencia { $$.code = $1.code; }
    ;

sentencia: '(' SETQ IDENTIF expresion ')' { sprintf(temp, "variable %s\n%s %s !", $3.code, $4.code, $3.code); $$.code = gen_code(temp); }
    | '(' SETF IDENTIF expresion ')' { sprintf(temp, "%s %s !", $4.code, $3.code); $$.code = gen_code(temp); }
    | '(' SETF '(' AREF IDENTIF expresion ')' expresion ')' { sprintf(temp, "%s %s %s [] !", $8.code, $6.code, $5.code); $$.code = gen_code(temp); }
    | '(' PRINT STRING ')' { sprintf(temp, ".\" %s\" cr", $3.code); $$.code = gen_code(temp); }
    | '(' PRIN1 expresion ')' { if ($3.code[0] == '"') { sprintf(temp, ".\" %s cr", $3.code + 1); temp[strlen(temp)] = '\0'; } else { sprintf(temp, "%s .", $3.code); } $$.code = gen_code(temp); }
    | '(' RETURN '-' FROM IDENTIF expresion ')' { sprintf(temp, "%s", $6.code); $$.code = gen_code(temp); }
    | llamada_funcion
    | expresiones_loop
    | expresiones_if
    | '(' PROGN sentencias ')' { $$.code = $3.code; }
    ;

llamada_funcion: '(' IDENTIF ')' { sprintf(temp, "%s", $2.code); $$.code = gen_code(temp); }
    | '(' IDENTIF lista_expresiones ')' { sprintf(temp, "%s %s", $2.code, $3.code); $$.code = gen_code(temp); }
    ;

lista_expresiones: expresion { $$.code = $1.code; }
    | expresion lista_expresiones { sprintf(temp, "%s %s", $1.code, $2.code); $$.code = gen_code(temp); }
    ;

expresiones_loop: '(' LOOP WHILE condicion DO sentencias ')' { sprintf(temp, "begin %s while %s repeat", $4.code, $6.code); $$.code = gen_code(temp); }
    ;

expresiones_if: '(' IF condicion sentencias ')' { sprintf(temp, "%s if %s then", $3.code, $4.code); $$.code = gen_code(temp); }
    | '(' IF condicion sentencias ELSE sentencias ')' { sprintf(temp, "%s if %s else %s then", $3.code, $4.code, $6.code); $$.code = gen_code(temp); }
    ;

condicion: expresion { $$.code = $1.code; }
    ;

expresion: termino { $$.code = $1.code; }
    | expresiones_aritmeticas
    | llamada_funcion
    | expresiones_logicas
    | expresiones_compuestas
    | expresiones_array
    ;

expresiones_aritmeticas: '(' '+' expresion expresion ')' { sprintf(temp, "%s %s +", $3.code, $4.code); $$.code = gen_code(temp); }
    | '(' '-' expresion expresion ')' { sprintf(temp, "%s %s -", $3.code, $4.code); $$.code = gen_code(temp); }
    | '(' '*' expresion expresion ')' { sprintf(temp, "%s %s *", $3.code, $4.code); $$.code = gen_code(temp); }
    | '(' '/' expresion expresion ')' { sprintf(temp, "%s %s /", $2.code, $3.code); $$.code = gen_code(temp); }
    | '(' MOD expresion expresion ')' { sprintf(temp, "%s %s mod", $3.code, $4.code); $$.code = gen_code(temp); }
    ;

expresiones_logicas: '(' AND expresion expresion ')' { sprintf(temp, "%s %s and", $3.code, $4.code); $$.code = gen_code(temp); }
    | '(' OR expresion expresion ')' { sprintf(temp, "%s %s or", $3.code, $4.code); $$.code = gen_code(temp); }
    | '(' NOT expresion ')' { sprintf(temp, "%s 0=", $3.code); $$.code = gen_code(temp); }
    ;

expresiones_compuestas: '(' NEQ expresion expresion ')' { sprintf(temp, "%s %s <>", $3.code, $4.code); $$.code = gen_code(temp); }
    | '(' '=' expresion expresion ')' { sprintf(temp, "%s %s =", $3.code, $4.code); $$.code = gen_code(temp); }
    | '(' '<' expresion expresion ')' { sprintf(temp, "%s %s <", $3.code, $4.code); $$.code = gen_code(temp); }
    | '(' '>' expresion expresion ')' { sprintf(temp, "%s %s >", $3.code, $4.code); $$.code = gen_code(temp); }
    | '(' LEQ expresion expresion ')' { sprintf(temp, "%s %s <=", $3.code, $4.code); $$.code = gen_code(temp); }
    | '(' GEQ expresion expresion ')' { sprintf(temp, "%s %s >=", $3.code, $4.code); $$.code = gen_code(temp); }
    ;

expresiones_array: '(' AREF IDENTIF expresion ')' { sprintf(temp, "%s %s [] @", $4.code, $3.code); $$.code = gen_code(temp); }
    ;

termino: IDENTIF { sprintf(temp, "%s @", $1.code); $$.code = gen_code(temp); }
    | NUMBER { sprintf(temp, "%d", $1.value); $$.code = gen_code(temp); }
    | STRING { sprintf(temp, "\"%s\"", $1.code); $$.code = gen_code(temp); }
    ;

%%                            // SECCION 4    Codigo en C

int n_line = 1 ;

int yyerror (mensaje)
char *mensaje ;
{
    fprintf (stderr, "%s en la linea %d\n", mensaje, n_line) ;
    printf ( "\n") ;	// bye
}

char *int_to_string (int n)
{
    sprintf (temp, "%d", n) ;
    return gen_code (temp) ;
}

char *char_to_string (char c)
{
    sprintf (temp, "%c", c) ;
    return gen_code (temp) ;
}

char *my_malloc (int nbytes)       // reserva n bytes de memoria dinamica
{
    char *p ;
    static long int nb = 0;        // sirven para contabilizar la memoria
    static int nv = 0 ;            // solicitada en total

    p = malloc (nbytes) ;
    if (p == NULL) {
        fprintf (stderr, "No queda memoria para %d bytes mas\n", nbytes) ;
        fprintf (stderr, "Reservados %ld bytes en %d llamadas\n", nb, nv) ;
        exit (0) ;
    }
    nb += (long) nbytes ;
    nv++ ;

    return p ;
}


/***************************************************************************/
/********************** Seccion de Palabras Reservadas *********************/
/***************************************************************************/

typedef struct s_keyword { // para las palabras reservadas de C
    char *name ;
    int token ;
} t_keyword ;

t_keyword keywords [] = { // define las palabras reservadas y los
    "main",        MAIN,
    "defun",       DEFUN,
    "princ",       PRIN1,  // princ es equivalente a prini en Forth (imprime sin salto)
    "print",       PRINT,
    "setq",        SETQ,
    "setf",        SETF,
    "loop",        LOOP,
    "while",       WHILE,
    "do",          DO,
    "if",          IF,
    "else",        ELSE,
    "then",        THEN,
    "progn",       PROGN,
    "aref",        AREF,
    "mod",         MOD,
    "and",         AND,
    "or",          OR,
    "not",         NOT,
    "/=",          NEQ,
    "=",           EQ,
    "<=",          LEQ,
    ">=",          GEQ,
    "return",      RETURN,
    "from",        FROM,
    NULL,          0
} ;

t_keyword *search_keyword (char *symbol_name)
{                                  // Busca n_s en la tabla de pal. res.
                                   // y devuelve puntero a registro (simbolo)
    int i ;
    t_keyword *sim ;

    i = 0 ;
    sim = keywords ;
    while (sim [i].name != NULL) {
	    if (strcmp (sim [i].name, symbol_name) == 0) {
		                             // strcmp(a, b) devuelve == 0 si a==b
            return &(sim [i]) ;
        }
        i++ ;
    }

    return NULL ;
}

 
/***************************************************************************/
/******************* Seccion del Analizador Lexicografico ******************/
/***************************************************************************/

char *gen_code (char *name)     // copia el argumento a un
{                                      // string en memoria dinamica
    char *p ;
    int l ;
	
    l = strlen (name)+1 ;
    p = (char *) my_malloc (l) ;
    strcpy (p, name) ;
	
    return p ;
}


int yylex ()
{
// NO MODIFICAR ESTA FUNCION SIN PERMISO
    int i ;
    unsigned char c ;
    unsigned char cc ;
    char ops_expandibles [] = "!<=|>%&/+-*" ;
    char temp_str [256] ;
    t_keyword *symbol ;

    do {
        c = getchar () ;

        if (c == '#') {	// Ignora las lineas que empiezan por #  (#define, #include)
            do {		//	OJO que puede funcionar mal si una linea contiene #
                c = getchar () ;
            } while (c != '\n') ;
        }

        if (c == '/') {	// Si la linea contiene un / puede ser inicio de comentario
            cc = getchar () ;
            if (cc != '/') {   // Si el siguiente char es /  es un comentario, pero...
                ungetc (cc, stdin) ;
            } else {
                c = getchar () ;	// ...
                if (c == '@') {	// Si es la secuencia //@  ==> transcribimos la linea
                    do {		// Se trata de codigo inline (Codigo embebido en C)
                        c = getchar () ;
                        putchar (c) ;
                    } while (c != '\n') ;
                } else {		// ==> comentario, ignorar la linea
                    while (c != '\n') {
                        c = getchar () ;
                    }
                }
            }
        } else if (c == '\\') c = getchar () ;
		
        if (c == '\n')
            n_line++ ;

    } while (c == ' ' || c == '\n' || c == 10 || c == 13 || c == '\t') ;
    
    if (c == '\"') {
        i = 0 ;
        do {
            c = getchar () ;
            temp_str [i++] = c ;
        } while (c != '\"' && i < 255) ;
        if (i == 256) {
            printf ("AVISO: string con mas de 255 caracteres en linea %d\n", n_line) ;
        }		 	// habria que leer hasta el siguiente " , pero, y si falta?
        temp_str [--i] = '\0' ;
        yylval.code = gen_code (temp_str) ;
        return (STRING) ;
    }

    if (c == '.' || (c >= '0' && c <= '9')) {
        ungetc (c, stdin) ;
        scanf ("%d", &yylval.value) ;
//         printf ("\nDEV: NUMBER %d\n", yylval.value) ;        // PARA DEPURAR
        return NUMBER ;
    }

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        i = 0 ;
        while (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9') || c == '_') && i < 255) {
            temp_str [i++] = tolower (c) ;
            c = getchar () ;
        }
        temp_str [i] = '\0' ;
        ungetc (c, stdin) ;

        yylval.code = gen_code (temp_str) ;
        symbol = search_keyword (yylval.code) ;
        if (symbol == NULL) {    // no es palabra reservada -> identificador antes vrariabre
//               printf ("\nDEV: IDENTIF %s\n", yylval.code) ;    // PARA DEPURAR
            return (IDENTIF) ;
        } else {
//               printf ("\nDEV: OTRO %s\n", yylval.code) ;       // PARA DEPURAR
            return (symbol->token) ;
        }
    }

    if (strchr (ops_expandibles, c) != NULL) { // busca c en ops_expandibles
        cc = getchar () ;
        sprintf (temp_str, "%c%c", (char) c, (char) cc) ;
        symbol = search_keyword (temp_str) ;
        if (symbol == NULL) {
            ungetc (cc, stdin) ;
            yylval.code = NULL ;
            return (c) ;
        } else {
            yylval.code = gen_code (temp_str) ; // aunque no se use
            return (symbol->token) ;
        }
    }

//    printf ("\nDEV: LITERAL %d #%c#\n", (int) c, c) ;      // PARA DEPURAR
    if (c == EOF || c == 255 || c == 26) {
//         printf ("tEOF ") ;                                // PARA DEPURAR
        return (0) ;
    }

    return c ;
}


int main ()
{
    yyparse () ;
}
