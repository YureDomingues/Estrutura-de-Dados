#include <stdio.h>
#include <stdlib.h>

struct listaC{
    int id;
    struct listaC *prox;
};

typedef struct listaC ListaC;

//Função Criação

ListaC* lc_criar(ListaC *l){
    return NULL;
}

//Função Inserção

ListaC* lc_inserir(ListaC *l, int dado){
    ListaC* novo;
    novo = (ListaC*) malloc(sizeof(ListaC));
    novo->id = dado;

    if(l == NULL){
        novo->prox = novo;
    }else{
        ListaC *p = l;
        while(p->prox != l){
            p = p->prox;
        }
        p->prox = novo;
        novo->prox = l;
    }
    
    return novo;
}

//Função de Impressão

void lc_imprimir(ListaC *l){
    printf("Lista: ");
    if(l == NULL){
        printf("(vazia)\n");
        return;    
    }else{
        ListaC *p = l;
        do{
            printf("|%d|", p->id);
            p = p->prox;
        }while(p!=l);
        printf("\n");
    }
}

//Criar função de remover

int main(){
    ListaC *L;
    L = lc_criar(L);
    L = lc_inserir(L, 1);
    L = lc_inserir(L, 10);
    L = lc_inserir(L, -2);
    L = lc_inserir(L, 3);
    L = lc_inserir(L, 10);
    lc_imprimir((L->prox)->prox);


    return 0;
}