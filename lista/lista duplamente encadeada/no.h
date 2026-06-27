// lista_dupla.h
#ifndef LISTA_DUPLA_H
#define LISTA_DUPLA_H

// Estruturas opacas (encapsulamento)
typedef struct no No;
typedef struct listad Listad;

// ===== FUNÇÕES BÁSICAS =====
No* cria_no(int info);
Listad* cria_lista(void);
void libera_lista(Listad* l);  // ADICIONADO: importante!

// ===== INSERÇÕES =====
void insere_inicio(Listad* l, int valor);
void insere_fim(Listad* l, int valor);
void insere_depois(Listad* l, No* atual, int valor);  // Renomeado de insere_meio
void insere_antes(Listad* l, No* atual, int valor);   // ADICIONADO: simétrico

// ===== REMOÇÕES =====
void remove_inicio(Listad* l);
void remove_fim(Listad* l);
void remove_no(Listad* l, No* no);  // Remove por nó (mais eficiente)
void remove_valor(Listad* l, int valor);  // Remove primeira ocorrência

// ===== BUSCA =====
No* busca_valor(Listad* l, int valor);  // ADICIONADO
No* busca_posicao(Listad* l, int pos);   // ADICIONADO

// ===== IMPRESSÃO =====
void imprime_lista(Listad* l);  // Agora recebe Listad*
void imprime_reverso(Listad* l);  // ADICIONADO: aproveita lista dupla

// ===== UTILITÁRIOS =====
int tamanho_lista(Listad* l);  // ADICIONADO
int lista_vazia(Listad* l);     // ADICIONADO

#endif