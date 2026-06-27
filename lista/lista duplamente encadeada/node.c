#include "no.h"
#include <stdio.h>
#include <stdlib.h>

// Definição das estruturas
struct no {
    int info;
    struct no* ant;
    struct no* prox;
};

struct listad {
    No* head;
    No* tail;
    int tamanho;  // Opcional, mas útil
};

// ===== FUNÇÕES BÁSICAS =====

No* cria_no(int info) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        fprintf(stderr, "Erro: falha na alocação de memória\n");
        exit(EXIT_FAILURE);
    }
    novo->info = info;
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

Listad* cria_lista(void) {
    Listad* l = (Listad*)malloc(sizeof(Listad));
    if (l == NULL) {
        fprintf(stderr, "Erro: falha na alocação de memória\n");
        exit(EXIT_FAILURE);
    }
    l->head = NULL;
    l->tail = NULL;
    l->tamanho = 0;
    return l;
}

void libera_lista(Listad* l) {
    if (l == NULL) return;
    
    No* atual = l->head;
    while (atual != NULL) {
        No* prox = atual->prox;
        free(atual);
        atual = prox;
    }
    free(l);
}

// ===== INSERÇÕES =====

void insere_inicio(Listad* l, int valor) {
    if (l == NULL) return;
    
    No* novo = cria_no(valor);
    novo->prox = l->head;
    
    if (l->head != NULL) {
        l->head->ant = novo;
    } else {
        l->tail = novo;  // Lista estava vazia
    }
    l->head = novo;
    l->tamanho++;
}

void insere_fim(Listad* l, int valor) {
    if (l == NULL) return;
    
    No* novo = cria_no(valor);
    novo->ant = l->tail;
    
    if (l->tail != NULL) {
        l->tail->prox = novo;
    } else {
        l->head = novo;  // Lista estava vazia
    }
    l->tail = novo;
    l->tamanho++;
}

void insere_depois(Listad* l, No* atual, int valor) {
    if (l == NULL || atual == NULL) return;
    
    No* novo = cria_no(valor);
    novo->ant = atual;
    novo->prox = atual->prox;
    
    if (atual->prox != NULL) {
        atual->prox->ant = novo;
    } else {
        l->tail = novo;  // Inserindo no final
    }
    atual->prox = novo;
    l->tamanho++;
}

void insere_antes(Listad* l, No* atual, int valor) {
    if (l == NULL || atual == NULL) return;
    
    No* novo = cria_no(valor);
    novo->prox = atual;
    novo->ant = atual->ant;
    
    if (atual->ant != NULL) {
        atual->ant->prox = novo;
    } else {
        l->head = novo;  // Inserindo no início
    }
    atual->ant = novo;
    l->tamanho++;
}

// ===== REMOÇÕES =====

void remove_inicio(Listad* l) {
    if (l == NULL || l->head == NULL) return;
    
    No* removido = l->head;
    l->head = l->head->prox;
    
    if (l->head != NULL) {
        l->head->ant = NULL;
    } else {
        l->tail = NULL;  // Lista ficou vazia
    }
    
    free(removido);
    l->tamanho--;
}

void remove_fim(Listad* l) {
    if (l == NULL || l->tail == NULL) return;
    
    No* removido = l->tail;
    l->tail = l->tail->ant;
    
    if (l->tail != NULL) {
        l->tail->prox = NULL;
    } else {
        l->head = NULL;  // Lista ficou vazia
    }
    
    free(removido);
    l->tamanho--;
}

void remove_no(Listad* l, No* no) {
    if (l == NULL || no == NULL) return;
    
    // Ajusta ponteiros dos vizinhos
    if (no->ant != NULL) {
        no->ant->prox = no->prox;
    } else {
        l->head = no->prox;  // Removendo o primeiro
    }
    
    if (no->prox != NULL) {
        no->prox->ant = no->ant;
    } else {
        l->tail = no->ant;  // Removendo o último
    }
    
    free(no);
    l->tamanho--;
}

void remove_valor(Listad* l, int valor) {
    if (l == NULL) return;
    
    No* atual = busca_valor(l, valor);
    if (atual != NULL) {
        remove_no(l, atual);
    }
}

// ===== BUSCA =====

No* busca_valor(Listad* l, int valor) {
    if (l == NULL) return NULL;
    
    No* atual = l->head;
    while (atual != NULL) {
        if (atual->info == valor) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

No* busca_posicao(Listad* l, int pos) {
    if (l == NULL || pos < 0 || pos >= l->tamanho) return NULL;
    
    // Otimização: decide se começa do head ou do tail
    No* atual;
    if (pos < l->tamanho / 2) {
        // Começa do início
        atual = l->head;
        for (int i = 0; i < pos; i++) {
            atual = atual->prox;
        }
    } else {
        // Começa do fim
        atual = l->tail;
        for (int i = l->tamanho - 1; i > pos; i--) {
            atual = atual->ant;
        }
    }
    return atual;
}

// ===== IMPRESSÃO =====

void imprime_lista(Listad* l) {
    if (l == NULL) {
        printf("Lista inválida\n");
        return;
    }
    
    if (l->head == NULL) {
        printf("Lista vazia\n");
        return;
    }
    
    No* atual = l->head;
    printf("Lista (head -> tail): ");
    while (atual != NULL) {
        printf("%d ", atual->info);
        atual = atual->prox;
    }
    printf("\n");
}

void imprime_reverso(Listad* l) {
    if (l == NULL) {
        printf("Lista inválida\n");
        return;
    }
    
    if (l->tail == NULL) {
        printf("Lista vazia\n");
        return;
    }
    
    No* atual = l->tail;
    printf("Lista (tail -> head): ");
    while (atual != NULL) {
        printf("%d ", atual->info);
        atual = atual->ant;
    }
    printf("\n");
}

// ===== UTILITÁRIOS =====

int tamanho_lista(Listad* l) {
    return (l == NULL) ? 0 : l->tamanho;
}

int lista_vazia(Listad* l) {
    return (l == NULL || l->head == NULL);
}

// ===== FUNÇÃO EXTRA: INSERÇÃO ORDENADA =====

void insere_ordenado(Listad* l, int valor) {
    if (l == NULL) return;
    
    if (l->head == NULL || valor <= l->head->info) {
        insere_inicio(l, valor);
        return;
    }
    
    if (valor >= l->tail->info) {
        insere_fim(l, valor);
        return;
    }
    
    No* atual = l->head;
    while (atual != NULL && atual->info < valor) {
        atual = atual->prox;
    }
    
    // Insere antes de 'atual' (pois atual->info >= valor)
    insere_antes(l, atual, valor);
}