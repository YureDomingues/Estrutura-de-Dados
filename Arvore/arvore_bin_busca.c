#include <stdio.h>
#include <stdlib.h>

struct arv{
    int info;
    struct arv *esq;
    struct arv* dir;
};

typedef struct arv Arv;

Arv* abb_cria_vazia(void){
    return NULL;
}

void simetrica(Arv *v){
    if(v != NULL){
        simetrica(v->esq);
        printf("%d ", v->info);
        simetrica(v->dir);
    }
}

Arv* abb_busca(Arv* v, int dado){
    if(v == NULL) return NULL;
    else if(dado > v->info) return abb_busca(v->dir, dado);
    else if(dado < v->info) return abb_busca(v->esq, dado);
    else return v;
}

Arv* abb_insere(Arv* v, int dado){
    if(v == NULL){
        v = (Arv*) malloc(sizeof(v));
        v->info = dado;
        v->esq = v->dir = NULL;
    }else if(dado < v->info){
         v->esq = abb_insere(v->esq, dado);
    }else{
        v->dir = abb_insere(v->dir, dado);
    }
    return v;
}

//Cria função de remoção de um elemento da árvore

int main(void){
    Arv* a = abb_cria_vazia();

    a = abb_insere(a, 6);
    a = abb_insere(a, 8);
    a = abb_insere(a, 3);
    a = abb_insere(a, 1);
    a = abb_insere(a, 2);
    a = abb_insere(a, 4);

    simetrica(a);

    int x; 
    scanf("%d", &x);
    Arv *b = abb_busca(a, x);
    printf("\nBuscar %d: %s", x, (b!=NULL) && b->info == x ? "Encontrou" : "Não encontrou");

    return 0;
}
