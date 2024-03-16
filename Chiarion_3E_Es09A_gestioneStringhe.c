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

/* dichiarazione vettori globali */
bool alfabeto[26]={false}; //26 come le lettere dell'alfabeto, inizializzato a false
bool alfabeto2[26]={false};

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

void maiusc(char stringa[])
{
    /* ogni carattere viene
    convertito in maiuscolo */
    for(int i=0;i<strlen(stringa);i++)
        stringa[i]=toupper(stringa[i]);
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

/* funzione per unire le stringhe di posizione pari e dispari.
Se inserisce un numero pari viene creata la stringa con i caratteri di dimensione dispari.
Se inserisce un numero dispari la stringa con i caratteri di posizione dispari*/
void creaStringa(char stringa[], char stringaPari[], char stringaDispari[])
{
    /* dichiarazione variabili */
    int indexPari=0, indexDispari=0;
    int lunghezza = strlen(stringa);

    /* iterazione del ciclo  */
    for(int i=0;i<lunghezza;i++)
    {
        if(i%2==0)
        {
            stringaDispari[indexDispari]=stringa[i];
            indexDispari++;
        }
        else
        {
            stringaPari[indexPari]=stringa[i];
            indexPari++;
        }
    }

    stringaPari[indexPari]='\0';
    stringaDispari[indexDispari]='\0';
}

/* funzione che stampa il confronto tra stringhe */
void printConfrontoStringhe(char stringa1[], char stringa2[])
{
    if(strlen(stringa1)>strlen(stringa2))
        printf("\nLa stringa di lunghezza maggiore e' la prima.");
    else if(strlen(stringa2)>strlen(stringa1))
            printf("\nLa stringa di lunghezza maggiore e' la seconda.");
        else
            printf("\nLe due stringhe hanno la stessa lunghezza");
}

/* funzione per convertire da carattere ad intero ascii */
int asciiNum(char car)
{
    #define start 65

    return (int)car-start;
}

/* funzione per convertire da intero a carattere */
char asciiLet(int num)
{
    #define start 65

    return (char)(num+start);
}

/* funzione che controlla
quando esistono doppie consecutive,
cambiando un vettore di booleani */
void controlloDoppie(char stringa[])
{
    for(int i=0;i<strlen(stringa)-1;i++)
    {
        //se un carattere è uguale al suo consecutivo
        if(stringa[i]==stringa[i+1])
            alfabeto[asciiNum(stringa[i])]=true; //cambio valore del carattere nella posizione se presente
    }
}

/* funzione per controllare
se tra due stringhe
abbiamo lettere in comune */
void controlloLetUguali(char stringa1[], char stringa2[])
{
    for(int i=0;i<strlen(stringa1);i++){
        for(int k=0;k<strlen(stringa2); k++)
        {
            //se ho due caratteri uguali nelle stringhe
            if(stringa1[i]==stringa2[k])
                alfabeto2[asciiNum(stringa1[i])]=true; //cambio il valore a true
        }
    }
}

/* funzione per stampare in output
il vettore booleano dell'alfabeto */
void printLettere(bool vet[])
{
    printf("\n");
    for(int i=0;i<26;i++)
    {
        /* se il valore è true,
        viene stampato il carattere */
        if(vet[i])
            printf("%c\t", asciiLet(i));
    }
}

void main()
{
    /* dichiarazione variabili */
    bool soloLettere;
    int contVocali1, contConsonanti1;
    int contVocali2, contConsonanti2;
    char carVerifica;
    /* dichiarazione vettore */
    char stringa[100];
    char stringa2[100];
    char stringaPosPari[100];
    char stringaPosDispari[100];

    /* richiesta inserimento dati input */
    /* 1° stinga */
    printf("\n\n");
    do
    {
        printf("Inserisci la stringa in input (solo caratteri alfabetici): ");
        scanf("%s", stringa);
        maiusc(stringa); //converto la stringa in maiuscolo per evitare problemi
        soloLettere=checkSoloLettere(stringa);
        /* possibile messaggio di errore */
        if(!soloLettere)
            printf("\nHai inserito dei caratteri non alfabetici. Riprova.\n");
    } while (!soloLettere);

    /* conteggio vocali e consonanti */
    contVocali1 = contaVocali(stringa);
    contConsonanti1=strlen(stringa)-contVocali1;

    /* output primi risultati */
    printf("\n\nNella stringa sono presenti %d vocali", contVocali1);
    printf("\nNella stringa sono presenti %d consonanti", contConsonanti1);

    printf("\n\n");
    /* inserimento carattere di verifica */
    do
    {
        printf("\n\nInserisci il carattere alfabetico di verifica: ");
        scanf("%c", &carVerifica);
        scanf("%c", &carVerifica);
        carVerifica=toupper(carVerifica);
    } while (carVerifica<'A' || carVerifica>'Z');

    /* output di quanti caratteri uguali
    presenti nella stringa*/
    printf("\nIl carattere %c e' presente %d volte", carVerifica, contaChar(carVerifica, stringa));

    /* output stringa caratteri posizioni pari e dispari */
    creaStringa(stringa, stringaPosPari, stringaPosDispari);
    printf("\n\nLa stringa di caratteri nella posizione pari e' %s", stringaPosPari);
    printf("\nLa stringa di caratteri nella posizione dispari e' %s", stringaPosDispari);
    /* output doppie */
    printf("\nLe lettere doppie presenti sono: ");
    controlloDoppie(stringa);
    printLettere(alfabeto);

    /* richiesta inserimento seconda stringa */
    printf("\n");
    do
    {
        printf("Inserisci la stringa in input (solo caratteri alfabetici): ");
        scanf("%s", stringa2);
        maiusc(stringa2); //converto la stringa in maiuscolo per evitare problemi
        soloLettere=checkSoloLettere(stringa2);
        /* possibile messaggio di errore */
        if(!soloLettere)
            printf("\nHai inserito dei caratteri non alfabetici. Riprova.");
    } while (!soloLettere);


    /* output confronto stringhe */
    printf("\n\n\nCONFRONTO TRA STRINGHE: ");
    printConfrontoStringhe(stringa, stringa2); //quali delle due stringhe ha maggiore lunghezza

    /* conteggio vocali e consonanti */
    contVocali2 = contaVocali(stringa2);
    contConsonanti2=strlen(stringa2)-contVocali2;

    /* output conteggio vocali e consonanti */
    if(contVocali1>contVocali2)
        printf("\n\nHa piu' vocali la 1^ stringa");
    else if(contVocali2>contVocali1)
            printf("\n\nHa piu' vocali la 2^ stringa");
        else
            printf("\n\nEntrambe le stringhe hanno lo stesso numero di vocali");
    if(contConsonanti1>contConsonanti2)
        printf("\n\nHa piu' consonanti la 1^ stringa");
    else if(contConsonanti2>contConsonanti1)
            printf("\n\nHa piu' consonanti la 2^ stringa");
        else
            printf("\n\nEntrambe le stringhe hanno lo stesso numero di consonanti");

    /* controllo lettere uguali */
    printf("\n\nIn entrambe le stringhe sono presenti le seguenti lettere: ");
    controlloLetUguali(stringa, stringa2);
    printLettere(alfabeto2);
}
