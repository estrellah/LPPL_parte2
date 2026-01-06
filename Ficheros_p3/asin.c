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
#line 1 "src/asin.y"

#include <stdio.h>
#include <string.h>
#include "header.h"
#include "libtds.h"
#include "libgci.h"

extern int yylineno;

/* Variables globales para gestión de main y errores */
int nmain = 0;
int errDeclFunc = 0; /* Flag para indicar error en la cabecera de la función actual */

#line 85 "asin.c"

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

#include "asin.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TASIG = 3,                      /* TASIG  */
  YYSYMBOL_TMAS = 4,                       /* TMAS  */
  YYSYMBOL_TMENOS = 5,                     /* TMENOS  */
  YYSYMBOL_TMULT = 6,                      /* TMULT  */
  YYSYMBOL_TDIV = 7,                       /* TDIV  */
  YYSYMBOL_TPUNTOCOMA = 8,                 /* TPUNTOCOMA  */
  YYSYMBOL_TCOMA = 9,                      /* TCOMA  */
  YYSYMBOL_TPARAB = 10,                    /* TPARAB  */
  YYSYMBOL_TPARCERR = 11,                  /* TPARCERR  */
  YYSYMBOL_TLLAVAB = 12,                   /* TLLAVAB  */
  YYSYMBOL_TLLAVCERR = 13,                 /* TLLAVCERR  */
  YYSYMBOL_TCORCHAB = 14,                  /* TCORCHAB  */
  YYSYMBOL_TCORCHCERR = 15,                /* TCORCHCERR  */
  YYSYMBOL_TAND = 16,                      /* TAND  */
  YYSYMBOL_TOR = 17,                       /* TOR  */
  YYSYMBOL_TEXCL = 18,                     /* TEXCL  */
  YYSYMBOL_TIGUALQUE = 19,                 /* TIGUALQUE  */
  YYSYMBOL_TDISTINTOQUE = 20,              /* TDISTINTOQUE  */
  YYSYMBOL_TMAYORQUE = 21,                 /* TMAYORQUE  */
  YYSYMBOL_TMENORQUE = 22,                 /* TMENORQUE  */
  YYSYMBOL_TMAYORIGUAL = 23,               /* TMAYORIGUAL  */
  YYSYMBOL_TMENORIGUAL = 24,               /* TMENORIGUAL  */
  YYSYMBOL_TTRUE = 25,                     /* TTRUE  */
  YYSYMBOL_TFALSE = 26,                    /* TFALSE  */
  YYSYMBOL_TREAD = 27,                     /* TREAD  */
  YYSYMBOL_TPRINT = 28,                    /* TPRINT  */
  YYSYMBOL_TIF = 29,                       /* TIF  */
  YYSYMBOL_TELSE = 30,                     /* TELSE  */
  YYSYMBOL_TFOR = 31,                      /* TFOR  */
  YYSYMBOL_TRETURN = 32,                   /* TRETURN  */
  YYSYMBOL_TINT = 33,                      /* TINT  */
  YYSYMBOL_TBOOL = 34,                     /* TBOOL  */
  YYSYMBOL_TID = 35,                       /* TID  */
  YYSYMBOL_TCTE = 36,                      /* TCTE  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_programa = 38,                  /* programa  */
  YYSYMBOL_39_1 = 39,                      /* @1  */
  YYSYMBOL_40_2 = 40,                      /* @2  */
  YYSYMBOL_listDecla = 41,                 /* listDecla  */
  YYSYMBOL_decla = 42,                     /* decla  */
  YYSYMBOL_declaVar = 43,                  /* declaVar  */
  YYSYMBOL_const = 44,                     /* const  */
  YYSYMBOL_tipoSimp = 45,                  /* tipoSimp  */
  YYSYMBOL_declaFunc = 46,                 /* declaFunc  */
  YYSYMBOL_47_3 = 47,                      /* @3  */
  YYSYMBOL_48_4 = 48,                      /* $@4  */
  YYSYMBOL_paramForm = 49,                 /* paramForm  */
  YYSYMBOL_listParamForm = 50,             /* listParamForm  */
  YYSYMBOL_bloque = 51,                    /* bloque  */
  YYSYMBOL_52_5 = 52,                      /* @5  */
  YYSYMBOL_declaVarLocal = 53,             /* declaVarLocal  */
  YYSYMBOL_listInst = 54,                  /* listInst  */
  YYSYMBOL_inst = 55,                      /* inst  */
  YYSYMBOL_instExpre = 56,                 /* instExpre  */
  YYSYMBOL_instEntSal = 57,                /* instEntSal  */
  YYSYMBOL_instSelec = 58,                 /* instSelec  */
  YYSYMBOL_59_6 = 59,                      /* @6  */
  YYSYMBOL_60_7 = 60,                      /* @7  */
  YYSYMBOL_instIter = 61,                  /* instIter  */
  YYSYMBOL_62_8 = 62,                      /* @8  */
  YYSYMBOL_63_9 = 63,                      /* @9  */
  YYSYMBOL_64_10 = 64,                     /* @10  */
  YYSYMBOL_65_11 = 65,                     /* @11  */
  YYSYMBOL_66_12 = 66,                     /* $@12  */
  YYSYMBOL_expreOP = 67,                   /* expreOP  */
  YYSYMBOL_expre = 68,                     /* expre  */
  YYSYMBOL_expreLogic = 69,                /* expreLogic  */
  YYSYMBOL_expreIgual = 70,                /* expreIgual  */
  YYSYMBOL_expreRel = 71,                  /* expreRel  */
  YYSYMBOL_expreAd = 72,                   /* expreAd  */
  YYSYMBOL_expreMul = 73,                  /* expreMul  */
  YYSYMBOL_expreUna = 74,                  /* expreUna  */
  YYSYMBOL_expreSufi = 75,                 /* expreSufi  */
  YYSYMBOL_76_13 = 76,                     /* $@13  */
  YYSYMBOL_paramAct = 77,                  /* paramAct  */
  YYSYMBOL_listParamAct = 78,              /* listParamAct  */
  YYSYMBOL_79_14 = 79,                     /* $@14  */
  YYSYMBOL_opLogic = 80,                   /* opLogic  */
  YYSYMBOL_opIgual = 81,                   /* opIgual  */
  YYSYMBOL_opRel = 82,                     /* opRel  */
  YYSYMBOL_opAd = 83,                      /* opAd  */
  YYSYMBOL_opMul = 84,                     /* opMul  */
  YYSYMBOL_opUna = 85                      /* opUna  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   159

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    85,    85,    95,    85,   118,   119,   123,   124,   128,
     135,   148,   164,   165,   166,   170,   171,   175,   184,   175,
     200,   201,   208,   216,   226,   226,   262,   263,   267,   268,
     272,   273,   274,   275,   276,   280,   281,   285,   294,   303,
     310,   303,   321,   324,   331,   335,   338,   321,   349,   355,
     359,   360,   375,   393,   394,   411,   412,   425,   426,   439,
     440,   453,   454,   467,   468,   485,   490,   495,   506,   519,
     519,   550,   551,   558,   563,   563,   576,   577,   581,   582,
     586,   587,   588,   589,   593,   594,   598,   599,   603,   604,
     605
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
  "\"end of file\"", "error", "\"invalid token\"", "TASIG", "TMAS",
  "TMENOS", "TMULT", "TDIV", "TPUNTOCOMA", "TCOMA", "TPARAB", "TPARCERR",
  "TLLAVAB", "TLLAVCERR", "TCORCHAB", "TCORCHCERR", "TAND", "TOR", "TEXCL",
  "TIGUALQUE", "TDISTINTOQUE", "TMAYORQUE", "TMENORQUE", "TMAYORIGUAL",
  "TMENORIGUAL", "TTRUE", "TFALSE", "TREAD", "TPRINT", "TIF", "TELSE",
  "TFOR", "TRETURN", "TINT", "TBOOL", "TID", "TCTE", "$accept", "programa",
  "@1", "@2", "listDecla", "decla", "declaVar", "const", "tipoSimp",
  "declaFunc", "@3", "$@4", "paramForm", "listParamForm", "bloque", "@5",
  "declaVarLocal", "listInst", "inst", "instExpre", "instEntSal",
  "instSelec", "@6", "@7", "instIter", "@8", "@9", "@10", "@11", "$@12",
  "expreOP", "expre", "expreLogic", "expreIgual", "expreRel", "expreAd",
  "expreMul", "expreUna", "expreSufi", "$@13", "paramAct", "listParamAct",
  "$@14", "opLogic", "opIgual", "opRel", "opAd", "opMul", "opUna", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-129)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-75)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -129,     3,  -129,  -129,    -9,  -129,  -129,    -9,  -129,  -129,
     -30,  -129,  -129,     1,    20,  -129,   -25,     9,  -129,  -129,
    -129,    14,    23,    -9,  -129,    33,    15,    43,  -129,  -129,
      49,  -129,    -9,    51,  -129,  -129,  -129,  -129,    -9,  -129,
      36,     8,     1,  -129,  -129,  -129,   111,  -129,  -129,    67,
      71,    76,    79,   111,    39,  -129,  -129,  -129,  -129,  -129,
    -129,    82,    31,    42,    45,    75,    90,  -129,  -129,   123,
      87,    47,    59,   111,   111,   111,    91,   111,   111,    92,
    -129,  -129,  -129,   123,  -129,  -129,   123,  -129,  -129,  -129,
    -129,   123,  -129,  -129,   123,  -129,  -129,   123,    -4,  -129,
    -129,  -129,    93,    94,    95,    99,  -129,   100,  -129,    88,
     111,    42,    45,    75,    90,  -129,   111,   109,   112,  -129,
    -129,  -129,   119,   114,   113,  -129,   110,  -129,  -129,    83,
     111,   111,   117,  -129,  -129,   101,  -129,  -129,   111,  -129,
    -129,  -129,    83,  -129,  -129,   122,   111,  -129,   121,    83,
    -129
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     3,     1,     0,    15,    16,     4,     6,     7,
       0,     8,     5,    17,     0,     9,     0,     0,    13,    14,
      12,     0,     0,    21,    10,     0,     0,     0,    20,    11,
      22,    18,     0,     0,    23,    24,    19,    27,    29,    26,
       0,     0,     0,    88,    89,    36,     0,    29,    90,     0,
       0,     0,     0,     0,    67,    65,    28,    31,    32,    33,
      34,     0,    50,    53,    55,    57,    59,    61,    63,     0,
       0,     0,     0,     0,     0,    49,     0,     0,     0,     0,
      35,    76,    77,     0,    78,    79,     0,    80,    81,    82,
      83,     0,    84,    85,     0,    86,    87,     0,    67,    64,
      66,    30,     0,     0,     0,     0,    48,     0,    51,     0,
      72,    54,    56,    58,    60,    62,     0,     0,     0,    39,
      42,    25,    68,    73,     0,    71,     0,    37,    38,     0,
       0,     0,     0,    70,    68,     0,    43,    52,     0,    40,
      44,    75,     0,    45,    41,     0,    49,    46,     0,     0,
      47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,  -129,  -129,  -129,   127,    97,   124,   -15,  -129,
    -129,  -129,  -129,   107,  -129,  -129,  -129,    96,  -128,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
      -6,   -46,  -129,    61,    56,    54,    57,   -67,  -129,  -129,
    -129,    12,  -129,  -129,  -129,  -129,  -129,  -129,  -129
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     4,     7,     8,     9,    55,    10,    11,
      17,    33,    27,    28,    36,    37,    38,    41,    56,    57,
      58,    59,   129,   142,    60,   130,   140,   143,   145,   148,
     105,    61,    62,    63,    64,    65,    66,    67,    68,    79,
     124,   125,   132,    83,    86,    91,    94,    97,    69
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      70,   135,    99,     3,    14,    13,   -69,    76,    26,    15,
     116,    22,    43,    44,   144,    16,    45,    26,    46,    23,
      47,   150,    24,    40,     5,     6,    48,   103,   104,   106,
     115,   108,   109,    18,    19,    49,    50,    51,    25,    52,
      53,    29,    77,    54,    20,    18,    19,    81,    82,   -69,
      30,    43,    44,    78,    31,    45,    20,    46,    32,    47,
     101,    84,    85,    35,   123,    48,    87,    88,    89,    90,
     126,    42,    18,    19,    49,    50,    51,    72,    52,    92,
      93,    73,    54,    20,   136,   137,    74,    43,    44,    75,
      80,    45,   123,    46,   102,    47,    95,    96,   100,   107,
     106,    48,   110,   122,   117,   118,   119,   120,    18,    19,
      49,    50,    51,   121,    52,    43,    44,   127,    54,    20,
     128,    46,   131,   -74,   133,   134,   138,    43,    44,    48,
     146,   139,   149,    46,    12,    39,    18,    19,    21,    34,
     147,    48,   112,    71,   111,   113,    54,    20,    18,    19,
     141,   114,     0,     0,     0,     0,     0,     0,    98,    20
};

static const yytype_int16 yycheck[] =
{
      46,   129,    69,     0,     3,    35,    10,    53,    23,     8,
      14,    36,     4,     5,   142,    14,     8,    32,    10,    10,
      12,   149,     8,    38,    33,    34,    18,    73,    74,    75,
      97,    77,    78,    25,    26,    27,    28,    29,    15,    31,
      32,     8,     3,    35,    36,    25,    26,    16,    17,    10,
      35,     4,     5,    14,    11,     8,    36,    10,     9,    12,
      13,    19,    20,    12,   110,    18,    21,    22,    23,    24,
     116,    35,    25,    26,    27,    28,    29,    10,    31,     4,
       5,    10,    35,    36,   130,   131,    10,     4,     5,    10,
       8,     8,   138,    10,    35,    12,     6,     7,    11,     8,
     146,    18,    10,    15,    11,    11,    11,     8,    25,    26,
      27,    28,    29,    13,    31,     4,     5,     8,    35,    36,
       8,    10,     3,     9,    11,    15,     9,     4,     5,    18,
       8,    30,    11,    10,     7,    38,    25,    26,    14,    32,
     146,    18,    86,    47,    83,    91,    35,    36,    25,    26,
     138,    94,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    39,     0,    40,    33,    34,    41,    42,    43,
      45,    46,    42,    35,     3,     8,    14,    47,    25,    26,
      36,    44,    36,    10,     8,    15,    45,    49,    50,     8,
      35,    11,     9,    48,    50,    12,    51,    52,    53,    43,
      45,    54,    35,     4,     5,     8,    10,    12,    18,    27,
      28,    29,    31,    32,    35,    44,    55,    56,    57,    58,
      61,    68,    69,    70,    71,    72,    73,    74,    75,    85,
      68,    54,    10,    10,    10,    10,    68,     3,    14,    76,
       8,    16,    17,    80,    19,    20,    81,    21,    22,    23,
      24,    82,     4,     5,    83,     6,     7,    84,    35,    74,
      11,    13,    35,    68,    68,    67,    68,     8,    68,    68,
      10,    70,    71,    72,    73,    74,    14,    11,    11,    11,
       8,    13,    15,    68,    77,    78,    68,     8,     8,    59,
      62,     3,    79,    11,    15,    55,    68,    68,     9,    30,
      63,    78,    60,    64,    55,    65,     8,    67,    66,    11,
      55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    39,    40,    38,    41,    41,    42,    42,    43,
      43,    43,    44,    44,    44,    45,    45,    47,    48,    46,
      49,    49,    50,    50,    52,    51,    53,    53,    54,    54,
      55,    55,    55,    55,    55,    56,    56,    57,    57,    59,
      60,    58,    62,    63,    64,    65,    66,    61,    67,    67,
      68,    68,    68,    69,    69,    70,    70,    71,    71,    72,
      72,    73,    73,    74,    74,    75,    75,    75,    75,    76,
      75,    77,    77,    78,    79,    78,    80,    80,    81,    81,
      82,    82,    82,    82,    83,    83,    84,    84,    85,    85,
      85
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     3,     2,     1,     1,     1,     3,
       5,     6,     1,     1,     1,     1,     1,     0,     0,     8,
       1,     0,     2,     4,     0,     8,     2,     0,     2,     0,
       3,     1,     1,     1,     1,     2,     1,     5,     5,     0,
       0,     9,     0,     0,     0,     0,     0,    14,     1,     0,
       1,     3,     6,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     2,     1,     3,     1,     4,     0,
       5,     1,     0,     1,     0,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
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
  case 2: /* @1: %empty  */
#line 85 "src/asin.y"
      { 
        dvar = 0;
        niv = 0; 
        cargaContexto(niv); 
        nmain = 0;
        
        /* GCI: Reserva espacio para variables globales */
        (yyval.cent) = creaLans(si);
        emite(INCTOP, crArgNul(), crArgNul(), crArgNul());
      }
#line 1277 "asin.c"
    break;

  case 3: /* @2: %empty  */
#line 95 "src/asin.y"
      {
        /* GCI: Salto inicial al main */
        (yyval.cent) = creaLans(si);
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(-1));
      }
#line 1287 "asin.c"
    break;

  case 4: /* programa: @1 @2 listDecla  */
#line 101 "src/asin.y"
      {
        /* Verificaciones finales */
        if (nmain == 0) yyerror("Error semantico: El programa no tiene 'main'");
        else if (nmain > 1) yyerror("Error semantico: El programa tiene más de un 'main'");
        
        if (verTdS) mostrarTdS();
        
        /* GCI: Parchear la reserva de globales */
        completaLans((yyvsp[-2].cent), crArgEnt(dvar));
        
        /* GCI: Parchear el salto al main */
        SIMB sim = obtTdS("main");
        completaLans((yyvsp[-1].cent), crArgEtq(sim.d));
      }
#line 1306 "asin.c"
    break;

  case 9: /* declaVar: tipoSimp TID TPUNTOCOMA  */
#line 128 "src/asin.y"
                              {
        if (!insTdS((yyvsp[-1].ident), VARIABLE, (yyvsp[-2].cent), niv, dvar, -1)) { 
            yyerror("Error semantico: Identificador repetido");
        } else {
            dvar += TALLA_TIPO_SIMPLE;                         
        } 
      }
#line 1318 "asin.c"
    break;

  case 10: /* declaVar: tipoSimp TID TASIG const TPUNTOCOMA  */
#line 135 "src/asin.y"
                                          {
        if ((yyvsp[-4].cent) != (yyvsp[-1].exp).t) {
            yyerror("Error semantico: Tipos incompatibles en la inicializacion");
        }
        if (!insTdS((yyvsp[-3].ident), VARIABLE, (yyvsp[-4].cent), niv, dvar, -1)) { 
            yyerror("Error semantico: Identificador repetido");
        } else {
            SIMB s = obtTdS((yyvsp[-3].ident));
            dvar += TALLA_TIPO_SIMPLE; 
            /* GCI: Inicialización de variable */
            emite(EASIG, crArgEnt((yyvsp[-1].exp).val), crArgNul(), crArgPos(s.n, s.d));
        }
      }
#line 1336 "asin.c"
    break;

  case 11: /* declaVar: tipoSimp TID TCORCHAB TCTE TCORCHCERR TPUNTOCOMA  */
#line 148 "src/asin.y"
                                                       {
        int numelem = (yyvsp[-2].cent);
        if ((yyvsp[-2].cent) <= 0) { 
            yyerror("Error semantico: Talla inapropiada del array"); 
            numelem = 0; 
        }
        int refe_array = insTdA((yyvsp[-5].cent), numelem);
        if (!insTdS((yyvsp[-4].ident), VARIABLE, T_ARRAY, niv, dvar, refe_array)) { 
            yyerror("Error semantico: Identificador repetido");
        } else {
            dvar += numelem * TALLA_TIPO_SIMPLE; 
        }
      }
#line 1354 "asin.c"
    break;

  case 12: /* const: TCTE  */
#line 164 "src/asin.y"
             { (yyval.exp).t = T_ENTERO; (yyval.exp).val = (yyvsp[0].cent); }
#line 1360 "asin.c"
    break;

  case 13: /* const: TTRUE  */
#line 165 "src/asin.y"
             { (yyval.exp).t = T_LOGICO; (yyval.exp).val = 1; }
#line 1366 "asin.c"
    break;

  case 14: /* const: TFALSE  */
#line 166 "src/asin.y"
             { (yyval.exp).t = T_LOGICO; (yyval.exp).val = 0; }
#line 1372 "asin.c"
    break;

  case 15: /* tipoSimp: TINT  */
#line 170 "src/asin.y"
            { (yyval.cent) = T_ENTERO; }
#line 1378 "asin.c"
    break;

  case 16: /* tipoSimp: TBOOL  */
#line 171 "src/asin.y"
            { (yyval.cent) = T_LOGICO; }
#line 1384 "asin.c"
    break;

  case 17: /* @3: %empty  */
#line 175 "src/asin.y"
                   {
        (yyval.cent) = dvar; /* Guardamos dvar global */
        dvar = 0;        /* Reset para locales */
        niv = 1;         /* Entramos a nivel local */
        cargaContexto(niv);
        
        if (strcmp((yyvsp[0].ident), "main") == 0) { nmain++; }
        errDeclFunc = 0;
      }
#line 1398 "asin.c"
    break;

  case 18: /* $@4: %empty  */
#line 184 "src/asin.y"
                                {
        /* Insertamos la función en la TDS (nivel global) */
        if (!insTdS((yyvsp[-4].ident), FUNCION, (yyvsp[-5].cent), niv-1, si, (yyvsp[-1].lista).ref)) {
            yyerror("Error semantico: Identificador de funcion repetido");
            errDeclFunc = 1;
        }
      }
#line 1410 "asin.c"
    break;

  case 19: /* declaFunc: tipoSimp TID @3 TPARAB paramForm TPARCERR $@4 bloque  */
#line 191 "src/asin.y"
             {
        if (verTdS) mostrarTdS();
        descargaContexto(niv);
        niv = 0;          /* Volvemos a nivel global */
        dvar = (yyvsp[-5].cent);  /* Restauramos dvar global */
      }
#line 1421 "asin.c"
    break;

  case 20: /* paramForm: listParamForm  */
#line 200 "src/asin.y"
                    { (yyval.lista) = (yyvsp[0].lista); }
#line 1427 "asin.c"
    break;

  case 21: /* paramForm: %empty  */
#line 201 "src/asin.y"
                   {  
        (yyval.lista).ref = insTdD(-1, T_VACIO);
        (yyval.lista).talla = TALLA_SEGENLACES; 
      }
#line 1436 "asin.c"
    break;

  case 22: /* listParamForm: tipoSimp TID  */
#line 208 "src/asin.y"
                   {
        (yyval.lista).ref = insTdD(-1, (yyvsp[-1].cent));
        (yyval.lista).talla = TALLA_TIPO_SIMPLE + TALLA_SEGENLACES;
        /* Insertamos parámetro con desplazamiento negativo */
        if (!insTdS((yyvsp[0].ident), PARAMETRO, (yyvsp[-1].cent), niv, -(yyval.lista).talla, (yyval.lista).ref)) { 
            yyerror("Error semantico: Error al declarar el parametro");
        }
      }
#line 1449 "asin.c"
    break;

  case 23: /* listParamForm: tipoSimp TID TCOMA listParamForm  */
#line 216 "src/asin.y"
                                       {
        (yyval.lista).ref = insTdD((yyvsp[0].lista).ref, (yyvsp[-3].cent));
        (yyval.lista).talla = (yyvsp[0].lista).talla + TALLA_TIPO_SIMPLE; 
        if (!insTdS((yyvsp[-2].ident), PARAMETRO, (yyvsp[-3].cent), niv, -(yyval.lista).talla, (yyval.lista).ref)) { 
            yyerror("Error semantico: Error al declarar el parametro"); 
        }
      }
#line 1461 "asin.c"
    break;

  case 24: /* @5: %empty  */
#line 226 "src/asin.y"
              {
        /* Prólogo de función: PUSHFP, FPTOP, INCTOP */
        emite(PUSHFP, crArgNul(), crArgNul(), crArgNul());
        emite(FPTOP, crArgNul(), crArgNul(), crArgNul());
        (yyval.cent) = creaLans(si);
        emite(INCTOP, crArgNul(), crArgNul(), crArgNul());
      }
#line 1473 "asin.c"
    break;

  case 25: /* bloque: TLLAVAB @5 declaVarLocal listInst TRETURN expre TPUNTOCOMA TLLAVCERR  */
#line 233 "src/asin.y"
                                                                {
        INF info = obtTdD(-1); /* Obtenemos info de función actual */
        
        if (errDeclFunc == 1) {
            yyerror("Error semantico: Error en la declaracion de la funcion");
        } else if (info.tipo != T_ERROR && (yyvsp[-2].exp).t != T_ERROR && (yyvsp[-2].exp).t != info.tipo) {
            yyerror("Error semantico: Error de tipos en el 'return'");
        }

        /* GCI: Parchear INCTOP con tamaño de variables locales */
        completaLans((yyvsp[-6].cent), crArgEnt(dvar));
        
        /* GCI: Gestión del valor de retorno */
        int dirret = TALLA_SEGENLACES + TALLA_TIPO_SIMPLE + info.tsp;
        emite(EASIG, crArgPos(niv, (yyvsp[-2].exp).d), crArgNul(), crArgPos(niv, -dirret));
        
        /* Epílogo: Restaurar pila */
        emite(TOPFP, crArgNul(), crArgNul(), crArgNul());
        emite(FPPOP, crArgNul(), crArgNul(), crArgNul());
        
        if (strcmp(info.nom, "main") == 0) {
            emite(FIN, crArgNul(), crArgNul(), crArgNul());
        } else {
            emite(RET, crArgNul(), crArgNul(), crArgNul());
        }
      }
#line 1504 "asin.c"
    break;

  case 35: /* instExpre: expre TPUNTOCOMA  */
#line 280 "src/asin.y"
                       { (yyval.exp) = (yyvsp[-1].exp); }
#line 1510 "asin.c"
    break;

  case 36: /* instExpre: TPUNTOCOMA  */
#line 281 "src/asin.y"
                 { (yyval.exp).t = T_VACIO; }
#line 1516 "asin.c"
    break;

  case 37: /* instEntSal: TREAD TPARAB TID TPARCERR TPUNTOCOMA  */
#line 285 "src/asin.y"
                                           {
        SIMB s = obtTdS((yyvsp[-2].ident));
        if (s.t == T_ERROR) {
            yyerror("Error semantico: Objeto no declarado en 'read'");
        } else if (s.t != T_ENTERO) {
            yyerror("Error semantico: La instruccion 'read' solo admite variables de tipo entero");
        }
        emite(EREAD, crArgNul(), crArgNul(), crArgPos(s.n, s.d));
      }
#line 1530 "asin.c"
    break;

  case 38: /* instEntSal: TPRINT TPARAB expre TPARCERR TPUNTOCOMA  */
#line 294 "src/asin.y"
                                              {
        if ((yyvsp[-2].exp).t != T_ENTERO) {
            yyerror("Error semantico: La instruccion 'print' solo admite expresiones de tipo entero");
        }
        emite(EWRITE, crArgNul(), crArgNul(), crArgPos(niv, (yyvsp[-2].exp).d));
      }
#line 1541 "asin.c"
    break;

  case 39: /* @6: %empty  */
#line 303 "src/asin.y"
                                {
        if ((yyvsp[-1].exp).t != T_LOGICO) {
            yyerror("Error semantico: La condicion del 'if' debe ser de tipo logico");
        }
        (yyval.cent) = creaLans(si);
        emite(EIGUAL, crArgPos(niv, (yyvsp[-1].exp).d), crArgEnt(0), crArgNul());
      }
#line 1553 "asin.c"
    break;

  case 40: /* @7: %empty  */
#line 310 "src/asin.y"
                 {
        (yyval.cent) = creaLans(si);
        emite(GOTOS, crArgNul(), crArgNul(), crArgNul());
        completaLans((yyvsp[-2].cent), crArgEtq(si));
      }
#line 1563 "asin.c"
    break;

  case 41: /* instSelec: TIF TPARAB expre TPARCERR @6 inst TELSE @7 inst  */
#line 315 "src/asin.y"
           {
        completaLans((yyvsp[-1].cent), crArgEtq(si));
      }
#line 1571 "asin.c"
    break;

  case 42: /* @8: %empty  */
#line 321 "src/asin.y"
                                     {
        (yyval.cent) = si; /* Marca inicio condición */
      }
#line 1579 "asin.c"
    break;

  case 43: /* @9: %empty  */
#line 324 "src/asin.y"
            {
        if ((yyvsp[0].exp).t != T_LOGICO) {
            yyerror("Error semantico: La condicion del 'for' debe ser de tipo logico");
        }
        (yyval.cent) = creaLans(si); /* Salto fin si falso */
        emite(EIGUAL, crArgEnt(0), crArgPos(niv, (yyvsp[0].exp).d), crArgNul());
      }
#line 1591 "asin.c"
    break;

  case 44: /* @10: %empty  */
#line 331 "src/asin.y"
      {
        (yyval.cent) = creaLans(si); /* Salto al cuerpo si verdadero (salta update) */
        emite(GOTOS, crArgNul(), crArgNul(), crArgNul());
      }
#line 1600 "asin.c"
    break;

  case 45: /* @11: %empty  */
#line 335 "src/asin.y"
      {
        (yyval.cent) = si; /* Inicio del Update */
      }
#line 1608 "asin.c"
    break;

  case 46: /* $@12: %empty  */
#line 338 "src/asin.y"
                         {
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq((yyvsp[-6].cent))); /* Vuelve a condición */
        completaLans((yyvsp[-3].cent), crArgEtq(si)); /* Parcheamos salto al cuerpo */
      }
#line 1617 "asin.c"
    break;

  case 47: /* instIter: TFOR TPARAB expreOP TPUNTOCOMA @8 expre @9 @10 @11 TPUNTOCOMA expreOP $@12 TPARCERR inst  */
#line 342 "src/asin.y"
                    {
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq((yyvsp[-5].cent))); /* Vuelve al update tras cuerpo */
        completaLans((yyvsp[-7].cent), crArgEtq(si)); /* Parcheamos salida bucle */
      }
#line 1626 "asin.c"
    break;

  case 48: /* expreOP: expre  */
#line 349 "src/asin.y"
            { 
        if ((yyvsp[0].exp).t != T_ENTERO && (yyvsp[0].exp).t != T_LOGICO) {
            yyerror("Error semantico: La expresion del 'for' debe ser de tipo simple");
        }
        (yyval.exp) = (yyvsp[0].exp);
      }
#line 1637 "asin.c"
    break;

  case 49: /* expreOP: %empty  */
#line 355 "src/asin.y"
                   { (yyval.exp).t = T_VACIO; }
#line 1643 "asin.c"
    break;

  case 50: /* expre: expreLogic  */
#line 359 "src/asin.y"
                 { (yyval.exp) = (yyvsp[0].exp); }
#line 1649 "asin.c"
    break;

  case 51: /* expre: TID TASIG expre  */
#line 360 "src/asin.y"
                      {
        SIMB sim = obtTdS((yyvsp[-2].ident));
        if (sim.t == T_ERROR) {
            yyerror("Error semantico: Objeto no declarado");
            (yyval.exp).t = T_ENTERO;
        } else {
            if (!(((sim.t == T_ENTERO) && ((yyvsp[0].exp).t == T_ENTERO)) || ((sim.t == T_LOGICO) && ((yyvsp[0].exp).t == T_LOGICO)))) {
                yyerror("Error semantico: Error de tipos en la ‘instruccion de asignacion’");
            }
            (yyval.exp).t = sim.t;
        }
        (yyval.exp).d = creaVarTemp();
        emite(EASIG, crArgPos(niv, (yyvsp[0].exp).d), crArgNul(), crArgPos(sim.n, sim.d)); /* Asignar a variable */
        emite(EASIG, crArgPos(niv, (yyvsp[0].exp).d), crArgNul(), crArgPos(niv, (yyval.exp).d));    /* Resultado expresión */
      }
#line 1669 "asin.c"
    break;

  case 52: /* expre: TID TCORCHAB expre TCORCHCERR TASIG expre  */
#line 375 "src/asin.y"
                                                {
        SIMB sim = obtTdS((yyvsp[-5].ident));
        if (sim.t == T_ERROR) yyerror("Error semantico: Objeto no declarado");
        else if (sim.t != T_ARRAY) yyerror("Error semantico: Se esperaba un array");
        else if ((yyvsp[-3].exp).t != T_ENTERO) yyerror("Error semantico: El indice del array debe ser entero");
        else {
            DIM dim = obtTdA(sim.ref);
            if (dim.telem != (yyvsp[0].exp).t) yyerror("Error semantico: Error de tipos en la asignacion del array");
            (yyval.exp).t = dim.telem;
            (yyval.exp).d = creaVarTemp();
            /* Asignación a vector: vect[indice] = valor */
            emite(EVA, crArgPos(sim.n, sim.d), crArgPos(niv, (yyvsp[-3].exp).d), crArgPos(niv, (yyvsp[0].exp).d));
            emite(EASIG, crArgPos(niv, (yyvsp[0].exp).d), crArgNul(), crArgPos(niv, (yyval.exp).d));
        }
      }
#line 1689 "asin.c"
    break;

  case 53: /* expreLogic: expreIgual  */
#line 393 "src/asin.y"
                 { (yyval.exp) = (yyvsp[0].exp); }
#line 1695 "asin.c"
    break;

  case 54: /* expreLogic: expreLogic opLogic expreIgual  */
#line 394 "src/asin.y"
                                    {
        if ((yyvsp[-2].exp).t != T_LOGICO || (yyvsp[0].exp).t != T_LOGICO) {
            yyerror("Error semantico: Operador logico espera tipos logicos");
        }
        (yyval.exp).t = T_LOGICO;
        (yyval.exp).d = creaVarTemp();
        emite((yyvsp[-1].cent), crArgPos(niv, (yyvsp[-2].exp).d), crArgPos(niv, (yyvsp[0].exp).d), crArgPos(niv, (yyval.exp).d));
        
        /* Ajuste específico para OR (suma lógica) si es > 1 */
        if ((yyvsp[-1].cent) == ESUM) {
             emite(EMENEQ, crArgPos(niv, (yyval.exp).d), crArgEnt(1), crArgEtq(si+2));
             emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, (yyval.exp).d));
        }
      }
#line 1714 "asin.c"
    break;

  case 55: /* expreIgual: expreRel  */
#line 411 "src/asin.y"
               { (yyval.exp) = (yyvsp[0].exp); }
#line 1720 "asin.c"
    break;

  case 56: /* expreIgual: expreIgual opIgual expreRel  */
#line 412 "src/asin.y"
                                  {
        if ((yyvsp[-2].exp).t != (yyvsp[0].exp).t) {
            yyerror("Error semantico: Tipos incompatibles en la comparacion de igualdad");
        }
        (yyval.exp).t = T_LOGICO;
        (yyval.exp).d = creaVarTemp();
        emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, (yyval.exp).d));
        emite((yyvsp[-1].cent), crArgPos(niv, (yyvsp[-2].exp).d), crArgPos(niv, (yyvsp[0].exp).d), crArgEtq(si+2));
        emite(EASIG, crArgEnt(0), crArgNul(), crArgPos(niv, (yyval.exp).d));
      }
#line 1735 "asin.c"
    break;

  case 57: /* expreRel: expreAd  */
#line 425 "src/asin.y"
              { (yyval.exp) = (yyvsp[0].exp); }
#line 1741 "asin.c"
    break;

  case 58: /* expreRel: expreRel opRel expreAd  */
#line 426 "src/asin.y"
                             {
        if ((yyvsp[-2].exp).t != T_ENTERO || (yyvsp[0].exp).t != T_ENTERO) {
            yyerror("Error semantico: Operador relacional espera tipos enteros");
        }
        (yyval.exp).t = T_LOGICO;
        (yyval.exp).d = creaVarTemp();
        emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, (yyval.exp).d));
        emite((yyvsp[-1].cent), crArgPos(niv, (yyvsp[-2].exp).d), crArgPos(niv, (yyvsp[0].exp).d), crArgEtq(si+2));
        emite(EASIG, crArgEnt(0), crArgNul(), crArgPos(niv, (yyval.exp).d));
      }
#line 1756 "asin.c"
    break;

  case 59: /* expreAd: expreMul  */
#line 439 "src/asin.y"
               { (yyval.exp) = (yyvsp[0].exp); }
#line 1762 "asin.c"
    break;

  case 60: /* expreAd: expreAd opAd expreMul  */
#line 440 "src/asin.y"
                            {
        if ((yyvsp[-2].exp).t != T_ENTERO || (yyvsp[0].exp).t != T_ENTERO) {
            yyerror("Error semantico: Operador aritmetico espera tipos enteros");
            (yyval.exp).t = T_ENTERO;
        } else {
            (yyval.exp).t = T_ENTERO;
        }
        (yyval.exp).d = creaVarTemp();
        emite((yyvsp[-1].cent), crArgPos(niv, (yyvsp[-2].exp).d), crArgPos(niv, (yyvsp[0].exp).d), crArgPos(niv, (yyval.exp).d));
      }
#line 1777 "asin.c"
    break;

  case 61: /* expreMul: expreUna  */
#line 453 "src/asin.y"
               { (yyval.exp) = (yyvsp[0].exp); }
#line 1783 "asin.c"
    break;

  case 62: /* expreMul: expreMul opMul expreUna  */
#line 454 "src/asin.y"
                              {
        if ((yyvsp[-2].exp).t != T_ENTERO || (yyvsp[0].exp).t != T_ENTERO) {
            yyerror("Error semantico: los tipos no son enteros");
            (yyval.exp).t = T_ENTERO;
        } else {
            (yyval.exp).t = T_ENTERO;
        }
        (yyval.exp).d = creaVarTemp();
        emite((yyvsp[-1].cent), crArgPos(niv, (yyvsp[-2].exp).d), crArgPos(niv, (yyvsp[0].exp).d), crArgPos(niv, (yyval.exp).d));
      }
#line 1798 "asin.c"
    break;

  case 63: /* expreUna: expreSufi  */
#line 467 "src/asin.y"
                { (yyval.exp) = (yyvsp[0].exp); }
#line 1804 "asin.c"
    break;

  case 64: /* expreUna: opUna expreUna  */
#line 468 "src/asin.y"
                     {
        if ((yyvsp[-1].cent) == ESIG) { /* Operador NOT (!) */
            if ((yyvsp[0].exp).t != T_LOGICO) yyerror("Operacion para NOT no usa tipo logico");
            (yyval.exp).t = T_LOGICO;
            (yyval.exp).d = creaVarTemp();
            /* Lógica: 1 - x (Si x es 0->1, si x es 1->0) */
            emite(EDIF, crArgEnt(1), crArgPos(niv, (yyvsp[0].exp).d), crArgPos(niv, (yyval.exp).d));
        } else { /* Operadores + o - unarios */
            if ((yyvsp[0].exp).t != T_ENTERO) yyerror("Operacion unarios no usa tipo entero");
            (yyval.exp).t = T_ENTERO;
            (yyval.exp).d = creaVarTemp();
            emite((yyvsp[-1].cent), crArgPos(niv, (yyvsp[0].exp).d), crArgEnt(0), crArgPos(niv, (yyval.exp).d));
        }
      }
#line 1823 "asin.c"
    break;

  case 65: /* expreSufi: const  */
#line 485 "src/asin.y"
            {
        (yyval.exp).t = (yyvsp[0].exp).t;
        (yyval.exp).d = creaVarTemp();
        emite(EASIG, crArgEnt((yyvsp[0].exp).val), crArgNul(), crArgPos(niv, (yyval.exp).d));
      }
#line 1833 "asin.c"
    break;

  case 66: /* expreSufi: TPARAB expre TPARCERR  */
#line 490 "src/asin.y"
                            {
        (yyval.exp).t = (yyvsp[-1].exp).t;
        (yyval.exp).d = creaVarTemp();
        emite(EASIG, crArgPos(niv, (yyvsp[-1].exp).d), crArgNul(), crArgPos(niv, (yyval.exp).d));
      }
#line 1843 "asin.c"
    break;

  case 67: /* expreSufi: TID  */
#line 495 "src/asin.y"
          {
        SIMB sim = obtTdS((yyvsp[0].ident));
        if (sim.t == T_ERROR) {
            yyerror("Error semantico: Objeto no declarado");
            (yyval.exp).t = T_ENTERO;
        } else {
            (yyval.exp).t = sim.t;
            (yyval.exp).d = creaVarTemp();
            emite(EASIG, crArgPos(sim.n, sim.d), crArgNul(), crArgPos(niv, (yyval.exp).d));
        }
      }
#line 1859 "asin.c"
    break;

  case 68: /* expreSufi: TID TCORCHAB expre TCORCHCERR  */
#line 506 "src/asin.y"
                                    {
        SIMB sim = obtTdS((yyvsp[-3].ident));
        if (sim.t == T_ERROR) yyerror("Error semantico: Objeto no declarado");
        else if (sim.t != T_ARRAY) yyerror("Error semantico: Se esperaba un array");
        else if ((yyvsp[-1].exp).t != T_ENTERO) yyerror("Error semantico: El indice del array debe ser de tipo entero");
        else {
            DIM dim = obtTdA(sim.ref);
            (yyval.exp).t = dim.telem;
            (yyval.exp).d = creaVarTemp();
            /* Acceso a vector: res = vect[indice] */
            emite(EAV, crArgPos(sim.n, sim.d), crArgPos(niv, (yyvsp[-1].exp).d), crArgPos(niv, (yyval.exp).d));
        }
      }
#line 1877 "asin.c"
    break;

  case 69: /* $@13: %empty  */
#line 519 "src/asin.y"
          {
        emite(INCTOP, crArgNul(), crArgNul(), crArgEnt(TALLA_TIPO_SIMPLE));
      }
#line 1885 "asin.c"
    break;

  case 70: /* expreSufi: TID $@13 TPARAB paramAct TPARCERR  */
#line 522 "src/asin.y"
                               {
        SIMB sim = obtTdS((yyvsp[-4].ident));
        if (sim.t == T_ERROR) {
            yyerror("Error semantico: Objeto no declarado");
            (yyval.exp).t = T_ERROR;
        } else {
            INF inf = obtTdD(sim.ref);
            if (inf.tipo == T_ERROR) {
                yyerror("Error semantico: Se esperaba una funcion");
                (yyval.exp).t = T_ERROR;
            } else if (inf.tsp != (yyvsp[-1].lista).talla) {
                yyerror("Numero de parametros incorrecto en llamada a funcion");
            } else if (!cmpDom((yyvsp[-1].lista).ref, sim.ref)) {
                yyerror("Error semantico: Error en los parametros");
            } else {
                emite(CALL, crArgNul(), crArgNul(), crArgEtq(sim.d));
                emite(DECTOP, crArgNul(), crArgNul(), crArgEnt(inf.tsp));
                (yyval.exp).t = inf.tipo;
                if (inf.tipo != T_VACIO) {
                    (yyval.exp).d = creaVarTemp();
                    emite(EPOP, crArgNul(), crArgNul(), crArgPos(niv, (yyval.exp).d));
                }
            }
        }
      }
#line 1915 "asin.c"
    break;

  case 71: /* paramAct: listParamAct  */
#line 550 "src/asin.y"
                   { (yyval.lista) = (yyvsp[0].lista); }
#line 1921 "asin.c"
    break;

  case 72: /* paramAct: %empty  */
#line 551 "src/asin.y"
                   {
        (yyval.lista).ref = insTdD(-1, T_VACIO);
        (yyval.lista).talla = 0;
      }
#line 1930 "asin.c"
    break;

  case 73: /* listParamAct: expre  */
#line 558 "src/asin.y"
            {
        emite(EPUSH, crArgNul(), crArgNul(), crArgPos(niv, (yyvsp[0].exp).d));
        (yyval.lista).ref = insTdD(-1, (yyvsp[0].exp).t);
        (yyval.lista).talla = 1;
      }
#line 1940 "asin.c"
    break;

  case 74: /* $@14: %empty  */
#line 563 "src/asin.y"
            {
        emite(EPUSH, crArgNul(), crArgNul(), crArgPos(niv, (yyvsp[0].exp).d));
      }
#line 1948 "asin.c"
    break;

  case 75: /* listParamAct: expre $@14 TCOMA listParamAct  */
#line 566 "src/asin.y"
                         {
        (yyval.lista).ref = insTdD((yyvsp[0].lista).ref, (yyvsp[-3].exp).t);
        (yyval.lista).talla = (yyvsp[0].lista).talla + 1;
      }
#line 1957 "asin.c"
    break;

  case 76: /* opLogic: TAND  */
#line 576 "src/asin.y"
           { (yyval.cent) = EMULT; }
#line 1963 "asin.c"
    break;

  case 77: /* opLogic: TOR  */
#line 577 "src/asin.y"
           { (yyval.cent) = ESUM; }
#line 1969 "asin.c"
    break;

  case 78: /* opIgual: TIGUALQUE  */
#line 581 "src/asin.y"
                { (yyval.cent) = EIGUAL; }
#line 1975 "asin.c"
    break;

  case 79: /* opIgual: TDISTINTOQUE  */
#line 582 "src/asin.y"
                   { (yyval.cent) = EDIST; }
#line 1981 "asin.c"
    break;

  case 80: /* opRel: TMAYORQUE  */
#line 586 "src/asin.y"
                { (yyval.cent) = EMAY; }
#line 1987 "asin.c"
    break;

  case 81: /* opRel: TMENORQUE  */
#line 587 "src/asin.y"
                { (yyval.cent) = EMEN; }
#line 1993 "asin.c"
    break;

  case 82: /* opRel: TMAYORIGUAL  */
#line 588 "src/asin.y"
                  { (yyval.cent) = EMAYEQ; }
#line 1999 "asin.c"
    break;

  case 83: /* opRel: TMENORIGUAL  */
#line 589 "src/asin.y"
                  { (yyval.cent) = EMENEQ; }
#line 2005 "asin.c"
    break;

  case 84: /* opAd: TMAS  */
#line 593 "src/asin.y"
           { (yyval.cent) = ESUM; }
#line 2011 "asin.c"
    break;

  case 85: /* opAd: TMENOS  */
#line 594 "src/asin.y"
             { (yyval.cent) = EDIF; }
#line 2017 "asin.c"
    break;

  case 86: /* opMul: TMULT  */
#line 598 "src/asin.y"
            { (yyval.cent) = EMULT; }
#line 2023 "asin.c"
    break;

  case 87: /* opMul: TDIV  */
#line 599 "src/asin.y"
            { (yyval.cent) = EDIVI; }
#line 2029 "asin.c"
    break;

  case 88: /* opUna: TMAS  */
#line 603 "src/asin.y"
           { (yyval.cent) = ESUM; }
#line 2035 "asin.c"
    break;

  case 89: /* opUna: TMENOS  */
#line 604 "src/asin.y"
             { (yyval.cent) = EDIF; }
#line 2041 "asin.c"
    break;

  case 90: /* opUna: TEXCL  */
#line 605 "src/asin.y"
            { (yyval.cent) = ESIG; }
#line 2047 "asin.c"
    break;


#line 2051 "asin.c"

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

#line 608 "src/asin.y"
