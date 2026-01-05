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
    }funcion;
    struct {
        int e;
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
/*NUEVO: TIPOS DE LOS NO-TEMINALES*/

/*INFORMACION DE PARAMETROS*/
%type <paramInfo> paramForm
%type <paramInfo> listParamForm
%type <paramInfo> paramAct
%type <paramInfo> listParamAct

%type <funcion> declaFunc
%type <funcion> bloque
/*AL SER ENTEROS LOS TIPOS, CADA UNA DE LAS SIGUIENTES ALMACENARÁ UN ENTERO*/
%type <tipo> tipoSimp
/*El no terminal const va a usar el campo .t de la estructura 'tipo' %union*/
%type <tipo> const
%type <tipo> expre
%type <tipo> expreOP
%type <tipo> expreLogic
%type <tipo> expreIgual
%type <tipo> expreRel
%type <tipo> expreAd
%type <tipo> expreMul
%type <tipo> expreUna
%type <tipo> expreSufi
%type <tipo> instExpre
%type <emite> opUna opMul opAd opRel opIgual opLogic

/* REGLAS - COMO CONSTRUIR CADA SÍMBOLO NO TERMINAL A PARTIR DE SUS PARTES*/
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

        /* (Opcional) descarga del contexto global:
         * descargaContexto(niv);   // si lo queréis usar
         */
    }
    ;
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

        /* (Opcional) descarga del contexto global:
         * descargaContexto(niv);   // si lo queréis usar
         */
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
declaVar: tipoSimp TID TPUNTOCOMA  /* tipoSimp: $1, TID: $2, TPUNTOCOMA:$3. Ej --> int id; */
    { 
        /*Si ponerlo en la tabla de simbolos no da error...*/
        if (!insTdS(strdup($2), VARIABLE, $1.t, niv, dvar, -1))
            yyerror("Identificador de variable repetido"); /* Variable ya declarada */
        else {
            dvar += TALLA_TIPO_SIMPLE;
            /* PARTE 3: si es global (niv==0), acumular talla en tallaGlobales */
            if (niv == 0)
                tallaGlobales += TALLA_TIPO_SIMPLE;
        }
    }
    | tipoSimp TID TASIG const TPUNTOCOMA  /* tipoSimp: $1, TID: $2, TASIG:$3, const: $4, TPUNTOCOMA:$5 */
    {
        /* O lo quitas directamente si ya no necesitas el debug */
        fprintf(stderr,
                "DEBUG: insTdS call (init var) name='%s' tipo=%d niv=%d desp=%d\n",
                $2, $1.t, niv, dvar);
        fflush(stderr);

        if (!insTdS(strdup($2), VARIABLE, $1.t, niv, dvar, -1))
            yyerror("Identificador de variable repetido");
        else {
            if ($1.t != $4.t)
                yyerror("Error de tipos en la inicializacion de la variable");
            dvar += TALLA_TIPO_SIMPLE;
            if (niv == 0)
                tallaGlobales += TALLA_TIPO_SIMPLE;
        }
    }
    | tipoSimp TID TCORCHAB TCTE TCORCHCERR TPUNTOCOMA 
    {
        int talla_arr = $4;
        /*Si la talla es menor o igual que 0, no es válida*/
        if(talla_arr <= 0){
            yyerror("Talla inapropiada del array");
        } else {
            /*Insertamos el tipo y la talla en la tabla de arrays*/
            int ref = insTdA($1.t, talla_arr); /*Tiene referencia porque es un array*/
                    
            fprintf(stderr, "DEBUG: insTdS call (array) name='%s' tipo=T_ARRAY niv=%d desp=%d ref=%d\n", $2, niv, dvar, ref);
            fflush(stderr);
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
    {    /*OBJETIVO: Gestion del contexto y guardar ‘‘dvar’’*/
        /*Entrar en nuevo nivel ANTES de procesar parámetros */
        niv++;
        cargaContexto(niv);
        dvar = 0; /*Se resetea el desplazamiento*/

        /* === PARTE 3: información de función actual y etiqueta === */

        /* Guardar el nombre de la función actual (para saber si es main) */
        funcionActual = strdup($2);

        /* La función empieza en la instrucción actual 'si' */
        if (strcmp($2, "main") == 0) {
            etqMain = si;
        }
    }
        TPARAB paramForm TPARCERR
    {    /*OBJETIVO: Insertar informacion de la funcion en la TdS */
        /* ¿Es main? contamos cuántas hay */
        if (strcmp($2, "main") == 0) {
            mainCount++;
        }

        /* Insertar la funcion en la TdS de nivel global (niv-1) */
        SIMB simb = obtTdS($2);
        if (simb.t != T_ERROR) {
            yyerror("Función repetida");
            errorDeclFuncActual = 1;
        } else if (!insTdS(strdup($2), FUNCION, $1.t, niv-1, si, $5.ref)) {
            /*            ***********  ^^^  AQUÍ  ^^^  *********** */
            yyerror("Función repetida");
            errorDeclFuncActual = 1;
        } else {
            errorDeclFuncActual = 0;
        }
    }

    bloque
    /* Gestion del contexto y recuperar ‘‘dvar’’*/
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
      TCTE        { $$.t = T_ENTERO; } /*SINTETIZA TIPO*/
    | TTRUE       { $$.t = T_LOGICO; }
    | TFALSE      { $$.t = T_LOGICO; }
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
        /*Primer parámetro (último en la lista), se crea dominio*/
        $$.ref = insTdD(-1, $1.t); 
        
        /*Insertar parámetro en orden inverso */
        if(!insTdS(strdup($2), PARAMETRO, $1.t, niv, 0, -1)){
            yyerror("Identificador de parametro repetido");
        }
    }
    | listParamForm TCOMA tipoSimp TID 
    {
        /*Insertar param con el dominio ya creado --> en orden inverso */
        $$.ref = insTdD($1.ref, $3.t);
        $$.num_params = $1.num_params + 1;
        $$.talla = $1.talla + TALLA_TIPO_SIMPLE;

        /*Añadir param en TDS en posición correcta */
        if (!insTdS(strdup($4), PARAMETRO, $3.t, niv, 0, -1)){
             yyerror("Identificador de parametro repetido");
        }
    }
    ;
bloque:
    TLLAVAB
    {
        /* === PRÓLOGO DE FUNCIÓN: enlaces de control y reserva de RA === */
        TIPO_ARG argN = crArgNul();

        /* Enlaces de control */
        emite(PUSHFP, argN, argN, argN);
        emite(FPTOP,  argN, argN, argN);

        /* Reserva de espacio para variables locales + temporales.
           Talla desconocida todavía: dejamos el resultado (res) nulo
           y guardamos la instrucción en una lista de pendientes.   */
        emite(INCTOP, argN, argN, argN);
        /* Guardamos la lista de LANS de esta INCTOP en el atributo cent */
        $<cent>$ = creaLans(si-1);
    }
    declaVarLocal listInst TRETURN expre TPUNTOCOMA TLLAVCERR 
    {
        /*Verificar tipo del return vs tipo de función*/
        $$.desp        = dvar;
        $$.num_params  = 0;
        $$.tipo_return = $6.t;  /* OJO: ahora el return es el 6º símbolo */

        /* === COMPLETAR RESERVA DE LOCALES+TEMPORALES === */
        {
            TIPO_ARG argTalla = crArgEnt(dvar);
            /* La acción intermedia está en la posición 2 de la producción */
            completaLans($<cent>2, argTalla);
        }

        /* === EPÍLOGO DE FUNCIÓN: liberar RA y enlaces de control === */
        {
            TIPO_ARG argN = crArgNul();

            /* Liberar segmento de variables locales y temporales */
            emite(TOPFP, argN, argN, argN);
            emite(FPPOP, argN, argN, argN);

            /* FIN o RET según sea main u otra función */
            if (funcionActual != NULL && strcmp(funcionActual, "main") == 0) {
                emite(FIN, argN, argN, argN);
            } else {
                emite(RET, argN, argN, argN);
            }
        }

        /* Mostrar TdS de esta funcion (global + locales + parámetros) */
        if (verTdS) mostrarTdS();

        /*Descargar el contexto de la función al terminar su bloque */
        descargaContexto(niv);
        niv--;
    }
    ;

declaVarLocal:
    | declaVarLocal declaVar ;

listInst:
    | listInst inst ;
inst:
      TLLAVAB listInst TLLAVCERR 
    | instExpre 
    | instEntSal 
    | instSelec 
    | instIter ;
instExpre:
      expre TPUNTOCOMA    { $$.t = $1.t; }
    | TPUNTOCOMA          { $$.t = T_VACIO; }
    ;  
instEntSal:
    TREAD TPARAB TID TPARCERR TPUNTOCOMA 
    {
        SIMB sim = obtTdS($3);
        if (sim.t == T_ERROR)
            yyerror("Variable no declarada en READ");
        else if (sim.t != T_ENTERO)
            yyerror("El argumento del 'read' debe ser 'entero'");
    }
    | TPRINT TPARAB expre TPARCERR TPUNTOCOMA
    {
        /* Verificar que la expresión sea de tipo entero */
        if ($3.t != T_ENTERO && $3.t != T_ERROR)
            yyerror("La expresion del 'print' debe ser 'entera'");
    };
instSelec:
    TIF TPARAB expre TPARCERR inst TELSE inst 
    {
        if ($3.t != T_LOGICO)
            yyerror("La expresión de la instrucción if-else debe ser de tipo lógico");
    }
    ;
instIter:
    TFOR TPARAB expreOP TPUNTOCOMA expre TPUNTOCOMA expreOP TPARCERR inst 
    {
        /* Verificar que la expresión de la condición sea de tipo lógico (TBOOL) */
        /* La expresión del medio es obligatoria y debe ser de tipo lógico */
        if ($5.t != T_LOGICO)
            yyerror("La expresion del 'for' debe ser 'logica'");
    }
    ;

/* EXPRESIONES, DEVUELVEN EL TIPO*/
expreOP:
    /* Vacío */
    {
        $$.t = T_VACIO;  /*TIPO POR DEFECTO CUANDO ESTÁ VACÍO*/
    }
    | expre 
    {
        $$.t = $1.t;  /*SINTETIZA EL TIPO*/
    }
    ;
expre:
    expreLogic 
    {
        $$.t = $1.t;
    }
    | TID TASIG expre 
    {   /* Este es el ejemplo que nos han dado*/
        SIMB sim = obtTdS($1);
        if (sim.t == T_ERROR) yyerror("Objeto no declarado");
        else if (! (((sim.t == T_ENTERO) && ($3.t == T_ENTERO)) ||
                ((sim.t == T_LOGICO) && ($3.t == T_LOGICO))) )
                if($3.t!= T_ERROR)
                    yyerror("Error de tipos en la 'instruccion de asignacion'");
        /* Propagar el tipo de la expresión (puede ser T_ERROR) */
        $$.t = $3.t;
      }
    | TID TCORCHAB expre TCORCHCERR TASIG expre 
    {
        SIMB sim = obtTdS($1);
        if (sim.t == T_ERROR)
            yyerror("Asignación a array no declarado");
        else{
            if(sim.t != T_ARRAY){
                yyerror("La variable debe ser tipo 'array'");
            }
            else {
                /*Verificar que el índice sea entero (si no fue ya error) */
                if ($3.t != T_ENTERO && $3.t != T_ERROR)
                    yyerror("El indice del 'array' debe ser entero");
                else{
                    DIM info_arr = obtTdA(sim.ref);
                    /*Solo emitir error si la expresión no vino ya marcada como error */
                    if ($6.t != T_ERROR && info_arr.telem != $6.t) {
                        yyerror("Error de tipos en la asignacion a un 'array'");
                    }
                }
            }
            
            /*Propagar el tipo (puede ser T_ERROR) */
            $$.t = $6.t; 
        }
      }
      ;
expreLogic:
    expreIgual 
    {
        $$.t = $1.t;
    }
    | expreLogic opLogic expreIgual 
    {
        /*Operaciones lógicas requieren operandos lógicos */
        if ($1.t == T_ERROR || $3.t == T_ERROR) {
            $$.t = T_ERROR;
        } else if ($1.t != T_LOGICO || $3.t != T_LOGICO) {
            yyerror("Error de tipos en expresión lógica");
            $$.t = T_ERROR;
        } else {
            $$.t = T_LOGICO;
        }
    }
    ;
expreIgual:
    expreRel 
    {
        $$.t = $1.t;
    }
    | expreIgual opIgual expreRel 
    {
        /*Las comparaciones de igualdad requieren operandos del mismo tipo */
        if ($1.t == T_ERROR || $3.t == T_ERROR) {
            $$.t = T_ERROR;
        } else if ($1.t != $3.t) {
            yyerror("Error de tipos en expresión de igualdad");
            $$.t = T_ERROR;
        } else {
            $$.t = T_LOGICO;
        }
    }
    ;
expreRel:
    expreAd 
    {
        $$.t = $1.t;
    }
    | expreRel opRel expreAd 
    {
        /* Las relaciones requieren operandos enteros */
        if ($1.t == T_ERROR || $3.t == T_ERROR) {
            $$.t = T_ERROR;
        } else if ($1.t != T_ENTERO || $3.t != T_ENTERO) {
            yyerror("Error de tipos en expresión relacional");
            $$.t = T_ERROR;
        } else {
            $$.t = T_LOGICO;
        }
    }
    ;

/*SACADO DE LA PAG17*/
expreAd:
    expreMul 
    {
        $$.t = $1.t;
    }
    | expreAd opAd expreMul 
    {
        /* Suma/resta requieren operandos enteros */
        if ($1.t == T_ERROR || $3.t == T_ERROR) {
            $$.t = T_ERROR;
        } else if ($1.t != T_ENTERO || $3.t != T_ENTERO) {
            yyerror("Error de tipos en 'expresion aditiva'");
            $$.t = T_ERROR;
        } else {
            $$.t = T_ENTERO;
        }
        emite($2, crArgPos(niv, $1.d), crArgPos(niv, $3.d), crArgPos(niv, $$.d));
    }
    ;
expreMul:
    expreUna 
    {
        $$.t = $1.t;
    }
    | expreMul opMul expreUna 
    {
        /* Multiplicación/división requieren operandos enteros */
        if ($1.t == T_ERROR || $3.t == T_ERROR) {
            $$.t = T_ERROR;
        } else if ($1.t != T_ENTERO || $3.t != T_ENTERO) {
            yyerror("Error de tipos en 'expresion multiplicativa'");
            $$.t = T_ERROR; /* Propagar que hubo un error de tipos */
        } else {
            $$.t = T_ENTERO;
        }
    }
    ;
expreUna:
    expreSufi 
    {
        $$.t = $1.t;
    }
    | opUna expreUna 
    {
        /*Operadores unarios conservan el tipo (solo para enteros) */
        if ($2.t == T_ERROR) {
            $$.t = T_ERROR;
        } else if ($2.t != T_ENTERO) {
            yyerror("Error de tipos en expresión unaria");
            $$.t = T_ERROR;
        } else {
            $$.t = T_ENTERO;
        }
    }
    ;
expreSufi:
    const 
    {
        /*Propagar el tipo de la constante (entero o lógico) */
        $$.t = $1.t;
    }
    | TPARAB expre TPARCERR 
    {
        $$.t = $2.t;
    }
    | TID 
    {
        SIMB sim = obtTdS($1);
        if (sim.t == T_ERROR)
            yyerror("Uso de variable no declarada");
        $$.t = sim.t; 
      }
    | TID TCORCHAB expre TCORCHCERR 
    {
        SIMB sim = obtTdS($1);
        if (sim.t == T_ERROR)
            yyerror("Uso de array no declarado");

        /*Verificar que el índice sea entero */
        if ($3.t != T_ENTERO && $3.t != T_ERROR)
            yyerror("El indice del \"array\" debe ser entero");
        $$.t = sim.t;
      }
    | TID TPARAB paramAct TPARCERR 
    {
        SIMB sim = obtTdS($1);
        if (sim.t == T_ERROR) {
            yyerror("Uso de función no declarada");
        } else {
            /* Comprobar que el dominio de los parametros actuales coincide con el de la funcion */
            if (!cmpDom($3.ref, sim.ref)) {
                yyerror("Parámetros de la función no coinciden con la declaración");
            }
        }
        $$.t = sim.t;
    };


paramAct: 
    /* Vacío*/      
    {
        /* Dominio vacío: 0 parámetros actuales */
        $$.num_params = 0;
        $$.ref        = insTdD(-1, T_VACIO);
        $$.talla      = 0;
    }
    | listParamAct   
    {
        /* Copiamos el dominio construido en listParamAct */
        $$.num_params = $1.num_params;
        $$.ref        = $1.ref;
        $$.talla      = $1.talla;
    }
    ;
listParamAct:
    expre 
    {
        /*Último argumento --> crea nuevo dominio */
        $$.num_params = 1;
        $$.ref = insTdD(-1, $1.t);
        $$.talla = TALLA_TIPO_SIMPLE;
    }
    | expre TCOMA listParamAct 
        {$$.num_params = $3.num_params + 1;    // suma al resto de parámetros
        $$.ref = insTdD($3.ref, $1.t);          // encadena dominios
        $$.talla = TALLA_TIPO_SIMPLE;}
    ;

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

%%
