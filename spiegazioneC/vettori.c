//Author: Daniele Chiarion
//Date: 06-03-2024

/* esercizio spiegazione vettori */

void main()
{
    /* dichiarazione variabili */
    int numElementi;
    int i;
    /* dichiarazione vettore */
    int vet[10];

    /* richiesta inserimento elementi da inserire */
    do
    {
        printf("Quanti numeri vuoi inserire? (da 1 a 10): ");
        scanf("%d", &numElementi);
    } while (numElementi<=0 || numElementi>10);
    

    /* richiesta inserimento dati */
    for(i=0;i<numElementi; i++)
    {
        printf("Inserisci %d^ numero: ", i+1);
        scanf("%d", &vet[i]);
    }

    /* output dati inseriti */
    printf("\n\nNUMERI INSERITI:\n");
    for(i=0;i<numElementi;i++)
    {
        printf("%d\t", vet[i]);
    }
}