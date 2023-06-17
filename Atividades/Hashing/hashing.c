#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashing.h"

int N;

struct aluno{
    int matricula;
    char nome[100];
    char curso[50];
    int disponivel; //disponivel = 1 (ainda é um espaço não usado)
};

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

void inicializar(char *nomeArq, int numeroAlunos){
    N = numeroAlunos;

    FILE *arq = fopen(nomeArq, "wb");

    if(arq == NULL){
        "Houve um problema ao abrir/criar este arquivo.\n";
        exit(EXIT_FAILURE);
    }

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

    while(A.matricula!=matricula && !A.disponivel){
        pos = (pos+1)%N;
        
        fseek(arq, pos*sizeof(Aluno), SEEK_SET);
        fread(&A, sizeof(Aluno), 1, arq);
    }

    if(A.matricula != matricula){
        printf("Não foi encontrado registro para essa matrícula.\n");
    }else{
        imprimirInformacoes(A, 0);
    }
        
    fclose(arq);
}

void imprimirTabela(char *nomeArq){
    FILE *arq = fopen(nomeArq, "rb");

    Aluno A;
    
    for(int i=0; i<N; i++){
        fread(&A, sizeof(Aluno), 1, arq);
        imprimirInformacoes(A, 1);
    }

    fclose(arq);
}



