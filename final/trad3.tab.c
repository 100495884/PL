/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "trad3.y"
                          // SECCION 1 Declaraciones de C-Yacc

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


#line 141 "trad3.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUMBER = 258,                  /* NUMBER  */
    IDENTIF = 259,                 /* IDENTIF  */
    INTEGER = 260,                 /* INTEGER  */
    STRING = 261,                  /* STRING  */
    MAIN = 262,                    /* MAIN  */
    WHILE = 263,                   /* WHILE  */
    PUTS = 264,                    /* PUTS  */
    PRINTF = 265,                  /* PRINTF  */
    AND = 266,                     /* AND  */
    OR = 267,                      /* OR  */
    NEQ = 268,                     /* NEQ  */
    EQ = 269,                      /* EQ  */
    LEQ = 270,                     /* LEQ  */
    GEQ = 271,                     /* GEQ  */
    IF = 272,                      /* IF  */
    ELSE = 273,                    /* ELSE  */
    FOR = 274,                     /* FOR  */
    RETURN = 275,                  /* RETURN  */
    UNARY_SIGN = 276               /* UNARY_SIGN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_IDENTIF = 4,                    /* IDENTIF  */
  YYSYMBOL_INTEGER = 5,                    /* INTEGER  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_MAIN = 7,                       /* MAIN  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_PUTS = 9,                       /* PUTS  */
  YYSYMBOL_PRINTF = 10,                    /* PRINTF  */
  YYSYMBOL_AND = 11,                       /* AND  */
  YYSYMBOL_OR = 12,                        /* OR  */
  YYSYMBOL_NEQ = 13,                       /* NEQ  */
  YYSYMBOL_EQ = 14,                        /* EQ  */
  YYSYMBOL_LEQ = 15,                       /* LEQ  */
  YYSYMBOL_GEQ = 16,                       /* GEQ  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_ELSE = 18,                      /* ELSE  */
  YYSYMBOL_FOR = 19,                       /* FOR  */
  YYSYMBOL_RETURN = 20,                    /* RETURN  */
  YYSYMBOL_21_ = 21,                       /* '@'  */
  YYSYMBOL_22_ = 22,                       /* '='  */
  YYSYMBOL_23_ = 23,                       /* '<'  */
  YYSYMBOL_24_ = 24,                       /* '>'  */
  YYSYMBOL_25_ = 25,                       /* '+'  */
  YYSYMBOL_26_ = 26,                       /* '-'  */
  YYSYMBOL_27_ = 27,                       /* '*'  */
  YYSYMBOL_28_ = 28,                       /* '/'  */
  YYSYMBOL_29_ = 29,                       /* '%'  */
  YYSYMBOL_UNARY_SIGN = 30,                /* UNARY_SIGN  */
  YYSYMBOL_31_ = 31,                       /* ';'  */
  YYSYMBOL_32_ = 32,                       /* ','  */
  YYSYMBOL_33_ = 33,                       /* '('  */
  YYSYMBOL_34_ = 34,                       /* ')'  */
  YYSYMBOL_35_ = 35,                       /* '{'  */
  YYSYMBOL_36_ = 36,                       /* '}'  */
  YYSYMBOL_37_ = 37,                       /* '['  */
  YYSYMBOL_38_ = 38,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_axioma = 40,                    /* axioma  */
  YYSYMBOL_programa_principal = 41,        /* programa_principal  */
  YYSYMBOL_variables = 42,                 /* variables  */
  YYSYMBOL_variable = 43,                  /* variable  */
  YYSYMBOL_funciones = 44,                 /* funciones  */
  YYSYMBOL_funcion = 45,                   /* funcion  */
  YYSYMBOL_46_1 = 46,                      /* $@1  */
  YYSYMBOL_parametros = 47,                /* parametros  */
  YYSYMBOL_main = 48,                      /* main  */
  YYSYMBOL_49_2 = 49,                      /* $@2  */
  YYSYMBOL_sentencias = 50,                /* sentencias  */
  YYSYMBOL_sentencia = 51,                 /* sentencia  */
  YYSYMBOL_estructura = 52,                /* estructura  */
  YYSYMBOL_sentencias_if = 53,             /* sentencias_if  */
  YYSYMBOL_contador_for = 54,              /* contador_for  */
  YYSYMBOL_incremento_decremento = 55,     /* incremento_decremento  */
  YYSYMBOL_definiciones = 56,              /* definiciones  */
  YYSYMBOL_definicion = 57,                /* definicion  */
  YYSYMBOL_expresiones_print = 58,         /* expresiones_print  */
  YYSYMBOL_expresion = 59,                 /* expresion  */
  YYSYMBOL_parametros_extra = 60,          /* parametros_extra  */
  YYSYMBOL_condicion = 61,                 /* condicion  */
  YYSYMBOL_termino = 62,                   /* termino  */
  YYSYMBOL_operando = 63                   /* operando  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   281

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  199

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   276


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    29,     2,     2,
      33,    34,    27,    25,    32,    26,     2,    28,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    31,
      23,    22,    24,     2,    21,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   107,   107,   110,   111,   115,   116,   119,   120,   124,
     125,   128,   128,   134,   136,   138,   142,   142,   146,   148,
     150,   152,   155,   157,   159,   162,   165,   167,   169,   171,
     173,   175,   179,   186,   188,   190,   192,   197,   200,   201,
     203,   207,   209,   211,   216,   219,   225,   227,   231,   234,
     237,   243,   245,   250,   251,   253,   255,   257,   259,   261,
     263,   265,   267,   273,   275,   280,   282,   284,   286,   288,
     290,   292,   294,   296,   298,   300,   302,   304,   306,   308,
     310,   315,   316,   318,   323,   326,   328
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "IDENTIF",
  "INTEGER", "STRING", "MAIN", "WHILE", "PUTS", "PRINTF", "AND", "OR",
  "NEQ", "EQ", "LEQ", "GEQ", "IF", "ELSE", "FOR", "RETURN", "'@'", "'='",
  "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "UNARY_SIGN", "';'",
  "','", "'('", "')'", "'{'", "'}'", "'['", "']'", "$accept", "axioma",
  "programa_principal", "variables", "variable", "funciones", "funcion",
  "$@1", "parametros", "main", "$@2", "sentencias", "sentencia",
  "estructura", "sentencias_if", "contador_for", "incremento_decremento",
  "definiciones", "definicion", "expresiones_print", "expresion",
  "parametros_extra", "condicion", "termino", "operando", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-149)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      78,  -149,     9,  -149,    19,  -149,   103,    52,  -149,   103,
    -149,    26,   -17,    67,    38,  -149,  -149,  -149,  -149,   106,
      75,    49,  -149,     9,    42,    80,    72,  -149,  -149,    31,
      31,     4,  -149,  -149,    91,   100,   107,   109,   118,   137,
    -149,  -149,   -22,  -149,   213,  -149,  -149,  -149,     9,   128,
     106,   128,    47,     4,     4,     4,     4,     4,     4,  -149,
    -149,   -19,     9,   140,   152,   154,   155,   156,     4,     4,
     138,   159,   128,  -149,   150,  -149,   223,   171,   194,    99,
      99,  -149,  -149,  -149,     4,    71,     4,   180,     4,   207,
       4,     4,    27,    40,   168,   187,  -149,   128,  -149,  -149,
       4,  -149,  -149,    40,  -149,   181,   199,     9,   168,   101,
     184,   231,   141,   192,   225,   200,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,  -149,  -149,  -149,   208,  -149,   198,  -149,     4,
     201,    75,   212,     4,    40,    40,    40,    40,    40,    40,
      40,    40,   153,   193,    79,    79,  -149,  -149,  -149,  -149,
       4,   128,   209,   239,   128,  -149,    75,   147,    40,   210,
    -149,     4,   204,   128,   217,  -149,   240,  -149,  -149,   128,
    -149,   227,   232,   228,  -149,   226,   265,   235,   128,    93,
     128,   236,   270,   271,   241,  -149,  -149,  -149,  -149
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    11,     0,    16,     0,     2,     0,     6,     4,     0,
      10,     0,    49,     0,     0,     1,     3,     5,     9,    15,
       0,     0,     7,     0,     0,     0,     0,    85,    84,     0,
       0,     0,    48,    81,     0,     0,    47,     0,    14,     0,
      82,    83,    84,    59,     0,    53,    50,     8,     0,     0,
      15,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,    13,     0,    61,    64,     0,     0,    54,
      55,    56,    57,    58,     0,     0,     0,    22,     0,     0,
       0,     0,     0,    30,    31,    32,    17,    19,    20,    12,
       0,    60,    62,    24,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,    63,    28,     0,    23,     0,    27,     0,
       0,     0,    41,     0,    65,    66,    67,    68,    70,    72,
      69,    71,    73,    74,    75,    76,    78,    80,    77,    79,
       0,     0,     0,    52,     0,    43,     0,     0,    25,     0,
      26,     0,     0,    38,     0,    42,     0,    33,    51,    37,
      40,    34,     0,     0,    39,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    35,    44,    45,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -149,  -149,  -149,   268,  -149,   114,  -149,  -149,   229,  -149,
    -149,   -39,  -148,  -147,    88,  -149,  -149,   -44,     0,   110,
     -30,   -64,   -82,   -20,   113
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,     9,    11,    26,    10,
      14,    70,    71,    72,   174,   115,   183,    35,    36,   162,
     108,    77,    95,    45,    33
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      32,    44,    13,    84,    60,    20,   109,    27,    42,   112,
      43,    52,    74,    12,    85,    53,   172,   173,    86,    15,
      21,   105,    76,    78,    79,    80,    81,    82,    83,    29,
      30,   113,   114,    98,    27,    28,   133,    31,    93,    94,
     172,   173,   152,   153,   154,   155,   156,   157,   158,   159,
      27,    42,    34,    43,   103,    76,   106,     2,   132,    19,
     111,   167,    87,   136,    31,    54,    55,    56,    57,    58,
      76,    24,    29,    30,    27,    42,    37,    43,    27,    28,
      31,    75,     1,     2,    38,     3,   144,   145,   146,   147,
     148,   149,   150,   151,   128,   129,    29,    30,    22,    23,
      29,    30,   130,   131,    31,   104,    39,     1,    31,   163,
       3,    25,   124,   125,   126,   127,   128,   129,   192,   193,
      16,   165,   169,    18,   130,   131,    56,    57,    58,    46,
     168,    47,    61,    62,   180,   137,    63,    64,    65,    48,
     184,   163,    40,    41,    49,    66,   175,    67,    68,    69,
      50,   194,   124,   125,   126,   127,   128,   129,   124,   125,
     126,   127,   128,   129,   130,   131,   126,   127,   128,   129,
     130,   131,    51,    88,    96,   140,   130,   131,   176,   116,
     117,   118,   119,   120,   121,    89,    99,    90,    91,    92,
      97,   122,   123,    54,    55,    56,    57,    58,   124,   125,
     126,   127,   128,   129,   124,   101,   126,   127,   128,   129,
     130,   131,   107,   110,   141,   134,   130,   131,   138,    54,
      55,    56,    57,    58,    54,    55,    56,    57,    58,   142,
     160,   143,   102,   161,   166,   179,   164,   135,    54,    55,
      56,    57,    58,   170,   182,   185,   177,    59,    54,    55,
      56,    57,    58,   181,   186,   100,    54,    55,    56,    57,
      58,   188,   187,   139,    54,    55,    56,    57,    58,   189,
     190,   171,   195,   196,   197,    17,   191,   198,     0,    73,
       0,   178
};

static const yytype_int16 yycheck[] =
{
      20,    31,     2,    22,    48,    22,    88,     3,     4,    91,
       6,    33,    51,     4,    33,    37,   164,   164,    37,     0,
      37,    85,    52,    53,    54,    55,    56,    57,    58,    25,
      26,     4,     5,    72,     3,     4,   100,    33,    68,    69,
     188,   188,   124,   125,   126,   127,   128,   129,   130,   131,
       3,     4,     3,     6,    84,    85,    86,     5,    97,    33,
      90,   143,    62,   107,    33,    25,    26,    27,    28,    29,
     100,    33,    25,    26,     3,     4,    34,     6,     3,     4,
      33,    34,     4,     5,     4,     7,   116,   117,   118,   119,
     120,   121,   122,   123,    15,    16,    25,    26,    31,    32,
      25,    26,    23,    24,    33,    34,    34,     4,    33,   139,
       7,     5,    11,    12,    13,    14,    15,    16,    25,    26,
       6,   141,   161,     9,    23,    24,    27,    28,    29,    38,
     160,    31,     4,     5,   173,    34,     8,     9,    10,    32,
     179,   171,    29,    30,    35,    17,   166,    19,    20,    21,
      32,   190,    11,    12,    13,    14,    15,    16,    11,    12,
      13,    14,    15,    16,    23,    24,    13,    14,    15,    16,
      23,    24,    35,    33,    36,    34,    23,    24,    31,    11,
      12,    13,    14,    15,    16,    33,    36,    33,    33,    33,
      31,    23,    24,    25,    26,    27,    28,    29,    11,    12,
      13,    14,    15,    16,    11,    34,    13,    14,    15,    16,
      23,    24,    32,     6,    22,    34,    23,    24,    34,    25,
      26,    27,    28,    29,    25,    26,    27,    28,    29,     4,
      22,    31,    38,    35,    22,    31,    35,    38,    25,    26,
      27,    28,    29,    34,     4,    18,    36,    34,    25,    26,
      27,    28,    29,    36,    22,    32,    25,    26,    27,    28,
      29,    35,    34,    32,    25,    26,    27,    28,    29,     4,
      35,    32,    36,     3,     3,     7,   188,    36,    -1,    50,
      -1,   171
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,     7,    40,    41,    42,    43,    44,    45,
      48,    46,     4,    57,    49,     0,    44,    42,    44,    33,
      22,    37,    31,    32,    33,     5,    47,     3,     4,    25,
      26,    33,    62,    63,     3,    56,    57,    34,     4,    34,
      63,    63,     4,     6,    59,    62,    38,    31,    32,    35,
      32,    35,    33,    37,    25,    26,    27,    28,    29,    34,
      56,     4,     5,     8,     9,    10,    17,    19,    20,    21,
      50,    51,    52,    47,    50,    34,    59,    60,    59,    59,
      59,    59,    59,    59,    22,    33,    37,    57,    33,    33,
      33,    33,    33,    59,    59,    61,    36,    31,    50,    36,
      32,    34,    38,    59,    34,    60,    59,    32,    59,    61,
       6,    59,    61,     4,     5,    54,    11,    12,    13,    14,
      15,    16,    23,    24,    11,    12,    13,    14,    15,    16,
      23,    24,    50,    60,    34,    38,    56,    34,    34,    32,
      34,    22,     4,    31,    59,    59,    59,    59,    59,    59,
      59,    59,    61,    61,    61,    61,    61,    61,    61,    61,
      22,    35,    58,    59,    35,    62,    22,    61,    59,    50,
      34,    32,    51,    52,    53,    62,    31,    36,    58,    31,
      50,    36,     4,    55,    50,    18,    22,    34,    35,     4,
      35,    53,    25,    26,    50,    36,     3,     3,    36
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    42,    43,    43,    44,
      44,    46,    45,    47,    47,    47,    49,    48,    50,    50,
      50,    50,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    52,    52,    52,    52,    53,    53,    53,
      53,    54,    54,    54,    55,    55,    56,    56,    57,    57,
      57,    58,    58,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    60,    60,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    62,    62,    62,    63,    63,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     3,     5,     2,
       1,     0,     8,     4,     2,     0,     0,     7,     3,     2,
       2,     1,     2,     4,     3,     6,     6,     4,     4,     3,
       2,     2,     2,     7,     7,    11,    11,     2,     1,     3,
       2,     2,     4,     3,     5,     5,     3,     1,     3,     1,
       4,     3,     1,     1,     3,     3,     3,     3,     3,     1,
       4,     3,     4,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     2,     2,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* axioma: programa_principal  */
#line 107 "trad3.y"
                                             { ; }
#line 1383 "trad3.tab.c"
    break;

  case 3: /* programa_principal: variables funciones  */
#line 110 "trad3.y"
                                                    { ; }
#line 1389 "trad3.tab.c"
    break;

  case 4: /* programa_principal: funciones  */
#line 111 "trad3.y"
                                          { ; }
#line 1395 "trad3.tab.c"
    break;

  case 5: /* variables: variable variables  */
#line 115 "trad3.y"
                               { ; }
#line 1401 "trad3.tab.c"
    break;

  case 6: /* variables: variable  */
#line 116 "trad3.y"
                               { ; }
#line 1407 "trad3.tab.c"
    break;

  case 7: /* variable: INTEGER definicion ';'  */
#line 119 "trad3.y"
                                                    { printf ("(setq %s)\n", yyvsp[-1].code) ;  }
#line 1413 "trad3.tab.c"
    break;

  case 8: /* variable: INTEGER definicion ',' definiciones ';'  */
#line 120 "trad3.y"
                                                    { printf ("(setq %s) %s\n", yyvsp[-3].code, yyvsp[-1].code) ; }
#line 1419 "trad3.tab.c"
    break;

  case 9: /* funciones: funcion funciones  */
#line 124 "trad3.y"
                                { ; }
#line 1425 "trad3.tab.c"
    break;

  case 10: /* funciones: main  */
#line 125 "trad3.y"
                                { ; }
#line 1431 "trad3.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 128 "trad3.y"
                   { sprintf (funcion_actual, "%s", yyvsp[0].code); }
#line 1437 "trad3.tab.c"
    break;

  case 12: /* funcion: IDENTIF $@1 '(' parametros ')' '{' sentencias '}'  */
#line 129 "trad3.y"
                                                  { if (strcmp(yyvsp[-4].code, " ") != 0) { printf("(defun %s(%s) %s)\n", yyvsp[-7].code, yyvsp[-4].code, yyvsp[-1].code);
							  } else { printf("(defun %s() %s)\n", yyvsp[-7].code, yyvsp[-1].code); }
							  strcpy(funcion_actual, ""); }
#line 1445 "trad3.tab.c"
    break;

  case 13: /* parametros: INTEGER IDENTIF ',' parametros  */
#line 134 "trad3.y"
                                              { sprintf (temp, "%s %s", yyvsp[-2].code, yyvsp[0].code) ;
                                                            yyval.code = gen_code(temp);}
#line 1452 "trad3.tab.c"
    break;

  case 14: /* parametros: INTEGER IDENTIF  */
#line 136 "trad3.y"
                                                          { sprintf (temp, "%s", yyvsp[0].code) ;
                                                            yyval.code = gen_code(temp);}
#line 1459 "trad3.tab.c"
    break;

  case 15: /* parametros: %empty  */
#line 138 "trad3.y"
                                                          { sprintf (temp, " ") ;
                                                            yyval.code = gen_code(temp);}
#line 1466 "trad3.tab.c"
    break;

  case 16: /* $@2: %empty  */
#line 142 "trad3.y"
                  { sprintf (funcion_actual, "%s", yyvsp[0].code); }
#line 1472 "trad3.tab.c"
    break;

  case 17: /* main: MAIN $@2 '(' ')' '{' sentencias '}'  */
#line 142 "trad3.y"
                                                                                           { printf("(defun main() %s)\n", yyvsp[-1].code);}
#line 1478 "trad3.tab.c"
    break;

  case 18: /* sentencias: sentencia ';' sentencias  */
#line 146 "trad3.y"
                                         { sprintf(temp, "%s %s", yyvsp[-2].code, yyvsp[0].code);
                                         yyval.code = gen_code(temp);}
#line 1485 "trad3.tab.c"
    break;

  case 19: /* sentencias: sentencia ';'  */
#line 148 "trad3.y"
                                       { sprintf (temp, "%s", yyvsp[-1].code) ;
                                         yyval.code = gen_code(temp);}
#line 1492 "trad3.tab.c"
    break;

  case 20: /* sentencias: estructura sentencias  */
#line 150 "trad3.y"
                                       { sprintf(temp, "%s %s", yyvsp[-1].code, yyvsp[0].code);
                                         yyval.code = gen_code(temp);}
#line 1499 "trad3.tab.c"
    break;

  case 21: /* sentencias: estructura  */
#line 152 "trad3.y"
                                       { yyval = yyvsp[0]; }
#line 1505 "trad3.tab.c"
    break;

  case 22: /* sentencia: INTEGER definicion  */
#line 155 "trad3.y"
                                            { sprintf (temp, "(setq %s_%s)", funcion_actual, yyvsp[0].code) ;  
                                           yyval.code = gen_code (temp) ; }
#line 1512 "trad3.tab.c"
    break;

  case 23: /* sentencia: INTEGER definicion ',' definiciones  */
#line 157 "trad3.y"
                                                         { sprintf (temp, "(setq %s_%s) %s", funcion_actual, yyvsp[-2].code, yyvsp[0].code) ;  
                                           	    yyval.code = gen_code (temp) ; }
#line 1519 "trad3.tab.c"
    break;

  case 24: /* sentencia: IDENTIF '=' expresion  */
#line 159 "trad3.y"
                                             { if (variable_local(yyvsp[-2].code)) { sprintf (temp, "(setf %s_%s %s)", funcion_actual, yyvsp[-2].code, yyvsp[0].code);
					   } else { sprintf (temp, "(setf %s %s)", yyvsp[-2].code, yyvsp[0].code); }
                                           yyval.code = gen_code (temp) ; }
#line 1527 "trad3.tab.c"
    break;

  case 25: /* sentencia: IDENTIF '[' expresion ']' '=' expresion  */
#line 162 "trad3.y"
                                                      { if (variable_local(yyvsp[-5].code)) { sprintf (temp, "(setf (aref %s_%s %s) %s)", funcion_actual, yyvsp[-5].code, yyvsp[-3].code, yyvsp[0].code);
            						} else { sprintf (temp, "(setf (aref %s %s) %s)", yyvsp[-5].code, yyvsp[-3].code, yyvsp[0].code); }
                                           		yyval.code = gen_code (temp) ; }
#line 1535 "trad3.tab.c"
    break;

  case 26: /* sentencia: PRINTF '(' expresion ',' expresiones_print ')'  */
#line 165 "trad3.y"
                                                                  { sprintf (temp, "%s", yyvsp[-1].code) ;  
                                           yyval.code = gen_code (temp) ; }
#line 1542 "trad3.tab.c"
    break;

  case 27: /* sentencia: PUTS '(' STRING ')'  */
#line 167 "trad3.y"
                                         { sprintf (temp, "(print \"%s\")", yyvsp[-1].code) ;  
                                           yyval.code = gen_code (temp) ; }
#line 1549 "trad3.tab.c"
    break;

  case 28: /* sentencia: IDENTIF '(' parametros_extra ')'  */
#line 169 "trad3.y"
                                                   { sprintf (temp, "(%s %s)", yyvsp[-3].code, yyvsp[-1].code);
                                                     yyval.code = gen_code (temp) ; }
#line 1556 "trad3.tab.c"
    break;

  case 29: /* sentencia: IDENTIF '(' ')'  */
#line 171 "trad3.y"
                                         { sprintf (temp, "(%s)", yyvsp[-2].code) ;
                                	   yyval.code = gen_code (temp) ; }
#line 1563 "trad3.tab.c"
    break;

  case 30: /* sentencia: RETURN expresion  */
#line 173 "trad3.y"
                                         { sprintf(temp, "(return-from %s %s)", funcion_actual, yyvsp[0].code);
                            		   yyval.code = gen_code(temp);}
#line 1570 "trad3.tab.c"
    break;

  case 31: /* sentencia: '@' expresion  */
#line 175 "trad3.y"
                             { 
                sprintf(temp, "(print %s)", yyvsp[0].code);
                yyval.code = gen_code(temp); 
              }
#line 1579 "trad3.tab.c"
    break;

  case 32: /* sentencia: '@' condicion  */
#line 179 "trad3.y"
                             { 
             sprintf(temp, "(print %s)", yyvsp[0].code);
             yyval.code = gen_code(temp); 
           }
#line 1588 "trad3.tab.c"
    break;

  case 33: /* estructura: WHILE '(' condicion ')' '{' sentencias '}'  */
#line 186 "trad3.y"
                                                           { sprintf(temp, "(loop while %s do %s)", yyvsp[-4].code, yyvsp[-1].code);
                                                               yyval.code = gen_code(temp);}
#line 1595 "trad3.tab.c"
    break;

  case 34: /* estructura: IF '(' condicion ')' '{' sentencias_if '}'  */
#line 188 "trad3.y"
                                                           { sprintf(temp, "(if %s %s)", yyvsp[-4].code, yyvsp[-1].code);
                                                               yyval.code = gen_code(temp);}
#line 1602 "trad3.tab.c"
    break;

  case 35: /* estructura: IF '(' condicion ')' '{' sentencias_if '}' ELSE '{' sentencias_if '}'  */
#line 190 "trad3.y"
                                                                                        { sprintf(temp, "(if %s %s %s)", yyvsp[-8].code, yyvsp[-5].code, yyvsp[-1].code);
                                                                                            yyval.code = gen_code(temp);}
#line 1609 "trad3.tab.c"
    break;

  case 36: /* estructura: FOR '(' contador_for ';' condicion ';' incremento_decremento ')' '{' sentencias '}'  */
#line 192 "trad3.y"
                                                                                                  { sprintf(temp, "%s (loop while %s do %s %s)", yyvsp[-8].code,
                                                                                    yyvsp[-6].code, yyvsp[-1].code, yyvsp[-4].code) ;
                                                                                    yyval.code = gen_code (temp) ; }
#line 1617 "trad3.tab.c"
    break;

  case 37: /* sentencias_if: sentencia ';'  */
#line 197 "trad3.y"
                                { if (leer_parentesis(yyvsp[-1].code)) { sprintf (temp, "(progn %s)", yyvsp[-1].code) ;
				  } else { sprintf (temp, "%s", yyvsp[-1].code) ; }
                                  yyval.code = gen_code (temp) ; }
#line 1625 "trad3.tab.c"
    break;

  case 38: /* sentencias_if: estructura  */
#line 200 "trad3.y"
                                { yyval = yyvsp[0]; }
#line 1631 "trad3.tab.c"
    break;

  case 39: /* sentencias_if: sentencia ';' sentencias  */
#line 201 "trad3.y"
                                            { sprintf (temp, "(progn %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                	      yyval.code = gen_code (temp) ; }
#line 1638 "trad3.tab.c"
    break;

  case 40: /* sentencias_if: estructura sentencias  */
#line 203 "trad3.y"
                                            { sprintf (temp, "(progn %s %s)", yyvsp[-1].code, yyvsp[0].code) ;
                                                yyval.code = gen_code (temp) ; }
#line 1645 "trad3.tab.c"
    break;

  case 41: /* contador_for: INTEGER IDENTIF  */
#line 207 "trad3.y"
                                  { sprintf (temp, "(setq %s_%s 0)", funcion_actual, yyvsp[0].code) ;
                                 yyval.code = gen_code (temp) ; }
#line 1652 "trad3.tab.c"
    break;

  case 42: /* contador_for: INTEGER IDENTIF '=' termino  */
#line 209 "trad3.y"
                                          { sprintf (temp, "(setq %s_%s %s)", funcion_actual, yyvsp[-2].code, yyvsp[0].code) ;
                                            yyval.code = gen_code (temp) ; }
#line 1659 "trad3.tab.c"
    break;

  case 43: /* contador_for: IDENTIF '=' termino  */
#line 211 "trad3.y"
                                      { if (variable_local(yyvsp[-2].code)) { sprintf (temp, "(setf %s_%s %s)", funcion_actual, yyvsp[-2].code, yyvsp[0].code);
         				} else { sprintf (temp, "(setf %s %s)", yyvsp[-2].code, yyvsp[0].code); }
                                        yyval.code = gen_code (temp) ; }
#line 1667 "trad3.tab.c"
    break;

  case 44: /* incremento_decremento: IDENTIF '=' IDENTIF '+' NUMBER  */
#line 216 "trad3.y"
                                                      { if (variable_local(yyvsp[-4].code)) { sprintf (temp, "(setf %s_%s (+ %s_%s %d))", funcion_actual, yyvsp[-4].code, funcion_actual, yyvsp[-2].code, yyvsp[0].value);
					 } else { sprintf (temp, "(setf %s (+ %s %d))", yyvsp[-4].code, yyvsp[-2].code, yyvsp[0].value); }
                                         yyval.code = gen_code (temp) ; }
#line 1675 "trad3.tab.c"
    break;

  case 45: /* incremento_decremento: IDENTIF '=' IDENTIF '-' NUMBER  */
#line 219 "trad3.y"
                                       { if (variable_local(yyvsp[-4].code)) { sprintf (temp, "(setf %s_%s (- %s_%s %d))", funcion_actual, yyvsp[-4].code, funcion_actual, yyvsp[-2].code, yyvsp[0].value);
      					 } else { sprintf (temp, "(setf %s (- %s %d))", yyvsp[-4].code, yyvsp[-2].code, yyvsp[0].value); }
                                         yyval.code = gen_code (temp) ; }
#line 1683 "trad3.tab.c"
    break;

  case 46: /* definiciones: definicion ',' definiciones  */
#line 225 "trad3.y"
                                           { sprintf (temp, "(setq %s) %s", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1690 "trad3.tab.c"
    break;

  case 47: /* definiciones: definicion  */
#line 227 "trad3.y"
                                                 { sprintf (temp, "(setq %s)", yyvsp[0].code) ;  
                                           yyval.code = gen_code (temp) ; }
#line 1697 "trad3.tab.c"
    break;

  case 48: /* definicion: IDENTIF '=' termino  */
#line 231 "trad3.y"
                                         { if (strcmp(funcion_actual, "") != 0) { add_symbol(yyvsp[-2].code, funcion_actual); }
					   sprintf (temp, "%s %s", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1705 "trad3.tab.c"
    break;

  case 49: /* definicion: IDENTIF  */
#line 234 "trad3.y"
                                         { if (strcmp(funcion_actual, "") != 0) { add_symbol(yyvsp[0].code, funcion_actual); }
            				   sprintf (temp, "%s 0", yyvsp[0].code) ;  
                                           yyval.code = gen_code (temp) ; }
#line 1713 "trad3.tab.c"
    break;

  case 50: /* definicion: IDENTIF '[' NUMBER ']'  */
#line 237 "trad3.y"
                                         { if (strcmp(funcion_actual, "") != 0) { add_symbol(yyvsp[-3].code, funcion_actual); }
            				   sprintf (temp, "%s (make-array %d)", yyvsp[-3].code, yyvsp[-1].value) ;  
                                           yyval.code = gen_code (temp) ; }
#line 1721 "trad3.tab.c"
    break;

  case 51: /* expresiones_print: expresion ',' expresiones_print  */
#line 243 "trad3.y"
                                                     { sprintf (temp, "(princ %s) %s", yyvsp[-2].code, yyvsp[0].code); 
						       yyval.code = gen_code (temp) ; }
#line 1728 "trad3.tab.c"
    break;

  case 52: /* expresiones_print: expresion  */
#line 245 "trad3.y"
                                             { sprintf (temp, "(princ %s)", yyvsp[0].code) ;  
		                               yyval.code = gen_code (temp) ; }
#line 1735 "trad3.tab.c"
    break;

  case 53: /* expresion: termino  */
#line 250 "trad3.y"
                                         { yyval = yyvsp[0] ; }
#line 1741 "trad3.tab.c"
    break;

  case 54: /* expresion: expresion '+' expresion  */
#line 251 "trad3.y"
                                         { sprintf (temp, "(+ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1748 "trad3.tab.c"
    break;

  case 55: /* expresion: expresion '-' expresion  */
#line 253 "trad3.y"
                                         { sprintf (temp, "(- %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1755 "trad3.tab.c"
    break;

  case 56: /* expresion: expresion '*' expresion  */
#line 255 "trad3.y"
                                         { sprintf (temp, "(* %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1762 "trad3.tab.c"
    break;

  case 57: /* expresion: expresion '/' expresion  */
#line 257 "trad3.y"
                                         { sprintf (temp, "(/ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1769 "trad3.tab.c"
    break;

  case 58: /* expresion: expresion '%' expresion  */
#line 259 "trad3.y"
                                         { sprintf (temp, "(mod %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1776 "trad3.tab.c"
    break;

  case 59: /* expresion: STRING  */
#line 261 "trad3.y"
                                         { sprintf (temp, "\"%s\"", yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1783 "trad3.tab.c"
    break;

  case 60: /* expresion: IDENTIF '(' parametros_extra ')'  */
#line 263 "trad3.y"
                                                  { sprintf (temp, "(%s %s)", yyvsp[-3].code, yyvsp[-1].code) ;
                                                    yyval.code = gen_code (temp) ; }
#line 1790 "trad3.tab.c"
    break;

  case 61: /* expresion: IDENTIF '(' ')'  */
#line 265 "trad3.y"
                                         { sprintf (temp, "(%s)", yyvsp[-2].code) ;
                                	   yyval.code = gen_code (temp) ; }
#line 1797 "trad3.tab.c"
    break;

  case 62: /* expresion: IDENTIF '[' expresion ']'  */
#line 267 "trad3.y"
                                            { if (variable_local(yyvsp[-3].code)) { sprintf (temp, "(aref %s_%s %s)", funcion_actual, yyvsp[-3].code, yyvsp[-1].code);
            				      } else { sprintf (temp, "(aref %s %s)", yyvsp[-3].code, yyvsp[-1].code); }
                                              yyval.code = gen_code (temp) ; }
#line 1805 "trad3.tab.c"
    break;

  case 63: /* parametros_extra: expresion ',' parametros_extra  */
#line 273 "trad3.y"
                                                     { sprintf (temp, "%s %s", yyvsp[-2].code, yyvsp[0].code) ;
                                                       yyval.code = gen_code(temp);}
#line 1812 "trad3.tab.c"
    break;

  case 64: /* parametros_extra: expresion  */
#line 275 "trad3.y"
                                                     { sprintf (temp, "%s", yyvsp[0].code) ;
                                                       yyval.code = gen_code(temp);}
#line 1819 "trad3.tab.c"
    break;

  case 65: /* condicion: expresion AND expresion  */
#line 280 "trad3.y"
                                       { sprintf (temp, "(and %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1826 "trad3.tab.c"
    break;

  case 66: /* condicion: expresion OR expresion  */
#line 282 "trad3.y"
                                        { sprintf (temp, "(or %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1833 "trad3.tab.c"
    break;

  case 67: /* condicion: expresion NEQ expresion  */
#line 284 "trad3.y"
                                         { sprintf (temp, "(/= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1840 "trad3.tab.c"
    break;

  case 68: /* condicion: expresion EQ expresion  */
#line 286 "trad3.y"
                                        { sprintf (temp, "(= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1847 "trad3.tab.c"
    break;

  case 69: /* condicion: expresion '<' expresion  */
#line 288 "trad3.y"
                                         { sprintf (temp, "(< %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1854 "trad3.tab.c"
    break;

  case 70: /* condicion: expresion LEQ expresion  */
#line 290 "trad3.y"
                                         { sprintf (temp, "(<= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1861 "trad3.tab.c"
    break;

  case 71: /* condicion: expresion '>' expresion  */
#line 292 "trad3.y"
                                         { sprintf (temp, "(> %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1868 "trad3.tab.c"
    break;

  case 72: /* condicion: expresion GEQ expresion  */
#line 294 "trad3.y"
                                         { sprintf (temp, "(>= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1875 "trad3.tab.c"
    break;

  case 73: /* condicion: condicion AND condicion  */
#line 296 "trad3.y"
                                         { sprintf (temp, "(and %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1882 "trad3.tab.c"
    break;

  case 74: /* condicion: condicion OR condicion  */
#line 298 "trad3.y"
                                        { sprintf (temp, "(or %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1889 "trad3.tab.c"
    break;

  case 75: /* condicion: condicion NEQ condicion  */
#line 300 "trad3.y"
                                         { sprintf (temp, "(/= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1896 "trad3.tab.c"
    break;

  case 76: /* condicion: condicion EQ condicion  */
#line 302 "trad3.y"
                                        { sprintf (temp, "(= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1903 "trad3.tab.c"
    break;

  case 77: /* condicion: condicion '<' condicion  */
#line 304 "trad3.y"
                                         { sprintf (temp, "(< %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1910 "trad3.tab.c"
    break;

  case 78: /* condicion: condicion LEQ condicion  */
#line 306 "trad3.y"
                                         { sprintf (temp, "(<= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1917 "trad3.tab.c"
    break;

  case 79: /* condicion: condicion '>' condicion  */
#line 308 "trad3.y"
                                         { sprintf (temp, "(> %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1924 "trad3.tab.c"
    break;

  case 80: /* condicion: condicion GEQ condicion  */
#line 310 "trad3.y"
                                         { sprintf (temp, "(>= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1931 "trad3.tab.c"
    break;

  case 81: /* termino: operando  */
#line 315 "trad3.y"
                                                   { yyval = yyvsp[0] ; }
#line 1937 "trad3.tab.c"
    break;

  case 82: /* termino: '+' operando  */
#line 316 "trad3.y"
                                                   { sprintf (temp, "(+ %s)", yyvsp[0].code) ;
                                                     yyval.code = gen_code (temp) ; }
#line 1944 "trad3.tab.c"
    break;

  case 83: /* termino: '-' operando  */
#line 318 "trad3.y"
                                                   { sprintf (temp, "(- %s)", yyvsp[0].code) ;
                                                     yyval.code = gen_code (temp) ; }
#line 1951 "trad3.tab.c"
    break;

  case 84: /* operando: IDENTIF  */
#line 323 "trad3.y"
                                         { if (variable_local(yyvsp[0].code)) { sprintf (temp, "%s_%s", funcion_actual, yyvsp[0].code);
					   } else { sprintf (temp, "%s", yyvsp[0].code); }
                                           yyval.code = gen_code (temp) ; }
#line 1959 "trad3.tab.c"
    break;

  case 85: /* operando: NUMBER  */
#line 326 "trad3.y"
                                         { sprintf (temp, "%d", yyvsp[0].value) ;
                                           yyval.code = gen_code (temp) ; }
#line 1966 "trad3.tab.c"
    break;

  case 86: /* operando: '(' expresion ')'  */
#line 328 "trad3.y"
                                         { yyval = yyvsp[-1] ; }
#line 1972 "trad3.tab.c"
    break;


#line 1976 "trad3.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 331 "trad3.y"
                            // SECCION 4    Codigo en C

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
    "<",       '<',
    ">",       '>',
    "<=",	   LEQ,
    ">=",	   GEQ,
    "@",       '@',
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

    // Manejo especial para @
    if (c == '@') {
        return '@';  // Token para impresión rápida
    }
    
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

    if (strchr(ops_expandibles, c) != NULL) {
        cc = getchar();
        
        // Caso especial para operadores de comparación
        if ((c == '<' || c == '>') && cc == '=') {
            char op[3] = {c, '=', '\0'};
            yylval.code = gen_code(op);
            return (c == '<') ? LEQ : GEQ;
        }
        
        // Operadores simples
        if (c == '<' || c == '>') {
            ungetc(cc, stdin);
            return c;
        }
        
        // Resto de operadores compuestos
        sprintf(temp_str, "%c%c", (char)c, (char)cc);
        symbol = search_keyword(temp_str);
        if (symbol != NULL) {
            yylval.code = gen_code(temp_str);
            return symbol->token;
        }
        
        ungetc(cc, stdin);
        return c;
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
