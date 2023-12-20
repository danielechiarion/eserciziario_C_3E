//Author: Daniele Chiarion
//Date: 19-12-2023

/* scrivi il codice di un programma che
riassuma tutte le funzionalità degli esercizi
3 e 4 */

#include <stdio.h>

void main()
{
	/* dichiarazione variabili */
	int scelta;
	
	/* menu di scelta */
	printf("Benvenuto! Scegli tra le seguenti funzionalita': ");
	printf("\nDigita 1 - Sconto di prezzi");
	printf("\nDigita 2 - Conteggio, somma e media di numeri positivi e negativi");
	printf("\nDigita 3 - Somma di numeri primi alterni\n");
	
	/* input con controllo */
	do
	{
		scanf("%d", &scelta);
		
		if(scelta<1 || scelta>3)
			printf("\nValore inserito errato. Riprova\n");
	}while(scelta<1 || scelta>3);
	
	if(scelta==1)
		sconto();
		
		else if(scelta==2)
			posNeg();
			
			else
				numPrimi();
}

void sconto()
{
	/* dichiarazione e inizializzazione di variabili */
    int prezzo;
    int ripetere;
    double sconto;
    double prezzo_scontato;

	/* dichiarazione e inizializzazione di costanti */
	#define SCONTO1 10
	#define SCONTO2 20
	#define SCONTO3 30

    do
    {
        /* inserimento dati input */
        do
        {
            printf("Inserisci un prezzo da pagare: ");
            scanf("%d", &prezzo);
        } while (prezzo <= 0);

        /* calcolo dati */
        if (prezzo <= 500)
        {
            printf("\n\nLo sconto applicato e' del %d%%", SCONTO1);
            prezzo_scontato = (double)(prezzo - prezzo * SCONTO1 / 100);
        }

        else if (prezzo > 500 && prezzo <= 1000)
        {
            printf("\n\nLo sconto applicato e' del %d%%", SCONTO2);
            prezzo_scontato = (double)(prezzo - prezzo * SCONTO2 / 100);
        }

        else
        {
            printf("\n\n Lo sconto applicato e' del %d%%", SCONTO3);
            prezzo_scontato = (double)(prezzo - prezzo * SCONTO3 / 100);
        }

        printf("\nIl prezzo scontato e' %.2f", prezzo_scontato);

        /* richiesta ripetizione */
        do
        {
            printf("\n\nDesidera ripetere?\nInserire 1 per ripetere\n0 per annullare\n");
            scanf("%d", &ripetere);
        } while (ripetere != 0 && ripetere != 1);

    } while (ripetere == 1);
}

void posNeg()
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

void numPrimi()
{
	/* dichiarazione e inizializzazione variabili */
    int num;
    int i=0,j,k;
    int contDiv=0;
    int somma=0;


    /* richiesta inserimento dati input */
    do
    {
        printf("Inserisci un numero positivo: ");
        scanf("%d", &num);
    } while (num<0);

    /* ricerca numeri primi */
    k=num;
    while(i<num*2)
    {
    	for(j=k;j>0;j--)
    	{
    		if(k%j==0)
    			contDiv++;
		}
		
		if(contDiv==2)
		{
			i++;
			
			if(i%2!=0)
			{
				somma=somma+k;
				printf("\nIl %d^ numero primo e' %d", i, k);
			}		
		}
		
		/* incremento e azzeramento variabili opportune */
		contDiv=0;
		k++;
	}
	
	/* output risultati */
	printf("\n\nLa somma finale dei numeri alterni primi maggiori di %d e' %d ", num, somma);
}
