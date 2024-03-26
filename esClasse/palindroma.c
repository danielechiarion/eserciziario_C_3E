//Author: Daniele Chiarion
//Date: 26-03-2024

/* scrivi un programma che rilevi i pezzi di stringa
palindromi */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* funzione per copiare il contenuto parziale
di una stringa sorgente verso una
stringa di destinazione */
void copiaStringa(char src[], char dest[], int start, int finish)
{
    int indexStringa=0; //dichiarazione indice stringa di destinazione

    /* scorro tutti i caratteri partendo
    dai parametri di inizio e fine ricevuti */
    for(int i=start;i<=finish;i++)
    {
        dest[indexStringa]=src[i]; //copio ogni carattere
        indexStringa++; //aumento indice
    }

    dest[indexStringa]='\0'; //assegno terminatore finale
}

/* funzione per stampare a schermo
una stringa palindroma */
void printResult(char stringa[])
{
    printf("\n%s", stringa);
}

/* funzione booleana che controlla
se una stringa è palindroma */
bool isPalindroma(char stringa[], int limite)
{
    /* dichiarazione e inizializzazione variabili */
    bool check=true;
    int lung=strlen(stringa); //lunghezza stringa data

    /* anzitutto controllo se la lunghezza
    della stringa è maggiore o uguale a limite minimo imposto */
    if(lung<limite)
        check=false;
    else
    {
        /* scorro tutti i valori
        fino a metà stringa */
        for(int i=0;i<lung/2;i++)
        {
            /* al primo carattere non uguale al suo
            corrispondente opposto nella stringa */
            if(stringa[i]!=stringa[lung-1-i]){
                check=false; //cambio valore variabile
                break; //esco dal ciclo
            }
        }
    }

    return check; //ritorno valore
}

/* funzione che prende in input una stringa e un limite di minimo di parole
e ritorna in output a schermo tutte le stringhe palindrome trovate */
void palindroma(char stringa[], int limite)
{
    char stringa2[50]; //creo seconda stringa

    /* creo tutte le possibili stringhe*/
    /* parto dalla stringa completa
    per poi togliere un carattere di volta in volta */
    for(int i=0;i<strlen(stringa);i++)
    {
        /* per ogni stringa di cui togliamo un carattere
        proviamo tutte le combinazioni,
        riducendone ogni volta la lunghezza */
        for(int k=strlen(stringa)-1;k>=i+2;k--)
        {
            copiaStringa(stringa, stringa2, i, k); //creiamo la nuova stringa
            if(isPalindroma(stringa2, limite)) //verifichiamo se è palindroma
                printResult(stringa2); //eventualmente stampiamo a video
        }
    }
}

void main()
{
    char input[]="lacassatasiciliana"; //inizializzo la stringa

    palindroma(input, 3); //invoco la funzione
}
