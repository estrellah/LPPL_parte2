
%{
#include<stdio.h>
#include <math.h>
#include <string.h>
#include "../Ficheros_p1/include/header.h"
#include "../include/asin.h"
#define  retornar(x) {if (verbosidad) ECHO; return x ; }
%}

delimitador [ \t]+
digito      [0-9]
letra_min   [a-z]
letra_may   [A-Z]
signo       [-+*/]
entero      {digito}+
real        ({entero}?"."{digito}+)|({entero}".")
constante   ({entero}|{real})
variable    ({letra_min}|{letra_may})(({letra_min}|{letra_may}|{entero}|"_")*)
comentario  "//"[^\n]*

%%
{delimitador}  ;
"\n"           { yylineno++; } //MODIFICADO
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
"true"         {yylval.i = 1; retornar (TTRUE);}
"false"        {yylval.i = 0; retornar (TFALSE);}
"bool"         {yylval.i = 2; retornar (TBOOL);}
"int"          {yylval.i = 1; retornar (TINT);}
"read"         {retornar (TREAD);}
"print"        {retornar (TPRINT);}
"if"           {retornar (TIF);}
"else"         {retornar (TELSE);}
"for"          {retornar (TFOR);}
"return"       {retornar (TRETURN);}
{constante}    {
    /* Truncar números reales a enteros */
    double val = atof(yytext);
    yylval.i = (int)val;  /* Trunca la parte decimal */
    retornar (TCTE);
}
{variable}     {
    /* Guardar el identificador en yylval.s para que el parser lo reciba */
    yylval.s = strdup(yytext);
    retornar (TID);
}
{comentario}   ;
.              {yyerror("Caracter desconocido");}
%%