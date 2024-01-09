// Author: Daniele Chiarion
// Date: 13-12-2023

/* Su una somma di denaro (relativa all'acquito di un prodotto) si vuole applicare uno sconto in base all'importo inserito seguendo il seguente schema:
            da 0 a 500€ sconto del 10%;
            da 501 a 1000 sconto del 20%;
            oltre i 1001 sconto 30%;
 Il programma dopo aver calcolato e visualizzato a video lo sconto ed il prezzo netto deve permettere di re-inserire
 ulteriori somme di denaro. */

#include <stdio.h>
void main()
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

        /* different instructions for different prices */
        if (prezzo <= 500)
        {
            printf("\n\nLo sconto applicato e' del %d%%", SCONTO1); //output of the discount
            prezzo_scontato = (double)(prezzo - prezzo * SCONTO1 / 100); //calculating the discounted price
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

        /* repetition request*/
        do
        {
            printf("\n\nDesidera ripetere?\nInserire 1 per ripetere\n0 per annullare\n");
            scanf("%d", &ripetere);
        } while (ripetere != 0 && ripetere != 1);

    } while (ripetere == 1);
}
