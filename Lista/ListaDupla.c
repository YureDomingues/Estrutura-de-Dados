#include <stdio.h>
#include <stdlib.h>

struct lista2{
    int info;
    struct lista2 *ant;
    struct lista2 *prox;
};

typedef struct lista2 Lista2;

//Função de Criação

Lista2* lst2_criar(void){
    return NULL;
}

//Função de Inserção

Lista2* lst2_inserir(Lista2 *l, int dado){
    Lista2* novo;
    novo = (Lista2*) malloc(sizeof(Lista2));
    novo->info = dado;
    novo->prox = l;

    if(l==NULL){
        novo->ant = NULL;
    }else{
        l->ant = novo;
    }

    return novo;
}

//Função imprimir

void lst2_imprimir(Lista2* l){
    Lista2 *p = l;
    printf("Lista: ");
    while(p!=NULL){
        printf("|%d|", p->info);
        p = p->prox;
    }
    printf("\n");
}

//Função imprimir inverso

void lst2_imprimir_inv(Lista2* l){
    Lista2* p=l;
    
    while(p->prox!=NULL) p = p->prox;
    printf("Lista: ");
    while(p!=NULL){
        printf("|%d|", p->info);
        p = p->ant;
    }
    printf("\n");
}

//Função de busca

Lista2* lst2_buscar(Lista2* l, int dado){
    Lista2* p;
    
    for(p=l; p!=NULL; p = p->prox){
        if(p->info == dado) return p;
    }

    return NULL;
}

//Função de remoção

Lista2* lst2_remover(Lista2* l, int dado){
    Lista2 *p = lst2_buscar(l, dado);

    if(p == NULL) return l;
    
    if(p->ant == NULL){
        l = p->prox;
        l->ant = NULL;
    }else if(p->prox == NULL){
        (p->ant)->prox = NULL;
    }else{
        (p->prox)->ant = p->ant;
        (p->ant)->prox = p->prox;
    }

    return l;

}



int main(){

    Lista2 *L, *B;

    L = lst2_criar();
    L = lst2_inserir(L, 3);
    L = lst2_inserir(L, 2);
    L = lst2_inserir(L, 7);
    L = lst2_inserir(L, 4);
    L = lst2_inserir(L, -1);
    L = lst2_inserir(L, -3);
    L = lst2_inserir(L, 10);

    lst2_imprimir(L);

    L = lst2_remover(L, 10);
    lst2_imprimir(L);
    L = lst2_remover(L, 3);
    lst2_imprimir(L);
    L = lst2_remover(L, 7);
    lst2_imprimir(L);
    
    


    return 0;
}