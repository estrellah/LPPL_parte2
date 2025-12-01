/*CADA VALOR SEMÁNTICO PUEDE CONTENER O UN INT O UN CHAR*/
%union {
    int i;
    char *s;
}

%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "../include/header.h"
    #include "../include/libtds.h"
    extern int yylineno;

    /*PARA COMPROBAR SI HAY MAIN EN EL PROGRAMA*/
    int mainCount = 0;
     /* Tipo de retorno declarado de la función actualmente procesada (parser-local)
         Usamos esta variable en lugar de llamar a obtTdD(-1) para evitar acceder
         a estructuras internas de la TdS que podrían estar en un estado
         inconsistente y provocar un segfault. */
     int current_func_return = T_ERROR;
    /* Temporales para manejar la insercion de funciones con mid-rule actions */
    char * nombre_func = NULL;
    int tipo_func = 0;
    
%}

%token <s> TID
%token <i> TINT TBOOL TCTE
/*OPERADORES*/
%token TASIG TMAS TMENOS TDIV TMULT
%token TEXCL TFALSE TTRUE TAND TOR
%token TPARAB TPARCERR TLLAVAB TLLAVCERR TCORCHAB TCORCHCERR
%token TPUNTOCOMA TCOMA
%token TREAD TPRINT TIF TELSE TFOR TRETURN

/*COMPARACIONES*/
%token TIGUALQUE TDISTINTOQUE TMAYORQUE TMENORQUE TMAYORIGUAL TMENORIGUAL

/*NUEVO: TIPOS DE LOS NO-TEMINALES*/
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
%type <i> expreOP
%type <i> paramAct
%type <i> listParamAct

/* REGLAS - COMO CONSTRUIR CADA SÍMBOLO NO TERMINAL A PARTIR DE SUS PARTES*/
%%
/* PROGRAMA SERÁ LA ÚLTIMA REGLA EN REDUCIRSE, POR LO QUE ALLÍ COMPROBAREMOS EL NUM DE MAINS */
programa: listDecla 
    {
        
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
    {   /*El res_b es el resultado de la búsqueda*/
        int res_b = 0;

        /*Ahora se verá si ya hay una variable con ese nombre y tipo.
        Además, el strdup nos permite pasar el valor a String*/

        fprintf(stderr, "DEBUG: insTdS call (var) name='%s' tipo=%d niv=%d desp=%d\n", $2, $1, niv, dvar);
        fflush(stderr);
        res_b = insTdS(strdup($2), VARIABLE, $1, niv, dvar, -1);
        if (!res_b) yyerror("Identificador variable repetido"); /* Variable ya declarada */
        else
            dvar += TALLA_TIPO_SIMPLE;
    }
    | tipoSimp TID TASIG const TPUNTOCOMA  /* tipoSimp: $1, TID: $2, TASIG:$3, const: $4, TPUNTOCOMA:$5 */
    {
        int res_b = 0;
        fprintf(stderr, "DEBUG: insTdS call (init var) name='%s' tipo=%d niv=%d desp=%d\n", $2, $1, niv, dvar);
        fflush(stderr);
        res_b = insTdS(strdup($2), VARIABLE, $1, niv, dvar, -1);
        if (!res_b) yyerror("Identificador variable repetido");
        else {
            /* Comprobar que el tipo de la inicialización coincide con el declarado */
            if ($1 != $4)
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
                int ref = insTdA($1, talla_arr); /*Tiene referencia porque es un array*/
                    
                int res_b = 0;
                fprintf(stderr, "DEBUG: insTdS call (array) name='%s' tipo=T_ARRAY niv=%d desp=%d ref=%d\n", $2, niv, dvar, ref);
                fflush(stderr);
                res_b = insTdS(strdup($2), VARIABLE, T_ARRAY, niv, dvar, ref);
                if (!res_b) yyerror("Identificador del array repetido");
                else
                    dvar += talla_arr * TALLA_TIPO_SIMPLE;
                
            }
    };

/* AQUÍ LA FUNCION PUEDE SER MAIN*/
declaFunc:
    tipoSimp TID 
    {    /*OBJETIVO: Gestion del contexto y guardar ‘‘dvar’’*/
        /*Se guarda la informacion necesaria para posteriormente agregarlo en la tds*/
        tipo_func = $1;
        nombre_func = strdup($2);
        /*Entrar en nuevo nivel ANTES de procesar parámetros */
        niv++;
        cargaContexto(niv);
        dvar = 0; /*Se resetea el desplazamiento*/
    }
    TPARAB paramForm TPARCERR
    {    /*OBJETIVO: Insertar informacion de la funcion en la TdS */
        /* Ahora paramForm ha creado el dominio y ha insertado parámetros en `niv`.
           Insertar la función en el nivel exterior (niv-1) usando la referencia devuelta por paramForm ($1). */
        int ref = $2;
        if (nombre_func && strcmp(nombre_func, "main") == 0) { mainCount++; }
        
        SIMB simb = obtTdS(nombre_func);
        if (simb.t != T_ERROR && simb.n == niv-1) {
            yyerror("Función repetida");
        } else if (!insTdS(nombre_func, FUNCION, tipo_func, niv-1, dvar, ref)) {
            yyerror("Función repetida");
        } else {
            /* Guardar localmente el tipo de retorno de la función actual
               para evitar llamadas inseguras a obtTdD(-1) durante el parseo. */
            current_func_return = tipo_func;
        }
        
    }
    bloque
     /* Mostrar la informacion de la funcion en la TdS */
    /* Gestion del contexto y recuperar ‘‘dvar’’*/{

    }
    ;


const:
    TCTE        { $$ = T_ENTERO; } /*Sintetiza tipo*/
    | TTRUE     { $$ = T_LOGICO; }
    | TFALSE    { $$ = T_LOGICO; }
    ;
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
        if(!insTdS(strdup($2), PARAMETRO, $1, niv, 0, -1)){
            yyerror("Identificador de parametro repetido");
        }
    }
    | listParamForm TCOMA tipoSimp TID 
    {
        /*Insertar param con el dominio ya creado --> en orden inverso */
        $$ = insTdD($1, $3);

        /*Añadir param en TDS en posición correcta */
        if (!insTdS(strdup($4), PARAMETRO, $3, niv, 0, -1)){
             yyerror("Identificador de parametro repetido");
        }
    }
    ;
bloque:
    TLLAVAB declaVarLocal listInst TRETURN expre TPUNTOCOMA TLLAVCERR 
    {
        /* Verificar que el tipo de la expresión del return coincide con el tipo
   declarado para la función actual (obtTdD(-1) devuelve info de la función). */
        /* Usar la variable parser-local `current_func_return` en lugar de
           llamar a `obtTdD(-1)` (evita acceder a estructuras internas que
           pueden no estar listas y provocar segfault). */
        fprintf(stderr, "DEBUG: current_func_return=%d\n", current_func_return);
        fflush(stderr);
        if (current_func_return != T_ERROR) {
            if ($5 != current_func_return && $5 != T_ERROR) {
                yyerror("Error de tipos en el 'return'");
            }
        }
        /*Descargar el contexto de la función al terminar su bloque */
        descargaContexto(niv);
        niv--;
        /* Restaurar la información de retorno actual por seguridad */
        current_func_return = T_ERROR;
    }
    ;
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
        if ($3 != T_ENTERO && $3 != T_ERROR)
            yyerror("La expresion del 'print' debe ser 'entera'");
    };

instSelec:
    TIF TPARAB expre TPARCERR inst TELSE inst 
    {
        /* Verificar que la expresión de la condición sea de tipo lógico (TBOOL) */
        if ($3 != T_LOGICO)
            yyerror("La expresión de la instrucción if-else debe ser de tipo lógico");
    }
    ;
instIter:
    TFOR TPARAB expreOP TPUNTOCOMA expre TPUNTOCOMA expreOP TPARCERR inst 
    {
        /* Verificar que la expresión de la condición sea de tipo lógico (TBOOL) */
        /* La expresión del medio es obligatoria y debe ser de tipo lógico */
        if ($5 != T_LOGICO)
            yyerror("La expresion del 'for' debe ser 'logica'");
    }
    ;
expreOP:
    /* Vacío */
    {
        $$ = 0;  /* valor por defecto cuando está vacía */
    }
    | expre 
    {
        $$ = $1;  /*sintetiza el valor*/
    }
    ;
expre:
    expreLogic 
    {
        $$ = $1;
    }
    | TID TASIG expre 
    {   /* Este es el ejemplo que nos han dado*/
        SIMB sim = obtTdS($1);
        if (sim.t == T_ERROR) yyerror("Objeto no declarado");
        else if (! (((sim.t == T_ENTERO) && ($3 == T_ENTERO)) ||
                ((sim.t == T_LOGICO) && ($3 == T_LOGICO))) )
                if($3!= T_ERROR)
                    yyerror("Error de tipos en la 'instruccion de asignacion'");
        /* Propagar el tipo de la expresión (puede ser T_ERROR) */
        $$ = $3;
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
                if ($3 != T_ENTERO && $3 != T_ERROR)
                    yyerror("El indice del 'array' debe ser entero");
                else{
                    DIM info_arr = obtTdA(sim.ref);
                    /*Solo emitir error si la expresión no vino ya marcada como error */
                    if ($6 != T_ERROR && info_arr.telem != $6) {
                        yyerror("Error de tipos en la asignacion a un 'array'");
                    }
                }
            }
            
            /*Propagar el tipo (puede ser T_ERROR) */
            $$ = $6; 
        }
      }
      ;
expreLogic:
    expreIgual 
    {
        $$ = $1;
    }
    | expreLogic opLogic expreIgual 
    {
        /*Operaciones lógicas requieren operandos lógicos */
        if ($1 == T_ERROR || $3 == T_ERROR) {
            $$ = T_ERROR;
        } else if ($1 != T_LOGICO || $3 != T_LOGICO) {
            yyerror("Error de tipos en expresión lógica");
            $$ = T_ERROR;
        } else {
            $$ = T_LOGICO;
        }
    }
    ;
expreIgual:
    expreRel 
    {
        $$ = $1;
    }
    | expreIgual opIgual expreRel 
    {
        /*Las comparaciones de igualdad requieren operandos del mismo tipo */
        if ($1 == T_ERROR || $3 == T_ERROR) {
            $$ = T_ERROR;
        } else if ($1 != $3) {
            yyerror("Error de tipos en expresión de igualdad");
            $$ = T_ERROR;
        } else {
            $$ = T_LOGICO;
        }
    }
    ;
expreRel:
    expreAd 
    {
        $$ = $1;
    }
    | expreRel opRel expreAd 
    {
        /* Las relaciones requieren operandos enteros */
        if ($1 == T_ERROR || $3 == T_ERROR) {
            $$ = T_ERROR;
        } else if ($1 != T_ENTERO || $3 != T_ENTERO) {
            yyerror("Error de tipos en expresión relacional");
            $$ = T_ERROR;
        } else {
            $$ = T_LOGICO;
        }
    }
    ;
expreAd:
    expreMul 
    {
        $$ = $1;
    }
    | expreAd opAd expreMul 
    {
        /* Suma/resta requieren operandos enteros */
        if ($1 == T_ERROR || $3 == T_ERROR) {
            $$ = T_ERROR;
        } else if ($1 != T_ENTERO || $3 != T_ENTERO) {
            yyerror("Error de tipos en 'expresion aditiva'");
            $$ = T_ERROR;
        } else {
            $$ = T_ENTERO;
        }
    }
    ;
expreMul:
    expreUna 
    {
        $$ = $1;
    }
    | expreMul opMul expreUna 
    {
        /* Multiplicación/división requieren operandos enteros */
        if ($1 == T_ERROR || $3 == T_ERROR) {
            $$ = T_ERROR;
        } else if ($1 != T_ENTERO || $3 != T_ENTERO) {
            yyerror("Error de tipos en 'expresion multiplicativa'");
            $$ = T_ERROR; /* Propagar que hubo un error de tipos */
        } else {
            $$ = T_ENTERO;
        }
    }
    ;
expreUna:
    expreSufi 
    {
        $$ = $1;
    }
    | opUna expreUna 
    {
        /*Operadores unarios conservan el tipo (solo para enteros) */
        if ($2 == T_ERROR) {
            $$ = T_ERROR;
        } else if ($2 != T_ENTERO) {
            yyerror("Error de tipos en expresión unaria");
            $$ = T_ERROR;
        } else {
            $$ = T_ENTERO;
        }
    }
    ;
expreSufi:
    const 
    {
        /*Propagar el tipo de la constante (entero o lógico) */
        $$ = $1;
    }
    | TPARAB expre TPARCERR 
    {
        $$ = $2;
    }
    | TID 
    {
        SIMB sim = obtTdS($1);
        if (sim.t == T_ERROR)
            yyerror("Uso de variable no declarada");
        $$ = sim.t;   /* devuelve el tipo */
      }
    | TID TCORCHAB expre TCORCHCERR 
    {
        SIMB sim = obtTdS($1);
        if (sim.t == T_ERROR)
            yyerror("Uso de array no declarado");

        /*Verificar que el índice sea entero */
        if ($3 != T_ENTERO && $3 != T_ERROR)
            yyerror("El indice del \"array\" debe ser entero");
        $$ = sim.t;
      }
    | TID TPARAB paramAct TPARCERR 
    {
        SIMB sim = obtTdS($1);
        if (sim.t == T_ERROR)
            yyerror("Uso de función no declarada");
        else {
        /*Comprueba coincidencia de dominios (parámetros) */
            /* si ambos -1 => sin parámetros -> OK */
            if (!($3 == -1 && sim.ref == -1)) {
                if (!cmpDom($3, sim.ref))
                    yyerror("Parámetros de la función no coinciden con la declaración");
            }
        }
          $$ = sim.t;  /* return function return type */
      };

paramAct:
    { $$ = -1; }  /*Sin parámetros*/
    |listParamAct { $$ = $1; }; 
listParamAct:
    expre 
    {
        /*Último argumento --> crea nuevo dominio */
        $$ = insTdD(-1, $1);
    }
    | expre TCOMA listParamAct 
        {$$ = insTdD($3, $1);}
    ;
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
