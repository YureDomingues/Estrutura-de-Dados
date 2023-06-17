#include <string.h>
#include "menu.h"

void menu(){

    char arquivo[100];
    int numAlunos;

    printf("Digite o nome do arquivo a ser manipulado: ");
    scanf("%s", arquivo);
    printf("Agora Digite o número de alunos na tabela: ");
    scanf("%d", &numAlunos);

    inicializar(arquivo, numAlunos);

    int terminou = 0;

    while(!terminou){
        printf("\n\n");
        printf("1 - Inserir novo aluno\n");
        printf("2 - Imprimir informações de um aluno\n");
        printf("3 - Imprimir tabela de dispersão\n");
        printf("4 - Sair\n\n");

        int escolha;
        scanf("%d", &escolha);
        printf("\n");

        switch (escolha)
        {
            int matricula;
            case 1:
                
                char nomeAluno[100];
                char curso[50];
                printf("Digite a matrícula do aluno: ");
                scanf("%d", &matricula);
                setbuf(stdin, NULL);
                printf("Digite o nome do aluno: ");
                scanf("%[^\n]", nomeAluno);
                setbuf(stdin, NULL);
                printf("Digite o nome do curso: ");
                scanf("%[^\n]", curso);
                setbuf(stdin, NULL);
                inserir(arquivo, matricula, nomeAluno, curso);
                break;
            
            case 2:
                printf("Digite a matrícula do aluno: ");
                scanf("%d", &matricula);
                setbuf(stdin, NULL);
                printf("\n");
                imprimirBusca(arquivo, matricula);
                break;

            case 3:
                imprimirTabela(arquivo);
                break;
            
            case 4:
                terminou = 1;
                printf("Saindo...\n");
                break;
            default:
                printf("Escolha uma opção válida.\n");
                break;
            }
    }
}
