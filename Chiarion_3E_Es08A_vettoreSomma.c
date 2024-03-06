//Author: Daniele Chiarion
//Date: 06-03-2024

/* Dopo aver caricato in memoria un 2 vettori di uguale dimensione composti da numeri interi
scrivere in output un terzo vettore dato dalla somma delle componenti fatta a una a una (Vettore
somma). */

void main()
{
    /* dichiarazione variabili */
    int dimensione;
    int i;

    /* richiesta inserimento dati input */
    do
    {
        printf("Inserisci la dimensione del vettore: ");
        scanf("%d", &dimensione);
        /* messaggio di errore */
        if(dimensione<=0)
            printf("Valore inserito negativo o nullo. Riprova.\n");
    } while (dimensione<=0);

    /* dichiarazione vettori */
    int vet1[dimensione], vet2[dimensione], vetSomma[dimensione];

    /* input dati */
    inputDatiVet(dimensione, 1, vet1);
    inputDatiVet(dimensione, 2, vet2);

    /* somma vettori */
    sommaVet(vet1, vet2, vetSomma, dimensione);

    /* output risultati */
    printf("\n\nVETTORE SOMMA\n");
    for(i=0;i<dimensione;i++)
    {
        printf("%d\t", vetSomma[i]);
    }
}

/* metodo per l'inserimento dati */
void inputDatiVet(int size, int ordine, int vet[])
{
    int i;
    printf("\n\n%d^ VETTORE\n", ordine);
    for(i=0;i<size;i++)
    {
        /* input dati */
        printf("Inserisci il %d^ numero: ", i+1);
        scanf("%d", &vet[i]);
    }
}

/* metodo per la somma dei vettori */
void sommaVet(int vet1[], int vet2[], int vetSomma[], int size)
{
    int i;
    /* popolamento vettore somma */
    for(i=0;i<size;i++)
    {
        vetSomma[i]=vet1[i]+vet2[i];
    }
}