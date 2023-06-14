#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

/*Atividade:
    Implementar um programa para "Hashing em arquivo"
        - Tratamento de colusão: próxima posição livre.

    O menu deve conter as seguintes opções:
        1 - inserir novo aluno (matrícula, nome, curso)
        2 - Imprimir as informações de um determinado aluno (busca pela matrícula)
        3 - imprimir toda a tabela de dispersão (tabela hash)
        4 - Sair
*/

typedef struct aluno{
    int matricula;
    char nome[100];
    char curso[50];
    int disponivel; //disponivel = 1 (ainda é um espaço não usado)
}Aluno;

int hash(int matricula){
    return matricula%N;
}

int encontrarPosicao(char *nomeArq, int matricula){
    int pos = hash(matricula);

    FILE *arq = fopen(nomeArq, "rb");

    fseek(arq, pos*sizeof(Aluno), SEEK_SET);

    Aluno A;

    fread(&A, sizeof(Aluno), 1, arq);

    while(!A.disponivel){
        pos = (pos+1)%N;
        fseek(arq, pos*sizeof(Aluno), SEEK_SET);
        fread(&A, sizeof(Aluno), 1, arq);
    }

    fclose(arq);

    return pos;
    
}

void inserir(char *nomeArq, int matricula, char *nomeAluno, char *nomeCurso){
    int pos = encontrarPosicao(nomeArq, matricula);

    FILE *arq = fopen(nomeArq, "r+b");

    fseek(arq, pos*sizeof(Aluno), SEEK_SET);

    Aluno A;
    A.matricula = matricula;
    strcpy(A.nome, nomeAluno);
    strcpy(A.curso, nomeCurso);
    A.disponivel = 0;

    fwrite(&A, sizeof(Aluno), 1, arq);

    fclose(arq);
}

void inicializar(char *nomeArq){
    FILE *arq = fopen(nomeArq, "wb");
    Aluno A;
    A.disponivel = 1;
    A.matricula = 0;
    A.nome[0] = '\0';
    A.curso[0] = '\0';

    for(int i=0; i<N; i++){
        fwrite(&A, sizeof(Aluno), 1, arq);
    }

    fclose(arq);
}

void imprimirInformacoes(Aluno A, int imprimirDisponibilidade){
    if(!imprimirDisponibilidade){
        if(A.disponivel){
        printf("Não foi encontradas informações sobre o aluno.\n");
        }else{
            printf("Nome: %s\n", A.nome);
            printf("Matrícula: %d\n", A.matricula);
            printf("Curso: %s\n", A.curso);
        }
    }else{
        printf("Nome: %s\n", A.nome);
        printf("Matrícula: %d\n", A.matricula);
        printf("Curso: %s\n", A.curso);
        printf("Disponibilidade: %d\n", A.disponivel);
    }

    printf("\n");
    
}

void imprimirBusca(char *nomeArq, int matricula){
    int pos = hash(matricula);

    FILE *arq = fopen(nomeArq, "rb");

    fseek(arq, pos*sizeof(Aluno), SEEK_SET);

    Aluno A;

    fread(&A, sizeof(Aluno), 1, arq);

    if(A.matricula != matricula){
        while(A.matricula!=matricula && !A.disponivel){
            pos = (pos+1)%N;
            
            fseek(arq, pos*sizeof(Aluno), SEEK_SET);
            fread(&A, sizeof(Aluno), 1, arq);
        }
    }

    imprimirInformacoes(A, 0);
    
    fclose(arq);
}

void imprimirTabela(char *nomeArq, int tamanho){
    FILE *arq = fopen(nomeArq, "rb");

    Aluno A;
    
    for(int i=0; i<tamanho; i++){
        fread(&A, sizeof(Aluno), 1, arq);
        imprimirInformacoes(A, 1);
    }

    fclose(arq);
}


int main(){

    /*montar menu*/

    char nomeArquivo[100];

    strcpy(nomeArquivo, "arquivo");

    inicializar(nomeArquivo);
    inserir(nomeArquivo, 123456, "José", "Ciência da Computação");
    inserir(nomeArquivo, 123457, "Daniel", "Ciência da Computação");
    // imprimirBusca(nomeArquivo, 123458);
    imprimirTabela(nomeArquivo, N);

    return 0;
}