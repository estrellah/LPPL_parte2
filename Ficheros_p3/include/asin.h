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
    TDIV = 261,                    /* TDIV  */
    TMULT = 262,                   /* TMULT  */
    TEXCL = 263,                   /* TEXCL  */
    TFALSE = 264,                  /* TFALSE  */
    TTRUE = 265,                   /* TTRUE  */
    TAND = 266,                    /* TAND  */
    TOR = 267,                     /* TOR  */
    TPARAB = 268,                  /* TPARAB  */
    TPARCERR = 269,                /* TPARCERR  */
    TLLAVAB = 270,                 /* TLLAVAB  */
    TLLAVCERR = 271,               /* TLLAVCERR  */
    TCORCHAB = 272,                /* TCORCHAB  */
    TCORCHCERR = 273,              /* TCORCHCERR  */
    TPUNTOCOMA = 274,              /* TPUNTOCOMA  */
    TCOMA = 275,                   /* TCOMA  */
    TREAD = 276,                   /* TREAD  */
    TPRINT = 277,                  /* TPRINT  */
    TIF = 278,                     /* TIF  */
    TELSE = 279,                   /* TELSE  */
    TFOR = 280,                    /* TFOR  */
    TRETURN = 281,                 /* TRETURN  */
    TIGUALQUE = 282,               /* TIGUALQUE  */
    TDISTINTOQUE = 283,            /* TDISTINTOQUE  */
    TMAYORQUE = 284,               /* TMAYORQUE  */
    TMENORQUE = 285,               /* TMENORQUE  */
    TMAYORIGUAL = 286,             /* TMAYORIGUAL  */
    TMENORIGUAL = 287,             /* TMENORIGUAL  */
    TID = 288,                     /* TID  */
    TINT = 289,                    /* TINT  */
    TBOOL = 290,                   /* TBOOL  */
    TCTE = 291                     /* TCTE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 32 "src/asin.y"

    char *ident;    /* Nombre del identificador*/
    int cent;       /* Entero genérico (LANS, etiquetas...) */

    struct {
        int num_params;
        int ref;
        int talla;
    } paramInfo;

    struct {
        int t;
    } tipo;

    struct{
        int tipo_return;
        char *nombre_func;
        int desp;
        int num_params;
    } funcion;

    /* Expresión con código intermedio asociado */
    struct {
        int t;   /* tipo de la expresión (T_ENTERO, T_LOGICO, ...) */
        int d;   /* desplazamiento donde está almacenado el valor */
        int n;   /* nivel donde está esa posición (0 global, 1 local, ...) */
    } exp;

    /* Operador que se traduce a un código de operación 3D */
    struct {
        int e;   /* código de operación (ESUM, EDIF, EMULT, ...) */
    } emite;

    /* Para guardar listas de saltos (verdadero/falso) en una sola acción */
    struct {
        int ltrue;
        int lfalse;
    } listas;

#line 140 "asin.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_ASIN_H_INCLUDED  */
