//Author: Daniele Chiarion
//Date: 24-04-2024

/* Dopo aver letto un vettore di N elementi utilizzando i puntatori 
calcolare la media del vettore e determinare il massimo ed il minimo. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* funzione per pulire lo schermo */
void ClrScr()
{
    #ifdef _WIN32      // Check if the OS is Windows
        system("cls"); // instruction for clearing cmd of Windows
    #else
        system("clear"); // instruction for clearing shell of Linux / MacOS
    #endif
}

/* funzione per calcolare la media */
float mediaCalc(int *vettore, int size){
    /* dichiarazione variabili */
    float somma=0;

    /* scorro tutti i valori
    e li sommo, poi divido */
    for(int i=0;i<size;i++)
        somma += *(vettore+i);

    return somma/size; //restituisco valore
}

/* funzione per calcolare il
massimo e il minimo */
void minMax(int *vettore, int size, int *min, int *max){
    /* assegno i valori iniziali 
    al massimo e al minimo*/
    *min = *vettore;
    *max = *vettore;

    /* scorro tutti i valori, 
    partendo già dalla seconda posizione*/
    for(int i=1;i<size;i++){
        if(*(vettore+i)>*max)
            *max = *(vettore+i);
        if(*(vettore+i)<*min)
            *min= *(vettore+i);
    }
}

/* funzione per l'input
del valore */
void inputCodice(int nMax, int input[]){
    printf("Inserisci valori vettore: ");
    for(int i=0;i<nMax; i++){
        scanf("%d", &input[i]);
    }
}

void main(){
    /* dichiarazione variabili */
    int max, min;
    float media;
    int dimensione;

    /* input dimensione */
    do
    {
        printf("Quanti numeri vuoi inserire? ");
        scanf("%d", &dimensione);
    } while (dimensione<=0);
    
    /* dichiarazione vettori e 
    input numeri */
    int vet[dimensione];
    inputCodice(dimensione, vet);

    /* trasferimento dati puntatore 
    e determinazione massimo, minimo 
    e media*/
    int *puntatore = vet;
    media = mediaCalc(puntatore, dimensione);
    minMax(puntatore, dimensione, &min, &max);

    /* output risultati */
    printf("\n\nLa media dei valori inseriti e' %.2f", media);
    printf("\nIl minimo e' %d", min);
    printf("\nIl massimo e' %d", max);
}