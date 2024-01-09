//Author: Daniele Chiarion
//Date: 21-12-2023

/* Una banca vuole conoscere alcune informazioni sulle proprie azioni detenute in portafoglio.
Scrivere il programma in c che dopo aver inserito da tastiera la denominazione dell’azione e il suo prezzo
determini e visualizzi in Output:
1) La somma dei prezzi delle azioni;
2) La media dei prezzi delle azioni;
3) L’azione con il prezzo massimo;
4) L’azione con il prezzo minimo
5) La media dei prezzi delle azioni con un importo compreso tra 2,50 e 3,50 euro, estremi inclusi.
L’inserimento termina con la parola “terminato”.
Il programma deve permettere il reinserimento del prezzo se è pari a zero o inferiore. */

#include <stdio.h> //I/O library
#include <string.h> //string management library
void main()
{
	/* variables declaration and initialization */
	char nome[100], nomeMin[100], nomeMax[100];
	char fine[10];
	float prezzo, prezzoMin, prezzoMax;
	float somma=0, somma2=0;
	float media, media2;
	int cont=0, cont2=0;
	
	/* constants definition */
	#define TERMINE1 2.5
	#define TERMINE2 3.5
	
	/* loop */
	do
	{
		/* input datas */
		printf("Inserisci nome azione: ");
		scanf("%s", &nome);
		printf("Inserisci prezzo azione: ");
		scanf("%f", &prezzo);
		
		/* finding maximum and minimum (we first assing at the fist value both maximun and minimum) */
		if(cont==0)
		{
			prezzoMin=prezzo;
			prezzoMax=prezzo;
			strcpy(nomeMin, nome); //we use strcpy to copy a string from a variable to another
			strcpy(nomeMax, nome);
		}
		/* conditions for the change of maximum and minimum */
		else
		{
			if(prezzo<prezzoMin)
			{
				prezzoMin=prezzo;
				strcpy(nomeMin, nome);
			}
			
			if(prezzo>prezzoMax)
			{
				prezzoMax=prezzo;
				strcpy(nomeMax, nome);
			}
		}
		
		/* increasing of the variables */
		somma+=prezzo;
		cont++;
		
		/* particular increasing for a precise interval */
		if(prezzo>=TERMINE1 && prezzo<=TERMINE2)
		{
			somma2+=prezzo;
			cont2++;
		}
		
		/* demand of repeat the whole process before */
		printf("Desideri inserire una nuova azione?\nDigita SI per confermare, qualsiasi altro tasto per annullare\n");
		scanf("%s", &fine);
	}while(strcmp(fine, "SI")==0 || strcmp(fine, "si")==0); //strcmp serve per confrontare il contenuto tra stringhe. Se dà risultato 0 significa che sono uguali.
																	
	/* calcultaion of avarage prices of actions */
	media=somma/cont;
	media2=somma2/cont2;
	
	/* output of the results */
	printf("\n\nLa somma dei prezzi delle azioni e' %.2f€", somma);
	printf("\nLa media dei prezzi delle azioni e' %.2f€", media);
	printf("\nL'azione con il prezzo minimo e' %s con %.2f€", nomeMin, prezzoMin);
	printf("\nL'azione con il prezzo massimo e' %s con %.2f€", nomeMax, prezzoMax);
	printf("\nLa media delle azioni comprese tra %.2f€ e %.2f€ e' %.2f€", TERMINE1, TERMINE2, media2);																
}
