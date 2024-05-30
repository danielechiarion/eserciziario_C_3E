#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* funzione che stampa in output il contenuto di un vettore
in un'unica riga con tabulazioni */
void stampaVettori(int vet[], int size){
    /* controlla se la dimensione è maggiore di 0,
    altrimenti stampa delle barre */
    if(size>0){
      for(int i=0;i<size;i++)
        printf("%d\t", vet[i]);
    }
    else
        printf("//");
}

/* funzione che azzera un vettore */
void azzeraVettore(int vet[], int size){
    for(int i=0;i<size;i++)
    {
        vet[i]=0; //imposto la cifra a 0
    }
}

/* funzione che azzera tutte e 3
le torri inserite */
void azzeraTorri(int vet1[], int vet2[], int vet3[], int size){
    /* azzero i tre vettori */
    azzeraVettore(vet1, size);
    azzeraVettore(vet2, size);
    azzeraVettore(vet3, size);
}

/* funzione che serve a visualizzare tutte le torri
con i loro numeri */
void stampaTorri(int vet1[], int vet2[], int vet3[], int index1, int index2, int index3){
    printf("\n"); //mando un a capo
    /* visualizza risultati torre 1 */
    printf("Torre 1: ");
    stampaVettori(vet1, index1);
    printf("\n");
    /* visualizza risultati torre 2 */
    printf("Torre 2: ");
    stampaVettori(vet2, index2);
    printf("\n");
    /* visualizza risultati torre 3 */
    printf("Torre 3: ");
    stampaVettori(vet3, index3);
    printf("\n");

    sleep(1);
}

/* funzione che inserisci il vettore popolando
di numeri consecutivi */
void popolaVettore(int vet[], int size){
    /* per ogni valore inserito si
    ha i+1 */
    for(int i=0;i<size;i++)
        vet[i]=size-i;
}

/* funzione che sposta il valore del vettore
in un altro, con conseguente cambiamento degli indici */
void spostaElemento(int src[], int dest[], int *indexSrc, int *indexDest){
    dest[*indexDest+1]=src[(*indexSrc)]; //sposto il valore
    src[(*indexSrc)]=0; //azzero il valore sorgente

    /* aggiorno gli indici */
    (*indexDest)++;
    (*indexSrc)--;
}

/* funzione che usa l'algoritmo delle torri di hanoi per spostare numeri
dal primo vettore all'ultimo */
void torriHanoi(int vet1[], int vet2[], int vet3[], int size){
    /* dichiaro gli indici dei vettori
    e altre variabili*/
    int index1=size-1, index2=-1,index3=-1; //index1 è uguale a size perchè all'inizio contiene tutti gli elementi
    int cont=0;
    int scelta;

    /* il ciclo va avanti fino a quando
    tutti gli elemnti si trovano nell'ultimo vettore */
    while(index3!=size-1){
        /* se il contatore è un multiplo di 3,
        devo spostare il contenuto tra i due vettori
        agli estremi */
        if(cont%3==0){
            /* lo spostamento può avvenire in due direzioni,
            se l'indice 3 è uguale a 0 o l'ultimo valore di vet1 è minore di vet3,
            allora sposto da vet1 a vet3 */
            if(index3<0 || vet1[index1]<vet3[index3])
                spostaElemento(vet1, vet3, &index1, &index3);
            else
                spostaElemento(vet3, vet1, &index3, &index1);
        }
        else if(cont%3-1==0){ //se il contatore viene dopo l'ultimo spostamento devo iniziare gli spostamenti interni
            /* nel primo caso ho un valore nel primo vettore che è minore
            nell'ultimo del secondo vettore.
            Quello che faccio è quindi spostarlo verso il centro */
            if(index2<0 ||(index1>=0 && vet1[index1]<vet2[index2])){
                spostaElemento(vet1, vet2, &index1, &index2);
                scelta=1;
            }
            /* altrimenti il movimento verrà fatto verso l'esterno */
            else{
                spostaElemento(vet2, vet1, &index2, &index1); //in questo caso sposto sempre verso sinistra
                scelta=2; //assegno la scelta

                /* controllo solo se il nuovo ultimo numero del vettore 2
                è maggiore dell'ultimo numero del vettore 3.
                Altrimenti cambio la scelta */
                if(vet2[index2]>vet3[index3])
                    scelta=1;
            }
        }
        else{ //l'ultima parte riguarda il completamento di quanto iniziato nella seconda condizione
            /* le scelte vengono quindi utilizzate per dare continuità
            a quanto in precedenza, assicurandosi che l'operazione sia giusta */
            switch(scelta){
                case 1:
                    spostaElemento(vet3, vet2, &index3, &index2); //sposto l'elemento dall'ultimo vettore al centrale
                    break;
                case 2:
                    spostaElemento(vet2, vet3, &index2, &index3); //sposta elemento dal vettore centrale all'ultimo
                    break;
            }
        }

        stampaTorri(vet1, vet2, vet3, index1+1, index2+1, index3+1); //visualizzo il contenuto delle torri ad ogni passaggio
        cont++; //incremento sempre il contatore
    }
}

void main(){
    /* dichirazione variabili */
    int quantiNumeri;

    /* richiesta inserimento dati input */
    do{
        printf("Quanti numeri vuoi spostare? ");
        scanf("%d", &quantiNumeri);
    }while(quantiNumeri<=0); //ripeto fin quando non ottengo un numero positivo

    /* dichiaro i 3 vettori */
    int vet1[quantiNumeri];
    int vet2[quantiNumeri];
    int vet3[quantiNumeri];

    /* azzero tutti i vettori e popolo il primo */
    azzeraTorri(vet1, vet2, vet3, quantiNumeri);
    popolaVettore(vet1, quantiNumeri);

    /* utilizzo infine l'algoritmo delle torri di hanoi */
    stampaTorri(vet1, vet2, vet3, quantiNumeri, 0, 0); //prima di tutto visualizzo il contenuto delle torri
    torriHanoi(vet1, vet2, vet3, quantiNumeri);
}
