/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     STRING = 258,
     ID = 259,
     INT = 260,
     FLOAT = 261,
     IF = 262,
     ELSE = 263,
     ELIF = 264,
     WHILE = 265,
     RETURN = 266,
     AND = 267,
     OR = 268,
     NOT = 269,
     PASS = 270,
     DEF = 271,
     BOOL = 272,
     KW_INT = 273,
     KW_STRING = 274,
     KW_FLOAT = 275,
     EQ = 276,
     ASSIGN = 277,
     GEQ = 278,
     LEQ = 279,
     LESS = 280,
     GREATER = 281,
     NEQ = 282,
     PLUS = 283,
     MINUS = 284,
     POW = 285,
     MUL = 286,
     DIV = 287,
     DOT = 288,
     SEMI = 289,
     COMMA = 290,
     LPAREN = 291,
     RPAREN = 292,
     LBRACK = 293,
     RBRACK = 294,
     ARROW = 295,
     COLON = 296,
     TRUE = 297,
     FALSE = 298,
     LOWER_THAN_ELSE = 299
   };
#endif
/* Tokens.  */
#define STRING 258
#define ID 259
#define INT 260
#define FLOAT 261
#define IF 262
#define ELSE 263
#define ELIF 264
#define WHILE 265
#define RETURN 266
#define AND 267
#define OR 268
#define NOT 269
#define PASS 270
#define DEF 271
#define BOOL 272
#define KW_INT 273
#define KW_STRING 274
#define KW_FLOAT 275
#define EQ 276
#define ASSIGN 277
#define GEQ 278
#define LEQ 279
#define LESS 280
#define GREATER 281
#define NEQ 282
#define PLUS 283
#define MINUS 284
#define POW 285
#define MUL 286
#define DIV 287
#define DOT 288
#define SEMI 289
#define COMMA 290
#define LPAREN 291
#define RPAREN 292
#define LBRACK 293
#define RBRACK 294
#define ARROW 295
#define COLON 296
#define TRUE 297
#define FALSE 298
#define LOWER_THAN_ELSE 299




/* Copy the first part of user declarations.  */
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
} node;

node *mknode(char *token, node *left, node *right);
node *mk_leaf(char *token);
node *int_node(int val);
node *float_node(float val);
void printtree(node *tree, int indent);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 24 "proj.y"
{
    char *sval;
    int ival;
    float fval;
    struct node *n;
}
/* Line 193 of yacc.c.  */
#line 214 "proj.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 227 "proj.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

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
/* YYNRULES -- Number of states.  */
#define YYNSTATES  130

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    19,    20,    22,    24,
      28,    31,    33,    35,    37,    39,    41,    45,    46,    48,
      51,    53,    55,    59,    61,    63,    64,    67,    69,    71,
      73,    75,    77,    79,    81,    86,    92,    97,   103,   107,
     112,   118,   122,   125,   129,   132,   135,   140,   144,   148,
     152,   156,   160,   164,   168,   172,   176,   180,   184,   188,
     192,   195,   197,   199,   201,   203,   205,   207,   209,   213,
     215,   220,   225,   226,   228,   230
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,    47,    -1,    48,    -1,    47,    48,    -1,
      16,     4,    36,    49,    37,    54,    41,    56,    -1,    -1,
      50,    -1,    51,    -1,    51,    34,    50,    -1,    52,    53,
      -1,    18,    -1,    19,    -1,    20,    -1,    17,    -1,     4,
      -1,     4,    35,    53,    -1,    -1,    55,    -1,    40,    52,
      -1,    57,    -1,    60,    -1,    25,    59,    26,    -1,    57,
      -1,    60,    -1,    -1,    59,    60,    -1,    61,    -1,    63,
      -1,    64,    -1,    66,    -1,    67,    -1,    68,    -1,    65,
      -1,     7,    69,    41,    58,    -1,     7,    69,    41,    58,
      62,    -1,     9,    69,    41,    58,    -1,     9,    69,    41,
      58,    62,    -1,     8,    41,    58,    -1,     4,    22,    69,
      33,    -1,    52,     4,    22,    69,    33,    -1,    52,    53,
      33,    -1,    71,    33,    -1,    11,    69,    33,    -1,    11,
      33,    -1,    15,    33,    -1,    10,    69,    41,    58,    -1,
      69,    13,    69,    -1,    69,    12,    69,    -1,    69,    21,
      69,    -1,    69,    27,    69,    -1,    69,    23,    69,    -1,
      69,    24,    69,    -1,    69,    26,    69,    -1,    69,    25,
      69,    -1,    69,    28,    69,    -1,    69,    29,    69,    -1,
      69,    31,    69,    -1,    69,    32,    69,    -1,    69,    30,
      69,    -1,    14,    69,    -1,    70,    -1,     5,    -1,     6,
      -1,     4,    -1,     3,    -1,    42,    -1,    43,    -1,    36,
      69,    37,    -1,    71,    -1,    70,    38,    69,    39,    -1,
       4,    36,    72,    37,    -1,    -1,    73,    -1,    69,    -1,
      69,    35,    73,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    61,    61,    66,    67,    77,    95,    96,   101,   102,
     110,   119,   120,   121,   122,   126,   127,   138,   139,   144,
     149,   151,   156,   162,   163,   167,   168,   181,   182,   183,
     184,   185,   186,   187,   192,   200,   214,   220,   228,   233,
     242,   249,   257,   262,   264,   269,   273,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   317,   328,   329,   334,   335
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING", "ID", "INT", "FLOAT", "IF",
  "ELSE", "ELIF", "WHILE", "RETURN", "AND", "OR", "NOT", "PASS", "DEF",
  "BOOL", "KW_INT", "KW_STRING", "KW_FLOAT", "EQ", "ASSIGN", "GEQ", "LEQ",
  "LESS", "GREATER", "NEQ", "PLUS", "MINUS", "POW", "MUL", "DIV", "DOT",
  "SEMI", "COMMA", "LPAREN", "RPAREN", "LBRACK", "RBRACK", "ARROW",
  "COLON", "TRUE", "FALSE", "LOWER_THAN_ELSE", "$accept", "program",
  "func_list", "func", "args", "arg_decl_list", "param_decl", "type",
  "id_list", "opt_ret_type", "return_type", "body", "block", "suite",
  "stmt_list", "stmt", "if_stmt", "elif_tail", "assign_stmt", "decl_stmt",
  "expr_stmt", "return_stmt", "pass_stmt", "while_stmt", "expr", "primary",
  "call", "opt_arg_expr_list", "arg_expr_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
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

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
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

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
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

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    13,    14,    15,    35,    20,    22,
      23,    36,   112,   113,    64,   114,    39,   121,    40,    41,
      42,    43,    44,    45,    69,    58,    59,    70,    71
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -84
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

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -84,   -84,   -84,   113,   -84,    99,   -84,    -4,   -12,   -84,
     -84,   -84,    91,   -83,   -84,   -22,   -84,    -9,   -84,   -84,
     -84,   -84,   -84,   -84,   -29,   -84,   -27,   -84,    24
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
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

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
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

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 62 "proj.y"
    { (yyval.n) = mknode("CODE", (yyvsp[(1) - (1)].n), NULL); printtree((yyval.n), 0); ;}
    break;

  case 3:
#line 66 "proj.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); ;}
    break;

  case 4:
#line 68 "proj.y"
    {
          node *t = (yyvsp[(1) - (2)].n);
          while(t->right != NULL) t = t->right;
          t->right = (yyvsp[(2) - (2)].n);
          (yyval.n) = (yyvsp[(1) - (2)].n);
      ;}
    break;

  case 5:
#line 78 "proj.y"
    {
          node *func_name = mk_leaf((yyvsp[(2) - (8)].sval));
          node *a = (yyvsp[(4) - (8)].n);      /* ARGS node */
          node *r = (yyvsp[(6) - (8)].n);      /* RETURN node */
          node *b = (yyvsp[(8) - (8)].n);      /* BODY node */

          /* (FUNC foo (ARGS ...) (RETURN ...) (BODY ...)) */
          func_name->right = a;
          a->right = r;
          r->right = b;

          (yyval.n) = mknode("FUNC", func_name, NULL);
      ;}
    break;

  case 6:
#line 95 "proj.y"
    { (yyval.n) = mknode("ARGS", mknode("NONE", NULL, NULL), NULL); ;}
    break;

  case 7:
#line 97 "proj.y"
    { (yyval.n) = mknode("ARGS", (yyvsp[(1) - (1)].n), NULL); ;}
    break;

  case 8:
#line 101 "proj.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); ;}
    break;

  case 9:
#line 103 "proj.y"
    {
          (yyvsp[(1) - (3)].n)->right = (yyvsp[(3) - (3)].n);
          (yyval.n) = (yyvsp[(1) - (3)].n);
      ;}
    break;

  case 10:
#line 111 "proj.y"
    {
          /* (INT x y z) or (BOOL f) */
          (yyvsp[(1) - (2)].n)->left = (yyvsp[(2) - (2)].n);
          (yyval.n) = (yyvsp[(1) - (2)].n);
      ;}
    break;

  case 11:
#line 119 "proj.y"
    { (yyval.n) = mknode("INT", NULL, NULL); ;}
    break;

  case 12:
#line 120 "proj.y"
    { (yyval.n) = mknode("STRING", NULL, NULL); ;}
    break;

  case 13:
#line 121 "proj.y"
    { (yyval.n) = mknode("FLOAT", NULL, NULL); ;}
    break;

  case 14:
#line 122 "proj.y"
    { (yyval.n) = mknode("BOOL", NULL, NULL); ;}
    break;

  case 15:
#line 126 "proj.y"
    { (yyval.n) = mk_leaf((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 16:
#line 128 "proj.y"
    {
          node *n = mk_leaf((yyvsp[(1) - (3)].sval));
          n->right = (yyvsp[(3) - (3)].n);
          (yyval.n) = n;
      ;}
    break;

  case 17:
#line 138 "proj.y"
    { (yyval.n) = mknode("RETURN", mknode("VOID", NULL, NULL), NULL); ;}
    break;

  case 18:
#line 140 "proj.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); ;}
    break;

  case 19:
#line 145 "proj.y"
    { (yyval.n) = mknode("RETURN", (yyvsp[(2) - (2)].n), NULL); ;}
    break;

  case 20:
#line 150 "proj.y"
    { (yyval.n) = mknode("BODY", (yyvsp[(1) - (1)].n)->left, NULL); ;}
    break;

  case 21:
#line 152 "proj.y"
    { (yyval.n) = mknode("BODY", (yyvsp[(1) - (1)].n), NULL); ;}
    break;

  case 22:
#line 157 "proj.y"
    { (yyval.n) = mknode("BLOCK", (yyvsp[(2) - (3)].n), NULL); ;}
    break;

  case 23:
#line 162 "proj.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); ;}
    break;

  case 24:
#line 163 "proj.y"
    { (yyval.n) = mknode("BLOCK", (yyvsp[(1) - (1)].n), NULL); ;}
    break;

  case 25:
#line 167 "proj.y"
    { (yyval.n) = NULL; ;}
    break;

  case 26:
#line 169 "proj.y"
    {
          if ((yyvsp[(1) - (2)].n) == NULL) (yyval.n) = (yyvsp[(2) - (2)].n);
          else {
              node *p = (yyvsp[(1) - (2)].n);
              while (p->right) p = p->right;
              p->right = (yyvsp[(2) - (2)].n);
              (yyval.n) = (yyvsp[(1) - (2)].n);
          }
      ;}
    break;

  case 34:
#line 193 "proj.y"
    {
          /* מבנה ילדים: cond -> then (ללא tail) */
          node *cond = (yyvsp[(2) - (4)].n);
          node *then_b = (yyvsp[(4) - (4)].n);
          cond->right = then_b;
          (yyval.n) = mknode("IF", cond, NULL);
      ;}
    break;

  case 35:
#line 201 "proj.y"
    {
          /* מבנה ילדים: cond -> then -> tail (ELIF/ELSE) */
          node *cond = (yyvsp[(2) - (5)].n);
          node *then_b = (yyvsp[(4) - (5)].n);
          node *tail = (yyvsp[(5) - (5)].n);
          cond->right = then_b;
          then_b->right = tail;
          (yyval.n) = mknode("IF", cond, NULL);
      ;}
    break;

  case 36:
#line 215 "proj.y"
    {
          node *cond = (yyvsp[(2) - (4)].n);
          cond->right = (yyvsp[(4) - (4)].n);
          (yyval.n) = mknode("ELIF", cond, NULL);
      ;}
    break;

  case 37:
#line 221 "proj.y"
    {
          node *cond = (yyvsp[(2) - (5)].n);
          cond->right = (yyvsp[(4) - (5)].n);
          node *elif_node = mknode("ELIF", cond, NULL);
          elif_node->right = (yyvsp[(5) - (5)].n);
          (yyval.n) = elif_node;
      ;}
    break;

  case 38:
#line 229 "proj.y"
    { (yyval.n) = mknode("ELSE", (yyvsp[(3) - (3)].n), NULL); ;}
    break;

  case 39:
#line 234 "proj.y"
    {
          node *id = mk_leaf((yyvsp[(1) - (4)].sval));
          id->right = (yyvsp[(3) - (4)].n);
          (yyval.n) = mknode("ASS", id, NULL);
      ;}
    break;

  case 40:
#line 243 "proj.y"
    {
          node *id = mk_leaf((yyvsp[(2) - (5)].sval));
          (yyvsp[(1) - (5)].n)->left = id;
          id->right = (yyvsp[(4) - (5)].n);
          (yyval.n) = mknode("DECL", (yyvsp[(1) - (5)].n), NULL);
      ;}
    break;

  case 41:
#line 250 "proj.y"
    {
          (yyvsp[(1) - (3)].n)->left = (yyvsp[(2) - (3)].n);
          (yyval.n) = mknode("DECL", (yyvsp[(1) - (3)].n), NULL);
      ;}
    break;

  case 42:
#line 258 "proj.y"
    { (yyval.n) = (yyvsp[(1) - (2)].n); ;}
    break;

  case 43:
#line 263 "proj.y"
    { (yyval.n) = mknode("RET", (yyvsp[(2) - (3)].n), NULL); ;}
    break;

  case 44:
#line 265 "proj.y"
    { (yyval.n) = mknode("RET", mknode("VOID", NULL, NULL), NULL); ;}
    break;

  case 45:
#line 269 "proj.y"
    { (yyval.n) = mknode("PASS", NULL, NULL); ;}
    break;

  case 46:
#line 274 "proj.y"
    {
          node *cond = (yyvsp[(2) - (4)].n);
          cond->right = (yyvsp[(4) - (4)].n);
          (yyval.n) = mknode("WHILE", cond, NULL);
      ;}
    break;

  case 47:
#line 282 "proj.y"
    { node *n = mknode("OR", (yyvsp[(1) - (3)].n), NULL); (yyvsp[(1) - (3)].n)->right = (yyvsp[(3) - (3)].n); (yyval.n) = n; ;}
    break;

  case 48:
#line 283 "proj.y"
    { node *n = mknode("AND", (yyvsp[(1) - (3)].n), NULL); (yyvsp[(1) - (3)].n)->right = (yyvsp[(3) - (3)].n); (yyval.n) = n; ;}
    break;

  case 49:
#line 284 "proj.y"
    { node *n = mknode("==", (yyvsp[(1) - (3)].n), NULL); (yyvsp[(1) - (3)].n)->right = (yyvsp[(3) - (3)].n); (yyval.n) = n; ;}
    break;

  case 50:
#line 285 "proj.y"
    { node *n = mknode("!=", (yyvsp[(1) - (3)].n), NULL); (yyvsp[(1) - (3)].n)->right = (yyvsp[(3) - (3)].n); (yyval.n) = n; ;}
    break;

  case 51:
#line 286 "proj.y"
    { node *n = mknode(">=", (yyvsp[(1) - (3)].n), NULL); (yyvsp[(1) - (3)].n)->right = (yyvsp[(3) - (3)].n); (yyval.n) = n; ;}
    break;

  case 52:
#line 287 "proj.y"
    { node *n = mknode("<=", (yyvsp[(1) - (3)].n), NULL); (yyvsp[(1) - (3)].n)->right = (yyvsp[(3) - (3)].n); (yyval.n) = n; ;}
    break;

  case 53:
#line 288 "proj.y"
    { node *n = mknode(">", (yyvsp[(1) - (3)].n), NULL); (yyvsp[(1) - (3)].n)->right = (yyvsp[(3) - (3)].n); (yyval.n) = n; ;}
    break;

  case 54:
#line 289 "proj.y"
    { node *n = mknode("<", (yyvsp[(1) - (3)].n), NULL); (yyvsp[(1) - (3)].n)->right = (yyvsp[(3) - (3)].n); (yyval.n) = n; ;}
    break;

  case 55:
#line 290 "proj.y"
    { node *n = mknode("+", (yyvsp[(1) - (3)].n), NULL); (yyvsp[(1) - (3)].n)->right = (yyvsp[(3) - (3)].n); (yyval.n) = n; ;}
    break;

  case 56:
#line 291 "proj.y"
    { node *n = mknode("-", (yyvsp[(1) - (3)].n), NULL); (yyvsp[(1) - (3)].n)->right = (yyvsp[(3) - (3)].n); (yyval.n) = n; ;}
    break;

  case 57:
#line 292 "proj.y"
    { node *n = mknode("*", (yyvsp[(1) - (3)].n), NULL); (yyvsp[(1) - (3)].n)->right = (yyvsp[(3) - (3)].n); (yyval.n) = n; ;}
    break;

  case 58:
#line 293 "proj.y"
    { node *n = mknode("/", (yyvsp[(1) - (3)].n), NULL); (yyvsp[(1) - (3)].n)->right = (yyvsp[(3) - (3)].n); (yyval.n) = n; ;}
    break;

  case 59:
#line 294 "proj.y"
    { node *n = mknode("**", (yyvsp[(1) - (3)].n), NULL); (yyvsp[(1) - (3)].n)->right = (yyvsp[(3) - (3)].n); (yyval.n) = n; ;}
    break;

  case 60:
#line 295 "proj.y"
    { node *n = mknode("NOT", (yyvsp[(2) - (2)].n), NULL); (yyval.n) = n; ;}
    break;

  case 61:
#line 296 "proj.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); ;}
    break;

  case 62:
#line 300 "proj.y"
    { (yyval.n) = int_node((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 63:
#line 301 "proj.y"
    { (yyval.n) = float_node((yyvsp[(1) - (1)].fval)); ;}
    break;

  case 64:
#line 302 "proj.y"
    { (yyval.n) = mk_leaf((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 65:
#line 303 "proj.y"
    { (yyval.n) = mk_leaf((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 66:
#line 304 "proj.y"
    { (yyval.n) = mknode("True", NULL, NULL); ;}
    break;

  case 67:
#line 305 "proj.y"
    { (yyval.n) = mknode("False", NULL, NULL); ;}
    break;

  case 68:
#line 306 "proj.y"
    { (yyval.n) = (yyvsp[(2) - (3)].n); ;}
    break;

  case 69:
#line 307 "proj.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); ;}
    break;

  case 70:
#line 309 "proj.y"
    {
          node *base = (yyvsp[(1) - (4)].n);
          base->right = (yyvsp[(3) - (4)].n);
          (yyval.n) = mknode("INDEX", base, NULL);
      ;}
    break;

  case 71:
#line 318 "proj.y"
    {
          node *func_name = mk_leaf((yyvsp[(1) - (4)].sval));
          node *args = (yyvsp[(3) - (4)].n);
          func_name->right = args;
          (yyval.n) = mknode("CALL", func_name, NULL);
      ;}
    break;

  case 72:
#line 328 "proj.y"
    { (yyval.n) = mknode("ARGS", mknode("NONE", NULL, NULL), NULL); ;}
    break;

  case 73:
#line 330 "proj.y"
    { (yyval.n) = mknode("ARGS", (yyvsp[(1) - (1)].n), NULL); ;}
    break;

  case 74:
#line 334 "proj.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); ;}
    break;

  case 75:
#line 336 "proj.y"
    {
          (yyvsp[(1) - (3)].n)->right = (yyvsp[(3) - (3)].n);
          (yyval.n) = (yyvsp[(1) - (3)].n);
      ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2005 "proj.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 342 "proj.y"


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
    return newnode;
}

node *mk_leaf(char *token) {
    return mknode(token, NULL, NULL);
}

node *int_node(int val) {
    char buff[20];
    sprintf(buff, "%d", val);
    return mknode(buff, NULL, NULL);
}

node *float_node(float val) {
    char buff[30];
    sprintf(buff, "%.2f", val);
    return mknode(buff, NULL, NULL);
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

