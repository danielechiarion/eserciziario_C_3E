//Author: Daniele Chiarion
//Date: 13-03-2024

/* Scrivere un programma in C che dopo aver inserito una stringa a piacere determini e o verifichi:
1) Il numero di consonanti e vocali contenute;
2) Che contenga solo lettere;
3) Il conteggio di una lettera (se presente) scelta dall’utente;
4) Crei 2 ulteriori stringhe che contengano 1 le lettere di posizione pari; la 2° le lettere di posizione
dispari;
5) Verifichi se contiene doppie.
Inserita una 2° stringa determinare:
1) Quale delle 2 è più lunga e più corta;
2) Quale delle 2 stringhe contiene più vocali;
3) Quale delle 2 stringhe contiene più consonanti;
4) Quali sono le lettere contenute in ambedue le stringhe;*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void main()
{
    /* dichiarazione variabili */
    bool soloLettere;
    int contVocali1, contConsonanti1;
    /* dichiarazione vettore */
    char stringa[100];
    char carVerifica;

    /* richiesta inserimento dati input */
    do
    {
        printf("Inserisci la stringa in input (solo caratteri alfabetici): ");
        scanf("%s", &stringa);
        maiusc(stringa); //converto la stringa in maiuscolo per evitare problemi
        soloLettere=checkSoloLettere(stringa);
        /* possibile messaggio di errore */
        if(!soloLettere)
            printf("\nHai inserito dei caratteri non alfabetici. Riprova.");
    } while (!soloLettere);

    /* conteggio vocali e consonanti */
    contVocali1 = contaVocali(stringa);
    contConsonanti1=strlen(stringa)-contVocali1;

    /* output primi risultati */
    printf("\n\nNella stringa sono presenti %d vocali", contVocali1);
    printf("\nNella stringa sono presenti %d consonanti", contConsonanti1);
    
    /* inserimento carattere di verifica */
    do
    {
        printf("Inserisci il carattere alfabetico maiuscolo di verifica: ");
        scanf("%c", &carVerifica);
    } while (carVerifica<'A' || carVerifica>'Z');

    /* output di quanti caratteri uguali 
    presenti nella stringa*/
    printf("\n\nIl carattere %c e' presente %d volte", carVerifica, contaChar(carVerifica, stringa));


}

/* funzione per controllare se
la stringa inserita contiene solo caratteri numerici */
bool checkSoloLettere(char stringa[])
{
    bool result=true; //dichiarazione e inizializzazione variabile
    
    for(int i=0;i<strlen(stringa);i++)
    {
        /* se trovo un valore non alfabetico, 
        il valore diventa false */
        if(stringa[i]<'A' || stringa[i]>'Z')
        {
            result=false;
            break;
        }
    }

    return result; //ritorno risultato in booleano
}

char maiusc(char stringa[])
{
    char stringa2[strlen(stringa)];
    for(int i=0;i<strlen(stringa);i++)
        stringa2[i]=toupper(stringa[i]);

    return stringa2;
}

/* funzione per contare le vocali in una stringa */
int contaVocali(char stringa[])
{
    int contatore=0;

    /* scorro ogni carattere e verifico se c'è una vocale */
    for(int i=0;i<strlen(stringa);i++)
    {
        if(stringa[i]=='A' || stringa[i]=='E' || stringa[i]=='I' || stringa[i]=='O' || stringa[i]=='U')
            contatore++;
    }

    return contatore;
}

/* funzione per contare
quanti caratteri uguali nella stringa */
int contaChar(char car, char stringa[])
{
    int cont=0; //dichiarazione variabile contatore

    /* conteggio carattere */
    for(int i=0;i<strlen(stringa);i++)
    {
        if(stringa[i]==car)
            cont++;
    }

    return cont; 
}

/* metodo per unire le stringhe di posizione pari e dispari. 
Se inserisce un numero pari viene*/