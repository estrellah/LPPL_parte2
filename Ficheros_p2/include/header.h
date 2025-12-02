/*****************************************************************************/
/**   Ejemplo de un posible fichero de cabeceras donde situar las           **/
/** definiciones de constantes, variables y estructuras para MenosC. Los    **/
/** alumnos deberan adaptarlo al desarrollo de su propio compilador.    **/
/*****************************************************************************/
#ifndef _HEADER_H
#define _HEADER_H
//NUEVO: TALLAS
#define TALLA_TIPO_SIMPLE 1
#define TALLA_SEGENLACES 2
/****************************************************** Constantes generales */
#define TRUE  1
#define FALSE 0
#define OP_NOT 0
#define OP_SUMA 1
#define OP_RESTA 2
#define OP_MULT 3
#define OP_DIV 4
#define OP_MAYORQ 5
#define OP_MENORQ 6
#define OP_MAYORI 7
#define OP_MENORI 8
#define OP_IGUALQ 9
#define OP_DISTINTOQ 10
#define OP_OR 11
#define OP_AND 12

/****************************************************** Definiciones de tipos */

/************************************* Variables externas definidas en el AL */
extern int yylex();
extern int yyparse();
//NUEVO:FLAG PARA MOSTRAR TDS
 extern int verTdS;
 extern int dvar; 
 extern int niv;

extern FILE *yyin;                           /* Fichero de entrada           */
extern int   yylineno;                       /* Contador del numero de linea */
extern char *yytext;                         /* Patron detectado             */
/********* Funciones y variables externas definidas en el Programa Principal */
extern void yyerror(const char * msg) ;   /* Tratamiento de errores          */

extern int verbosidad;                   /* Flag si se desea una traza       */
extern int numErrores;              /* Contador del numero de errores        */

#endif  /* _HEADER_H */
/*****************************************************************************/
