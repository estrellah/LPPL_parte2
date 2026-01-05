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

    /* nombre de la función que se está compilando ahora */
    char *funcionActual = NULL;
%}

/* ATRIBUTOS */
%union {
    char *ident;    /* Nombre del identificador*/
    int cent;       /* Valor de la cte numerica entera */

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
        fprintf(stderr, "DEBUG: ULTIMA REGLA");
        fflush(stderr);

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
            /* (Opcional) aquí podrías generar un EASIG para inicializar la variable */
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
        /* true: lo representamos como 1 */
        $$.t = T_LOGICO;
        $$.n = niv;
        $$.d = creaVarTemp();

        TIPO_ARG aVal = crArgEnt(1);         /* OJO: aquí ya NO usamos $1    */
        TIPO_ARG aRes = crArgPos(niv, $$.d);

        emite(EASIG, aVal, crArgNul(), aRes);
      }
    | TFALSE
      {
        /* false: lo representamos como 0 */
        $$.t = T_LOGICO;
        $$.n = niv;
        $$.d = creaVarTemp();

        TIPO_ARG aVal = crArgEnt(0);         /* Tampoco usamos $1 aquí       */
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
        /* PRÓLOGO DE FUNCIÓN */
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

        /* EPÍLOGO DE FUNCIÓN */
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

instSelec:
    TIF TPARAB expre TPARCERR inst TELSE inst 
    {
        if ($3.t != T_LOGICO)
            yyerror("La expresión de la instrucción if-else debe ser de tipo lógico");
        /* Código de salto condicional se haría aquí (otra parte del grupo) */
    }
    ;

instIter:
    TFOR TPARAB expreOP TPUNTOCOMA expre TPUNTOCOMA expreOP TPARCERR inst 
    {
        if ($5.t != T_LOGICO)
            yyerror("La expresion del 'for' debe ser 'logica'");
        /* Saltos de bucle se harían aquí */
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
            /* usamos EMULT para && y ESUM para || sobre 0/1 */
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
        /* Distinguimos +, -, ! por el código en $1.e */
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
            if ($3.t != T_ENTERO && $3.t != T_ERROR)
                yyerror("El indice del \"array\" debe ser entero");

            DIM info_arr = obtTdA(sim.ref);
            $$.t = info_arr.telem;
            if ($3.t == T_ENTERO) {
                /* EAV arr, idx, res */
                $$.d = creaVarTemp();
                $$.n = niv;
                emite(EAV,
                      crArgPos(sim.n, sim.d),
                      crArgPos($3.n, $3.d),
                      crArgPos($$.n, $$.d));
            } else {
                $$.d = 0;
                $$.n = 0;
            }
        }
      }
    | TID TPARAB paramAct TPARCERR 
    {
        SIMB sim = obtTdS($1);
        if (sim.t == T_ERROR) {
            yyerror("Uso de función no declarada");
            $$.t = T_ERROR;
            $$.d = 0;
            $$.n = 0;
        } else {
            if (!cmpDom($3.ref, sim.ref)) {
                yyerror("Parámetros de la función no coinciden con la declaración");
                $$.t = T_ERROR;
            } else {
                /* Aquí iría la secuencia completa de llamada (EPUSH, CALL, etc.) */
                /* Por ahora solo modelamos que devuelve algo de tipo sim.t en un temporal */
                $$.t = sim.t;
                $$.d = creaVarTemp();
                $$.n = niv;
                /* TODO: generar código real de llamada */
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
        $$.num_params = 1;
        $$.ref = insTdD(-1, $1.t);
        $$.talla = TALLA_TIPO_SIMPLE;
    }
    | expre TCOMA listParamAct 
    {
        $$.num_params = $3.num_params + 1;
        $$.ref = insTdD($3.ref, $1.t);
        $$.talla = TALLA_TIPO_SIMPLE;
    }
    ;

/* OPERADORES → códigos de operación 3D */

/* Para && y || usamos multiplicación y suma sobre 0/1 */
opLogic: 
      TAND { $$.e = EMULT; }
    | TOR  { $$.e = ESUM;  }
    ;

opIgual:
      TIGUALQUE     { $$.e = EIGUAL; }
    | TDISTINTOQUE  { $$.e = EDIST;  }
    ;

opRel:
      TMAYORQUE     { $$.e = EMAY;   }
    | TMENORQUE    { $$.e = EMEN;   }
    | TMAYORIGUAL  { $$.e = EMAYEQ; }
    | TMENORIGUAL  { $$.e = EMENEQ; }
    ;

/* + y - binarios */
opAd:
      TMAS   { $$.e = ESUM; }
    | TMENOS { $$.e = EDIF; }
    ;

/* * y / */
opMul:
      TMULT  { $$.e = EMULT; }
    | TDIV   { $$.e = EDIVI; }
    ;

/* unarios: +, -, ! 
   mapeo:
   '+' → e = 0  (no-op)
   '-' → e = ESIG
   '!' → e = -1 (lo tratamos aparte)
*/
opUna: 
      TMAS   { $$.e = 0;    }
    | TMENOS { $$.e = ESIG; }
    | TEXCL  { $$.e = -1;   }
    ;

%%

