#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main(){

    int heap[N];

    int sair = 0;

    int opcao;
    while (! sair)
    {
        printf(
            "1 - inserir elemento x \n"
            "2 - remover elemento \n"
            "3 - imprimir \n"
            "4 - sair \n"
        );
        printf("> ");
        scanf("%d",&opcao);
        switch (opcao)
        {
        case 1:
            int x;
            printf("Numero: \n>");
            scanf("%d", &x);
            Inserir(heap,x);
            break;
        case 2:
            printf("%d",remover(heap));
            break;
        case 3:
            imprimir(heap);
            break;
        case 4:
            sair = 1;
        
        default:

            break;
        }

    }
    

    return 0;
}