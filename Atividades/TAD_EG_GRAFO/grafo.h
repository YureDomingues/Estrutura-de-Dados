#ifndef GRAFO
#define GRAFO
#include <stdio.h>
#include <stdlib.h>


typedef struct grafo *Grafo;

void inicializar(struct grafo **g, int n);
void inserirAresta(struct grafo **g, int origem, int destino, void *obj, int size);
void removerAresta(struct grafo **g, int origem, int destino, void *obj);
void imprimirGrafo(struct grafo **g, int n, void (*imprimir)(void*));
void caminhos(struct grafo **g, int b, int *vet, int pos);
int existe(int *vet, int valor, int n);



#endif
