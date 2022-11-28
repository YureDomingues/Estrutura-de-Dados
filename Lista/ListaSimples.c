#include <stdio.h>
#include <stdlib.h>

struct lista{
    int info;
    struct lista *prox_lista;
};

typedef struct lista Lista;

//Função de Criação

Lista* lst_criar(void){
    return NULL;
}

//Função de Inserção: a mais simples que é inserir na primeira posição da lista

Lista* lst_inserir(Lista *l, int dado){
    Lista *novo;
    novo = (Lista*) malloc(sizeof(Lista));

    novo->info = dado;
    novo->prox_lista = l;
    
    return novo;
}

//Função que percorre todos os elementos da lista, ex: impressão

void lst_imprime(Lista* l){
    Lista *p = l;
    printf("Lista: ");

    while(p != NULL){
        printf("|%d|", p->info);
        p = p->prox_lista;
    }

    printf("\n");
}

//Função que verifica se a lista está vazia

int lst_vazia(Lista *l){
    return (l == NULL);
}

//Função de busca

Lista* lst_buscar(Lista* l, int dado){
    Lista *p;
    for(p = l; p != NULL; p = p->prox_lista){
        if(p->info == dado) break;
    }
    return p;
}

//Função que retira um elemento da lista

Lista* lst_remover(Lista *l, int dado){

    if(l==NULL) return l;

    Lista *anterior = NULL;
    Lista *p = l;

    while( p != NULL && p->info != dado){
        anterior = p;
        p = p->prox_lista;
    }

    if(p == NULL) return l;

    if(anterior == NULL){
        l = p->prox_lista;
    }else{
        anterior->prox_lista = p->prox_lista;
    }

    free(p);

    return l;
}

//Função para liberar lista

void lst_liberar(Lista *l){
    Lista *p = l;

    while(p!=NULL){
        Lista *t = p->prox_lista;
        p = t;
    }

}

//Função de inserção de forma ordenada

Lista* lst_inserir_ultima(Lista *l, int dado){
    Lista *novo;
    Lista *anterior = NULL;
    Lista *p = l;

    while(p != NULL){
        anterior = p;
        p = p->prox_lista;
    }

    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = dado;

    if(anterior==NULL){
        novo->prox_lista = l;
        l = novo;
    }else{
        novo->prox_lista = anterior->prox_lista;
        anterior->prox_lista = novo;
    }

    return l;
}

//Imprimir posOrdem

void posOrdem(Lista* l){
    if(l==NULL) return;
    posOrdem(l->prox_lista);
    printf("|%d|", l->info);
}

//Imprimir preOrdem

void preOrdem(Lista *l){
    if(l==NULL) return;
    printf("|%d|", l->info);
    preOrdem(l->prox_lista); 
}




int main(){
    Lista *a;

    a = lst_criar();

    a = lst_inserir(a, 1);
    a = lst_inserir(a, 10);
    a = lst_inserir(a, 29);
    a = lst_inserir(a, 13);
    a = lst_inserir(a, 17);
    a = lst_inserir(a, 2);

    printf("posOrdem:\n");
    posOrdem(a);
    printf("\npreOrdem:\n");
    preOrdem(a);
    

    

    return 0;
}

