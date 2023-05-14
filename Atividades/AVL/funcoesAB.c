#include "funcoesAB.h"

/*--------------------------Funções Atividade 1--------------------------*/

void imprimir_pre_ordem(arvore *arv)
{
    if (arv != NULL)
    {
        printf("[%d]", arv->info);
        imprimir_pre_ordem(arv->esq);
        imprimir_pre_ordem(arv->dir);
    }
}

void imprimir_pos_ordem(arvore *arv)
{
    if (arv != NULL)
    {
        imprimir_pos_ordem(arv->esq);
        imprimir_pos_ordem(arv->dir);
        printf("[%d]", arv->info);
    }
}

void imprimir_em_ordem(arvore *arv)
{
    if (arv != NULL)
    {
        imprimir_em_ordem(arv->esq);
        printf("[%d]", arv->info);
        imprimir_em_ordem(arv->dir);
    }
}

void imprimir_em_largura(arvore *arv){
    int totalNiveis = contar_niveis(arv)+1;

    for(int i =0; i<=totalNiveis; i++){
        imprimir_nivel(arv, i, 0);
        printf("\n");
    }
}

void nivel_elemento(arvore *arv, int elemento, int nivelAtual){
    if(arv == NULL){
        return;
    }
    if(arv->info == elemento){
        printf("O nível do elemento %d é : %d", elemento, nivelAtual);
        return;
    }
    nivel_elemento(arv->esq, elemento, nivelAtual+1);
    nivel_elemento(arv->dir, elemento, nivelAtual+1);
}

/*-------------------------------------------------------------------------------------*/

void imprimir_nivel(arvore *arv, int nivelDesejado, int nivelInicial)
{
    if (arv == NULL)
        return;
    if (nivelDesejado == nivelInicial)
        printf("[%d]", arv->info);
    imprimir_nivel(arv->esq, nivelDesejado, nivelInicial + 1);
    imprimir_nivel(arv->dir, nivelDesejado, nivelInicial + 1);
}

void imprimir_no_folha(arvore *arv)
{
    if (arv != NULL)
    {
        if (arv->esq == NULL && arv->dir == NULL)
            printf("[%d]", arv->info);
        imprimir_no_folha(arv->esq);
        imprimir_no_folha(arv->dir);
    }
}

int esta_balanceada(arvore *arv)
{
    if (arv == NULL)
        return 0;
    int esq = esta_balanceada(arv->esq);
    int dir = esta_balanceada(arv->dir);
    if (esq == -1 || dir == -1)
        return -1;
    if (-2 >= esq - dir || esq - dir >= 2)
        return -1;
    if (esq > dir)
        return esq + 1;
    else
        return dir + 1;
}

int contar_niveis(arvore *arv)
{
    if (arv == NULL)
        return 0;
    int esq = contar_niveis(arv->esq);
    int dir = contar_niveis(arv->dir);
    if (esq > dir)
        return esq + 1;
    else
        return dir + 1;
}

int potencia(int num1, int num2)
{
    int result = 1;
    for (int i = 0; i < num2; i++)
    {
        result *= num1;
    }
    return result;
}

int esta_cheia(arvore *arv)
{
    return potencia(2, contar_niveis(arv)) - 1 == contar_elementos(arv);
}

/*-------------------------------------------------------------------------------------*/

arvore *ler_arvore(FILE *arq)
{
    char c;
    int num;

    fscanf(arq, "%c", &c);
    fscanf(arq, "%d", &num);

    if (num == -1)
    {
        fscanf(arq, "%c", &c);
        return NULL;
    }
    else
    {
        arvore *a = (arvore *)malloc(sizeof(arvore));
        a->info = num;
        a->esq = ler_arvore(arq);
        a->dir = ler_arvore(arq);
        fscanf(arq, "%c", &c);
        return a;
    }
}

int verifica_existencia(arvore *arv, int x)
{
    if (arv == NULL)
        return 0;
    else if (arv->info == x)
        return 1;
    else
    {
        int ret = verifica_existencia(arv->esq, x);
        if (ret == 1)
            return 1;
        return verifica_existencia(arv->dir, x);
    }
}

int contar_elementos(arvore *arv)
{
    if (arv == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + contar_elementos(arv->esq) + contar_elementos(arv->dir);
    }
}
