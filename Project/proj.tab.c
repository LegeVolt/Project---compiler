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
#line 1 "proj.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int yylex(void);
int yyerror(const char *s);
extern int lineno;
extern char *yytext;

typedef struct node {
    char *token;
    struct node *left;
    struct node *right;
    int lineno;  /* Line number for error reporting */
} node;

node *mknode(char *token, node *left, node *right);
node *mk_leaf(char *token);
node *int_node(int val);
node *float_node(float val);
void printtree(node *tree, int indent);

/* Semantic analysis */
int semantic_analysis(struct node *root);
static node *ast_root = NULL;

#line 99 "proj.tab.c"

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

#include "proj.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_STRING = 3,                     /* STRING  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_FLOAT = 6,                      /* FLOAT  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_ELIF = 9,                       /* ELIF  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_AND = 12,                       /* AND  */
  YYSYMBOL_OR = 13,                        /* OR  */
  YYSYMBOL_NOT = 14,                       /* NOT  */
  YYSYMBOL_PASS = 15,                      /* PASS  */
  YYSYMBOL_DEF = 16,                       /* DEF  */
  YYSYMBOL_BOOL = 17,                      /* BOOL  */
  YYSYMBOL_KW_INT = 18,                    /* KW_INT  */
  YYSYMBOL_KW_STRING = 19,                 /* KW_STRING  */
  YYSYMBOL_KW_FLOAT = 20,                  /* KW_FLOAT  */
  YYSYMBOL_EQ = 21,                        /* EQ  */
  YYSYMBOL_ASSIGN = 22,                    /* ASSIGN  */
  YYSYMBOL_GEQ = 23,                       /* GEQ  */
  YYSYMBOL_LEQ = 24,                       /* LEQ  */
  YYSYMBOL_LESS = 25,                      /* LESS  */
  YYSYMBOL_GREATER = 26,                   /* GREATER  */
  YYSYMBOL_NEQ = 27,                       /* NEQ  */
  YYSYMBOL_PLUS = 28,                      /* PLUS  */
  YYSYMBOL_MINUS = 29,                     /* MINUS  */
  YYSYMBOL_POW = 30,                       /* POW  */
  YYSYMBOL_MUL = 31,                       /* MUL  */
  YYSYMBOL_DIV = 32,                       /* DIV  */
  YYSYMBOL_DOT = 33,                       /* DOT  */
  YYSYMBOL_SEMI = 34,                      /* SEMI  */
  YYSYMBOL_COMMA = 35,                     /* COMMA  */
  YYSYMBOL_LPAREN = 36,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 37,                    /* RPAREN  */
  YYSYMBOL_LBRACK = 38,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 39,                    /* RBRACK  */
  YYSYMBOL_ARROW = 40,                     /* ARROW  */
  YYSYMBOL_COLON = 41,                     /* COLON  */
  YYSYMBOL_TRUE = 42,                      /* TRUE  */
  YYSYMBOL_FALSE = 43,                     /* FALSE  */
  YYSYMBOL_LOWER_THAN_ELSE = 44,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_program = 46,                   /* program  */
  YYSYMBOL_func_list = 47,                 /* func_list  */
  YYSYMBOL_func = 48,                      /* func  */
  YYSYMBOL_args = 49,                      /* args  */
  YYSYMBOL_arg_decl_list = 50,             /* arg_decl_list  */
  YYSYMBOL_param_decl = 51,                /* param_decl  */
  YYSYMBOL_type = 52,                      /* type  */
  YYSYMBOL_id_list = 53,                   /* id_list  */
  YYSYMBOL_opt_ret_type = 54,              /* opt_ret_type  */
  YYSYMBOL_return_type = 55,               /* return_type  */
  YYSYMBOL_body = 56,                      /* body  */
  YYSYMBOL_block = 57,                     /* block  */
  YYSYMBOL_suite = 58,                     /* suite  */
  YYSYMBOL_stmt_list = 59,                 /* stmt_list  */
  YYSYMBOL_stmt = 60,                      /* stmt  */
  YYSYMBOL_if_stmt = 61,                   /* if_stmt  */
  YYSYMBOL_elif_tail = 62,                 /* elif_tail  */
  YYSYMBOL_assign_stmt = 63,               /* assign_stmt  */
  YYSYMBOL_decl_stmt = 64,                 /* decl_stmt  */
  YYSYMBOL_expr_stmt = 65,                 /* expr_stmt  */
  YYSYMBOL_return_stmt = 66,               /* return_stmt  */
  YYSYMBOL_pass_stmt = 67,                 /* pass_stmt  */
  YYSYMBOL_while_stmt = 68,                /* while_stmt  */
  YYSYMBOL_expr = 69,                      /* expr  */
  YYSYMBOL_primary = 70,                   /* primary  */
  YYSYMBOL_call = 71,                      /* call  */
  YYSYMBOL_opt_arg_expr_list = 72,         /* opt_arg_expr_list  */
  YYSYMBOL_arg_expr_list = 73              /* arg_expr_list  */
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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   341

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  130

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    66,    66,    77,    78,    88,   106,   107,   112,   113,
     121,   130,   131,   132,   133,   137,   138,   149,   150,   155,
     160,   162,   167,   173,   174,   178,   179,   192,   193,   194,
     195,   196,   197,   198,   203,   211,   225,   231,   239,   244,
     253,   261,   269,   274,   276,   281,   285,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   329,   340,   341,   346,   347
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
  "\"end of file\"", "error", "\"invalid token\"", "STRING", "ID", "INT",
  "FLOAT", "IF", "ELSE", "ELIF", "WHILE", "RETURN", "AND", "OR", "NOT",
  "PASS", "DEF", "BOOL", "KW_INT", "KW_STRING", "KW_FLOAT", "EQ", "ASSIGN",
  "GEQ", "LEQ", "LESS", "GREATER", "NEQ", "PLUS", "MINUS", "POW", "MUL",
  "DIV", "DOT", "SEMI", "COMMA", "LPAREN", "RPAREN", "LBRACK", "RBRACK",
  "ARROW", "COLON", "TRUE", "FALSE", "LOWER_THAN_ELSE", "$accept",
  "program", "func_list", "func", "args", "arg_decl_list", "param_decl",
  "type", "id_list", "opt_ret_type", "return_type", "body", "block",
  "suite", "stmt_list", "stmt", "if_stmt", "elif_tail", "assign_stmt",
  "decl_stmt", "expr_stmt", "return_stmt", "pass_stmt", "while_stmt",
  "expr", "primary", "call", "opt_arg_expr_list", "arg_expr_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-84)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -8,    15,    20,    -8,   -84,   -10,   -84,   -84,    56,   -84,
     -84,   -84,   -84,    -1,   -84,    -7,    34,     0,    56,    28,
     -84,    56,    36,   -84,   -84,    34,   -84,   276,   -84,   -15,
      29,    29,    25,    33,   -84,    75,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,    61,    29,    29,   -84,
      54,   -84,   -84,    29,    29,   -84,   -84,    57,    58,   -84,
      80,   -84,   202,   -84,   193,   -13,    62,   -84,   224,   164,
      65,   -84,   -84,   143,    29,    29,    29,    29,    29,    29,
      29,    29,    29,    29,    29,    29,    29,   276,    29,   276,
     -84,   -84,   -84,    29,   -84,   -84,    29,   -84,   -84,   297,
     285,   309,   309,   309,   309,   309,   309,   -20,   -20,    69,
      69,    69,   -84,     7,   -84,   122,   -84,   246,   -84,    74,
      29,   -84,   -84,   -84,   276,   101,   -84,   276,     7,   -84
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     3,     0,     1,     4,     6,    14,
      11,    12,    13,     0,     7,     8,     0,    17,     0,    15,
      10,     0,     0,    18,     9,     0,    19,     0,    16,     0,
       0,     0,     0,     0,    25,     0,     5,    20,    21,    27,
      28,    29,    33,    30,    31,    32,     0,     0,    72,    65,
      64,    62,    63,     0,     0,    66,    67,     0,    61,    69,
       0,    44,     0,    45,     0,    15,     0,    42,     0,    74,
       0,    73,    60,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      43,    22,    26,     0,    41,    39,     0,    71,    68,    48,
      47,    49,    51,    52,    54,    53,    50,    55,    56,    59,
      57,    58,    23,    34,    24,     0,    46,     0,    75,     0,
       0,    35,    70,    40,     0,     0,    38,     0,    36,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -84,   -84,   -84,   113,   -84,    99,   -84,    -4,   -12,   -84,
     -84,   -84,    91,   -83,   -84,   -22,   -84,    -9,   -84,   -84,
     -84,   -84,   -84,   -84,   -29,   -84,   -27,   -84,    24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,    13,    14,    15,    35,    20,    22,
      23,    36,   112,   113,    64,   114,    39,   121,    40,    41,
      42,    43,    44,    45,    69,    58,    59,    70,    71
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      46,    57,    60,    62,    16,    38,   116,    47,     1,    93,
      84,    85,    86,    28,    16,   119,   120,    26,    68,     5,
       6,    48,    25,    66,    72,    73,     8,    18,    49,    50,
      51,    52,    49,    50,    51,    52,    17,    46,    19,    53,
      21,   126,    92,    53,   128,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,    61,   115,
      46,    54,    46,    25,   117,    54,    63,    55,    56,    74,
      75,    55,    56,     9,    10,    11,    12,    27,    76,    65,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      48,   125,    74,    75,    67,    94,    88,    46,    87,    84,
      46,    76,    97,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    74,    75,   124,     7,    24,    37,   129,
     118,    89,    76,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    74,    75,     0,     0,     0,     0,
       0,     0,   127,    76,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    74,    75,     0,     0,     0,
       0,   122,     0,     0,    76,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    74,    75,     0,     0,
      98,     0,     0,     0,     0,    76,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    29,     0,    96,
      30,     0,     0,    31,    32,     0,     0,     0,    33,     0,
       9,    10,    11,    12,    74,    75,     0,     0,     0,    91,
       0,     0,     0,    76,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    90,    74,    75,     0,     0,
       0,     0,     0,     0,     0,    76,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    95,    74,    75,
       0,     0,     0,     0,     0,     0,     0,    76,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,   123,
      29,     0,     0,    30,     0,     0,    31,    32,     0,     0,
       0,    33,     0,     9,    10,    11,    12,    74,     0,     0,
       0,    34,     0,     0,     0,     0,    76,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    76,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,     0,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,
      85,    86
};

static const yytype_int16 yycheck[] =
{
      27,    30,    31,    32,     8,    27,    89,    22,    16,    22,
      30,    31,    32,    25,    18,     8,     9,    21,    47,     4,
       0,    36,    35,    35,    53,    54,    36,    34,     3,     4,
       5,     6,     3,     4,     5,     6,    37,    64,     4,    14,
      40,   124,    64,    14,   127,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    33,    88,
      87,    36,    89,    35,    93,    36,    33,    42,    43,    12,
      13,    42,    43,    17,    18,    19,    20,    41,    21,     4,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      36,   120,    12,    13,    33,    33,    38,   124,    41,    30,
     127,    21,    37,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    12,    13,    41,     3,    18,    27,   128,
      96,    41,    21,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    21,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    12,    13,    -1,    -1,    -1,
      -1,    39,    -1,    -1,    21,    -1,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    12,    13,    -1,    -1,
      37,    -1,    -1,    -1,    -1,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,     4,    -1,    35,
       7,    -1,    -1,    10,    11,    -1,    -1,    -1,    15,    -1,
      17,    18,    19,    20,    12,    13,    -1,    -1,    -1,    26,
      -1,    -1,    -1,    21,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       4,    -1,    -1,     7,    -1,    -1,    10,    11,    -1,    -1,
      -1,    15,    -1,    17,    18,    19,    20,    12,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    21,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    21,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      21,    -1,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    16,    46,    47,    48,     4,     0,    48,    36,    17,
      18,    19,    20,    49,    50,    51,    52,    37,    34,     4,
      53,    40,    54,    55,    50,    35,    52,    41,    53,     4,
       7,    10,    11,    15,    25,    52,    56,    57,    60,    61,
      63,    64,    65,    66,    67,    68,    71,    22,    36,     3,
       4,     5,     6,    14,    36,    42,    43,    69,    70,    71,
      69,    33,    69,    33,    59,     4,    53,    33,    69,    69,
      72,    73,    69,    69,    12,    13,    21,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    41,    38,    41,
      33,    26,    60,    22,    33,    33,    35,    37,    37,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    57,    58,    60,    69,    58,    69,    73,     8,
       9,    62,    39,    33,    41,    69,    58,    41,    58,    62
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    49,    49,    50,    50,
      51,    52,    52,    52,    52,    53,    53,    54,    54,    55,
      56,    56,    57,    58,    58,    59,    59,    60,    60,    60,
      60,    60,    60,    60,    61,    61,    62,    62,    62,    63,
      64,    64,    65,    66,    66,    67,    68,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    71,    72,    72,    73,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     8,     0,     1,     1,     3,
       2,     1,     1,     1,     1,     1,     3,     0,     1,     2,
       1,     1,     3,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     4,     5,     4,     5,     3,     4,
       5,     3,     2,     3,     2,     2,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       4,     4,     0,     1,     1,     3
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
  case 2: /* program: func_list  */
#line 67 "proj.y"
      { 
          (yyval.n) = mknode("CODE", (yyvsp[0].n), NULL); 
          ast_root = (yyval.n);
          if (semantic_analysis((yyval.n)) == 0) {
              printtree((yyval.n), 0);
          }
      }
#line 1293 "proj.tab.c"
    break;

  case 3: /* func_list: func  */
#line 77 "proj.y"
           { (yyval.n) = (yyvsp[0].n); }
#line 1299 "proj.tab.c"
    break;

  case 4: /* func_list: func_list func  */
#line 79 "proj.y"
      {
          node *t = (yyvsp[-1].n);
          while(t->right != NULL) t = t->right;
          t->right = (yyvsp[0].n);
          (yyval.n) = (yyvsp[-1].n);
      }
#line 1310 "proj.tab.c"
    break;

  case 5: /* func: DEF ID LPAREN args RPAREN opt_ret_type COLON body  */
#line 89 "proj.y"
      {
          node *func_name = mk_leaf((yyvsp[-6].sval));
          node *a = (yyvsp[-4].n);      /* ARGS node */
          node *r = (yyvsp[-2].n);      /* RETURN node */
          node *b = (yyvsp[0].n);      /* BODY node */

          /* (FUNC foo (ARGS ...) (RETURN ...) (BODY ...)) */
          func_name->right = a;
          a->right = r;
          r->right = b;

          (yyval.n) = mknode("FUNC", func_name, NULL);
      }
#line 1328 "proj.tab.c"
    break;

  case 6: /* args: %empty  */
#line 106 "proj.y"
      { (yyval.n) = mknode("ARGS", mknode("NONE", NULL, NULL), NULL); }
#line 1334 "proj.tab.c"
    break;

  case 7: /* args: arg_decl_list  */
#line 108 "proj.y"
      { (yyval.n) = mknode("ARGS", (yyvsp[0].n), NULL); }
#line 1340 "proj.tab.c"
    break;

  case 8: /* arg_decl_list: param_decl  */
#line 112 "proj.y"
                 { (yyval.n) = (yyvsp[0].n); }
#line 1346 "proj.tab.c"
    break;

  case 9: /* arg_decl_list: param_decl SEMI arg_decl_list  */
#line 114 "proj.y"
      {
          (yyvsp[-2].n)->right = (yyvsp[0].n);
          (yyval.n) = (yyvsp[-2].n);
      }
#line 1355 "proj.tab.c"
    break;

  case 10: /* param_decl: type id_list  */
#line 122 "proj.y"
      {
          /* (INT x y z) or (BOOL f) */
          (yyvsp[-1].n)->left = (yyvsp[0].n);
          (yyval.n) = (yyvsp[-1].n);
      }
#line 1365 "proj.tab.c"
    break;

  case 11: /* type: KW_INT  */
#line 130 "proj.y"
                { (yyval.n) = mknode("INT", NULL, NULL); }
#line 1371 "proj.tab.c"
    break;

  case 12: /* type: KW_STRING  */
#line 131 "proj.y"
                { (yyval.n) = mknode("STRING", NULL, NULL); }
#line 1377 "proj.tab.c"
    break;

  case 13: /* type: KW_FLOAT  */
#line 132 "proj.y"
                { (yyval.n) = mknode("FLOAT", NULL, NULL); }
#line 1383 "proj.tab.c"
    break;

  case 14: /* type: BOOL  */
#line 133 "proj.y"
                { (yyval.n) = mknode("BOOL", NULL, NULL); }
#line 1389 "proj.tab.c"
    break;

  case 15: /* id_list: ID  */
#line 137 "proj.y"
         { (yyval.n) = mk_leaf((yyvsp[0].sval)); }
#line 1395 "proj.tab.c"
    break;

  case 16: /* id_list: ID COMMA id_list  */
#line 139 "proj.y"
      {
          node *n = mk_leaf((yyvsp[-2].sval));
          n->right = (yyvsp[0].n);
          (yyval.n) = n;
      }
#line 1405 "proj.tab.c"
    break;

  case 17: /* opt_ret_type: %empty  */
#line 149 "proj.y"
      { (yyval.n) = mknode("RETURN", mknode("VOID", NULL, NULL), NULL); }
#line 1411 "proj.tab.c"
    break;

  case 18: /* opt_ret_type: return_type  */
#line 151 "proj.y"
      { (yyval.n) = (yyvsp[0].n); }
#line 1417 "proj.tab.c"
    break;

  case 19: /* return_type: ARROW type  */
#line 156 "proj.y"
      { (yyval.n) = mknode("RETURN", (yyvsp[0].n), NULL); }
#line 1423 "proj.tab.c"
    break;

  case 20: /* body: block  */
#line 161 "proj.y"
      { (yyval.n) = mknode("BODY", (yyvsp[0].n)->left, NULL); }
#line 1429 "proj.tab.c"
    break;

  case 21: /* body: stmt  */
#line 163 "proj.y"
      { (yyval.n) = mknode("BODY", (yyvsp[0].n), NULL); }
#line 1435 "proj.tab.c"
    break;

  case 22: /* block: LESS stmt_list GREATER  */
#line 168 "proj.y"
      { (yyval.n) = mknode("BLOCK", (yyvsp[-1].n), NULL); }
#line 1441 "proj.tab.c"
    break;

  case 23: /* suite: block  */
#line 173 "proj.y"
            { (yyval.n) = (yyvsp[0].n); }
#line 1447 "proj.tab.c"
    break;

  case 24: /* suite: stmt  */
#line 174 "proj.y"
            { (yyval.n) = mknode("BLOCK", (yyvsp[0].n), NULL); }
#line 1453 "proj.tab.c"
    break;

  case 25: /* stmt_list: %empty  */
#line 178 "proj.y"
                  { (yyval.n) = NULL; }
#line 1459 "proj.tab.c"
    break;

  case 26: /* stmt_list: stmt_list stmt  */
#line 180 "proj.y"
      {
          if ((yyvsp[-1].n) == NULL) (yyval.n) = (yyvsp[0].n);
          else {
              node *p = (yyvsp[-1].n);
              while (p->right) p = p->right;
              p->right = (yyvsp[0].n);
              (yyval.n) = (yyvsp[-1].n);
          }
      }
#line 1473 "proj.tab.c"
    break;

  case 34: /* if_stmt: IF expr COLON suite  */
#line 204 "proj.y"
      {
          /* מבנה ילדים: cond -> then (ללא tail) */
          node *cond = (yyvsp[-2].n);
          node *then_b = (yyvsp[0].n);
          cond->right = then_b;
          (yyval.n) = mknode("IF", cond, NULL);
      }
#line 1485 "proj.tab.c"
    break;

  case 35: /* if_stmt: IF expr COLON suite elif_tail  */
#line 212 "proj.y"
      {
          /* מבנה ילדים: cond -> then -> tail (ELIF/ELSE) */
          node *cond = (yyvsp[-3].n);
          node *then_b = (yyvsp[-1].n);
          node *tail = (yyvsp[0].n);
          cond->right = then_b;
          then_b->right = tail;
          (yyval.n) = mknode("IF", cond, NULL);
      }
#line 1499 "proj.tab.c"
    break;

  case 36: /* elif_tail: ELIF expr COLON suite  */
#line 226 "proj.y"
      {
          node *cond = (yyvsp[-2].n);
          cond->right = (yyvsp[0].n);
          (yyval.n) = mknode("ELIF", cond, NULL);
      }
#line 1509 "proj.tab.c"
    break;

  case 37: /* elif_tail: ELIF expr COLON suite elif_tail  */
#line 232 "proj.y"
      {
          node *cond = (yyvsp[-3].n);
          cond->right = (yyvsp[-1].n);
          node *elif_node = mknode("ELIF", cond, NULL);
          elif_node->right = (yyvsp[0].n);
          (yyval.n) = elif_node;
      }
#line 1521 "proj.tab.c"
    break;

  case 38: /* elif_tail: ELSE COLON suite  */
#line 240 "proj.y"
      { (yyval.n) = mknode("ELSE", (yyvsp[0].n), NULL); }
#line 1527 "proj.tab.c"
    break;

  case 39: /* assign_stmt: ID ASSIGN expr DOT  */
#line 245 "proj.y"
      {
          node *id = mk_leaf((yyvsp[-3].sval));
          id->right = (yyvsp[-1].n);
          (yyval.n) = mknode("ASS", id, NULL);
      }
#line 1537 "proj.tab.c"
    break;

  case 40: /* decl_stmt: type ID ASSIGN expr DOT  */
#line 254 "proj.y"
      {
          node *id = mk_leaf((yyvsp[-3].sval));
          node *init = mknode("INIT", (yyvsp[-1].n), NULL);  /* Wrap initializer to distinguish from id_list */
          (yyvsp[-4].n)->left = id;
          id->right = init;
          (yyval.n) = mknode("DECL", (yyvsp[-4].n), NULL);
      }
#line 1549 "proj.tab.c"
    break;

  case 41: /* decl_stmt: type id_list DOT  */
#line 262 "proj.y"
      {
          (yyvsp[-2].n)->left = (yyvsp[-1].n);
          (yyval.n) = mknode("DECL", (yyvsp[-2].n), NULL);
      }
#line 1558 "proj.tab.c"
    break;

  case 42: /* expr_stmt: call DOT  */
#line 270 "proj.y"
      { (yyval.n) = (yyvsp[-1].n); }
#line 1564 "proj.tab.c"
    break;

  case 43: /* return_stmt: RETURN expr DOT  */
#line 275 "proj.y"
      { (yyval.n) = mknode("RET", (yyvsp[-1].n), NULL); }
#line 1570 "proj.tab.c"
    break;

  case 44: /* return_stmt: RETURN DOT  */
#line 277 "proj.y"
      { (yyval.n) = mknode("RET", mknode("VOID", NULL, NULL), NULL); }
#line 1576 "proj.tab.c"
    break;

  case 45: /* pass_stmt: PASS DOT  */
#line 281 "proj.y"
               { (yyval.n) = mknode("PASS", NULL, NULL); }
#line 1582 "proj.tab.c"
    break;

  case 46: /* while_stmt: WHILE expr COLON suite  */
#line 286 "proj.y"
      {
          node *cond = (yyvsp[-2].n);
          cond->right = (yyvsp[0].n);
          (yyval.n) = mknode("WHILE", cond, NULL);
      }
#line 1592 "proj.tab.c"
    break;

  case 47: /* expr: expr OR expr  */
#line 294 "proj.y"
                      { node *n = mknode("OR", (yyvsp[-2].n), NULL); (yyvsp[-2].n)->right = (yyvsp[0].n); (yyval.n) = n; }
#line 1598 "proj.tab.c"
    break;

  case 48: /* expr: expr AND expr  */
#line 295 "proj.y"
                      { node *n = mknode("AND", (yyvsp[-2].n), NULL); (yyvsp[-2].n)->right = (yyvsp[0].n); (yyval.n) = n; }
#line 1604 "proj.tab.c"
    break;

  case 49: /* expr: expr EQ expr  */
#line 296 "proj.y"
                      { node *n = mknode("==", (yyvsp[-2].n), NULL); (yyvsp[-2].n)->right = (yyvsp[0].n); (yyval.n) = n; }
#line 1610 "proj.tab.c"
    break;

  case 50: /* expr: expr NEQ expr  */
#line 297 "proj.y"
                      { node *n = mknode("!=", (yyvsp[-2].n), NULL); (yyvsp[-2].n)->right = (yyvsp[0].n); (yyval.n) = n; }
#line 1616 "proj.tab.c"
    break;

  case 51: /* expr: expr GEQ expr  */
#line 298 "proj.y"
                      { node *n = mknode(">=", (yyvsp[-2].n), NULL); (yyvsp[-2].n)->right = (yyvsp[0].n); (yyval.n) = n; }
#line 1622 "proj.tab.c"
    break;

  case 52: /* expr: expr LEQ expr  */
#line 299 "proj.y"
                      { node *n = mknode("<=", (yyvsp[-2].n), NULL); (yyvsp[-2].n)->right = (yyvsp[0].n); (yyval.n) = n; }
#line 1628 "proj.tab.c"
    break;

  case 53: /* expr: expr GREATER expr  */
#line 300 "proj.y"
                        { node *n = mknode(">", (yyvsp[-2].n), NULL); (yyvsp[-2].n)->right = (yyvsp[0].n); (yyval.n) = n; }
#line 1634 "proj.tab.c"
    break;

  case 54: /* expr: expr LESS expr  */
#line 301 "proj.y"
                      { node *n = mknode("<", (yyvsp[-2].n), NULL); (yyvsp[-2].n)->right = (yyvsp[0].n); (yyval.n) = n; }
#line 1640 "proj.tab.c"
    break;

  case 55: /* expr: expr PLUS expr  */
#line 302 "proj.y"
                      { node *n = mknode("+", (yyvsp[-2].n), NULL); (yyvsp[-2].n)->right = (yyvsp[0].n); (yyval.n) = n; }
#line 1646 "proj.tab.c"
    break;

  case 56: /* expr: expr MINUS expr  */
#line 303 "proj.y"
                      { node *n = mknode("-", (yyvsp[-2].n), NULL); (yyvsp[-2].n)->right = (yyvsp[0].n); (yyval.n) = n; }
#line 1652 "proj.tab.c"
    break;

  case 57: /* expr: expr MUL expr  */
#line 304 "proj.y"
                      { node *n = mknode("*", (yyvsp[-2].n), NULL); (yyvsp[-2].n)->right = (yyvsp[0].n); (yyval.n) = n; }
#line 1658 "proj.tab.c"
    break;

  case 58: /* expr: expr DIV expr  */
#line 305 "proj.y"
                      { node *n = mknode("/", (yyvsp[-2].n), NULL); (yyvsp[-2].n)->right = (yyvsp[0].n); (yyval.n) = n; }
#line 1664 "proj.tab.c"
    break;

  case 59: /* expr: expr POW expr  */
#line 306 "proj.y"
                      { node *n = mknode("**", (yyvsp[-2].n), NULL); (yyvsp[-2].n)->right = (yyvsp[0].n); (yyval.n) = n; }
#line 1670 "proj.tab.c"
    break;

  case 60: /* expr: NOT expr  */
#line 307 "proj.y"
                         { node *n = mknode("NOT", (yyvsp[0].n), NULL); (yyval.n) = n; }
#line 1676 "proj.tab.c"
    break;

  case 61: /* expr: primary  */
#line 308 "proj.y"
                      { (yyval.n) = (yyvsp[0].n); }
#line 1682 "proj.tab.c"
    break;

  case 62: /* primary: INT  */
#line 312 "proj.y"
                      { (yyval.n) = int_node((yyvsp[0].ival)); }
#line 1688 "proj.tab.c"
    break;

  case 63: /* primary: FLOAT  */
#line 313 "proj.y"
                      { (yyval.n) = float_node((yyvsp[0].fval)); }
#line 1694 "proj.tab.c"
    break;

  case 64: /* primary: ID  */
#line 314 "proj.y"
                      { (yyval.n) = mk_leaf((yyvsp[0].sval)); }
#line 1700 "proj.tab.c"
    break;

  case 65: /* primary: STRING  */
#line 315 "proj.y"
                      { (yyval.n) = mk_leaf((yyvsp[0].sval)); }
#line 1706 "proj.tab.c"
    break;

  case 66: /* primary: TRUE  */
#line 316 "proj.y"
                      { (yyval.n) = mknode("True", NULL, NULL); }
#line 1712 "proj.tab.c"
    break;

  case 67: /* primary: FALSE  */
#line 317 "proj.y"
                      { (yyval.n) = mknode("False", NULL, NULL); }
#line 1718 "proj.tab.c"
    break;

  case 68: /* primary: LPAREN expr RPAREN  */
#line 318 "proj.y"
                         { (yyval.n) = (yyvsp[-1].n); }
#line 1724 "proj.tab.c"
    break;

  case 69: /* primary: call  */
#line 319 "proj.y"
                      { (yyval.n) = (yyvsp[0].n); }
#line 1730 "proj.tab.c"
    break;

  case 70: /* primary: primary LBRACK expr RBRACK  */
#line 321 "proj.y"
      {
          node *base = (yyvsp[-3].n);
          base->right = (yyvsp[-1].n);
          (yyval.n) = mknode("INDEX", base, NULL);
      }
#line 1740 "proj.tab.c"
    break;

  case 71: /* call: ID LPAREN opt_arg_expr_list RPAREN  */
#line 330 "proj.y"
      {
          node *func_name = mk_leaf((yyvsp[-3].sval));
          node *args = (yyvsp[-1].n);
          func_name->right = args;
          (yyval.n) = mknode("CALL", func_name, NULL);
      }
#line 1751 "proj.tab.c"
    break;

  case 72: /* opt_arg_expr_list: %empty  */
#line 340 "proj.y"
      { (yyval.n) = mknode("ARGS", mknode("NONE", NULL, NULL), NULL); }
#line 1757 "proj.tab.c"
    break;

  case 73: /* opt_arg_expr_list: arg_expr_list  */
#line 342 "proj.y"
      { (yyval.n) = mknode("ARGS", (yyvsp[0].n), NULL); }
#line 1763 "proj.tab.c"
    break;

  case 74: /* arg_expr_list: expr  */
#line 346 "proj.y"
           { (yyval.n) = (yyvsp[0].n); }
#line 1769 "proj.tab.c"
    break;

  case 75: /* arg_expr_list: expr COMMA arg_expr_list  */
#line 348 "proj.y"
      {
          (yyvsp[-2].n)->right = (yyvsp[0].n);
          (yyval.n) = (yyvsp[-2].n);
      }
#line 1778 "proj.tab.c"
    break;


#line 1782 "proj.tab.c"

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

#line 354 "proj.y"


int main() {
    return yyparse();
}

int yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s near '%s'\n", lineno, s, yytext);
    return 0;
}

node *mknode(char *token, node *left, node *right) {
    node *newnode = (node*)malloc(sizeof(node));
    char *newstr = (char*)malloc(strlen(token) + 1);
    strcpy(newstr, token);
    newnode->left = left;
    newnode->right = right;
    newnode->token = newstr;
    newnode->lineno = lineno;
    return newnode;
}

node *mk_leaf(char *token) {
    node *n = mknode(token, NULL, NULL);
    n->lineno = lineno;
    return n;
}

node *int_node(int val) {
    char buff[20];
    sprintf(buff, "%d", val);
    node *n = mknode(buff, NULL, NULL);
    n->lineno = lineno;
    return n;
}

node *float_node(float val) {
    char buff[30];
    sprintf(buff, "%.2f", val);
    node *n = mknode(buff, NULL, NULL);
    n->lineno = lineno;
    return n;
}

void printtree(node *tree, int indent) {
    if (!tree) return;
    for (int i = 0; i < indent; ++i) printf("  ");
    if (tree->left == NULL) {
        printf("%s\n", tree->token);
    } else {
        printf("(%s\n", tree->token);
        node *child = tree->left;
        while (child) {
            printtree(child, indent + 1);
            child = child->right;
        }
        for (int i = 0; i < indent; ++i) printf("  ");
        printf(")\n");
    }
}
