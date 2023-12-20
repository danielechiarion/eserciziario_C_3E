// Author: Daniele Chiarion
// Date: 15-11-2023

/* Programma che legge N numeri interi con N scelto dall'utente e calcola
la somma e la media dei numeri inseriti
stampando i risultati a video */

#include <stdio.h>

#define NOME "Daniele Chiarion"
void main()
{
    // dichiarazione e inizializzazione variabili
    int volte, i = 0, numero, somma=0;
    float media;

    // richiesta inserimento dati input
    do
    {
        printf("Inserisci quanti numeri vuoi inserire: ");
        scanf("%d", &volte);
    } while (volte <= 0);

    while (i < volte)
    {
        printf("Inserisci un numero: ");
        scanf("%d", &numero);

        somma = somma + numero;
        i++;
    }

    media = (float)somma / volte; //applicando il casting dico di rendere il risultato decimale

    // restituzione dati output
    printf("\n\nLa somma dei numeri inseriti e' %d", somma);
    printf("\nLa media dei numeri inseriti e' %.2f", media);
    printf("\n\n\nIl programma è stato realizzato da %s", NOME);
}