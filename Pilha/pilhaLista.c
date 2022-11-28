#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
}Lista;

typedef struct pilha{
    Lista *prim;
}Pilha;

Pilha* pilha_cria(void){
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}

int pilha_vazia(Pilha *p){
    return (p->prim == NULL);
}

void pilha_push(Pilha *p, int dado){
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = dado;
    novo->prox = p->prim;
    p->prim = novo;
}

int pilha_pop(Pilha *p){
    Lista *t;
    int x;
    if(pilha_vazia(p)){
        printf("Pilha vazia.\n");
        exit(EXIT_FAILURE);
    }
    t = p->prim;
    x = t->info;
    p->prim = t->prox;
    free(t);
    return x;
}

void pilha_libera(Pilha *p){
    Lista *q = p->prim;
    while(q!=NULL){
        Lista*t = q->prox;
        free(q);
        q = t;
    }
    free(p);
}

int main(void){
    

    return 0;
}