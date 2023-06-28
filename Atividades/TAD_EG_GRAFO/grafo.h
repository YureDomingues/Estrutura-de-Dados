#ifndef GRAFO
#define GRAFO
#include <stdio.h>
#include <stdlib.h>

typedef struct grafo *Grafo;

void inicializar(struct grafo **g,int tamanho);
void inserirAresta(struct grafo **g, int origem, int destino, void *obj);
void removerAresta(struct grafo **g, int origem, int destino, void *obj);
void imprimirGrafo(struct grafo **g, int n);
void caminhos(struct grafo **g, int b, int *vet, int pos);
#endif
