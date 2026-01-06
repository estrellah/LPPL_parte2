/*INTEGRANTES DEL GRUPO:
- Anais Gomez Mari
- Alex Mancebo Colorado
- Xavi Naya Pons
- Estrella Herrejon Lucas
*/

%{
#include <stdio.h>
#include <string.h>
#include "header.h"
#include "libtds.h"
#include "libgci.h"

extern int yylineno;

/* Variables globales para gestión de main y errores */
int nmain = 0;
int errDeclFunc = 0; /* Flag para indicar error en la cabecera de la función actual */
%}

%union{
    char *ident;    /* Nombre del identificador */
    int cent;       /* Valor entero (usado para constantes, etiquetas, LANS) */
    
    /* Estructura para parámetros */
    struct {
        int num_params;
        int ref;
        int talla;
    } paramInfo;

    /* Estructura para tipos simples */
    struct {
        int t;
    } tipo;

    /* Estructura para expresiones y constantes (TIPO, DESPLAZAMIENTO, NIVEL, VALOR) */
    /* Añadimos 'val' porque asinS.y lo usa para constantes numéricas */
    struct {
        int t;      /* Tipo (T_ENTERO, T_LOGICO...) */
        int d;      /* Desplazamiento / Dirección */
        int n;      /* Nivel */
        int val;    /* Valor constante (si aplica) */
    } exp;

    /* Estructura para listas de parámetros */
    struct {
        int ref;
        int talla;
    } lista;
}

/* ======
   TOKENS
   ====== */
/* Operadores y Símbolos */
%token TASIG TMAS TMENOS TMULT TDIV
%token TPUNTOCOMA TCOMA
%token TPARAB TPARCERR TLLAVAB TLLAVCERR TCORCHAB TCORCHCERR

/* Lógicos y Relacionales */
%token TAND TOR TEXCL
%token TIGUALQUE TDISTINTOQUE TMAYORQUE TMENORQUE TMAYORIGUAL TMENORIGUAL

/* Palabras Reservadas */
%token TTRUE TFALSE
%token TREAD TPRINT TIF TELSE TFOR TRETURN
%token TINT TBOOL

/* Tokens con valor semántico */
%token <ident> TID
%token <cent> TCTE

/* ==========================================================================
   TIPOS DE LOS NO-TERMINALES
   ========================================================================== */
%type <cent> tipoSimp 
%type <exp> const expre expreOP expreLogic expreIgual expreRel expreAd expreMul expreUna expreSufi instExpre
%type <cent> opLogic opIgual opRel opAd opMul opUna
%type <lista> paramForm listParamForm paramAct listParamAct

/* ==========================================================================
   GRAMÁTICA
   ========================================================================== */
%%

programa
    : { 
        dvar = 0;
        niv = 0; 
        cargaContexto(niv); 
        nmain = 0;
        
        /* GCI: Reserva espacio para variables globales */
        $<cent>$ = creaLans(si);
        emite(INCTOP, crArgNul(), crArgNul(), crArgNul());
      }
      {
        /* GCI: Salto inicial al main */
        $<cent>$ = creaLans(si);
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(-1));
      }
      listDecla 
      {
        /* Verificaciones finales */
        if (nmain == 0) yyerror("Error semantico: El programa no tiene 'main'");
        else if (nmain > 1) yyerror("Error semantico: El programa tiene más de un 'main'");
        
        if (verTdS) mostrarTdS();
        
        /* GCI: Parchear la reserva de globales */
        completaLans($<cent>1, crArgEnt(dvar));
        
        /* GCI: Parchear el salto al main */
        SIMB sim = obtTdS("main");
        completaLans($<cent>2, crArgEtq(sim.d));
      }
    ;

listDecla
    : listDecla decla
    | decla
    ;

decla
    : declaVar
    | declaFunc
    ;

declaVar
    : tipoSimp TID TPUNTOCOMA {
        if (!insTdS($2, VARIABLE, $1, niv, dvar, -1)) { 
            yyerror("Error semantico: Identificador repetido");
        } else {
            dvar += TALLA_TIPO_SIMPLE;                         
        } 
      }
    | tipoSimp TID TASIG const TPUNTOCOMA {
        if ($1 != $4.t) {
            yyerror("Error semantico: Tipos incompatibles en la inicializacion");
        }
        if (!insTdS($2, VARIABLE, $1, niv, dvar, -1)) { 
            yyerror("Error semantico: Identificador repetido");
        } else {
            SIMB s = obtTdS($2);
            dvar += TALLA_TIPO_SIMPLE; 
            /* GCI: Inicialización de variable */
            emite(EASIG, crArgEnt($4.val), crArgNul(), crArgPos(s.n, s.d));
        }
      }
    | tipoSimp TID TCORCHAB TCTE TCORCHCERR TPUNTOCOMA {
        int numelem = $4;
        if ($4 <= 0) { 
            yyerror("Error semantico: Talla inapropiada del array"); 
            numelem = 0; 
        }
        int refe_array = insTdA($1, numelem);
        if (!insTdS($2, VARIABLE, T_ARRAY, niv, dvar, refe_array)) { 
            yyerror("Error semantico: Identificador repetido");
        } else {
            dvar += numelem * TALLA_TIPO_SIMPLE; 
        }
      }
    ;

const
    : TCTE   { $$.t = T_ENTERO; $$.val = $1; }
    | TTRUE  { $$.t = T_LOGICO; $$.val = 1; }
    | TFALSE { $$.t = T_LOGICO; $$.val = 0; }
    ;

tipoSimp
    : TINT  { $$ = T_ENTERO; }
    | TBOOL { $$ = T_LOGICO; }
    ;

declaFunc
    : tipoSimp TID {
        $<cent>$ = dvar; /* Guardamos dvar global */
        dvar = 0;        /* Reset para locales */
        niv = 1;         /* Entramos a nivel local */
        cargaContexto(niv);
        
        if (strcmp($2, "main") == 0) { nmain++; }
        errDeclFunc = 0;
      }
      TPARAB paramForm TPARCERR {
        /* Insertamos la función en la TDS (nivel global) */
        if (!insTdS($2, FUNCION, $1, niv-1, si, $5.ref)) {
            yyerror("Error semantico: Identificador de funcion repetido");
            errDeclFunc = 1;
        }
      }
      bloque {
        if (verTdS) mostrarTdS();
        descargaContexto(niv);
        niv = 0;          /* Volvemos a nivel global */
        dvar = $<cent>3;  /* Restauramos dvar global */
      }
    ;

paramForm
    : listParamForm { $$ = $1; }
    | /* Vacío */ {  
        $$.ref = insTdD(-1, T_VACIO);
        $$.talla = TALLA_SEGENLACES; 
      }
    ;

listParamForm
    : tipoSimp TID {
        $$.ref = insTdD(-1, $1);
        $$.talla = TALLA_TIPO_SIMPLE + TALLA_SEGENLACES;
        /* Insertamos parámetro con desplazamiento negativo */
        if (!insTdS($2, PARAMETRO, $1, niv, -$$.talla, $$.ref)) { 
            yyerror("Error semantico: Error al declarar el parametro");
        }
      }
    | tipoSimp TID TCOMA listParamForm {
        $$.ref = insTdD($4.ref, $1);
        $$.talla = $4.talla + TALLA_TIPO_SIMPLE; 
        if (!insTdS($2, PARAMETRO, $1, niv, -$$.talla, $$.ref)) { 
            yyerror("Error semantico: Error al declarar el parametro"); 
        }
      }
    ;

bloque
    : TLLAVAB {
        /* Prólogo de función: PUSHFP, FPTOP, INCTOP */
        emite(PUSHFP, crArgNul(), crArgNul(), crArgNul());
        emite(FPTOP, crArgNul(), crArgNul(), crArgNul());
        $<cent>$ = creaLans(si);
        emite(INCTOP, crArgNul(), crArgNul(), crArgNul());
      }
      declaVarLocal listInst TRETURN expre TPUNTOCOMA TLLAVCERR {
        INF info = obtTdD(-1); /* Obtenemos info de función actual */
        
        if (errDeclFunc == 1) {
            yyerror("Error semantico: Error en la declaracion de la funcion");
        } else if (info.tipo != T_ERROR && $6.t != T_ERROR && $6.t != info.tipo) {
            yyerror("Error semantico: Error de tipos en el 'return'");
        }

        /* GCI: Parchear INCTOP con tamaño de variables locales */
        completaLans($<cent>2, crArgEnt(dvar));
        
        /* GCI: Gestión del valor de retorno */
        int dirret = TALLA_SEGENLACES + TALLA_TIPO_SIMPLE + info.tsp;
        emite(EASIG, crArgPos(niv, $6.d), crArgNul(), crArgPos(niv, -dirret));
        
        /* Epílogo: Restaurar pila */
        emite(TOPFP, crArgNul(), crArgNul(), crArgNul());
        emite(FPPOP, crArgNul(), crArgNul(), crArgNul());
        
        if (strcmp(info.nom, "main") == 0) {
            emite(FIN, crArgNul(), crArgNul(), crArgNul());
        } else {
            emite(RET, crArgNul(), crArgNul(), crArgNul());
        }
      }
    ;

declaVarLocal
    : declaVarLocal declaVar
    | /* Vacío */
    ;

listInst
    : listInst inst
    | /* Vacío */
    ;

inst
    : TLLAVAB listInst TLLAVCERR
    | instExpre
    | instEntSal
    | instSelec
    | instIter
    ;

instExpre
    : expre TPUNTOCOMA { $$ = $1; }
    | TPUNTOCOMA { $$.t = T_VACIO; }
    ;

instEntSal
    : TREAD TPARAB TID TPARCERR TPUNTOCOMA {
        SIMB s = obtTdS($3);
        if (s.t == T_ERROR) {
            yyerror("Error semantico: Objeto no declarado en 'read'");
        } else if (s.t != T_ENTERO) {
            yyerror("Error semantico: La instruccion 'read' solo admite variables de tipo entero");
        }
        emite(EREAD, crArgNul(), crArgNul(), crArgPos(s.n, s.d));
      }
    | TPRINT TPARAB expre TPARCERR TPUNTOCOMA {
        if ($3.t != T_ENTERO) {
            yyerror("Error semantico: La instruccion 'print' solo admite expresiones de tipo entero");
        }
        emite(EWRITE, crArgNul(), crArgNul(), crArgPos(niv, $3.d));
      }
    ;

instSelec
    : TIF TPARAB expre TPARCERR {
        if ($3.t != T_LOGICO) {
            yyerror("Error semantico: La condicion del 'if' debe ser de tipo logico");
        }
        $<cent>$ = creaLans(si);
        emite(EIGUAL, crArgPos(niv, $3.d), crArgEnt(0), crArgNul());
      }
      inst TELSE {
        $<cent>$ = creaLans(si);
        emite(GOTOS, crArgNul(), crArgNul(), crArgNul());
        completaLans($<cent>5, crArgEtq(si));
      }
      inst {
        completaLans($<cent>8, crArgEtq(si));
      }
    ;

instIter
    : TFOR TPARAB expreOP TPUNTOCOMA {
        $<cent>$ = si; /* Marca inicio condición */
      }
      expre {
        if ($6.t != T_LOGICO) {
            yyerror("Error semantico: La condicion del 'for' debe ser de tipo logico");
        }
        $<cent>$ = creaLans(si); /* Salto fin si falso */
        emite(EIGUAL, crArgEnt(0), crArgPos(niv, $6.d), crArgNul());
      }
      {
        $<cent>$ = creaLans(si); /* Salto al cuerpo si verdadero (salta update) */
        emite(GOTOS, crArgNul(), crArgNul(), crArgNul());
      }
      {
        $<cent>$ = si; /* Inicio del Update */
      }
      TPUNTOCOMA expreOP {
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq($<cent>5)); /* Vuelve a condición */
        completaLans($<cent>8, crArgEtq(si)); /* Parcheamos salto al cuerpo */
      }
      TPARCERR inst {
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq($<cent>9)); /* Vuelve al update tras cuerpo */
        completaLans($<cent>7, crArgEtq(si)); /* Parcheamos salida bucle */
      }
    ;

expreOP
    : expre { 
        if ($1.t != T_ENTERO && $1.t != T_LOGICO) {
            yyerror("Error semantico: La expresion del 'for' debe ser de tipo simple");
        }
        $$ = $1;
      }
    | /* Vacío */ { $$.t = T_VACIO; }
    ;

expre
    : expreLogic { $$ = $1; }
    | TID TASIG expre {
        SIMB sim = obtTdS($1);
        if (sim.t == T_ERROR) {
            yyerror("Error semantico: Objeto no declarado");
            $$.t = T_ENTERO;
        } else {
            if (!(((sim.t == T_ENTERO) && ($3.t == T_ENTERO)) || ((sim.t == T_LOGICO) && ($3.t == T_LOGICO)))) {
                yyerror("Error semantico: Error de tipos en la ‘instruccion de asignacion’");
            }
            $$.t = sim.t;
        }
        $$.d = creaVarTemp();
        emite(EASIG, crArgPos(niv, $3.d), crArgNul(), crArgPos(sim.n, sim.d)); /* Asignar a variable */
        emite(EASIG, crArgPos(niv, $3.d), crArgNul(), crArgPos(niv, $$.d));    /* Resultado expresión */
      }
    | TID TCORCHAB expre TCORCHCERR TASIG expre {
        SIMB sim = obtTdS($1);
        if (sim.t == T_ERROR) yyerror("Error semantico: Objeto no declarado");
        else if (sim.t != T_ARRAY) yyerror("Error semantico: Se esperaba un array");
        else if ($3.t != T_ENTERO) yyerror("Error semantico: El indice del array debe ser entero");
        else {
            DIM dim = obtTdA(sim.ref);
            if (dim.telem != $6.t) yyerror("Error semantico: Error de tipos en la asignacion del array");
            $$.t = dim.telem;
            $$.d = creaVarTemp();
            /* Asignación a vector: vect[indice] = valor */
            emite(EVA, crArgPos(sim.n, sim.d), crArgPos(niv, $3.d), crArgPos(niv, $6.d));
            emite(EASIG, crArgPos(niv, $6.d), crArgNul(), crArgPos(niv, $$.d));
        }
      }
    ;

expreLogic
    : expreIgual { $$ = $1; }
    | expreLogic opLogic expreIgual {
        if ($1.t != T_LOGICO || $3.t != T_LOGICO) {
            yyerror("Error semantico: Operador logico espera tipos logicos");
        }
        $$.t = T_LOGICO;
        $$.d = creaVarTemp();
        emite($2, crArgPos(niv, $1.d), crArgPos(niv, $3.d), crArgPos(niv, $$.d));
        
        /* Ajuste específico para OR (suma lógica) si es > 1 */
        if ($2 == ESUM) {
             emite(EMENEQ, crArgPos(niv, $$.d), crArgEnt(1), crArgEtq(si+2));
             emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, $$.d));
        }
      }
    ;

expreIgual
    : expreRel { $$ = $1; }
    | expreIgual opIgual expreRel {
        if ($1.t != $3.t) {
            yyerror("Error semantico: Tipos incompatibles en la comparacion de igualdad");
        }
        $$.t = T_LOGICO;
        $$.d = creaVarTemp();
        emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, $$.d));
        emite($2, crArgPos(niv, $1.d), crArgPos(niv, $3.d), crArgEtq(si+2));
        emite(EASIG, crArgEnt(0), crArgNul(), crArgPos(niv, $$.d));
      }
    ;

expreRel
    : expreAd { $$ = $1; }
    | expreRel opRel expreAd {
        if ($1.t != T_ENTERO || $3.t != T_ENTERO) {
            yyerror("Error semantico: Operador relacional espera tipos enteros");
        }
        $$.t = T_LOGICO;
        $$.d = creaVarTemp();
        emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, $$.d));
        emite($2, crArgPos(niv, $1.d), crArgPos(niv, $3.d), crArgEtq(si+2));
        emite(EASIG, crArgEnt(0), crArgNul(), crArgPos(niv, $$.d));
      }
    ;

expreAd
    : expreMul { $$ = $1; }
    | expreAd opAd expreMul {
        if ($1.t != T_ENTERO || $3.t != T_ENTERO) {
            yyerror("Error semantico: Operador aritmetico espera tipos enteros");
            $$.t = T_ENTERO;
        } else {
            $$.t = T_ENTERO;
        }
        $$.d = creaVarTemp();
        emite($2, crArgPos(niv, $1.d), crArgPos(niv, $3.d), crArgPos(niv, $$.d));
      }
    ;

expreMul
    : expreUna { $$ = $1; }
    | expreMul opMul expreUna {
        if ($1.t != T_ENTERO || $3.t != T_ENTERO) {
            yyerror("Error semantico: los tipos no son enteros");
            $$.t = T_ENTERO;
        } else {
            $$.t = T_ENTERO;
        }
        $$.d = creaVarTemp();
        emite($2, crArgPos(niv, $1.d), crArgPos(niv, $3.d), crArgPos(niv, $$.d));
      }
    ;

expreUna
    : expreSufi { $$ = $1; }
    | opUna expreUna {
        if ($1 == ESIG) { /* Operador NOT (!) */
            if ($2.t != T_LOGICO) yyerror("Operacion para NOT no usa tipo logico");
            $$.t = T_LOGICO;
            $$.d = creaVarTemp();
            emite(EDIF, crArgEnt(1), crArgPos(niv, $2.d), crArgPos(niv, $$.d));
        } else { /* Operadores + o - unarios */
            if ($2.t != T_ENTERO) yyerror("Operacion unarios no usa tipo entero");
            $$.t = T_ENTERO;
            $$.d = creaVarTemp();
            emite($1, crArgPos(niv, $2.d), crArgEnt(0), crArgPos(niv, $$.d));
        }
      }
    ;

expreSufi
    : const {
        $$.t = $1.t;
        $$.d = creaVarTemp();
        emite(EASIG, crArgEnt($1.val), crArgNul(), crArgPos(niv, $$.d));
      }
    | TPARAB expre TPARCERR {
        $$.t = $2.t;
        $$.d = creaVarTemp();
        emite(EASIG, crArgPos(niv, $2.d), crArgNul(), crArgPos(niv, $$.d));
      }
    | TID {
        SIMB sim = obtTdS($1);
        if (sim.t == T_ERROR) {
            yyerror("Error semantico: Objeto no declarado");
            $$.t = T_ENTERO;
        } else {
            $$.t = sim.t;
            $$.d = creaVarTemp();
            emite(EASIG, crArgPos(sim.n, sim.d), crArgNul(), crArgPos(niv, $$.d));
        }
      }
    | TID TCORCHAB expre TCORCHCERR {
        SIMB sim = obtTdS($1);
        if (sim.t == T_ERROR) yyerror("Error semantico: Objeto no declarado");
        else if (sim.t != T_ARRAY) yyerror("Error semantico: Se esperaba un array");
        else if ($3.t != T_ENTERO) yyerror("Error semantico: El indice del array debe ser de tipo entero");
        else {
            DIM dim = obtTdA(sim.ref);
            $$.t = dim.telem;
            $$.d = creaVarTemp();
            /* Acceso a vector: res = vect[indice] */
            emite(EAV, crArgPos(sim.n, sim.d), crArgPos(niv, $3.d), crArgPos(niv, $$.d));
        }
      }
    | TID {
        emite(INCTOP, crArgNul(), crArgNul(), crArgEnt(TALLA_TIPO_SIMPLE));
      }
      TPARAB paramAct TPARCERR {
        SIMB sim = obtTdS($1);
        if (sim.t == T_ERROR) {
            yyerror("Error semantico: Objeto no declarado");
            $$.t = T_ERROR;
        } else {
            INF inf = obtTdD(sim.ref);
            if (inf.tipo == T_ERROR) {
                yyerror("Error semantico: Se esperaba una funcion");
                $$.t = T_ERROR;
            } else if (inf.tsp != $4.talla) {
                yyerror("Numero de parametros incorrecto en llamada a funcion");
            } else if (!cmpDom($4.ref, sim.ref)) {
                yyerror("Error semantico: Error en los parametros");
            } else {
                emite(CALL, crArgNul(), crArgNul(), crArgEtq(sim.d));
                emite(DECTOP, crArgNul(), crArgNul(), crArgEnt(inf.tsp));
                $$.t = inf.tipo;
                if (inf.tipo != T_VACIO) {
                    $$.d = creaVarTemp();
                    emite(EPOP, crArgNul(), crArgNul(), crArgPos(niv, $$.d));
                }
            }
        }
      }
    ;

paramAct
    : listParamAct { $$ = $1; }
    | /* Vacío */ {
        $$.ref = insTdD(-1, T_VACIO);
        $$.talla = 0;
      }
    ;

listParamAct
    : expre {
        emite(EPUSH, crArgNul(), crArgNul(), crArgPos(niv, $1.d));
        $$.ref = insTdD(-1, $1.t);
        $$.talla = 1;
      }
    | expre {
        emite(EPUSH, crArgNul(), crArgNul(), crArgPos(niv, $1.d));
      }
      TCOMA listParamAct {
        $$.ref = insTdD($4.ref, $1.t);
        $$.talla = $4.talla + 1;
      }
    ;

/* ==========================================================================
   OPERADORES
   ========================================================================== */
opLogic
    : TAND { $$ = EMULT; }
    | TOR  { $$ = ESUM; }
    ;

opIgual
    : TIGUALQUE { $$ = EIGUAL; }
    | TDISTINTOQUE { $$ = EDIST; }
    ;

opRel
    : TMAYORQUE { $$ = EMAY; }
    | TMENORQUE { $$ = EMEN; }
    | TMAYORIGUAL { $$ = EMAYEQ; }
    | TMENORIGUAL { $$ = EMENEQ; }
    ;

opAd
    : TMAS { $$ = ESUM; }
    | TMENOS { $$ = EDIF; }
    ;

opMul
    : TMULT { $$ = EMULT; }
    | TDIV  { $$ = EDIVI; }
    ;

opUna
    : TMAS { $$ = ESUM; }
    | TMENOS { $$ = EDIF; }
    | TEXCL { $$ = ESIG; }
    ;

%%