#include "menu.h"

void menu(arvore **arv, FILE **arq, int *terminou)
{
    char arquivo[100];

    printf("\nEscolha uma das opções: \n\n");
    if (*arv == NULL)
    {
        printf("1 - Ler uma árvore de um arquivo fornecido pelo usuário\n");
        printf("9 - Sair\n\n");
    }
    else
    {
        printf("1 - Ler uma árvore de um arquivo fornecido pelo usuário\n");
        printf("2 - Imprimir a árvore\n");
        printf("3 - Verificar se o elemento x existe na árvore\n");
        printf("4 - Contar o número de elementos da árvore\n");
        printf("5 - Imprimir folhas menores que um valor x\n");
        printf("6 - Verificar se a árvore está balanceada\n");
        printf("7 - Verificar se a árvore está cheia\n");
        printf("8 - Imprimir o nível de um nó x\n");
        printf("9 - Sair\n\n");
    }
    int escolha;
    scanf("%d", &escolha);
    printf("\n");

    switch (escolha)
    {
    case 1:
    {
        printf("Digite o nome do arquivo a ser aberto (exemplo.txt): ");
        do
        {
            scanf("%s", arquivo);
            *arq = fopen(arquivo, "rt");

            if (*arq == NULL)
            {
                printf("Houve um erro ao tentar abrir arquivo.\n\nDigite novamente o nome: ");
            }
            else
            {
                printf("\n");
            }
        } while (*arq == NULL);

        *arv = ler_arvore(*arq);

        printf("%s ao ler a árvore\n", arv != NULL ? "Sucesso" : "Falha");
        break;
    }

    case 2:
    {
        imprimir(*arv);
        break;
    }

    case 3:
    {
        int x;
        printf("Digite o elemento: ");
        scanf("%d", &x);
        printf("\n%s esse elemento na árvore.\n", verifica_existencia_abb(&(*arv), x) ? "Existe" : "Não existe");
        break;
    }

    case 4:
    {
        int quantidade = contar_elementos(*arv);
        printf("O número de elementos é: nível%d\n", quantidade);
        break;
    }

    case 5:
        int elemento_menor;
        printf("Informe o elemento: ");
        scanf("%d", &elemento_menor);
        imprimir_folhas_menores(arv, elemento_menor);
        printf("\n");
        break;
    case 6:
        printf("%s balanceada.\n", esta_balanceada(*arv) ? "Está" : "Não está");
        break;
    case 7:
        printf("%s cheia.", esta_cheia(*arv) ? "Está" : "Não está");
        break;
    case 8:
        int e;
        printf("Informe o elemento: ");
        scanf("%d", &e);
        verifica_existencia(*arv, e) ? nivel_elemento(*arv, e, 0) : printf("Elemento não encontrado");
        printf("\n\n");
        break;
    case 9:
    {
        *terminou = 1;
        limpar_memoria(arv);
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

void imprimir(arvore *arv)
{
    printf("Escolha uma das opções de impressão: \n");
    printf("1 - Pré-ordem\n");
    printf("2 - Pós-ordem\n");
    printf("3 - Em ordem\n");
    printf("4 - Em largura\n\n");

    int escolha;

    scanf("%d", &escolha);
    printf("\n");

    switch (escolha)
    {
    case 1:
        printf("Pré-ordem:\n");
        imprimir_pre_ordem(arv);
        printf("\n");
        break;
    case 2:
        printf("Pós-ordem:\n");
        imprimir_pos_ordem(arv);
        printf("\n");
        break;
    case 3:
        printf("Em ordem:\n");
        imprimir_em_ordem(arv);
        printf("\n");
        break;
    case 4:
        printf("Em largura:\n");
        imprimir_em_largura(arv);
        printf("\n");
        break;
    default:
        printf("Opção inválida\n");
        break;
    }
}
