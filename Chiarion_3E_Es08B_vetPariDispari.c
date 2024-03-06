//Author: Daniele Chiarion
//Date: 06-03-2024

/* Scrivere un programma in c che dopo aver inserito un vettore di N numeri interi separi il vettore
inserito in 2 ulteriori vettori il primo contenente i numeri pari ed il secondo con i numeri dispari. */

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
}

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
        aumento il contatore*/
        if(scelta==0 && vet[i]%2==0)
            cont++;
        /* se ho scelto di contare i numeri dispari e il numero è dispari 
        aumento il contatore*/    
        else if(scelta==1 && vet[i]%2!=0)
            cont++;    
    }

    return cont; //ritorno valore
}