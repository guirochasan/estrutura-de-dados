#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"

struct nodes
{
    int info;
    struct nodes* prox;
};

Node* cria_node(int info){

    Node* novo = (Node*)malloc(sizeof(struct nodes));
    if (!novo){
        return NULL;
    }
    novo->info = info;
    novo->prox = NULL;
    return novo; 
}

int insere_inicio(Node** phead, int info){

    Node* novo = cria_node(info);
    if(!novo){
        return 0;
    }
    if(*phead == NULL){
        *phead = novo;
        return 1;
    }
    novo->prox = *phead;
    *phead = novo;
    return 1;
}