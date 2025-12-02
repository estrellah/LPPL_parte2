
%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "../include/header.h"
    #include "../include/libtds.h"
    extern int yylineno;

    /*PARA COMPROBAR SI HAY MAIN EN EL PROGRAMA*/
    int mainCount = 0;
    /* Temporales para manejar la insercion de funciones con mid-rule actions */
    int tipo_func = 0;
    
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

/* REGLAS - COMO CONSTRUIR CADA SÍMBOLO NO TERMINAL A PARTIR DE SUS PARTES*/
%%
/* PROGRAMA SERÁ LA ÚLTIMA REGLA EN REDUCIRSE, POR LO QUE ALLÍ COMPROBAREMOS EL NUM DE MAINS */
programa: listDecla 
    {
    if(verTdS) mostrarTdS();  
    fprintf(stderr, "DEBUG: ULTIMA REGLA");
    fflush(stderr);
        if (mainCount == 0)
            yyerror("El programa no tiene 'main'");
        else if (mainCount > 1)
            yyerror("Hay más de una función main");
    }
    ;
listDecla: 
    decla | listDecla decla ;
decla:
    declaVar | declaFunc ;

/* DECLARAR VARIABLES Y FUNCIONES*/
declaVar: tipoSimp TID TPUNTOCOMA  /* tipoSimp: $1, TID: $2, TPUNTOCOMA:$3. Ej --> int id; */
    { 
        /*Si ponerlo en la tabla de simbolos no da error...*/
        if (!insTdS(strdup($2), VARIABLE, $1.t, niv, dvar, -1)) yyerror("Identificador de variable repetido"); /* Variable ya declarada */
        else
            dvar += TALLA_TIPO_SIMPLE;
    }
    | tipoSimp TID TASIG const TPUNTOCOMA  /* tipoSimp: $1, TID: $2, TASIG:$3, const: $4, TPUNTOCOMA:$5 */
    {
        fprintf(stderr, "DEBUG: insTdS call (init var) name='%s' tipo=%d niv=%d desp=%d\n", $2, $1, niv, dvar);
        fflush(stderr);
        if (!insTdS(strdup($2), VARIABLE, $1.t, niv, dvar, -1)) yyerror("Identificador de variable repetido");
        else {
            if ($1.t != $4.t)
                yyerror("Error de tipos en la inicializacion de la variable");
            dvar += TALLA_TIPO_SIMPLE;
            }
    }
    | tipoSimp TID TCORCHAB TCTE TCORCHCERR TPUNTOCOMA 
    {
        int talla_arr =$4;
        /*Si la talla es menor o igual que 0, no es válida*/
        if(talla_arr <=0){ yyerror("Talla inapropiada del array");}
            else{
                /*Insertamos el tipo y la talla en la tabla de arrays*/
                int ref = insTdA($1.t, talla_arr); /*Tiene referencia porque es un array*/
                    
                fprintf(stderr, "DEBUG: insTdS call (array) name='%s' tipo=T_ARRAY niv=%d desp=%d ref=%d\n", $2, niv, dvar, ref);
                fflush(stderr);
                if (!insTdS(strdup($2), VARIABLE, T_ARRAY, niv, dvar, ref)) yyerror("Identificador del array repetido");
                else
                    dvar += talla_arr * TALLA_TIPO_SIMPLE;
                
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
    }
    TPARAB paramForm TPARCERR
    {    /*OBJETIVO: Insertar informacion de la funcion en la TdS */
        if (strdup($2) && strcmp(strdup($2), "main") == 0) { mainCount++; }
        
        SIMB simb = obtTdS(strdup($2));
        if (simb.t != T_ERROR) {
            yyerror("Función repetida");
        } else if (!insTdS(strdup($2), FUNCION, $1.t, niv-1, dvar, $2)) {
            yyerror("Función repetida");
        }
        
    }
    bloque
     /* Mostrar la informacion de la funcion en la TdS */
    /* Gestion del contexto y recuperar ‘‘dvar’’*/{
        $$.tipo_return = $1.t;
        $$.nombre_func = strdup($2);
        if (verTdS) { mostrarTdS(); }
		dvar = $8.desp;
		$$.num_params = $5.num_params;
        if($8.tipo_return != $1.t){
            yyerror("Error de tipos en el 'return'");
        }
    }
    ;


const:
    TCTE        { $$.t = T_ENTERO; } /*SINTETIZA TIPO*/
    | TTRUE     { $$.t = T_LOGICO; }
    | TFALSE    { $$.t = T_LOGICO; }
    ;
tipoSimp:
    TINT    {$$.t = T_ENTERO;}
    | TBOOL {$$.t = T_LOGICO;};

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
    TLLAVAB declaVarLocal listInst TRETURN expre TPUNTOCOMA TLLAVCERR 
    {
        /*Verificar tipo del return vs tipo de función*/

        $$.desp = dvar;
        $$.num_params = 0;
        $$.tipo_return = $5.t;

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
    TLLAVAB listInst TLLAVCERR | instExpre | instEntSal | instSelec |instIter ;
instExpre:
    expre TPUNTOCOMA    {$$.t = $1.t;}
    | TPUNTOCOMA        {$$.t = T_VACIO;}
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
        if (sim.t == T_ERROR)
            yyerror("Uso de función no declarada");
        else {
        /*Comprueba coincidencia de dominios (parámetros) */
            /* si ambos -1 => sin parámetros -> OK */
            if (!($3.num_params == -1 && sim.ref == -1)) {
                if (!cmpDom($3.num_params, sim.ref))
                    yyerror("Parámetros de la función no coinciden con la declaración");
            }
        }
          $$.t = sim.t;
      };

paramAct: 
    /* Vacío*/      {$$.num_params = -1;}
    |listParamAct   {$$.num_params = $1.num_params;}; 
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

/*OPERACIONES, NO ALMACENAN NADA*/
opLogic: 
    TAND | TOR;
opIgual:
    TIGUALQUE |TDISTINTOQUE;
opRel:
    TMAYORQUE | TMENORQUE | TMAYORIGUAL | TMENORIGUAL ;
opAd:
    TMAS | TMENOS ;
opMul:
    TMULT | TDIV;
opUna: 
    TMAS | TMENOS | TEXCL;

%%
