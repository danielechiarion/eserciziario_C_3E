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
    /* variables declaration and initialization */
    int dim;
    int contPos=0, contNeg=0;
    int sommaPos=0, sommaNeg=0;
    int i;
    double mediaPos=0, mediaNeg=0;

    /* data input */
    do
    {
        printf("Quanti numeri vuoi inserire? ");
        scanf("%d", &dim);
    } while (dim<=0);

    /* array declaration and initialization */
    int vet[dim];

    /* input data request */
    printf("\n\n");
    for(i=0;i<dim;i++)
    {
        printf("Inserisci un valore: ");
        scanf("%d", &vet[i]);

		/* control if the number is positive of negative, so decide where the value will be added up */
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

    /* calculate of the averages */ 
    mediaPos=(double) sommaPos/contPos;
    mediaNeg=(double) sommaNeg/contNeg;

    /* output df the results */
    printf("\n\nNUMERI POSITIVI: ");
    printf("Numero = %d", contPos);
    printf("\nSomma = %d", sommaPos);
    printf("\nMedia = %.2f", mediaPos);
    printf("\n\nNUMERI NEGATIVI: ");
    printf("Numero = %d", contNeg);
    printf("\nSomma (valore assoluto) = %d", sommaNeg);
    printf("\nMedia = %.2f", mediaNeg);
}
