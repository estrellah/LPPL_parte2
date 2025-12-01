%{
    #include <stdio.h>
    #include "../include/header.h"
    extern int yylineno;
%}

%token TID TINT TBOOL TCTE
/*OPERADORES*/
%token TASIG TMAS TMENOS TDIV TMULT
%token TEXCL TFALSE TTRUE TAND TOR
%token TPARAB TPARCERR TLLAVAB TLLAVCERR TCORCHAB TCORCHCERR
%token TPUNTOCOMA TCOMA
%token TREAD TPRINT TIF TELSE TFOR TRETURN

/*Comparaciones*/
%token TIGUALQUE TDISTINTOQUE TMAYORQUE TMENORQUE TMAYORIGUAL TMENORIGUAL

/* REGLAS - COMO CONSTRUIR CADA SÍMBOLO NO TERMINAL A PARTIR DE SUS PARTES*/
%%
programa: listDecla ;
listDecla: 
    decla | listDecla decla ;
decla:
    declaVar | declaFunc ;
declaVar:
    tipoSimp TID TPUNTOCOMA | tipoSimp TID TASIG const TPUNTOCOMA 
    | tipoSimp TID TCORCHAB TCTE TCORCHCERR TPUNTOCOMA ;
const:
    TCTE | TTRUE | TFALSE ;
tipoSimp:
    TINT | TBOOL ;
declaFunc:
    tipoSimp TID TPARAB paramForm TPARCERR bloque ;
paramForm:
    | listParamForm ;
listParamForm:
    tipoSimp TID | tipoSimp TID TCOMA listParamForm ;
bloque:
    TLLAVAB declaVarLocal listInst TRETURN expre TPUNTOCOMA TLLAVCERR ;
declaVarLocal:
    | declaVarLocal declaVar ;
listInst:
    | listInst inst ;
inst:
    TLLAVAB listInst TLLAVCERR | instExpre | instEntSal | instSelec |instIter ;
instExpre:
    expre TPUNTOCOMA | TPUNTOCOMA ;
instEntSal:
    TREAD TPARAB TID TPARCERR TPUNTOCOMA | TPRINT TPARAB expre TPARCERR TPUNTOCOMA ;
instSelec:
    TIF TPARAB expre TPARCERR inst TELSE inst ;
instIter:
    TFOR TPARAB expreOP TPUNTOCOMA expre TPUNTOCOMA expreOP TPARCERR inst ;
expreOP:
    | expre ;
expre:
    expreLogic | TID TASIG expre | TID TCORCHAB expre TCORCHCERR TASIG expre ;
expreLogic:
    expreIgual | expreLogic opLogic expreIgual ;
expreIgual:
    expreRel | expreIgual opIgual expreRel ;
expreRel:
    expreAd | expreRel opRel expreAd ;
expreAd:
    expreMul | expreAd opAd expreMul ;
expreMul:
    expreUna | expreMul opMul expreUna ;
expreUna:
    expreSufi | opUna expreUna ;
expreSufi:
    const | TPARAB expre TPARCERR |TID | TID TCORCHAB expre TCORCHCERR | TID TPARAB paramAct TPARCERR ;
paramAct:
    |listParamAct ;
listParamAct:
    expre | expre TCOMA listParamAct ;
opLogic:
    TAND | TOR ;
opIgual:
    TIGUALQUE |TDISTINTOQUE ;
opRel:
    TMAYORQUE | TMENORQUE | TMAYORIGUAL | TMENORIGUAL ;
opAd:
    TMAS | TMENOS ;
opMul:
    TMULT | TDIV ;
opUna:
    TMAS | TMENOS | TEXCL ;

%%
