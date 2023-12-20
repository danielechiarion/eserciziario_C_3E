//Author: Daniele Chiarion
//Date: 13-12-2023

/* Dato un numero N intero positivo,
stampare la somma dei primi N numeri primi alternati (uno sì e uno no) */

#include <stdio.h>
void main()
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
    	for(j=k+1;j>0;j--)
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
