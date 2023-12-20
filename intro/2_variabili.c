// Author: Daniele Chiarion
// Date: 08-11-2023

#include <stdio.h>
void main()
{
    int num;          // variabile intera
    float numrea;     // variabile reale
    double numgrande; // numero di grandi dimensioni
    char lettera;     // caratteri
    char parola[10];  // dichiarazione stringa (da 0 a 9, 10° è fine stringa)
    int lettera2;

    lettera='a';
    lettera2 = 'a';

    printf("Il codice della lettera a e': %c", lettera); 
    printf("\nIl codice della lettera a e': %d", lettera2); // compare il rispettivo codice ASCII del carattere
}