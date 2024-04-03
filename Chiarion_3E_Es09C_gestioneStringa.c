//Author: Daniele Chiarion
//Date: 03-04-2024

/* Scrivere
un programma in C che dopo aver inserito una stringa a piacere
permetta di:

1)Inserire un carattere, scelto dall’utente in una posizione sempre
scelta dall’utente;

2)Sostituisca un carattere, scelto dall’utente, con il seguente: X. */

#include <stdio.h>
#include <string.h>

/* funzione che inserisce un carattere
in una posizione specifica della stringa */
void inserisciChar(char stringa[], char car, int pos){
    stringa[pos]=car; //inserisco carattere nella posizione prevista

    /* se il carattere è in coda alla stringa, 
    sposto il terminatore */
    if(pos==strlen(stringa))
        stringa[pos+1]='\0';
}

/* funzione che sostituisce il carattere
presente nella stringa con X */
void sostiuisciX(char stringa[], char car){
    /* scorro tutti i caratteri */
    for(int i=0;i<strlen(stringa);i++){
        if(stringa[i]==car) //se trovo il carattere
            stringa[i]='X'; //sostiuisco nella stringa
    }
}

void main(){
    /* dichiarazione variabili */
    char stringa[50];
    char inputChar;
    int posizione;

    /* input stringa */
    printf("Inserisci stringa: ");
    scanf("%s", stringa);

    /* PUNTO 1 
    inserisco carattere a piacere in una posizione a piacere 
    scelta dall'utente*/
    /* input dati */
    printf("\nInserisci un carattere da aggiungere: ");
    scanf("%c", &inputChar);
    scanf("%c", &inputChar);
    do
    {
        printf("Inserisci posizione inserimento carattere: ");
        scanf("%d", &posizione);
        /* messaggio di errore */
        if(posizione>strlen(stringa) || posizione<0)
            printf("\nIl valore inserito e' negativo o superiore alla lunghezza della stringa\n\n");
    } while (posizione>strlen(stringa) || posizione<0); //controllo che l'indice inserito sia corretto e non superiore alla lunghezza della stringa e non negativo

    inserisciChar(stringa, inputChar, posizione); //modifico stringa
    
    /* output risultati */
    printf("\nLa stringa modificata e' %s", stringa);


    /* PUNTO 2 */
    /* sostiture un carattere, 
    scelto dall'utente, con X */
    /* input carattere */
    printf("\n\nInserisci carattere da modificare con X: ");
    scanf("%c", &inputChar);
    scanf("%c", &inputChar);

    sostiuisciX(stringa, inputChar); //modifico la stringa

    /* output risultati */
    printf("\nLa stringa modificata e' %s", stringa);
}