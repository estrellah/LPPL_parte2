/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_ASIN_H_INCLUDED
# define YY_YY_ASIN_H_INCLUDED
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
    TASIG = 258,                   /* TASIG  */
    TMAS = 259,                    /* TMAS  */
    TMENOS = 260,                  /* TMENOS  */
    TMULT = 261,                   /* TMULT  */
    TDIV = 262,                    /* TDIV  */
    TPUNTOCOMA = 263,              /* TPUNTOCOMA  */
    TCOMA = 264,                   /* TCOMA  */
    TPARAB = 265,                  /* TPARAB  */
    TPARCERR = 266,                /* TPARCERR  */
    TLLAVAB = 267,                 /* TLLAVAB  */
    TLLAVCERR = 268,               /* TLLAVCERR  */
    TCORCHAB = 269,                /* TCORCHAB  */
    TCORCHCERR = 270,              /* TCORCHCERR  */
    TAND = 271,                    /* TAND  */
    TOR = 272,                     /* TOR  */
    TEXCL = 273,                   /* TEXCL  */
    TIGUALQUE = 274,               /* TIGUALQUE  */
    TDISTINTOQUE = 275,            /* TDISTINTOQUE  */
    TMAYORQUE = 276,               /* TMAYORQUE  */
    TMENORQUE = 277,               /* TMENORQUE  */
    TMAYORIGUAL = 278,             /* TMAYORIGUAL  */
    TMENORIGUAL = 279,             /* TMENORIGUAL  */
    TTRUE = 280,                   /* TTRUE  */
    TFALSE = 281,                  /* TFALSE  */
    TREAD = 282,                   /* TREAD  */
    TPRINT = 283,                  /* TPRINT  */
    TIF = 284,                     /* TIF  */
    TELSE = 285,                   /* TELSE  */
    TFOR = 286,                    /* TFOR  */
    TRETURN = 287,                 /* TRETURN  */
    TINT = 288,                    /* TINT  */
    TBOOL = 289,                   /* TBOOL  */
    TID = 290,                     /* TID  */
    TCTE = 291                     /* TCTE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "src/asin.y"

    char *ident;    /* Nombre del identificador */
    int cent;       /* Valor entero (usado para constantes, etiquetas, LANS) */
    
    /* Estructura para parámetros */
    struct {
        int num_params;
        int ref;
        int talla;
    } paramInfo;

    /* Estructura para tipos simples */
    struct {
        int t;
    } tipo;

    /* Estructura para expresiones y constantes (TIPO, DESPLAZAMIENTO, NIVEL, VALOR) */
    /* Añadimos 'val' porque asinS.y lo usa para constantes numéricas */
    struct {
        int t;      /* Tipo (T_ENTERO, T_LOGICO...) */
        int d;      /* Desplazamiento / Dirección */
        int n;      /* Nivel */
        int val;    /* Valor constante (si aplica) */
    } exp;

    /* Estructura para listas de parámetros */
    struct {
        int ref;
        int talla;
    } lista;

#line 132 "asin.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_ASIN_H_INCLUDED  */
