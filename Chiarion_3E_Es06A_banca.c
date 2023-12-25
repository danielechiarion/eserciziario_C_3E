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

#include <stdio.h> //libreria per I/O
#include <string.h> //libreria per la gestione delle stringhe
void main()
{
	/* dichiarazione e inizializzazione variabili */
	char nome[100], nomeMin[100], nomeMax[100];
	char fine[10];
	float prezzo, prezzoMin, prezzoMax;
	float somma=0, somma2=0;
	float media, media2;
	int cont=0, cont2=0;
	
	/* definizione costanti */
	#define TERMINE1 2.5
	#define TERMINE2 3.5
	
	/* ripetizione inserimento valori */
	do
	{
		/* richiesta inserimento dati */
		printf("Inserisci nome azione: ");
		scanf("%s", &nome);
		printf("Inserisci prezzo azione: ");
		scanf("%f", &prezzo);
		
		/* elaborazione dati */
		if(cont==0)
		{
			prezzoMin=prezzo;
			prezzoMax=prezzo;
			strcpy(nomeMin, nome); //strcpy serve per assegnare un valore di una stringa ad un'altra
			strcpy(nomeMax, nome);
		}
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
		
		somma+=prezzo;
		cont++;
		
		if(prezzo>=TERMINE1 && prezzo<=TERMINE2)
		{
			somma2+=prezzo;
			cont2++;
		}
		
		/* richiesta ripetizione operazioni */
		printf("Desideri inserire una nuova azione?\nDigita SI per confermare, qualsiasi altro tasto per annullare\n");
		scanf("%s", &fine);
	}while(strcmp(fine, "SI")==0 || strcmp(fine, "si")==0); //strcmp serve per confrontare il contenuto tra stringhe. Se dà risultato 0 significa che sono uguali.
																	
	/* calcolo medie */
	media=somma/cont;
	media2=somma2/cont2;
	
	/* output risultati */
	printf("\n\nLa somma dei prezzi delle azioni e' %.2f€", somma);
	printf("\nLa media dei prezzi delle azioni e' %.2f€", media);
	printf("\nL'azione con il prezzo minimo e' %s con %.2f€", nomeMin, prezzoMin);
	printf("\nL'azione con il prezzo massimo e' %s con %.2f€", nomeMax, prezzoMax);
	printf("\nLa media delle azioni comprese tra %.2f€ e %.2f€ e' %.2f€", TERMINE1, TERMINE2, media2);																
}
