/* A Bison parser, made by GNU Bison 3.7.6.  */

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
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./constants.h"
#include <errno.h>
#include "./syntax_tree.h"
#include "./name_hash.h"
#include "./gen_eey.h"

//int yydebug = 1;
extern FILE* yyin;
extern FILE* yyout;

extern int yylex();
extern int line_id;

Syntax_Tree* tree_root;


void yyerror(char* s){
    fprintf(stderr, "Error at line #%d: %s\n", line_id, s);
    exit(0);
}


#line 98 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    WHILE = 260,                   /* WHILE  */
    CONTINUE = 261,                /* CONTINUE  */
    BREAK = 262,                   /* BREAK  */
    RETURN = 263,                  /* RETURN  */
    INT = 264,                     /* INT  */
    VOID = 265,                    /* VOID  */
    CONST = 266,                   /* CONST  */
    L_PAR = 267,                   /* L_PAR  */
    R_PAR = 268,                   /* R_PAR  */
    L_SBRAC = 269,                 /* L_SBRAC  */
    R_SBRAC = 270,                 /* R_SBRAC  */
    L_CBRAC = 271,                 /* L_CBRAC  */
    R_CBRAC = 272,                 /* R_CBRAC  */
    COMMA = 273,                   /* COMMA  */
    COLON = 274,                   /* COLON  */
    DECIMAL_TOK = 275,             /* DECIMAL_TOK  */
    IDENT = 276,                   /* IDENT  */
    IDENT_FUNC = 277,              /* IDENT_FUNC  */
    NOT_OP1 = 278,                 /* NOT_OP1  */
    MULDIV_OP2 = 279,              /* MULDIV_OP2  */
    ADDMIN_OP3 = 280,              /* ADDMIN_OP3  */
    COMP_OP4 = 281,                /* COMP_OP4  */
    EQUAL_OP5 = 282,               /* EQUAL_OP5  */
    AND_OP6 = 283,                 /* AND_OP6  */
    OR_OP7 = 284,                  /* OR_OP7  */
    ASSIGN_OP8 = 285               /* ASSIGN_OP8  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
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
#define IDENT_FUNC 277
#define NOT_OP1 278
#define MULDIV_OP2 279
#define ADDMIN_OP3 280
#define COMP_OP4 281
#define EQUAL_OP5 282
#define AND_OP6 283
#define OR_OP7 284
#define ASSIGN_OP8 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 29 "parser.y"

	unsigned val;
	char* name;
	struct Syntax_Tree* node;

#line 217 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_WHILE = 5,                      /* WHILE  */
  YYSYMBOL_CONTINUE = 6,                   /* CONTINUE  */
  YYSYMBOL_BREAK = 7,                      /* BREAK  */
  YYSYMBOL_RETURN = 8,                     /* RETURN  */
  YYSYMBOL_INT = 9,                        /* INT  */
  YYSYMBOL_VOID = 10,                      /* VOID  */
  YYSYMBOL_CONST = 11,                     /* CONST  */
  YYSYMBOL_L_PAR = 12,                     /* L_PAR  */
  YYSYMBOL_R_PAR = 13,                     /* R_PAR  */
  YYSYMBOL_L_SBRAC = 14,                   /* L_SBRAC  */
  YYSYMBOL_R_SBRAC = 15,                   /* R_SBRAC  */
  YYSYMBOL_L_CBRAC = 16,                   /* L_CBRAC  */
  YYSYMBOL_R_CBRAC = 17,                   /* R_CBRAC  */
  YYSYMBOL_COMMA = 18,                     /* COMMA  */
  YYSYMBOL_COLON = 19,                     /* COLON  */
  YYSYMBOL_DECIMAL_TOK = 20,               /* DECIMAL_TOK  */
  YYSYMBOL_IDENT = 21,                     /* IDENT  */
  YYSYMBOL_IDENT_FUNC = 22,                /* IDENT_FUNC  */
  YYSYMBOL_NOT_OP1 = 23,                   /* NOT_OP1  */
  YYSYMBOL_MULDIV_OP2 = 24,                /* MULDIV_OP2  */
  YYSYMBOL_ADDMIN_OP3 = 25,                /* ADDMIN_OP3  */
  YYSYMBOL_COMP_OP4 = 26,                  /* COMP_OP4  */
  YYSYMBOL_EQUAL_OP5 = 27,                 /* EQUAL_OP5  */
  YYSYMBOL_AND_OP6 = 28,                   /* AND_OP6  */
  YYSYMBOL_OR_OP7 = 29,                    /* OR_OP7  */
  YYSYMBOL_ASSIGN_OP8 = 30,                /* ASSIGN_OP8  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_COMP_UNIT = 32,                 /* COMP_UNIT  */
  YYSYMBOL_DECL = 33,                      /* DECL  */
  YYSYMBOL_CONST_INDEXES = 34,             /* CONST_INDEXES  */
  YYSYMBOL_VAR_INDEXES = 35,               /* VAR_INDEXES  */
  YYSYMBOL_CONST_DECL = 36,                /* CONST_DECL  */
  YYSYMBOL_CONST_DEFS = 37,                /* CONST_DEFS  */
  YYSYMBOL_CONST_DEF = 38,                 /* CONST_DEF  */
  YYSYMBOL_CONST_INIT_VAL = 39,            /* CONST_INIT_VAL  */
  YYSYMBOL_CONST_INIT_LIST = 40,           /* CONST_INIT_LIST  */
  YYSYMBOL_VAR_DECL = 41,                  /* VAR_DECL  */
  YYSYMBOL_VAR_DEFS = 42,                  /* VAR_DEFS  */
  YYSYMBOL_VAR_DEF = 43,                   /* VAR_DEF  */
  YYSYMBOL_INIT_VAL = 44,                  /* INIT_VAL  */
  YYSYMBOL_INIT_LIST = 45,                 /* INIT_LIST  */
  YYSYMBOL_FUNC_DEF = 46,                  /* FUNC_DEF  */
  YYSYMBOL_FUNC_TYPE = 47,                 /* FUNC_TYPE  */
  YYSYMBOL_FUNC_FPARAMS = 48,              /* FUNC_FPARAMS  */
  YYSYMBOL_FUNC_FPARAM = 49,               /* FUNC_FPARAM  */
  YYSYMBOL_BLOCK = 50,                     /* BLOCK  */
  YYSYMBOL_BLOCK_ITEMS = 51,               /* BLOCK_ITEMS  */
  YYSYMBOL_BLOCK_ITEM = 52,                /* BLOCK_ITEM  */
  YYSYMBOL_STMT = 53,                      /* STMT  */
  YYSYMBOL_CONST_EXP = 54,                 /* CONST_EXP  */
  YYSYMBOL_EXP = 55,                       /* EXP  */
  YYSYMBOL_ADD_EXP = 56,                   /* ADD_EXP  */
  YYSYMBOL_MUL_EXP = 57,                   /* MUL_EXP  */
  YYSYMBOL_UNARY_EXP = 58,                 /* UNARY_EXP  */
  YYSYMBOL_UNARY_OP = 59,                  /* UNARY_OP  */
  YYSYMBOL_FUNC_RPARAMS = 60,              /* FUNC_RPARAMS  */
  YYSYMBOL_PRIMARY_EXP = 61,               /* PRIMARY_EXP  */
  YYSYMBOL_LVAL = 62,                      /* LVAL  */
  YYSYMBOL_REL_EXP = 63,                   /* REL_EXP  */
  YYSYMBOL_EQ_EXP = 64,                    /* EQ_EXP  */
  YYSYMBOL_COND = 65,                      /* COND  */
  YYSYMBOL_LAND_EXP = 66,                  /* LAND_EXP  */
  YYSYMBOL_LOR_EXP = 67,                   /* LOR_EXP  */
  YYSYMBOL_INTEGER = 68,                   /* INTEGER  */
  YYSYMBOL_IDENTIFIER = 69,                /* IDENTIFIER  */
  YYSYMBOL_IDENTIFIER_FUNC = 70            /* IDENTIFIER_FUNC  */
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

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYLAST   207

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    57,    57,    63,    69,    75,    82,    83,    85,    90,
      96,   101,   107,   108,   113,   119,   125,   133,   138,   142,
     147,   152,   158,   160,   165,   171,   177,   184,   189,   196,
     201,   205,   210,   215,   221,   228,   237,   241,   246,   251,
     257,   262,   269,   275,   283,   288,   293,   299,   300,   302,
     306,   312,   317,   322,   328,   335,   341,   345,   349,   353,
     359,   361,   363,   364,   371,   372,   379,   380,   385,   390,
     396,   401,   406,   411,   417,   418,   419,   421,   429,   434,
     435,   442,   443,   450,   452,   453,   460,   461,   468,   477,
     482
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
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "WHILE",
  "CONTINUE", "BREAK", "RETURN", "INT", "VOID", "CONST", "L_PAR", "R_PAR",
  "L_SBRAC", "R_SBRAC", "L_CBRAC", "R_CBRAC", "COMMA", "COLON",
  "DECIMAL_TOK", "IDENT", "IDENT_FUNC", "NOT_OP1", "MULDIV_OP2",
  "ADDMIN_OP3", "COMP_OP4", "EQUAL_OP5", "AND_OP6", "OR_OP7", "ASSIGN_OP8",
  "$accept", "COMP_UNIT", "DECL", "CONST_INDEXES", "VAR_INDEXES",
  "CONST_DECL", "CONST_DEFS", "CONST_DEF", "CONST_INIT_VAL",
  "CONST_INIT_LIST", "VAR_DECL", "VAR_DEFS", "VAR_DEF", "INIT_VAL",
  "INIT_LIST", "FUNC_DEF", "FUNC_TYPE", "FUNC_FPARAMS", "FUNC_FPARAM",
  "BLOCK", "BLOCK_ITEMS", "BLOCK_ITEM", "STMT", "CONST_EXP", "EXP",
  "ADD_EXP", "MUL_EXP", "UNARY_EXP", "UNARY_OP", "FUNC_RPARAMS",
  "PRIMARY_EXP", "LVAL", "REL_EXP", "EQ_EXP", "COND", "LAND_EXP",
  "LOR_EXP", "INTEGER", "IDENTIFIER", "IDENTIFIER_FUNC", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285
};
#endif

#define YYPACT_NINF (-132)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      40,    -7,  -132,    22,    42,    40,  -132,  -132,    40,    24,
    -132,    21,    34,    -3,    -7,  -132,  -132,  -132,  -132,     8,
    -132,    -7,   182,   133,    23,    37,    44,     2,    -7,    49,
      53,    58,  -132,   182,  -132,  -132,  -132,    55,  -132,    54,
      43,  -132,   182,  -132,  -132,  -132,    64,   139,   109,  -132,
    -132,   133,  -132,    -7,   151,    51,    69,    93,  -132,    49,
      76,    73,    75,   182,   182,  -132,   182,  -132,  -132,    74,
      78,  -132,    85,    77,  -132,  -132,   121,  -132,  -132,   151,
     163,  -132,    81,    94,    88,    89,   170,    -7,  -132,  -132,
    -132,   102,    93,  -132,  -132,    80,  -132,  -132,  -132,  -132,
      43,  -132,    96,   182,  -132,   133,  -132,  -132,   104,   106,
    -132,    75,   182,   182,  -132,  -132,  -132,   105,  -132,  -132,
     182,    64,  -132,  -132,   151,  -132,  -132,    54,   101,   108,
     123,   111,   118,   127,  -132,   129,  -132,  -132,   182,   182,
      52,   182,   182,    52,  -132,    54,   101,   146,   108,   111,
    -132,    52,  -132
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    36,    37,     0,     0,     2,     6,     7,     3,     0,
      89,     0,    23,    27,     0,     1,     4,     5,    90,     0,
      22,     0,     0,     0,    28,     0,    13,     0,     0,     0,
       0,    38,    24,     0,    88,    71,    70,     0,    60,    61,
      62,    64,     0,    66,    75,    76,    78,     0,     0,    25,
      29,     0,    12,     0,     0,     0,    40,     0,    34,     0,
       0,     0,     8,     0,     0,    69,     0,    77,    67,    72,
       0,    30,    32,     0,    26,    14,     0,    15,    17,     0,
       0,    42,     0,     0,     0,     0,     0,     0,    49,    47,
      52,     0,    45,    48,    51,    75,    35,    39,    74,     9,
      63,    65,     0,     0,    68,     0,    31,    18,    20,     0,
      16,    41,     0,     0,    57,    56,    58,     0,    44,    46,
       0,    10,    73,    33,     0,    19,    43,    79,    81,    84,
       0,    86,    83,     0,    59,     0,    11,    21,     0,     0,
       0,     0,     0,     0,    50,    80,    82,    53,    85,    87,
      55,     0,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -132,    18,   -53,   -21,    36,  -132,   112,  -132,   -41,    45,
    -132,   145,  -132,   -18,    63,  -132,  -132,   110,  -132,   -22,
      87,  -132,  -131,   -19,   -23,   -94,   114,   -34,  -132,    84,
    -132,   -56,    41,    56,    68,    57,  -132,  -132,     1,   187
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,    24,    67,     6,    25,    26,   108,   109,
       7,    11,    12,    72,    73,     8,     9,    30,    31,    90,
      91,    92,    93,    78,    38,    39,    40,    41,    42,    70,
      43,    44,   128,   129,   130,   131,   132,    45,    46,    47
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      50,    95,    13,    37,    89,    49,    55,    58,    65,   147,
      61,    22,   150,    77,    10,    27,    22,    28,   127,   127,
     152,    29,    13,    16,    69,    50,    17,    23,    50,    56,
     101,    14,    54,    74,    94,    81,    95,    96,   110,    89,
      20,    99,    15,   102,   145,   127,    18,   127,   127,     1,
       2,     3,    21,    51,    27,    82,    52,    83,    84,    85,
      86,    37,    53,   117,    33,    57,    59,    64,    57,    94,
      62,    88,    34,    10,    18,    35,    60,    36,    66,    63,
      69,    79,    50,    80,    95,    28,    98,    95,    13,    22,
     126,   104,   103,   112,   106,    95,    82,   135,    83,    84,
      85,    86,    87,   105,     3,    33,   113,   114,   115,    57,
     120,   121,    88,    34,    10,    18,    35,    94,    36,   118,
      94,    33,   124,   125,   134,    48,    71,   138,    94,    34,
      10,    18,    35,    33,    36,   139,   140,    76,   107,   141,
     143,    34,    10,    18,    35,    33,    36,   142,   144,    48,
     151,    33,    68,    34,    10,    18,    35,   136,    36,    34,
      10,    18,    35,    33,    36,    75,    32,    76,   123,   137,
      97,    34,    10,    18,    35,    33,    36,   100,   111,   119,
     146,   133,    33,    34,    10,    18,    35,   122,    36,   116,
      34,    10,    18,    35,    33,    36,    19,   148,     0,   149,
       0,     0,    34,    10,    18,    35,     0,    36
};

static const yytype_int16 yycheck[] =
{
      23,    57,     1,    22,    57,    23,    27,    29,    42,   140,
      33,    14,   143,    54,    21,    14,    14,     9,   112,   113,
     151,    13,    21,     5,    47,    48,     8,    30,    51,    28,
      64,     9,    30,    51,    57,    56,    92,    59,    79,    92,
      19,    62,     0,    66,   138,   139,    22,   141,   142,     9,
      10,    11,    18,    30,    53,     3,    19,     5,     6,     7,
       8,    80,    18,    86,    12,    16,    13,    24,    16,    92,
      15,    19,    20,    21,    22,    23,    18,    25,    14,    25,
     103,    30,   105,    14,   140,     9,    13,   143,    87,    14,
     111,    13,    18,    12,    17,   151,     3,   120,     5,     6,
       7,     8,     9,    18,    11,    12,    12,    19,    19,    16,
      30,    15,    19,    20,    21,    22,    23,   140,    25,    17,
     143,    12,    18,    17,    19,    16,    17,    26,   151,    20,
      21,    22,    23,    12,    25,    27,    13,    16,    17,    28,
      13,    20,    21,    22,    23,    12,    25,    29,    19,    16,
       4,    12,    13,    20,    21,    22,    23,   121,    25,    20,
      21,    22,    23,    12,    25,    53,    21,    16,   105,   124,
      60,    20,    21,    22,    23,    12,    25,    63,    15,    92,
     139,   113,    12,    20,    21,    22,    23,   103,    25,    19,
      20,    21,    22,    23,    12,    25,     9,   141,    -1,   142,
      -1,    -1,    20,    21,    22,    23,    -1,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    10,    11,    32,    33,    36,    41,    46,    47,
      21,    42,    43,    69,     9,     0,    32,    32,    22,    70,
      19,    18,    14,    30,    34,    37,    38,    69,     9,    13,
      48,    49,    42,    12,    20,    23,    25,    54,    55,    56,
      57,    58,    59,    61,    62,    68,    69,    70,    16,    44,
      55,    30,    19,    18,    30,    34,    69,    16,    50,    13,
      18,    55,    15,    25,    24,    58,    14,    35,    13,    55,
      60,    17,    44,    45,    44,    37,    16,    39,    54,    30,
      14,    34,     3,     5,     6,     7,     8,     9,    19,    33,
      50,    51,    52,    53,    55,    62,    50,    48,    13,    34,
      57,    58,    55,    18,    13,    18,    17,    17,    39,    40,
      39,    15,    12,    12,    19,    19,    19,    55,    17,    51,
      30,    15,    60,    45,    18,    17,    34,    56,    63,    64,
      65,    66,    67,    65,    19,    55,    35,    40,    26,    27,
      13,    28,    29,    13,    19,    56,    63,    53,    64,    66,
      53,     4,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    32,    32,    32,    33,    33,    34,    34,
      35,    35,    36,    37,    37,    38,    38,    39,    39,    39,
      40,    40,    41,    42,    42,    43,    43,    43,    43,    44,
      44,    44,    45,    45,    46,    46,    47,    47,    48,    48,
      49,    49,    49,    49,    50,    51,    51,    52,    52,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      54,    55,    56,    56,    57,    57,    58,    58,    58,    58,
      59,    59,    60,    60,    61,    61,    61,    62,    62,    63,
      63,    64,    64,    65,    66,    66,    67,    67,    68,    69,
      70
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     3,     4,
       3,     4,     4,     1,     3,     3,     4,     1,     2,     3,
       1,     3,     3,     1,     3,     3,     4,     1,     2,     1,
       2,     3,     1,     3,     4,     5,     1,     1,     1,     3,
       2,     4,     3,     5,     3,     1,     2,     1,     1,     1,
       4,     1,     1,     5,     7,     5,     2,     2,     2,     3,
       1,     1,     1,     3,     1,     3,     1,     2,     3,     2,
       1,     1,     1,     3,     3,     1,     1,     2,     1,     1,
       3,     1,     3,     1,     1,     3,     1,     3,     1,     1,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 2: /* COMP_UNIT: DECL  */
#line 58 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_COMP_UNIT, 0, 0, 0, NULL, NULL);
            tree_root = (yyval.node);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1396 "y.tab.c"
    break;

  case 3: /* COMP_UNIT: FUNC_DEF  */
#line 64 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_COMP_UNIT, 0, 0, 0, NULL, NULL);
            tree_root = (yyval.node);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1406 "y.tab.c"
    break;

  case 4: /* COMP_UNIT: DECL COMP_UNIT  */
#line 70 "parser.y"
        {
            (yyval.node) = (yyvsp[0].node);
            tree_root = (yyval.node);
            insert_sons((yyval.node), (yyvsp[-1].node), 0);
        }
#line 1416 "y.tab.c"
    break;

  case 5: /* COMP_UNIT: FUNC_DEF COMP_UNIT  */
#line 76 "parser.y"
        {
            (yyval.node) = (yyvsp[0].node);
            tree_root = (yyval.node);
            insert_sons((yyval.node), (yyvsp[-1].node), 0);
        }
#line 1426 "y.tab.c"
    break;

  case 6: /* DECL: CONST_DECL  */
#line 82 "parser.y"
                       {(yyval.node) = (yyvsp[0].node);}
#line 1432 "y.tab.c"
    break;

  case 7: /* DECL: VAR_DECL  */
#line 83 "parser.y"
                       {(yyval.node) = (yyvsp[0].node);}
#line 1438 "y.tab.c"
    break;

  case 8: /* CONST_INDEXES: L_SBRAC CONST_EXP R_SBRAC  */
#line 86 "parser.y"
        {
            (yyval.node) = new_node(CONST_REST, TP_INDEXES, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[-1].node), 0);
        }
#line 1447 "y.tab.c"
    break;

  case 9: /* CONST_INDEXES: L_SBRAC CONST_EXP R_SBRAC CONST_INDEXES  */
#line 91 "parser.y"
        {
            (yyval.node) = (yyvsp[0].node);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1456 "y.tab.c"
    break;

  case 10: /* VAR_INDEXES: L_SBRAC EXP R_SBRAC  */
#line 97 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_INDEXES, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[-1].node), 0);
        }
#line 1465 "y.tab.c"
    break;

  case 11: /* VAR_INDEXES: L_SBRAC EXP R_SBRAC VAR_INDEXES  */
#line 102 "parser.y"
        {
            (yyval.node) = (yyvsp[0].node);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1474 "y.tab.c"
    break;

  case 12: /* CONST_DECL: CONST INT CONST_DEFS COLON  */
#line 107 "parser.y"
                                        {(yyval.node) = (yyvsp[-1].node);}
#line 1480 "y.tab.c"
    break;

  case 13: /* CONST_DEFS: CONST_DEF  */
#line 109 "parser.y"
        {
            (yyval.node) = new_node(CONST_REST, TP_DECL, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1489 "y.tab.c"
    break;

  case 14: /* CONST_DEFS: CONST_DEF COMMA CONST_DEFS  */
#line 114 "parser.y"
        {
            (yyval.node) = (yyvsp[0].node);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1498 "y.tab.c"
    break;

  case 15: /* CONST_DEF: IDENTIFIER ASSIGN_OP8 CONST_INIT_VAL  */
#line 120 "parser.y"
        {
            (yyval.node) = new_node(CONST_REST, TP_DEF, 1, 0, 0, NULL, (yyvsp[-1].name));
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1508 "y.tab.c"
    break;

  case 16: /* CONST_DEF: IDENTIFIER CONST_INDEXES ASSIGN_OP8 CONST_INIT_VAL  */
#line 126 "parser.y"
        {
            (yyval.node) = new_node(CONST_REST, TP_DEF, 3, 0, 0, NULL, (yyvsp[-1].name));
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
            insert_sons((yyval.node), (yyvsp[-3].node), 0);
        }
#line 1519 "y.tab.c"
    break;

  case 17: /* CONST_INIT_VAL: CONST_EXP  */
#line 134 "parser.y"
        {
            (yyval.node) = new_node(CONST_REST, TP_INIT_VAL, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1528 "y.tab.c"
    break;

  case 18: /* CONST_INIT_VAL: L_CBRAC R_CBRAC  */
#line 139 "parser.y"
        {
            (yyval.node) = new_node(CONST_REST, TP_INIT_VAL, 1, 0, 0, NULL, NULL);
        }
#line 1536 "y.tab.c"
    break;

  case 19: /* CONST_INIT_VAL: L_CBRAC CONST_INIT_LIST R_CBRAC  */
#line 143 "parser.y"
        {
            (yyval.node) = (yyvsp[-1].node);
        }
#line 1544 "y.tab.c"
    break;

  case 20: /* CONST_INIT_LIST: CONST_INIT_VAL  */
#line 148 "parser.y"
        {
            (yyval.node) = new_node(CONST_REST, TP_INIT_VAL, 1, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1553 "y.tab.c"
    break;

  case 21: /* CONST_INIT_LIST: CONST_INIT_VAL COMMA CONST_INIT_LIST  */
#line 153 "parser.y"
        {
            (yyval.node) = (yyvsp[0].node);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1562 "y.tab.c"
    break;

  case 22: /* VAR_DECL: INT VAR_DEFS COLON  */
#line 158 "parser.y"
                             {(yyval.node) = (yyvsp[-1].node);}
#line 1568 "y.tab.c"
    break;

  case 23: /* VAR_DEFS: VAR_DEF  */
#line 161 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_DECL, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1577 "y.tab.c"
    break;

  case 24: /* VAR_DEFS: VAR_DEF COMMA VAR_DEFS  */
#line 166 "parser.y"
        {
            (yyval.node) = (yyvsp[0].node);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1586 "y.tab.c"
    break;

  case 25: /* VAR_DEF: IDENTIFIER ASSIGN_OP8 INIT_VAL  */
#line 172 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_DEF, 1, 0, 0, NULL, (yyvsp[-1].name));
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1596 "y.tab.c"
    break;

  case 26: /* VAR_DEF: IDENTIFIER CONST_INDEXES ASSIGN_OP8 INIT_VAL  */
#line 178 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_DEF, 3, 0, 0, NULL, (yyvsp[-1].name));
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
            insert_sons((yyval.node), (yyvsp[-3].node), 0);
        }
#line 1607 "y.tab.c"
    break;

  case 27: /* VAR_DEF: IDENTIFIER  */
#line 185 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_DEF, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1616 "y.tab.c"
    break;

  case 28: /* VAR_DEF: IDENTIFIER CONST_INDEXES  */
#line 190 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_DEF, 2, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-1].node), 0);
        }
#line 1626 "y.tab.c"
    break;

  case 29: /* INIT_VAL: EXP  */
#line 197 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_INIT_VAL, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1635 "y.tab.c"
    break;

  case 30: /* INIT_VAL: L_CBRAC R_CBRAC  */
#line 202 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_INIT_VAL, 1, 0, 0, NULL, NULL);
        }
#line 1643 "y.tab.c"
    break;

  case 31: /* INIT_VAL: L_CBRAC INIT_LIST R_CBRAC  */
#line 206 "parser.y"
        {
            (yyval.node) = (yyvsp[-1].node);
        }
#line 1651 "y.tab.c"
    break;

  case 32: /* INIT_LIST: INIT_VAL  */
#line 211 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_INIT_VAL, 1, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1660 "y.tab.c"
    break;

  case 33: /* INIT_LIST: INIT_VAL COMMA INIT_LIST  */
#line 216 "parser.y"
        {
            (yyval.node) = (yyvsp[0].node);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1669 "y.tab.c"
    break;

  case 34: /* FUNC_DEF: FUNC_TYPE IDENTIFIER_FUNC R_PAR BLOCK  */
#line 222 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_FUNC_DEF, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
            insert_sons((yyval.node), (yyvsp[-3].node), 0);
        }
#line 1680 "y.tab.c"
    break;

  case 35: /* FUNC_DEF: FUNC_TYPE IDENTIFIER_FUNC FUNC_FPARAMS R_PAR BLOCK  */
#line 229 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_FUNC_DEF, 1, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
            insert_sons((yyval.node), (yyvsp[-3].node), 0);
            insert_sons((yyval.node), (yyvsp[-4].node), 0);
        }
#line 1692 "y.tab.c"
    break;

  case 36: /* FUNC_TYPE: INT  */
#line 238 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_TOKEN, 0, TOK_INT, 0, NULL, NULL);
        }
#line 1700 "y.tab.c"
    break;

  case 37: /* FUNC_TYPE: VOID  */
#line 242 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_TOKEN, 0, TOK_VOID, 0, NULL, NULL);
        }
#line 1708 "y.tab.c"
    break;

  case 38: /* FUNC_FPARAMS: FUNC_FPARAM  */
#line 247 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_FUNC_FPARAM, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1717 "y.tab.c"
    break;

  case 39: /* FUNC_FPARAMS: FUNC_FPARAM COMMA FUNC_FPARAMS  */
#line 252 "parser.y"
        {
            (yyval.node) = (yyvsp[0].node);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1726 "y.tab.c"
    break;

  case 40: /* FUNC_FPARAM: INT IDENTIFIER  */
#line 258 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_DEF, 4, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1735 "y.tab.c"
    break;

  case 41: /* FUNC_FPARAM: INT IDENTIFIER L_SBRAC R_SBRAC  */
#line 263 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_DEF, 6, 0, 0, NULL, NULL);
            Syntax_Tree* tmp_node = new_node(NONCONST_REST, TP_INDEXES, 1, 0, 0, NULL, NULL);
            insert_sons((yyval.node), tmp_node, 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1746 "y.tab.c"
    break;

  case 42: /* FUNC_FPARAM: INT IDENTIFIER CONST_INDEXES  */
#line 270 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_DEF, 6, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-1].node), 0);
        }
#line 1756 "y.tab.c"
    break;

  case 43: /* FUNC_FPARAM: INT IDENTIFIER L_SBRAC R_SBRAC CONST_INDEXES  */
#line 276 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_DEF, 6, 0, 0, NULL, NULL);
            (yyvsp[0].node)->option = 1;
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-3].node), 0);
        }
#line 1767 "y.tab.c"
    break;

  case 44: /* BLOCK: L_CBRAC BLOCK_ITEMS R_CBRAC  */
#line 284 "parser.y"
        {
            (yyval.node) = (yyvsp[-1].node);
        }
#line 1775 "y.tab.c"
    break;

  case 45: /* BLOCK_ITEMS: BLOCK_ITEM  */
#line 289 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_BLOCK, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1784 "y.tab.c"
    break;

  case 46: /* BLOCK_ITEMS: BLOCK_ITEM BLOCK_ITEMS  */
#line 294 "parser.y"
        {
            (yyval.node) = (yyvsp[0].node);
            insert_sons((yyval.node), (yyvsp[-1].node), 0);
        }
#line 1793 "y.tab.c"
    break;

  case 47: /* BLOCK_ITEM: DECL  */
#line 299 "parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 1799 "y.tab.c"
    break;

  case 48: /* BLOCK_ITEM: STMT  */
#line 300 "parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 1805 "y.tab.c"
    break;

  case 49: /* STMT: COLON  */
#line 303 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_TOKEN, 0, TOK_NONE, 0, NULL, NULL);
        }
#line 1813 "y.tab.c"
    break;

  case 50: /* STMT: LVAL ASSIGN_OP8 EXP COLON  */
#line 307 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_STMT, 0, 0, 0, NULL, (yyvsp[-2].name));
            insert_sons((yyval.node), (yyvsp[-1].node), 0);
            insert_sons((yyval.node), (yyvsp[-3].node), 0);
        }
#line 1823 "y.tab.c"
    break;

  case 51: /* STMT: EXP  */
#line 313 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_STMT, 1, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1832 "y.tab.c"
    break;

  case 52: /* STMT: BLOCK  */
#line 318 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_STMT, 2, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1841 "y.tab.c"
    break;

  case 53: /* STMT: IF L_PAR COND R_PAR STMT  */
#line 323 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_STMT, 3, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1851 "y.tab.c"
    break;

  case 54: /* STMT: IF L_PAR COND R_PAR STMT ELSE STMT  */
#line 329 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_STMT, 4, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
            insert_sons((yyval.node), (yyvsp[-4].node), 0);
        }
#line 1862 "y.tab.c"
    break;

  case 55: /* STMT: WHILE L_PAR COND R_PAR STMT  */
#line 336 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_STMT, 5, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1872 "y.tab.c"
    break;

  case 56: /* STMT: BREAK COLON  */
#line 342 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_STMT, 6, 0, 0, NULL, NULL);
        }
#line 1880 "y.tab.c"
    break;

  case 57: /* STMT: CONTINUE COLON  */
#line 346 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_STMT, 7, 0, 0, NULL, NULL);
        }
#line 1888 "y.tab.c"
    break;

  case 58: /* STMT: RETURN COLON  */
#line 350 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_STMT, 8, 0, 0, NULL, NULL);
        }
#line 1896 "y.tab.c"
    break;

  case 59: /* STMT: RETURN EXP COLON  */
#line 354 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_STMT, 9, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[-1].node), 0);
        }
#line 1905 "y.tab.c"
    break;

  case 60: /* CONST_EXP: EXP  */
#line 359 "parser.y"
               {(yyval.node) = (yyvsp[0].node);}
#line 1911 "y.tab.c"
    break;

  case 61: /* EXP: ADD_EXP  */
#line 361 "parser.y"
                  {(yyval.node) = (yyvsp[0].node);}
#line 1917 "y.tab.c"
    break;

  case 62: /* ADD_EXP: MUL_EXP  */
#line 363 "parser.y"
                   {(yyval.node) = (yyvsp[0].node);}
#line 1923 "y.tab.c"
    break;

  case 63: /* ADD_EXP: ADD_EXP ADDMIN_OP3 MUL_EXP  */
#line 365 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_BINARY_EXP, 0, 0, 0, NULL, (yyvsp[-1].name));
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1933 "y.tab.c"
    break;

  case 64: /* MUL_EXP: UNARY_EXP  */
#line 371 "parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 1939 "y.tab.c"
    break;

  case 65: /* MUL_EXP: MUL_EXP MULDIV_OP2 UNARY_EXP  */
#line 373 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_BINARY_EXP, 0, 0, 0, NULL, (yyvsp[-1].name));
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1949 "y.tab.c"
    break;

  case 66: /* UNARY_EXP: PRIMARY_EXP  */
#line 379 "parser.y"
                       {(yyval.node) = (yyvsp[0].node);}
#line 1955 "y.tab.c"
    break;

  case 67: /* UNARY_EXP: IDENTIFIER_FUNC R_PAR  */
#line 381 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_FUNC_CALL, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[-1].node), 0);
        }
#line 1964 "y.tab.c"
    break;

  case 68: /* UNARY_EXP: IDENTIFIER_FUNC FUNC_RPARAMS R_PAR  */
#line 386 "parser.y"
        {
            (yyval.node) = (yyvsp[-1].node);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1973 "y.tab.c"
    break;

  case 69: /* UNARY_EXP: UNARY_OP UNARY_EXP  */
#line 391 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_UNARY_EXP, 0, 0, 0, NULL, (yyvsp[-1].node)->op_name);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1982 "y.tab.c"
    break;

  case 70: /* UNARY_OP: ADDMIN_OP3  */
#line 397 "parser.y"
        {
            // tmp
            (yyval.node) = new_node(0, 0, 0, 0, 0, NULL, (yyvsp[0].name));
        }
#line 1991 "y.tab.c"
    break;

  case 71: /* UNARY_OP: NOT_OP1  */
#line 402 "parser.y"
        {
            (yyval.node) = new_node(0, 0, 0, 0, 0, NULL, (yyvsp[0].name));
        }
#line 1999 "y.tab.c"
    break;

  case 72: /* FUNC_RPARAMS: EXP  */
#line 407 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_FUNC_CALL, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 2008 "y.tab.c"
    break;

  case 73: /* FUNC_RPARAMS: EXP COMMA FUNC_RPARAMS  */
#line 412 "parser.y"
        {
            (yyval.node) = (yyvsp[0].node);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 2017 "y.tab.c"
    break;

  case 74: /* PRIMARY_EXP: L_PAR EXP R_PAR  */
#line 417 "parser.y"
                             {(yyval.node) = (yyvsp[-1].node);}
#line 2023 "y.tab.c"
    break;

  case 75: /* PRIMARY_EXP: LVAL  */
#line 418 "parser.y"
                             {(yyval.node) = (yyvsp[0].node);}
#line 2029 "y.tab.c"
    break;

  case 76: /* PRIMARY_EXP: INTEGER  */
#line 419 "parser.y"
                             {(yyval.node) = (yyvsp[0].node);}
#line 2035 "y.tab.c"
    break;

  case 77: /* LVAL: IDENTIFIER VAR_INDEXES  */
#line 422 "parser.y"
        {
            // option #2: indexing
            (yyval.node) = new_node(NONCONST_REST, TP_UNARY_EXP, 1, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-1].node), 0);
        }
#line 2046 "y.tab.c"
    break;

  case 78: /* LVAL: IDENTIFIER  */
#line 430 "parser.y"
        {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2054 "y.tab.c"
    break;

  case 79: /* REL_EXP: ADD_EXP  */
#line 434 "parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 2060 "y.tab.c"
    break;

  case 80: /* REL_EXP: REL_EXP COMP_OP4 ADD_EXP  */
#line 436 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_BINARY_EXP, 0, 0, 0, NULL, (yyvsp[-1].name));
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 2070 "y.tab.c"
    break;

  case 81: /* EQ_EXP: REL_EXP  */
#line 442 "parser.y"
                       {(yyval.node) = (yyvsp[0].node);}
#line 2076 "y.tab.c"
    break;

  case 82: /* EQ_EXP: EQ_EXP EQUAL_OP5 REL_EXP  */
#line 444 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_BINARY_EXP, 0, 0, 0, NULL, (yyvsp[-1].name));
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 2086 "y.tab.c"
    break;

  case 83: /* COND: LOR_EXP  */
#line 450 "parser.y"
              {(yyval.node) = (yyvsp[0].node);}
#line 2092 "y.tab.c"
    break;

  case 84: /* LAND_EXP: EQ_EXP  */
#line 452 "parser.y"
                   {(yyval.node) = (yyvsp[0].node);}
#line 2098 "y.tab.c"
    break;

  case 85: /* LAND_EXP: LAND_EXP AND_OP6 EQ_EXP  */
#line 454 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_BINARY_EXP, 0, 0, 0, NULL, (yyvsp[-1].name));
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 2108 "y.tab.c"
    break;

  case 86: /* LOR_EXP: LAND_EXP  */
#line 460 "parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 2114 "y.tab.c"
    break;

  case 87: /* LOR_EXP: LOR_EXP OR_OP7 LAND_EXP  */
#line 462 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_BINARY_EXP, 0, 0, 0, NULL, (yyvsp[-1].name));
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 2124 "y.tab.c"
    break;

  case 88: /* INTEGER: DECIMAL_TOK  */
#line 469 "parser.y"
        {
            if ((yyvsp[0].val) == 444){
                (yyvsp[0].val)++;
                (yyvsp[0].val)--;
            }
            (yyval.node) = new_node(NONCONST_REST, TP_TOKEN, 0, TOK_DEC, (yyvsp[0].val), NULL, NULL);
        }
#line 2136 "y.tab.c"
    break;

  case 89: /* IDENTIFIER: IDENT  */
#line 478 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_TOKEN, 0, TOK_IDENT, 0, (yyvsp[0].name), NULL);
        }
#line 2144 "y.tab.c"
    break;

  case 90: /* IDENTIFIER_FUNC: IDENT_FUNC  */
#line 483 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_TOKEN, 0, TOK_IDENT, 0, (yyvsp[0].name), NULL);
        }
#line 2152 "y.tab.c"
    break;


#line 2156 "y.tab.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 488 "parser.y"


int main(int argc, char* argv[]){
    if (argc != 3){
        printf("Usage: ./parser INPUT_SYSY_FILE OUTPUT_EEYORE_FILE\n");
        return 0;
    }
    FILE* inp_file = fopen(argv[1], "r");
    FILE* oup_file = fopen(argv[2], "w");
    printf("%s\n", argv[1]);
    yyin = inp_file;

    tree_root = NULL;
    yyparse();
    //print_tree(tree_root);

    generate_eeyore(tree_root, oup_file);

    destruct_tree_completely(tree_root);
    
    return 0;
}
