/*****************************************************************************/
/*  Programa principal y tratamiento de errores.                             */
/*                       Jose Miguel Benedi v.24                             */
/*****************************************************************************/
#include <stdio.h>
#include <string.h>
#include "../include/header.h"

int verbosidad = FALSE;                    /* Si se desea una traza o no     */
int numErrores = 0;                        /* Contador del numero de errores */
/*****************************************************************************/
void yyerror(const char *msg){
    numErrores++;
    fprintf(stderr, "\nError en la linea %d: %s\n", yylineno, msg);
 }
 int main(int argc, char **argv) {
    int i, n=1 ;
    for (i=1; i<argc; ++i)
        if (strcmp(argv[i], "-v")==0) { verbosidad = TRUE; n++; }
    if (argc == n+1)
        if ((yyin = fopen (argv[n], "r")) == NULL)
            fprintf (stderr, "El fichero '%s' no es valido\n", argv[n]) ;
        else {yyparse ();}
    else fprintf (stderr, "Uso: cmc [-v] fichero\n");
    if (numErrores==0){
      //printf("No hay errores\n");
    }else{
      printf("Hay '%x' errores\n", numErrores);
    }
    
    return (0);
 } 