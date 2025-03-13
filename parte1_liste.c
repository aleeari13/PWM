#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//implementazione delle struct
typedef struct nodo {   //struct nodo
    int dato;
    struct nodo *next;
} nodo;

typedef struct {    //struct LinkedLista
    nodo *head;
    int dimensione;
} LinkedLista;


//dichiarazione delle funzioni
LinkedLista* initLinkedLista();
int inserisciInTesta(int, LinkedLista*);
int inserisciInCoda(int, LinkedLista*);
int rimuoviInTesta(LinkedLista*);
int rimuoviInCoda(LinkedLista*);
void cancella(LinkedLista*);
void stampa(LinkedLista*);



int main(int argc, char *argv[]){     
    int a = 10; 
    int b = 3;   //main
    int testa; 
    int var1; 
    int var2; 
    int flag = 0;

    LinkedLista *lista = initLinkedLista();
    testa = inserisciInTesta(a,lista);
    var1 = inserisciInCoda(b,lista); 
    var2 = inserisciInCoda(5,lista);

    stampa(lista);

    flag = rimuoviInTesta(lista);

    //Rimozione nodo in testa
    if(flag == -1)
    {
        printf("Erorre nella lista.\n");
    } else 
    {
        printf("rimosso head\n");
    }

    //rimozione nodo in coda
    if(flag == -1)
    {
        printf("Erorre nella lista.\n");
    } else 
    {
        printf("rimosso head\n");
    }
    
    stampa(lista);

    //inserisci gli altri nodi in lista
    inserisciInTesta(20, lista);
    inserisciInCoda(15, lista);
    inserisciInCoda(25, lista);

    printf("Lista dopo nuovi inserimenti: \n");
    stampa(lista);

    cancella(lista);
    free(lista);
    printf("Lista cancellata correttamente. \n");
    
    return 0;
}


//implementazione delle funzioni

LinkedLista *initLinkedLista(){
    LinkedLista *lista = (LinkedLista *)malloc(sizeof(LinkedLista));
    lista -> head = NULL;
    lista -> dimensione = 0;
    return lista;
}

int inserisciInTesta(int valore,LinkedLista *lista){
    nodo *nodo1 = (nodo*)malloc(sizeof(nodo));
    if(nodo1 == NULL){
        printf("Errore, non è stato possibile allocare memoria.\n");
        return -1;
    }
    nodo1 -> dato = valore;
    nodo1 -> next = lista -> head;
    lista -> head = nodo1;
    lista -> dimensione++;
    return nodo1 -> dato;
}

int inserisciInCoda(int valore,LinkedLista *lista){
    int dimensione = 0;
    nodo *nodo1 = (nodo*)malloc(sizeof(nodo));
    if(nodo1 == NULL){
         printf("Errore, non è stato possibile allocare memoria.\n");
         return -1;
    }
    nodo1 -> dato = valore; 
   
    dimensione = lista -> dimensione;
    if(lista == NULL)
        return-1;
    else
    {
        if(lista -> head == NULL)
        {
            lista -> head = nodo1;
            printf("sono qui");
        } else
        {
            nodo *corrente = lista -> head;
            while((*corrente).next != NULL){
                corrente = corrente -> next;
            }
            corrente -> next = nodo1;
            lista -> dimensione++;
        }
        return nodo1 -> dato;
    }
}

int rimuoviInTesta(LinkedLista *lista){
    if(lista == NULL || lista -> head == NULL){
        return - 1;
    } else 
    {
        nodo *nodo1 = lista -> head;
        nodo1 = nodo1 -> next;

        free(lista -> head);
        lista -> head = nodo1;

        lista -> dimensione--;
        return 0;
    }
}

int rimuoviInCoda(LinkedLista *lista)
{
    if(lista == NULL || lista -> head == NULL)
    {
        return -1;
    } else
    {
        if(lista -> head -> next == NULL)
        {
            free(lista -> head);
            lista -> head = NULL;
            lista -> dimensione--;
            return 0;
        }
        nodo *attuale = lista -> head;
        while(attuale -> next -> next != NULL)
        {
            attuale = attuale -> next;
        }
        free(attuale -> next);
        attuale -> next = NULL;
        lista -> dimensione--;
        return 0;
    }
}

void cancella(LinkedLista *lista){
    int i;
    nodo *n1;
    nodo *n2;

    n1 = lista -> head;
    n2 = lista -> head;

    for(i = 0; i < (lista -> dimensione);i++){
        n1 = n2;
        n2 = n2 -> next;
        free(n1);
    }
}

void stampa(LinkedLista *lista){
    if(lista == NULL || lista -> head == NULL)
    {
        printf("Errore, la lista non è esistente o inizializzata\n");
    } else
    {
        int i = 0, val;
        nodo *temp = lista -> head;

        while(temp != NULL)
        {
            i++;
            val = temp -> dato;
            temp = temp -> next;
            printf("valore numero %d è: %d\n", i, val);
        }  
    }
}