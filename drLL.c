/*406 Marcos Emigdio Ramírez Cerdán, Javier Moyano San Bruno
100499744@alumnos.uc3m.es 100495884@alumnos.uc3m.es*/
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Referencia los números, los operadores y las variables
#define T_NUMBER 	1001
#define T_OPERATOR	1002		
#define T_VARIABLE  1003  

void ParseYourGrammar () ; 		/// Dummy Parser
void ParseAxiom () ;			/// Prototype for forward reference 		

struct s_tokens {
	int token ;					// Here we store the current token/literal 
	int old_token ; 			// Sometimes we need to check the previous token
	int number ;				// The value of the number 
	int old_number ;			// old number value
	char variable_name [8] ;	/// variable name	
	char old_var_name [8] ;		/// old variable name			
	int token_val ;				// the arithmetic operator
	int old_token_val ;			// old arithmetic operator
} ;

struct s_tokens tokens = {0, 0, 0, -1, "", "", 0, -1}; // contains initial values


int line_counter = 1 ;


void update_old_token () 
{					/// Sometimes we need to check the previous token
	tokens.old_token = tokens.token ;
	tokens.old_number = tokens.number ;
	strcpy (tokens.old_var_name, tokens.variable_name) ;	/// Copy variable names			
	tokens.old_token_val = tokens.token_val ;
}


void init_tokens () 
{ 								///  Not really neccesary
    tokens.token = 0;
	tokens.old_token = 0 ;
    tokens.number = 0 ;
    tokens.old_number = -1 ;
	strcpy (tokens.old_var_name, "") ;			/// erase old variable name
	strcpy (tokens.variable_name, "") ;			/// Erase variable name
    tokens.token_val = 0;
    tokens.old_token_val = -1;
}


int rd_lex ()
{
	int c ;
	int cc ;
	// Salta espacios en blanco y cuenta las líneas para dar información
	do {
		c = getchar () ;
		if (c == '\n')
			line_counter++ ;	// info for rd_syntax_error()
	} while (c == '\t' || c == ' ' || c == '\r') ;	/// \r is part of a newline in some Operating Systems
	
	if (isdigit (c)) {			/// Token Number is [Digit]+
		ungetc (c, stdin) ;		/// This returns one character to the standard input stream
		update_old_token () ;
		scanf ("%d", &tokens.number) ;
		tokens.token = T_NUMBER ;
		return (tokens.token) ;	// returns the Token for Variable
	}

	if (isalpha(c)) {  /// Token Variable of type Letter[Digit]? 
        update_old_token () ;
		cc = getchar () ;
		if (isdigit (cc)) {									
			sprintf (tokens.variable_name, "%c%c", c, cc) ;		/// This copies the LetterDigit name in the variable name
		} else {											
			ungetc (cc, stdin) ;									
			sprintf (tokens.variable_name, "%c", c) ;			/// This copies the single Letter name in the variable name
		}													
		tokens.token = T_VARIABLE ;
        return (tokens.token) ;	// returns the Token for Variable
    } 

	if (c == '+' || c == '-' || c == '*' || c == '/') {  /// Remember that = is returned as a literal
		update_old_token () ;
		tokens.token_val = c ;
		tokens.token = T_OPERATOR ;
		return (tokens.token) ;		// returns the Token for Arithmetic Operators
	}					

	if (c == EOF){         /// End Of Archive detection for enhanced Batch Processing
        exit (0) ;
    } 

	update_old_token () ;
	tokens.token = c ;
	return (tokens.token) ;		// returns a literal
}


void rd_syntax_error (int expected, int token, char *output) 
{
	fprintf (stderr, "ERROR in line %d ", line_counter) ;
	fprintf (stderr, output, expected, token) ;
	
	exit (0) ;
}


void MatchSymbol (int expected_token)
{
	if (tokens.token != expected_token) {
		rd_syntax_error (expected_token, tokens.token, "token %d expected, but %d was read") ;
		exit (0) ;
	} else {
	 	rd_lex () ; 			/// read next Token
	}
}


// #define ParseLParen() 	MatchSymbol ('(') ; // More concise and efficient definitions
// #define ParseRParen() 	MatchSymbol (')') ; ///   rather than using functions
											/// The actual recomendation is to use MatchSymbol in the code rather than theese macros


void ParseExpresion(); // Prototipo de la función

void ParseYourGrammar() {
	// Si el token es un paréntesis de apertura, se espera una expresión
    if (tokens.token == '(') { 
		// Coincide con el paréntesis de apertura y avanza al siguiente token
        MatchSymbol('(');
		// Llama a la función ParseExpresion para que analice la expresión
        ParseExpresion();
		// Coincide con el paréntesis de cierre ')' y avanza al siguiente token
        MatchSymbol(')');
    } else if (tokens.token == T_NUMBER) {  // Verifica si el token actual es un número
        printf("%d", tokens.number); 
        MatchSymbol(T_NUMBER);
    } else if (tokens.token == T_VARIABLE) { // Verifica si el token actual es una variable
        printf("%s", tokens.variable_name);
        MatchSymbol(T_VARIABLE);
    } else {
		// Si no es ninguno de los casos anteriores, lanza un error de sintaxis
        rd_syntax_error(-1, tokens.token, "ERROR: Se esperaba un número, variable o paréntesis de apertura.");
    }
}

void ParseExpresion() {
	// Verifica si el token actual es un operador
    if (tokens.token == T_OPERATOR) {
        char operador = tokens.token_val;
        MatchSymbol(T_OPERATOR);

        // Imprimir paréntesis solo si es una expresión compuesta
        printf("(");
		// Procesa la primera expresión
        ParseYourGrammar();
        printf(" %c ", operador);
		// Procesa la segunda expresión
        ParseYourGrammar();
		// Imprime un paréntesis de cierre para la expresión compuesta
        printf(")");

    } else if (tokens.token == '=') { // Verifica si el token actual es un signo de igual '='
        MatchSymbol('=');
        // Verifica si el token actual es una variable
        if (tokens.token == T_VARIABLE) {
			// Simepre imprimirá el paréntesis de apertura
            printf("(%s = ", tokens.variable_name);
            MatchSymbol(T_VARIABLE);

            // Verifica si lo que sigue es una expresión entre paréntesis
            if (tokens.token == '(') {
                ParseYourGrammar(); // Ya maneja los paréntesis internos
            } else {
				// Procesa la expresión sin paréntesis
                ParseYourGrammar();
            }
			// Imprime un paréntesis de cierre para la asignación
            printf(")");
        } else {
			// Si no es una variable, lanza un error de sintaxis
            rd_syntax_error(-1, tokens.token, "ERROR: Se esperaba una variable después del signo '='.");
        }
    } else {
		// Si no es una variable, lanza un error de sintaxis
        rd_syntax_error(-1, tokens.token, "ERROR: Se esperaba un operador o un signo '='.");
    }
}

void ParseAxiom () 
{									/// Axiom ::= \n
	ParseYourGrammar () ;			/// Dummy Parser. Complete this with your design								
	if (tokens.token == '\n') {
		printf ("\n") ; 	
		MatchSymbol ('\n') ;
		
	} else { 
		rd_syntax_error (-1, tokens.token, "-- Unexpected Token (Expected:%d=None, Read:%d) at end of Parsing\n") ;
	}
}


int main (int argc, char **argv) 
{
// Usage :  drLL -s  ==> evaluate a single Input Line
//          drLL     ==> evalute multiple Input Lines until some error appears
/// DO NOT MODIFY THE CODE INSIDE THE MAIN FUNCTION WITHOUT PERMISSION

	int flagMultiple = 1 ;
	
	if (argc >= 2) {
		if (strcmp ("-s", argv [1]) == 0) {
			flagMultiple = 0 ;
		}
	}
	
	rd_lex () ;						/// Read first Token only once
	do {
		ParseAxiom () ;		
//		printf ("\n") ;
	} while (flagMultiple) ;
	
	exit (0) ;
}
