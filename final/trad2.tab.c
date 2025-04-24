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
#line 3 "trad2.y"
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
// Definitions for explicit attributes

typedef struct s_attr {
        int value ;
        char *code ;
} t_attr ;

// Tabla de símbolos para diferenciar entre variables locales y globales
struct symbol {
    char name[50];
    char scope[50];
};

struct symbol symbol_table[100];
int symbol_count = 0;
char current_function[50] = "";

void add_symbol(char* name, char* scope) {
    strcpy(symbol_table[symbol_count].name, name);
    strcpy(symbol_table[symbol_count].scope, scope);
    symbol_count++;
}

int is_local(char* name) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0 && strcmp(symbol_table[i].scope, current_function) == 0) {
            return 1;
        }
    }
    return 0;
}

int read_paren(char* my_string) {
   int inside_paren = 0;
   int sentence = 0;
   for (int i = 0; my_string[i] != '\0'; i++) {
   	if (my_string[i] == '(') {
   	    if (inside_paren == 0 && sentence) {
   		return 1;
   	    }
   	    inside_paren++;
   	}
   	else if (my_string[i] == ')') {
   	    inside_paren--;
   	    sentence = 1;
   	}
   }		
   return 0;
}

#define YYSTYPE t_attr


#line 142 "trad2.tab.c"

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
  YYSYMBOL_programa = 41,                  /* programa  */
  YYSYMBOL_variables = 42,                 /* variables  */
  YYSYMBOL_variable = 43,                  /* variable  */
  YYSYMBOL_funciones = 44,                 /* funciones  */
  YYSYMBOL_funcion = 45,                   /* funcion  */
  YYSYMBOL_46_1 = 46,                      /* $@1  */
  YYSYMBOL_lista_parametros = 47,          /* lista_parametros  */
  YYSYMBOL_main = 48,                      /* main  */
  YYSYMBOL_49_2 = 49,                      /* $@2  */
  YYSYMBOL_sentencias = 50,                /* sentencias  */
  YYSYMBOL_sentencia = 51,                 /* sentencia  */
  YYSYMBOL_estructura = 52,                /* estructura  */
  YYSYMBOL_sentencias_if = 53,             /* sentencias_if  */
  YYSYMBOL_inicializ = 54,                 /* inicializ  */
  YYSYMBOL_incdec = 55,                    /* incdec  */
  YYSYMBOL_definiciones = 56,              /* definiciones  */
  YYSYMBOL_definir = 57,                   /* definir  */
  YYSYMBOL_expresiones_print = 58,         /* expresiones_print  */
  YYSYMBOL_expresion = 59,                 /* expresion  */
  YYSYMBOL_enter_parametros = 60,          /* enter_parametros  */
  YYSYMBOL_condicional = 61,               /* condicional  */
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
#define YYLAST   460

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  200

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
       0,   108,   108,   111,   112,   116,   117,   120,   121,   125,
     126,   129,   129,   135,   137,   139,   143,   143,   147,   149,
     151,   153,   156,   158,   160,   163,   166,   168,   170,   172,
     174,   176,   180,   187,   189,   191,   193,   198,   201,   202,
     204,   208,   210,   212,   217,   220,   226,   228,   232,   235,
     238,   244,   246,   251,   252,   254,   256,   258,   260,   262,
     264,   266,   268,   271,   274,   276,   281,   283,   285,   287,
     289,   291,   293,   295,   297,   299,   301,   303,   305,   307,
     309,   311,   315,   316,   318,   322,   325,   327
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
  "programa", "variables", "variable", "funciones", "funcion", "$@1",
  "lista_parametros", "main", "$@2", "sentencias", "sentencia",
  "estructura", "sentencias_if", "inicializ", "incdec", "definiciones",
  "definir", "expresiones_print", "expresion", "enter_parametros",
  "condicional", "termino", "operando", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-146)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-82)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     104,  -146,     0,  -146,    57,  -146,   118,     8,  -146,   118,
    -146,   -18,    16,   102,    17,  -146,  -146,  -146,  -146,    61,
      59,    74,  -146,     0,    68,    89,    79,  -146,  -146,    13,
      13,    72,  -146,  -146,    85,    75,    83,    82,    95,   124,
    -146,  -146,    50,  -146,   201,   436,  -146,  -146,  -146,     0,
     403,    61,   403,    15,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,  -146,    72,
      72,    72,    72,    72,    72,    72,    72,  -146,    77,     0,
     107,   145,   157,   158,   165,    72,    72,   166,   172,   403,
    -146,   170,  -146,   265,   174,   137,   402,   377,   417,   417,
     129,   129,   129,   129,   117,   117,  -146,  -146,  -146,   358,
     173,   105,    36,   237,    48,    69,   161,   232,    72,    39,
      72,   177,    72,   204,    72,    72,   169,   358,   358,   331,
    -146,   403,  -146,  -146,    72,  -146,  -146,   358,  -146,   184,
     156,     0,   225,   185,   287,   231,   198,   217,   191,  -146,
    -146,  -146,   209,  -146,   188,  -146,    72,   197,    59,   211,
      72,    72,   403,   200,   309,   403,  -146,    59,   337,   358,
     214,  -146,    72,   220,   403,   221,  -146,   252,  -146,  -146,
     403,  -146,   240,   245,   228,  -146,   238,   268,   239,   403,
     151,   403,   246,   280,   281,   249,  -146,  -146,  -146,  -146
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    11,     0,    16,     0,     2,     0,     6,     4,     0,
      10,     0,    49,     0,     0,     1,     3,     5,     9,    15,
       0,     0,     7,     0,     0,     0,     0,    86,    85,     0,
       0,     0,    48,    82,     0,     0,    47,     0,    14,     0,
      83,    84,    85,    59,     0,    63,    53,    50,     8,     0,
       0,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    87,     0,
       0,     0,     0,     0,     0,     0,     0,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
      13,     0,    61,    65,     0,     0,    66,    67,    68,    69,
      71,    73,    70,    72,    54,    55,    56,    57,    58,     0,
      63,    63,    63,    63,    63,    63,    63,    63,     0,     0,
       0,    22,     0,     0,     0,     0,     0,    30,    31,    63,
      17,    19,    20,    12,     0,    60,    62,    24,    29,     0,
       0,     0,    63,     0,     0,    63,     0,     0,     0,    18,
      64,    28,     0,    23,     0,    27,     0,     0,     0,    41,
       0,     0,     0,     0,    52,     0,    43,     0,    63,    25,
       0,    26,     0,     0,    38,     0,    42,     0,    33,    51,
      37,    40,    34,     0,     0,    39,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    35,    44,    45,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -146,  -146,  -146,   279,  -146,   126,  -146,  -146,   236,  -146,
    -146,   -50,  -145,  -118,   106,  -146,  -146,   -46,    12,   132,
     -30,   -65,   -64,   -20,   171
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,     9,    11,    26,    10,
      14,    87,    88,    89,   175,   148,   184,    35,    36,   163,
     109,    94,    45,    46,    33
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,    44,    91,    77,    12,   110,   111,   112,   113,   114,
     115,   116,   117,     2,    13,    19,    27,    28,    27,    42,
     173,    43,   129,    93,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    20,   132,
      29,    30,    27,    42,   173,    43,    31,   174,    31,    92,
      24,    73,    74,    21,   139,   127,   128,    15,   142,    75,
      76,   145,    27,    28,    29,    30,    25,   -76,   -76,   150,
     -76,   174,    31,   138,   -76,    27,    42,    34,    43,   -79,
     -79,   149,   -79,    53,    29,    30,   -79,    54,   137,    93,
     140,   121,    31,    38,   144,   153,   168,    29,    30,   118,
     -81,   -81,    37,   -81,    93,    31,    48,   -81,     1,     2,
     119,     3,   170,    39,   120,    49,    69,    50,    71,    72,
      73,    74,     1,    47,   181,     3,   164,    51,    75,    76,
     185,   169,    16,    22,    23,    18,   -75,   -75,   166,   -75,
     122,   195,   164,   -75,    65,    66,    67,   176,    55,    56,
      57,    58,    59,    60,    63,    64,    65,    66,    67,    52,
      61,    62,    63,    64,    65,    66,    67,    55,    56,    57,
      58,    59,    60,   146,   147,   136,   193,   194,   123,    61,
      62,    63,    64,    65,    66,    67,    71,    72,    73,    74,
     124,   125,   -78,   -78,   152,   -78,    75,    76,   126,   -78,
      40,    41,   130,   131,   -74,   -74,   133,   -74,   135,   141,
     143,   -74,    55,    56,    57,    58,    59,    60,   151,   155,
     158,   159,   160,   162,    61,    62,    63,    64,    65,    66,
      67,   161,   165,   167,   171,    68,    69,    70,    71,    72,
      73,    74,    69,    70,    71,    72,    73,    74,    75,    76,
     178,   180,    73,    74,    75,    76,   183,   182,   186,   154,
      75,    76,   188,   -80,   -80,   157,   -80,   187,   -77,   -77,
     -80,   -77,   190,   189,   191,   -77,    55,    56,    57,    58,
      59,    60,   196,   197,   198,   199,    17,    90,    61,    62,
      63,    64,    65,    66,    67,   192,     0,   134,    55,    56,
      57,    58,    59,    60,   179,     0,     0,     0,     0,     0,
      61,    62,    63,    64,    65,    66,    67,     0,     0,   156,
      55,    56,    57,    58,    59,    60,     0,     0,     0,     0,
       0,     0,    61,    62,    63,    64,    65,    66,    67,     0,
       0,   172,    69,    70,    71,    72,    73,    74,    69,    70,
      71,    72,    73,    74,    75,    76,     0,     0,     0,     0,
      75,    76,   -32,     0,     0,     0,     0,     0,   177,    55,
      56,    57,    58,    59,    60,     0,     0,     0,     0,     0,
       0,    61,    62,    63,    64,    65,    66,    67,    55,     0,
      57,    58,    59,    60,     0,     0,     0,     0,     0,     0,
      61,    62,    63,    64,    65,    66,    67,    78,    79,     0,
       0,    80,    81,    82,     0,    57,    58,    59,    60,     0,
      83,     0,    84,    85,    86,    61,    62,    63,    64,    65,
      66,    67,    59,    60,     0,     0,     0,     0,     0,     0,
      61,    62,    63,    64,    65,    66,    67,    69,    70,    71,
      72,    73,    74,     0,     0,     0,     0,     0,     0,    75,
      76
};

static const yytype_int16 yycheck[] =
{
      20,    31,    52,    49,     4,    69,    70,    71,    72,    73,
      74,    75,    76,     5,     2,    33,     3,     4,     3,     4,
     165,     6,    86,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    22,    89,
      25,    26,     3,     4,   189,     6,    33,   165,    33,    34,
      33,    15,    16,    37,   119,    85,    86,     0,   122,    23,
      24,   125,     3,     4,    25,    26,     5,    31,    32,   134,
      34,   189,    33,    34,    38,     3,     4,     3,     6,    31,
      32,   131,    34,    33,    25,    26,    38,    37,   118,   119,
     120,    79,    33,     4,   124,   141,   160,    25,    26,    22,
      31,    32,    34,    34,   134,    33,    31,    38,     4,     5,
      33,     7,   162,    34,    37,    32,    11,    35,    13,    14,
      15,    16,     4,    38,   174,     7,   156,    32,    23,    24,
     180,   161,     6,    31,    32,     9,    31,    32,   158,    34,
      33,   191,   172,    38,    27,    28,    29,   167,    11,    12,
      13,    14,    15,    16,    25,    26,    27,    28,    29,    35,
      23,    24,    25,    26,    27,    28,    29,    11,    12,    13,
      14,    15,    16,     4,     5,    38,    25,    26,    33,    23,
      24,    25,    26,    27,    28,    29,    13,    14,    15,    16,
      33,    33,    31,    32,    38,    34,    23,    24,    33,    38,
      29,    30,    36,    31,    31,    32,    36,    34,    34,    32,
       6,    38,    11,    12,    13,    14,    15,    16,    34,    34,
      22,     4,    31,    35,    23,    24,    25,    26,    27,    28,
      29,    22,    35,    22,    34,    34,    11,    12,    13,    14,
      15,    16,    11,    12,    13,    14,    15,    16,    23,    24,
      36,    31,    15,    16,    23,    24,     4,    36,    18,    34,
      23,    24,    34,    31,    32,    34,    34,    22,    31,    32,
      38,    34,     4,    35,    35,    38,    11,    12,    13,    14,
      15,    16,    36,     3,     3,    36,     7,    51,    23,    24,
      25,    26,    27,    28,    29,   189,    -1,    32,    11,    12,
      13,    14,    15,    16,   172,    -1,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    27,    28,    29,    -1,    -1,    32,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    32,    11,    12,    13,    14,    15,    16,    11,    12,
      13,    14,    15,    16,    23,    24,    -1,    -1,    -1,    -1,
      23,    24,    31,    -1,    -1,    -1,    -1,    -1,    31,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    11,    -1,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    27,    28,    29,     4,     5,    -1,
      -1,     8,     9,    10,    -1,    13,    14,    15,    16,    -1,
      17,    -1,    19,    20,    21,    23,    24,    25,    26,    27,
      28,    29,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    27,    28,    29,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      24
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,     7,    40,    41,    42,    43,    44,    45,
      48,    46,     4,    57,    49,     0,    44,    42,    44,    33,
      22,    37,    31,    32,    33,     5,    47,     3,     4,    25,
      26,    33,    62,    63,     3,    56,    57,    34,     4,    34,
      63,    63,     4,     6,    59,    61,    62,    38,    31,    32,
      35,    32,    35,    33,    37,    11,    12,    13,    14,    15,
      16,    23,    24,    25,    26,    27,    28,    29,    34,    11,
      12,    13,    14,    15,    16,    23,    24,    56,     4,     5,
       8,     9,    10,    17,    19,    20,    21,    50,    51,    52,
      47,    50,    34,    59,    60,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      61,    61,    61,    61,    61,    61,    61,    61,    22,    33,
      37,    57,    33,    33,    33,    33,    33,    59,    59,    61,
      36,    31,    50,    36,    32,    34,    38,    59,    34,    60,
      59,    32,    61,     6,    59,    61,     4,     5,    54,    50,
      60,    34,    38,    56,    34,    34,    32,    34,    22,     4,
      31,    22,    35,    58,    59,    35,    62,    22,    61,    59,
      50,    34,    32,    51,    52,    53,    62,    31,    36,    58,
      31,    50,    36,     4,    55,    50,    18,    22,    34,    35,
       4,    35,    53,    25,    26,    50,    36,     3,     3,    36
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
      59,    59,    59,    59,    60,    60,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    62,    63,    63,    63
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
       4,     3,     4,     1,     3,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     2,     2,     1,     1,     3
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
  case 2: /* axioma: programa  */
#line 108 "trad2.y"
                                   { ; }
#line 1420 "trad2.tab.c"
    break;

  case 3: /* programa: variables funciones  */
#line 111 "trad2.y"
                                          { ; }
#line 1426 "trad2.tab.c"
    break;

  case 4: /* programa: funciones  */
#line 112 "trad2.y"
                                          { ; }
#line 1432 "trad2.tab.c"
    break;

  case 5: /* variables: variable variables  */
#line 116 "trad2.y"
                               { ; }
#line 1438 "trad2.tab.c"
    break;

  case 6: /* variables: variable  */
#line 117 "trad2.y"
                               { ; }
#line 1444 "trad2.tab.c"
    break;

  case 7: /* variable: INTEGER definir ';'  */
#line 120 "trad2.y"
                                                 { printf ("(setq %s)\n", yyvsp[-1].code) ;  }
#line 1450 "trad2.tab.c"
    break;

  case 8: /* variable: INTEGER definir ',' definiciones ';'  */
#line 121 "trad2.y"
                                                 { printf ("(setq %s) %s\n", yyvsp[-3].code, yyvsp[-1].code) ; }
#line 1456 "trad2.tab.c"
    break;

  case 9: /* funciones: funcion funciones  */
#line 125 "trad2.y"
                                { ; }
#line 1462 "trad2.tab.c"
    break;

  case 10: /* funciones: main  */
#line 126 "trad2.y"
                                { ; }
#line 1468 "trad2.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 129 "trad2.y"
                   { sprintf (current_function, "%s", yyvsp[0].code); }
#line 1474 "trad2.tab.c"
    break;

  case 12: /* funcion: IDENTIF $@1 '(' lista_parametros ')' '{' sentencias '}'  */
#line 130 "trad2.y"
                                                        { if (strcmp(yyvsp[-4].code, " ") != 0) { printf("(defun %s(%s) %s)\n", yyvsp[-7].code, yyvsp[-4].code, yyvsp[-1].code);
							  } else { printf("(defun %s() %s)\n", yyvsp[-7].code, yyvsp[-1].code); }
							  strcpy(current_function, ""); }
#line 1482 "trad2.tab.c"
    break;

  case 13: /* lista_parametros: INTEGER IDENTIF ',' lista_parametros  */
#line 135 "trad2.y"
                                                          { sprintf (temp, "%s %s", yyvsp[-2].code, yyvsp[0].code) ;
                                                            yyval.code = gen_code(temp);}
#line 1489 "trad2.tab.c"
    break;

  case 14: /* lista_parametros: INTEGER IDENTIF  */
#line 137 "trad2.y"
                                                          { sprintf (temp, "%s", yyvsp[0].code) ;
                                                            yyval.code = gen_code(temp);}
#line 1496 "trad2.tab.c"
    break;

  case 15: /* lista_parametros: %empty  */
#line 139 "trad2.y"
                                                          { sprintf (temp, " ") ;
                                                            yyval.code = gen_code(temp);}
#line 1503 "trad2.tab.c"
    break;

  case 16: /* $@2: %empty  */
#line 143 "trad2.y"
                  { sprintf (current_function, "%s", yyvsp[0].code); }
#line 1509 "trad2.tab.c"
    break;

  case 17: /* main: MAIN $@2 '(' ')' '{' sentencias '}'  */
#line 143 "trad2.y"
                                                                                             { printf("(defun main() %s)\n", yyvsp[-1].code);}
#line 1515 "trad2.tab.c"
    break;

  case 18: /* sentencias: sentencia ';' sentencias  */
#line 147 "trad2.y"
                                         { sprintf(temp, "%s %s", yyvsp[-2].code, yyvsp[0].code);
                                         yyval.code = gen_code(temp);}
#line 1522 "trad2.tab.c"
    break;

  case 19: /* sentencias: sentencia ';'  */
#line 149 "trad2.y"
                                       { sprintf (temp, "%s", yyvsp[-1].code) ;
                                         yyval.code = gen_code(temp);}
#line 1529 "trad2.tab.c"
    break;

  case 20: /* sentencias: estructura sentencias  */
#line 151 "trad2.y"
                                       { sprintf(temp, "%s %s", yyvsp[-1].code, yyvsp[0].code);
                                         yyval.code = gen_code(temp);}
#line 1536 "trad2.tab.c"
    break;

  case 21: /* sentencias: estructura  */
#line 153 "trad2.y"
                                       { yyval = yyvsp[0]; }
#line 1542 "trad2.tab.c"
    break;

  case 22: /* sentencia: INTEGER definir  */
#line 156 "trad2.y"
                                         { sprintf (temp, "(setq %s_%s)", current_function, yyvsp[0].code) ;  
                                           yyval.code = gen_code (temp) ; }
#line 1549 "trad2.tab.c"
    break;

  case 23: /* sentencia: INTEGER definir ',' definiciones  */
#line 158 "trad2.y"
                                                  { sprintf (temp, "(setq %s_%s) %s", current_function, yyvsp[-2].code, yyvsp[0].code) ;  
                                           	    yyval.code = gen_code (temp) ; }
#line 1556 "trad2.tab.c"
    break;

  case 24: /* sentencia: IDENTIF '=' expresion  */
#line 160 "trad2.y"
                                         { if (is_local(yyvsp[-2].code)) { sprintf (temp, "(setf %s_%s %s)", current_function, yyvsp[-2].code, yyvsp[0].code);
					   } else { sprintf (temp, "(setf %s %s)", yyvsp[-2].code, yyvsp[0].code); }
                                           yyval.code = gen_code (temp) ; }
#line 1564 "trad2.tab.c"
    break;

  case 25: /* sentencia: IDENTIF '[' expresion ']' '=' expresion  */
#line 163 "trad2.y"
                                                      { if (is_local(yyvsp[-5].code)) { sprintf (temp, "(setf (aref %s_%s %s) %s)", current_function, yyvsp[-5].code, yyvsp[-3].code, yyvsp[0].code);
            						} else { sprintf (temp, "(setf (aref %s %s) %s)", yyvsp[-5].code, yyvsp[-3].code, yyvsp[0].code); }
                                           		yyval.code = gen_code (temp) ; }
#line 1572 "trad2.tab.c"
    break;

  case 26: /* sentencia: PRINTF '(' expresion ',' expresiones_print ')'  */
#line 166 "trad2.y"
                                                                  { sprintf (temp, "%s", yyvsp[-1].code) ;  
                                           yyval.code = gen_code (temp) ; }
#line 1579 "trad2.tab.c"
    break;

  case 27: /* sentencia: PUTS '(' STRING ')'  */
#line 168 "trad2.y"
                                         { sprintf (temp, "(print \"%s\")", yyvsp[-1].code) ;  
                                           yyval.code = gen_code (temp) ; }
#line 1586 "trad2.tab.c"
    break;

  case 28: /* sentencia: IDENTIF '(' enter_parametros ')'  */
#line 170 "trad2.y"
                                                   { sprintf (temp, "(%s %s)", yyvsp[-3].code, yyvsp[-1].code);
                                                     yyval.code = gen_code (temp) ; }
#line 1593 "trad2.tab.c"
    break;

  case 29: /* sentencia: IDENTIF '(' ')'  */
#line 172 "trad2.y"
                                         { sprintf (temp, "(%s)", yyvsp[-2].code) ;
                                	   yyval.code = gen_code (temp) ; }
#line 1600 "trad2.tab.c"
    break;

  case 30: /* sentencia: RETURN expresion  */
#line 174 "trad2.y"
                                         { sprintf(temp, "(return-from %s %s)", current_function, yyvsp[0].code);
                            		   yyval.code = gen_code(temp);}
#line 1607 "trad2.tab.c"
    break;

  case 31: /* sentencia: '@' expresion  */
#line 176 "trad2.y"
                             { 
                sprintf(temp, "(print %s)", yyvsp[0].code);
                yyval.code = gen_code(temp); 
              }
#line 1616 "trad2.tab.c"
    break;

  case 32: /* sentencia: '@' condicional  */
#line 180 "trad2.y"
                               { 
             sprintf(temp, "(print %s)", yyvsp[0].code);
             yyval.code = gen_code(temp); 
           }
#line 1625 "trad2.tab.c"
    break;

  case 33: /* estructura: WHILE '(' condicional ')' '{' sentencias '}'  */
#line 187 "trad2.y"
                                                             { sprintf(temp, "(loop while %s do %s)", yyvsp[-4].code, yyvsp[-1].code);
                                                               yyval.code = gen_code(temp);}
#line 1632 "trad2.tab.c"
    break;

  case 34: /* estructura: IF '(' condicional ')' '{' sentencias_if '}'  */
#line 189 "trad2.y"
                                                             { sprintf(temp, "(if %s %s)", yyvsp[-4].code, yyvsp[-1].code);
                                                               yyval.code = gen_code(temp);}
#line 1639 "trad2.tab.c"
    break;

  case 35: /* estructura: IF '(' condicional ')' '{' sentencias_if '}' ELSE '{' sentencias_if '}'  */
#line 191 "trad2.y"
                                                                                          { sprintf(temp, "(if %s %s %s)", yyvsp[-8].code, yyvsp[-5].code, yyvsp[-1].code);
                                                                                            yyval.code = gen_code(temp);}
#line 1646 "trad2.tab.c"
    break;

  case 36: /* estructura: FOR '(' inicializ ';' condicional ';' incdec ')' '{' sentencias '}'  */
#line 193 "trad2.y"
                                                                                  { sprintf(temp, "%s (loop while %s do %s %s)", yyvsp[-8].code,
                                                                                    yyvsp[-6].code, yyvsp[-1].code, yyvsp[-4].code) ;
                                                                                    yyval.code = gen_code (temp) ; }
#line 1654 "trad2.tab.c"
    break;

  case 37: /* sentencias_if: sentencia ';'  */
#line 198 "trad2.y"
                                { if (read_paren(yyvsp[-1].code)) { sprintf (temp, "(progn %s)", yyvsp[-1].code) ;
				  } else { sprintf (temp, "%s", yyvsp[-1].code) ; }
                                  yyval.code = gen_code (temp) ; }
#line 1662 "trad2.tab.c"
    break;

  case 38: /* sentencias_if: estructura  */
#line 201 "trad2.y"
                                { yyval = yyvsp[0]; }
#line 1668 "trad2.tab.c"
    break;

  case 39: /* sentencias_if: sentencia ';' sentencias  */
#line 202 "trad2.y"
                                            { sprintf (temp, "(progn %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                	      yyval.code = gen_code (temp) ; }
#line 1675 "trad2.tab.c"
    break;

  case 40: /* sentencias_if: estructura sentencias  */
#line 204 "trad2.y"
                                            { sprintf (temp, "(progn %s %s)", yyvsp[-1].code, yyvsp[0].code) ;
                                                yyval.code = gen_code (temp) ; }
#line 1682 "trad2.tab.c"
    break;

  case 41: /* inicializ: INTEGER IDENTIF  */
#line 208 "trad2.y"
                               { sprintf (temp, "(setq %s_%s 0)", current_function, yyvsp[0].code) ;
                                 yyval.code = gen_code (temp) ; }
#line 1689 "trad2.tab.c"
    break;

  case 42: /* inicializ: INTEGER IDENTIF '=' termino  */
#line 210 "trad2.y"
                                          { sprintf (temp, "(setq %s_%s %s)", current_function, yyvsp[-2].code, yyvsp[0].code) ;
                                            yyval.code = gen_code (temp) ; }
#line 1696 "trad2.tab.c"
    break;

  case 43: /* inicializ: IDENTIF '=' termino  */
#line 212 "trad2.y"
                                      { if (is_local(yyvsp[-2].code)) { sprintf (temp, "(setf %s_%s %s)", current_function, yyvsp[-2].code, yyvsp[0].code);
         				} else { sprintf (temp, "(setf %s %s)", yyvsp[-2].code, yyvsp[0].code); }
                                        yyval.code = gen_code (temp) ; }
#line 1704 "trad2.tab.c"
    break;

  case 44: /* incdec: IDENTIF '=' IDENTIF '+' NUMBER  */
#line 217 "trad2.y"
                                       { if (is_local(yyvsp[-4].code)) { sprintf (temp, "(setf %s_%s (+ %s_%s %d))", current_function, yyvsp[-4].code, current_function, yyvsp[-2].code, yyvsp[0].value);
					 } else { sprintf (temp, "(setf %s (+ %s %d))", yyvsp[-4].code, yyvsp[-2].code, yyvsp[0].value); }
                                         yyval.code = gen_code (temp) ; }
#line 1712 "trad2.tab.c"
    break;

  case 45: /* incdec: IDENTIF '=' IDENTIF '-' NUMBER  */
#line 220 "trad2.y"
                                       { if (is_local(yyvsp[-4].code)) { sprintf (temp, "(setf %s_%s (- %s_%s %d))", current_function, yyvsp[-4].code, current_function, yyvsp[-2].code, yyvsp[0].value);
      					 } else { sprintf (temp, "(setf %s (- %s %d))", yyvsp[-4].code, yyvsp[-2].code, yyvsp[0].value); }
                                         yyval.code = gen_code (temp) ; }
#line 1720 "trad2.tab.c"
    break;

  case 46: /* definiciones: definir ',' definiciones  */
#line 226 "trad2.y"
                                        { sprintf (temp, "(setq %s) %s", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1727 "trad2.tab.c"
    break;

  case 47: /* definiciones: definir  */
#line 228 "trad2.y"
                                         { sprintf (temp, "(setq %s)", yyvsp[0].code) ;  
                                           yyval.code = gen_code (temp) ; }
#line 1734 "trad2.tab.c"
    break;

  case 48: /* definir: IDENTIF '=' termino  */
#line 232 "trad2.y"
                                         { if (strcmp(current_function, "") != 0) { add_symbol(yyvsp[-2].code, current_function); }
					   sprintf (temp, "%s %s", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1742 "trad2.tab.c"
    break;

  case 49: /* definir: IDENTIF  */
#line 235 "trad2.y"
                                         { if (strcmp(current_function, "") != 0) { add_symbol(yyvsp[0].code, current_function); }
            				   sprintf (temp, "%s 0", yyvsp[0].code) ;  
                                           yyval.code = gen_code (temp) ; }
#line 1750 "trad2.tab.c"
    break;

  case 50: /* definir: IDENTIF '[' NUMBER ']'  */
#line 238 "trad2.y"
                                         { if (strcmp(current_function, "") != 0) { add_symbol(yyvsp[-3].code, current_function); }
            				   sprintf (temp, "%s (make-array %d)", yyvsp[-3].code, yyvsp[-1].value) ;  
                                           yyval.code = gen_code (temp) ; }
#line 1758 "trad2.tab.c"
    break;

  case 51: /* expresiones_print: expresion ',' expresiones_print  */
#line 244 "trad2.y"
                                                     { sprintf (temp, "(print %s) %s", yyvsp[-2].code, yyvsp[0].code); 
						       yyval.code = gen_code (temp) ; }
#line 1765 "trad2.tab.c"
    break;

  case 52: /* expresiones_print: expresion  */
#line 246 "trad2.y"
                                             { sprintf (temp, "(print %s)", yyvsp[0].code) ;  
		                               yyval.code = gen_code (temp) ; }
#line 1772 "trad2.tab.c"
    break;

  case 53: /* expresion: termino  */
#line 251 "trad2.y"
                                         { yyval = yyvsp[0] ; }
#line 1778 "trad2.tab.c"
    break;

  case 54: /* expresion: expresion '+' expresion  */
#line 252 "trad2.y"
                                         { sprintf (temp, "(+ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1785 "trad2.tab.c"
    break;

  case 55: /* expresion: expresion '-' expresion  */
#line 254 "trad2.y"
                                         { sprintf (temp, "(- %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1792 "trad2.tab.c"
    break;

  case 56: /* expresion: expresion '*' expresion  */
#line 256 "trad2.y"
                                         { sprintf (temp, "(* %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1799 "trad2.tab.c"
    break;

  case 57: /* expresion: expresion '/' expresion  */
#line 258 "trad2.y"
                                         { sprintf (temp, "(/ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1806 "trad2.tab.c"
    break;

  case 58: /* expresion: expresion '%' expresion  */
#line 260 "trad2.y"
                                         { sprintf (temp, "(mod %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1813 "trad2.tab.c"
    break;

  case 59: /* expresion: STRING  */
#line 262 "trad2.y"
                                         { sprintf (temp, "\"%s\"", yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1820 "trad2.tab.c"
    break;

  case 60: /* expresion: IDENTIF '(' enter_parametros ')'  */
#line 264 "trad2.y"
                                                  { sprintf (temp, "(%s %s)", yyvsp[-3].code, yyvsp[-1].code) ;
                                                    yyval.code = gen_code (temp) ; }
#line 1827 "trad2.tab.c"
    break;

  case 61: /* expresion: IDENTIF '(' ')'  */
#line 266 "trad2.y"
                                         { sprintf (temp, "(%s)", yyvsp[-2].code) ;
                                	   yyval.code = gen_code (temp) ; }
#line 1834 "trad2.tab.c"
    break;

  case 62: /* expresion: IDENTIF '[' expresion ']'  */
#line 268 "trad2.y"
                                            { if (is_local(yyvsp[-3].code)) { sprintf (temp, "(aref %s_%s %s)", current_function, yyvsp[-3].code, yyvsp[-1].code);
            				      } else { sprintf (temp, "(aref %s %s)", yyvsp[-3].code, yyvsp[-1].code); }
                                              yyval.code = gen_code (temp) ; }
#line 1842 "trad2.tab.c"
    break;

  case 63: /* expresion: condicional  */
#line 271 "trad2.y"
                                         { yyval = yyvsp[0]; }
#line 1848 "trad2.tab.c"
    break;

  case 64: /* enter_parametros: expresion ',' enter_parametros  */
#line 274 "trad2.y"
                                                     { sprintf (temp, "%s %s", yyvsp[-2].code, yyvsp[0].code) ;
                                                       yyval.code = gen_code(temp);}
#line 1855 "trad2.tab.c"
    break;

  case 65: /* enter_parametros: expresion  */
#line 276 "trad2.y"
                                                     { sprintf (temp, "%s", yyvsp[0].code) ;
                                                       yyval.code = gen_code(temp);}
#line 1862 "trad2.tab.c"
    break;

  case 66: /* condicional: expresion AND expresion  */
#line 281 "trad2.y"
                                         { sprintf (temp, "(and %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1869 "trad2.tab.c"
    break;

  case 67: /* condicional: expresion OR expresion  */
#line 283 "trad2.y"
                                        { sprintf (temp, "(or %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1876 "trad2.tab.c"
    break;

  case 68: /* condicional: expresion NEQ expresion  */
#line 285 "trad2.y"
                                         { sprintf (temp, "(/= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1883 "trad2.tab.c"
    break;

  case 69: /* condicional: expresion EQ expresion  */
#line 287 "trad2.y"
                                        { sprintf (temp, "(= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1890 "trad2.tab.c"
    break;

  case 70: /* condicional: expresion '<' expresion  */
#line 289 "trad2.y"
                                         { sprintf (temp, "(< %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1897 "trad2.tab.c"
    break;

  case 71: /* condicional: expresion LEQ expresion  */
#line 291 "trad2.y"
                                         { sprintf (temp, "(<= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1904 "trad2.tab.c"
    break;

  case 72: /* condicional: expresion '>' expresion  */
#line 293 "trad2.y"
                                         { sprintf (temp, "(> %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1911 "trad2.tab.c"
    break;

  case 73: /* condicional: expresion GEQ expresion  */
#line 295 "trad2.y"
                                         { sprintf (temp, "(>= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1918 "trad2.tab.c"
    break;

  case 74: /* condicional: condicional AND condicional  */
#line 297 "trad2.y"
                                             { sprintf (temp, "(and %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1925 "trad2.tab.c"
    break;

  case 75: /* condicional: condicional OR condicional  */
#line 299 "trad2.y"
                                            { sprintf (temp, "(or %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1932 "trad2.tab.c"
    break;

  case 76: /* condicional: condicional NEQ condicional  */
#line 301 "trad2.y"
                                             { sprintf (temp, "(/= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1939 "trad2.tab.c"
    break;

  case 77: /* condicional: condicional EQ condicional  */
#line 303 "trad2.y"
                                            { sprintf (temp, "(= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1946 "trad2.tab.c"
    break;

  case 78: /* condicional: condicional '<' condicional  */
#line 305 "trad2.y"
                                             { sprintf (temp, "(< %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1953 "trad2.tab.c"
    break;

  case 79: /* condicional: condicional LEQ condicional  */
#line 307 "trad2.y"
                                             { sprintf (temp, "(<= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1960 "trad2.tab.c"
    break;

  case 80: /* condicional: condicional '>' condicional  */
#line 309 "trad2.y"
                                             { sprintf (temp, "(> %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1967 "trad2.tab.c"
    break;

  case 81: /* condicional: condicional GEQ condicional  */
#line 311 "trad2.y"
                                             { sprintf (temp, "(>= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1974 "trad2.tab.c"
    break;

  case 82: /* termino: operando  */
#line 315 "trad2.y"
                                                   { yyval = yyvsp[0] ; }
#line 1980 "trad2.tab.c"
    break;

  case 83: /* termino: '+' operando  */
#line 316 "trad2.y"
                                                   { sprintf (temp, "(+ %s)", yyvsp[0].code) ;
                                                     yyval.code = gen_code (temp) ; }
#line 1987 "trad2.tab.c"
    break;

  case 84: /* termino: '-' operando  */
#line 318 "trad2.y"
                                                   { sprintf (temp, "(- %s)", yyvsp[0].code) ;
                                                     yyval.code = gen_code (temp) ; }
#line 1994 "trad2.tab.c"
    break;

  case 85: /* operando: IDENTIF  */
#line 322 "trad2.y"
                                         { if (is_local(yyvsp[0].code)) { sprintf (temp, "%s_%s", current_function, yyvsp[0].code);
					   } else { sprintf (temp, "%s", yyvsp[0].code); }
                                           yyval.code = gen_code (temp) ; }
#line 2002 "trad2.tab.c"
    break;

  case 86: /* operando: NUMBER  */
#line 325 "trad2.y"
                                         { sprintf (temp, "%d", yyvsp[0].value) ;
                                           yyval.code = gen_code (temp) ; }
#line 2009 "trad2.tab.c"
    break;

  case 87: /* operando: '(' expresion ')'  */
#line 327 "trad2.y"
                                         { yyval = yyvsp[-1] ; }
#line 2015 "trad2.tab.c"
    break;


#line 2019 "trad2.tab.c"

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

#line 330 "trad2.y"
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
