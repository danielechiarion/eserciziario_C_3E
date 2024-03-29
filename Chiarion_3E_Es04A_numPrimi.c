//Author: Daniele Chiarion
//Date: 13-12-2023

/* Dato un numero N intero positivo,
stampare la somma dei primi N numeri primi alternati (uno sì e uno no) */

#include <stdio.h>
void main()
{
    /* variables declaration and initialization */
    int num;
    int i=0,j,k;
    int contDiv=0;
    int somma=0;


    /* data input */
    do
    {
        printf("Inserisci un numero positivo: ");
        scanf("%d", &num);
    } while (num<0);

    /* prime numbers research */
    k=num;
    while(i<num*2)
    {
    	/* count of the dividers */
    	for(j=k+1;j>0;j--)
    	{
    		if(k%j==0)
    			contDiv++;
		}
		
		/* if the dividers are two, it's a prime number */
		if(contDiv==2)
		{
			i++;
			
			/* adding alternate values to the somma variable */
			if(i%2!=0)
			{
				somma=somma+k;
				printf("\nIl %d^ numero primo e' %d", i, k);
			}		
		}
		
		/* increasing and reset for the proper variables */
		contDiv=0;
		k++;
	}
	
	/* output of the results */
	printf("\n\nLa somma finale dei numeri alterni primi maggiori di %d e' %d ", num, somma);
}
