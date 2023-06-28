#ifndef _FUNCOES_GRAFO
#define _FUNCOES_GRAFO

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int destino;
    int custo;
    struct lista *prox;
}lista;

void inicializar(lista **g, int n);
void inserirAresta(lista **g, int origem, int destino, int custo);
void inserirLista(lista **l, int d, int c);
void removerAresta(lista **g, int origem, int destino, int custo);
void removerLista(lista **l, int destino, int custo);
void imprimirGrafo(lista **g, int n);
void imprimirLista(lista *l);
void caminhos(lista **g, int b, int *vet, int pos);
int existe(int *vet, int valor, int n);




#endif