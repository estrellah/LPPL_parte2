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
    int numParamActual = 0;   /* nº de parámetros de la función que se está declarando */

    /* nombre de la función que se está compilando ahora */
    char *funcionActual = NULL;

#line 101 "asin.c"

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
  YYSYMBOL_listDecla = 40,                 /* listDecla  */
  YYSYMBOL_decla = 41,                     /* decla  */
  YYSYMBOL_declaVar = 42,                  /* declaVar  */
  YYSYMBOL_declaFunc = 43,                 /* declaFunc  */
  YYSYMBOL_44_2 = 44,                      /* $@2  */
  YYSYMBOL_45_3 = 45,                      /* $@3  */
  YYSYMBOL_const = 46,                     /* const  */
  YYSYMBOL_tipoSimp = 47,                  /* tipoSimp  */
  YYSYMBOL_paramForm = 48,                 /* paramForm  */
  YYSYMBOL_listParamForm = 49,             /* listParamForm  */
  YYSYMBOL_bloque = 50,                    /* bloque  */
  YYSYMBOL_51_4 = 51,                      /* @4  */
  YYSYMBOL_declaVarLocal = 52,             /* declaVarLocal  */
  YYSYMBOL_listInst = 53,                  /* listInst  */
  YYSYMBOL_inst = 54,                      /* inst  */
  YYSYMBOL_instExpre = 55,                 /* instExpre  */
  YYSYMBOL_instEntSal = 56,                /* instEntSal  */
  YYSYMBOL_instSelec = 57,                 /* instSelec  */
  YYSYMBOL_58_5 = 58,                      /* @5  */
  YYSYMBOL_59_6 = 59,                      /* @6  */
  YYSYMBOL_instIter = 60,                  /* instIter  */
  YYSYMBOL_61_7 = 61,                      /* @7  */
  YYSYMBOL_62_8 = 62,                      /* $@8  */
  YYSYMBOL_expreOP = 63,                   /* expreOP  */
  YYSYMBOL_expre = 64,                     /* expre  */
  YYSYMBOL_expreLogic = 65,                /* expreLogic  */
  YYSYMBOL_expreIgual = 66,                /* expreIgual  */
  YYSYMBOL_expreRel = 67,                  /* expreRel  */
  YYSYMBOL_expreAd = 68,                   /* expreAd  */
  YYSYMBOL_expreMul = 69,                  /* expreMul  */
  YYSYMBOL_expreUna = 70,                  /* expreUna  */
  YYSYMBOL_expreSufi = 71,                 /* expreSufi  */
  YYSYMBOL_72_9 = 72,                      /* $@9  */
  YYSYMBOL_paramAct = 73,                  /* paramAct  */
  YYSYMBOL_listParamAct = 74,              /* listParamAct  */
  YYSYMBOL_opLogic = 75,                   /* opLogic  */
  YYSYMBOL_opIgual = 76,                   /* opIgual  */
  YYSYMBOL_opRel = 77,                     /* opRel  */
  YYSYMBOL_opAd = 78,                      /* opAd  */
  YYSYMBOL_opMul = 79,                     /* opMul  */
  YYSYMBOL_opUna = 80,                     /* opUna  */
  YYSYMBOL_marca = 81                      /* marca  */
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
#define YYLAST   152

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

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
       0,   122,   122,   122,   172,   173,   177,   178,   181,   191,
     204,   224,   234,   223,   270,   282,   294,   309,   310,   314,
     318,   325,   335,   349,   348,   406,   408,   410,   412,   415,
     416,   417,   418,   419,   422,   428,   437,   449,   464,   483,
     463,   514,   541,   510,   582,   587,   596,   602,   625,   660,
     666,   686,   692,   712,   718,   739,   745,   766,   772,   792,
     798,   844,   850,   856,   865,   898,   897,   947,   952,   962,
     975,  1000,  1000,  1002,  1002,  1004,  1004,  1004,  1004,  1007,
    1007,  1009,  1009,  1011,  1011,  1011,  1016
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
  "programa", "$@1", "listDecla", "decla", "declaVar", "declaFunc", "$@2",
  "$@3", "const", "tipoSimp", "paramForm", "listParamForm", "bloque", "@4",
  "declaVarLocal", "listInst", "inst", "instExpre", "instEntSal",
  "instSelec", "@5", "@6", "instIter", "@7", "$@8", "expreOP", "expre",
  "expreLogic", "expreIgual", "expreRel", "expreAd", "expreMul",
  "expreUna", "expreSufi", "$@9", "paramAct", "listParamAct", "opLogic",
  "opIgual", "opRel", "opAd", "opMul", "opUna", "marca", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-127)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
    -127,    25,   -22,  -127,  -127,  -127,   -22,  -127,  -127,  -127,
     -32,  -127,    62,     9,    -4,  -127,    30,  -127,  -127,  -127,
      19,    37,   -22,  -127,    43,    16,    52,    48,  -127,  -127,
    -127,   -22,    59,    45,  -127,  -127,  -127,  -127,   -22,  -127,
      50,    31,    62,  -127,  -127,  -127,    97,  -127,  -127,    78,
      84,    86,    91,    97,    56,  -127,  -127,  -127,  -127,  -127,
    -127,    92,    36,    33,    64,   111,   112,  -127,  -127,   104,
     106,     1,    88,    97,    97,    97,   103,    97,  -127,    97,
    -127,  -127,  -127,   104,  -127,  -127,   104,  -127,  -127,  -127,
    -127,   104,  -127,  -127,   104,  -127,  -127,   104,    -9,  -127,
    -127,  -127,   109,   110,   113,   107,  -127,   115,  -127,    97,
     114,    33,    64,   111,   112,  -127,    97,   116,   117,  -127,
    -127,  -127,   105,   120,  -127,   125,   121,  -127,  -127,    67,
      97,    97,  -127,    97,  -127,  -127,   119,  -127,  -127,   118,
    -127,    67,  -127,  -127,    97,   127,  -127,    67,  -127
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,    17,    18,     3,     4,     6,     7,
       0,     5,    11,     0,     0,     8,     0,    16,    15,    14,
       0,     0,    19,     9,     0,     0,     0,    20,    10,    21,
      12,     0,     0,     0,    23,    13,    22,    25,    27,    26,
       0,     0,     0,    83,    84,    85,     0,    27,    35,     0,
       0,     0,     0,     0,    63,    61,    28,    30,    31,    32,
      33,     0,    46,    49,    51,    53,    55,    57,    59,     0,
       0,     0,     0,     0,     0,    44,     0,     0,    65,     0,
      34,    71,    72,     0,    73,    74,     0,    75,    76,    77,
      78,     0,    79,    80,     0,    82,    81,     0,    63,    60,
      62,    29,     0,     0,     0,     0,    45,     0,    47,    67,
       0,    50,    52,    54,    56,    58,     0,     0,     0,    38,
      86,    24,    69,     0,    68,    64,     0,    36,    37,     0,
       0,     0,    66,     0,    64,    39,     0,    70,    48,     0,
      41,     0,    86,    40,    44,     0,    42,     0,    43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,  -127,  -127,   123,   108,  -127,  -127,  -127,   130,
      20,  -127,  -127,  -127,  -127,  -127,    98,  -126,  -127,  -127,
    -127,  -127,  -127,  -127,  -127,  -127,     0,   -46,  -127,    65,
      61,    58,    57,   -67,  -127,  -127,  -127,    21,  -127,  -127,
    -127,  -127,  -127,  -127,     8
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     6,     7,     8,     9,    16,    32,    55,
      10,    26,    27,    35,    37,    38,    41,    56,    57,    58,
      59,   129,   139,    60,   142,   147,   105,    61,    62,    63,
      64,    65,    66,    67,    68,   109,   123,   124,    83,    86,
      91,    94,    97,    69,   130
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      70,    12,    99,   135,    78,    43,    44,    76,   116,    45,
      17,    18,     4,     5,    46,   143,    47,   101,    17,    18,
      48,   148,    49,    50,    51,     3,    52,   103,   104,   106,
     115,   108,    21,   110,    54,    43,    44,    19,    23,    45,
      17,    18,    25,    22,    46,    19,    47,    81,    82,    29,
      48,    33,    49,    50,    51,    24,    52,    53,    40,    77,
      84,    85,    28,   122,    54,    13,    30,    19,    31,    78,
     126,    43,    44,    79,    34,    45,    17,    18,    36,    14,
      46,    15,    47,    42,   136,   122,    48,   138,    49,    50,
      51,    72,    52,    87,    88,    89,    90,    73,   106,    74,
      54,    43,    44,    19,    75,    45,    17,    18,    43,    44,
      46,    80,    45,    17,    18,    92,    93,    46,    95,    96,
     100,   102,   107,   117,   118,   131,   120,   119,   133,    11,
      54,   121,   125,    19,   132,   127,   128,    98,   140,   134,
      19,   146,   141,    20,   145,    71,    39,   112,   111,   113,
     144,   114,   137
};

static const yytype_uint8 yycheck[] =
{
      46,    33,    69,   129,    13,     4,     5,    53,    17,     8,
       9,    10,    34,    35,    13,   141,    15,    16,     9,    10,
      19,   147,    21,    22,    23,     0,    25,    73,    74,    75,
      97,    77,    36,    79,    33,     4,     5,    36,    19,     8,
       9,    10,    22,    13,    13,    36,    15,    11,    12,    33,
      19,    31,    21,    22,    23,    18,    25,    26,    38,     3,
      27,    28,    19,   109,    33,     3,    14,    36,    20,    13,
     116,     4,     5,    17,    15,     8,     9,    10,    33,    17,
      13,    19,    15,    33,   130,   131,    19,   133,    21,    22,
      23,    13,    25,    29,    30,    31,    32,    13,   144,    13,
      33,     4,     5,    36,    13,     8,     9,    10,     4,     5,
      13,    19,     8,     9,    10,     4,     5,    13,     6,     7,
      14,    33,    19,    14,    14,    20,    19,    14,     3,     6,
      33,    16,    18,    36,    14,    19,    19,    33,    19,    18,
      36,    14,    24,    13,   144,    47,    38,    86,    83,    91,
     142,    94,   131
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    39,     0,    34,    35,    40,    41,    42,    43,
      47,    41,    33,     3,    17,    19,    44,     9,    10,    36,
      46,    36,    13,    19,    18,    47,    48,    49,    19,    33,
      14,    20,    45,    47,    15,    50,    33,    51,    52,    42,
      47,    53,    33,     4,     5,     8,    13,    15,    19,    21,
      22,    23,    25,    26,    33,    46,    54,    55,    56,    57,
      60,    64,    65,    66,    67,    68,    69,    70,    71,    80,
      64,    53,    13,    13,    13,    13,    64,     3,    13,    17,
      19,    11,    12,    75,    27,    28,    76,    29,    30,    31,
      32,    77,     4,     5,    78,     6,     7,    79,    33,    70,
      14,    16,    33,    64,    64,    63,    64,    19,    64,    72,
      64,    66,    67,    68,    69,    70,    17,    14,    14,    14,
      19,    16,    64,    73,    74,    18,    64,    19,    19,    58,
      81,    20,    14,     3,    18,    54,    64,    74,    64,    59,
      19,    24,    61,    54,    81,    63,    14,    62,    54
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    39,    38,    40,    40,    41,    41,    42,    42,
      42,    44,    45,    43,    46,    46,    46,    47,    47,    48,
      48,    49,    49,    51,    50,    52,    52,    53,    53,    54,
      54,    54,    54,    54,    55,    55,    56,    56,    58,    59,
      57,    61,    62,    60,    63,    63,    64,    64,    64,    65,
      65,    66,    66,    67,    67,    68,    68,    69,    69,    70,
      70,    71,    71,    71,    71,    72,    71,    73,    73,    74,
      74,    75,    75,    76,    76,    77,    77,    77,    77,    78,
      78,    79,    79,    80,    80,    80,    81
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     3,     5,
       6,     0,     0,     8,     1,     1,     1,     1,     1,     0,
       1,     2,     4,     0,     8,     0,     2,     0,     2,     3,
       1,     1,     1,     1,     2,     1,     5,     5,     0,     0,
       9,     0,     0,    13,     0,     1,     1,     3,     6,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       2,     1,     3,     1,     4,     0,     5,     0,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0
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
#line 122 "src/asin.y"
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
#line 1294 "asin.c"
    break;

  case 3: /* programa: $@1 listDecla  */
#line 144 "src/asin.y"
    {
        /* ========= FINAL DEL PROGRAMA ========= */

        if (verTdS) mostrarTdS();

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
    }
#line 1324 "asin.c"
    break;

  case 8: /* declaVar: tipoSimp TID TPUNTOCOMA  */
#line 182 "src/asin.y"
    { 
        if (!insTdS(strdup((yyvsp[-1].ident)), VARIABLE, (yyvsp[-2].tipo).t, niv, dvar, -1))
            yyerror("Identificador de variable repetido");
        else {
            dvar += TALLA_TIPO_SIMPLE;
            if (niv == 0)
                tallaGlobales += TALLA_TIPO_SIMPLE;
        }
    }
#line 1338 "asin.c"
    break;

  case 9: /* declaVar: tipoSimp TID TASIG const TPUNTOCOMA  */
#line 192 "src/asin.y"
    {
        if (!insTdS(strdup((yyvsp[-3].ident)), VARIABLE, (yyvsp[-4].tipo).t, niv, dvar, -1))
            yyerror("Identificador de variable repetido");
        else {
            if ((yyvsp[-4].tipo).t != (yyvsp[-1].exp).t)
                yyerror("Error de tipos en la inicializacion de la variable");
            /* (Opcional) podrías generar aquí EASIG para inicializarla */
            dvar += TALLA_TIPO_SIMPLE;
            if (niv == 0)
                tallaGlobales += TALLA_TIPO_SIMPLE;
        }
    }
#line 1355 "asin.c"
    break;

  case 10: /* declaVar: tipoSimp TID TCORCHAB TCTE TCORCHCERR TPUNTOCOMA  */
#line 205 "src/asin.y"
    {
        int talla_arr = (yyvsp[-2].cent);
        if(talla_arr <= 0){
            yyerror("Talla inapropiada del array");
        } else {
            int ref = insTdA((yyvsp[-5].tipo).t, talla_arr);
            if (!insTdS(strdup((yyvsp[-4].ident)), VARIABLE, T_ARRAY, niv, dvar, ref))
                yyerror("Identificador del array repetido");
            else {
                dvar += talla_arr * TALLA_TIPO_SIMPLE;
                if (niv == 0)
                    tallaGlobales += talla_arr * TALLA_TIPO_SIMPLE;
            }
        }
    }
#line 1375 "asin.c"
    break;

  case 11: /* $@2: %empty  */
#line 224 "src/asin.y"
    {
        niv++;
        cargaContexto(niv);
        dvar = 0;
        funcionActual = strdup((yyvsp[0].ident));
        if (strcmp((yyvsp[0].ident), "main") == 0) {
            etqMain = si;
        }
    }
#line 1389 "asin.c"
    break;

  case 12: /* $@3: %empty  */
#line 234 "src/asin.y"
    {
        /* <<< AÑADIDO: nº de parámetros de esta función >>> */
        numParamActual = (yyvsp[-1].paramInfo).num_params;

        if (strcmp((yyvsp[-4].ident), "main") == 0) {
            mainCount++;
        }

        SIMB simb = obtTdS((yyvsp[-4].ident));
        if (simb.t != T_ERROR) {
            yyerror("Función repetida");
            errorDeclFuncActual = 1;
        } else if (!insTdS(strdup((yyvsp[-4].ident)), FUNCION, (yyvsp[-5].tipo).t, niv-1, si, (yyvsp[-1].paramInfo).ref)) {
            yyerror("Función repetida");
            errorDeclFuncActual = 1;
        } else {
            errorDeclFuncActual = 0;
        }
    }
#line 1413 "asin.c"
    break;

  case 13: /* declaFunc: tipoSimp TID $@2 TPARAB paramForm TPARCERR $@3 bloque  */
#line 254 "src/asin.y"
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
#line 1431 "asin.c"
    break;

  case 14: /* const: TCTE  */
#line 271 "src/asin.y"
      {
        /* constante entera: tipo ENTERO, creamos un temporal con ese valor */
        (yyval.exp).t = T_ENTERO;
        (yyval.exp).n = niv;
        (yyval.exp).d = creaVarTemp();

        TIPO_ARG aVal = crArgEnt((yyvsp[0].cent));        /* valor entero de la constante */
        TIPO_ARG aRes = crArgPos(niv, (yyval.exp).d); /* posición del temporal        */

        emite(EASIG, aVal, crArgNul(), aRes);
      }
#line 1447 "asin.c"
    break;

  case 15: /* const: TTRUE  */
#line 283 "src/asin.y"
      {
        /* true: 1 */
        (yyval.exp).t = T_LOGICO;
        (yyval.exp).n = niv;
        (yyval.exp).d = creaVarTemp();

        TIPO_ARG aVal = crArgEnt(1);
        TIPO_ARG aRes = crArgPos(niv, (yyval.exp).d);

        emite(EASIG, aVal, crArgNul(), aRes);
      }
#line 1463 "asin.c"
    break;

  case 16: /* const: TFALSE  */
#line 295 "src/asin.y"
      {
        /* false: 0 */
        (yyval.exp).t = T_LOGICO;
        (yyval.exp).n = niv;
        (yyval.exp).d = creaVarTemp();

        TIPO_ARG aVal = crArgEnt(0);
        TIPO_ARG aRes = crArgPos(niv, (yyval.exp).d);

        emite(EASIG, aVal, crArgNul(), aRes);
      }
#line 1479 "asin.c"
    break;

  case 17: /* tipoSimp: TINT  */
#line 309 "src/asin.y"
              { (yyval.tipo).t = T_ENTERO; }
#line 1485 "asin.c"
    break;

  case 18: /* tipoSimp: TBOOL  */
#line 310 "src/asin.y"
              { (yyval.tipo).t = T_LOGICO; }
#line 1491 "asin.c"
    break;

  case 19: /* paramForm: %empty  */
#line 314 "src/asin.y"
    { 
        (yyval.paramInfo).ref = insTdD(-1, T_VACIO);
        (yyval.paramInfo).num_params = 0;
    }
#line 1500 "asin.c"
    break;

  case 20: /* paramForm: listParamForm  */
#line 318 "src/asin.y"
                    { 
        (yyval.paramInfo).num_params = (yyvsp[0].paramInfo).num_params; 
        (yyval.paramInfo).ref = (yyvsp[0].paramInfo).ref;
        }
#line 1509 "asin.c"
    break;

  case 21: /* listParamForm: tipoSimp TID  */
#line 326 "src/asin.y"
    {
        (yyval.paramInfo).num_params = 1;
        (yyval.paramInfo).talla = TALLA_TIPO_SIMPLE+ TALLA_SEGENLACES;
        (yyval.paramInfo).ref = insTdD(-1, (yyvsp[-1].tipo).t); 
        
        if(!insTdS(strdup((yyvsp[0].ident)), PARAMETRO, (yyvsp[-1].tipo).t, niv, 0, -1)){
            yyerror("Identificador de parametro repetido");
        }
    }
#line 1523 "asin.c"
    break;

  case 22: /* listParamForm: listParamForm TCOMA tipoSimp TID  */
#line 336 "src/asin.y"
    {
        (yyval.paramInfo).ref = insTdD((yyvsp[-3].paramInfo).ref, (yyvsp[-1].tipo).t);
        (yyval.paramInfo).num_params = (yyvsp[-3].paramInfo).num_params + 1;
        (yyval.paramInfo).talla = (yyvsp[-3].paramInfo).talla + TALLA_TIPO_SIMPLE;

        if (!insTdS(strdup((yyvsp[0].ident)), PARAMETRO, (yyvsp[-1].tipo).t, niv, 0, -1)){
             yyerror("Identificador de parametro repetido");
        }
    }
#line 1537 "asin.c"
    break;

  case 23: /* @4: %empty  */
#line 349 "src/asin.y"
    {
        TIPO_ARG argN = crArgNul();
        emite(PUSHFP, argN, argN, argN);
        emite(FPTOP,  argN, argN, argN);

        emite(INCTOP, argN, argN, argN);
        (yyval.cent) = creaLans(si-1);
    }
#line 1550 "asin.c"
    break;

  case 24: /* bloque: TLLAVAB @4 declaVarLocal listInst TRETURN expre TPUNTOCOMA TLLAVCERR  */
#line 358 "src/asin.y"
    {
        (yyval.funcion).desp        = dvar;
        (yyval.funcion).num_params  = 0;
        (yyval.funcion).tipo_return = (yyvsp[-2].exp).t;

        /* Completar INCTOP locales+temporales */
        {
            TIPO_ARG argTalla = crArgEnt(dvar);
            completaLans((yyvsp[-6].cent), argTalla);
        }

        /* === ESTRELLA: guardar valor de retorno en el RA ===
           Convenio: antes de llamar a la función se ha hecho:
             EPUSH 0           ; hueco valor retorno
             EPUSH arg_k
             ...
             EPUSH arg_1
           Con ese convenio, tras hacer CALL/PUSHFP/FPTOP,
           el hueco de retorno queda a -(numParamActual + 2)
           respecto de fp. */
        if ((yyvsp[-2].exp).t != T_ERROR) {
            int despRet = -(numParamActual + 2);
            TIPO_ARG aSrc = crArgPos((yyvsp[-2].exp).n, (yyvsp[-2].exp).d);
            TIPO_ARG aN   = crArgNul();
            TIPO_ARG aDst = crArgPos(niv, despRet);
            emite(EASIG, aSrc, aN, aDst);
        }

        /* === EPÍLOGO DE FUNCIÓN === */
        {
            TIPO_ARG argN = crArgNul();

            emite(TOPFP, argN, argN, argN);
            emite(FPPOP, argN, argN, argN);

            if (funcionActual != NULL && strcmp(funcionActual, "main") == 0) {
                emite(FIN, argN, argN, argN);
            } else {
                emite(RET, argN, argN, argN);
            }
        }

        if (verTdS) mostrarTdS();
        descargaContexto(niv);
        niv--;
    }
#line 1601 "asin.c"
    break;

  case 34: /* instExpre: expre TPUNTOCOMA  */
#line 423 "src/asin.y"
      {
        (yyval.exp).t = (yyvsp[-1].exp).t;
        (yyval.exp).d = (yyvsp[-1].exp).d;
        (yyval.exp).n = (yyvsp[-1].exp).n;
      }
#line 1611 "asin.c"
    break;

  case 35: /* instExpre: TPUNTOCOMA  */
#line 429 "src/asin.y"
      {
        (yyval.exp).t = T_VACIO;
        (yyval.exp).d = 0;
        (yyval.exp).n = 0;
      }
#line 1621 "asin.c"
    break;

  case 36: /* instEntSal: TREAD TPARAB TID TPARCERR TPUNTOCOMA  */
#line 438 "src/asin.y"
    {
        SIMB sim = obtTdS((yyvsp[-2].ident));
        if (sim.t == T_ERROR)
            yyerror("Variable no declarada en READ");
        else if (sim.t != T_ENTERO)
            yyerror("El argumento del 'read' debe ser 'entero'");
        else {
            TIPO_ARG aN = crArgNul();
            emite(EREAD, aN, aN, crArgPos(sim.n, sim.d));
        }
    }
#line 1637 "asin.c"
    break;

  case 37: /* instEntSal: TPRINT TPARAB expre TPARCERR TPUNTOCOMA  */
#line 450 "src/asin.y"
    {
        if ((yyvsp[-2].exp).t != T_ENTERO && (yyvsp[-2].exp).t != T_ERROR)
            yyerror("La expresion del 'print' debe ser 'entera'");
        else if ((yyvsp[-2].exp).t != T_ERROR) {
            TIPO_ARG aN = crArgNul();
            emite(EWRITE, crArgPos((yyvsp[-2].exp).n, (yyvsp[-2].exp).d), aN, aN);
        }
    }
#line 1650 "asin.c"
    break;

  case 38: /* @5: %empty  */
#line 464 "src/asin.y"
    {
        if ((yyvsp[-1].exp).t != T_LOGICO && (yyvsp[-1].exp).t != T_ERROR)
            yyerror("La expresión de la instrucción if-else debe ser de tipo lógico");

        if ((yyvsp[-1].exp).t != T_ERROR) {
            TIPO_ARG a0   = crArgEnt(0);
            TIPO_ARG aNul = crArgNul();

            /* si cond == 0 saltaremos al ELSE (aún sin etiqueta) */
            emite(EIGUAL,
                  crArgPos((yyvsp[-1].exp).n, (yyvsp[-1].exp).d),
                  a0,
                  aNul);
            (yyval.cent) = creaLans(si-1);  /* lista de saltos al else */
        } else {
            (yyval.cent) = -1;
        }
    }
#line 1673 "asin.c"
    break;

  case 39: /* @6: %empty  */
#line 483 "src/asin.y"
    {
        /* tras el then: salto incondicional al final del if-else */
        TIPO_ARG aN = crArgNul();
        emite(GOTOS, aN, aN, aN);

        /* parchear saltos de la condición hacia el inicio del else (ahora si) */
        if ((yyvsp[-1].cent) != -1) {
            TIPO_ARG aEtqElse = crArgEtq(si);
            completaLans((yyvsp[-1].cent), aEtqElse);
        }

        (yyval.cent) = creaLans(si-1);   /* lista de saltos desde el then al final */
    }
#line 1691 "asin.c"
    break;

  case 40: /* instSelec: TIF TPARAB expre TPARCERR @5 inst @6 TELSE inst  */
#line 498 "src/asin.y"
    {
        /* completar saltos al final del if-else */
        if ((yyvsp[-2].cent) != -1) {
            TIPO_ARG aEtqFin = crArgEtq(si);
            completaLans((yyvsp[-2].cent), aEtqFin);
        }
    }
#line 1703 "asin.c"
    break;

  case 41: /* @7: %empty  */
#line 514 "src/asin.y"
    {
        /* Punto tras evaluar la condición */
        (yyval.listas).ltrue  = -1;
        (yyval.listas).lfalse = -1;

        if ((yyvsp[-1].exp).t != T_LOGICO && (yyvsp[-1].exp).t != T_ERROR)
            yyerror("La expresion del 'for' debe ser 'logica'");

        if ((yyvsp[-1].exp).t != T_ERROR) {
            TIPO_ARG a0   = crArgEnt(0);
            TIPO_ARG aNul = crArgNul();

            /* si cond == 0 -> salida del bucle (Lend, aún desconocida) */
            emite(EIGUAL,
                  crArgPos((yyvsp[-1].exp).n, (yyvsp[-1].exp).d),
                  a0,
                  aNul);
            (yyval.listas).lfalse = creaLans(si-1);

            /* si cond != 0 -> ir al cuerpo (Lbody, aún desconocida) */
            emite(GOTOS, aNul, aNul, aNul);
            (yyval.listas).ltrue = creaLans(si-1);
        }
    }
#line 1732 "asin.c"
    break;

  case 42: /* $@8: %empty  */
#line 541 "src/asin.y"
    {
        /* Estamos justo antes del cuerpo: si cond es true, venimos aquí */

        /* Parchear saltos verdaderos al comienzo del cuerpo (etiqueta actual) */
        if ((yyvsp[-3].listas).ltrue != -1) {
            TIPO_ARG aBody = crArgEtq(si);
            completaLans((yyvsp[-3].listas).ltrue, aBody);
        }

        /* Desde el final del update, volver a la condición */
        {
            TIPO_ARG aN    = crArgNul();
            TIPO_ARG aCond = crArgEtq((yyvsp[-6].cent));
            emite(GOTOS, aN, aN, aCond);
        }
    }
#line 1753 "asin.c"
    break;

  case 43: /* instIter: TFOR TPARAB expreOP TPUNTOCOMA marca expre TPUNTOCOMA @7 marca expreOP TPARCERR $@8 inst  */
#line 558 "src/asin.y"
    {
        /* Al final del cuerpo:
           1) ir al inicio del update
           2) completar saltos de salida (cond == 0) al punto actual (fin) */

        /* 1) goto inicio update ($9) */
        {
            TIPO_ARG aN   = crArgNul();
            TIPO_ARG aUpd = crArgEtq((yyvsp[-4].cent));
            emite(GOTOS, aN, aN, aUpd);
        }

        /* 2) completar lista de falsos (salida del bucle) */
        if ((yyvsp[-5].listas).lfalse != -1) {
            TIPO_ARG aEnd = crArgEtq(si);
            completaLans((yyvsp[-5].listas).lfalse, aEnd);
        }
    }
#line 1776 "asin.c"
    break;

  case 44: /* expreOP: %empty  */
#line 582 "src/asin.y"
    {
        (yyval.exp).t = T_VACIO;
        (yyval.exp).d = 0;
        (yyval.exp).n = 0;
    }
#line 1786 "asin.c"
    break;

  case 45: /* expreOP: expre  */
#line 588 "src/asin.y"
    {
        (yyval.exp).t = (yyvsp[0].exp).t;
        (yyval.exp).d = (yyvsp[0].exp).d;
        (yyval.exp).n = (yyvsp[0].exp).n;
    }
#line 1796 "asin.c"
    break;

  case 46: /* expre: expreLogic  */
#line 597 "src/asin.y"
    {
        (yyval.exp).t = (yyvsp[0].exp).t;
        (yyval.exp).d = (yyvsp[0].exp).d;
        (yyval.exp).n = (yyvsp[0].exp).n;
    }
#line 1806 "asin.c"
    break;

  case 47: /* expre: TID TASIG expre  */
#line 603 "src/asin.y"
    {   
        SIMB sim = obtTdS((yyvsp[-2].ident));
        if (sim.t == T_ERROR) {
            yyerror("Objeto no declarado");
            (yyval.exp).t = T_ERROR;
        } else if (!(((sim.t == T_ENTERO) && ((yyvsp[0].exp).t == T_ENTERO)) ||
                     ((sim.t == T_LOGICO) && ((yyvsp[0].exp).t == T_LOGICO)))) {
            if ((yyvsp[0].exp).t != T_ERROR)
                yyerror("Error de tipos en la 'instruccion de asignacion'");
            (yyval.exp).t = T_ERROR;
        } else {
            /* código de asignación x = e */
            TIPO_ARG aSrc = crArgPos((yyvsp[0].exp).n, (yyvsp[0].exp).d);
            TIPO_ARG aN   = crArgNul();
            TIPO_ARG aDst = crArgPos(sim.n, sim.d);
            emite(EASIG, aSrc, aN, aDst);

            (yyval.exp).t = (yyvsp[0].exp).t;
            (yyval.exp).d = sim.d;
            (yyval.exp).n = sim.n;
        }
      }
#line 1833 "asin.c"
    break;

  case 48: /* expre: TID TCORCHAB expre TCORCHCERR TASIG expre  */
#line 626 "src/asin.y"
    {
        SIMB sim = obtTdS((yyvsp[-5].ident));
        if (sim.t == T_ERROR) {
            yyerror("Asignación a array no declarado");
            (yyval.exp).t = T_ERROR;
        } else if (sim.t != T_ARRAY) {
            yyerror("La variable debe ser tipo 'array'");
            (yyval.exp).t = T_ERROR;
        } else {
            if ((yyvsp[-3].exp).t != T_ENTERO && (yyvsp[-3].exp).t != T_ERROR)
                yyerror("El indice del 'array' debe ser entero");

            DIM info_arr = obtTdA(sim.ref);
            if ((yyvsp[0].exp).t != T_ERROR && info_arr.telem != (yyvsp[0].exp).t)
                yyerror("Error de tipos en la asignacion a un 'array'");

            if ((yyvsp[-3].exp).t == T_ENTERO && (yyvsp[0].exp).t == info_arr.telem) {
                /* EVA src, idx, arr */
                TIPO_ARG aSrc = crArgPos((yyvsp[0].exp).n, (yyvsp[0].exp).d);
                TIPO_ARG aIdx = crArgPos((yyvsp[-3].exp).n, (yyvsp[-3].exp).d);
                TIPO_ARG aArr = crArgPos(sim.n, sim.d);
                emite(EVA, aSrc, aIdx, aArr);

                (yyval.exp).t = (yyvsp[0].exp).t;
                (yyval.exp).d = sim.d;
                (yyval.exp).n = sim.n;
            } else {
                (yyval.exp).t = T_ERROR;
            }
        }
      }
#line 1869 "asin.c"
    break;

  case 49: /* expreLogic: expreIgual  */
#line 661 "src/asin.y"
    {
        (yyval.exp).t = (yyvsp[0].exp).t;
        (yyval.exp).d = (yyvsp[0].exp).d;
        (yyval.exp).n = (yyvsp[0].exp).n;
    }
#line 1879 "asin.c"
    break;

  case 50: /* expreLogic: expreLogic opLogic expreIgual  */
#line 667 "src/asin.y"
    {
        if ((yyvsp[-2].exp).t == T_ERROR || (yyvsp[0].exp).t == T_ERROR) {
            (yyval.exp).t = T_ERROR;
        } else if ((yyvsp[-2].exp).t != T_LOGICO || (yyvsp[0].exp).t != T_LOGICO) {
            yyerror("Error de tipos en expresión lógica");
            (yyval.exp).t = T_ERROR;
        } else {
            (yyval.exp).t = T_LOGICO;
            (yyval.exp).d = creaVarTemp();
            (yyval.exp).n = niv;
            emite((yyvsp[-1].emite).e,
                  crArgPos((yyvsp[-2].exp).n, (yyvsp[-2].exp).d),
                  crArgPos((yyvsp[0].exp).n, (yyvsp[0].exp).d),
                  crArgPos((yyval.exp).n, (yyval.exp).d));
        }
    }
#line 1900 "asin.c"
    break;

  case 51: /* expreIgual: expreRel  */
#line 687 "src/asin.y"
    {
        (yyval.exp).t = (yyvsp[0].exp).t;
        (yyval.exp).d = (yyvsp[0].exp).d;
        (yyval.exp).n = (yyvsp[0].exp).n;
    }
#line 1910 "asin.c"
    break;

  case 52: /* expreIgual: expreIgual opIgual expreRel  */
#line 693 "src/asin.y"
    {
        if ((yyvsp[-2].exp).t == T_ERROR || (yyvsp[0].exp).t == T_ERROR) {
            (yyval.exp).t = T_ERROR;
        } else if ((yyvsp[-2].exp).t != (yyvsp[0].exp).t) {
            yyerror("Error de tipos en expresión de igualdad");
            (yyval.exp).t = T_ERROR;
        } else {
            (yyval.exp).t = T_LOGICO;
            (yyval.exp).d = creaVarTemp();
            (yyval.exp).n = niv;
            emite((yyvsp[-1].emite).e,
                  crArgPos((yyvsp[-2].exp).n, (yyvsp[-2].exp).d),
                  crArgPos((yyvsp[0].exp).n, (yyvsp[0].exp).d),
                  crArgPos((yyval.exp).n, (yyval.exp).d));
        }
    }
#line 1931 "asin.c"
    break;

  case 53: /* expreRel: expreAd  */
#line 713 "src/asin.y"
    {
        (yyval.exp).t = (yyvsp[0].exp).t;
        (yyval.exp).d = (yyvsp[0].exp).d;
        (yyval.exp).n = (yyvsp[0].exp).n;
    }
#line 1941 "asin.c"
    break;

  case 54: /* expreRel: expreRel opRel expreAd  */
#line 719 "src/asin.y"
    {
        if ((yyvsp[-2].exp).t == T_ERROR || (yyvsp[0].exp).t == T_ERROR) {
            (yyval.exp).t = T_ERROR;
        } else if ((yyvsp[-2].exp).t != T_ENTERO || (yyvsp[0].exp).t != T_ENTERO) {
            yyerror("Error de tipos en expresión relacional");
            (yyval.exp).t = T_ERROR;
        } else {
            (yyval.exp).t = T_LOGICO;
            (yyval.exp).d = creaVarTemp();
            (yyval.exp).n = niv;
            emite((yyvsp[-1].emite).e,
                  crArgPos((yyvsp[-2].exp).n, (yyvsp[-2].exp).d),
                  crArgPos((yyvsp[0].exp).n, (yyvsp[0].exp).d),
                  crArgPos((yyval.exp).n, (yyval.exp).d));
        }
    }
#line 1962 "asin.c"
    break;

  case 55: /* expreAd: expreMul  */
#line 740 "src/asin.y"
    {
        (yyval.exp).t = (yyvsp[0].exp).t;
        (yyval.exp).d = (yyvsp[0].exp).d;
        (yyval.exp).n = (yyvsp[0].exp).n;
    }
#line 1972 "asin.c"
    break;

  case 56: /* expreAd: expreAd opAd expreMul  */
#line 746 "src/asin.y"
    {
        if ((yyvsp[-2].exp).t == T_ERROR || (yyvsp[0].exp).t == T_ERROR) {
            (yyval.exp).t = T_ERROR;
        } else if ((yyvsp[-2].exp).t != T_ENTERO || (yyvsp[0].exp).t != T_ENTERO) {
            yyerror("Error de tipos en 'expresion aditiva'");
            (yyval.exp).t = T_ERROR;
        } else {
            (yyval.exp).t = T_ENTERO;
            (yyval.exp).d = creaVarTemp();
            (yyval.exp).n = niv;
            emite((yyvsp[-1].emite).e,
                  crArgPos((yyvsp[-2].exp).n, (yyvsp[-2].exp).d),
                  crArgPos((yyvsp[0].exp).n, (yyvsp[0].exp).d),
                  crArgPos((yyval.exp).n, (yyval.exp).d));
        }
    }
#line 1993 "asin.c"
    break;

  case 57: /* expreMul: expreUna  */
#line 767 "src/asin.y"
    {
        (yyval.exp).t = (yyvsp[0].exp).t;
        (yyval.exp).d = (yyvsp[0].exp).d;
        (yyval.exp).n = (yyvsp[0].exp).n;
    }
#line 2003 "asin.c"
    break;

  case 58: /* expreMul: expreMul opMul expreUna  */
#line 773 "src/asin.y"
    {
        if ((yyvsp[-2].exp).t == T_ERROR || (yyvsp[0].exp).t == T_ERROR) {
            (yyval.exp).t = T_ERROR;
        } else if ((yyvsp[-2].exp).t != T_ENTERO || (yyvsp[0].exp).t != T_ENTERO) {
            yyerror("Error de tipos en 'expresion multiplicativa'");
            (yyval.exp).t = T_ERROR;
        } else {
            (yyval.exp).t = T_ENTERO;
            (yyval.exp).d = creaVarTemp();
            (yyval.exp).n = niv;
            emite((yyvsp[-1].emite).e,
                  crArgPos((yyvsp[-2].exp).n, (yyvsp[-2].exp).d),
                  crArgPos((yyvsp[0].exp).n, (yyvsp[0].exp).d),
                  crArgPos((yyval.exp).n, (yyval.exp).d));
        }
    }
#line 2024 "asin.c"
    break;

  case 59: /* expreUna: expreSufi  */
#line 793 "src/asin.y"
    {
        (yyval.exp).t = (yyvsp[0].exp).t;
        (yyval.exp).d = (yyvsp[0].exp).d;
        (yyval.exp).n = (yyvsp[0].exp).n;
    }
#line 2034 "asin.c"
    break;

  case 60: /* expreUna: opUna expreUna  */
#line 799 "src/asin.y"
    {
        /* '+' no hace nada, '-' y '!' se manejan según $1.e */
        if ((yyvsp[-1].emite).e == 0) {          /* '+' → no-op */
            (yyval.exp).t = (yyvsp[0].exp).t;
            (yyval.exp).d = (yyvsp[0].exp).d;
            (yyval.exp).n = (yyvsp[0].exp).n;
        }
        else if ((yyvsp[-1].emite).e == ESIG) {  /* '-' unario */
            if ((yyvsp[0].exp).t == T_ERROR) {
                (yyval.exp).t = T_ERROR;
            } else if ((yyvsp[0].exp).t != T_ENTERO) {
                yyerror("Error de tipos en expresión unaria");
                (yyval.exp).t = T_ERROR;
            } else {
                (yyval.exp).t = T_ENTERO;
                (yyval.exp).d = creaVarTemp();
                (yyval.exp).n = niv;
                TIPO_ARG aN = crArgNul();
                emite(ESIG,
                      crArgPos((yyvsp[0].exp).n, (yyvsp[0].exp).d),
                      aN,
                      crArgPos((yyval.exp).n, (yyval.exp).d));
            }
        }
        else {                    /* '!' lógica: implementamos !E como (E == 0) */
            if ((yyvsp[0].exp).t == T_ERROR) {
                (yyval.exp).t = T_ERROR;
            } else if ((yyvsp[0].exp).t != T_LOGICO) {
                yyerror("Error de tipos en expresión unaria lógica");
                (yyval.exp).t = T_ERROR;
            } else {
                (yyval.exp).t = T_LOGICO;
                (yyval.exp).d = creaVarTemp();
                (yyval.exp).n = niv;
                TIPO_ARG aZero = crArgEnt(0);
                emite(EIGUAL,
                      crArgPos((yyvsp[0].exp).n, (yyvsp[0].exp).d),
                      aZero,
                      crArgPos((yyval.exp).n, (yyval.exp).d));
            }
        }
    }
#line 2081 "asin.c"
    break;

  case 61: /* expreSufi: const  */
#line 845 "src/asin.y"
    {
        (yyval.exp).t = (yyvsp[0].exp).t;
        (yyval.exp).d = (yyvsp[0].exp).d;
        (yyval.exp).n = (yyvsp[0].exp).n;
    }
#line 2091 "asin.c"
    break;

  case 62: /* expreSufi: TPARAB expre TPARCERR  */
#line 851 "src/asin.y"
    {
        (yyval.exp).t = (yyvsp[-1].exp).t;
        (yyval.exp).d = (yyvsp[-1].exp).d;
        (yyval.exp).n = (yyvsp[-1].exp).n;
    }
#line 2101 "asin.c"
    break;

  case 63: /* expreSufi: TID  */
#line 857 "src/asin.y"
    {
        SIMB sim = obtTdS((yyvsp[0].ident));
        if (sim.t == T_ERROR)
            yyerror("Uso de variable no declarada");
        (yyval.exp).t = sim.t;
        (yyval.exp).d = sim.d;
        (yyval.exp).n = sim.n;
    }
#line 2114 "asin.c"
    break;

  case 64: /* expreSufi: TID TCORCHAB expre TCORCHCERR  */
#line 866 "src/asin.y"
    {
        SIMB sim = obtTdS((yyvsp[-3].ident));
        if (sim.t == T_ERROR) {
            yyerror("Uso de array no declarado");
            (yyval.exp).t = T_ERROR;
        } else if (sim.t != T_ARRAY) {
            yyerror("La variable debe ser tipo 'array'");
            (yyval.exp).t = T_ERROR;
        } else {
            /* Verificar que el índice sea entero (si no fue ya error) */
            if ((yyvsp[-1].exp).t != T_ENTERO && (yyvsp[-1].exp).t != T_ERROR)
                yyerror("El indice del 'array' debe ser entero");

            if ((yyvsp[-1].exp).t == T_ENTERO) {
                /* Obtener info del array y crear temporal para el valor */
                DIM info_arr = obtTdA(sim.ref);
                (yyval.exp).t = info_arr.telem;
                (yyval.exp).n = niv;
                (yyval.exp).d = creaVarTemp();

                /* Emitir EAV arr, idx, dest_temp */
                TIPO_ARG aArr = crArgPos(sim.n, sim.d);
                TIPO_ARG aIdx = crArgPos((yyvsp[-1].exp).n, (yyvsp[-1].exp).d);
                TIPO_ARG aRes = crArgPos((yyval.exp).n, (yyval.exp).d);
                emite(EAV, aArr, aIdx, aRes);
            } else {
                (yyval.exp).t = T_ERROR;
            }
        }
    }
#line 2149 "asin.c"
    break;

  case 65: /* $@9: %empty  */
#line 898 "src/asin.y"
      {
          /* Reservamos espacio para el valor de retorno */
          TIPO_ARG aN = crArgNul();
          emite(EPUSH, aN, aN, crArgEnt(0));
      }
#line 2159 "asin.c"
    break;

  case 66: /* expreSufi: TID TPARAB $@9 paramAct TPARCERR  */
#line 904 "src/asin.y"
    {
        SIMB sim = obtTdS((yyvsp[-4].ident));
        if (sim.t == T_ERROR) {
            yyerror("Uso de función no declarada");
            (yyval.exp).t = T_ERROR;
            (yyval.exp).d = 0;
            (yyval.exp).n = 0;
        } else {
            /* Comprobación de parámetros (ya la tenías) */
            if (!cmpDom((yyvsp[-1].paramInfo).ref, sim.ref)) {
                yyerror("Parámetros de la función no coinciden con la declaración");
                (yyval.exp).t = T_ERROR;
                (yyval.exp).d = 0;
                (yyval.exp).n = 0;
            } else {
                TIPO_ARG aN = crArgNul();

                /* sim.d contiene la etiqueta (si) de inicio de la función */
                emite(CALL, aN, aN, crArgEtq(sim.d));

                /* Al volver:
                   Pila = [... RA llamante ... , ret, arg_1, ..., arg_k ]
                   Queremos:
                     - quitar los k argumentos
                     - quedarnos con ret en un temporal */
                if ((yyvsp[-1].paramInfo).num_params > 0) {
                    emite(DECTOP, aN, aN, crArgEnt((yyvsp[-1].paramInfo).num_params));
                }

                /* Crear temporal para el valor devuelto */
                (yyval.exp).t = sim.t;
                (yyval.exp).d = creaVarTemp();
                (yyval.exp).n = niv;

                emite(EPOP, aN, aN, crArgPos((yyval.exp).n, (yyval.exp).d));
            }
        }
    }
#line 2202 "asin.c"
    break;

  case 67: /* paramAct: %empty  */
#line 947 "src/asin.y"
    {
        (yyval.paramInfo).num_params = 0;
        (yyval.paramInfo).ref        = insTdD(-1, T_VACIO);
        (yyval.paramInfo).talla      = 0;
    }
#line 2212 "asin.c"
    break;

  case 68: /* paramAct: listParamAct  */
#line 953 "src/asin.y"
    {
        (yyval.paramInfo).num_params = (yyvsp[0].paramInfo).num_params;
        (yyval.paramInfo).ref        = (yyvsp[0].paramInfo).ref;
        (yyval.paramInfo).talla      = (yyvsp[0].paramInfo).talla;
    }
#line 2222 "asin.c"
    break;

  case 69: /* listParamAct: expre  */
#line 963 "src/asin.y"
    {
        /* Último argumento --> crea dominio */
        (yyval.paramInfo).num_params = 1;
        (yyval.paramInfo).ref   = insTdD(-1, (yyvsp[0].exp).t);
        (yyval.paramInfo).talla = TALLA_TIPO_SIMPLE;

        /* ESTRELLA: EPUSH del valor del argumento */
        if ((yyvsp[0].exp).t != T_ERROR) {
            TIPO_ARG aN = crArgNul();
            emite(EPUSH, aN, aN, crArgPos((yyvsp[0].exp).n, (yyvsp[0].exp).d));
        }
    }
#line 2239 "asin.c"
    break;

  case 70: /* listParamAct: expre TCOMA listParamAct  */
#line 976 "src/asin.y"
    {
        /* Añadimos un argumento a la izquierda */
        (yyval.paramInfo).num_params = (yyvsp[0].paramInfo).num_params + 1;
        (yyval.paramInfo).ref   = insTdD((yyvsp[0].paramInfo).ref, (yyvsp[-2].exp).t);
        (yyval.paramInfo).talla = (yyvsp[0].paramInfo).talla + TALLA_TIPO_SIMPLE;

        /* EPUSH del valor de este argumento.
           OJO: por la recursión, los EPUSH se generan
           de derecha a izquierda: arg_k, ..., arg_1. */
        if ((yyvsp[-2].exp).t != T_ERROR) {
            TIPO_ARG aN = crArgNul();
            emite(EPUSH, aN, aN, crArgPos((yyvsp[-2].exp).n, (yyvsp[-2].exp).d));
        }
    }
#line 2258 "asin.c"
    break;

  case 71: /* opLogic: TAND  */
#line 1000 "src/asin.y"
         {(yyval.emite).e = EMULT;}
#line 2264 "asin.c"
    break;

  case 72: /* opLogic: TOR  */
#line 1000 "src/asin.y"
                              {(yyval.emite).e = ESUM;}
#line 2270 "asin.c"
    break;

  case 73: /* opIgual: TIGUALQUE  */
#line 1002 "src/asin.y"
              {(yyval.emite).e = EIGUAL;}
#line 2276 "asin.c"
    break;

  case 74: /* opIgual: TDISTINTOQUE  */
#line 1002 "src/asin.y"
                                             {(yyval.emite).e = EDIST;}
#line 2282 "asin.c"
    break;

  case 75: /* opRel: TMAYORQUE  */
#line 1004 "src/asin.y"
              {(yyval.emite).e = EMAY;}
#line 2288 "asin.c"
    break;

  case 76: /* opRel: TMENORQUE  */
#line 1004 "src/asin.y"
                                        {(yyval.emite).e = EMEN;}
#line 2294 "asin.c"
    break;

  case 77: /* opRel: TMAYORIGUAL  */
#line 1004 "src/asin.y"
                                                                     {(yyval.emite).e = EMAYEQ;}
#line 2300 "asin.c"
    break;

  case 78: /* opRel: TMENORIGUAL  */
#line 1004 "src/asin.y"
                                                                                                   {(yyval.emite).e = EMENEQ;}
#line 2306 "asin.c"
    break;

  case 79: /* opAd: TMAS  */
#line 1007 "src/asin.y"
         {(yyval.emite).e = ESUM;}
#line 2312 "asin.c"
    break;

  case 80: /* opAd: TMENOS  */
#line 1007 "src/asin.y"
                                {(yyval.emite).e = EDIF;}
#line 2318 "asin.c"
    break;

  case 81: /* opMul: TMULT  */
#line 1009 "src/asin.y"
          {(yyval.emite).e = EMULT;}
#line 2324 "asin.c"
    break;

  case 82: /* opMul: TDIV  */
#line 1009 "src/asin.y"
                                {(yyval.emite).e = EDIVI;}
#line 2330 "asin.c"
    break;

  case 83: /* opUna: TMAS  */
#line 1011 "src/asin.y"
         {(yyval.emite).e = ESUM;}
#line 2336 "asin.c"
    break;

  case 84: /* opUna: TMENOS  */
#line 1011 "src/asin.y"
                                {(yyval.emite).e = EDIF;}
#line 2342 "asin.c"
    break;

  case 85: /* opUna: TEXCL  */
#line 1011 "src/asin.y"
                                                      {(yyval.emite).e = ESIG;}
#line 2348 "asin.c"
    break;

  case 86: /* marca: %empty  */
#line 1016 "src/asin.y"
                 { (yyval.cent) = si; }
#line 2354 "asin.c"
    break;


#line 2358 "asin.c"

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

#line 1019 "src/asin.y"

