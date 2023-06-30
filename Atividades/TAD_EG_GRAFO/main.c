#include "grafo.h"

#define n 10
int main(){

    Grafo g[n];

    inicializar(g, n);

    void *a = malloc(sizeof(int));
    a =(void *) 1;

    inserirAresta(g,3,2,a, sizeof(int));
    imprimirGrafo(g,10);

    return 0;
}