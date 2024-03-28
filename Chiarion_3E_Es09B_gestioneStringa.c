// Author: Daniele Chiarion
// Date: 27-03-2024

/* Scrivere un programma in C che dopo aver inserito una stringa a piacere permetta di:
   1) Eliminare 1 carattere scelto dall’utente ( o   più di 1 se si ripetono);
   2) Eliminare 1 carattere scelto dall’utente in  base alla sua posizione;
   3) Aggiungere 1  carattere scelto dall’utente alla fine della stringa; */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/* funzione per menu generico */
int menu(char stringa[][200], int size)
{
    int scelta;
    int i;

    do
    {
        printf("\n=== %s ===", stringa[0]); // output of the title
        for (i = 1; i < size; i++)
        {
            printf("\n%s", stringa[i]); // output of the options
        }
        printf("\n");
        scanf("%d", &scelta);
        /* error message */
        if (scelta < 1 || scelta > size - 1)
        {
            printf("\nValore errato. Riprova");
            sleep(3);
            ClrScr();
        }
    } while (scelta < 1 || scelta > size - 1); // checking value

    return scelta;
}

/* funzione per pulire lo schermo */
void ClrScr()
{
#ifdef _WIN32      // Check if the OS is Windows
    system("cls"); // instruction for clearing cmd of Windows
#else
    system("clear"); // instruction for clearing shell of Linux / MacOS
#endif
}

/* funzione che cancella carattere
in base alla posizione */
void cancellaPos(char stringa[], int pos)
{
    /* parto dalla posizione prevista e
    scorro tutti i caratteri*/
    for (int i = pos + 1; i < strlen(stringa); i++)
        stringa[i - 1] = stringa[i]; // scorro i caratteri nella posizione precedente

    /* metto nell'ultima posizione,
    prima occupata da un carattere, il terminatore */
    stringa[strlen(stringa)-1]='\0';
}

/* funzione per cancellare
i caratteri uguali nella stringa */
void cancellaCarattere(char stringa[], char carattere)
{
    int indexStringa=0; //dichiaro un indice da incrementare manualmente

    /* scorro tutti i caratteri per cercare
    quello richiesto */
    for (int i = 0; i < strlen(stringa); i++)
    while(indexStringa<strlen(stringa)){
       if (stringa[indexStringa] == carattere) // se lo strovo, sposto tutti i caratteri verso sinistra
            cancellaPos(stringa, indexStringa); //rimango quindi nello stesso indice per verificare un nuovo carattere
       else
            indexStringa++; //altrimenti mi sposto su un nuovo carattere
    }
}

void concatenaCarattere(char stringa[], char carattere)
{
    int lunghezza=strlen(stringa); //trovo la lunghezza della stringa iniziale
    stringa[lunghezza]=carattere; //metto il carattere in coda alla stringa
    stringa[lunghezza+1]='\0'; //aggiungo il terminatore di stringa
}

void main()
{
    /* dichiarazione variabili */
    char stringa[100];
    // menu di scelta utente
    char inputChar;
    char continua;
    int posizione;
    int scelta;
    char opzioni[][200] = {{"OPZIONI PER L'UTENTE"},{"[1] Eliminare un carattere scelto dall'utente"},{"[2] Eliminare un carattere scelto dall'utente in base alla posizione"},{"[3] Aggiungere un carattere scelto a fine stringa"},{"[4] Fine"}};

    /* input dati */
    printf("Inserisci la stringa: ");
    scanf("%s", stringa);


    /* ripetizione operazioni
    fino a quando non si sceglie di terminare */
    do
    {
        scelta = menu(opzioni, sizeof(opzioni) / sizeof(opzioni[0]));
        ClrScr();
        printf("La stringa di riferimento e' %s\n\n", stringa); //dico qual è la stringa di riferimento
        /* switch case con le varie opzioni */
        switch (scelta)
        {
        case 1:
            /* input carattere */
            printf("Inserisci carattere da eliminare: ");
            scanf("%c", &inputChar);
            scanf("%c", &inputChar);
            /* modifica stringa */
            cancellaCarattere(stringa, inputChar);
            /* output risultati */
            printf("\n\nLa stringa modificata e' %s", stringa);
            break;
        case 2:
            do
            { /* input valori */
                printf("Inserisci posizione del carattere da eliminare: ");
                scanf("%d", &posizione);

                /* possibile messaggio di errore */
                if (posizione < 0 || posizione >= strlen(stringa))
                    printf("\nIl valore non appartiene all'intervallo richiesto.\n\n");
            } while (posizione < 0 || posizione >= strlen(stringa)); // controllo se il valore è corretto
            /* modifica stringa */
            cancellaPos(stringa, posizione);
            /* output risultati */
            printf("\n\nLa stringa modificata e' %s", stringa);
            break;
        case 3:
            /* input carattere */
            printf("Inserisci carattere da aggiungere a fine stringa: ");
            scanf("%c", &inputChar);
            scanf("%c", &inputChar);
            /* modifica stringa
            e concatenazione carattere*/
            concatenaCarattere(stringa, inputChar);
            /* output risultati */
            printf("\n\nLa stringa modificata e' %s", stringa);
            break;
        default:
            printf("arresto del sistema");
            sleep(3);
        }

        /* richiesta continuazione programma */
        printf("\n\nPremi INVIO per continuare ");
        scanf("%c", &continua);
        scanf("%c", &continua);
    } while (scelta!=sizeof(opzioni)/sizeof(opzioni[0])-1);
}
