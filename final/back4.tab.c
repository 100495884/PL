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
#line 1 "back4.y"
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


#line 106 "back4.tab.c"

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

#include "back4.tab.h"
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
  YYSYMBOL_SETQ = 7,                       /* SETQ  */
  YYSYMBOL_SETF = 8,                       /* SETF  */
  YYSYMBOL_DEFUN = 9,                      /* DEFUN  */
  YYSYMBOL_MAIN = 10,                      /* MAIN  */
  YYSYMBOL_LOOP = 11,                      /* LOOP  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_DO = 13,                        /* DO  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_THEN = 16,                      /* THEN  */
  YYSYMBOL_PROGN = 17,                     /* PROGN  */
  YYSYMBOL_PRINT = 18,                     /* PRINT  */
  YYSYMBOL_PRIN1 = 19,                     /* PRIN1  */
  YYSYMBOL_AREF = 20,                      /* AREF  */
  YYSYMBOL_MOD = 21,                       /* MOD  */
  YYSYMBOL_AND = 22,                       /* AND  */
  YYSYMBOL_OR = 23,                        /* OR  */
  YYSYMBOL_NOT = 24,                       /* NOT  */
  YYSYMBOL_NEQ = 25,                       /* NEQ  */
  YYSYMBOL_LEQ = 26,                       /* LEQ  */
  YYSYMBOL_GEQ = 27,                       /* GEQ  */
  YYSYMBOL_RETURN = 28,                    /* RETURN  */
  YYSYMBOL_FROM = 29,                      /* FROM  */
  YYSYMBOL_30_ = 30,                       /* '='  */
  YYSYMBOL_EQ = 31,                        /* EQ  */
  YYSYMBOL_32_ = 32,                       /* '<'  */
  YYSYMBOL_33_ = 33,                       /* '>'  */
  YYSYMBOL_34_ = 34,                       /* '+'  */
  YYSYMBOL_35_ = 35,                       /* '-'  */
  YYSYMBOL_36_ = 36,                       /* '*'  */
  YYSYMBOL_37_ = 37,                       /* '/'  */
  YYSYMBOL_UNARY_SIGN = 38,                /* UNARY_SIGN  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_make_array_ = 41,            /* "make-arrayç"  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_programa = 43,                  /* programa  */
  YYSYMBOL_declaraciones_funciones = 44,   /* declaraciones_funciones  */
  YYSYMBOL_declaracion = 45,               /* declaracion  */
  YYSYMBOL_valor = 46,                     /* valor  */
  YYSYMBOL_funcion = 47,                   /* funcion  */
  YYSYMBOL_param_list = 48,                /* param_list  */
  YYSYMBOL_main_func = 49,                 /* main_func  */
  YYSYMBOL_cuerpo = 50,                    /* cuerpo  */
  YYSYMBOL_sentencias = 51,                /* sentencias  */
  YYSYMBOL_sentencia = 52,                 /* sentencia  */
  YYSYMBOL_func_call = 53,                 /* func_call  */
  YYSYMBOL_expr_list = 54,                 /* expr_list  */
  YYSYMBOL_loop_expr = 55,                 /* loop_expr  */
  YYSYMBOL_if_expr = 56,                   /* if_expr  */
  YYSYMBOL_cond = 57,                      /* cond  */
  YYSYMBOL_expr = 58,                      /* expr  */
  YYSYMBOL_arith_expr = 59,                /* arith_expr  */
  YYSYMBOL_logic_expr = 60,                /* logic_expr  */
  YYSYMBOL_comp_expr = 61,                 /* comp_expr  */
  YYSYMBOL_array_expr = 62,                /* array_expr  */
  YYSYMBOL_termino = 63                    /* termino  */
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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   155

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  165

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      39,    40,    36,    34,     2,    35,     2,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,    30,    33,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    31,    38,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    58,    58,    61,    62,    63,    64,    68,    71,    77,
      78,    82,    86,    87,    91,    97,   101,   102,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   119,   120,
     124,   125,   129,   133,   134,   138,   142,   143,   144,   145,
     146,   147,   151,   152,   153,   154,   155,   159,   160,   161,
     165,   166,   167,   168,   169,   170,   174,   178,   179,   180
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
  "INTEGER", "STRING", "SETQ", "SETF", "DEFUN", "MAIN", "LOOP", "WHILE",
  "DO", "IF", "ELSE", "THEN", "PROGN", "PRINT", "PRIN1", "AREF", "MOD",
  "AND", "OR", "NOT", "NEQ", "LEQ", "GEQ", "RETURN", "FROM", "'='", "EQ",
  "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "UNARY_SIGN", "'('", "')'",
  "\"make-arrayç\"", "$accept", "programa", "declaraciones_funciones",
  "declaracion", "valor", "funcion", "param_list", "main_func", "cuerpo",
  "sentencias", "sentencia", "func_call", "expr_list", "loop_expr",
  "if_expr", "cond", "expr", "arith_expr", "logic_expr", "comp_expr",
  "array_expr", "termino", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-44)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -35,    23,     5,   -44,   -35,   -35,   -35,     4,    -3,   -44,
     -44,   -44,   -44,    15,   -25,    -6,   -44,   -44,     7,    10,
      52,    17,    55,   -44,    52,    19,    36,    38,   -44,    36,
     119,    39,   -44,    36,   -44,   -44,   -44,    40,    42,    13,
      72,    16,    71,    25,    36,    78,    25,    50,    47,   -44,
     -44,   -44,   -44,   -44,   -44,    85,   -44,   -44,    48,    25,
     -44,   -44,   -44,   -44,   -44,    25,    25,    67,    25,    36,
     -44,    51,    53,    54,    61,    82,    91,    25,    25,    25,
      25,    25,    25,    25,    25,    25,    25,    25,    25,    25,
      25,   -44,   -44,    56,    57,    94,    86,   -13,   -44,   -44,
     -44,    96,    73,    25,    25,    25,    25,    74,    25,    25,
      25,    25,    25,    25,    25,    25,    25,    25,   -44,   -44,
      25,    36,    36,   -44,    25,   -44,    84,    88,    89,    92,
     -44,    95,    99,   100,   101,   102,   103,   104,   105,   106,
     108,   109,   110,   111,   112,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,    25,
     -44,   -44,   -44,   113,   -44
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,     0,     0,     2,     6,     6,     6,     0,     0,     1,
       3,     4,     5,     0,     0,     0,     9,    10,     0,     0,
      12,     0,     0,     7,    12,     0,     0,     0,    13,     0,
       0,     0,    15,    17,    24,    25,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    16,
       8,    11,    58,    57,    59,     0,    28,    38,     0,    30,
      37,    39,    40,    41,    36,     0,     0,     0,     0,     0,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    29,    31,     0,     0,     0,     0,     0,    27,    21,
      22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,    19,
       0,     0,     0,    33,     0,    14,     0,     0,     0,     0,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    56,    46,    47,    48,    50,
      54,    55,    51,    52,    53,    42,    43,    44,    45,     0,
      32,    34,    23,     0,    20
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -44,   -44,     6,   -44,   -44,   -44,   107,   -44,   125,   -18,
     -44,   -20,    66,   -44,   -44,    87,   -43,   -44,   -44,   -44,
     -44,   -44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,    19,     5,    25,     6,    31,    32,
      33,    57,    58,    35,    36,    69,    59,    60,    61,    62,
      63,    64
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      70,    14,   122,    73,     1,     9,    34,    15,    13,    34,
      10,    11,    12,    34,    20,    49,    52,    53,    16,    54,
      66,    17,    93,    94,    34,    70,    71,   123,    52,    53,
       7,    54,     8,    21,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    22,    34,
      23,    97,    55,    56,    18,    67,    24,    26,    27,    29,
     126,   127,   128,   129,    55,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,    30,    65,   141,    37,    48,
      50,   144,    51,    68,    72,    74,    75,    95,    91,    39,
     101,    98,   102,    99,   100,   103,   118,   119,   120,   121,
     124,    34,    34,   142,   143,    76,    77,    78,    79,    80,
      81,    82,    83,   125,   130,    84,   163,    85,    86,    87,
      88,    89,    90,    39,   145,    92,    40,    41,   146,   147,
      42,    28,   148,    43,     0,   149,    44,    45,    46,   150,
     151,   152,   153,   154,   155,   156,   157,    47,   158,   159,
     160,   161,   162,   164,    38,    96
};

static const yytype_int16 yycheck[] =
{
      43,     4,    15,    46,    39,     0,    26,    10,     4,    29,
       4,     5,     6,    33,    39,    33,     3,     4,     3,     6,
       4,     6,    65,    66,    44,    68,    44,    40,     3,     4,
       7,     6,     9,    39,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    41,    69,
      40,    69,    39,    40,    39,    39,     4,    40,     3,    40,
     103,   104,   105,   106,    39,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    39,     4,   120,    40,    40,
      40,   124,    40,    12,     6,    35,    39,    20,    40,     4,
      29,    40,    10,    40,    40,     4,    40,    40,     4,    13,
       4,   121,   122,   121,   122,    20,    21,    22,    23,    24,
      25,    26,    27,    40,    40,    30,   159,    32,    33,    34,
      35,    36,    37,     4,    40,    59,     7,     8,    40,    40,
      11,    24,    40,    14,    -1,    40,    17,    18,    19,    40,
      40,    40,    40,    40,    40,    40,    40,    28,    40,    40,
      40,    40,    40,    40,    29,    68
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    39,    43,    44,    45,    47,    49,     7,     9,     0,
      44,    44,    44,     4,     4,    10,     3,     6,    39,    46,
      39,    39,    41,    40,     4,    48,    40,     3,    48,    40,
      39,    50,    51,    52,    53,    55,    56,    40,    50,     4,
       7,     8,    11,    14,    17,    18,    19,    28,    40,    51,
      40,    40,     3,     4,     6,    39,    40,    53,    54,    58,
      59,    60,    61,    62,    63,     4,     4,    39,    12,    57,
      58,    51,     6,    58,    35,    39,    20,    21,    22,    23,
      24,    25,    26,    27,    30,    32,    33,    34,    35,    36,
      37,    40,    54,    58,    58,    20,    57,    51,    40,    40,
      40,    29,    10,     4,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    40,    40,
       4,    13,    15,    40,     4,    40,    58,    58,    58,    58,
      40,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    51,    51,    58,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    58,    40
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    44,    44,    45,    45,    46,
      46,    47,    48,    48,    49,    50,    51,    51,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    53,    53,
      54,    54,    55,    56,    56,    57,    58,    58,    58,    58,
      58,    58,    59,    59,    59,    59,    59,    60,    60,    60,
      61,    61,    61,    61,    61,    61,    62,    63,    63,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     0,     5,     8,     1,
       1,     8,     0,     2,    10,     1,     2,     1,     5,     5,
       9,     4,     4,     7,     1,     1,     1,     4,     3,     4,
       1,     2,     7,     5,     7,     1,     1,     1,     1,     1,
       1,     1,     5,     5,     5,     5,     5,     5,     5,     4,
       5,     5,     5,     5,     5,     5,     5,     1,     1,     1
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
  case 2: /* programa: declaraciones_funciones  */
#line 58 "back4.y"
                                  { ; }
#line 1250 "back4.tab.c"
    break;

  case 3: /* declaraciones_funciones: declaracion declaraciones_funciones  */
#line 61 "back4.y"
                                          { ; }
#line 1256 "back4.tab.c"
    break;

  case 4: /* declaraciones_funciones: funcion declaraciones_funciones  */
#line 62 "back4.y"
                                      { ; }
#line 1262 "back4.tab.c"
    break;

  case 5: /* declaraciones_funciones: main_func declaraciones_funciones  */
#line 63 "back4.y"
                                        { ; }
#line 1268 "back4.tab.c"
    break;

  case 6: /* declaraciones_funciones: %empty  */
#line 64 "back4.y"
                   { ; }
#line 1274 "back4.tab.c"
    break;

  case 7: /* declaracion: '(' SETQ IDENTIF valor ')'  */
#line 68 "back4.y"
                                 { 
          printf("variable %s\n%s %s !\n", yyvsp[-2].code, yyvsp[-1].code, yyvsp[-2].code); yyval.code = gen_code(temp); 
      }
#line 1282 "back4.tab.c"
    break;

  case 8: /* declaracion: '(' SETQ IDENTIF '(' "make-arrayç" NUMBER ')' ')'  */
#line 71 "back4.y"
                                                        { 
          printf("variable %s\ncreate %s %s cells allot\n", yyvsp[-5].code, yyvsp[-5].code, yyvsp[-2].code); 
      }
#line 1290 "back4.tab.c"
    break;

  case 9: /* valor: NUMBER  */
#line 77 "back4.y"
             { sprintf(temp, "%d", yyvsp[0].value); yyval.code = gen_code(temp); }
#line 1296 "back4.tab.c"
    break;

  case 10: /* valor: STRING  */
#line 78 "back4.y"
             { yyval.code = yyvsp[0].code; }
#line 1302 "back4.tab.c"
    break;

  case 11: /* funcion: '(' DEFUN IDENTIF '(' param_list ')' cuerpo ')'  */
#line 82 "back4.y"
                                                      { printf(": %s ( %s -- retorno )\n%s ;\n", yyvsp[-5].code, yyvsp[-3].code, yyvsp[-1].code); }
#line 1308 "back4.tab.c"
    break;

  case 12: /* param_list: %empty  */
#line 86 "back4.y"
                   { yyval.code = gen_code(""); }
#line 1314 "back4.tab.c"
    break;

  case 13: /* param_list: IDENTIF param_list  */
#line 87 "back4.y"
                         { sprintf(temp, "%s %s", yyvsp[-1].code, yyvsp[0].code); yyval.code = gen_code(temp); }
#line 1320 "back4.tab.c"
    break;

  case 14: /* main_func: '(' DEFUN MAIN '(' ')' cuerpo ')' '(' MAIN ')'  */
#line 91 "back4.y"
                                                     { 
          printf(": main\n%s ;\nmain\n", yyvsp[-4].code); 
      }
#line 1328 "back4.tab.c"
    break;

  case 15: /* cuerpo: sentencias  */
#line 97 "back4.y"
                 { yyval.code = yyvsp[0].code; }
#line 1334 "back4.tab.c"
    break;

  case 16: /* sentencias: sentencia sentencias  */
#line 101 "back4.y"
                           { sprintf(temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code); yyval.code = gen_code(temp); }
#line 1340 "back4.tab.c"
    break;

  case 17: /* sentencias: sentencia  */
#line 102 "back4.y"
                { yyval.code = yyvsp[0].code; }
#line 1346 "back4.tab.c"
    break;

  case 18: /* sentencia: '(' SETQ IDENTIF expr ')'  */
#line 106 "back4.y"
                              { sprintf(temp, "variable %s\n%s %s !", yyvsp[-2].code, yyvsp[-1].code, yyvsp[-2].code); yyval.code = gen_code(temp); }
#line 1352 "back4.tab.c"
    break;

  case 19: /* sentencia: '(' SETF IDENTIF expr ')'  */
#line 107 "back4.y"
                                { sprintf(temp, "%s %s !", yyvsp[-1].code, yyvsp[-2].code); yyval.code = gen_code(temp); }
#line 1358 "back4.tab.c"
    break;

  case 20: /* sentencia: '(' SETF '(' AREF IDENTIF expr ')' expr ')'  */
#line 108 "back4.y"
                                                  { sprintf(temp, "%s %s %s [] !", yyvsp[-1].code, yyvsp[-3].code, yyvsp[-4].code); yyval.code = gen_code(temp); }
#line 1364 "back4.tab.c"
    break;

  case 21: /* sentencia: '(' PRINT STRING ')'  */
#line 109 "back4.y"
                           { sprintf(temp, ".\" %s\" cr", yyvsp[-1].code); yyval.code = gen_code(temp); }
#line 1370 "back4.tab.c"
    break;

  case 22: /* sentencia: '(' PRIN1 expr ')'  */
#line 110 "back4.y"
                         { if (yyvsp[-1].code[0] == '"') { sprintf(temp, ".\" %s cr", yyvsp[-1].code + 1); temp[strlen(temp)] = '\0'; } else { sprintf(temp, "%s .", yyvsp[-1].code); } yyval.code = gen_code(temp); }
#line 1376 "back4.tab.c"
    break;

  case 23: /* sentencia: '(' RETURN '-' FROM IDENTIF expr ')'  */
#line 111 "back4.y"
                                           { sprintf(temp, "%s", yyvsp[-1].code); yyval.code = gen_code(temp); }
#line 1382 "back4.tab.c"
    break;

  case 27: /* sentencia: '(' PROGN sentencias ')'  */
#line 115 "back4.y"
                               { yyval.code = yyvsp[-1].code; }
#line 1388 "back4.tab.c"
    break;

  case 28: /* func_call: '(' IDENTIF ')'  */
#line 119 "back4.y"
                      { sprintf(temp, "%s", yyvsp[-1].code); yyval.code = gen_code(temp); }
#line 1394 "back4.tab.c"
    break;

  case 29: /* func_call: '(' IDENTIF expr_list ')'  */
#line 120 "back4.y"
                                { sprintf(temp, "%s %s", yyvsp[-2].code, yyvsp[-1].code); yyval.code = gen_code(temp); }
#line 1400 "back4.tab.c"
    break;

  case 30: /* expr_list: expr  */
#line 124 "back4.y"
           { yyval.code = yyvsp[0].code; }
#line 1406 "back4.tab.c"
    break;

  case 31: /* expr_list: expr expr_list  */
#line 125 "back4.y"
                     { sprintf(temp, "%s %s", yyvsp[-1].code, yyvsp[0].code); yyval.code = gen_code(temp); }
#line 1412 "back4.tab.c"
    break;

  case 32: /* loop_expr: '(' LOOP WHILE cond DO sentencias ')'  */
#line 129 "back4.y"
                                            { sprintf(temp, "begin %s while %s repeat", yyvsp[-3].code, yyvsp[-1].code); yyval.code = gen_code(temp); }
#line 1418 "back4.tab.c"
    break;

  case 33: /* if_expr: '(' IF cond sentencias ')'  */
#line 133 "back4.y"
                                 { sprintf(temp, "%s if %s then", yyvsp[-2].code, yyvsp[-1].code); yyval.code = gen_code(temp); }
#line 1424 "back4.tab.c"
    break;

  case 34: /* if_expr: '(' IF cond sentencias ELSE sentencias ')'  */
#line 134 "back4.y"
                                                 { sprintf(temp, "%s if %s else %s then", yyvsp[-4].code, yyvsp[-3].code, yyvsp[-1].code); yyval.code = gen_code(temp); }
#line 1430 "back4.tab.c"
    break;

  case 35: /* cond: expr  */
#line 138 "back4.y"
           { yyval.code = yyvsp[0].code; }
#line 1436 "back4.tab.c"
    break;

  case 36: /* expr: termino  */
#line 142 "back4.y"
              { yyval.code = yyvsp[0].code; }
#line 1442 "back4.tab.c"
    break;

  case 42: /* arith_expr: '(' '+' expr expr ')'  */
#line 151 "back4.y"
                            { sprintf(temp, "%s %s +", yyvsp[-2].code, yyvsp[-1].code); yyval.code = gen_code(temp); }
#line 1448 "back4.tab.c"
    break;

  case 43: /* arith_expr: '(' '-' expr expr ')'  */
#line 152 "back4.y"
                            { sprintf(temp, "%s %s -", yyvsp[-2].code, yyvsp[-1].code); yyval.code = gen_code(temp); }
#line 1454 "back4.tab.c"
    break;

  case 44: /* arith_expr: '(' '*' expr expr ')'  */
#line 153 "back4.y"
                            { sprintf(temp, "%s %s *", yyvsp[-2].code, yyvsp[-1].code); yyval.code = gen_code(temp); }
#line 1460 "back4.tab.c"
    break;

  case 45: /* arith_expr: '(' '/' expr expr ')'  */
#line 154 "back4.y"
                            { sprintf(temp, "%s %s /", yyvsp[-3].code, yyvsp[-2].code); yyval.code = gen_code(temp); }
#line 1466 "back4.tab.c"
    break;

  case 46: /* arith_expr: '(' MOD expr expr ')'  */
#line 155 "back4.y"
                            { sprintf(temp, "%s %s mod", yyvsp[-2].code, yyvsp[-1].code); yyval.code = gen_code(temp); }
#line 1472 "back4.tab.c"
    break;

  case 47: /* logic_expr: '(' AND expr expr ')'  */
#line 159 "back4.y"
                            { sprintf(temp, "%s %s and", yyvsp[-2].code, yyvsp[-1].code); yyval.code = gen_code(temp); }
#line 1478 "back4.tab.c"
    break;

  case 48: /* logic_expr: '(' OR expr expr ')'  */
#line 160 "back4.y"
                           { sprintf(temp, "%s %s or", yyvsp[-2].code, yyvsp[-1].code); yyval.code = gen_code(temp); }
#line 1484 "back4.tab.c"
    break;

  case 49: /* logic_expr: '(' NOT expr ')'  */
#line 161 "back4.y"
                       { sprintf(temp, "%s 0=", yyvsp[-1].code); yyval.code = gen_code(temp); }
#line 1490 "back4.tab.c"
    break;

  case 50: /* comp_expr: '(' NEQ expr expr ')'  */
#line 165 "back4.y"
                            { sprintf(temp, "%s %s <>", yyvsp[-2].code, yyvsp[-1].code); yyval.code = gen_code(temp); }
#line 1496 "back4.tab.c"
    break;

  case 51: /* comp_expr: '(' '=' expr expr ')'  */
#line 166 "back4.y"
                            { sprintf(temp, "%s %s =", yyvsp[-2].code, yyvsp[-1].code); yyval.code = gen_code(temp); }
#line 1502 "back4.tab.c"
    break;

  case 52: /* comp_expr: '(' '<' expr expr ')'  */
#line 167 "back4.y"
                            { sprintf(temp, "%s %s <", yyvsp[-2].code, yyvsp[-1].code); yyval.code = gen_code(temp); }
#line 1508 "back4.tab.c"
    break;

  case 53: /* comp_expr: '(' '>' expr expr ')'  */
#line 168 "back4.y"
                            { sprintf(temp, "%s %s >", yyvsp[-2].code, yyvsp[-1].code); yyval.code = gen_code(temp); }
#line 1514 "back4.tab.c"
    break;

  case 54: /* comp_expr: '(' LEQ expr expr ')'  */
#line 169 "back4.y"
                            { sprintf(temp, "%s %s <=", yyvsp[-2].code, yyvsp[-1].code); yyval.code = gen_code(temp); }
#line 1520 "back4.tab.c"
    break;

  case 55: /* comp_expr: '(' GEQ expr expr ')'  */
#line 170 "back4.y"
                            { sprintf(temp, "%s %s >=", yyvsp[-2].code, yyvsp[-1].code); yyval.code = gen_code(temp); }
#line 1526 "back4.tab.c"
    break;

  case 56: /* array_expr: '(' AREF IDENTIF expr ')'  */
#line 174 "back4.y"
                                { sprintf(temp, "%s %s [] @", yyvsp[-1].code, yyvsp[-2].code); yyval.code = gen_code(temp); }
#line 1532 "back4.tab.c"
    break;

  case 57: /* termino: IDENTIF  */
#line 178 "back4.y"
              { sprintf(temp, "%s @", yyvsp[0].code); yyval.code = gen_code(temp); }
#line 1538 "back4.tab.c"
    break;

  case 58: /* termino: NUMBER  */
#line 179 "back4.y"
             { sprintf(temp, "%d", yyvsp[0].value); yyval.code = gen_code(temp); }
#line 1544 "back4.tab.c"
    break;

  case 59: /* termino: STRING  */
#line 180 "back4.y"
             { sprintf(temp, "\"%s\"", yyvsp[0].code); yyval.code = gen_code(temp); }
#line 1550 "back4.tab.c"
    break;


#line 1554 "back4.tab.c"

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

#line 183 "back4.y"
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
