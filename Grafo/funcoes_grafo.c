#include <stdio.h>
#include <stdlib.h>
#include "funcoes_grafo.h"

void inicializar(lista **g, int n){
    for(int i =0; i<=n; i++){
        g[i] = NULL;
    }
}

void inserirAresta(lista **g, int origem, int destino, int custo){
    inserirLista(&(g[origem]), destino, custo);
}

void inserirLista(lista **l, int d, int c){
    lista *no = (lista*) malloc(sizeof(lista));
    no->destino = d;
    no->custo = c;
    no->prox = *l;
    (*l) = no;
}

void removerAresta(lista **g, int origem, int destino, int custo){
    removerLista(&(g[origem]), destino, custo);
}

void removerLista(lista **l, int destino, int custo){

    if(*l==NULL) return;

    lista **anterior = NULL;
    lista **p = l;

    while( *p != NULL && (*p)->destino != destino && (*p)->custo != custo){
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

int existe(int *vet, int valor, int n){
    for(int i=0; i<n; i++){
        if(vet[i] == valor)
            return 1;
    }
    return 0;
}

void caminhos(lista **g, int b, int *vet, int pos){
    if(vet[pos-1] == b){
        printf("\n");
        for(int i=0;i<pos;i++){
            printf("%d", vet[i]);
        }
    }else{
        lista *p = g[vet[pos-1]];
        while(p!=NULL){
            if(!existe(vet, p->destino, pos)){
                vet[pos] = p->destino;
                caminhos(g, b, vet, pos+1);
            }
            p = p->prox;
        }
    }
}