/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./constants.h"
#include <errno.h>
#include "./syntax_tree.h"
#include "./name_hash.h"


extern int line_no;

syntax_tree* tree_root;

void yyerror(const char* s){
    fprintf(stderr, "Error at line #%d: %s\n", line_no, s);
    exit(0);
}


#line 87 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    WHILE = 260,
    CONTINUE = 261,
    BREAK = 262,
    RETURN = 263,
    INT = 264,
    VOID = 265,
    CONST = 266,
    L_PAR = 267,
    R_PAR = 268,
    L_SBRAC = 269,
    R_SBRAC = 270,
    L_CBRAC = 271,
    R_CBRAC = 272,
    COMMA = 273,
    COLON = 274,
    DECIMAL_TOK = 275,
    IDENT = 276,
    NOT_OP1 = 277,
    MULDIV_OP2 = 278,
    ADDMIN_OP3 = 279,
    COMP_OP4 = 280,
    EQUAL_OP5 = 281,
    AND_OP6 = 282,
    OR_OP7 = 283,
    ASSIGN_OP8 = 284
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define WHILE 260
#define CONTINUE 261
#define BREAK 262
#define RETURN 263
#define INT 264
#define VOID 265
#define CONST 266
#define L_PAR 267
#define R_PAR 268
#define L_SBRAC 269
#define R_SBRAC 270
#define L_CBRAC 271
#define R_CBRAC 272
#define COMMA 273
#define COLON 274
#define DECIMAL_TOK 275
#define IDENT 276
#define NOT_OP1 277
#define MULDIV_OP2 278
#define ADDMIN_OP3 279
#define COMP_OP4 280
#define EQUAL_OP5 281
#define AND_OP6 282
#define OR_OP7 283
#define ASSIGN_OP8 284

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 191 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   197

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    44,    44,    50,    56,    62,    69,    70,    72,    77,
      83,    88,    94,    95,   100,   106,   113,   122,   127,   131,
     136,   141,   147,   149,   154,   160,   167,   175,   180,   187,
     192,   196,   201,   206,   212,   219,   228,   232,   237,   242,
     248,   253,   260,   266,   274,   279,   283,   289,   290,   292,
     296,   303,   308,   313,   319,   326,   332,   336,   340,   344,
     350,   352,   354,   355,   362,   363,   370,   371,   376,   381,
     387,   392,   397,   402,   408,   409,   410,   412,   420,   421,
     428,   429,   436,   438,   439,   446,   447,   454,   459
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "WHILE", "CONTINUE",
  "BREAK", "RETURN", "INT", "VOID", "CONST", "L_PAR", "R_PAR", "L_SBRAC",
  "R_SBRAC", "L_CBRAC", "R_CBRAC", "COMMA", "COLON", "DECIMAL_TOK",
  "IDENT", "NOT_OP1", "MULDIV_OP2", "ADDMIN_OP3", "COMP_OP4", "EQUAL_OP5",
  "AND_OP6", "OR_OP7", "ASSIGN_OP8", "$accept", "COMP_UNIT", "DECL",
  "CONST_INDEXES", "VAR_INDEXES", "CONST_DECL", "CONST_DEFS", "CONST_DEF",
  "CONST_INIT_VAL", "CONST_INIT_LIST", "VAR_DECL", "VAR_DEFS", "VAR_DEF",
  "INIT_VAL", "INIT_LIST", "FUNC_DEF", "FUNC_TYPE", "FUNC_FPARAMS",
  "FUNC_FPARAM", "BLOCK", "BLOCK_ITEMS", "BLOCK_ITEM", "STMT", "CONST_EXP",
  "EXP", "ADD_EXP", "MUL_EXP", "UNARY_EXP", "UNARY_OP", "FUNC_RPARAMS",
  "PRIMARY_EXP", "LVAL", "REL_EXP", "EQ_EXP", "COND", "LAND_EXP",
  "LOR_EXP", "INTEGER", "IDENTIFIER", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284
};
# endif

#define YYPACT_NINF -99

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-99)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      67,   -12,   -99,     6,    25,    67,   -99,   -99,    67,   -12,
     -99,     7,    18,     0,   -12,   -99,   -99,   -99,    33,   -99,
     -12,   114,    83,     8,    30,    36,    13,     4,   -99,   114,
     -99,   -99,   -99,    50,   -99,    31,    48,   -99,   114,   -99,
     -99,   -99,    34,    40,   -99,   -99,    83,   -99,   -12,   136,
      44,   -12,    63,    69,    65,    73,    71,   114,   114,   -99,
      46,   114,   -99,   -99,    79,    74,   -99,   -99,    72,   -99,
     -99,   136,    84,   103,   -99,    63,    92,   -99,   -99,    48,
     -99,   -99,    95,   104,   101,    83,   -99,   -99,   102,   123,
     -99,   147,   -99,   131,   139,   134,   135,   153,   -12,   -99,
     -99,   -99,   138,   103,   -99,   -99,   132,   -99,   -99,   114,
     -99,   149,   -99,   136,   -99,    71,   114,   114,   -99,   -99,
     -99,   145,   -99,   -99,   114,   -99,   -99,   -99,   -99,    31,
     141,   144,   163,   151,   152,   166,   -99,   162,   114,   114,
     125,   114,   114,   125,   -99,    31,   141,   178,   144,   151,
     -99,   125,   -99
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    37,     0,     0,     2,     6,     7,     3,     0,
      88,     0,    23,    27,     0,     1,     4,     5,     0,    22,
       0,     0,     0,    28,     0,    13,     0,     0,    24,     0,
      87,    71,    70,     0,    60,    61,    62,    64,     0,    66,
      75,    76,     0,     0,    25,    29,     0,    12,     0,     0,
       0,     0,     0,     0,    38,     0,     8,     0,     0,    69,
       0,     0,    77,    30,    32,     0,    26,    14,     0,    15,
      17,     0,    40,     0,    34,     0,     0,    74,     9,    63,
      65,    67,    72,     0,     0,     0,    31,    18,    20,     0,
      16,     0,    42,     0,     0,     0,     0,     0,     0,    49,
      47,    52,     0,    45,    48,    51,    75,    35,    39,     0,
      68,    10,    33,     0,    19,    41,     0,     0,    57,    56,
      58,     0,    44,    46,     0,    73,    11,    21,    43,    78,
      80,    83,     0,    85,    82,     0,    59,     0,     0,     0,
       0,     0,     0,     0,    50,    79,    81,    53,    84,    86,
      55,     0,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -99,    15,   -68,   -25,    75,   -99,   137,   -99,   -37,    70,
     -99,   164,   -99,   -16,   105,   -99,   -99,   111,   -99,   -42,
      85,   -99,    -1,   -17,   -22,   -98,   140,   -30,   -99,    80,
     -99,   -71,    52,    51,    76,    53,   -99,   -99,     2
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,    23,    62,     6,    24,    25,    88,    89,
       7,    11,    12,    64,    65,     8,     9,    53,    54,   101,
     102,   103,   104,    70,    34,    35,    36,    37,    38,    83,
      39,    40,   130,   131,   132,   133,   134,    41,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      45,    50,   106,    13,    33,   100,    44,    55,    59,    10,
      74,    18,    69,    51,    21,    14,    26,    52,   129,   129,
      16,    45,    13,    17,    45,    15,    19,    21,    80,    22,
      66,    78,   106,   107,    90,   100,    20,    46,    82,    84,
     145,   129,    49,   129,   129,    27,    60,    92,    61,    47,
      26,   105,    29,    72,    48,    57,    43,    63,    29,    81,
      30,    10,    31,    45,    32,    56,    30,    10,    31,   106,
      32,    58,   106,    71,    33,   121,     1,     2,     3,    73,
     106,   105,    75,    76,    29,    21,    77,    82,    68,    87,
     128,    86,    30,    10,    31,    29,    32,    85,    91,    43,
      13,    51,   137,    30,    10,    31,    93,    32,    94,    95,
      96,    97,    98,   109,     3,    29,   111,   110,   105,    73,
     113,   105,    99,    30,    10,    31,    29,    32,    93,   105,
      94,    95,    96,    97,    30,    10,    31,    29,    32,   147,
     114,    73,   150,   116,    99,    30,    10,    31,    29,    32,
     152,   117,    68,   118,   119,   122,    30,    10,    31,    29,
      32,   124,   115,    61,   136,    29,   138,    30,    10,    31,
     139,    32,   120,    30,    10,    31,   140,    32,   141,   143,
     142,   144,   151,   127,    28,    67,   126,   108,   123,   125,
     112,   146,   148,   135,     0,   149,     0,    79
};

static const yytype_int16 yycheck[] =
{
      22,    26,    73,     1,    21,    73,    22,    29,    38,    21,
      52,     9,    49,     9,    14,     9,    14,    13,   116,   117,
       5,    43,    20,     8,    46,     0,    19,    14,    58,    29,
      46,    56,   103,    75,    71,   103,    18,    29,    60,    61,
     138,   139,    29,   141,   142,    12,    12,    72,    14,    19,
      48,    73,    12,    51,    18,    24,    16,    17,    12,    13,
      20,    21,    22,    85,    24,    15,    20,    21,    22,   140,
      24,    23,   143,    29,    91,    97,     9,    10,    11,    16,
     151,   103,    13,    18,    12,    14,    13,   109,    16,    17,
     115,    17,    20,    21,    22,    12,    24,    18,    14,    16,
      98,     9,   124,    20,    21,    22,     3,    24,     5,     6,
       7,     8,     9,    18,    11,    12,    15,    13,   140,    16,
      18,   143,    19,    20,    21,    22,    12,    24,     3,   151,
       5,     6,     7,     8,    20,    21,    22,    12,    24,   140,
      17,    16,   143,    12,    19,    20,    21,    22,    12,    24,
     151,    12,    16,    19,    19,    17,    20,    21,    22,    12,
      24,    29,    15,    14,    19,    12,    25,    20,    21,    22,
      26,    24,    19,    20,    21,    22,    13,    24,    27,    13,
      28,    19,     4,   113,    20,    48,   111,    76,   103,   109,
      85,   139,   141,   117,    -1,   142,    -1,    57
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    10,    11,    31,    32,    35,    40,    45,    46,
      21,    41,    42,    68,     9,     0,    31,    31,    68,    19,
      18,    14,    29,    33,    36,    37,    68,    12,    41,    12,
      20,    22,    24,    53,    54,    55,    56,    57,    58,    60,
      61,    67,    68,    16,    43,    54,    29,    19,    18,    29,
      33,     9,    13,    47,    48,    54,    15,    24,    23,    57,
      12,    14,    34,    17,    43,    44,    43,    36,    16,    38,
      53,    29,    68,    16,    49,    13,    18,    13,    33,    56,
      57,    13,    54,    59,    54,    18,    17,    17,    38,    39,
      38,    14,    33,     3,     5,     6,     7,     8,     9,    19,
      32,    49,    50,    51,    52,    54,    61,    49,    47,    18,
      13,    15,    44,    18,    17,    15,    12,    12,    19,    19,
      19,    54,    17,    50,    29,    59,    34,    39,    33,    55,
      62,    63,    64,    65,    66,    64,    19,    54,    25,    26,
      13,    27,    28,    13,    19,    55,    62,    52,    63,    65,
      52,     4,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    30,    31,    31,    31,    31,    32,    32,    33,    33,
      34,    34,    35,    36,    36,    37,    37,    38,    38,    38,
      39,    39,    40,    41,    41,    42,    42,    42,    42,    43,
      43,    43,    44,    44,    45,    45,    46,    46,    47,    47,
      48,    48,    48,    48,    49,    50,    50,    51,    51,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      53,    54,    55,    55,    56,    56,    57,    57,    57,    57,
      58,    58,    59,    59,    60,    60,    60,    61,    62,    62,
      63,    63,    64,    65,    65,    66,    66,    67,    68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     3,     4,
       3,     4,     4,     1,     3,     3,     4,     1,     2,     3,
       1,     3,     3,     1,     3,     3,     4,     1,     2,     1,
       2,     3,     1,     3,     5,     6,     1,     1,     1,     3,
       2,     4,     3,     5,     3,     1,     2,     1,     1,     1,
       4,     1,     1,     5,     7,     5,     2,     2,     2,     3,
       1,     1,     1,     3,     1,     3,     1,     3,     4,     2,
       1,     1,     1,     3,     3,     1,     1,     2,     1,     3,
       1,     3,     1,     1,     3,     1,     3,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
#line 45 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_COMP_UNIT, 0, 0, 0, NULL, NULL);
            tree_root = (yyval.node);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 51 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_COMP_UNIT, 0, 0, 0, NULL, NULL);
            tree_root = (yyval.node);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 57 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            tree_root = (yyval.node);
            insert_sons((yyval.node), (yyvsp[-1].node), 0);
        }
#line 1408 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 63 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            tree_root = (yyval.node);
            insert_sons((yyval.node), (yyvsp[-1].node), 0);
        }
#line 1418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 69 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node)}
#line 1424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 70 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node)}
#line 1430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 73 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(CONST_REST, TP_INDEXES, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[-1].node), 0);
        }
#line 1439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 78 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 84 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_INDEXES, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[-1].node), 0);
        }
#line 1457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 89 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 94 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 96 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(CONST_REST, TP_DECL, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 101 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 107 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(CONST_REST, TP_DEF, 1, 0, 0, NULL, (yyvsp[-1].name));
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-1].name), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 114 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(CONST_REST, TP_DEF, 3, 0, 0, NULL, (yyvsp[-1].name));
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-1].name), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
            insert_sons((yyval.node), (yyvsp[-3].node), 0);
        }
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 123 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(CONST_REST, TP_INIT_VAL, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 128 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(CONST_REST, TP_INIT_VAL, 1, 0, 0, NULL, NULL);
        }
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 132 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-1].node);
        }
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 137 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(CONST_REST, TP_INIT_VAL, 1, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 142 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 147 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 150 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_DECL, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 155 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 161 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_DEF, 1, 0, 0, NULL, (yyvsp[-1].name));
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-1].name), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 168 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_DEF, 3, 0, 0, NULL, (yyvsp[-1].name));
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-1].name), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
            insert_sons((yyval.node), (yyvsp[-3].node), 0);
        }
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 176 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_DEF, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 181 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_DEF, 2, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-1].node), 0);
        }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 188 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_INIT_VAL, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 193 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_INIT_VAL, 1, 0, 0, NULL, NULL);
        }
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 197 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-1].node);
        }
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 202 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_INIT_VAL, 1, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 207 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 213 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_FUNC_DEF, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-3].node), 0);
            insert_sons((yyval.node), (yyvsp[-4].node), 0);
        }
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 220 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_FUNC_DEF, 1, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
            insert_sons((yyval.node), (yyvsp[-4].node), 0);
            insert_sons((yyval.node), (yyvsp[-5].node), 0);
        }
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 229 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_TOKEN, 0, TOK_INT, 0, NULL, NULL);
        }
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 233 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_TOKEN, 0, TOK_VOID, 0, NULL, NULL);
        }
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 238 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_FUNC_FPRAM, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 243 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-1].name);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 249 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_DEF, 0, 0, 0, NULL, NULL);
            insert((yyval.node), (yyvsp[0].node), 0);
        }
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 254 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_DEF, 2, 0, 0, NULL, NULL);
            syntax_tree* tmp_node = new_node(NONCONST_REST, TP_INDEXES, 1, 0, 0, NULL, NULL);
            insert((yyval.node), tmp_node, 0);
            insert((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 261 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_DEF, 2, 0, 0, NULL, NULL);
            insert((yyval.node), (yyvsp[0].node), 0);
            insert((yyval.node), (yyvsp[-1].node), 0);
        }
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 267 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_DEF, 2, 0, 0, NULL, NULL);
            (yyvsp[-2].name)->option = 1;
            insert((yyval.node), (yyvsp[-2].name), 0);
            insert((yyval.node), (yyvsp[-3].node), 0);
        }
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 275 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-1].node);
        }
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 280 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_BLOCK, 0, 0, 0, NULL, NULL);
        }
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 284 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            insert_sons((yyval.node), (yyvsp[-1].node), 0);
        }
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 289 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 290 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 293 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_TOKEN, 0, TOK_NONE, 0, NULL, NULL);
        }
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 297 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_STMT, 0, 0, 0, NULL, (yyvsp[-2].name));
            insert_sons((yyval.node), (yyvsp[-1].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].name), 0);
            insert_sons((yyval.node), (yyvsp[-3].node), 0);
        }
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 304 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_STMT, 1, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 309 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_STMT, 2, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 314 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_STMT, 3, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 320 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_STMT, 4, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
            insert_sons((yyval.node), (yyvsp[-4].node), 0);
        }
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 327 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_STMT, 5, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 333 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_STMT, 6, 0, 0, NULL, NULL);
        }
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 337 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_STMT, 7, 0, 0, NULL, NULL);
        }
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 341 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_STMT, 8, 0, 0, NULL, NULL);
        }
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 345 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_STMT, 9, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[-1].node), 0);
        }
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 350 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 352 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 354 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 356 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_BINARY_EXP, 0, 0, 0, NULL, (yyvsp[-1].name));
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 362 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 364 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_BINARY_EXP, 0, 0, 0, NULL, (yyvsp[-1].name));
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 370 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 372 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_FUNC_CALL, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 377 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-1].node);
            insert_sons((yyval.node), (yyvsp[-3].node), 0);
        }
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 382 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_UNARY_EXP, 0, 0, 0, NULL, (yyvsp[-1].node)->op_name);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 388 "parser.y" /* yacc.c:1646  */
    {
            // tmp
            (yyval.node) = new_node(0, 0, 0, 0, 0, NULL, (yyvsp[0].name));
        }
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 393 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(0, 0, 0, 0, 0, NULL, (yyvsp[0].name));
        }
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 398 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_FUNC_CALL, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 403 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 408 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 409 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 410 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 413 "parser.y" /* yacc.c:1646  */
    {
            // option #2: indexing
            (yyval.node) = new_node(NONCONST_REST, TP_UNARY_EXP, 1, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-1].node), 0);
        }
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 420 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 422 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_BINARY_EXP, 0, 0, 0, NULL, (yyvsp[-1].name));
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 428 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 430 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_BINARY_EXP, 0, 0, 0, NULL, (yyvsp[-1].name));
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 436 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 438 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 440 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_BINARY_EXP, 0, 0, 0, NULL, (yyvsp[-1].name));
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 446 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 448 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_BINARY_EXP, 0, 0, 0, NULL, (yyvsp[-1].name));
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 455 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_TOKEN, 0, TOK_DEC, (yyvsp[0].value), NULL, NULL);
        }
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 460 "parser.y" /* yacc.c:1646  */
    {
            (yyval.node) = new_node(NONCONST_REST, TP_TOKEN, 0, TOK_IDENT, 0, (yyvsp[0].name), NULL);
        }
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2132 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
  return yyresult;
}
#line 465 "parser.y" /* yacc.c:1906  */


int main(int argc, char* argv){
    if (argc != 2){
        printf("Usage: ./parser TARGET_FILE\n");
        return 0;
    }
    FILE* inp_file = fopen(argv[1], "r");
    yyin = inp_file;

    tree_root = NULL;
    yyparse();
    print_tree(tree_root);
    return 0;
}
