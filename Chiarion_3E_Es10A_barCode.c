//Author: Daniele Chiarion
//Date: 10-04-2024

/* I codici a barre dei prodotti sono composti da 13 cifre, di cui l'ultima e' una cifra di controllo che si determina a partire dalle prime 12 (il codice vero e proprio) applicando le seguenti regole:
1)moltiplicare per 3 tutte le cifre in posizione dispari;
2)moltiplicare per 1 tutte le cifre in posizione pari;
3)sommare tra loro tutti i 12 valori così ottenuti;
4)calcolare il resto della divisione per 10 della somma ottenuta;
Codificare in linguaggio C un programma che, a paqrtire da un vettore di 12 elementi corrispondenti alle cifre di un codice a barre restituisca la cifra di controllo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
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

/* funzione che calcola la potenza */
int potenza(int base, int esponente){
    int risultato=1; //dichiarazione variabile

    /* moltiplico quante volte richiesto */
    for(int i=0;i<esponente; i++)
        risultato*=base;

    return risultato; //ritorno valore
}

/* funzione che verifica
se un numero appartiene a quell'ordine di grandezza */
bool checkNumLength(int num){
    if(num>=potenza(10, num-1) && num<potenza(10, num))
        return true; //se il numero appartiene l'intervallo, restituisce true
    else 
        return false; //altrimenti restituisce false
}

/* funzione per convertire una stringa 
in un intero */
int convertStringtoInt(char vet[], int size){
    int risultato=0; //dichiarazione variabile
    
    for(int i=0;i<size;i++)
        risultato=vet[i]*potenza(10, size-1-i); //aggiungo ogni volta il valore rispettando la posizione

    return risultato; //ritorno il risultato
}

/* funzione per l'input 
del valore */
int inputCodice(int nMax){
    char input[nMax-1]; //dichiarazione variabile come stringa

    do
    {
        printf("\nInserisci un codice di 12 cifre: ");
        scanf("%s", input);
        /* possibile messaggio di errore */
        if(strlen(input)!=12){
            printf("\n\nIl valore non e' di 12 cifre");
            sleep(4);
            ClrScr();
        }
    } while (strlen(input)!=12); //controllo se il numero è di 12 cifre

    return convertStringtoInt(input, strlen(input));
}

/* funzione per suddividere un numero
in vettore, con una cifra per ciascuna posizione */
void dividiinVettore(int numero, int vet[], int size){
    for(int i=0;i<size-1;i++){
        vet[i]=numero/potenza(10, numero-i); //trovo la cifra e l'assegno alla posizione
        numero-=potenza(10, numero-i); //sottraggo al numero ciò che è già stato calcolato
    }
}

/* funzione per calcolare
l'ultimo numero del codice a barre */
void calcolaUltimoNumero(int vet[], int size){
    int ultimoNumero=0; //dichiarazione variabile

    /* con cifre pari sono intesi i valori nelle posizioni 1,3...
    con le cifre dispari sono intesi i valori nelle posizioni 0,2,4...*/
    for(int i=0;i<size-1;i++){ //metto size-1 perchè l'ultima posizione e' ancora da popolare
        if(i%2==0)
            ultimoNumero+=vet[i]*3; //se è dispari moltiplico il numero per 3
        else
            ultimoNumero+=vet[i]; //altrimenti lo mantengo così
    }

    vet[size-1]=ultimoNumero%10; //assegno all'ultima posizione il risultato trovato
}

/* funzione che 
stampa a schermo il vettore */
void printVet(int vet[], int size){
    /* scorro tutti i valori
    e li stampo*/
    printf("\n");
    for(int i=0;i<size;i++)
        printf("%d", vet[i]);
}

void main(){
    /* dichiarazione variabili e vettori */
    #define maxLength 13
    int numero;
    int vet[maxLength];

    /* input valori
    e suddivisione in un vettore */
    numero=inputCodice(maxLength);
    dividiinVettore(numero, vet, sizeof(vet)/sizeof(vet[0]));

    calcolaUltimoNumero(vet, sizeof(vet)/sizeof(vet[0])); //calcolo ultimo numero codice a barre

    /* output risultati */
    printf("\n\nIl codice a barre completo e': ");
    printVet(vet, sizeof(vet)/sizeof(vet[0]));
}