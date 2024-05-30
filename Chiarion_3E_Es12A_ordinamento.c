//Author: Daniele Chiarion
//Date: 08-05-2024

/* dato un vettore di N numeri, 
ordinarli in ordine crescente utilizzando i seguenti metodi:
 - bubble sort
 - selection sort */

#include <stdio.h>
#include <stdbool.h>

/* funzione che utilizza lo scambio */
void swap(int *a, int *b){
    int temp; //dichiarazione variabile temporanea

    /* scambio variabili */
    temp=*a;
    *a=*b;
    *b=temp;
}

/* funzione che, preso un vettore di interi, 
lo ordini attraverso il bubble sort */
void bubbleSort(int vet[], int size){
    bool operazioni; //variabile di controllo operazioni
    int giro=0; //conta quante operazioni vengono fatte

    do
    {
        /* scorro tutti i valori */
        for(int i=0;i<size-giro-1;i++){
            operazioni=false; //reinizializzo ogni volta la variabile
            if(vet[i]>vet[i+1]){
                swap(&vet[i], &vet[i+1]); //scambio variabili
                operazioni=true; //cambio stato variabile booleana
            }
        }  
        giro++; //incremento la variabile
    } while (operazioni); //ripeto fino a quando vengono compiute operazioni
}

/* funzione che ordina un vettore utilizzando
il selection sort */
void selectionSort(int vet[], int size){
    /* scorro tutti i valori */
    for(int i=0;i<size-1;i++){
        /* confronto ogni valore con tutti gli altri*/
        for(int k=i+1;k<size;k++){
            if(vet[k]<vet[i])
                swap(&vet[i], &vet[k]); //scambio valori
        }
    }
}

/* funzione che copia il contenuto
da un array ad un altro */
void arrayCopy(int src[], int dest[], int sizeDest){
    /* copiatura di ogni
    singolo valore */
    for(int i=0;i<sizeDest;i++)
        dest[i]=src[i];
}

/* funzione che
stampa a schermo il vettore */
void printVet(int vet[], int size){
    /* scorro tutti i valori
    e li stampo*/
    printf("\n");
    for(int i=0;i<size;i++)
        printf("%d\t", vet[i]);
    printf("\n");    
}

void main(){
    /* dichiarazione variabili */
    int dimensione;

    /* input dimensione */
    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", &dimensione);

    /* dichiaro un vettore per l'inserimento 
    e due per gli ordinamenti che devo applicare */
    int vet[dimensione];
    int vetBubble[dimensione];
    int vetSelection[dimensione];

    /* input tutti i dati */
    printf("Inserisci i numeri: ");
    for(int i=0;i<dimensione; i++)
        scanf("%d", &vet[i]);

    /* copio i valori nei due array */
    arrayCopy(vet, vetBubble, dimensione);
    arrayCopy(vet, vetSelection, dimensione);

    /* ordinamento degli array */
    bubbleSort(vetBubble, dimensione);
    selectionSort(vetSelection, dimensione);

    /* output risultati */
    printf("\n\nVettore ordinato con bubble sort");
    printVet(vetBubble, dimensione);
    printf("\n\nVettore ordinato con selection sort");
    printVet(vetSelection, dimensione);
}