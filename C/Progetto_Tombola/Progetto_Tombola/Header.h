#ifndef Header_h
#define Header_h


#include <stdio.h>                          /*  Inclusione della libreria "stdio.h"  */
#include <stdlib.h>                         /*  Inclusione della libreria "stdlib.h"  */
#include <time.h>                           /*  Inclusione della libreria "time.h"  */
#include <string.h>                         /*  Inclusione della libreria "string.h"  */

#define righe 3                             /*  Definisco le righe della scheda di ogni giocatore  */
#define colonne 5                           /*  Definisco le colonne della scheda di ogni giocatore  */
#define maxnome 10                          /*  Definisco la dimensione massima da dare alla variabile char nome  */
#define maxscheda 15                        /*  Definisco la grandezza di ogni scheda  */
#define numero_utenti 5                     /*  Definisco il numero massimo di utenti  */
#define r 9                                 /*  Definisco le righe della matrice principale  */
#define c 10                                /*  Definisco le colonne della matrice principale  */

typedef enum { false, true } bool;          /*  Dichiaro un tipo di dato enumerato  */

typedef struct                              //  Dichiarazione globale struct giocatore con all'interno un
{                                           //  array di char 1D, un array di char 2D e cinque variabili intere
    char scheda[righe][colonne];
    char nome[maxnome];
    bool ambo;
    bool terno;
    bool quaterna;
    bool cinquina;
    bool tombola;
    
}giocatore;

giocatore utente[numero_utenti];                 /*  uso l' array di struct per identificare l' utente  */



void carica_scheda(void);                                    /*  prototipo della funzione di tipo void "carica_scheda"  */
void inizializza_scheda(void);                               /*  prototipo della funzione di tipo void "inizializza_scheda"  */
int controllo_risultato(bool *, bool *, bool *, bool *);             /*  prototipo della funzione di tipo intero "controllo_scheda"  */
void stampa_scheda(void);                                    /*  prototipo della funzione di tipo void "stampa_scheda"  */


#endif /* Header_h */
