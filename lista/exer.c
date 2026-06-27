#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int dado;
    struct list* prox;
} Node;

Node* cria_no () {
    Node* no = (Node*)malloc(sizeof(Node));
    no->dado = 0;
    no->prox = NULL;
    return no;
}

void delno (Node* a) {
    if (a->prox != NULL) {
        printf(" Nó intermediário, risco de perda de referência\n");
    }
    else {
        free(a);
    }
}

// ALTERADO: O primeiro parâmetro mudou de 'tail' para 'head' para refletir o comportamento real da função
void insere_fim (Node* head, int data) { 
    Node* nova_calda = cria_no();
    nova_calda->dado = data;
    
    // ALTERADO: Criado um ponteiro auxiliar para navegar na lista sem perder o início dela
    Node* aux = head; 
    
    // ALTERADO: Loop adicionado para caminhar até o ÚLTIMO nó (onde o prox é NULL)
    while (aux->prox != NULL) { 
        aux = aux->prox; // Avança o auxiliar para o próximo nó
    } // FIM DA ALTERAÇÃO
    
    // ALTERADO: Conecta o novo nó no final do último nó encontrado, e garante que o fim aponta para NULL
    aux->prox = nova_calda; 
    nova_calda->prox = NULL; 
}

void insert_anywhere( Node* place, int value){

    if (place == NULL) return;

    Node* novo = cria_no();
    novo->dado = value;
    novo->prox = place->prox;
    Node* aux = place->prox;
    place->prox = novo;
}

void printlist (Node* head) {
    printf(" Sua lista:  ");
    Node* aux;
    for (aux = head->prox; aux != NULL; aux = aux->prox) {
        printf(" %d", aux->dado);
    }
    printf("\n"); // ALTERADO: Adicionado apenas para quebrar a linha no console e melhorar o visual
}

int main() {
    Node* head = cria_no();
    int decis;
    
    // ALTERADO: Loop 'while' adicionado para manter o programa rodando até o usuário decidir sair (opção 0)
    while (1) { 
        printf("\n Digite: 1 para imprimir | 2 para adicionar | 0 para sair: ");
        scanf(" %d", &decis);
        
        if (decis == 0) { // ALTERADO: Nova condição para encerrar o programa graciosamente
            break; 
        }
        
        if (decis == 1) {
            printlist(head);
            // ALTERADO: O 'return 0;' foi removido daqui para o programa não fechar após imprimir
        }
        
        if (decis == 2) {
            int insert;
            printf(" Digite o número que quer adicionar: ");
            scanf(" %d", &insert);
            insere_fim(head, insert);
            // ALTERADO: O 'return 0;' foi removido daqui para permitir múltiplas inserções seguidas
        }
    } // FIM DO LOOP WHILE

    // ALTERADO: Boa prática de TAD - Liberar a memória do nó sentinela antes do programa fechar de vez
    free(head); 
    return 0;
}