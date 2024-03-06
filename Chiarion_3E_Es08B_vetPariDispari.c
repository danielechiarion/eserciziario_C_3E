//Author: Daniele Chiarion
//Date: 06-03-2024

/* Scrivere un programma in c che dopo aver inserito un vettore di N numeri interi separi il vettore
inserito in 2 ulteriori vettori il primo contenente i numeri pari ed il secondo con i numeri dispari. */

#include <stdio.h>
#include <stdlib.h>

void main()
{
    /* dichiarazione variabili */
    int dim;

    /* richiesta inserimento dati input */
    do
    {
        printf("Inserisci quanti numeri vuoi inserire: ");
        scanf("%d", &dim);
        /* messaggio di errore */
        if(dim<=0)
            printf("Valore inserito negativo o nullo. Riprova\n");
    } while (dim<=0);

    /* dichiarazione vettore */
    int vet[dim];

    /* input dati */
    inputDatiVet(dim, vet);

    /* dichiarazione vettori pari e dispari */
    int vetPari[contaPariODispari(vet, dim, 0)];
    int vetDispari[contaPariODispari(vet, dim, 1)];
    /* popolamento vettori pari e dispari */
    popolaVettore(vet, dim, 0, vetPari);
    popolaVettore(vet, dim, 1, vetDispari);

    /* output risultati */
    printf("\n\nVETTORE NUMERI PARI: \n");
    printRisultati(vetPari, sizeof(vetPari)/sizeof(vetPari[0]));
    printf("\n\nVETTORE NUMERI DISPARI: \n");
    printRisultati(vetDispari, sizeof(vetDispari)/sizeof(vetDispari[0]));
}

/* metodo per l'input dati */
void inputDatiVet(int size, int vet[])
{
    int i;
    printf("\n\nVETTORE\n");
    for(i=0;i<size;i++)
    {
        /* input dati */
        printf("Inserisci il %d^ numero: ", i+1);
        scanf("%d", &vet[i]);
    }
}

/* funzione che conta quanti pari e quanti dispari, +ù
- INSERIRE 0 per contare i pari
- INSERIRE 1 per contare i dispari */
int contaPariODispari(int vet[], int size, int scelta)
{
    /* dichiarazione variabili */
    int cont=0;
    int i;

    /* scorrimento valori array */
    for(i=0;i<size;i++)
    {
        /* se ho scelto di contare i numeri pari e il numero è pari
        o se ho scelto di contare i numeri dispari e il numero è dispari
        aumento il contatore*/
        if((vet[i]%2==0 && scelta==0) || (vet[i]%2!=0 && scelta==1))
            cont++;
    }

    return cont; //ritorno valore
}

/* metodo per popolare il vettore
di pari o dispari:
- INSERIRE 0 per i pari
- INSERIRE 1 per i dispari */

/*
- vet è il vettore contenente tutti i numeri
- size è la dimensione di vet
- scelta indica se popolare vettore di pari o di dispari
- vet2 è il vettore da popolare */
void popolaVettore(int vet[], int size, int scelta, int vet2[])
{
    int index=0; //dichiarazione indice vet2 (pari o dispari)
    int i;

    for(i=0;i<size;i++)
    {
        /* se il numero è dispari e sto popolando il vettore dei dispari
        o se il numero è pari e sto popolando il vettore dei pari
        assegno il valore al vettore e aumento il suo indice */
        if((vet[i]%2==0 && scelta==0) || (vet[i]%2!=0 && scelta==1))
        {
            vet2[index]=vet[i]; //assegno il valore al vettore
            index++; //aumento l'indice
        }
    }
}

/* funzione per stampare i risultati di un vettore */
void printRisultati(int vet[], int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d\t", vet[i]);
    }
}
