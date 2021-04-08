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


extern int line_no;

syntax_tree* tree_root;

void yyerror(const char* s){
    fprintf(stderr, "Error at line #%d: %s\n", line_no, s);
    exit(0);
}


#line 92 "parser.tab.c"

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
    NOT_OP1 = 277,                 /* NOT_OP1  */
    MULDIV_OP2 = 278,              /* MULDIV_OP2  */
    ADDMIN_OP3 = 279,              /* ADDMIN_OP3  */
    COMP_OP4 = 280,                /* COMP_OP4  */
    EQUAL_OP5 = 281,               /* EQUAL_OP5  */
    AND_OP6 = 282,                 /* AND_OP6  */
    OR_OP7 = 283,                  /* OR_OP7  */
    ASSIGN_OP8 = 284               /* ASSIGN_OP8  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);


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
  YYSYMBOL_NOT_OP1 = 22,                   /* NOT_OP1  */
  YYSYMBOL_MULDIV_OP2 = 23,                /* MULDIV_OP2  */
  YYSYMBOL_ADDMIN_OP3 = 24,                /* ADDMIN_OP3  */
  YYSYMBOL_COMP_OP4 = 25,                  /* COMP_OP4  */
  YYSYMBOL_EQUAL_OP5 = 26,                 /* EQUAL_OP5  */
  YYSYMBOL_AND_OP6 = 27,                   /* AND_OP6  */
  YYSYMBOL_OR_OP7 = 28,                    /* OR_OP7  */
  YYSYMBOL_ASSIGN_OP8 = 29,                /* ASSIGN_OP8  */
  YYSYMBOL_YYACCEPT = 30,                  /* $accept  */
  YYSYMBOL_COMP_UNIT = 31,                 /* COMP_UNIT  */
  YYSYMBOL_DECL = 32,                      /* DECL  */
  YYSYMBOL_CONST_INDEXES = 33,             /* CONST_INDEXES  */
  YYSYMBOL_VAR_INDEXES = 34,               /* VAR_INDEXES  */
  YYSYMBOL_CONST_DECL = 35,                /* CONST_DECL  */
  YYSYMBOL_CONST_DEFS = 36,                /* CONST_DEFS  */
  YYSYMBOL_CONST_DEF = 37,                 /* CONST_DEF  */
  YYSYMBOL_CONST_INIT_VAL = 38,            /* CONST_INIT_VAL  */
  YYSYMBOL_CONST_INIT_LIST = 39,           /* CONST_INIT_LIST  */
  YYSYMBOL_VAR_DECL = 40,                  /* VAR_DECL  */
  YYSYMBOL_VAR_DEFS = 41,                  /* VAR_DEFS  */
  YYSYMBOL_VAR_DEF = 42,                   /* VAR_DEF  */
  YYSYMBOL_INIT_VAL = 43,                  /* INIT_VAL  */
  YYSYMBOL_INIT_LIST = 44,                 /* INIT_LIST  */
  YYSYMBOL_FUNC_DEF = 45,                  /* FUNC_DEF  */
  YYSYMBOL_FUNC_TYPE = 46,                 /* FUNC_TYPE  */
  YYSYMBOL_FUNC_FPARAMS = 47,              /* FUNC_FPARAMS  */
  YYSYMBOL_FUNC_FPARAM = 48,               /* FUNC_FPARAM  */
  YYSYMBOL_BLOCK = 49,                     /* BLOCK  */
  YYSYMBOL_BLOCK_ITEMS = 50,               /* BLOCK_ITEMS  */
  YYSYMBOL_BLOCK_ITEM = 51,                /* BLOCK_ITEM  */
  YYSYMBOL_STMT = 52,                      /* STMT  */
  YYSYMBOL_CONST_EXP = 53,                 /* CONST_EXP  */
  YYSYMBOL_EXP = 54,                       /* EXP  */
  YYSYMBOL_ADD_EXP = 55,                   /* ADD_EXP  */
  YYSYMBOL_MUL_EXP = 56,                   /* MUL_EXP  */
  YYSYMBOL_UNARY_EXP = 57,                 /* UNARY_EXP  */
  YYSYMBOL_UNARY_OP = 58,                  /* UNARY_OP  */
  YYSYMBOL_FUNC_RPARAMS = 59,              /* FUNC_RPARAMS  */
  YYSYMBOL_PRIMARY_EXP = 60,               /* PRIMARY_EXP  */
  YYSYMBOL_LVAL = 61,                      /* LVAL  */
  YYSYMBOL_REL_EXP = 62,                   /* REL_EXP  */
  YYSYMBOL_EQ_EXP = 63,                    /* EQ_EXP  */
  YYSYMBOL_COND = 64,                      /* COND  */
  YYSYMBOL_LAND_EXP = 65,                  /* LAND_EXP  */
  YYSYMBOL_LOR_EXP = 66,                   /* LOR_EXP  */
  YYSYMBOL_INTEGER = 67,                   /* INTEGER  */
  YYSYMBOL_IDENTIFIER = 68                 /* IDENTIFIER  */
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
#define YYLAST   197

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


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
      25,    26,    27,    28,    29
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
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
  "DECIMAL_TOK", "IDENT", "NOT_OP1", "MULDIV_OP2", "ADDMIN_OP3",
  "COMP_OP4", "EQUAL_OP5", "AND_OP6", "OR_OP7", "ASSIGN_OP8", "$accept",
  "COMP_UNIT", "DECL", "CONST_INDEXES", "VAR_INDEXES", "CONST_DECL",
  "CONST_DEFS", "CONST_DEF", "CONST_INIT_VAL", "CONST_INIT_LIST",
  "VAR_DECL", "VAR_DEFS", "VAR_DEF", "INIT_VAL", "INIT_LIST", "FUNC_DEF",
  "FUNC_TYPE", "FUNC_FPARAMS", "FUNC_FPARAM", "BLOCK", "BLOCK_ITEMS",
  "BLOCK_ITEM", "STMT", "CONST_EXP", "EXP", "ADD_EXP", "MUL_EXP",
  "UNARY_EXP", "UNARY_OP", "FUNC_RPARAMS", "PRIMARY_EXP", "LVAL",
  "REL_EXP", "EQ_EXP", "COND", "LAND_EXP", "LOR_EXP", "INTEGER",
  "IDENTIFIER", YY_NULLPTR
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
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284
};
#endif

#define YYPACT_NINF (-99)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
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
static const yytype_int8 yydefact[] =
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
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,    23,    62,     6,    24,    25,    88,    89,
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
static const yytype_int8 yystos[] =
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
static const yytype_int8 yyr1[] =
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
static const yytype_int8 yyr2[] =
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
#line 45 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_COMP_UNIT, 0, 0, 0, NULL, NULL);
            tree_root = (yyval.node);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1329 "parser.tab.c"
    break;

  case 3: /* COMP_UNIT: FUNC_DEF  */
#line 51 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_COMP_UNIT, 0, 0, 0, NULL, NULL);
            tree_root = (yyval.node);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1339 "parser.tab.c"
    break;

  case 4: /* COMP_UNIT: DECL COMP_UNIT  */
#line 57 "parser.y"
        {
            (yyval.node) = (yyvsp[0].node);
            tree_root = (yyval.node);
            insert_sons((yyval.node), (yyvsp[-1].node), 0);
        }
#line 1349 "parser.tab.c"
    break;

  case 5: /* COMP_UNIT: FUNC_DEF COMP_UNIT  */
#line 63 "parser.y"
        {
            (yyval.node) = (yyvsp[0].node);
            tree_root = (yyval.node);
            insert_sons((yyval.node), (yyvsp[-1].node), 0);
        }
#line 1359 "parser.tab.c"
    break;

  case 6: /* DECL: CONST_DECL  */
#line 69 "parser.y"
                       {(yyval.node) = (yyvsp[0].node)}
#line 1365 "parser.tab.c"
    break;

  case 7: /* DECL: VAR_DECL  */
#line 70 "parser.y"
                       {(yyval.node) = (yyvsp[0].node)}
#line 1371 "parser.tab.c"
    break;

  case 8: /* CONST_INDEXES: L_SBRAC CONST_EXP R_SBRAC  */
#line 73 "parser.y"
        {
            (yyval.node) = new_node(CONST_REST, TP_INDEXES, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[-1].node), 0);
        }
#line 1380 "parser.tab.c"
    break;

  case 9: /* CONST_INDEXES: L_SBRAC CONST_EXP R_SBRAC CONST_INDEXES  */
#line 78 "parser.y"
        {
            (yyval.node) = (yyvsp[0].node);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1389 "parser.tab.c"
    break;

  case 10: /* VAR_INDEXES: L_SBRAC EXP R_SBRAC  */
#line 84 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_INDEXES, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[-1].node), 0);
        }
#line 1398 "parser.tab.c"
    break;

  case 11: /* VAR_INDEXES: L_SBRAC EXP R_SBRAC VAR_INDEXES  */
#line 89 "parser.y"
        {
            (yyval.node) = (yyvsp[0].node);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1407 "parser.tab.c"
    break;

  case 12: /* CONST_DECL: CONST INT CONST_DEFS COLON  */
#line 94 "parser.y"
                                        {(yyval.node) = (yyvsp[-1].node);}
#line 1413 "parser.tab.c"
    break;

  case 13: /* CONST_DEFS: CONST_DEF  */
#line 96 "parser.y"
        {
            (yyval.node) = new_node(CONST_REST, TP_DECL, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1422 "parser.tab.c"
    break;

  case 14: /* CONST_DEFS: CONST_DEF COMMA CONST_DEFS  */
#line 101 "parser.y"
        {
            (yyval.node) = (yyvsp[0].node);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1431 "parser.tab.c"
    break;

  case 15: /* CONST_DEF: IDENTIFIER ASSIGN_OP8 CONST_INIT_VAL  */
#line 107 "parser.y"
        {
            (yyval.node) = new_node(CONST_REST, TP_DEF, 1, 0, 0, NULL, (yyvsp[-1].name));
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-1].name), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1442 "parser.tab.c"
    break;

  case 16: /* CONST_DEF: IDENTIFIER CONST_INDEXES ASSIGN_OP8 CONST_INIT_VAL  */
#line 114 "parser.y"
        {
            (yyval.node) = new_node(CONST_REST, TP_DEF, 3, 0, 0, NULL, (yyvsp[-1].name));
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-1].name), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
            insert_sons((yyval.node), (yyvsp[-3].node), 0);
        }
#line 1454 "parser.tab.c"
    break;

  case 17: /* CONST_INIT_VAL: CONST_EXP  */
#line 123 "parser.y"
        {
            (yyval.node) = new_node(CONST_REST, TP_INIT_VAL, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1463 "parser.tab.c"
    break;

  case 18: /* CONST_INIT_VAL: L_CBRAC R_CBRAC  */
#line 128 "parser.y"
        {
            (yyval.node) = new_node(CONST_REST, TP_INIT_VAL, 1, 0, 0, NULL, NULL);
        }
#line 1471 "parser.tab.c"
    break;

  case 19: /* CONST_INIT_VAL: L_CBRAC CONST_INIT_LIST R_CBRAC  */
#line 132 "parser.y"
        {
            (yyval.node) = (yyvsp[-1].node);
        }
#line 1479 "parser.tab.c"
    break;

  case 20: /* CONST_INIT_LIST: CONST_INIT_VAL  */
#line 137 "parser.y"
        {
            (yyval.node) = new_node(CONST_REST, TP_INIT_VAL, 1, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1488 "parser.tab.c"
    break;

  case 21: /* CONST_INIT_LIST: CONST_INIT_VAL COMMA CONST_INIT_LIST  */
#line 142 "parser.y"
        {
            (yyval.node) = (yyvsp[0].node);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1497 "parser.tab.c"
    break;

  case 22: /* VAR_DECL: INT VAR_DEFS COLON  */
#line 147 "parser.y"
                             {(yyval.node) = (yyvsp[-1].node);}
#line 1503 "parser.tab.c"
    break;

  case 23: /* VAR_DEFS: VAR_DEF  */
#line 150 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_DECL, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1512 "parser.tab.c"
    break;

  case 24: /* VAR_DEFS: VAR_DEF COMMA VAR_DEFS  */
#line 155 "parser.y"
        {
            (yyval.node) = (yyvsp[0].node);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1521 "parser.tab.c"
    break;

  case 25: /* VAR_DEF: IDENTIFIER ASSIGN_OP8 INIT_VAL  */
#line 161 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_DEF, 1, 0, 0, NULL, (yyvsp[-1].name));
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-1].name), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1532 "parser.tab.c"
    break;

  case 26: /* VAR_DEF: IDENTIFIER CONST_INDEXES ASSIGN_OP8 INIT_VAL  */
#line 168 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_DEF, 3, 0, 0, NULL, (yyvsp[-1].name));
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-1].name), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
            insert_sons((yyval.node), (yyvsp[-3].node), 0);
        }
#line 1544 "parser.tab.c"
    break;

  case 27: /* VAR_DEF: IDENTIFIER  */
#line 176 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_DEF, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1553 "parser.tab.c"
    break;

  case 28: /* VAR_DEF: IDENTIFIER CONST_INDEXES  */
#line 181 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_DEF, 2, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-1].node), 0);
        }
#line 1563 "parser.tab.c"
    break;

  case 29: /* INIT_VAL: EXP  */
#line 188 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_INIT_VAL, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1572 "parser.tab.c"
    break;

  case 30: /* INIT_VAL: L_CBRAC R_CBRAC  */
#line 193 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_INIT_VAL, 1, 0, 0, NULL, NULL);
        }
#line 1580 "parser.tab.c"
    break;

  case 31: /* INIT_VAL: L_CBRAC INIT_LIST R_CBRAC  */
#line 197 "parser.y"
        {
            (yyval.node) = (yyvsp[-1].node);
        }
#line 1588 "parser.tab.c"
    break;

  case 32: /* INIT_LIST: INIT_VAL  */
#line 202 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_INIT_VAL, 1, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1597 "parser.tab.c"
    break;

  case 33: /* INIT_LIST: INIT_VAL COMMA INIT_LIST  */
#line 207 "parser.y"
        {
            (yyval.node) = (yyvsp[0].node);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1606 "parser.tab.c"
    break;

  case 34: /* FUNC_DEF: FUNC_TYPE IDENTIFIER L_PAR R_PAR BLOCK  */
#line 213 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_FUNC_DEF, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-3].node), 0);
            insert_sons((yyval.node), (yyvsp[-4].node), 0);
        }
#line 1617 "parser.tab.c"
    break;

  case 35: /* FUNC_DEF: FUNC_TYPE IDENTIFIER L_PAR FUNC_FPARAMS R_PAR BLOCK  */
#line 220 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_FUNC_DEF, 1, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
            insert_sons((yyval.node), (yyvsp[-4].node), 0);
            insert_sons((yyval.node), (yyvsp[-5].node), 0);
        }
#line 1629 "parser.tab.c"
    break;

  case 36: /* FUNC_TYPE: INT  */
#line 229 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_TOKEN, 0, TOK_INT, 0, NULL, NULL);
        }
#line 1637 "parser.tab.c"
    break;

  case 37: /* FUNC_TYPE: VOID  */
#line 233 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_TOKEN, 0, TOK_VOID, 0, NULL, NULL);
        }
#line 1645 "parser.tab.c"
    break;

  case 38: /* FUNC_FPARAMS: FUNC_FPARAM  */
#line 238 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_FUNC_FPRAM, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1654 "parser.tab.c"
    break;

  case 39: /* FUNC_FPARAMS: FUNC_FPARAM COMMA FUNC_FPARAMS  */
#line 243 "parser.y"
        {
            (yyval.node) = (yyvsp[-1].name);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1663 "parser.tab.c"
    break;

  case 40: /* FUNC_FPARAM: INT IDENTIFIER  */
#line 249 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_DEF, 0, 0, 0, NULL, NULL);
            insert((yyval.node), (yyvsp[0].node), 0);
        }
#line 1672 "parser.tab.c"
    break;

  case 41: /* FUNC_FPARAM: INT IDENTIFIER L_SBRAC R_SBRAC  */
#line 254 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_DEF, 2, 0, 0, NULL, NULL);
            syntax_tree* tmp_node = new_node(NONCONST_REST, TP_INDEXES, 1, 0, 0, NULL, NULL);
            insert((yyval.node), tmp_node, 0);
            insert((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1683 "parser.tab.c"
    break;

  case 42: /* FUNC_FPARAM: INT IDENTIFIER CONST_INDEXES  */
#line 261 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_DEF, 2, 0, 0, NULL, NULL);
            insert((yyval.node), (yyvsp[0].node), 0);
            insert((yyval.node), (yyvsp[-1].node), 0);
        }
#line 1693 "parser.tab.c"
    break;

  case 43: /* FUNC_FPARAM: INT IDENTIFIER L_SBRAC R_SBRAC CONST_INDEXES  */
#line 267 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_DEF, 2, 0, 0, NULL, NULL);
            (yyvsp[-2].name)->option = 1;
            insert((yyval.node), (yyvsp[-2].name), 0);
            insert((yyval.node), (yyvsp[-3].node), 0);
        }
#line 1704 "parser.tab.c"
    break;

  case 44: /* BLOCK: L_CBRAC BLOCK_ITEMS R_CBRAC  */
#line 275 "parser.y"
        {
            (yyval.node) = (yyvsp[-1].node);
        }
#line 1712 "parser.tab.c"
    break;

  case 45: /* BLOCK_ITEMS: BLOCK_ITEM  */
#line 280 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_BLOCK, 0, 0, 0, NULL, NULL);
        }
#line 1720 "parser.tab.c"
    break;

  case 46: /* BLOCK_ITEMS: BLOCK_ITEM BLOCK_ITEMS  */
#line 284 "parser.y"
        {
            (yyval.node) = (yyvsp[0].node);
            insert_sons((yyval.node), (yyvsp[-1].node), 0);
        }
#line 1729 "parser.tab.c"
    break;

  case 47: /* BLOCK_ITEM: DECL  */
#line 289 "parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 1735 "parser.tab.c"
    break;

  case 48: /* BLOCK_ITEM: STMT  */
#line 290 "parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 1741 "parser.tab.c"
    break;

  case 49: /* STMT: COLON  */
#line 293 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_TOKEN, 0, TOK_NONE, 0, NULL, NULL);
        }
#line 1749 "parser.tab.c"
    break;

  case 50: /* STMT: LVAL ASSIGN_OP8 EXP COLON  */
#line 297 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_STMT, 0, 0, 0, NULL, (yyvsp[-2].name));
            insert_sons((yyval.node), (yyvsp[-1].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].name), 0);
            insert_sons((yyval.node), (yyvsp[-3].node), 0);
        }
#line 1760 "parser.tab.c"
    break;

  case 51: /* STMT: EXP  */
#line 304 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_STMT, 1, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1769 "parser.tab.c"
    break;

  case 52: /* STMT: BLOCK  */
#line 309 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_STMT, 2, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1778 "parser.tab.c"
    break;

  case 53: /* STMT: IF L_PAR COND R_PAR STMT  */
#line 314 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_STMT, 3, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1788 "parser.tab.c"
    break;

  case 54: /* STMT: IF L_PAR COND R_PAR STMT ELSE STMT  */
#line 320 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_STMT, 4, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
            insert_sons((yyval.node), (yyvsp[-4].node), 0);
        }
#line 1799 "parser.tab.c"
    break;

  case 55: /* STMT: WHILE L_PAR COND R_PAR STMT  */
#line 327 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_STMT, 5, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1809 "parser.tab.c"
    break;

  case 56: /* STMT: BREAK COLON  */
#line 333 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_STMT, 6, 0, 0, NULL, NULL);
        }
#line 1817 "parser.tab.c"
    break;

  case 57: /* STMT: CONTINUE COLON  */
#line 337 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_STMT, 7, 0, 0, NULL, NULL);
        }
#line 1825 "parser.tab.c"
    break;

  case 58: /* STMT: RETURN COLON  */
#line 341 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_STMT, 8, 0, 0, NULL, NULL);
        }
#line 1833 "parser.tab.c"
    break;

  case 59: /* STMT: RETURN EXP COLON  */
#line 345 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_STMT, 9, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[-1].node), 0);
        }
#line 1842 "parser.tab.c"
    break;

  case 60: /* CONST_EXP: EXP  */
#line 350 "parser.y"
               {(yyval.node) = (yyvsp[0].node);}
#line 1848 "parser.tab.c"
    break;

  case 61: /* EXP: ADD_EXP  */
#line 352 "parser.y"
                  {(yyval.node) = (yyvsp[0].node);}
#line 1854 "parser.tab.c"
    break;

  case 62: /* ADD_EXP: MUL_EXP  */
#line 354 "parser.y"
                   {(yyval.node) = (yyvsp[0].node);}
#line 1860 "parser.tab.c"
    break;

  case 63: /* ADD_EXP: ADD_EXP ADDMIN_OP3 MUL_EXP  */
#line 356 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_BINARY_EXP, 0, 0, 0, NULL, (yyvsp[-1].name));
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1870 "parser.tab.c"
    break;

  case 64: /* MUL_EXP: UNARY_EXP  */
#line 362 "parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 1876 "parser.tab.c"
    break;

  case 65: /* MUL_EXP: MUL_EXP MULDIV_OP2 UNARY_EXP  */
#line 364 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_BINARY_EXP, 0, 0, 0, NULL, (yyvsp[-1].name));
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1886 "parser.tab.c"
    break;

  case 66: /* UNARY_EXP: PRIMARY_EXP  */
#line 370 "parser.y"
                       {(yyval.node) = (yyvsp[0].node);}
#line 1892 "parser.tab.c"
    break;

  case 67: /* UNARY_EXP: IDENTIFIER L_PAR R_PAR  */
#line 372 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_FUNC_CALL, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1901 "parser.tab.c"
    break;

  case 68: /* UNARY_EXP: IDENTIFIER L_PAR FUNC_RPARAMS R_PAR  */
#line 377 "parser.y"
        {
            (yyval.node) = (yyvsp[-1].node);
            insert_sons((yyval.node), (yyvsp[-3].node), 0);
        }
#line 1910 "parser.tab.c"
    break;

  case 69: /* UNARY_EXP: UNARY_OP UNARY_EXP  */
#line 382 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_UNARY_EXP, 0, 0, 0, NULL, (yyvsp[-1].node)->op_name);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1919 "parser.tab.c"
    break;

  case 70: /* UNARY_OP: ADDMIN_OP3  */
#line 388 "parser.y"
        {
            // tmp
            (yyval.node) = new_node(0, 0, 0, 0, 0, NULL, (yyvsp[0].name));
        }
#line 1928 "parser.tab.c"
    break;

  case 71: /* UNARY_OP: NOT_OP1  */
#line 393 "parser.y"
        {
            (yyval.node) = new_node(0, 0, 0, 0, 0, NULL, (yyvsp[0].name));
        }
#line 1936 "parser.tab.c"
    break;

  case 72: /* FUNC_RPARAMS: EXP  */
#line 398 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_FUNC_CALL, 0, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
        }
#line 1945 "parser.tab.c"
    break;

  case 73: /* FUNC_RPARAMS: EXP COMMA FUNC_RPARAMS  */
#line 403 "parser.y"
        {
            (yyval.node) = (yyvsp[0].node);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1954 "parser.tab.c"
    break;

  case 74: /* PRIMARY_EXP: L_PAR EXP R_PAR  */
#line 408 "parser.y"
                             {(yyval.node) = (yyvsp[-1].node);}
#line 1960 "parser.tab.c"
    break;

  case 75: /* PRIMARY_EXP: LVAL  */
#line 409 "parser.y"
                             {(yyval.node) = (yyvsp[0].node);}
#line 1966 "parser.tab.c"
    break;

  case 76: /* PRIMARY_EXP: INTEGER  */
#line 410 "parser.y"
                             {(yyval.node) = (yyvsp[0].node);}
#line 1972 "parser.tab.c"
    break;

  case 77: /* LVAL: IDENTIFIER VAR_INDEXES  */
#line 413 "parser.y"
        {
            // option #2: indexing
            (yyval.node) = new_node(NONCONST_REST, TP_UNARY_EXP, 1, 0, 0, NULL, NULL);
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-1].node), 0);
        }
#line 1983 "parser.tab.c"
    break;

  case 78: /* REL_EXP: ADD_EXP  */
#line 420 "parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 1989 "parser.tab.c"
    break;

  case 79: /* REL_EXP: REL_EXP COMP_OP4 ADD_EXP  */
#line 422 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_BINARY_EXP, 0, 0, 0, NULL, (yyvsp[-1].name));
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 1999 "parser.tab.c"
    break;

  case 80: /* EQ_EXP: REL_EXP  */
#line 428 "parser.y"
                       {(yyval.node) = (yyvsp[0].node);}
#line 2005 "parser.tab.c"
    break;

  case 81: /* EQ_EXP: EQ_EXP EQUAL_OP5 REL_EXP  */
#line 430 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_BINARY_EXP, 0, 0, 0, NULL, (yyvsp[-1].name));
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 2015 "parser.tab.c"
    break;

  case 82: /* COND: LOR_EXP  */
#line 436 "parser.y"
              {(yyval.node) = (yyvsp[0].node);}
#line 2021 "parser.tab.c"
    break;

  case 83: /* LAND_EXP: EQ_EXP  */
#line 438 "parser.y"
                   {(yyval.node) = (yyvsp[0].node);}
#line 2027 "parser.tab.c"
    break;

  case 84: /* LAND_EXP: LAND_EXP AND_OP6 EQ_EXP  */
#line 440 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_BINARY_EXP, 0, 0, 0, NULL, (yyvsp[-1].name));
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 2037 "parser.tab.c"
    break;

  case 85: /* LOR_EXP: LAND_EXP  */
#line 446 "parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 2043 "parser.tab.c"
    break;

  case 86: /* LOR_EXP: LOR_EXP OR_OP7 LAND_EXP  */
#line 448 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_BINARY_EXP, 0, 0, 0, NULL, (yyvsp[-1].name));
            insert_sons((yyval.node), (yyvsp[0].node), 0);
            insert_sons((yyval.node), (yyvsp[-2].node), 0);
        }
#line 2053 "parser.tab.c"
    break;

  case 87: /* INTEGER: DECIMAL_TOK  */
#line 455 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_TOKEN, 0, TOK_DEC, (yyvsp[0].value), NULL, NULL);
        }
#line 2061 "parser.tab.c"
    break;

  case 88: /* IDENTIFIER: IDENT  */
#line 460 "parser.y"
        {
            (yyval.node) = new_node(NONCONST_REST, TP_TOKEN, 0, TOK_IDENT, 0, (yyvsp[0].name), NULL);
        }
#line 2069 "parser.tab.c"
    break;


#line 2073 "parser.tab.c"

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

#line 465 "parser.y"


int main(int argc, char* argv){
    if (argc != 2){
        printf("Usage: ./parser TARGET_FILE\n");
        return 0;
    }
    FILE* inp_file = fopen(argv[1], "r");
    yyin = inp_file;

    tree_root = NULL;
    yyparse();
    print_tree(root);
    return 0;
}
