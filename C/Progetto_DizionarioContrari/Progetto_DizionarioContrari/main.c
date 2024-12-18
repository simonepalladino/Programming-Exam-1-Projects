/*  TRACCIA 2:
Si vuole simulare la gestione di un dizionario della lingua italiana. Il dizionario è
indicizzato tramite le lettere dell’alfabeto ed ogni parola contiene al massimo 5
contrari (e.g., gestione matriciale).
Permettere all’utente di:
    • Data una parola visualizzare i contrari presenti nel dizionario (usare la ricerca
    binaria).
Implementare l’algoritmo per la simulazione del dizionario ed effettuare almeno
un test per ognuna delle opzioni richieste dall’utente.
*/





/*  SPIEGAZIONE:  Il seguente programma consente di cercare una parola all'interno del dizionario e
 tramite l'algoritmo della ricerca binaria sarà in grado di stampare i contrari di quella parola. Inoltre se
 non riesce a trovare la parola stamperà "parola non presente nel dizionario" */

#include "Header.h"                                                                            /*  Inclusione "Header.h"  */


int main()
{
    char chiave[50];                                   /*  dichiaro una stringa di caratteri di dimensione 50  */
    int i;                                             /*  dichiaro la variabile i che servirà per il ciclo for  */
    printf("Il programma consente di cercare una parola all'interno del vocabolario e stampare i contrari di quella specifica parola: \n");
    printf("Scegli la parola da cercare: \n");
    gets(chiave);


    /*  Dizionario con i vari contrari  */

    /*Definizione lettera A*/
    strcpy(vocaboli[0].parola[0], "abbandonare");
    strcpy(vocaboli[0].contrario[0], "restare");
    strcpy(vocaboli[0].contrario[1], "resistere");
    strcpy(vocaboli[0].contrario[2], "reggere");
    strcpy(vocaboli[0].contrario[3], "ostinarsi");
    strcpy(vocaboli[0].contrario[4], "sollevarsi");

    /*Definizione lettera B*/
    strcpy(vocaboli[1].parola[0], "bagnare");
    strcpy(vocaboli[1].contrario[0], "asciugare");
    strcpy(vocaboli[1].contrario[1], "seccare");
    strcpy(vocaboli[1].contrario[2], "essicare");
    strcpy(vocaboli[1].contrario[3], "disidratare");
    strcpy(vocaboli[1].contrario[4], "inaridire");

    /*Definizione lettera C*/
    strcpy(vocaboli[2].parola[0], "cadere");
    strcpy(vocaboli[2].contrario[0], "salire");
    strcpy(vocaboli[2].contrario[1], "alzarsi");
    strcpy(vocaboli[2].contrario[2], "crescere");
    strcpy(vocaboli[2].contrario[3], "risalire");
    strcpy(vocaboli[2].contrario[4], "sollevarsi");

    /*Definizione lettera D*/
    strcpy(vocaboli[3].parola[0], "debolezza");
    strcpy(vocaboli[3].contrario[0], "robustezza");
    strcpy(vocaboli[3].contrario[1], "forza");
    strcpy(vocaboli[3].contrario[2], "sicurezza");
    strcpy(vocaboli[3].contrario[3], "pregio");
    strcpy(vocaboli[3].contrario[4], "qualità");

    /*Definizione lettera E*/
    strcpy(vocaboli[4].parola[0], "eccellente");
    strcpy(vocaboli[4].contrario[0], "inferiore");
    strcpy(vocaboli[4].contrario[1], "mediocre");
    strcpy(vocaboli[4].contrario[2], "ordinario");
    strcpy(vocaboli[4].contrario[3], "pessimo");
    strcpy(vocaboli[4].contrario[4], "spregevole");

    /*Definizione lettera F*/
    strcpy(vocaboli[5].parola[0], "finito");
    strcpy(vocaboli[5].contrario[0], "iniziato");
    strcpy(vocaboli[5].contrario[1], "avviato");
    strcpy(vocaboli[5].contrario[2], "incompleto");
    strcpy(vocaboli[5].contrario[3], "inestinguibile");
    strcpy(vocaboli[5].contrario[4], "incompiuto");

    /*Definizione lettera G*/
    strcpy(vocaboli[6].parola[0], "generoso");
    strcpy(vocaboli[6].contrario[0], "avaro");
    strcpy(vocaboli[6].contrario[1], "tirchio");
    strcpy(vocaboli[6].contrario[2], "spilorcio");
    strcpy(vocaboli[6].contrario[3], "taccagno");
    strcpy(vocaboli[6].contrario[4], "egoista");

    /*Definizione lettera H*/
    strcpy(vocaboli[7].parola[0], "hardware");
    strcpy(vocaboli[7].contrario[0], "software");
    strcpy(vocaboli[7].contrario[1], "programmi");
    strcpy(vocaboli[7].contrario[2], "");
    strcpy(vocaboli[7].contrario[3], "");
    strcpy(vocaboli[7].contrario[4], "");

    /*Definizione lettera I*/
    strcpy(vocaboli[8].parola[0], "irregolare");
    strcpy(vocaboli[8].contrario[0], "regolare");
    strcpy(vocaboli[8].contrario[1], "uniforme");
    strcpy(vocaboli[8].contrario[2], "proporzionato");
    strcpy(vocaboli[8].contrario[3], "adatto");
    strcpy(vocaboli[8].contrario[4], "lecito");

    /*Definizione lettera L*/
    strcpy(vocaboli[9].parola[0], "largo");
    strcpy(vocaboli[9].contrario[0], "stretto");
    strcpy(vocaboli[9].contrario[1], "scomodo");
    strcpy(vocaboli[9].contrario[2], "chiuso");
    strcpy(vocaboli[9].contrario[3], "contato");
    strcpy(vocaboli[9].contrario[4], "ristretto");

    /*Definizione lettera M*/
    strcpy(vocaboli[10].parola[0], "magnetizzare");
    strcpy(vocaboli[10].contrario[0], "respingere");
    strcpy(vocaboli[10].contrario[1], "allontanare");
    strcpy(vocaboli[10].contrario[2], "smagnetizzare");
    strcpy(vocaboli[10].contrario[3], "");
    strcpy(vocaboli[10].contrario[4], "");

    /*Definizione lettera N*/
    strcpy(vocaboli[11].parola[0], "negato");
    strcpy(vocaboli[11].contrario[0], "confessato");
    strcpy(vocaboli[11].contrario[1], "permesso");
    strcpy(vocaboli[11].contrario[2], "concesso");
    strcpy(vocaboli[11].contrario[3], "portato");
    strcpy(vocaboli[11].contrario[4], "predisposto");

    /*Definizione lettera O*/
    strcpy(vocaboli[12].parola[0], "obiettivamente");
    strcpy(vocaboli[12].contrario[0], "parzialmente");
    strcpy(vocaboli[12].contrario[1], "soggettivamente");
    strcpy(vocaboli[12].contrario[2], "");
    strcpy(vocaboli[12].contrario[3], "");
    strcpy(vocaboli[12].contrario[4], "");

    /*Definizione lettera P*/
    strcpy(vocaboli[13].parola[0], "palese");
    strcpy(vocaboli[13].contrario[0], "oscuro");
    strcpy(vocaboli[13].contrario[1], "incerto");
    strcpy(vocaboli[13].contrario[2], "ambiguo");
    strcpy(vocaboli[13].contrario[3], "dubbio");
    strcpy(vocaboli[13].contrario[4], "ignoto");

    /*Definizione lettera Q*/
    strcpy(vocaboli[14].parola[0], "questione");
    strcpy(vocaboli[14].contrario[0], "accordo");
    strcpy(vocaboli[14].contrario[1], "intesa");
    strcpy(vocaboli[14].contrario[2], "consenso");
    strcpy(vocaboli[14].contrario[3], "certezza");
    strcpy(vocaboli[14].contrario[4], "soluzione");

    /*Definizione lettera R*/
    strcpy(vocaboli[15].parola[0], "rabbioso");
    strcpy(vocaboli[15].contrario[0], "placido");
    strcpy(vocaboli[15].contrario[1], "paziente");
    strcpy(vocaboli[15].contrario[2], "misurato");
    strcpy(vocaboli[15].contrario[3], "accomodante");
    strcpy(vocaboli[15].contrario[4], "conciliante");

    /*Definizione lettera S*/
    strcpy(vocaboli[16].parola[0], "sabotare");
    strcpy(vocaboli[16].contrario[0], "aiutare");
    strcpy(vocaboli[16].contrario[1], "appoggiare");
    strcpy(vocaboli[16].contrario[2], "sostenere");
    strcpy(vocaboli[16].contrario[3], "favorire");
    strcpy(vocaboli[16].contrario[4], "");

    /*Definizione lettera T*/
    strcpy(vocaboli[17].parola[0], "taglio");
    strcpy(vocaboli[17].contrario[0], "saldatura");
    strcpy(vocaboli[17].contrario[1], "incremento");
    strcpy(vocaboli[17].contrario[2], "ingrandimento");
    strcpy(vocaboli[17].contrario[3], "attacatura");
    strcpy(vocaboli[17].contrario[4], "aumento");

    /*Definizione lettera U*/
    strcpy(vocaboli[18].parola[0], "umido");
    strcpy(vocaboli[18].contrario[0], "asciutto");
    strcpy(vocaboli[18].contrario[1], "secco");
    strcpy(vocaboli[18].contrario[2], "");
    strcpy(vocaboli[18].contrario[3], "");
    strcpy(vocaboli[18].contrario[4], "");

    /*Definizione lettera V*/
    strcpy(vocaboli[19].parola[0], "vantaggioso");
    strcpy(vocaboli[19].contrario[0], "inutile");
    strcpy(vocaboli[19].contrario[1], "svantaggioso");
    strcpy(vocaboli[19].contrario[2], "sfavorele");
    strcpy(vocaboli[19].contrario[3], "sconvienente");
    strcpy(vocaboli[19].contrario[4], "");

    /*Definizione lettera Z*/
    strcpy(vocaboli[20].parola[0], "zuccheroso");
    strcpy(vocaboli[20].contrario[0], "amaro");
    strcpy(vocaboli[20].contrario[1], "aspro");
    strcpy(vocaboli[20].contrario[2], "acre");
    strcpy(vocaboli[20].contrario[3], "brusco");
    strcpy(vocaboli[20].contrario[4], "rude");


    int indice = ric_bin_S(chiave, vocaboli, 21);                       /*  Dichiaro la variabile intera "Indice" e conterrà il risultato
                                                                        della funzione "ric_bin_S" con i parametri chiave,
                                                                        vocaboli e la dimensione  */

    if (indice==-1)                                                     /*  Se non trova la parola stampa "parola non presente nel dizionario"  */
    {
        printf ("Parola non presente nel dizionario\n");
        
    }
    else
        for (i=0; i<5; i++)                                                 /*  In questo ciclo stampa i 5 contrari della parola  */
        {
            printf("Il %d-esimo contrario presente nel dizionario e': %s\n", i+1, vocaboli[indice].contrario[i]);
            
        }
    return 0;
}


int ric_bin_S(char *chiave, Dizionario vocaboli[], int n)                                      /*  funzione di tipo intera con parametri chiave, vocaboli, n  */
{
    int mediano, primo, ultimo;
    primo = 0;
    ultimo = n - 1;
    while (primo <= ultimo)
    {
        mediano = (primo + ultimo) / 2;
        if ((strcmp(chiave, vocaboli[mediano].parola)) == 0)                                /*  Se trova la parola ritorna il mediano  */
            return mediano;
        else if (strcmp(chiave, vocaboli[mediano].parola) < 0)
            ultimo = mediano - 1;                                                           /*  Se la chiave è minore del mediano si sposta sulla semi-porzione di sinistra e continua i confronti  */
        else
            primo = mediano + 1;                                                            /*  Se la chiave è maggiore del mediano si sposta sulla semi-porzione di destra e continua i confronti  */
        
    }
    return -1;                                                                               /*  Se non trova la chiave ritorna -1  */
}
