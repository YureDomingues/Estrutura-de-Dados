#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "funcoes_grafo.h"
int main(){
    int terminou = 0;
    lista **grafo;

    int size;
    printf("tamanho de vertices do grafo:");
    scanf("%d",&size);

    grafo = (lista **) malloc(sizeof(lista)*(size+1));
    inicializar(grafo,size);

    while(!terminou){
        menu(grafo, &terminou, &size);
    }
    

    return 0;
}