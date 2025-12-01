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
  YYSYMBOL_TID = 3,                        /* TID  */
  YYSYMBOL_TINT = 4,                       /* TINT  */
  YYSYMBOL_TBOOL = 5,                      /* TBOOL  */
  YYSYMBOL_TCTE = 6,                       /* TCTE  */
  YYSYMBOL_TASIG = 7,                      /* TASIG  */
  YYSYMBOL_TMAS = 8,                       /* TMAS  */
  YYSYMBOL_TMENOS = 9,                     /* TMENOS  */
  YYSYMBOL_TDIV = 10,                      /* TDIV  */
  YYSYMBOL_TMULT = 11,                     /* TMULT  */
  YYSYMBOL_TEXCL = 12,                     /* TEXCL  */
  YYSYMBOL_TFALSE = 13,                    /* TFALSE  */
  YYSYMBOL_TTRUE = 14,                     /* TTRUE  */
  YYSYMBOL_TAND = 15,                      /* TAND  */
  YYSYMBOL_TOR = 16,                       /* TOR  */
  YYSYMBOL_TPARAB = 17,                    /* TPARAB  */
  YYSYMBOL_TPARCERR = 18,                  /* TPARCERR  */
  YYSYMBOL_TLLAVAB = 19,                   /* TLLAVAB  */
  YYSYMBOL_TLLAVCERR = 20,                 /* TLLAVCERR  */
  YYSYMBOL_TCORCHAB = 21,                  /* TCORCHAB  */
  YYSYMBOL_TCORCHCERR = 22,                /* TCORCHCERR  */
  YYSYMBOL_TPUNTOCOMA = 23,                /* TPUNTOCOMA  */
  YYSYMBOL_TCOMA = 24,                     /* TCOMA  */
  YYSYMBOL_TREAD = 25,                     /* TREAD  */
  YYSYMBOL_TPRINT = 26,                    /* TPRINT  */
  YYSYMBOL_TIF = 27,                       /* TIF  */
  YYSYMBOL_TELSE = 28,                     /* TELSE  */
  YYSYMBOL_TFOR = 29,                      /* TFOR  */
  YYSYMBOL_TRETURN = 30,                   /* TRETURN  */
  YYSYMBOL_TIGUALQUE = 31,                 /* TIGUALQUE  */
  YYSYMBOL_TDISTINTOQUE = 32,              /* TDISTINTOQUE  */
  YYSYMBOL_TMAYORQUE = 33,                 /* TMAYORQUE  */
  YYSYMBOL_TMENORQUE = 34,                 /* TMENORQUE  */
  YYSYMBOL_TMAYORIGUAL = 35,               /* TMAYORIGUAL  */
  YYSYMBOL_TMENORIGUAL = 36,               /* TMENORIGUAL  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_programa = 38,                  /* programa  */
  YYSYMBOL_listDecla = 39,                 /* listDecla  */
  YYSYMBOL_decla = 40,                     /* decla  */
  YYSYMBOL_declaVar = 41,                  /* declaVar  */
  YYSYMBOL_declaFunc = 42,                 /* declaFunc  */
  YYSYMBOL_43_1 = 43,                      /* $@1  */
  YYSYMBOL_44_2 = 44,                      /* $@2  */
  YYSYMBOL_const = 45,                     /* const  */
  YYSYMBOL_tipoSimp = 46,                  /* tipoSimp  */
  YYSYMBOL_paramForm = 47,                 /* paramForm  */
  YYSYMBOL_listParamForm = 48,             /* listParamForm  */
  YYSYMBOL_bloque = 49,                    /* bloque  */
  YYSYMBOL_declaVarLocal = 50,             /* declaVarLocal  */
  YYSYMBOL_listInst = 51,                  /* listInst  */
  YYSYMBOL_inst = 52,                      /* inst  */
  YYSYMBOL_instExpre = 53,                 /* instExpre  */
  YYSYMBOL_instEntSal = 54,                /* instEntSal  */
  YYSYMBOL_instSelec = 55,                 /* instSelec  */
  YYSYMBOL_instIter = 56,                  /* instIter  */
  YYSYMBOL_expreOP = 57,                   /* expreOP  */
  YYSYMBOL_expre = 58,                     /* expre  */
  YYSYMBOL_expreLogic = 59,                /* expreLogic  */
  YYSYMBOL_expreIgual = 60,                /* expreIgual  */
  YYSYMBOL_expreRel = 61,                  /* expreRel  */
  YYSYMBOL_expreAd = 62,                   /* expreAd  */
  YYSYMBOL_expreMul = 63,                  /* expreMul  */
  YYSYMBOL_expreUna = 64,                  /* expreUna  */
  YYSYMBOL_expreSufi = 65,                 /* expreSufi  */
  YYSYMBOL_paramAct = 66,                  /* paramAct  */
  YYSYMBOL_listParamAct = 67,              /* listParamAct  */
  YYSYMBOL_opLogic = 68,                   /* opLogic  */
  YYSYMBOL_opIgual = 69,                   /* opIgual  */
  YYSYMBOL_opRel = 70,                     /* opRel  */
  YYSYMBOL_opAd = 71,                      /* opAd  */
  YYSYMBOL_opMul = 72,                     /* opMul  */
  YYSYMBOL_opUna = 73                      /* opUna  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 7 "src/asin.y"

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "../include/header.h"
    #include "../include/libtds.h"
    extern int yylineno;

    /*PARA COMPROBAR SI HAY MAIN EN EL PROGRAMA*/
    int mainCount = 0;
     /* Tipo de retorno declarado de la función actualmente procesada (parser-local)
         Usamos esta variable en lugar de llamar a obtTdD(-1) para evitar acceder
         a estructuras internas de la TdS que podrían estar en un estado
         inconsistente y provocar un segfault. */
     int current_func_return = T_ERROR;
    /* Temporales para manejar la insercion de funciones con mid-rule actions */
    char * nombre_func = NULL;
    int tipo_func = 0;
    

#line 197 "asin.c"


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
#define YYLAST   153

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

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
       0,    60,    60,    72,    72,    74,    74,    77,    91,   105,
     128,   138,   127,   165,   166,   167,   170,   170,   173,   174,
     177,   187,   199,   220,   221,   222,   223,   225,   225,   225,
     225,   225,   227,   228,   232,   240,   248,   256,   266,   269,
     275,   279,   290,   318,   322,   336,   340,   354,   358,   372,
     376,   390,   394,   408,   412,   426,   431,   435,   442,   453,
     470,   471,   473,   478,   482,   482,   484,   484,   486,   486,
     486,   486,   488,   489,   491,   491,   493,   493,   493
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
  "\"end of file\"", "error", "\"invalid token\"", "TID", "TINT", "TBOOL",
  "TCTE", "TASIG", "TMAS", "TMENOS", "TDIV", "TMULT", "TEXCL", "TFALSE",
  "TTRUE", "TAND", "TOR", "TPARAB", "TPARCERR", "TLLAVAB", "TLLAVCERR",
  "TCORCHAB", "TCORCHCERR", "TPUNTOCOMA", "TCOMA", "TREAD", "TPRINT",
  "TIF", "TELSE", "TFOR", "TRETURN", "TIGUALQUE", "TDISTINTOQUE",
  "TMAYORQUE", "TMENORQUE", "TMAYORIGUAL", "TMENORIGUAL", "$accept",
  "programa", "listDecla", "decla", "declaVar", "declaFunc", "$@1", "$@2",
  "const", "tipoSimp", "paramForm", "listParamForm", "bloque",
  "declaVarLocal", "listInst", "inst", "instExpre", "instEntSal",
  "instSelec", "instIter", "expreOP", "expre", "expreLogic", "expreIgual",
  "expreRel", "expreAd", "expreMul", "expreUna", "expreSufi", "paramAct",
  "listParamAct", "opLogic", "opIgual", "opRel", "opAd", "opMul", "opUna", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-121)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,  -121,  -121,    16,     4,  -121,  -121,  -121,     0,  -121,
    -121,    -6,    -1,    13,  -121,    11,  -121,  -121,  -121,    17,
      26,     4,  -121,    29,    51,    47,    34,  -121,  -121,  -121,
       4,    48,    63,  -121,  -121,  -121,     4,  -121,    65,    30,
      -6,    20,  -121,  -121,  -121,    67,  -121,  -121,    52,    57,
      60,    68,    67,  -121,  -121,  -121,  -121,  -121,  -121,    64,
       6,     3,    28,    37,    40,  -121,  -121,   130,    67,    67,
      67,    73,    80,    92,    67,    67,    67,    75,  -121,  -121,
    -121,   130,  -121,  -121,   130,  -121,  -121,  -121,  -121,   130,
    -121,  -121,   130,  -121,  -121,   130,   -11,  -121,  -121,    72,
      83,  -121,    82,  -121,  -121,    84,    94,    97,    87,  -121,
      96,     3,    28,    37,    40,  -121,    67,    67,  -121,   113,
      98,   100,   105,    67,  -121,   103,  -121,    67,  -121,  -121,
      99,   106,  -121,  -121,   105,    67,  -121,   108,   105,  -121
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    16,    17,     0,     2,     3,     5,     6,     0,     1,
       4,    10,     0,     0,     7,     0,    13,    15,    14,     0,
       0,    18,     8,     0,     0,     0,    19,     9,    20,    11,
       0,     0,     0,    23,    12,    21,    25,    24,     0,     0,
       0,    57,    76,    77,    78,     0,    25,    33,     0,     0,
       0,     0,     0,    55,    26,    28,    29,    30,    31,     0,
      40,    43,    45,    47,    49,    51,    53,     0,     0,    60,
       0,     0,     0,     0,     0,     0,    38,     0,    32,    64,
      65,     0,    66,    67,     0,    68,    69,    70,    71,     0,
      72,    73,     0,    75,    74,     0,    57,    54,    41,    62,
       0,    61,     0,    56,    27,     0,     0,     0,     0,    39,
       0,    44,    46,    48,    50,    52,     0,     0,    59,    58,
       0,     0,     0,     0,    22,     0,    63,     0,    34,    35,
       0,     0,    58,    42,     0,    38,    36,     0,     0,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -121,  -121,  -121,   131,   101,  -121,  -121,  -121,   128,   -10,
    -121,  -121,  -121,  -121,    95,  -120,  -121,  -121,  -121,  -121,
      10,   -45,  -121,    69,    62,    59,    61,   -63,  -121,  -121,
      32,  -121,  -121,  -121,  -121,  -121,  -121
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,    15,    31,    53,     8,
      25,    26,    34,    36,    39,    54,    55,    56,    57,    58,
     108,    59,    60,    61,    62,    63,    64,    65,    66,   100,
     101,    81,    84,    89,    92,    95,    67
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      71,    12,   130,    11,    97,    16,    69,    77,     1,     2,
     116,    24,    17,    18,   136,    13,     9,    14,   139,    20,
      32,    79,    80,    98,    99,   102,    38,    68,    21,   106,
     107,   109,   115,    41,    82,    83,    16,    69,    42,    43,
      22,    70,    44,    17,    18,    90,    91,    45,    23,    46,
      93,    94,    27,    47,    28,    48,    49,    50,    30,    51,
      52,    85,    86,    87,    88,    29,    35,    33,    40,    73,
      41,   125,    99,    16,    74,    42,    43,    75,   131,    44,
      17,    18,   133,    41,    45,    76,    16,    78,    42,    43,
     109,   103,    44,    17,    18,   105,   117,    45,   110,    46,
     104,   118,   120,    47,   119,    48,    49,    50,    41,    51,
     123,    16,   121,    42,    43,   122,   124,    44,    17,    18,
     127,   128,    45,   129,    46,   132,   138,   134,    47,   135,
      48,    49,    50,    96,    51,    10,    16,    37,    42,    43,
      19,    72,    44,    17,    18,   137,   112,    45,   113,   126,
     111,     0,     0,   114
};

static const yytype_int16 yycheck[] =
{
      45,     7,   122,     3,    67,     6,    17,    52,     4,     5,
      21,    21,    13,    14,   134,    21,     0,    23,   138,     6,
      30,    15,    16,    68,    69,    70,    36,     7,    17,    74,
      75,    76,    95,     3,    31,    32,     6,    17,     8,     9,
      23,    21,    12,    13,    14,     8,     9,    17,    22,    19,
      10,    11,    23,    23,     3,    25,    26,    27,    24,    29,
      30,    33,    34,    35,    36,    18,     3,    19,     3,    17,
       3,   116,   117,     6,    17,     8,     9,    17,   123,    12,
      13,    14,   127,     3,    17,    17,     6,    23,     8,     9,
     135,    18,    12,    13,    14,     3,    24,    17,    23,    19,
      20,    18,    18,    23,    22,    25,    26,    27,     3,    29,
      23,     6,    18,     8,     9,    18,    20,    12,    13,    14,
       7,    23,    17,    23,    19,    22,    18,    28,    23,    23,
      25,    26,    27,     3,    29,     4,     6,    36,     8,     9,
      12,    46,    12,    13,    14,   135,    84,    17,    89,   117,
      81,    -1,    -1,    92
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,    38,    39,    40,    41,    42,    46,     0,
      40,     3,     7,    21,    23,    43,     6,    13,    14,    45,
       6,    17,    23,    22,    46,    47,    48,    23,     3,    18,
      24,    44,    46,    19,    49,     3,    50,    41,    46,    51,
       3,     3,     8,     9,    12,    17,    19,    23,    25,    26,
      27,    29,    30,    45,    52,    53,    54,    55,    56,    58,
      59,    60,    61,    62,    63,    64,    65,    73,     7,    17,
      21,    58,    51,    17,    17,    17,    17,    58,    23,    15,
      16,    68,    31,    32,    69,    33,    34,    35,    36,    70,
       8,     9,    71,    10,    11,    72,     3,    64,    58,    58,
      66,    67,    58,    18,    20,     3,    58,    58,    57,    58,
      23,    60,    61,    62,    63,    64,    21,    24,    18,    22,
      18,    18,    18,    23,    20,    58,    67,     7,    23,    23,
      52,    58,    22,    58,    28,    23,    52,    57,    18,    52
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    41,    41,    41,
      43,    44,    42,    45,    45,    45,    46,    46,    47,    47,
      48,    48,    49,    50,    50,    51,    51,    52,    52,    52,
      52,    52,    53,    53,    54,    54,    55,    56,    57,    57,
      58,    58,    58,    59,    59,    60,    60,    61,    61,    62,
      62,    63,    63,    64,    64,    65,    65,    65,    65,    65,
      66,    66,    67,    67,    68,    68,    69,    69,    70,    70,
      70,    70,    71,    71,    72,    72,    73,    73,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     5,     6,
       0,     0,     8,     1,     1,     1,     1,     1,     0,     1,
       2,     4,     7,     0,     2,     0,     2,     3,     1,     1,
       1,     1,     2,     1,     5,     5,     7,     9,     0,     1,
       1,     3,     6,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     2,     1,     3,     1,     4,     4,
       0,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
  case 2: /* programa: listDecla  */
#line 61 "src/asin.y"
    {
        
    fprintf(stderr, "DEBUG: ULTIMA REGLA");
    fflush(stderr);
        if (mainCount == 0)
            yyerror("El programa no tiene 'main'");
        else if (mainCount > 1)
            yyerror("Hay más de una función main");
    }
#line 1256 "asin.c"
    break;

  case 7: /* declaVar: tipoSimp TID TPUNTOCOMA  */
#line 78 "src/asin.y"
    {   /*El res_b es el resultado de la búsqueda*/
        int res_b = 0;

        /*Ahora se verá si ya hay una variable con ese nombre y tipo.
        Además, el strdup nos permite pasar el valor a String*/

        fprintf(stderr, "DEBUG: insTdS call (var) name='%s' tipo=%d niv=%d desp=%d\n", (yyvsp[-1].s), (yyvsp[-2].i), niv, dvar);
        fflush(stderr);
        res_b = insTdS(strdup((yyvsp[-1].s)), VARIABLE, (yyvsp[-2].i), niv, dvar, -1);
        if (!res_b) yyerror("Identificador variable repetido"); /* Variable ya declarada */
        else
            dvar += TALLA_TIPO_SIMPLE;
    }
#line 1274 "asin.c"
    break;

  case 8: /* declaVar: tipoSimp TID TASIG const TPUNTOCOMA  */
#line 92 "src/asin.y"
    {
        int res_b = 0;
        fprintf(stderr, "DEBUG: insTdS call (init var) name='%s' tipo=%d niv=%d desp=%d\n", (yyvsp[-3].s), (yyvsp[-4].i), niv, dvar);
        fflush(stderr);
        res_b = insTdS(strdup((yyvsp[-3].s)), VARIABLE, (yyvsp[-4].i), niv, dvar, -1);
        if (!res_b) yyerror("Identificador variable repetido");
        else {
            /* Comprobar que el tipo de la inicialización coincide con el declarado */
            if ((yyvsp[-4].i) != (yyvsp[-1].i))
                yyerror("Error de tipos en la inicializacion de la variable");
            dvar += TALLA_TIPO_SIMPLE;
            }
    }
#line 1292 "asin.c"
    break;

  case 9: /* declaVar: tipoSimp TID TCORCHAB TCTE TCORCHCERR TPUNTOCOMA  */
#line 106 "src/asin.y"
    {
        int talla_arr =(yyvsp[-2].i);
        /*Si la talla es menor o igual que 0, no es válida*/
        if(talla_arr <=0){ yyerror("Talla inapropiada del array");}
            else{
                /*Insertamos el tipo y la talla en la tabla de arrays*/
                int ref = insTdA((yyvsp[-5].i), talla_arr); /*Tiene referencia porque es un array*/
                    
                int res_b = 0;
                fprintf(stderr, "DEBUG: insTdS call (array) name='%s' tipo=T_ARRAY niv=%d desp=%d ref=%d\n", (yyvsp[-4].s), niv, dvar, ref);
                fflush(stderr);
                res_b = insTdS(strdup((yyvsp[-4].s)), VARIABLE, T_ARRAY, niv, dvar, ref);
                if (!res_b) yyerror("Identificador del array repetido");
                else
                    dvar += talla_arr * TALLA_TIPO_SIMPLE;
                
            }
    }
#line 1315 "asin.c"
    break;

  case 10: /* $@1: %empty  */
#line 128 "src/asin.y"
    {    /*OBJETIVO: Gestion del contexto y guardar ‘‘dvar’’*/
        /*Se guarda la informacion necesaria para posteriormente agregarlo en la tds*/
        tipo_func = (yyvsp[-1].i);
        nombre_func = strdup((yyvsp[0].s));
        /*Entrar en nuevo nivel ANTES de procesar parámetros */
        niv++;
        cargaContexto(niv);
        dvar = 0; /*Se resetea el desplazamiento*/
    }
#line 1329 "asin.c"
    break;

  case 11: /* $@2: %empty  */
#line 138 "src/asin.y"
    {    /*OBJETIVO: Insertar informacion de la funcion en la TdS */
        /* Ahora paramForm ha creado el dominio y ha insertado parámetros en `niv`.
           Insertar la función en el nivel exterior (niv-1) usando la referencia devuelta por paramForm ($1). */
        int ref = (yyvsp[-4].s);
        if (nombre_func && strcmp(nombre_func, "main") == 0) { mainCount++; }
        
        SIMB simb = obtTdS(nombre_func);
        if (simb.t != T_ERROR && simb.n == niv-1) {
            yyerror("Función repetida");
        } else if (!insTdS(nombre_func, FUNCION, tipo_func, niv-1, dvar, ref)) {
            yyerror("Función repetida");
        } else {
            /* Guardar localmente el tipo de retorno de la función actual
               para evitar llamadas inseguras a obtTdD(-1) durante el parseo. */
            current_func_return = tipo_func;
        }
        
    }
#line 1352 "asin.c"
    break;

  case 12: /* declaFunc: tipoSimp TID $@1 TPARAB paramForm TPARCERR $@2 bloque  */
#line 158 "src/asin.y"
                                                          {

    }
#line 1360 "asin.c"
    break;

  case 13: /* const: TCTE  */
#line 165 "src/asin.y"
                { (yyval.i) = T_ENTERO; }
#line 1366 "asin.c"
    break;

  case 14: /* const: TTRUE  */
#line 166 "src/asin.y"
                { (yyval.i) = T_LOGICO; }
#line 1372 "asin.c"
    break;

  case 15: /* const: TFALSE  */
#line 167 "src/asin.y"
                { (yyval.i) = T_LOGICO; }
#line 1378 "asin.c"
    break;

  case 18: /* paramForm: %empty  */
#line 173 "src/asin.y"
    { (yyval.i) = -1; }
#line 1384 "asin.c"
    break;

  case 20: /* listParamForm: tipoSimp TID  */
#line 178 "src/asin.y"
    {
        /*Primer parámetro (último en la lista), se crea dominio*/
        (yyval.i) = insTdD(-1, (yyvsp[-1].i)); 
        
        /* Insertar parámetro en orden inverso */
        if(!insTdS(strdup((yyvsp[0].s)), PARAMETRO, (yyvsp[-1].i), niv, 0, -1)){
            yyerror("Identificador de parametro repetido");
        }
    }
#line 1398 "asin.c"
    break;

  case 21: /* listParamForm: listParamForm TCOMA tipoSimp TID  */
#line 188 "src/asin.y"
    {
        /*Insertar param con el dominio ya creado --> en orden inverso */
        (yyval.i) = insTdD((yyvsp[-3].i), (yyvsp[-1].i));

        /*Añadir param en TDS en posición correcta */
        if (!insTdS(strdup((yyvsp[0].s)), PARAMETRO, (yyvsp[-1].i), niv, 0, -1)){
             yyerror("Identificador de parametro repetido");
        }
    }
#line 1412 "asin.c"
    break;

  case 22: /* bloque: TLLAVAB declaVarLocal listInst TRETURN expre TPUNTOCOMA TLLAVCERR  */
#line 200 "src/asin.y"
    {
        /* Verificar que el tipo de la expresión del return coincide con el tipo
   declarado para la función actual (obtTdD(-1) devuelve info de la función). */
        /* Usar la variable parser-local `current_func_return` en lugar de
           llamar a `obtTdD(-1)` (evita acceder a estructuras internas que
           pueden no estar listas y provocar segfault). */
        fprintf(stderr, "DEBUG: current_func_return=%d\n", current_func_return);
        fflush(stderr);
        if (current_func_return != T_ERROR) {
            if ((yyvsp[-2].i) != current_func_return && (yyvsp[-2].i) != T_ERROR) {
                yyerror("Error de tipos en el 'return'");
            }
        }
        /*Descargar el contexto de la función al terminar su bloque */
        descargaContexto(niv);
        niv--;
        /* Restaurar la información de retorno actual por seguridad */
        current_func_return = T_ERROR;
    }
#line 1436 "asin.c"
    break;

  case 34: /* instEntSal: TREAD TPARAB TID TPARCERR TPUNTOCOMA  */
#line 233 "src/asin.y"
    {
        SIMB sim = obtTdS((yyvsp[-2].s));
        if (sim.t == T_ERROR)
            yyerror("Variable no declarada en READ");
        else if (sim.t != T_ENTERO)
            yyerror("El argumento del 'read' debe ser 'entero'");
    }
#line 1448 "asin.c"
    break;

  case 35: /* instEntSal: TPRINT TPARAB expre TPARCERR TPUNTOCOMA  */
#line 241 "src/asin.y"
    {
        /* Verificar que la expresión sea de tipo entero */
        if ((yyvsp[-2].i) != T_ENTERO && (yyvsp[-2].i) != T_ERROR)
            yyerror("La expresion del 'print' debe ser 'entera'");
    }
#line 1458 "asin.c"
    break;

  case 36: /* instSelec: TIF TPARAB expre TPARCERR inst TELSE inst  */
#line 249 "src/asin.y"
    {
        /* Verificar que la expresión de la condición sea de tipo lógico (TBOOL) */
        if ((yyvsp[-4].i) != T_LOGICO)
            yyerror("La expresión de la instrucción if-else debe ser de tipo lógico");
    }
#line 1468 "asin.c"
    break;

  case 37: /* instIter: TFOR TPARAB expreOP TPUNTOCOMA expre TPUNTOCOMA expreOP TPARCERR inst  */
#line 257 "src/asin.y"
    {
        /* Verificar que la expresión de la condición sea de tipo lógico (TBOOL) */
        /* La expresión del medio es obligatoria y debe ser de tipo lógico */
        if ((yyvsp[-4].i) != T_LOGICO)
            yyerror("La expresion del 'for' debe ser 'logica'");
    }
#line 1479 "asin.c"
    break;

  case 38: /* expreOP: %empty  */
#line 266 "src/asin.y"
    {
        (yyval.i) = 0;  /* valor por defecto cuando está vacía */
    }
#line 1487 "asin.c"
    break;

  case 39: /* expreOP: expre  */
#line 270 "src/asin.y"
    {
        (yyval.i) = (yyvsp[0].i);  /*sintetiza el valor*/
    }
#line 1495 "asin.c"
    break;

  case 40: /* expre: expreLogic  */
#line 276 "src/asin.y"
    {
        (yyval.i) = (yyvsp[0].i);
    }
#line 1503 "asin.c"
    break;

  case 41: /* expre: TID TASIG expre  */
#line 280 "src/asin.y"
    {   /* Este es el ejemplo que nos han dado*/
        SIMB sim = obtTdS((yyvsp[-2].s));
        if (sim.t == T_ERROR) yyerror("Objeto no declarado");
        else if (! (((sim.t == T_ENTERO) && ((yyvsp[0].i) == T_ENTERO)) ||
                ((sim.t == T_LOGICO) && ((yyvsp[0].i) == T_LOGICO))) )
                if((yyvsp[0].i)!= T_ERROR)
                    yyerror("Error de tipos en la 'instruccion de asignacion'");
        /* Propagar el tipo de la expresión (puede ser T_ERROR) */
        (yyval.i) = (yyvsp[0].i);
      }
#line 1518 "asin.c"
    break;

  case 42: /* expre: TID TCORCHAB expre TCORCHCERR TASIG expre  */
#line 291 "src/asin.y"
    {
        SIMB sim = obtTdS((yyvsp[-5].s));
        if (sim.t == T_ERROR)
            yyerror("Asignación a array no declarado");
        else{
            if(sim.t != T_ARRAY){
                yyerror("La variable debe ser tipo 'array'");
            }
            else {
                /*Verificar que el índice sea entero (si no fue ya error) */
                if ((yyvsp[-3].i) != T_ENTERO && (yyvsp[-3].i) != T_ERROR)
                    yyerror("El indice del 'array' debe ser entero");
                else{
                    DIM info_arr = obtTdA(sim.ref);
                    /*Solo emitir error si la expresión no vino ya marcada como error */
                    if ((yyvsp[0].i) != T_ERROR && info_arr.telem != (yyvsp[0].i)) {
                        yyerror("Error de tipos en la asignacion a un 'array'");
                    }
                }
            }
            
            /*Propagar el tipo (puede ser T_ERROR) */
            (yyval.i) = (yyvsp[0].i); 
        }
      }
#line 1548 "asin.c"
    break;

  case 43: /* expreLogic: expreIgual  */
#line 319 "src/asin.y"
    {
        (yyval.i) = (yyvsp[0].i);
    }
#line 1556 "asin.c"
    break;

  case 44: /* expreLogic: expreLogic opLogic expreIgual  */
#line 323 "src/asin.y"
    {
        /*Operaciones lógicas requieren operandos lógicos */
        if ((yyvsp[-2].i) == T_ERROR || (yyvsp[0].i) == T_ERROR) {
            (yyval.i) = T_ERROR;
        } else if ((yyvsp[-2].i) != T_LOGICO || (yyvsp[0].i) != T_LOGICO) {
            yyerror("Error de tipos en expresión lógica");
            (yyval.i) = T_ERROR;
        } else {
            (yyval.i) = T_LOGICO;
        }
    }
#line 1572 "asin.c"
    break;

  case 45: /* expreIgual: expreRel  */
#line 337 "src/asin.y"
    {
        (yyval.i) = (yyvsp[0].i);
    }
#line 1580 "asin.c"
    break;

  case 46: /* expreIgual: expreIgual opIgual expreRel  */
#line 341 "src/asin.y"
    {
        /*Las comparaciones de igualdad requieren operandos del mismo tipo */
        if ((yyvsp[-2].i) == T_ERROR || (yyvsp[0].i) == T_ERROR) {
            (yyval.i) = T_ERROR;
        } else if ((yyvsp[-2].i) != (yyvsp[0].i)) {
            yyerror("Error de tipos en expresión de igualdad");
            (yyval.i) = T_ERROR;
        } else {
            (yyval.i) = T_LOGICO;
        }
    }
#line 1596 "asin.c"
    break;

  case 47: /* expreRel: expreAd  */
#line 355 "src/asin.y"
    {
        (yyval.i) = (yyvsp[0].i);
    }
#line 1604 "asin.c"
    break;

  case 48: /* expreRel: expreRel opRel expreAd  */
#line 359 "src/asin.y"
    {
        /* Las relaciones requieren operandos enteros */
        if ((yyvsp[-2].i) == T_ERROR || (yyvsp[0].i) == T_ERROR) {
            (yyval.i) = T_ERROR;
        } else if ((yyvsp[-2].i) != T_ENTERO || (yyvsp[0].i) != T_ENTERO) {
            yyerror("Error de tipos en expresión relacional");
            (yyval.i) = T_ERROR;
        } else {
            (yyval.i) = T_LOGICO;
        }
    }
#line 1620 "asin.c"
    break;

  case 49: /* expreAd: expreMul  */
#line 373 "src/asin.y"
    {
        (yyval.i) = (yyvsp[0].i);
    }
#line 1628 "asin.c"
    break;

  case 50: /* expreAd: expreAd opAd expreMul  */
#line 377 "src/asin.y"
    {
        /* Suma/resta requieren operandos enteros */
        if ((yyvsp[-2].i) == T_ERROR || (yyvsp[0].i) == T_ERROR) {
            (yyval.i) = T_ERROR;
        } else if ((yyvsp[-2].i) != T_ENTERO || (yyvsp[0].i) != T_ENTERO) {
            yyerror("Error de tipos en 'expresion aditiva'");
            (yyval.i) = T_ERROR;
        } else {
            (yyval.i) = T_ENTERO;
        }
    }
#line 1644 "asin.c"
    break;

  case 51: /* expreMul: expreUna  */
#line 391 "src/asin.y"
    {
        (yyval.i) = (yyvsp[0].i);
    }
#line 1652 "asin.c"
    break;

  case 52: /* expreMul: expreMul opMul expreUna  */
#line 395 "src/asin.y"
    {
        /* Multiplicación/división requieren operandos enteros */
        if ((yyvsp[-2].i) == T_ERROR || (yyvsp[0].i) == T_ERROR) {
            (yyval.i) = T_ERROR;
        } else if ((yyvsp[-2].i) != T_ENTERO || (yyvsp[0].i) != T_ENTERO) {
            yyerror("Error de tipos en 'expresion multiplicativa'");
            (yyval.i) = T_ERROR; /* Propagar que hubo un error de tipos */
        } else {
            (yyval.i) = T_ENTERO;
        }
    }
#line 1668 "asin.c"
    break;

  case 53: /* expreUna: expreSufi  */
#line 409 "src/asin.y"
    {
        (yyval.i) = (yyvsp[0].i);
    }
#line 1676 "asin.c"
    break;

  case 54: /* expreUna: opUna expreUna  */
#line 413 "src/asin.y"
    {
        /*Operadores unarios conservan el tipo (solo para enteros) */
        if ((yyvsp[0].i) == T_ERROR) {
            (yyval.i) = T_ERROR;
        } else if ((yyvsp[0].i) != T_ENTERO) {
            yyerror("Error de tipos en expresión unaria");
            (yyval.i) = T_ERROR;
        } else {
            (yyval.i) = T_ENTERO;
        }
    }
#line 1692 "asin.c"
    break;

  case 55: /* expreSufi: const  */
#line 427 "src/asin.y"
    {
        /*Propagar el tipo de la constante (entero o lógico) */
        (yyval.i) = (yyvsp[0].i);
    }
#line 1701 "asin.c"
    break;

  case 56: /* expreSufi: TPARAB expre TPARCERR  */
#line 432 "src/asin.y"
    {
        (yyval.i) = (yyvsp[-1].i);
    }
#line 1709 "asin.c"
    break;

  case 57: /* expreSufi: TID  */
#line 436 "src/asin.y"
    {
        SIMB sim = obtTdS((yyvsp[0].s));
        if (sim.t == T_ERROR)
            yyerror("Uso de variable no declarada");
        (yyval.i) = sim.t;   /* devuelve el tipo */
      }
#line 1720 "asin.c"
    break;

  case 58: /* expreSufi: TID TCORCHAB expre TCORCHCERR  */
#line 443 "src/asin.y"
    {
        SIMB sim = obtTdS((yyvsp[-3].s));
        if (sim.t == T_ERROR)
            yyerror("Uso de array no declarado");

        /*Verificar que el índice sea entero */
        if ((yyvsp[-1].i) != T_ENTERO && (yyvsp[-1].i) != T_ERROR)
            yyerror("El indice del \"array\" debe ser entero");
        (yyval.i) = sim.t;
      }
#line 1735 "asin.c"
    break;

  case 59: /* expreSufi: TID TPARAB paramAct TPARCERR  */
#line 454 "src/asin.y"
    {
        SIMB sim = obtTdS((yyvsp[-3].s));
        if (sim.t == T_ERROR)
            yyerror("Uso de función no declarada");
        else {
        /*Comprueba coincidencia de dominios (parámetros) */
            /* si ambos -1 => sin parámetros -> OK */
            if (!((yyvsp[-1].i) == -1 && sim.ref == -1)) {
                if (!cmpDom((yyvsp[-1].i), sim.ref))
                    yyerror("Parámetros de la función no coinciden con la declaración");
            }
        }
          (yyval.i) = sim.t;  /* return function return type */
      }
#line 1754 "asin.c"
    break;

  case 60: /* paramAct: %empty  */
#line 470 "src/asin.y"
    { (yyval.i) = -1; }
#line 1760 "asin.c"
    break;

  case 61: /* paramAct: listParamAct  */
#line 471 "src/asin.y"
                  { (yyval.i) = (yyvsp[0].i); }
#line 1766 "asin.c"
    break;

  case 62: /* listParamAct: expre  */
#line 474 "src/asin.y"
    {
        /*Último argumento --> crea nuevo dominio */
        (yyval.i) = insTdD(-1, (yyvsp[0].i));
    }
#line 1775 "asin.c"
    break;

  case 63: /* listParamAct: expre TCOMA listParamAct  */
#line 479 "src/asin.y"
        {(yyval.i) = insTdD((yyvsp[0].i), (yyvsp[-2].i));}
#line 1781 "asin.c"
    break;


#line 1785 "asin.c"

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

#line 495 "src/asin.y"

