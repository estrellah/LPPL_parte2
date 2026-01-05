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
    #include <stdlib.h>
    #include "../include/header.h"
    #include "../include/libtds.h"
    #include "../include/libgci.h"
    extern int yylineno;

    /* PARTE 2: control de main y errores de declaración */
    int mainCount = 0;
    int tipo_func = 0;
    int errorDeclFuncActual = 0;

    /* ========= PARTE 3: control de programa / código ========= */

    /* etiqueta (posición en el código) donde empieza main */
    int etqMain = -1;

    /* listas de saltos/argumentos no satisfechos del arranque */
    int lansReservaGlob = -1;   /* lista para reserva de variables globales */
    int lansSaltoMain  = -1;    /* lista para salto inicial a main */

    int tallaGlobales = 0;      /* talla total de las globales (nivel 0) */

    /* nombre de la función que se está compilando ahora */
    char *funcionActual = NULL;

#line 100 "asin.c"

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
  YYSYMBOL_TDIV = 6,                       /* TDIV  */
  YYSYMBOL_TMULT = 7,                      /* TMULT  */
  YYSYMBOL_TEXCL = 8,                      /* TEXCL  */
  YYSYMBOL_TFALSE = 9,                     /* TFALSE  */
  YYSYMBOL_TTRUE = 10,                     /* TTRUE  */
  YYSYMBOL_TAND = 11,                      /* TAND  */
  YYSYMBOL_TOR = 12,                       /* TOR  */
  YYSYMBOL_TPARAB = 13,                    /* TPARAB  */
  YYSYMBOL_TPARCERR = 14,                  /* TPARCERR  */
  YYSYMBOL_TLLAVAB = 15,                   /* TLLAVAB  */
  YYSYMBOL_TLLAVCERR = 16,                 /* TLLAVCERR  */
  YYSYMBOL_TCORCHAB = 17,                  /* TCORCHAB  */
  YYSYMBOL_TCORCHCERR = 18,                /* TCORCHCERR  */
  YYSYMBOL_TPUNTOCOMA = 19,                /* TPUNTOCOMA  */
  YYSYMBOL_TCOMA = 20,                     /* TCOMA  */
  YYSYMBOL_TREAD = 21,                     /* TREAD  */
  YYSYMBOL_TPRINT = 22,                    /* TPRINT  */
  YYSYMBOL_TIF = 23,                       /* TIF  */
  YYSYMBOL_TELSE = 24,                     /* TELSE  */
  YYSYMBOL_TFOR = 25,                      /* TFOR  */
  YYSYMBOL_TRETURN = 26,                   /* TRETURN  */
  YYSYMBOL_TIGUALQUE = 27,                 /* TIGUALQUE  */
  YYSYMBOL_TDISTINTOQUE = 28,              /* TDISTINTOQUE  */
  YYSYMBOL_TMAYORQUE = 29,                 /* TMAYORQUE  */
  YYSYMBOL_TMENORQUE = 30,                 /* TMENORQUE  */
  YYSYMBOL_TMAYORIGUAL = 31,               /* TMAYORIGUAL  */
  YYSYMBOL_TMENORIGUAL = 32,               /* TMENORIGUAL  */
  YYSYMBOL_TID = 33,                       /* TID  */
  YYSYMBOL_TINT = 34,                      /* TINT  */
  YYSYMBOL_TBOOL = 35,                     /* TBOOL  */
  YYSYMBOL_TCTE = 36,                      /* TCTE  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_programa = 38,                  /* programa  */
  YYSYMBOL_39_1 = 39,                      /* $@1  */
  YYSYMBOL_40_2 = 40,                      /* $@2  */
  YYSYMBOL_listDecla = 41,                 /* listDecla  */
  YYSYMBOL_decla = 42,                     /* decla  */
  YYSYMBOL_declaVar = 43,                  /* declaVar  */
  YYSYMBOL_declaFunc = 44,                 /* declaFunc  */
  YYSYMBOL_45_3 = 45,                      /* $@3  */
  YYSYMBOL_46_4 = 46,                      /* $@4  */
  YYSYMBOL_const = 47,                     /* const  */
  YYSYMBOL_tipoSimp = 48,                  /* tipoSimp  */
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
  YYSYMBOL_instIter = 59,                  /* instIter  */
  YYSYMBOL_expreOP = 60,                   /* expreOP  */
  YYSYMBOL_expre = 61,                     /* expre  */
  YYSYMBOL_expreLogic = 62,                /* expreLogic  */
  YYSYMBOL_expreIgual = 63,                /* expreIgual  */
  YYSYMBOL_expreRel = 64,                  /* expreRel  */
  YYSYMBOL_expreAd = 65,                   /* expreAd  */
  YYSYMBOL_expreMul = 66,                  /* expreMul  */
  YYSYMBOL_expreUna = 67,                  /* expreUna  */
  YYSYMBOL_expreSufi = 68,                 /* expreSufi  */
  YYSYMBOL_paramAct = 69,                  /* paramAct  */
  YYSYMBOL_listParamAct = 70,              /* listParamAct  */
  YYSYMBOL_opLogic = 71,                   /* opLogic  */
  YYSYMBOL_opIgual = 72,                   /* opIgual  */
  YYSYMBOL_opRel = 73,                     /* opRel  */
  YYSYMBOL_opAd = 74,                      /* opAd  */
  YYSYMBOL_opMul = 75,                     /* opMul  */
  YYSYMBOL_opUna = 76                      /* opUna  */
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   154

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  144

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
       0,    97,    97,    97,   153,   153,   209,   210,   214,   215,
     218,   230,   248,   273,   290,   272,   329,   330,   331,   334,
     335,   339,   343,   349,   361,   376,   375,   430,   431,   433,
     434,   436,   437,   438,   439,   440,   442,   443,   446,   454,
     461,   468,   480,   483,   489,   493,   504,   532,   536,   550,
     554,   568,   572,   588,   592,   607,   611,   625,   629,   643,
     648,   652,   659,   670,   687,   693,   702,   709,   720,   720,
     722,   722,   724,   724,   724,   724,   727,   727,   729,   729,
     731,   731,   731
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
  "TMENOS", "TDIV", "TMULT", "TEXCL", "TFALSE", "TTRUE", "TAND", "TOR",
  "TPARAB", "TPARCERR", "TLLAVAB", "TLLAVCERR", "TCORCHAB", "TCORCHCERR",
  "TPUNTOCOMA", "TCOMA", "TREAD", "TPRINT", "TIF", "TELSE", "TFOR",
  "TRETURN", "TIGUALQUE", "TDISTINTOQUE", "TMAYORQUE", "TMENORQUE",
  "TMAYORIGUAL", "TMENORIGUAL", "TID", "TINT", "TBOOL", "TCTE", "$accept",
  "programa", "$@1", "$@2", "listDecla", "decla", "declaVar", "declaFunc",
  "$@3", "$@4", "const", "tipoSimp", "paramForm", "listParamForm",
  "bloque", "@5", "declaVarLocal", "listInst", "inst", "instExpre",
  "instEntSal", "instSelec", "instIter", "expreOP", "expre", "expreLogic",
  "expreIgual", "expreRel", "expreAd", "expreMul", "expreUna", "expreSufi",
  "paramAct", "listParamAct", "opLogic", "opIgual", "opRel", "opAd",
  "opMul", "opUna", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-123)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -123,    37,   -31,   -31,  -123,  -123,  -123,   -31,  -123,  -123,
    -123,   -28,   -31,  -123,     5,     0,   -22,  -123,    29,  -123,
    -123,  -123,    27,    36,   -31,  -123,    31,    15,    48,    51,
    -123,  -123,  -123,   -31,    62,    42,  -123,  -123,  -123,  -123,
     -31,  -123,    46,    30,     5,  -123,  -123,  -123,     8,  -123,
    -123,    75,    81,    87,    91,     8,    44,  -123,  -123,  -123,
    -123,  -123,  -123,    86,    14,    32,    95,    78,   108,  -123,
    -123,    60,    96,    76,    83,     8,     8,     8,    99,     8,
       8,     8,  -123,  -123,  -123,    60,  -123,  -123,    60,  -123,
    -123,  -123,  -123,    60,  -123,  -123,    60,  -123,  -123,    60,
       6,  -123,  -123,  -123,   114,   115,   116,   103,  -123,   117,
    -123,   112,   121,  -123,   118,    32,    95,    78,   108,  -123,
       8,   119,   120,    98,     8,  -123,     8,  -123,   134,   122,
    -123,  -123,   123,   124,  -123,     8,  -123,    98,     8,  -123,
    -123,   127,    98,  -123
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     0,     1,    19,    20,     3,     6,     8,
       9,     0,     5,     7,    13,     0,     0,    10,     0,    18,
      17,    16,     0,     0,    21,    11,     0,     0,     0,    22,
      12,    23,    14,     0,     0,     0,    25,    15,    24,    27,
      29,    28,     0,     0,     0,    80,    81,    82,     0,    29,
      37,     0,     0,     0,     0,     0,    61,    59,    30,    32,
      33,    34,    35,     0,    44,    47,    49,    51,    53,    55,
      57,     0,     0,     0,     0,     0,     0,    42,     0,     0,
      64,     0,    36,    68,    69,     0,    70,    71,     0,    72,
      73,    74,    75,     0,    76,    77,     0,    79,    78,     0,
      61,    58,    60,    31,     0,     0,     0,     0,    43,     0,
      45,    66,     0,    65,     0,    48,    50,    52,    54,    56,
       0,     0,     0,     0,     0,    26,     0,    63,    62,     0,
      38,    39,     0,     0,    67,     0,    62,     0,    42,    46,
      40,     0,     0,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -123,  -123,  -123,  -123,   139,    -1,   104,  -123,  -123,  -123,
     130,    34,  -123,  -123,  -123,  -123,  -123,    97,  -122,  -123,
    -123,  -123,  -123,    10,   -48,  -123,    64,    63,    57,    56,
     -69,  -123,  -123,    28,  -123,  -123,  -123,  -123,  -123,  -123
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     3,     7,     8,     9,    10,    18,    34,
      57,    11,    28,    29,    37,    39,    40,    43,    58,    59,
      60,    61,    62,   107,    63,    64,    65,    66,    67,    68,
      69,    70,   112,   113,    85,    88,    93,    96,    99,    71
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      72,   132,   101,     5,     6,    14,    13,    78,    15,    19,
      20,    13,    45,    46,    23,   140,    47,    19,    20,    80,
     143,    48,    16,   120,    17,    83,    84,   105,   106,   108,
     119,   110,   111,   114,    45,    46,    21,     4,    47,    19,
      20,    56,    24,    48,    21,    49,    25,    79,    31,    50,
      30,    51,    52,    53,    26,    54,    55,    80,    27,    86,
      87,    81,    32,    56,    45,    46,    21,    35,    47,    19,
      20,    33,   129,    48,    42,    38,   133,    36,   111,    44,
      45,    46,    94,    95,    47,    19,    20,   139,    74,    48,
     108,    49,   103,   100,    75,    50,    21,    51,    52,    53,
      76,    54,    45,    46,    77,    82,    47,    19,    20,    56,
     102,    48,    21,    49,    97,    98,   104,    50,   109,    51,
      52,    53,   124,    54,    89,    90,    91,    92,   121,   122,
     123,    56,   126,   125,    21,   127,   128,   135,   130,   131,
     136,   142,    12,   138,    41,    22,    73,   137,   141,   115,
     117,   116,   118,     0,   134
};

static const yytype_int16 yycheck[] =
{
      48,   123,    71,    34,    35,    33,     7,    55,     3,     9,
      10,    12,     4,     5,    36,   137,     8,     9,    10,    13,
     142,    13,    17,    17,    19,    11,    12,    75,    76,    77,
      99,    79,    80,    81,     4,     5,    36,     0,     8,     9,
      10,    33,    13,    13,    36,    15,    19,     3,    33,    19,
      19,    21,    22,    23,    18,    25,    26,    13,    24,    27,
      28,    17,    14,    33,     4,     5,    36,    33,     8,     9,
      10,    20,   120,    13,    40,    33,   124,    15,   126,    33,
       4,     5,     4,     5,     8,     9,    10,   135,    13,    13,
     138,    15,    16,    33,    13,    19,    36,    21,    22,    23,
      13,    25,     4,     5,    13,    19,     8,     9,    10,    33,
      14,    13,    36,    15,     6,     7,    33,    19,    19,    21,
      22,    23,    19,    25,    29,    30,    31,    32,    14,    14,
      14,    33,    20,    16,    36,    14,    18,     3,    19,    19,
      18,    14,     3,    19,    40,    15,    49,    24,   138,    85,
      93,    88,    96,    -1,   126
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    39,    40,     0,    34,    35,    41,    42,    43,
      44,    48,    41,    42,    33,     3,    17,    19,    45,     9,
      10,    36,    47,    36,    13,    19,    18,    48,    49,    50,
      19,    33,    14,    20,    46,    48,    15,    51,    33,    52,
      53,    43,    48,    54,    33,     4,     5,     8,    13,    15,
      19,    21,    22,    23,    25,    26,    33,    47,    55,    56,
      57,    58,    59,    61,    62,    63,    64,    65,    66,    67,
      68,    76,    61,    54,    13,    13,    13,    13,    61,     3,
      13,    17,    19,    11,    12,    71,    27,    28,    72,    29,
      30,    31,    32,    73,     4,     5,    74,     6,     7,    75,
      33,    67,    14,    16,    33,    61,    61,    60,    61,    19,
      61,    61,    69,    70,    61,    63,    64,    65,    66,    67,
      17,    14,    14,    14,    19,    16,    20,    14,    18,    61,
      19,    19,    55,    61,    70,     3,    18,    24,    19,    61,
      55,    60,    14,    55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    39,    38,    40,    38,    41,    41,    42,    42,
      43,    43,    43,    45,    46,    44,    47,    47,    47,    48,
      48,    49,    49,    50,    50,    52,    51,    53,    53,    54,
      54,    55,    55,    55,    55,    55,    56,    56,    57,    57,
      58,    59,    60,    60,    61,    61,    61,    62,    62,    63,
      63,    64,    64,    65,    65,    66,    66,    67,    67,    68,
      68,    68,    68,    68,    69,    69,    70,    70,    71,    71,
      72,    72,    73,    73,    73,    73,    74,    74,    75,    75,
      76,    76,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     1,     2,     1,     1,
       3,     5,     6,     0,     0,     8,     1,     1,     1,     1,
       1,     0,     1,     2,     4,     0,     8,     0,     2,     0,
       2,     3,     1,     1,     1,     1,     2,     1,     5,     5,
       7,     9,     0,     1,     1,     3,     6,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     2,     1,
       3,     1,     4,     4,     0,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
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
  case 2: /* $@1: %empty  */
#line 97 "src/asin.y"
    {
        /* === INICIALIZACIÓN DEL CONTEXTO GLOBAL (igual que en la parte 2) === */
        niv = 0;
        dvar = 0;
        si  = 0;
        cargaContexto(niv);

        /* === CÓDIGO DE ARRANQUE DEL PROGRAMA (parte 3) ===
           1) Reserva de espacio para variables globales
           2) Salto incondicional a main
        */
        TIPO_ARG argN = crArgNul();

        /* 1) Reserva de espacio para variables globales */
        emite(INCTOP, argN, argN, argN);
        lansReservaGlob = creaLans(si-1);

        /* 2) Salto inicial a main */
        emite(GOTOS, argN, argN, argN);
        lansSaltoMain = creaLans(si-1);
    }
#line 1286 "asin.c"
    break;

  case 3: /* programa: $@1 listDecla  */
#line 119 "src/asin.y"
    {
        /* ========= FINAL DEL PROGRAMA ========= */

        if (verTdS) mostrarTdS();
        fprintf(stderr, "DEBUG: ULTIMA REGLA");
        fflush(stderr);

        /* Comprobaciones de main */
        if (mainCount == 0) {
            yyerror("El programa no tiene 'main'");
        } else if (mainCount > 1) {
            yyerror("Hay más de una función main");
        }

        /* SOLO si hay exactamente una main completamos los lanzamientos */
        if (mainCount == 1) {
            TIPO_ARG arg;

            /* Completar INCTOP con tallaGlobales */
            arg = crArgEnt(tallaGlobales);
            completaLans(lansReservaGlob, arg);

            /* Completar GOTOS con etiqueta de main */
            arg = crArgEtq(etqMain);
            completaLans(lansSaltoMain, arg);
        }

        /* (Opcional) descarga del contexto global:
         * descargaContexto(niv);   // si lo queréis usar
         */
    }
#line 1322 "asin.c"
    break;

  case 4: /* $@2: %empty  */
#line 153 "src/asin.y"
    {
        /* === INICIALIZACIÓN DEL CONTEXTO GLOBAL (igual que en la parte 2) === */
        niv = 0;
        dvar = 0;
        si  = 0;
        cargaContexto(niv);

        /* === CÓDIGO DE ARRANQUE DEL PROGRAMA (parte 3) ===
           1) Reserva de espacio para variables globales
           2) Salto incondicional a main
        */
        TIPO_ARG argN = crArgNul();

        /* 1) Reserva de espacio para variables globales */
        emite(INCTOP, argN, argN, argN);
        lansReservaGlob = creaLans(si-1);

        /* 2) Salto inicial a main */
        emite(GOTOS, argN, argN, argN);
        lansSaltoMain = creaLans(si-1);
    }
#line 1348 "asin.c"
    break;

  case 5: /* programa: $@2 listDecla  */
#line 175 "src/asin.y"
    {
        /* ========= FINAL DEL PROGRAMA ========= */

        if (verTdS) mostrarTdS();
        fprintf(stderr, "DEBUG: ULTIMA REGLA");
        fflush(stderr);

        /* Comprobaciones de main */
        if (mainCount == 0) {
            yyerror("El programa no tiene 'main'");
        } else if (mainCount > 1) {
            yyerror("Hay más de una función main");
        }

        /* SOLO si hay exactamente una main completamos los lanzamientos */
        if (mainCount == 1) {
            TIPO_ARG arg;

            /* Completar INCTOP con tallaGlobales */
            arg = crArgEnt(tallaGlobales);
            completaLans(lansReservaGlob, arg);

            /* Completar GOTOS con etiqueta de main */
            arg = crArgEtq(etqMain);
            completaLans(lansSaltoMain, arg);
        }

        /* (Opcional) descarga del contexto global:
         * descargaContexto(niv);   // si lo queréis usar
         */
    }
#line 1384 "asin.c"
    break;

  case 10: /* declaVar: tipoSimp TID TPUNTOCOMA  */
#line 219 "src/asin.y"
    { 
        /*Si ponerlo en la tabla de simbolos no da error...*/
        if (!insTdS(strdup((yyvsp[-1].ident)), VARIABLE, (yyvsp[-2].tipo).t, niv, dvar, -1))
            yyerror("Identificador de variable repetido"); /* Variable ya declarada */
        else {
            dvar += TALLA_TIPO_SIMPLE;
            /* PARTE 3: si es global (niv==0), acumular talla en tallaGlobales */
            if (niv == 0)
                tallaGlobales += TALLA_TIPO_SIMPLE;
        }
    }
#line 1400 "asin.c"
    break;

  case 11: /* declaVar: tipoSimp TID TASIG const TPUNTOCOMA  */
#line 231 "src/asin.y"
    {
        /* O lo quitas directamente si ya no necesitas el debug */
        fprintf(stderr,
                "DEBUG: insTdS call (init var) name='%s' tipo=%d niv=%d desp=%d\n",
                (yyvsp[-3].ident), (yyvsp[-4].tipo).t, niv, dvar);
        fflush(stderr);

        if (!insTdS(strdup((yyvsp[-3].ident)), VARIABLE, (yyvsp[-4].tipo).t, niv, dvar, -1))
            yyerror("Identificador de variable repetido");
        else {
            if ((yyvsp[-4].tipo).t != (yyvsp[-1].tipo).t)
                yyerror("Error de tipos en la inicializacion de la variable");
            dvar += TALLA_TIPO_SIMPLE;
            if (niv == 0)
                tallaGlobales += TALLA_TIPO_SIMPLE;
        }
    }
#line 1422 "asin.c"
    break;

  case 12: /* declaVar: tipoSimp TID TCORCHAB TCTE TCORCHCERR TPUNTOCOMA  */
#line 249 "src/asin.y"
    {
        int talla_arr = (yyvsp[-2].cent);
        /*Si la talla es menor o igual que 0, no es válida*/
        if(talla_arr <= 0){
            yyerror("Talla inapropiada del array");
        } else {
            /*Insertamos el tipo y la talla en la tabla de arrays*/
            int ref = insTdA((yyvsp[-5].tipo).t, talla_arr); /*Tiene referencia porque es un array*/
                    
            fprintf(stderr, "DEBUG: insTdS call (array) name='%s' tipo=T_ARRAY niv=%d desp=%d ref=%d\n", (yyvsp[-4].ident), niv, dvar, ref);
            fflush(stderr);
            if (!insTdS(strdup((yyvsp[-4].ident)), VARIABLE, T_ARRAY, niv, dvar, ref))
                yyerror("Identificador del array repetido");
            else {
                dvar += talla_arr * TALLA_TIPO_SIMPLE;
                if (niv == 0)
                    tallaGlobales += talla_arr * TALLA_TIPO_SIMPLE;
            }
        }
    }
#line 1447 "asin.c"
    break;

  case 13: /* $@3: %empty  */
#line 273 "src/asin.y"
    {    /*OBJETIVO: Gestion del contexto y guardar ‘‘dvar’’*/
        /*Entrar en nuevo nivel ANTES de procesar parámetros */
        niv++;
        cargaContexto(niv);
        dvar = 0; /*Se resetea el desplazamiento*/

        /* === PARTE 3: información de función actual y etiqueta === */

        /* Guardar el nombre de la función actual (para saber si es main) */
        funcionActual = strdup((yyvsp[0].ident));

        /* La función empieza en la instrucción actual 'si' */
        if (strcmp((yyvsp[0].ident), "main") == 0) {
            etqMain = si;
        }
    }
#line 1468 "asin.c"
    break;

  case 14: /* $@4: %empty  */
#line 290 "src/asin.y"
    {    /*OBJETIVO: Insertar informacion de la funcion en la TdS */
        /* ¿Es main? contamos cuántas hay */
        if (strcmp((yyvsp[-4].ident), "main") == 0) {
            mainCount++;
        }

        /* Insertar la funcion en la TdS de nivel global (niv-1) */
        SIMB simb = obtTdS((yyvsp[-4].ident));
        if (simb.t != T_ERROR) {
            yyerror("Función repetida");
            errorDeclFuncActual = 1;
        } else if (!insTdS(strdup((yyvsp[-4].ident)), FUNCION, (yyvsp[-5].tipo).t, niv-1, si, (yyvsp[-1].paramInfo).ref)) {
            /*            ***********  ^^^  AQUÍ  ^^^  *********** */
            yyerror("Función repetida");
            errorDeclFuncActual = 1;
        } else {
            errorDeclFuncActual = 0;
        }
    }
#line 1492 "asin.c"
    break;

  case 15: /* declaFunc: tipoSimp TID $@3 TPARAB paramForm TPARCERR $@4 bloque  */
#line 312 "src/asin.y"
    {
        (yyval.funcion).tipo_return = (yyvsp[-7].tipo).t;
        (yyval.funcion).nombre_func = strdup((yyvsp[-6].ident));
        dvar = (yyvsp[0].funcion).desp;
        (yyval.funcion).num_params = (yyvsp[-3].paramInfo).num_params;

        if (errorDeclFuncActual) {
            yyerror("En la declaracion de la funcion");
            errorDeclFuncActual = 0;
        } else if ((yyvsp[0].funcion).tipo_return != (yyvsp[-7].tipo).t) {
            yyerror("Error de tipos en el 'return'");
        }
    }
#line 1510 "asin.c"
    break;

  case 16: /* const: TCTE  */
#line 329 "src/asin.y"
                  { (yyval.tipo).t = T_ENTERO; }
#line 1516 "asin.c"
    break;

  case 17: /* const: TTRUE  */
#line 330 "src/asin.y"
                  { (yyval.tipo).t = T_LOGICO; }
#line 1522 "asin.c"
    break;

  case 18: /* const: TFALSE  */
#line 331 "src/asin.y"
                  { (yyval.tipo).t = T_LOGICO; }
#line 1528 "asin.c"
    break;

  case 19: /* tipoSimp: TINT  */
#line 334 "src/asin.y"
              { (yyval.tipo).t = T_ENTERO; }
#line 1534 "asin.c"
    break;

  case 20: /* tipoSimp: TBOOL  */
#line 335 "src/asin.y"
              { (yyval.tipo).t = T_LOGICO; }
#line 1540 "asin.c"
    break;

  case 21: /* paramForm: %empty  */
#line 339 "src/asin.y"
    { 
        (yyval.paramInfo).ref = insTdD(-1, T_VACIO);
        (yyval.paramInfo).num_params = 0;
    }
#line 1549 "asin.c"
    break;

  case 22: /* paramForm: listParamForm  */
#line 343 "src/asin.y"
                    { 
        (yyval.paramInfo).num_params = (yyvsp[0].paramInfo).num_params; 
        (yyval.paramInfo).ref = (yyvsp[0].paramInfo).ref;
        }
#line 1558 "asin.c"
    break;

  case 23: /* listParamForm: tipoSimp TID  */
#line 350 "src/asin.y"
    {
        (yyval.paramInfo).num_params = 1;
        (yyval.paramInfo).talla = TALLA_TIPO_SIMPLE+ TALLA_SEGENLACES;
        /*Primer parámetro (último en la lista), se crea dominio*/
        (yyval.paramInfo).ref = insTdD(-1, (yyvsp[-1].tipo).t); 
        
        /*Insertar parámetro en orden inverso */
        if(!insTdS(strdup((yyvsp[0].ident)), PARAMETRO, (yyvsp[-1].tipo).t, niv, 0, -1)){
            yyerror("Identificador de parametro repetido");
        }
    }
#line 1574 "asin.c"
    break;

  case 24: /* listParamForm: listParamForm TCOMA tipoSimp TID  */
#line 362 "src/asin.y"
    {
        /*Insertar param con el dominio ya creado --> en orden inverso */
        (yyval.paramInfo).ref = insTdD((yyvsp[-3].paramInfo).ref, (yyvsp[-1].tipo).t);
        (yyval.paramInfo).num_params = (yyvsp[-3].paramInfo).num_params + 1;
        (yyval.paramInfo).talla = (yyvsp[-3].paramInfo).talla + TALLA_TIPO_SIMPLE;

        /*Añadir param en TDS en posición correcta */
        if (!insTdS(strdup((yyvsp[0].ident)), PARAMETRO, (yyvsp[-1].tipo).t, niv, 0, -1)){
             yyerror("Identificador de parametro repetido");
        }
    }
#line 1590 "asin.c"
    break;

  case 25: /* @5: %empty  */
#line 376 "src/asin.y"
    {
        /* === PRÓLOGO DE FUNCIÓN: enlaces de control y reserva de RA === */
        TIPO_ARG argN = crArgNul();

        /* Enlaces de control */
        emite(PUSHFP, argN, argN, argN);
        emite(FPTOP,  argN, argN, argN);

        /* Reserva de espacio para variables locales + temporales.
           Talla desconocida todavía: dejamos el resultado (res) nulo
           y guardamos la instrucción en una lista de pendientes.   */
        emite(INCTOP, argN, argN, argN);
        /* Guardamos la lista de LANS de esta INCTOP en el atributo cent */
        (yyval.cent) = creaLans(si-1);
    }
#line 1610 "asin.c"
    break;

  case 26: /* bloque: TLLAVAB @5 declaVarLocal listInst TRETURN expre TPUNTOCOMA TLLAVCERR  */
#line 392 "src/asin.y"
    {
        /*Verificar tipo del return vs tipo de función*/
        (yyval.funcion).desp        = dvar;
        (yyval.funcion).num_params  = 0;
        (yyval.funcion).tipo_return = (yyvsp[-2].tipo).t;  /* OJO: ahora el return es el 6º símbolo */

        /* === COMPLETAR RESERVA DE LOCALES+TEMPORALES === */
        {
            TIPO_ARG argTalla = crArgEnt(dvar);
            /* La acción intermedia está en la posición 2 de la producción */
            completaLans((yyvsp[-6].cent), argTalla);
        }

        /* === EPÍLOGO DE FUNCIÓN: liberar RA y enlaces de control === */
        {
            TIPO_ARG argN = crArgNul();

            /* Liberar segmento de variables locales y temporales */
            emite(TOPFP, argN, argN, argN);
            emite(FPPOP, argN, argN, argN);

            /* FIN o RET según sea main u otra función */
            if (funcionActual != NULL && strcmp(funcionActual, "main") == 0) {
                emite(FIN, argN, argN, argN);
            } else {
                emite(RET, argN, argN, argN);
            }
        }

        /* Mostrar TdS de esta funcion (global + locales + parámetros) */
        if (verTdS) mostrarTdS();

        /*Descargar el contexto de la función al terminar su bloque */
        descargaContexto(niv);
        niv--;
    }
#line 1651 "asin.c"
    break;

  case 36: /* instExpre: expre TPUNTOCOMA  */
#line 442 "src/asin.y"
                          { (yyval.tipo).t = (yyvsp[-1].tipo).t; }
#line 1657 "asin.c"
    break;

  case 37: /* instExpre: TPUNTOCOMA  */
#line 443 "src/asin.y"
                          { (yyval.tipo).t = T_VACIO; }
#line 1663 "asin.c"
    break;

  case 38: /* instEntSal: TREAD TPARAB TID TPARCERR TPUNTOCOMA  */
#line 447 "src/asin.y"
    {
        SIMB sim = obtTdS((yyvsp[-2].ident));
        if (sim.t == T_ERROR)
            yyerror("Variable no declarada en READ");
        else if (sim.t != T_ENTERO)
            yyerror("El argumento del 'read' debe ser 'entero'");
    }
#line 1675 "asin.c"
    break;

  case 39: /* instEntSal: TPRINT TPARAB expre TPARCERR TPUNTOCOMA  */
#line 455 "src/asin.y"
    {
        /* Verificar que la expresión sea de tipo entero */
        if ((yyvsp[-2].tipo).t != T_ENTERO && (yyvsp[-2].tipo).t != T_ERROR)
            yyerror("La expresion del 'print' debe ser 'entera'");
    }
#line 1685 "asin.c"
    break;

  case 40: /* instSelec: TIF TPARAB expre TPARCERR inst TELSE inst  */
#line 462 "src/asin.y"
    {
        if ((yyvsp[-4].tipo).t != T_LOGICO)
            yyerror("La expresión de la instrucción if-else debe ser de tipo lógico");
    }
#line 1694 "asin.c"
    break;

  case 41: /* instIter: TFOR TPARAB expreOP TPUNTOCOMA expre TPUNTOCOMA expreOP TPARCERR inst  */
#line 469 "src/asin.y"
    {
        /* Verificar que la expresión de la condición sea de tipo lógico (TBOOL) */
        /* La expresión del medio es obligatoria y debe ser de tipo lógico */
        if ((yyvsp[-4].tipo).t != T_LOGICO)
            yyerror("La expresion del 'for' debe ser 'logica'");
    }
#line 1705 "asin.c"
    break;

  case 42: /* expreOP: %empty  */
#line 480 "src/asin.y"
    {
        (yyval.tipo).t = T_VACIO;  /*TIPO POR DEFECTO CUANDO ESTÁ VACÍO*/
    }
#line 1713 "asin.c"
    break;

  case 43: /* expreOP: expre  */
#line 484 "src/asin.y"
    {
        (yyval.tipo).t = (yyvsp[0].tipo).t;  /*SINTETIZA EL TIPO*/
    }
#line 1721 "asin.c"
    break;

  case 44: /* expre: expreLogic  */
#line 490 "src/asin.y"
    {
        (yyval.tipo).t = (yyvsp[0].tipo).t;
    }
#line 1729 "asin.c"
    break;

  case 45: /* expre: TID TASIG expre  */
#line 494 "src/asin.y"
    {   /* Este es el ejemplo que nos han dado*/
        SIMB sim = obtTdS((yyvsp[-2].ident));
        if (sim.t == T_ERROR) yyerror("Objeto no declarado");
        else if (! (((sim.t == T_ENTERO) && ((yyvsp[0].tipo).t == T_ENTERO)) ||
                ((sim.t == T_LOGICO) && ((yyvsp[0].tipo).t == T_LOGICO))) )
                if((yyvsp[0].tipo).t!= T_ERROR)
                    yyerror("Error de tipos en la 'instruccion de asignacion'");
        /* Propagar el tipo de la expresión (puede ser T_ERROR) */
        (yyval.tipo).t = (yyvsp[0].tipo).t;
      }
#line 1744 "asin.c"
    break;

  case 46: /* expre: TID TCORCHAB expre TCORCHCERR TASIG expre  */
#line 505 "src/asin.y"
    {
        SIMB sim = obtTdS((yyvsp[-5].ident));
        if (sim.t == T_ERROR)
            yyerror("Asignación a array no declarado");
        else{
            if(sim.t != T_ARRAY){
                yyerror("La variable debe ser tipo 'array'");
            }
            else {
                /*Verificar que el índice sea entero (si no fue ya error) */
                if ((yyvsp[-3].tipo).t != T_ENTERO && (yyvsp[-3].tipo).t != T_ERROR)
                    yyerror("El indice del 'array' debe ser entero");
                else{
                    DIM info_arr = obtTdA(sim.ref);
                    /*Solo emitir error si la expresión no vino ya marcada como error */
                    if ((yyvsp[0].tipo).t != T_ERROR && info_arr.telem != (yyvsp[0].tipo).t) {
                        yyerror("Error de tipos en la asignacion a un 'array'");
                    }
                }
            }
            
            /*Propagar el tipo (puede ser T_ERROR) */
            (yyval.tipo).t = (yyvsp[0].tipo).t; 
        }
      }
#line 1774 "asin.c"
    break;

  case 47: /* expreLogic: expreIgual  */
#line 533 "src/asin.y"
    {
        (yyval.tipo).t = (yyvsp[0].tipo).t;
    }
#line 1782 "asin.c"
    break;

  case 48: /* expreLogic: expreLogic opLogic expreIgual  */
#line 537 "src/asin.y"
    {
        /*Operaciones lógicas requieren operandos lógicos */
        if ((yyvsp[-2].tipo).t == T_ERROR || (yyvsp[0].tipo).t == T_ERROR) {
            (yyval.tipo).t = T_ERROR;
        } else if ((yyvsp[-2].tipo).t != T_LOGICO || (yyvsp[0].tipo).t != T_LOGICO) {
            yyerror("Error de tipos en expresión lógica");
            (yyval.tipo).t = T_ERROR;
        } else {
            (yyval.tipo).t = T_LOGICO;
        }
    }
#line 1798 "asin.c"
    break;

  case 49: /* expreIgual: expreRel  */
#line 551 "src/asin.y"
    {
        (yyval.tipo).t = (yyvsp[0].tipo).t;
    }
#line 1806 "asin.c"
    break;

  case 50: /* expreIgual: expreIgual opIgual expreRel  */
#line 555 "src/asin.y"
    {
        /*Las comparaciones de igualdad requieren operandos del mismo tipo */
        if ((yyvsp[-2].tipo).t == T_ERROR || (yyvsp[0].tipo).t == T_ERROR) {
            (yyval.tipo).t = T_ERROR;
        } else if ((yyvsp[-2].tipo).t != (yyvsp[0].tipo).t) {
            yyerror("Error de tipos en expresión de igualdad");
            (yyval.tipo).t = T_ERROR;
        } else {
            (yyval.tipo).t = T_LOGICO;
        }
    }
#line 1822 "asin.c"
    break;

  case 51: /* expreRel: expreAd  */
#line 569 "src/asin.y"
    {
        (yyval.tipo).t = (yyvsp[0].tipo).t;
    }
#line 1830 "asin.c"
    break;

  case 52: /* expreRel: expreRel opRel expreAd  */
#line 573 "src/asin.y"
    {
        /* Las relaciones requieren operandos enteros */
        if ((yyvsp[-2].tipo).t == T_ERROR || (yyvsp[0].tipo).t == T_ERROR) {
            (yyval.tipo).t = T_ERROR;
        } else if ((yyvsp[-2].tipo).t != T_ENTERO || (yyvsp[0].tipo).t != T_ENTERO) {
            yyerror("Error de tipos en expresión relacional");
            (yyval.tipo).t = T_ERROR;
        } else {
            (yyval.tipo).t = T_LOGICO;
        }
    }
#line 1846 "asin.c"
    break;

  case 53: /* expreAd: expreMul  */
#line 589 "src/asin.y"
    {
        (yyval.tipo).t = (yyvsp[0].tipo).t;
    }
#line 1854 "asin.c"
    break;

  case 54: /* expreAd: expreAd opAd expreMul  */
#line 593 "src/asin.y"
    {
        /* Suma/resta requieren operandos enteros */
        if ((yyvsp[-2].tipo).t == T_ERROR || (yyvsp[0].tipo).t == T_ERROR) {
            (yyval.tipo).t = T_ERROR;
        } else if ((yyvsp[-2].tipo).t != T_ENTERO || (yyvsp[0].tipo).t != T_ENTERO) {
            yyerror("Error de tipos en 'expresion aditiva'");
            (yyval.tipo).t = T_ERROR;
        } else {
            (yyval.tipo).t = T_ENTERO;
        }
        emite((yyvsp[-1].emite), crArgPos(niv, (yyvsp[-2].tipo).d), crArgPos(niv, (yyvsp[0].tipo).d), crArgPos(niv, (yyval.tipo).d));
    }
#line 1871 "asin.c"
    break;

  case 55: /* expreMul: expreUna  */
#line 608 "src/asin.y"
    {
        (yyval.tipo).t = (yyvsp[0].tipo).t;
    }
#line 1879 "asin.c"
    break;

  case 56: /* expreMul: expreMul opMul expreUna  */
#line 612 "src/asin.y"
    {
        /* Multiplicación/división requieren operandos enteros */
        if ((yyvsp[-2].tipo).t == T_ERROR || (yyvsp[0].tipo).t == T_ERROR) {
            (yyval.tipo).t = T_ERROR;
        } else if ((yyvsp[-2].tipo).t != T_ENTERO || (yyvsp[0].tipo).t != T_ENTERO) {
            yyerror("Error de tipos en 'expresion multiplicativa'");
            (yyval.tipo).t = T_ERROR; /* Propagar que hubo un error de tipos */
        } else {
            (yyval.tipo).t = T_ENTERO;
        }
    }
#line 1895 "asin.c"
    break;

  case 57: /* expreUna: expreSufi  */
#line 626 "src/asin.y"
    {
        (yyval.tipo).t = (yyvsp[0].tipo).t;
    }
#line 1903 "asin.c"
    break;

  case 58: /* expreUna: opUna expreUna  */
#line 630 "src/asin.y"
    {
        /*Operadores unarios conservan el tipo (solo para enteros) */
        if ((yyvsp[0].tipo).t == T_ERROR) {
            (yyval.tipo).t = T_ERROR;
        } else if ((yyvsp[0].tipo).t != T_ENTERO) {
            yyerror("Error de tipos en expresión unaria");
            (yyval.tipo).t = T_ERROR;
        } else {
            (yyval.tipo).t = T_ENTERO;
        }
    }
#line 1919 "asin.c"
    break;

  case 59: /* expreSufi: const  */
#line 644 "src/asin.y"
    {
        /*Propagar el tipo de la constante (entero o lógico) */
        (yyval.tipo).t = (yyvsp[0].tipo).t;
    }
#line 1928 "asin.c"
    break;

  case 60: /* expreSufi: TPARAB expre TPARCERR  */
#line 649 "src/asin.y"
    {
        (yyval.tipo).t = (yyvsp[-1].tipo).t;
    }
#line 1936 "asin.c"
    break;

  case 61: /* expreSufi: TID  */
#line 653 "src/asin.y"
    {
        SIMB sim = obtTdS((yyvsp[0].ident));
        if (sim.t == T_ERROR)
            yyerror("Uso de variable no declarada");
        (yyval.tipo).t = sim.t; 
      }
#line 1947 "asin.c"
    break;

  case 62: /* expreSufi: TID TCORCHAB expre TCORCHCERR  */
#line 660 "src/asin.y"
    {
        SIMB sim = obtTdS((yyvsp[-3].ident));
        if (sim.t == T_ERROR)
            yyerror("Uso de array no declarado");

        /*Verificar que el índice sea entero */
        if ((yyvsp[-1].tipo).t != T_ENTERO && (yyvsp[-1].tipo).t != T_ERROR)
            yyerror("El indice del \"array\" debe ser entero");
        (yyval.tipo).t = sim.t;
      }
#line 1962 "asin.c"
    break;

  case 63: /* expreSufi: TID TPARAB paramAct TPARCERR  */
#line 671 "src/asin.y"
    {
        SIMB sim = obtTdS((yyvsp[-3].ident));
        if (sim.t == T_ERROR) {
            yyerror("Uso de función no declarada");
        } else {
            /* Comprobar que el dominio de los parametros actuales coincide con el de la funcion */
            if (!cmpDom((yyvsp[-1].paramInfo).ref, sim.ref)) {
                yyerror("Parámetros de la función no coinciden con la declaración");
            }
        }
        (yyval.tipo).t = sim.t;
    }
#line 1979 "asin.c"
    break;

  case 64: /* paramAct: %empty  */
#line 687 "src/asin.y"
    {
        /* Dominio vacío: 0 parámetros actuales */
        (yyval.paramInfo).num_params = 0;
        (yyval.paramInfo).ref        = insTdD(-1, T_VACIO);
        (yyval.paramInfo).talla      = 0;
    }
#line 1990 "asin.c"
    break;

  case 65: /* paramAct: listParamAct  */
#line 694 "src/asin.y"
    {
        /* Copiamos el dominio construido en listParamAct */
        (yyval.paramInfo).num_params = (yyvsp[0].paramInfo).num_params;
        (yyval.paramInfo).ref        = (yyvsp[0].paramInfo).ref;
        (yyval.paramInfo).talla      = (yyvsp[0].paramInfo).talla;
    }
#line 2001 "asin.c"
    break;

  case 66: /* listParamAct: expre  */
#line 703 "src/asin.y"
    {
        /*Último argumento --> crea nuevo dominio */
        (yyval.paramInfo).num_params = 1;
        (yyval.paramInfo).ref = insTdD(-1, (yyvsp[0].tipo).t);
        (yyval.paramInfo).talla = TALLA_TIPO_SIMPLE;
    }
#line 2012 "asin.c"
    break;

  case 67: /* listParamAct: expre TCOMA listParamAct  */
#line 710 "src/asin.y"
        {(yyval.paramInfo).num_params = (yyvsp[0].paramInfo).num_params + 1;    // suma al resto de parámetros
        (yyval.paramInfo).ref = insTdD((yyvsp[0].paramInfo).ref, (yyvsp[-2].tipo).t);          // encadena dominios
        (yyval.paramInfo).talla = TALLA_TIPO_SIMPLE;}
#line 2020 "asin.c"
    break;

  case 68: /* opLogic: TAND  */
#line 720 "src/asin.y"
         {(yyval.emite).e = EMULT;}
#line 2026 "asin.c"
    break;

  case 69: /* opLogic: TOR  */
#line 720 "src/asin.y"
                              {(yyval.emite).e = ESUM;}
#line 2032 "asin.c"
    break;

  case 70: /* opIgual: TIGUALQUE  */
#line 722 "src/asin.y"
              {(yyval.emite).e = EIGUAL;}
#line 2038 "asin.c"
    break;

  case 71: /* opIgual: TDISTINTOQUE  */
#line 722 "src/asin.y"
                                             {(yyval.emite).e = EDIST;}
#line 2044 "asin.c"
    break;

  case 72: /* opRel: TMAYORQUE  */
#line 724 "src/asin.y"
              {(yyval.emite).e = EMAY;}
#line 2050 "asin.c"
    break;

  case 73: /* opRel: TMENORQUE  */
#line 724 "src/asin.y"
                                        {(yyval.emite).e = EMEN;}
#line 2056 "asin.c"
    break;

  case 74: /* opRel: TMAYORIGUAL  */
#line 724 "src/asin.y"
                                                                     {(yyval.emite).e = EMAYEQ;}
#line 2062 "asin.c"
    break;

  case 75: /* opRel: TMENORIGUAL  */
#line 724 "src/asin.y"
                                                                                                   {(yyval.emite).e = EMENEQ;}
#line 2068 "asin.c"
    break;

  case 76: /* opAd: TMAS  */
#line 727 "src/asin.y"
         {(yyval.emite).e = ESUM;}
#line 2074 "asin.c"
    break;

  case 77: /* opAd: TMENOS  */
#line 727 "src/asin.y"
                                {(yyval.emite).e = EDIF;}
#line 2080 "asin.c"
    break;

  case 78: /* opMul: TMULT  */
#line 729 "src/asin.y"
          {(yyval.emite).e = EMULT;}
#line 2086 "asin.c"
    break;

  case 79: /* opMul: TDIV  */
#line 729 "src/asin.y"
                                {(yyval.emite).e = EDIVI;}
#line 2092 "asin.c"
    break;

  case 80: /* opUna: TMAS  */
#line 731 "src/asin.y"
         {(yyval.emite).e = ESUM;}
#line 2098 "asin.c"
    break;

  case 81: /* opUna: TMENOS  */
#line 731 "src/asin.y"
                                {(yyval.emite).e = EDIF;}
#line 2104 "asin.c"
    break;

  case 82: /* opUna: TEXCL  */
#line 731 "src/asin.y"
                                                      {(yyval.emite).e = ESIG;}
#line 2110 "asin.c"
    break;


#line 2114 "asin.c"

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

#line 733 "src/asin.y"

