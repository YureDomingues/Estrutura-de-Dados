#include "grafo.h"

int main(){

    Grafo g;
    inicializar(&g, 10);
    void *a = malloc(sizeof(int));
    int *b;
    *b = 1;
    a = b;
    inserirAresta(&g,1,2,a);

    inserirAresta(&g,1,2,a);
    imprimirGrafo(&g,10);

    return 0;
}