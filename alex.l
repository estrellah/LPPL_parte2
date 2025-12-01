
%{
#include<stdio.h>
#include “asin.tab.h”
%}

delimitador [ \t\n]+
digito      [0-9]
letra_min   [a-z]
letra_may   [A-Z]
signo       [-+*/]
entero      {digito}+
real        ({entero}?"."{digito}+)|({entero}".")
constante   {entero} | {real}
variable    {letra_min}({letra_min}|{letra_may}|{entero}|"_")*
constante   {letra_may}+
comentario  "//"[^\n]*

%%
{delimitador}  ;
"="            {printf("TASIG\n");}
"+"            {printf("TMAS\n");}
"-"            {printf("TMENOS\n");}
"!"            {printf("TEXCL\n");}
"*"            {printf("TMULT\n");}
"/"            {printf("TDIV\n");}
"("            {printf("TPARAB\n");}
")"            {printf("TPARCERR\n");}
"{"            {printf("TLLAVAB\n");}
"}"            {printf("TLLAVCERR\n");}
"["            {printf("TCORCHAB\n");}
"]"            {printf("TCORCHCERR\n");}
";"            {printf("TPUNTOCOMA\n");}
","            {printf("TCOMA\n");}
"&&"           {printf("TAND\n");}
"||"           {printf("TOR\n");}
"=="           {printf("TIGUALQUE\n");}
"!="           {printf("TDISTINTOQUE\n");}
">"            {printf("TMAYORQUE\n");}
"<"            {printf("TMENORQUE\n");}
">="           {printf("TMAYORIGUAL\n");}
"<="           {printf("TMENORIGUAL\n");}
"true"         {printf("TTRUE\n");}
"false"        {printf("TFALSE\n");}
"bool"         {printf("TBOOL\n");}
"int"          {printf("TINT\n");}
"read"         {printf("TREAD\n");}
"print"        {printf("TPRINT\n");}
"if"           {printf("TIF\n");}
"else"         {printf("TELSE\n");}
"for"          {printf("TFOR\n");}
"return"       {printf("TRETURN\n");}
{constante}    {printf("TCTE\n");}
{variable}     {printf("TID\n");}
{comentario}   ;
.              {printf("Error\n");}
%%