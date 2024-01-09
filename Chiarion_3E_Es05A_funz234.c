//Author: Daniele Chiarion
//Date: 19-12-2023

/* scrivi il codice di un programma che
riassuma tutte le funzionalità degli esercizi
3 e 4 */

#include <stdio.h>

void main()
{
	/* variable declaration */
	int scelta;
	
	/* possible choices */
	printf("Benvenuto! Scegli tra le seguenti funzionalita': ");
	printf("\nDigita 1 - Sconto di prezzi");
	printf("\nDigita 2 - Conteggio, somma e media di numeri positivi e negativi");
	printf("\nDigita 3 - Somma di numeri primi alterni\n");
	
	/* control of input */
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

/* function to calculate a discount */
void sconto()
{
	/* variables declaration and initialization */
    int prezzo;
    int ripetere;
    double sconto;
    double prezzo_scontato;

	/* constants declaration and initialization */
	#define SCONTO1 10
	#define SCONTO2 20
	#define SCONTO3 30

    do
    {
        /* data input */
        do
        {
            printf("Inserisci un prezzo da pagare: ");
            scanf("%d", &prezzo);
        } while (prezzo <= 0);

        /* different discounts for different amount of money */
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

		/* output of the result */
        printf("\nIl prezzo scontato e' %.2f", prezzo_scontato);

        /* possible repetition with input control */
        do
        {
            printf("\n\nDesidera ripetere?\nInserire 1 per ripetere\n0 per annullare\n");
            scanf("%d", &ripetere);
        } while (ripetere != 0 && ripetere != 1);

    } while (ripetere == 1);
}

/* function to calculate the addition of positive and negative numbers */
void posNeg()
{
	/* variables declaration and initialization */
    int dim;
    int contPos=0, contNeg=0;
    int sommaPos=0, sommaNeg=0;
    int i;
    double mediaPos=0, mediaNeg=0;

    /* input data request */
    do
    {
        printf("Quanti numeri vuoi inserire? ");
        scanf("%d", &dim);
    } while (dim<=0);

    /* declaration and initialization array */
    int vet[dim];

    /* input data */
    printf("\n\n");
    for(i=0;i<dim;i++)
    {
        printf("Inserisci un valore: ");
        scanf("%d", &vet[i]);

		/* control if the number is positive or negative, so decide where it will be added up */
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

    /* calculate of avarages */ 
    mediaPos=(double) sommaPos/contPos;
    mediaNeg=(double) sommaNeg/contNeg;

    /* output of the results */
    printf("\n\nNUMERI POSITIVI: ");
    printf("Numero = %d", contPos);
    printf("\nSomma = %d", sommaPos);
    printf("\nMedia = %.2f", mediaPos);
    printf("\n\nNUMERI NEGATIVI: ");
    printf("Numero = %d", contNeg);
    printf("\nSomma (valore assoluto) = %d", sommaNeg);
    printf("\nMedia = %.2f", mediaNeg);
}

/* function to find prime numbers */
void numPrimi()
{
	 /* variables declaration and initialization */
    int num;
    int i=0,j,k=2;
    int contDiv=0;
    int somma=0;


    /* data input */
    do
    {
        printf("Inserisci un numero positivo: ");
        scanf("%d", &num);
    } while (num<0);

    /* prime numbers research */
    while(i<num*2)
    {
    	/* finding the dividers of the number */
    	for(j=k;j>0;j--)
    	{
    		if(k%j==0)
    			contDiv++;
		}
		
		/* if the dividers of the number are 2, this is a prime number */
		if(contDiv==2)
		{
			i++;
			
			/* alternating the sum of prime numbers */
			if(i%2!=0)
			{
				somma=somma+k;
				printf("\nIl %d^ numero primo e' %d", i, k);
			}		
		}
		
		/* increase and reset of the proper variables */
		contDiv=0;
		k++;
	}
	
	/* output of the results */
	printf("\n\nLa somma finale dei numeri alterni primi maggiori di %d e' %d ", num, somma);
}
