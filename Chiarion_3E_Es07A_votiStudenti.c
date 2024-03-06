// Author: Daniele Chiarion
// Date: 21-02-2024

/* Scrivere un programma in C che dopo aver inserito
i cognomi e i voti di una classe di studenti
determini e/o verifichi:
1) La media dei voti visualizzando, inoltre il numero di studenti inseriti;
 2) Il voto massimo, il voto minimo ed I relativi cognomi degli studenti
 3) Il numero degli studenti che hanno una valutazione sufficiente o superiore
 4) Il numero degli studenti che hanno una valutazione insufficiente o inferiore;
 5) Il numero di studenti che hanno un voto compreso tra 7.50 e 10 estremi inclusi.
Il programma deve permettere il re-inserimento degli studenti e dei relativi voti. */

#include <stdio.h>
#include <string.h>
void main()
{
    /* dichiarazione variabili */
    float voto;
    int numStudenti, contSuff = 0, contAlto = 0;
    int somma = 0;
    float media = 0;
    char ripetere;
    char cognome[20];
    float votoMin, votoMax;
    char nomeMin[20], nomeMax[20];

/* definizione costanti */
#define valMin 7.5
#define valMax 10.0

    do
    {
        ClrScr(); // pulizia schermo
        /* richiesta inserimento studenti */
        do
        {
            printf("Quanti studenti vuoi valutare? ");
            scanf("%d", &numStudenti);
        } while (numStudenti <= 0); // controllo per verificare che il numero di studenti non sia negativo o nullo

        for (int i = 0; i < numStudenti; i++)
        {
            /* richiesta inserimento dati */
            printf("\nInserisci cognome: ");
            scanf("%s", &cognome);
            do
            {
                printf("Inserisci voto: ");
                scanf("%f", &voto);
            } while (voto < 0 || voto > 10); // controllo voto inserito

            /* calcolo dati */
            somma += voto;
            if (voto >= 6)
                contSuff++;
            if (voto >= valMin && voto <= valMax)
                contAlto++;
            /* al primo avvio il primo voto diventa minimo e massimo */
            if (i == 0)
            {
                votoMin = voto;
                votoMax = voto;
                strcpy(nomeMin, cognome);
                strcpy(nomeMax, cognome);
            }
            else
            {
                /* se il voto e' minore, si assegna al voto minimo il valore del voto */
                if (voto < votoMin)
                {
                    votoMin = voto;
                    strcpy(nomeMin, cognome);
                }
                /* se il voto e' maggiore, si assegna al voto massimo il valore del voto */
                if (voto > votoMax)
                {
                    votoMax = voto;
                    strcpy(nomeMax, cognome);
                }
            }
        }

        /* calcolo media */
        media = somma / numStudenti;

        /* Output risultati */
        printf("\n\nLa media totale e' %.2f", media);
        printf("\nIl numero di studenti sufficienti e' %d", contSuff);
        printf("\nIl numero degli studenti insufficienti e' %d", numStudenti - contSuff);
        printf("\nIl numero degli studenti con voti compresi tra %.f e %.f e' %d", valMin, valMax, contAlto);
        printf("\n\nIl voto piu' alto e' stato preso da %s con %.f", nomeMax, votoMax);
        printf("\nIl voto piu' basso e' stato preso da %s con %.f", nomeMin, votoMin);

        /* azzeramento variabili */
        contSuff = 0;
        contAlto = 0;
        somma = 0;

        /* richiesta ripetizione programma */
        printf("\n\nVuoi inserire nuovi voti?\nDigita S per confermare, qualsiasi altro tasto per annullare: ");
        scanf("%c", &ripetere);
        scanf("%c", &ripetere);
    } while (ripetere == 'S' || ripetere == 's'); // ripetizione ciclo se la condizione viene rispettata
}

/* method for clearing screen */
void ClrScr()
{
#ifdef _WIN32      // Check if the OS is Windows
    system("cls"); // instruction for clearing cmd of Windows
#else
    system("clear"); // instruction for clearing shell of Linux / MacOS
#endif
}