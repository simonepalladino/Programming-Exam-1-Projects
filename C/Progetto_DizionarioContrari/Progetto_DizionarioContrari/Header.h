#ifndef Header_h
#define Header_h

#include <stdio.h>      /*  Inclusione delle librerie "stdio.h"  */
#include <stdlib.h>     /*  Inclusione delle librerie "stdlib.h"  */
#include <string.h>     /*  Inclusione delle librerie "string.h"  */



typedef struct dizionario {           /* Dichiarazione globale struct dizionario: Formata da 2 array 2D di char */
    char parola[100][100];
    char contrario[100][100];
}Dizionario;


Dizionario vocaboli[21];



int ric_bin_S(char *, Dizionario [], int);        /*  Prototipo della funzione "ric_bin_S" */

#endif /* Header_h */
