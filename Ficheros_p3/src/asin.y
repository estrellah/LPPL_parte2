%{
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
%}

/* ATRIBUTOS */
%union {
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
}


/*OPERADORES*/
%token TASIG TMAS TMENOS TDIV TMULT
%token TEXCL TFALSE TTRUE TAND TOR
%token TPARAB TPARCERR TLLAVAB TLLAVCERR TCORCHAB TCORCHCERR
%token TPUNTOCOMA TCOMA
%token TREAD TPRINT TIF TELSE TFOR TRETURN

/*COMPARACIONES*/
%token TIGUALQUE TDISTINTOQUE TMAYORQUE TMENORQUE TMAYORIGUAL TMENORIGUAL

%token <ident> TID
%token <cent> TINT TBOOL TCTE

/* TIPOS DE LOS NO-TEMINALES */

/* INFORMACION DE PARAMETROS*/
%type <paramInfo> paramForm
%type <paramInfo> listParamForm
%type <paramInfo> paramAct
%type <paramInfo> listParamAct

%type <funcion> declaFunc
%type <funcion> bloque

%type <tipo> tipoSimp

/* Ahora const y todas las expresiones usan <exp> para poder generar código */
%type <exp> const
%type <exp> expre
%type <exp> expreOP
%type <exp> expreLogic
%type <exp> expreIgual
%type <exp> expreRel
%type <exp> expreAd
%type <exp> expreMul
%type <exp> expreUna
%type <exp> expreSufi
%type <exp> instExpre

%type <emite> opUna opMul opAd opRel opIgual opLogic

/* Marcas de etiqueta (guardan si actual) */
%type <cent> marca

%%

/* PROGRAMA SERÁ LA ÚLTIMA REGLA EN REDUCIRSE */
programa
    :
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
    listDecla 
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
    ;

listDecla: 
      decla 
    | listDecla decla 
    ;

decla:
      declaVar 
    | declaFunc ;

/* DECLARAR VARIABLES Y FUNCIONES*/
declaVar: tipoSimp TID TPUNTOCOMA
    { 
        if (!insTdS(strdup($2), VARIABLE, $1.t, niv, dvar, -1))
            yyerror("Identificador de variable repetido");
        else {
            dvar += TALLA_TIPO_SIMPLE;
            if (niv == 0)
                tallaGlobales += TALLA_TIPO_SIMPLE;
        }
    }
    | tipoSimp TID TASIG const TPUNTOCOMA
    {
        if (!insTdS(strdup($2), VARIABLE, $1.t, niv, dvar, -1))
            yyerror("Identificador de variable repetido");
        else {
            if ($1.t != $4.t)
                yyerror("Error de tipos en la inicializacion de la variable");
            /* (Opcional) podrías generar aquí EASIG para inicializarla */
            dvar += TALLA_TIPO_SIMPLE;
            if (niv == 0)
                tallaGlobales += TALLA_TIPO_SIMPLE;
        }
    }
    | tipoSimp TID TCORCHAB TCTE TCORCHCERR TPUNTOCOMA 
    {
        int talla_arr = $4;
        if(talla_arr <= 0){
            yyerror("Talla inapropiada del array");
        } else {
            int ref = insTdA($1.t, talla_arr);
            if (!insTdS(strdup($2), VARIABLE, T_ARRAY, niv, dvar, ref))
                yyerror("Identificador del array repetido");
            else {
                dvar += talla_arr * TALLA_TIPO_SIMPLE;
                if (niv == 0)
                    tallaGlobales += talla_arr * TALLA_TIPO_SIMPLE;
            }
        }
    };

/* AQUÍ LA FUNCION PUEDE SER MAIN*/
declaFunc:
    tipoSimp TID 
    {
        niv++;
        cargaContexto(niv);
        dvar = 0;
        funcionActual = strdup($2);
        if (strcmp($2, "main") == 0) {
            etqMain = si;
        }
    }
    TPARAB paramForm TPARCERR
    {
        /* <<< AÑADIDO: nº de parámetros de esta función >>> */
        numParamActual = $5.num_params;

        if (strcmp($2, "main") == 0) {
            mainCount++;
        }

        SIMB simb = obtTdS($2);
        if (simb.t != T_ERROR) {
            yyerror("Función repetida");
            errorDeclFuncActual = 1;
        } else if (!insTdS(strdup($2), FUNCION, $1.t, niv-1, si, $5.ref)) {
            yyerror("Función repetida");
            errorDeclFuncActual = 1;
        } else {
            errorDeclFuncActual = 0;
        }
    }
    bloque
    {
        $$.tipo_return = $1.t;
        $$.nombre_func = strdup($2);
        dvar = $8.desp;
        $$.num_params = $5.num_params;

        if (errorDeclFuncActual) {
            yyerror("En la declaracion de la funcion");
            errorDeclFuncActual = 0;
        } else if ($8.tipo_return != $1.t) {
            yyerror("Error de tipos en el 'return'");
        }
    }
    ;

const:
      TCTE
      {
        /* constante entera: tipo ENTERO, creamos un temporal con ese valor */
        $$.t = T_ENTERO;
        $$.n = niv;
        $$.d = creaVarTemp();

        TIPO_ARG aVal = crArgEnt($1);        /* valor entero de la constante */
        TIPO_ARG aRes = crArgPos(niv, $$.d); /* posición del temporal        */

        emite(EASIG, aVal, crArgNul(), aRes);
      }
    | TTRUE
      {
        /* true: 1 */
        $$.t = T_LOGICO;
        $$.n = niv;
        $$.d = creaVarTemp();

        TIPO_ARG aVal = crArgEnt(1);
        TIPO_ARG aRes = crArgPos(niv, $$.d);

        emite(EASIG, aVal, crArgNul(), aRes);
      }
    | TFALSE
      {
        /* false: 0 */
        $$.t = T_LOGICO;
        $$.n = niv;
        $$.d = creaVarTemp();

        TIPO_ARG aVal = crArgEnt(0);
        TIPO_ARG aRes = crArgPos(niv, $$.d);

        emite(EASIG, aVal, crArgNul(), aRes);
      }
    ;

tipoSimp:
      TINT    { $$.t = T_ENTERO; }
    | TBOOL   { $$.t = T_LOGICO; }
    ;

paramForm:
    { 
        $$.ref = insTdD(-1, T_VACIO);
        $$.num_params = 0;
    }
    | listParamForm { 
        $$.num_params = $1.num_params; 
        $$.ref = $1.ref;
        }
    ;

listParamForm:
    tipoSimp TID 
    {
        $$.num_params = 1;
        $$.talla = TALLA_TIPO_SIMPLE+ TALLA_SEGENLACES;
        $$.ref = insTdD(-1, $1.t); 
        
        if(!insTdS(strdup($2), PARAMETRO, $1.t, niv, 0, -1)){
            yyerror("Identificador de parametro repetido");
        }
    }
    | listParamForm TCOMA tipoSimp TID 
    {
        $$.ref = insTdD($1.ref, $3.t);
        $$.num_params = $1.num_params + 1;
        $$.talla = $1.talla + TALLA_TIPO_SIMPLE;

        if (!insTdS(strdup($4), PARAMETRO, $3.t, niv, 0, -1)){
             yyerror("Identificador de parametro repetido");
        }
    }
    ;

bloque:
    TLLAVAB
    {
        TIPO_ARG argN = crArgNul();
        emite(PUSHFP, argN, argN, argN);
        emite(FPTOP,  argN, argN, argN);

        emite(INCTOP, argN, argN, argN);
        $<cent>$ = creaLans(si-1);
    }
    declaVarLocal listInst TRETURN expre TPUNTOCOMA TLLAVCERR 
    {
        $$.desp        = dvar;
        $$.num_params  = 0;
        $$.tipo_return = $6.t;

        /* Completar INCTOP locales+temporales */
        {
            TIPO_ARG argTalla = crArgEnt(dvar);
            completaLans($<cent>2, argTalla);
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
        if ($6.t != T_ERROR) {
            int despRet = -(numParamActual + 2);
            TIPO_ARG aSrc = crArgPos($6.n, $6.d);
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
    ;

declaVarLocal:
    /* vacío */
    | declaVarLocal declaVar ;

listInst:
    /* vacío */
    | listInst inst ;

inst:
      TLLAVAB listInst TLLAVCERR 
    | instExpre 
    | instEntSal 
    | instSelec 
    | instIter ;

instExpre:
      expre TPUNTOCOMA
      {
        $$.t = $1.t;
        $$.d = $1.d;
        $$.n = $1.n;
      }
    | TPUNTOCOMA
      {
        $$.t = T_VACIO;
        $$.d = 0;
        $$.n = 0;
      }
    ;  

instEntSal:
    TREAD TPARAB TID TPARCERR TPUNTOCOMA 
    {
        SIMB sim = obtTdS($3);
        if (sim.t == T_ERROR)
            yyerror("Variable no declarada en READ");
        else if (sim.t != T_ENTERO)
            yyerror("El argumento del 'read' debe ser 'entero'");
        else {
            TIPO_ARG aN = crArgNul();
            emite(EREAD, aN, aN, crArgPos(sim.n, sim.d));
        }
    }
    | TPRINT TPARAB expre TPARCERR TPUNTOCOMA
    {
        if ($3.t != T_ENTERO && $3.t != T_ERROR)
            yyerror("La expresion del 'print' debe ser 'entera'");
        else if ($3.t != T_ERROR) {
            TIPO_ARG aN = crArgNul();
            emite(EWRITE, crArgPos($3.n, $3.d), aN, aN);
        }
    }
    ;

/* ===== IF / IF-ELSE con saltos y LANS ===== */

instSelec:
    TIF TPARAB expre TPARCERR
    {
        if ($3.t != T_LOGICO && $3.t != T_ERROR)
            yyerror("La expresión de la instrucción if-else debe ser de tipo lógico");

        if ($3.t != T_ERROR) {
            TIPO_ARG a0   = crArgEnt(0);
            TIPO_ARG aNul = crArgNul();

            /* si cond == 0 saltaremos al ELSE (aún sin etiqueta) */
            emite(EIGUAL,
                  crArgPos($3.n, $3.d),
                  a0,
                  aNul);
            $<cent>$ = creaLans(si-1);  /* lista de saltos al else */
        } else {
            $<cent>$ = -1;
        }
    }
    inst
    {
        /* tras el then: salto incondicional al final del if-else */
        TIPO_ARG aN = crArgNul();
        emite(GOTOS, aN, aN, aN);

        /* parchear saltos de la condición hacia el inicio del else (ahora si) */
        if ($<cent>5 != -1) {
            TIPO_ARG aEtqElse = crArgEtq(si);
            completaLans($<cent>5, aEtqElse);
        }

        $<cent>$ = creaLans(si-1);   /* lista de saltos desde el then al final */
    }
    TELSE
    inst
    {
        /* completar saltos al final del if-else */
        if ($<cent>7 != -1) {
            TIPO_ARG aEtqFin = crArgEtq(si);
            completaLans($<cent>7, aEtqFin);
        }
    }
    ;

/* ===== FOR con saltos y LANS (semántica tipo for(init; cond; upd) inst) ===== */

instIter:
    TFOR TPARAB expreOP TPUNTOCOMA
    marca              /* $5: etiqueta de inicio de la condición */
    expre              /* $6: condición */
    TPUNTOCOMA
    {
        /* Punto tras evaluar la condición */
        $<listas>$.ltrue  = -1;
        $<listas>$.lfalse = -1;

        if ($6.t != T_LOGICO && $6.t != T_ERROR)
            yyerror("La expresion del 'for' debe ser 'logica'");

        if ($6.t != T_ERROR) {
            TIPO_ARG a0   = crArgEnt(0);
            TIPO_ARG aNul = crArgNul();

            /* si cond == 0 -> salida del bucle (Lend, aún desconocida) */
            emite(EIGUAL,
                  crArgPos($6.n, $6.d),
                  a0,
                  aNul);
            $<listas>$.lfalse = creaLans(si-1);

            /* si cond != 0 -> ir al cuerpo (Lbody, aún desconocida) */
            emite(GOTOS, aNul, aNul, aNul);
            $<listas>$.ltrue = creaLans(si-1);
        }
    }
    marca              /* $9: etiqueta de inicio del update */
    expreOP            /* update */
    TPARCERR
    {
        /* Estamos justo antes del cuerpo: si cond es true, venimos aquí */

        /* Parchear saltos verdaderos al comienzo del cuerpo (etiqueta actual) */
        if ($<listas>8.ltrue != -1) {
            TIPO_ARG aBody = crArgEtq(si);
            completaLans($<listas>8.ltrue, aBody);
        }

        /* Desde el final del update, volver a la condición */
        {
            TIPO_ARG aN    = crArgNul();
            TIPO_ARG aCond = crArgEtq($5);
            emite(GOTOS, aN, aN, aCond);
        }
    }
    inst               /* cuerpo del for */
    {
        /* Al final del cuerpo:
           1) ir al inicio del update
           2) completar saltos de salida (cond == 0) al punto actual (fin) */

        /* 1) goto inicio update ($9) */
        {
            TIPO_ARG aN   = crArgNul();
            TIPO_ARG aUpd = crArgEtq($9);
            emite(GOTOS, aN, aN, aUpd);
        }

        /* 2) completar lista de falsos (salida del bucle) */
        if ($<listas>8.lfalse != -1) {
            TIPO_ARG aEnd = crArgEtq(si);
            completaLans($<listas>8.lfalse, aEnd);
        }
    }
    ;

/* EXPRESIONES */

expreOP:
    /* Vacío */
    {
        $$.t = T_VACIO;
        $$.d = 0;
        $$.n = 0;
    }
    | expre 
    {
        $$.t = $1.t;
        $$.d = $1.d;
        $$.n = $1.n;
    }
    ;

expre:
    expreLogic 
    {
        $$.t = $1.t;
        $$.d = $1.d;
        $$.n = $1.n;
    }
    | TID TASIG expre 
    {   
        SIMB sim = obtTdS($1);
        if (sim.t == T_ERROR) {
            yyerror("Objeto no declarado");
            $$.t = T_ERROR;
        } else if (!(((sim.t == T_ENTERO) && ($3.t == T_ENTERO)) ||
                     ((sim.t == T_LOGICO) && ($3.t == T_LOGICO)))) {
            if ($3.t != T_ERROR)
                yyerror("Error de tipos en la 'instruccion de asignacion'");
            $$.t = T_ERROR;
        } else {
            /* código de asignación x = e */
            TIPO_ARG aSrc = crArgPos($3.n, $3.d);
            TIPO_ARG aN   = crArgNul();
            TIPO_ARG aDst = crArgPos(sim.n, sim.d);
            emite(EASIG, aSrc, aN, aDst);

            $$.t = $3.t;
            $$.d = sim.d;
            $$.n = sim.n;
        }
      }
    | TID TCORCHAB expre TCORCHCERR TASIG expre 
    {
        SIMB sim = obtTdS($1);
        if (sim.t == T_ERROR) {
            yyerror("Asignación a array no declarado");
            $$.t = T_ERROR;
        } else if (sim.t != T_ARRAY) {
            yyerror("La variable debe ser tipo 'array'");
            $$.t = T_ERROR;
        } else {
            if ($3.t != T_ENTERO && $3.t != T_ERROR)
                yyerror("El indice del 'array' debe ser entero");

            DIM info_arr = obtTdA(sim.ref);
            if ($6.t != T_ERROR && info_arr.telem != $6.t)
                yyerror("Error de tipos en la asignacion a un 'array'");

            if ($3.t == T_ENTERO && $6.t == info_arr.telem) {
                /* EVA src, idx, arr */
                TIPO_ARG aSrc = crArgPos($6.n, $6.d);
                TIPO_ARG aIdx = crArgPos($3.n, $3.d);
                TIPO_ARG aArr = crArgPos(sim.n, sim.d);
                emite(EVA, aSrc, aIdx, aArr);

                $$.t = $6.t;
                $$.d = sim.d;
                $$.n = sim.n;
            } else {
                $$.t = T_ERROR;
            }
        }
      }
      ;

expreLogic:
    expreIgual 
    {
        $$.t = $1.t;
        $$.d = $1.d;
        $$.n = $1.n;
    }
    | expreLogic opLogic expreIgual 
    {
        if ($1.t == T_ERROR || $3.t == T_ERROR) {
            $$.t = T_ERROR;
        } else if ($1.t != T_LOGICO || $3.t != T_LOGICO) {
            yyerror("Error de tipos en expresión lógica");
            $$.t = T_ERROR;
        } else {
            $$.t = T_LOGICO;
            $$.d = creaVarTemp();
            $$.n = niv;
            emite($2.e,
                  crArgPos($1.n, $1.d),
                  crArgPos($3.n, $3.d),
                  crArgPos($$.n, $$.d));
        }
    }
    ;

expreIgual:
    expreRel 
    {
        $$.t = $1.t;
        $$.d = $1.d;
        $$.n = $1.n;
    }
    | expreIgual opIgual expreRel 
    {
        if ($1.t == T_ERROR || $3.t == T_ERROR) {
            $$.t = T_ERROR;
        } else if ($1.t != $3.t) {
            yyerror("Error de tipos en expresión de igualdad");
            $$.t = T_ERROR;
        } else {
            $$.t = T_LOGICO;
            $$.d = creaVarTemp();
            $$.n = niv;
            emite($2.e,
                  crArgPos($1.n, $1.d),
                  crArgPos($3.n, $3.d),
                  crArgPos($$.n, $$.d));
        }
    }
    ;

expreRel:
    expreAd 
    {
        $$.t = $1.t;
        $$.d = $1.d;
        $$.n = $1.n;
    }
    | expreRel opRel expreAd 
    {
        if ($1.t == T_ERROR || $3.t == T_ERROR) {
            $$.t = T_ERROR;
        } else if ($1.t != T_ENTERO || $3.t != T_ENTERO) {
            yyerror("Error de tipos en expresión relacional");
            $$.t = T_ERROR;
        } else {
            $$.t = T_LOGICO;
            $$.d = creaVarTemp();
            $$.n = niv;
            emite($2.e,
                  crArgPos($1.n, $1.d),
                  crArgPos($3.n, $3.d),
                  crArgPos($$.n, $$.d));
        }
    }
    ;

/* EXPRESIONES ADITIVAS ( + y - ) */
expreAd:
    expreMul 
    {
        $$.t = $1.t;
        $$.d = $1.d;
        $$.n = $1.n;
    }
    | expreAd opAd expreMul 
    {
        if ($1.t == T_ERROR || $3.t == T_ERROR) {
            $$.t = T_ERROR;
        } else if ($1.t != T_ENTERO || $3.t != T_ENTERO) {
            yyerror("Error de tipos en 'expresion aditiva'");
            $$.t = T_ERROR;
        } else {
            $$.t = T_ENTERO;
            $$.d = creaVarTemp();
            $$.n = niv;
            emite($2.e,
                  crArgPos($1.n, $1.d),
                  crArgPos($3.n, $3.d),
                  crArgPos($$.n, $$.d));
        }
    }
    ;

/* EXPRESIONES MULTIPLICATIVAS ( * y / ) */
expreMul:
    expreUna 
    {
        $$.t = $1.t;
        $$.d = $1.d;
        $$.n = $1.n;
    }
    | expreMul opMul expreUna 
    {
        if ($1.t == T_ERROR || $3.t == T_ERROR) {
            $$.t = T_ERROR;
        } else if ($1.t != T_ENTERO || $3.t != T_ENTERO) {
            yyerror("Error de tipos en 'expresion multiplicativa'");
            $$.t = T_ERROR;
        } else {
            $$.t = T_ENTERO;
            $$.d = creaVarTemp();
            $$.n = niv;
            emite($2.e,
                  crArgPos($1.n, $1.d),
                  crArgPos($3.n, $3.d),
                  crArgPos($$.n, $$.d));
        }
    }
    ;

expreUna:
    expreSufi 
    {
        $$.t = $1.t;
        $$.d = $1.d;
        $$.n = $1.n;
    }
    | opUna expreUna 
    {
        /* '+' no hace nada, '-' y '!' se manejan según $1.e */
        if ($1.e == 0) {          /* '+' → no-op */
            $$.t = $2.t;
            $$.d = $2.d;
            $$.n = $2.n;
        }
        else if ($1.e == ESIG) {  /* '-' unario */
            if ($2.t == T_ERROR) {
                $$.t = T_ERROR;
            } else if ($2.t != T_ENTERO) {
                yyerror("Error de tipos en expresión unaria");
                $$.t = T_ERROR;
            } else {
                $$.t = T_ENTERO;
                $$.d = creaVarTemp();
                $$.n = niv;
                TIPO_ARG aN = crArgNul();
                emite(ESIG,
                      crArgPos($2.n, $2.d),
                      aN,
                      crArgPos($$.n, $$.d));
            }
        }
        else {                    /* '!' lógica: implementamos !E como (E == 0) */
            if ($2.t == T_ERROR) {
                $$.t = T_ERROR;
            } else if ($2.t != T_LOGICO) {
                yyerror("Error de tipos en expresión unaria lógica");
                $$.t = T_ERROR;
            } else {
                $$.t = T_LOGICO;
                $$.d = creaVarTemp();
                $$.n = niv;
                TIPO_ARG aZero = crArgEnt(0);
                emite(EIGUAL,
                      crArgPos($2.n, $2.d),
                      aZero,
                      crArgPos($$.n, $$.d));
            }
        }
    }
    ;

expreSufi:
    const 
    {
        $$.t = $1.t;
        $$.d = $1.d;
        $$.n = $1.n;
    }
    | TPARAB expre TPARCERR 
    {
        $$.t = $2.t;
        $$.d = $2.d;
        $$.n = $2.n;
    }
    | TID 
    {
        SIMB sim = obtTdS($1);
        if (sim.t == T_ERROR)
            yyerror("Uso de variable no declarada");
        $$.t = sim.t;
        $$.d = sim.d;
        $$.n = sim.n;
    }
    | TID TCORCHAB expre TCORCHCERR 
    {
        SIMB sim = obtTdS($1);
        if (sim.t == T_ERROR) {
            yyerror("Uso de array no declarado");
            $$.t = T_ERROR;
        } else if (sim.t != T_ARRAY) {
            yyerror("La variable debe ser tipo 'array'");
            $$.t = T_ERROR;
        } else {
            /* Verificar que el índice sea entero (si no fue ya error) */
            if ($3.t != T_ENTERO && $3.t != T_ERROR)
                yyerror("El indice del 'array' debe ser entero");

            if ($3.t == T_ENTERO) {
                /* Obtener info del array y crear temporal para el valor */
                DIM info_arr = obtTdA(sim.ref);
                $$.t = info_arr.telem;
                $$.n = niv;
                $$.d = creaVarTemp();

                /* Emitir EAV arr, idx, dest_temp */
                TIPO_ARG aArr = crArgPos(sim.n, sim.d);
                TIPO_ARG aIdx = crArgPos($3.n, $3.d);
                TIPO_ARG aRes = crArgPos($$.n, $$.d);
                emite(EAV, aArr, aIdx, aRes);
            } else {
                $$.t = T_ERROR;
            }
        }
    }
    /* === ESTRELLA: llamada a función === */
    | TID TPARAB
      {
          /* Reservamos espacio para el valor de retorno */
          TIPO_ARG aN = crArgNul();
          emite(EPUSH, aN, aN, crArgEnt(0));
      }
      paramAct TPARCERR 
    {
        SIMB sim = obtTdS($1);
        if (sim.t == T_ERROR) {
            yyerror("Uso de función no declarada");
            $$.t = T_ERROR;
            $$.d = 0;
            $$.n = 0;
        } else {
            /* Comprobación de parámetros (ya la tenías) */
            if (!cmpDom($4.ref, sim.ref)) {
                yyerror("Parámetros de la función no coinciden con la declaración");
                $$.t = T_ERROR;
                $$.d = 0;
                $$.n = 0;
            } else {
                TIPO_ARG aN = crArgNul();

                /* sim.d contiene la etiqueta (si) de inicio de la función */
                emite(CALL, aN, aN, crArgEtq(sim.d));

                /* Al volver:
                   Pila = [... RA llamante ... , ret, arg_1, ..., arg_k ]
                   Queremos:
                     - quitar los k argumentos
                     - quedarnos con ret en un temporal */
                if ($4.num_params > 0) {
                    emite(DECTOP, aN, aN, crArgEnt($4.num_params));
                }

                /* Crear temporal para el valor devuelto */
                $$.t = sim.t;
                $$.d = creaVarTemp();
                $$.n = niv;

                emite(EPOP, aN, aN, crArgPos($$.n, $$.d));
            }
        }
    }
    ;


paramAct: 
    /* Vacío*/      
    {
        $$.num_params = 0;
        $$.ref        = insTdD(-1, T_VACIO);
        $$.talla      = 0;
    }
    | listParamAct   
    {
        $$.num_params = $1.num_params;
        $$.ref        = $1.ref;
        $$.talla      = $1.talla;
    }
    ;


listParamAct:
    expre 
    {
        /* Último argumento --> crea dominio */
        $$.num_params = 1;
        $$.ref   = insTdD(-1, $1.t);
        $$.talla = TALLA_TIPO_SIMPLE;

        /* ESTRELLA: EPUSH del valor del argumento */
        if ($1.t != T_ERROR) {
            TIPO_ARG aN = crArgNul();
            emite(EPUSH, aN, aN, crArgPos($1.n, $1.d));
        }
    }
    | expre TCOMA listParamAct 
    {
        /* Añadimos un argumento a la izquierda */
        $$.num_params = $3.num_params + 1;
        $$.ref   = insTdD($3.ref, $1.t);
        $$.talla = $3.talla + TALLA_TIPO_SIMPLE;

        /* EPUSH del valor de este argumento.
           OJO: por la recursión, los EPUSH se generan
           de derecha a izquierda: arg_k, ..., arg_1. */
        if ($1.t != T_ERROR) {
            TIPO_ARG aN = crArgNul();
            emite(EPUSH, aN, aN, crArgPos($1.n, $1.d));
        }
    }
    ;

/* OPERADORES → códigos de operación 3D */

/* Para && y || usamos multiplicación y suma sobre 0/1 */
/*TODO LO SIGUIENTE YA ESTÁ HECHO*/

/*OPERACIONES*/
/*COMO NO HAY ELEMENTOS DE COD INTERMEDIO PARA AND Y OR, UTILIZAREMOS MULT Y SUM*/
opLogic: 
    TAND {$$.e = EMULT;}| TOR {$$.e = ESUM;};
opIgual:
    TIGUALQUE {$$.e = EIGUAL;} |TDISTINTOQUE {$$.e = EDIST;};
opRel:
    TMAYORQUE {$$.e = EMAY;}| TMENORQUE {$$.e = EMEN;} | TMAYORIGUAL {$$.e = EMAYEQ;}| TMENORIGUAL {$$.e = EMENEQ;};
/*SACADO DE LA PAG17*/
opAd:
    TMAS {$$.e = ESUM;}| TMENOS {$$.e = EDIF;};
opMul:
    TMULT {$$.e = EMULT;}| TDIV {$$.e = EDIVI;};
opUna: 
    TMAS {$$.e = ESUM;}| TMENOS {$$.e = EDIF;}| TEXCL {$$.e = ESIG;};
    ;

/* Marca de posición: guarda la etiqueta (si) del siguiente código */
marca:
    /* vacío */ { $$ = si; }
    ;

%%
