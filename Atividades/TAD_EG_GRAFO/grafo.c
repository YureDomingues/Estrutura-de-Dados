#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

struct grafo
{
    int destino;
    void *obj;
    struct grafo *prox;
};

void inicializar(struct grafo **g, int n){
    for(int i =0; i<=n; i++){
        g[i] = NULL;
    }
}

void inserirLista(struct grafo **l, int d, void *obj, int size){
    struct grafo *no = (struct grafo*) malloc(sizeof(struct grafo));
    no->obj = malloc(size);
    memcpy(no->obj,obj,size);
    no->destino = d;
    no->prox = *l;
    (*l) = no;
}

void inserirAresta(struct grafo **g, int origem, int destino, void *obj, int size){
    inserirLista(&(g[origem]), destino, obj, size);
}

void removerLista(struct grafo **l, int destino, void *obj){

    if(*l==NULL) return;

    struct grafo **anterior = NULL;
    struct grafo **p = l;

    while( *p != NULL && (*p)->destino != destino){
        anterior = p;
        (*p) = (*p)->prox;
    }

    if((*p) == NULL) return;

    if(anterior == NULL){
        *l = (*p)->prox;
    }else{
        (*anterior)->prox = (*p)->prox;
    }

    free(p);

}

void removerAresta(struct grafo **g, int origem, int destino, void *obj){
    removerLista(&(g[origem]), destino, obj);
}


void imprimirLista(struct grafo *l,void (*imprimir)(void*)){
    if(l!=NULL){
        printf("-(%d)", l->destino);
        imprimir(l->obj);
        imprimirLista(l->prox, imprimir);
    }
}
void imprimirGrafo(struct grafo **g, int n, void (*imprimir)(void*)){
    printf("Grafo: ");
    for(int i=1; i<=n; i++){
        printf("\n\t%d", i);
        imprimirLista(g[i],imprimir);
    }
    printf("\n");
}


int existe(int *vet, int valor, int n){
    for(int i=0; i<n; i++){
        if(vet[i] == valor)
            return 1;
    }
    return 0;
}

void caminhos(struct grafo **g, int b, int *vet, int pos){
    if(vet[pos-1] == b){
        printf("\n");
        for(int i=0;i<pos;i++){
            printf("%d", vet[i]);
        }
    }else{
        struct grafo *p = g[vet[pos-1]];
        while(p!=NULL){
            if(!existe(vet, p->destino, pos)){
                vet[pos] = p->destino;
                caminhos(g, b, vet, pos+1);
            }
            p = p->prox;
        }
    }
}