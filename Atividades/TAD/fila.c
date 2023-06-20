#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int N;

struct fila{
    int *vet;
    int qtdElementos;
    int posInicial;
};

void inicializar(Fila **f, unsigned int tamanho){
    N = tamanho;
    *f = (Fila*) malloc(sizeof(Fila));
    
    (*f)->vet = (int*) malloc(tamanho*sizeof(int));
    (*f)->qtdElementos = 0;
    (*f)->posInicial = 0;
}

void destruir(Fila *f){
    free(f);
}

int filaEstaCheia(Fila *f){
    return f->qtdElementos == N;
}

int filaEstaVazia(Fila *f){
    return f->qtdElementos == 0;
}

int posInsercao(Fila *f){
    return (f->posInicial+f->qtdElementos)%N;
}

int novaPosInicial(Fila *f){
    return (f->posInicial+1)%N;
}

int push(Fila *f, int valor){
    if(filaEstaCheia(f)){
        return -1;
    }
    
    int pos = posInsercao(f);
    f->vet[pos] = valor;
    f->qtdElementos++;

    return 1;
}

int posRemocao(Fila *f){
    return f->posInicial;
}

void pop(Fila *f){
    if(filaEstaVazia(f)){
        printf("A fila está vazia!");
    }else{
        int pos = posRemocao(f);
        printf("[%d]\n", f->vet[pos]);
        f->qtdElementos--;
        f->posInicial = novaPosInicial(f);
    } 
}

void imprimirFila(Fila *f){
    if(filaEstaVazia(f)){
        printf("A fila está vazia!");
    }else{
        for(int i=0, pos = f->posInicial; i < f->qtdElementos; i++){
            printf("[%d]", f->vet[pos]);
            pos = (pos+1)%N;
        }
        printf("\n");
    }
}