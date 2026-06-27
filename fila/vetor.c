#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"


struct fila
{
    int vetor;
    int inicio;
    int n_elem;
    int fim;
};

Fila* fila_cria(){ 

    Fila* a = (Fila*)malloc(sizeof(Fila));
    a-> vetor = (int*)malloc(4*sizeof(Fila));
    a-> fim = 4;
    a-> inicio = 0;
    a-> n_elem = 0;

    return a;
}
void libera(Fila* f){
    free(f->vetor);
    free(f);
}
void fila_insere(Fila* n, int i){

    if (n->fim == n->n_elem){

        n->fim *= 2;
        n-> vetor = (float *) realloc(n->vetor, n-> fim*sizeof(float ));

    }
    

}