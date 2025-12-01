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
    TID = 258,                     /* TID  */
    TINT = 259,                    /* TINT  */
    TBOOL = 260,                   /* TBOOL  */
    TCTE = 261,                    /* TCTE  */
    TASIG = 262,                   /* TASIG  */
    TMAS = 263,                    /* TMAS  */
    TMENOS = 264,                  /* TMENOS  */
    TDIV = 265,                    /* TDIV  */
    TMULT = 266,                   /* TMULT  */
    TEXCL = 267,                   /* TEXCL  */
    TFALSE = 268,                  /* TFALSE  */
    TTRUE = 269,                   /* TTRUE  */
    TAND = 270,                    /* TAND  */
    TOR = 271,                     /* TOR  */
    TPARAB = 272,                  /* TPARAB  */
    TPARCERR = 273,                /* TPARCERR  */
    TLLAVAB = 274,                 /* TLLAVAB  */
    TLLAVCERR = 275,               /* TLLAVCERR  */
    TCORCHAB = 276,                /* TCORCHAB  */
    TCORCHCERR = 277,              /* TCORCHCERR  */
    TPUNTOCOMA = 278,              /* TPUNTOCOMA  */
    TCOMA = 279,                   /* TCOMA  */
    TREAD = 280,                   /* TREAD  */
    TPRINT = 281,                  /* TPRINT  */
    TIF = 282,                     /* TIF  */
    TELSE = 283,                   /* TELSE  */
    TFOR = 284,                    /* TFOR  */
    TRETURN = 285,                 /* TRETURN  */
    TIGUALQUE = 286,               /* TIGUALQUE  */
    TDISTINTOQUE = 287,            /* TDISTINTOQUE  */
    TMAYORQUE = 288,               /* TMAYORQUE  */
    TMENORQUE = 289,               /* TMENORQUE  */
    TMAYORIGUAL = 290,             /* TMAYORIGUAL  */
    TMENORIGUAL = 291              /* TMENORIGUAL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_ASIN_H_INCLUDED  */
