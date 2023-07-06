#include "grafo.h"
#include <stdio.h>
#define n 10

void imprimir(void *v){
    int *a = (int*)v;
    printf("%d", (*a));
}
int main(){

    Grafo g[n];

    inicializar(g, n);
    int a = 2;
    inserirAresta(g,3,2,&a, sizeof(int));
    imprimirGrafo(g,10,imprimir);

    return 0;
}