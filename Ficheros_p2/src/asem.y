%union {
    int i;
}

%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "../Ficheros_p1/include/header.h"
    #include "../include/libtds.h"
    extern int yylineno;

    /*PARA COMPROBAR SI HAY MAIN EN EL PROGRAMA*/
    int mainCount = 0;
    
    /* Función auxiliar para insertar parámetros en orden inverso */
    void insertaParametros(int refDom) {
        /* Los parámetros ya están en la TdS en orden inverso a su declaración */
    }
    
    /* Función para limpiar nivel de variables locales */
    void borraNiv(int nivel) {
        /* Limpia variables del nivel especificado */
    }
    
    #define TALLA_TIPO_SIMPLE 4
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

/* Tipos de los nodos */
%type <i> tipoSimp
%type <i> const
%type <i> paramForm
%type <i> listParamForm
%type <i> expre
%type <i> expreLogic
%type <i> expreIgual
%type <i> expreRel
%type <i> expreAd
%type <i> expreMul
%type <i> expreUna
%type <i> expreSufi

/* REGLAS - COMO CONSTRUIR CADA SÍMBOLO NO TERMINAL A PARTIR DE SUS PARTES*/
%%
/* PROGRAMA SERÁ LA ÚLTIMA REGLA EN REDUCIRSE */
programa: listDecla 
    {
        if (mainCount == 0)
            yyerror("No existe la función main");
        else if (mainCount > 1)
            yyerror("Hay más de una función main");
    }
    ;
listDecla: 
    decla | listDecla decla ;
decla:
    declaVar | declaFunc ;

/* DECLARAR VARIABLES Y FUNCIONES*/
declaVar:
    tipoSimp TID TPUNTOCOMA  /* tipoSimp: $1, TID: $2, TPUNTOCOMA:$3 */
    {
          if (!insTdS(yytext, VARIABLE, $1, niv, dvar, -1))
              yyerror("Identificador repetido"); /* Variable ya declarada */
          else
              dvar += TALLA_TIPO_SIMPLE;
      }
    | tipoSimp TID TASIG const TPUNTOCOMA  /* tipoSimp: $1, TID: $2, TASIG:$3, const: $4, TPUNTOCOMA:$5 */
    {
          if (!insTdS(yytext, VARIABLE, $1, niv, dvar, -1))
              yyerror("Identificador repetido");
          else
              dvar += TALLA_TIPO_SIMPLE;
      }
    | tipoSimp TID TCORCHAB TCTE TCORCHCERR TPUNTOCOMA 
    {
          int num = $4; /*Obtener valor entero*/
          int ref = insTdA($1, num); /*Tiene referencia porque es un array*/
          if (!insTdS(yytext, VARIABLE, T_ARRAY, niv, dvar, ref))
              yyerror("Identificador repetido");
          else
              dvar += num * TALLA_TIPO_SIMPLE;
      }
    
    ;

/* AQUÍ LA FUNCION PUEDE SER MAIN*/
declaFunc:
    tipoSimp TID TPARAB paramForm TPARCERR bloque 
    {
        if (strcmp(yytext, "main") == 0) {
            mainCount++;
            if (mainCount == 1) {
                tipoMain = $1;
            }
        }
        
        /* Verificar que la función no haya sido declarada previamente */
        SIMB simb = obtTdS(yytext);
        if (simb.t != T_ERROR && simb.n == niv) {
            yyerror("Función repetida");
        } else if (!insTdS(yytext, FUNCION, $1, niv, dvar, $4)) {
            yyerror("Función repetida");
        } else {
            /* Crear nuevo ámbito para la función */
            niv++;
            
            /* Los parámetros ya fueron insertados en orden inverso por paramForm */
            
            /* Cerrar ámbito de la función */
            borraNiv(niv);
            niv--;
        }
    }
    ;


const:
    TCTE | TTRUE | TFALSE ;
tipoSimp:
    TINT | TBOOL ;

paramForm:
    { $$ = -1; }
    | listParamForm ;
listParamForm:
    tipoSimp TID 
    {
        /*Primer parámetro (último en la lista), se crea dominio*/
        $$ = insTdD(-1, $1); 
        
        /* Insertar parámetro en orden inverso */
        insTdS(yytext, PARAMETRO, $1, niv+1, /* desp */ 0, /* ref */ -1);
    }
    | listParamForm TCOMA tipoSimp TID 
    {
        /* Insertar param con el dominio ya creado - en orden inverso */
        $$ = insTdD($1, $3);

        /* Añadir param en TDS en posición correcta */
        insTdS(yytext, PARAMETRO, $3, niv+1, 0, -1);
    }
    ;
bloque:
    TLLAVAB declaVarLocal listInst TRETURN expre TPUNTOCOMA TLLAVCERR ;
declaVarLocal:
    | declaVarLocal declaVar ;
listInst:
    | listInst inst ;
inst:
    TLLAVAB listInst TLLAVCERR | instExpre | instEntSal | instSelec |instIter ;
instExpre:
    expre TPUNTOCOMA 
    | TPUNTOCOMA 
    ;
    ;
instEntSal:
    TREAD TPARAB TID TPARCERR TPUNTOCOMA 
    {
          SIMB sim = obtTdS(yytext);
          if (sim.t == T_ERROR)
              yyerror("Variable no declarada en READ");
      }
    | TPRINT TPARAB expre TPARCERR TPUNTOCOMA
    {

    }
     ;
instSelec:
    TIF TPARAB expre TPARCERR inst TELSE inst ;
instIter:
    TFOR TPARAB expreOP TPUNTOCOMA expre TPUNTOCOMA expreOP TPARCERR inst ;
expreOP:
    | expre ;
expre:
    expreLogic 
    | TID TASIG expre 
    {
          SIMB sim = obtTdS(yytext);
          if (sim.t == T_ERROR)
              yyerror("Asignación a variable no declarada");
      }
    | TID TCORCHAB expre TCORCHCERR TASIG expre 
    {
          SIMB sim = obtTdS(yytext);
          if (sim.t == T_ERROR)
              yyerror("Asignación a array no declarado");
      }
      ;
expreLogic:
    expreIgual | expreLogic opLogic expreIgual ;
expreIgual:
    expreRel | expreIgual opIgual expreRel ;
expreRel:
    expreAd | expreRel opRel expreAd ;
expreAd:
    expreMul 
    | expreAd opAd expreMul ;
expreMul:
    expreUna | expreMul opMul expreUna ;
expreUna:
    expreSufi | opUna expreUna ;
expreSufi:
    const 
    | TPARAB expre TPARCERR 
    |TID 
    {
          SIMB sim = obtTdS(yytext);
          if (sim.t == T_ERROR)
              yyerror("Uso de variable no declarada");
          $$ = sim.t;   /* devuelve el tipo */
      }
    | TID TCORCHAB expre TCORCHCERR 
    {
          SIMB sim = obtTdS(yytext);
          if (sim.t == T_ERROR)
              yyerror("Uso de array no declarado");
      }
    | TID TPARAB paramAct TPARCERR 
    {
          SIMB sim = obtTdS(yytext);
          if (sim.t == T_ERROR)
              yyerror("Uso de función no declarada");
      }
    ;

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
    TMAS 
    | TMENOS ;
opMul:
    TMULT | TDIV ;
opUna:
    TMAS | TMENOS | TEXCL ;

%%
