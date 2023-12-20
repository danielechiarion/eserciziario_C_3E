//Author: Daniele Chiarion
//Date: 22-11-2023

/* Dopo aver letto N numeri interi (max 30)
calcolare la somma e la media dei numeri pari e dei numeri dispari*/

#include <stdio.h>
void main()
{
    //dichiarazione  e inizializzazione variabili
    int dim,i,contp,contD,sommaP,sommaD;
    float mediaP,mediaD;

    //richiesta inserimento dati input
    do
    {
        printf("Quanti numeri vuoi inserire? ");
        scanf("%d", &dim);
    } while (dim<=0 || dim>30);

    //dichiarazione vettore
    int vet[dim];

    //elaborazione dati
    for(i=0;i<dim;i++)
    {
        do
        {
            printf("Inserisci un numero: ")
        } while (/* condition */);
        
        if()
    }
    
}