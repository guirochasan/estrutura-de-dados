#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

struct stack
{
    int n_elements;
    int size;
    float* vector;

};

Stack* cria_pilha(){

    Stack* p = (Stack*)malloc(sizeof(Stack));
    p->n_elements = 1;
    p->vector = (float*)malloc(p->size*sizeof(float));
    p->n_elements = 0;
    return p;
}

void free_pilha(Stack* a){

    free(a->vector);
    free(a);
}
Stack* push_pilha(Stack* p, float e){

    if (p->n_elements == p->size){

        printf(" Pilha cheia \n");
        p->size *= 2;
        p->vector = (float*)realloc(p->vector, p->size*sizeof(float));

    }
    p->vector[p->n_elements++] = e;
}

float pop_pilha(Stack* p){

    p->n_elements -= 1;
    float v = p->vector[p->n_elements];
    return v;
}

bool pilha_vazia(Stack* b){return (b->n_elements == 0);}
