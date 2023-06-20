#include <stdio.h>
#include "fila.h"


void menu(){

    Fila *fila;

    int n;

    printf("Digite o tamanho da lista: ");
    scanf("%d", &n);

    inicializar(&fila, n);

    int terminou = 0;

    while(!terminou){
        printf("\n\n");
        printf("1 - Inserir um elemento na fila.\n");
        printf("2 - Remover um elemento da fila.\n");
        printf("3 - Imprimir a fila.\n");
        printf("4 - Sair\n\n");

        int escolha;
        scanf("%d", &escolha);
        printf("\n");

        switch (escolha)
        {
            case 1:
                int elemento;
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &elemento);
                if(push(fila, elemento) == -1){
                    printf("\nA fila está cheia! O elemento não foi inserido.");
                }
                break;
            
            case 2:
                pop(fila);
                break;

            case 3:
                imprimirFila(fila);
                break;
            
            case 4:
                terminou = 1;
                destruir(fila);
                printf("Saindo...\n");
                break;
            default:
                printf("Escolha uma opção válida.\n");
                break;
            }
    }
}


int main(){

    menu();

    return 0;
}