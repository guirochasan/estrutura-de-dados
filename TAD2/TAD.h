#ifndef TAD_H
#define TAD_H

typedef struct ponto Ponto;
typedef unsigned int nat;
ponto* aloca_ponto(float x, float y, float z);
void desaloca_ponto(ponto* p);
void print_ponto(ponto* p);
nat distancia(ponto* p1, ponto* p2);






#endif