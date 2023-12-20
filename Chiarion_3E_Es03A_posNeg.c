//Author: Daniele Chiarion
//Date: 13-12-2023

/* Scrivere un programma in C che, dopo aver letto N numeri (n scelto dall'utente) calcoli e visualizzi a video 
- la somma dei numeri positivi
- la somma dei numeri negativi in valore assoluto
- il conteggio dei numeri negativi e positivi
- la media dei numeri positivi e negativi.*/

#include <stdio.h>
void main()
{
    /* dichiarazione e inizializzazione variabili */
    int dim;
    int contPos=0, contNeg=0;
    int sommaPos=0, sommaNeg=0;
    int i;
    double mediaPos=0, mediaNeg=0;

    /* richiesta numero valori */
    do
    {
        printf("Quanti numeri vuoi inserire? ");
        scanf("%d", &dim);
    } while (dim<=0);

    /* dichiarazione e inizializzazione vettori */
    int vet[dim];

    /* richiesta inserimento valori */
    printf("\n\n");
    for(i=0;i<dim;i++)
    {
        printf("Inserisci un valore: ");
        scanf("%d", &vet[i]);

        if(vet[i]<0)
        {
            contNeg++;
            sommaNeg=sommaNeg-vet[i];
        }

        else
        {
            contPos++;
            sommaPos=sommaPos+vet[i];
        }
    }

    /* calcolo media */ 
    mediaPos=(double) sommaPos/contPos;
    mediaNeg=(double) sommaNeg/contNeg;

    /* output di sistema */
    printf("\n\nNUMERI POSITIVI: ");
    printf("Numero = %d", contPos);
    printf("\nSomma = %d", sommaPos);
    printf("\nMedia = %.2f", mediaPos);
    printf("\n\nNUMERI NEGATIVI: ");
    printf("Numero = %d", contNeg);
    printf("\nSomma (valore assoluto) = %d", sommaNeg);
    printf("\nMedia = %.2f", mediaNeg);
}