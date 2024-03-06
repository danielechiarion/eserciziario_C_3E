//Author: Daniele Chiarion
//Date: 06-03-2024

/* Scrivere un programma in c che dopo aver inserito un vettore di N numeri controlli l’esistenza di
un numero richiesto successivamente all’utente. In caso affermativo visualizzare quante volte si
ripete il numero e che posizione/i occupa nel vettore utilizzato. */

#include <stdio.h>

void main()
{
    /* dichiarazione variabili */
    int dim;
    int numCheck;
    int freq;
    int i;

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
    printf("\nInserisci il numero da verificare: ");
    scanf("%d", &numCheck);

    /* elaborazione dati */
    freq=contFreq(vet, dim, numCheck);

    /* primo output,
    se il valore compare nel vettore o meno */
    if(freq==0)
        printf("\n\nIl valore inserito non compare nel vettore.");
    else
    {
        int posNum[freq]; //dichiaro vettore
        scriviPosizioneNum(vet, dim, numCheck, posNum);

        /* output risultati */
        printf("\n\nIl numero compare %d volte nelle posizioni:\n", freq);
        for(i=0;i<freq;i++)
        {
            printf("%d\t", posNum[i]);
        }
    }
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

/* metodo per contare la frequenza con cui un dato e' presente */
int contFreq(int vet[], int size, int num)
{
    /* dichiarazione variabili */
    int i;
    int freq=0;

    /* scorro tutti i dati per vedere quante volte
    compare lo stesso numero */
    for(i=0;i<size;i++)
    {
        if(vet[i]==num)
            freq++;
    }

    return freq; //ritorno la frequenza
}

/* metodo per copiare la posizione del dato */
/* con vet1 si intende l'array originario
con vet2 l'array da popolare con le posizioni del numero */
void scriviPosizioneNum(int vet[], int size, int num, int vet2[])
{
    int index=0; //dichiaro indice vet2
    int i;

    for(i=0;i<size;i++)
    {
        if(vet[i]==num)
        {
            vet2[index]=i; //inserisco il valore
            index++; //aumento l'indice
        }
    }
}
