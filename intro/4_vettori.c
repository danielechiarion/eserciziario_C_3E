// Author: Daniele Chiarion
// Date: 22-11-2023

/* Un vettore è una variabile strutturata,
che ha un insieme di valori dello stesso tipo
indicati da un indice */

/* Dopo aver letto n numeri (max 20)
calcolare la somma e la media dei numeri maggiori di 5
e visualizzare i risultati */

#include <stdio.h>
void main()
{
    // dichiarazione e inizializzazione variabili
    int dim, i, n = 0, somma = 0, vet[30];
    float media;

    // richiesta inserimento dati input
    do
    {
        printf("Quanti numeri vuoi inserire? ");
        scanf("%d", &dim);
    } while (dim <= 0 || dim > 20);

    // richiesta dati ed elaborazione
    for (i = 0; i < dim; i++)
    {
        printf("Inserisci un numero: ");
        scanf("%d", &vet[i]);

        if (vet[i] > 5)
        {
            somma = somma + vet[i];
            n++;
        }
    }

    // restituzione dati output
    // se non mettevo if nella media ci sarebbe il messaggio NAN (not a number)
    if (n > 0)
    {
        media = (float)somma / n; // metti il casting (float) altrimenti il numero non viene decimale
        printf("\nLa media dei numeri maggiori di 5 e' %.2f", media);
    }

    else
    {
        printf("Non ci sono numeri maggiori di 5");
    }

    printf("\n\nLa somma dei numeri maggiori di 5 e' %d", somma);
}