#include <stdio.h>
#include <stdlib.h>

#define N 10

struct pilha{
    int n;
    int vet[N];
};

typedef struct pilha Pilha;

Pilha* p_cria(void){
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->n = 0; 
    return p;
}

int p_vazia(Pilha *p){
    return (p->n == 0);
}

int p_cheia(Pilha *p){
    return (p->n == N);
}

void p_push(Pilha *p, int dado){

    if(p_cheia(p)){
        printf("A fila está cheia");
        exit(EXIT_FAILURE);
    }

    p->n++;
    p->vet[p->n-1] = dado;
}

int p_pop(Pilha *p){

    if(p_vazia(p)){
        printf("Não há elementos na pilha\n");
        exit(EXIT_FAILURE);
    }
    p->n--;
    return p->vet[p->n];
}

void p_libera(Pilha *p){
    free(p);
}

int main(void){
    

    return 0;
}
