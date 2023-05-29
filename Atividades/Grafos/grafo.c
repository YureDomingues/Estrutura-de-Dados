#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int destino;
    int custo;
    struct lista *prox;
}lista;

void inicializar(lista **g, int n){
    for(int i =0; i<n; i++){
        g[i] = NULL;
    }
}

void inserirAresta(lista **g, int origem, int destino, int custo){
    g[origem] = inserirLista(g[origem], destino, custo);
}

void insetirLista(lista **l, int d, int c){
    lista *no = (lista*) malloc(sizeof(lista));
    no->destino = d;
    no->custo = c;
    no->prox = l;
    (*l) = no;
}

void imprimirGrafo(lista **g, int n){
    printf("Grafo: ");
    for(int i=1; i<=n; i++){
        printf("\n\t%d", i);
        imprimirLista(g[i]);
    }
}

void imprimirLista(lista *l){
    if(l!=NULL){
        printf("-(%d, %d)", l->destino, l->custo);
        imprimirLista(l->prox);
    }
}

int main(){
    lista **g;
    int n;

    g = (lista*)malloc((n+1)*sizeof(lista*));
    //n é o número de nós de um grafo, inicializado em 1 pois a posição 0 não é utilizada



    return 0;
}