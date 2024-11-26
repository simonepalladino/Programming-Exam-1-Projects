/*                              TRACCIA 1
 
Si vuole sviluppare un algoritmo di simulazione del gioco della tombola.
L’algoritmo simula 5 giocatori, ognuno con una cartella. Ogni cartella deve
essere costruita a caso dall’algoritmo e assegnata a un giocatore. Una cartella
della tombola è formata da tre righe, ognuna con 5 numeri; in ogni riga può
esserci un solo numero per ogni decina (si ricorda che la tombola considera i
numeri da 1 a 90); inoltre, in una cartella non possono esserci numeri duplicati.
Dopo aver generato le cartelle, l’algoritmo simula l’estrazione in sequenza (a
caso) di un numero dal cestello (ovvero l’algoritmo genera a caso un numero
intero tra 1 e 90, evitando di generare due volte lo stesso numero) e termina
quando uno dei giocatori fa tombola, visualizzando il nome del giocatore.
L’algoritmo visualizza anche il giocatore che ha fatto ambo, il giocatore che ha
fatto terno, il giocatore che ha fatto quaterna, il giocatore che ha fatto quintina.
L’algoritmo deve anche visualizzare le cartelle di tutti i giocatori sia all’inizio sia
dopo l’occorrenza di ambo, terno, quaterna, quintina e tombola.
 
 */

 /*                            SPIEGAZIONE
  
  Il seguente programma simula il gioco della tombola con 5 giocatori inseriti in input dove
  verranno caricate in modo casuale tutte le schede di ogni giocatore e quando un giocatore fa ambo/terno/quaterna/cinquina/tombola
  verrà visualizzato a schermo
  
  
  */



#include "Header.h"



int main()
{
    int i,y,j,num,estratto,scelta;                                 /*  Dichiaro le variabili che utilizzerò nei vari cicli e nelle varie condizioni  */
    int ind_vincitore=-1;                                          /*  Dichiaro e inizializzo a -1 la variabile dell'indice del vincitore  */
    
    int tabella[r][c];                                             /*  Dichiaro un array 2D  (tabellone principale)  */
    
    
    carica_scheda();                                                /*  Chiamata alla funzione "carica_scheda"  */
    //inzio il caricamento della scheda di ogni giocatore
    inizializza_scheda();                                           /*  Chiamata alla funzione "inizializza_scheda"  */
    
    num=1;                                                          /*  Inizializzo la variabile num ad 1  */
    
    for (i=0; i<9; i++)                                             //  Carico con i seguenti cicli for innestati il tabellone principale
    {                                                               // con i numeri da 1 a 90
        for (j=0; j<10; j++)
        {
            tabella[i][j]=num;
            num++;
        }
        
    }
    
    bool ambo_fatto=false;                                         /*  Dichiaro e inizializzo a false la variabile bool ambo_fatto  */
    bool terno_fatto=false;                                        /*  Dichiaro e inizializzo a false la variabile bool terno_fatto  */
    bool quaterna_fatto=false;                                     /*  Dichiaro e inizializzo a false la variabile bool quaterna_fatto  */
    bool cinquina_fatto=false;                                     /*  Dichiaro e inizializzo a false la variabile bool cinquina_fatto  */
    
    do
    {
        bool giauscito=false;                                           /*  inizializza la variabile "giauscito" a 0  */
        srand(time(NULL));                                              /*  inizializza la generazione di numeri casuali che verrà usato
                                                                        dalla funzione rand() in modo che a ogni esecuzione generi numeri diversi.*/
        
        
        //Stampo le cartelle dei giocatori
        stampa_scheda();                                               /*  Chiamata alla funzione "stampa_scheda"  */
        estratto=0;                                                    /*  Imposto la variabile estratto a 0  */
        //Inizio del gioco
        do{                                                            //  Con questo ciclo do-while controllo i
            printf ("\n");
            printf ("\n");
            printf ("\n");
            printf ("\n");
            printf ("\n");
            printf ("\n");
            printf ("\n");
            printf ("\n");
            printf ("\n");
            for(i=0;i<numero_utenti;i++){                              //  numeri già usciti e li sostituisco con uno 0
                for(j=0;j<righe;j++){
                    for(y=0;y<colonne;y++){
                        if(utente[i].scheda[j][y]==estratto){
                            utente[i].scheda[j][y]=estratto;
                            }
                    }
                }
            }
            ind_vincitore=controllo_risultato(&ambo_fatto,&terno_fatto,&quaterna_fatto,&cinquina_fatto);
                                                                                                          //  il valore che restituisce la funzione controllo_risultato finisce nella
            if(ind_vincitore>=0 && ind_vincitore <= numero_utenti){                                       //  variabile ind_vincitore e, se la condizione dell' if si verifica
                printf("Il giocatore %s ha fatto TOMBOLA\n\n",utente[ind_vincitore].nome);                //  stampa il nome del giocatore che ha fatto
                return 0;                                                                                 //  tombola e termina il programma con la return 0
            }
            //Stampo le cartelle dei giocatori
            stampa_scheda();                                                                  /*  chiamata alla funzione "stampa_scheda"  */
            printf ("\n");
            printf ("\n");
            printf("TABELLA: \n\n");                                                          //  Con questo ciclo viene stampato il tabellone principale
            for (j=0; j<r; j++){
                for (y=0; y<c; y++){
                    printf("%d",tabella[j][y]);
                    printf("\t");
                }
                printf("\n");
            }
            printf("\n\n");
            printf("Estrazione...");
            //controllo sull'estrazione
            do{                                                                               //  Esegue l'estrazione con un numero random da 1 a 90 e imposta la cella
                giauscito=true;                                                               //  del tabellone principale del numero estratto a 0
                estratto=rand()%90+1;
                for (j=0; j<r; j++){
                    for (y=0; y<c; y++){
                        if (tabella[j][y]==estratto){
                            giauscito=false;
                        }
                    }
                }
            }while(giauscito==true);
            printf("\n");
            printf("Numero estratto: %d\n\n\n",estratto);
            
            for (j=0; j<r; j++){                                                  //  Sostituisco con uno 0 i numeri che vengono estratti
                for (y=0; y<c; y++){                                              //  sia del tabellone principale che delle schede dei giocatori
                    if(tabella[j][y]==estratto){
                        tabella[j][y]=0;
                    }
                }
            }
            for(i=0;i<numero_utenti;i++){
                for(j=0;j<righe;j++){
                    for(y=0;y<colonne;y++){
                        if(utente[i].scheda[j][y]==estratto){
                            utente[i].scheda[j][y]=0;
                        }
                    }
                }
            }
        }while(utente[ind_vincitore].tombola==true);                                                    //  Termina il ciclo do-while precedente
        printf("Vuoi estrarre un numero? (Premere 1 per SI, un altro valore per NO):\t");
        scanf("%d",&scelta);
    }
    while(scelta==1 || utente[ind_vincitore].tombola==true);                                            //  Termina il ciclo do-while precedente
    
    fflush(stdin);                                                                                   /*  Serve a ripulire l'area di memoria dedicata all'input.  */
    
    return 0;                                                                                        /*  Finisce il programma  */
    
}




void carica_scheda()                                                                                 /*  Questa funzione serve a carica la scheda di ogni giocatore  */
{
    int i,j,y;
    for(i=0;i<numero_utenti;i++)                                                                     /*  Con questi cicli innestati inseriamo i nomi dei giocatori e
                                                                                                      creiamo la scheda di ogni giocatore  */
    {
        printf("Inserici il nome del %d giocatore\t",i+1);
        gets(utente[i].nome);
        for(j=0;j<righe;j++)
        {
            for(y=0;y<colonne;y++){
                utente[i].scheda[j][y]=0;
            }
        }
    }
}


void inizializza_scheda()                                                                               /*  Questa funzione serve a inizializzare la scheda di ogni giocatore  */
{
    int i,col;
    for(i=0;i<numero_utenti;i++){
        
       /*  carico la prima colonna con numeri compresi tra 1 e 9  */
        
        col=rand()%8+1;                     //  la funzione random genera numeri casuali da 1 a 9
        col++;
        utente[i].scheda[0][0]=col;
        do
        {
            col=rand()%8+1;
            col++;
            
        }while(col==utente[i].scheda[0][0]);
        utente[i].scheda[1][0]=col;
        do{
            col=rand()%8+1;
            col++;
            
        }while(col==utente[i].scheda[0][0] || col==utente[i].scheda[1][0]);
        utente[i].scheda[2][0]=col;
        /*  carico la seconda colonna con numeri compresi tra 10 e 29  */
        col=rand()%(29-10)+10;
        col++;
        utente[i].scheda[0][1]=col;
        do {
            col=rand()%(29-10)+10;
            col++;
        }while(col==utente[i].scheda[0][1]);
        utente[i].scheda[1][1]=col;
        do{
            col=rand()%(29-10)+10;
            col++;
        }while(col==utente[i].scheda[0][1] || col==utente[i].scheda[1][1]);
        utente[i].scheda[2][1]=col;
        /*  carico la terza colonna con numeri compresi tra 30 e 59  */
        col=rand()%(59-30)+30;
        col++;
        utente[i].scheda[0][2]=col;
        do{
            col=rand()%(59-30)+30;
            col++;
        }while(col==utente[i].scheda[0][2]);
        utente[i].scheda[1][2]=col;
        do{
            col=rand()%(59-30)+30;
            col++;
            
        }while(col==utente[i].scheda[0][2] || col==utente[i].scheda[1][2]);
        utente[i].scheda[2][2]=col;
        /*  carico la quarta colonna con numeri compresi tra 60 e 79  */
        col=rand()%(79-60)+60;
        col++;
        utente[i].scheda[0][3]=col;
        do{
            col=rand()%(79-60)+60;
            col++;
        }while(col==utente[i].scheda[0][3]);
        utente[i].scheda[1][3]=col;
        do{
            col=rand()%(79-60)+60;
            col++;
        }while(col==utente[i].scheda[0][3] || col==utente[i].scheda[1][3]);
        utente[i].scheda[2][3]=col;
        /*  carico la quinta colonna con numeri compresi tra 80 e 90  */
        col=rand()%(90-80)+80;
        col++;
        utente[i].scheda[0][4]=col;
        do{
            col=rand()%(90-80)+80;
            col++;
        }while(col==utente[i].scheda[0][4]);
        utente[i].scheda[1][4]=col;
        do{
            col=rand()%(90-80)+80;
            col++;
        }while(col==utente[i].scheda[0][4] || col==utente[i].scheda[1][4]);
        utente[i].scheda[2][4]=col;
        
    }
    
}



int controllo_risultato(bool *ambo_fatto, bool *terno_fatto, bool *quaterna_fatto, bool *cinquina_fatto){
                                                                                            
    /*  Questa funzione serve a verificare
    se un giocatore ha fatto ambo,
    terno, quaterna, cinquina o tombola  */
    
    int i, j, y, conta;

    //ciclo AMBO
    for (i = 0; i < numero_utenti; i++)
    {
        if (utente[i].ambo == false && *ambo_fatto == false)
        {
            for (j = 0; j < 3; j++)
            {
                conta = 0;
                for (y = 0; y < colonne; y++)
                {
                    if (utente[i].scheda[j][y] == 0)
                    {
                        conta++;
                    }
                }
                if (conta == 2)                 /*  Se il contatore delle celle è arrivato a 2 allora il giocatore ha fatto ambo  */
                {
                    utente[i].ambo = true;
                    *ambo_fatto = true;
                    printf("Il giocatore %s ha fatto AMBO\n", utente[i].nome);
                    break;
                }
            }
        }
    }
    //ciclo TERNO
    for (i = 0; i < numero_utenti; i++)
    {
        if (utente[i].terno == false && *terno_fatto == false)
        {
            for (j = 0; j < 3; j++)
            {
                conta = 0;
                for (y = 0; y < colonne; y++)
                {
                    if (utente[i].scheda[j][y] == 0)
                    {
                        conta++;
                    }
                }
                if (conta == 3)                               /*  Se il contatore delle celle è arrivato a 3 allora il giocatore ha fatto terno  */
                {
                    utente[i].terno = true;
                    *terno_fatto = true;
                    printf("Il giocatore %s ha fatto TERNO\n", utente[i].nome);
                    break;
                }
            }
        }
    }
    //ciclo QUATERNA
    for (i = 0; i < numero_utenti; i++)
    {
        if (utente[i].quaterna == false && *quaterna_fatto == false)
        {
            for (j = 0; j < 3; j++)
            {
                conta = 0;
                for (y = 0; y < colonne; y++)
                {
                    if (utente[i].scheda[j][y] == 0)
                    {
                        conta++;
                    }
                }
                if (conta == 4)                                    /*  Se il contatore delle celle è arrivato a 4 allora il giocatore ha fatto quaterna  */
                {
                    utente[i].quaterna = true;
                    *quaterna_fatto = true;
                    printf("Il giocatore %s ha fatto QUATERNA\n", utente[i].nome);
                    break;
                }
            }
        }
    }
    //ciclo CINQUINA
    for (i = 0; i < numero_utenti; i++)
    {
        if (utente[i].cinquina == false && *cinquina_fatto == false)
        {
            for (j = 0; j < 3; j++)
            {
                conta = 0;
                for (y = 0; y < colonne; y++)
                {
                    if (utente[i].scheda[j][y] == 0)
                    {
                        conta++;
                    }
                }
                if (conta == 5)                                  /*  Se il contatore delle celle è arrivato a 5 allora il giocatore ha fatto cinquina  */
                {
                    utente[i].cinquina = true;
                    *cinquina_fatto = true;
                    printf("Il giocatore %s ha fatto CINQUINA\n", utente[i].nome);
                    break;
                }
            }
        }
    }
    //ciclo TOMBOLA
    for (i = 0; i < numero_utenti; i++)
    {
        if (utente[i].tombola == false)
        {
            conta = 0;
            for (j = 0; j < righe; j++)
            {
                for (y = 0; y < colonne; y++)
                {
                    if (utente[i].scheda[j][y] == 0)
                    {
                        conta++;
                    }
                }
            }
            if (conta == maxscheda)                                  /*  Se il contatore delle celle è arrivato a 15 (cioè tutte le celle della scheda)
                                                                      allora il giocatore ha fatto tombola e ritorna nel main dove verrà stampato
                                                                      il nome del vincitore  */
            {
                utente[i].tombola = true;
                return i;                                            /*  ritorna l'indice del vincitore  */
            }
        }
    }

    return -1;                                                       /*  ritorna -1 quindi ancora nessun giocatore ha vinto  */

}


void stampa_scheda(){                                                                  /*  Funzione che stampa la scheda del giocatore  */
    int i,y,j;
    printf ("\n");
    for(i=0;i<numero_utenti;i++)
    {
        printf ("\n");
        printf ("\n");
        printf("la scheda di %s e':\n",utente[i].nome);                               /*  Identifica il nome richiamando la variabile "nome" nella struct  */
        for(j=0;j<righe;j++)
        {
            for(y=0;y<colonne;y++){
                printf("%d\t",utente[i].scheda[j][y]);                                /*  Identifica la scheda richiamando la variabile "scheda" nella struct  */
            }
            printf("\n");
        }
    }
}
