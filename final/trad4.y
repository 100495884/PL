/* 406 Marcos Emigdio Ramírez Cerdán, Javier Moyano San Bruno*/
/*100499744@alumnos.uc3m.es 100495884@alumnos.uc3m.es*/
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

typedef struct s_attr {
        int value ;
        char *code ;
} t_attr ;

// Tabla de símbolos para diferenciar entre variables locales y globales
struct symbol {
    char name[50];
    char scope[50];
};

struct symbol tabla_de_simbolos[100];
int contador = 0;
char funcion_actual[50] = "";

void add_symbol(char* name, char* scope) {
    strcpy(tabla_de_simbolos[contador].name, name);
    strcpy(tabla_de_simbolos[contador].scope, scope);
    contador++;
}

int variable_local(char* name) {
    for (int i = 0; i < contador; i++) {
        if (strcmp(tabla_de_simbolos[i].name, name) == 0 && strcmp(tabla_de_simbolos[i].scope, funcion_actual) == 0) {
            return 1;
        }
    }
    return 0;
}

int leer_parentesis(char* my_string) {
   int dentro = 0;
   int sentencia = 0;
   for (int i = 0; my_string[i] != '\0'; i++) {
   	if (my_string[i] == '(') {
   	    if (dentro == 0 && sentencia) {
   		return 1;
   	    }
   	    dentro++;
   	}
   	else if (my_string[i] == ')') {
   	    dentro--;
   	    sentencia = 1;
   	}
   }		
   return 0;
}

#define YYSTYPE t_attr

%}

// Definiciones de tokens

%token NUMBER        
%token IDENTIF       // Identificador=variable
%token INTEGER       // identifica el tipo entero
%token STRING
%token MAIN          // identifica el main
%token WHILE         // identifica el bucle while
%token PUTS          // identifica la función puts    
%token PRINTF        // identifica la función printf
%token AND           // identifica los operadores lógicos
%token OR
%token NEQ
%token EQ
%token LEQ
%token GEQ
%token IF            // identifica las condiciones
%token ELSE
%token FOR           // identifica el bucle for
%token RETURN


%right '='                    // es la ultima operacion que se debe realizar
%left OR
%left AND
%left EQ NEQ
%left '<' '>' LEQ GEQ
%left '+' '-'                 // menor orden de precedencia
%left '*' '/' '%'             // orden de precedencia intermedio
%left UNARY_SIGN              // mayor orden de precedencia

%%                            // Seccion 3 Gramatica - Semantico

axioma: programa_principal { ; }
	;

programa_principal: variables funciones { ; }
    | funciones { ; }
    ;

/* Definiciones de las variables */
variables: variable variables { ; }
	| variable { ; }
	;
	  
variable: INTEGER definicion ';' { printf ("(setq %s)\n", $2.code) ; }
	| INTEGER definicion ',' definiciones ';' { printf ("(setq %s) %s\n", $2.code, $4.code) ; }  
	;

/* Definición de las funciones */
funciones: funcion funciones { ; }
	| main { ; }
	;

funcion: IDENTIF { sprintf (funcion_actual, "%s", $1.code); } '(' parametros ')' '{' sentencias '}'
    { if (strcmp($4.code, " ") != 0) { printf("(defun %s(%s) %s)\n", $1.code, $4.code, $7.code);
	} else { printf("(defun %s() %s)\n", $1.code, $7.code); } strcpy(funcion_actual, ""); }
	;

parametros: INTEGER IDENTIF ',' parametros { sprintf (temp, "%s %s", $2.code, $4.code) ; $$.code = gen_code(temp) ; }
    | INTEGER IDENTIF { sprintf (temp, "%s", $2.code) ; $$.code = gen_code(temp) ; }
    | /* lambda */ { sprintf (temp, " ") ; $$.code = gen_code(temp) ; }
    ;

main: MAIN { sprintf (funcion_actual, "%s", $1.code); } '(' ')' '{' sentencias '}' { printf("(defun main() %s)\n", $6.code) ; }
	;

/* Sentencias para una función */
sentencias: sentencia ';' sentencias { sprintf(temp, "%s %s", $1.code, $3.code); $$.code = gen_code(temp) ; }
    | sentencia ';' { sprintf (temp, "%s", $1.code) ; $$.code = gen_code(temp) ; }
    | estructura sentencias { sprintf(temp, "%s %s", $1.code, $2.code); $$.code = gen_code(temp) ; }
    | estructura { $$ = $1; }
	;

sentencia: INTEGER definicion { sprintf (temp, "(setq %s_%s)", funcion_actual, $2.code) ; $$.code = gen_code (temp) ; }  
	| INTEGER definicion ',' definiciones { sprintf (temp, "(setq %s_%s) %s", funcion_actual, $2.code, $4.code) ; $$.code = gen_code (temp) ; }  
	| IDENTIF '=' expresion { if (variable_local($1.code)) { sprintf (temp, "(setf %s_%s %s)", funcion_actual, $1.code, $3.code);
	} else { sprintf (temp, "(setf %s %s)", $1.code, $3.code); } $$.code = gen_code (temp) ; }
    | IDENTIF '[' expresion ']' '=' expresion { if (variable_local($1.code)) { sprintf (temp, "(setf (aref %s_%s %s) %s)", funcion_actual, $1.code, $3.code, $6.code);
    } else { sprintf (temp, "(setf (aref %s %s) %s)", $1.code, $3.code, $6.code); } $$.code = gen_code (temp) ; }
    | PRINTF '(' expresion ',' expresiones_print ')' { sprintf (temp, "%s", $5.code) ; $$.code = gen_code (temp) ; }
    | PUTS '(' STRING ')' { sprintf (temp, "(print \"%s\")", $3.code) ; $$.code = gen_code (temp) ; } 
    | IDENTIF '(' parametros_extra ')' { sprintf (temp, "(%s %s)", $1.code, $3.code); $$.code = gen_code (temp) ; } 
	| IDENTIF '(' ')' { sprintf (temp, "(%s)", $1.code) ; $$.code = gen_code (temp) ; } 
    | RETURN expresion { sprintf(temp, "(return-from %s %s)", funcion_actual, $2.code); $$.code = gen_code(temp) ; }
    ;

/* Estructuras  de bucles while y for, y condiciones if*/
estructura: WHILE '(' condicion ')' '{' sentencias '}' { sprintf(temp, "(loop while %s do %s)", $3.code, $6.code); $$.code = gen_code(temp) ; }
    | IF '(' condicion ')' '{' sentencias_if '}' { sprintf(temp, "(if %s %s)", $3.code, $6.code); $$.code = gen_code(temp) ; }
    | IF '(' condicion ')' '{' sentencias_if '}' ELSE '{' sentencias_if '}' { sprintf(temp, "(if %s %s %s)", $3.code, $6.code, $10.code); $$.code = gen_code(temp) ; }
    | FOR '(' contador_for ';' condicion ';' incremento_decremento ')' '{' sentencias '}' { sprintf(temp, "%s (loop while %s do %s %s)", $3.code, $5.code, $10.code, $7.code) ; $$.code = gen_code (temp) ; }
    ;

sentencias_if: sentencia ';' { if (leer_parentesis($1.code)) { sprintf (temp, "(progn %s)", $1.code) ; } else { sprintf (temp, "%s", $1.code) ; } $$.code = gen_code (temp) ; }
    | estructura { $$ = $1; }
    | sentencia ';' sentencias { sprintf (temp, "(progn %s %s)", $1.code, $3.code) ; $$.code = gen_code (temp) ; }
    | estructura sentencias	{ sprintf (temp, "(progn %s %s)", $1.code, $2.code) ; $$.code = gen_code (temp) ; }
    ;

contador_for: INTEGER IDENTIF { sprintf (temp, "(setq %s_%s 0)", funcion_actual, $2.code) ; $$.code = gen_code (temp) ; }
    | INTEGER IDENTIF '=' termino { sprintf (temp, "(setq %s_%s %s)", funcion_actual, $2.code, $4.code) ; $$.code = gen_code (temp) ; }
    | IDENTIF '=' termino { if (variable_local($1.code)) { sprintf (temp, "(setf %s_%s %s)", funcion_actual, $1.code, $3.code);
    } else { sprintf (temp, "(setf %s %s)", $1.code, $3.code); } $$.code = gen_code (temp) ; }
    ;
          
incremento_decremento: IDENTIF '=' IDENTIF '+' NUMBER { if (variable_local($1.code)) { sprintf (temp, "(setf %s_%s (+ %s_%s %d))", funcion_actual, $1.code, funcion_actual, $3.code, $5.value);
	} else { sprintf (temp, "(setf %s (+ %s %d))", $1.code, $3.code, $5.value); } $$.code = gen_code (temp) ; }
    | IDENTIF '=' IDENTIF '-' NUMBER { if (variable_local($1.code)) { sprintf (temp, "(setf %s_%s (- %s_%s %d))", funcion_actual, $1.code, funcion_actual, $3.code, $5.value);
    } else { sprintf (temp, "(setf %s (- %s %d))", $1.code, $3.code, $5.value); } $$.code = gen_code (temp) ; }
    ;

/* Definición de las variables */
definiciones: definicion ',' definiciones { sprintf (temp, "(setq %s) %s", $1.code, $3.code) ; $$.code = gen_code (temp) ; }
    | definicion { sprintf (temp, "(setq %s)", $1.code) ; $$.code = gen_code (temp) ; }
    ;

definicion: IDENTIF '=' termino	{ if (strcmp(funcion_actual, "") != 0) { add_symbol($1.code, funcion_actual); } sprintf (temp, "%s %s", $1.code, $3.code) ; $$.code = gen_code (temp) ; }
    | IDENTIF { if (strcmp(funcion_actual, "") != 0) { add_symbol($1.code, funcion_actual); } sprintf (temp, "%s 0", $1.code) ; $$.code = gen_code (temp) ; }
    | IDENTIF '[' NUMBER ']' { if (strcmp(funcion_actual, "") != 0) { add_symbol($1.code, funcion_actual); } sprintf (temp, "%s (make-array %d)", $1.code, $3.value) ; $$.code = gen_code (temp) ; }
    ;
         
/* Para el correcto uso del printf */
expresiones_print: expresion ',' expresiones_print { sprintf (temp, "(princ %s) %s", $1.code, $3.code); $$.code = gen_code (temp) ; }
	| expresion { sprintf (temp, "(princ %s)", $1.code) ; $$.code = gen_code (temp) ; }
	;
         
/* Todas las expresiones posibles */
expresion: termino { $$ = $1 ; }
    | expresion '+' expresion { sprintf (temp, "(+ %s %s)", $1.code, $3.code) ; $$.code = gen_code (temp) ; }
    | expresion '-' expresion { sprintf (temp, "(- %s %s)", $1.code, $3.code) ; $$.code = gen_code (temp) ; }
    | expresion '*' expresion { sprintf (temp, "(* %s %s)", $1.code, $3.code) ; $$.code = gen_code (temp) ; }
    | expresion '/' expresion { sprintf (temp, "(/ %s %s)", $1.code, $3.code) ; $$.code = gen_code (temp) ; }
    | expresion '%' expresion { sprintf (temp, "(mod %s %s)", $1.code, $3.code) ; $$.code = gen_code (temp) ; }
    | STRING { sprintf (temp, "\"%s\"", $1.code) ; $$.code = gen_code (temp) ; }
    | IDENTIF '(' parametros_extra ')'  { sprintf (temp, "(%s %s)", $1.code, $3.code) ; $$.code = gen_code (temp) ; } 
    | IDENTIF '(' ')' { sprintf (temp, "(%s)", $1.code) ; $$.code = gen_code (temp) ; } 
    | IDENTIF '[' expresion ']' { if (variable_local($1.code)) { sprintf (temp, "(aref %s_%s %s)", funcion_actual, $1.code, $3.code);
    } else { sprintf (temp, "(aref %s %s)", $1.code, $3.code); } $$.code = gen_code (temp) ; }
    ;

/* Parámetros extra para las expresiones */
parametros_extra: expresion ',' parametros_extra { sprintf (temp, "%s %s", $1.code, $3.code) ; $$.code = gen_code(temp) ; }
    | expresion { sprintf (temp, "%s", $1.code) ; $$.code = gen_code(temp) ; } 
    ;

/* Expresiones de las condiciones */
condicion: expresion AND expresion { sprintf (temp, "(and %s %s)", $1.code, $3.code) ; $$.code = gen_code (temp) ; }
    |   expresion OR expresion { sprintf (temp, "(or %s %s)", $1.code, $3.code) ; $$.code = gen_code (temp) ; }
    |   expresion NEQ expresion { sprintf (temp, "(/= %s %s)", $1.code, $3.code) ; $$.code = gen_code (temp) ; }
    |   expresion EQ expresion { sprintf (temp, "(= %s %s)", $1.code, $3.code) ; $$.code = gen_code (temp) ; }
    |   expresion '<' expresion { sprintf (temp, "(< %s %s)", $1.code, $3.code) ; $$.code = gen_code (temp) ; }
    |   expresion LEQ expresion { sprintf (temp, "(<= %s %s)", $1.code, $3.code) ; $$.code = gen_code (temp) ; }
    |   expresion '>' expresion { sprintf (temp, "(> %s %s)", $1.code, $3.code) ; $$.code = gen_code (temp) ; }
    |   expresion GEQ expresion { sprintf (temp, "(>= %s %s)", $1.code, $3.code) ; $$.code = gen_code (temp) ; }
    |   condicion AND condicion { sprintf (temp, "(and %s %s)", $1.code, $3.code) ; $$.code = gen_code (temp) ; }
    |   condicion OR condicion { sprintf (temp, "(or %s %s)", $1.code, $3.code) ; $$.code = gen_code (temp) ; }
    |   condicion NEQ condicion { sprintf (temp, "(/= %s %s)", $1.code, $3.code) ; $$.code = gen_code (temp) ; }
    |   condicion EQ condicion { sprintf (temp, "(= %s %s)", $1.code, $3.code) ; $$.code = gen_code (temp) ; }
    |   condicion '<' condicion { sprintf (temp, "(< %s %s)", $1.code, $3.code) ; $$.code = gen_code (temp) ; }
    |   condicion LEQ condicion { sprintf (temp, "(<= %s %s)", $1.code, $3.code) ; $$.code = gen_code (temp) ; }
    |   condicion '>' condicion { sprintf (temp, "(> %s %s)", $1.code, $3.code) ; $$.code = gen_code (temp) ; }
    |   condicion GEQ condicion { sprintf (temp, "(>= %s %s)", $1.code, $3.code) ; $$.code = gen_code (temp) ; }          
    ;

/* Un termino puede ser un número, una variable, un incremento o un decremento */
termino: operando { $$ = $1 ; }                          
    | '+' operando %prec UNARY_SIGN { sprintf (temp, "(+ %s)", $2.code) ; $$.code = gen_code (temp) ; }
    | '-' operando %prec UNARY_SIGN { sprintf (temp, "(- %s)", $2.code) ; $$.code = gen_code (temp) ; }    
    ;

/* Número, variable o expresión entre paréntesis */
operando: IDENTIF { if (variable_local($1.code)) { sprintf (temp, "%s_%s", funcion_actual, $1.code); } else { sprintf (temp, "%s", $1.code); } $$.code = gen_code (temp) ; }
    | NUMBER { sprintf (temp, "%d", $1.value) ; $$.code = gen_code (temp) ; }
    | '(' expresion ')' { $$ = $2 ; }
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
    "main",        MAIN,           // y los token asociados
    "int",         INTEGER,
    "puts",	   PUTS,
    "printf",  PRINTF,
    "while",   WHILE,
    "if",      IF,
    "else",    ELSE,
    "for",     FOR,
    "return",  RETURN,
    "&&",	   AND,
    "||",	   OR,
    "!=",	   NEQ,
    "==",	   EQ,
    "<=",	   LEQ,
    ">=",	   GEQ,
    NULL,          0               // para marcar el fin de la tabla
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
    int i ;
    unsigned char c ;
    unsigned char cc ;
    char ops_expandibles [] = "!<=>|%/&+-*" ;
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