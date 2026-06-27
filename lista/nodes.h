#ifndef NODES_H
#define NODES_H

typedef struct nodes Node;

Node* cria_node(int data);
void libera_node(Node* node);

#endif // NODES_H
