#ifndef STACK_H
#define STACK_H

typedef struct stack Stack;
Stack* cria_pilha();
void free_pilha(Stack* pilha);
bool pilha_vazia(Stack* p);
float pop_pilha(Stack* s);
void push_pilha(Stack* S, float data);




#endif