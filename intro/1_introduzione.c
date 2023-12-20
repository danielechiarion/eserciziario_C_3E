// Author: Daniele Chiarion
// Date: 25-10-2023

// Programma che visualizza un messaggio di saluto

// ctrl+SHIFT+i per identazione automatica
// gcc e nome del programma per cercare il programmma
// ./ nome del programma senza estensione per eseguire il programma

// inclusione libreria (altri programmi in C per compiti specifici)
#include <stdio.h>
void main() // non c'è bisogno di un ritorno di valore
{
    int num;
    
    printf("Inserisci un numero:\n");
    scanf("%d", &num);
    printf("Il numero inserito e': %d", num);
}