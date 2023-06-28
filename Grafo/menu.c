#include "menu.h"

void menu(lista **g, int *terminou, int *size)
{

    printf("\nEscolha uma das opções: \n\n");

        printf("1 - Inserir uma aresta no grafo\n");
        printf("2 - Remover uma aresta do grafo\n");
        printf("3 - Imprimir grafo\n");
        printf("4 - Imprimir os graus de entrada e saída no vértice\n");
        printf("5 - Verificar se um grafo é completo\n");
        printf("6 - Imprimir todos os caminhos da origem até o destino\n");
        printf("7 - Imprimir o caminho mais curto\n");
        printf("8 - Imprimir o caminho de menor custo\n");
        printf("9 - Sair\n\n");

    int escolha;
    scanf("%d", &escolha);
    printf("\n");

    switch (escolha)
    {
    case 1:
    {
        int o , d, c;
        scanf("%d",&o);
        scanf("%d",&d);
        scanf("%d",&c);
        inserirAresta(g,o,d,c);
        break;
    }

    case 2:
    {
        int o , d, c;
        scanf("%d",&o);
        scanf("%d",&d);
        scanf("%d",&c);
        removerAresta(g,o,d,c);
        break;
    }
    case 3:
    {
        imprimirGrafo(g, *size);
        break;
    }
    case 4:
    {
        break;
    }
    case 5:
    {
        break;
    }
    case 6:
    {
        break;
    }
    case 7:
    {
        break;
    }
    case 8:
    {
        break;
    }
    case 9:
    {
        *terminou = 1;
        printf("Saindo...\n\n");
        break;
    }
    default:
    {
        printf("Escolha inválida\n");
        break;
    }
    }
}