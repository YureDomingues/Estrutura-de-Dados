#include "grafo.h"

struct grafo
{
    void *obj;
    int destino;
    struct grafo *prox;
};

void inicializar(struct grafo **g, int tamanho){
    *g = (struct grafo*)malloc(sizeof(struct grafo)*tamanho);
    for(int i = 0; i<tamanho; i++){
        g[i] = NULL;
    }
}

void inserirLista(struct grafo **g, int d, void *obj){
    struct grafo *no = (struct grafo*) malloc(sizeof(struct grafo));
    no->obj = obj;
    no->destino = d;
    no->prox = *g;
    (*g) = no;
}

void inserirAresta(struct grafo **g, int origem, int destino, void *obj){
    inserirLista(&(g[origem]), destino, obj);
}


void removerLista(struct grafo **g, int destino, void *obj){

    if(*g==NULL) return;

    struct grafo **anterior = NULL;
    struct grafo **p = g;

    while( *p != NULL && (*p)->destino != destino && (*p)->obj != obj){
        anterior = p;
        (*p) = (*p)->prox;
    }

    if((*p) == NULL) return;

    if(anterior == NULL){
        *g = (*p)->prox;
    }else{
        (*anterior)->prox = (*p)->prox;
    }

    free(p);

}
void removerAresta(struct grafo **g, int origem, int destino, void * obj){
    removerLista(&(g[origem]), destino, obj);
}


void imprimirGrafo(struct grafo **g, int n){
    printf("Grafo: ");
    for(int i=1; i<=n; i++){
        printf("\n\t%d", i);
        imprimirLista(g[i]);
    }
}

void imprimirLista(struct grafo *g){
    if(g!=NULL){
        printf("-(%d)", g->destino);
        imprimirLista(g->prox);
    }
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