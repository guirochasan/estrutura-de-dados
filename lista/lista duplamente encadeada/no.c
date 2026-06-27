#include <stdio.h>
#include <stdlib.h>
#include "no.h"

struct no
{
    int info;
    struct no* prox;
    struct no* ant;
};
struct listad
{
    No* head;
    No* tail;
};
No* cria_no(int info){
    No* novo = (No*)malloc(sizeof(No));
    if (!novo){
        return NULL;
    }
    novo->info = info;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo; 
}
Listad* cria_lista(){
    Listad* nova = (Listad*)malloc(sizeof(Listad));
    if (!nova){
        return NULL;
    }
    nova->head = NULL;
    nova->tail = NULL;
    return nova; 
}
void inserirInicio(Listad* l, int valor) {
    
    No* novo = cria_no(valor);      
    novo->prox = l->head; 

    if (l->head != NULL) {
        l->head->ant = novo;
        No* aux = l->head;
        l->head =  
    } else {
        l->tail = novo;     
    }
    l->head = novo; 
}
void insere_meio(Listad* l, No *atual, int valor) {

    if (atual == NULL) return; 

    No* novo = cria_no(valor);
    novo->info = valor;
    
    novo->ant = atual;
    novo->prox = atual->prox;

    if (atual->prox != NULL) {
        atual->prox->ant = novo; 
    } 
    else {
        l->head = novo;           
    }
    atual->prox = novo;          
}