#include <stdio.h>
#include <stdlib.h>

#define N 3

struct fila{
    int ini;
    int n_elem;
    int vet[50];
};

typedef struct fila Fila;

Fila* fila_criar(void){
    Fila* f;
    f = (Fila*)malloc(sizeof(Fila));
    f->ini = 0;
    f->n_elem = 0;
    return f;
}

int fila_vazia(Fila* f){
    return (f->n_elem == 0);
}

void fila_inserir(Fila* f, int dado){
    
    if(f->n_elem == N){
        printf("Capacidade de fila estourou\n");
        exit(EXIT_FAILURE);
    }

    int fim = (f->ini+f->n_elem)%N;
    f->vet[fim] = dado;
    f->n_elem++;
}

int fila_retirar(Fila* f){

    if(fila_vazia(f)){
        printf("A fila está vazia.\n");
        exit(EXIT_FAILURE);
    }

    int dado = f->vet[f->ini];
    f->ini = (f->ini + 1)%N;
    f->n_elem--;

    return dado;
}

int main(){

    Fila *F;
    F = fila_criar();
    fila_inserir(F, 4);
    fila_inserir(F, 2);
    fila_inserir(F, 3);
    printf("Remover elemento: %d\n", fila_retirar(F));
    fila_inserir(F, 1);
    printf("Remover elemento: %d\n", fila_retirar(F));
    printf("Remover elemento: %d\n", fila_retirar(F));
    printf("Remover elemento: %d\n", fila_retirar(F));
    return 0;
}
