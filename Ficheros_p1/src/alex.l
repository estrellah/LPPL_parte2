
%{
#include<stdio.h>
#include "../include/header.h"
#include "asin.h"
#define  retornar(x) {if (verbosidad) ECHO; return x ; }
%}

delimitador [ \t\n]+
digito      [0-9]
letra_min   [a-z]
letra_may   [A-Z]
signo       [-+*/]
entero      {digito}+
real        ({entero}?"."{digito}+)|({entero}".")
constante   ({entero}|{real})
variable    {letra_min}({letra_min}|{letra_may}|{entero}|"_")*
comentario  "//"[^\n]*

%%
{delimitador}  ;
"="            {retornar (TASIG);}
"+"            {retornar (TMAS);}
"-"            {retornar (TMENOS);}
"!"            {retornar (TEXCL);}
"*"            {retornar (TMULT);}
"/"            {retornar (TDIV);}
"("            {retornar (TPARAB);}
")"            {retornar (TPARCERR);}
"{"            {retornar (TLLAVAB);}
"}"            {retornar (TLLAVCERR);}
"["            {retornar (TCORCHAB);}
"]"            {retornar (TCORCHCERR);}
";"            {retornar (TPUNTOCOMA);}
","            {retornar (TCOMA);}
"&&"           {retornar (TAND);}
"||"           {retornar (TOR);}
"=="           {retornar (TIGUALQUE);}
"!="           {retornar (TDISTINTOQUE);}
">"            {retornar (TMAYORQUE);}
"<"            {retornar (TMENORQUE);}
">="           {retornar (TMAYORIGUAL);}
"<="           {retornar (TMENORIGUAL);}
"true"         {retornar (TTRUE);}
"false"        {retornar (TFALSE);}
"bool"         {retornar (TBOOL);}
"int"          {retornar (TINT);}
"read"         {retornar (TREAD);}
"print"        {retornar (TPRINT);}
"if"           {retornar (TIF);}
"else"         {retornar (TELSE);}
"for"          {retornar (TFOR);}
"return"       {retornar (TRETURN);}
{constante}    {retornar (TCTE);}
{variable}     {retornar (TID);}
{comentario}   ;
.              {yyerror("Caracter desconocido");}
%%