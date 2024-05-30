#include <stdio.h>
#include <string.h>

void main(){
    /* dichiarare un puntatore di interi e assegnarli
    l'indirizzo di una variabile intera. 
    Successivamente stampare il valore tramite puntatore */
    int num=10;
    int *puntatore = &num;
    printf("Valore variabile: %d", *puntatore);

    /* dichiarare un puntatore a caratteri 
    e assegnarli il valore di una stringa. 
    Successivamente stampa il valore della stringa tramite puntatore */
    char *punt;
    char stringa[] = {"ciao mondo"};
    punt = stringa; //la stringa indica già l'indirizzo
    printf("\n\nStringa: %s\n", punt);

    /* dichiarare un puntatore di interi e assegnarli
    l'indirizzo di una variabile intera. 
    Successivamente incrementa il puntatore e stampa il risultato */
    int numero=5;
    int *pointer = &numero; //senza asterisco si agisce sull'indirizzo
    (*pointer)++; 
    printf("\n\nIl numero incrementato e' : %d", numero);

    /* dato un vettore di float già segnato, 
    eseguire la somma dei valori */
    float array[]={2.5,3.7,1.2,5.9,4.3};
    float *punta = array; //assegno al primo indirizzo
    float somma=0;
    for(int i=0;i<5;i++)
        somma+= *(punta+i);
    printf("\n\nLa somma dei valori vale %f", somma);
}