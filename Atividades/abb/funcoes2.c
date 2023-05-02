#include "funcoes2.h"

/*--------------------------Funções Atividade 2--------------------------*/

int verifica_existencia_abb(arvore **arv, int elemento)
{
    if (*arv == NULL)
    {
        return 0;
    }
    else
    {
        if (elemento == (*arv)->info)
        {
            return 1;
        }
        else if (elemento < (*arv)->info)
        {
            return verifica_existencia_abb(&(*arv)->esq, elemento);
        }
        else
        {
            return verifica_existencia_abb(&(*arv)->dir, elemento);
        }
    }
}

void imprimir_folhas_menores(arvore **arv, int elemento)
{
    if (*arv != NULL)
    {
        if (elemento <= (*arv)->info)
        {
            imprimir_folhas_menores(&(*arv)->esq, elemento);
        }
        else
        {
            if ((*arv)->esq == NULL && (*arv)->dir == NULL)
            {
                printf("[%d] ", (*arv)->info);
            }
            else
            {
                imprimir_folhas_menores(&(*arv)->esq, elemento);
                imprimir_folhas_menores(&(*arv)->dir, elemento);
            }
        }
    }
}

void limpar_memoria(arvore **arv)
{
    if (*arv != NULL)
    {
        limpar_memoria(&(*arv)->esq);
        limpar_memoria(&(*arv)->dir);
        free(*arv);
    }

    arv = NULL;
}

int nivel_abb(arvore *arv, int elemento, int nivel)
{
    if (arv == NULL)
        return -1;
    if (arv->info == elemento)
        return nivel;
    if (arv->info > elemento)
        return nivel_abb(arv->esq, elemento, nivel + 1);
    else
        return nivel_abb(arv->dir, elemento, nivel + 1);
}

void inserir_abb(arvore **arv, int elemento)
{
    if (*arv == NULL)
    {
        *arv = (arvore *)malloc(sizeof(arvore));
        (*arv)->info = elemento;
        (*arv)->esq = NULL;
        (*arv)->dir = NULL;
        return;
    }
    if ((*arv)->info > elemento)
        inserir_abb(&(*arv)->esq, elemento);
    else
        inserir_abb(&(*arv)->dir, elemento);
}

int remover_maior_abb(arvore **arv);
void remover_no_abb(arvore **arv)
{
    if (*arv == NULL)
        return;
    if ((*arv)->esq == NULL && (*arv)->dir == NULL)
    {
        free(*arv);
        *arv = NULL;
    }
    else if ((*arv)->esq == NULL && (*arv)->dir != NULL)
        *arv = (*arv)->dir;
    else if ((*arv)->esq != NULL && (*arv)->dir == NULL)
        *arv = (*arv)->esq;
    else
        (*arv)->info = remover_maior_abb(&(*arv)->esq);
}

void remover_abb(arvore **arv, int elemento)
{
    if (*arv == NULL)
        return;
    if ((*arv)->info == elemento)
        remover_no_abb(arv);
    else if ((*arv)->info > elemento)
        remover_abb(&(*arv)->esq, elemento);
    else
        remover_abb(&(*arv)->dir, elemento);
}
int remover_maior_abb(arvore **arv)
{
    if (*arv == NULL)
        return -1;
    if ((*arv)->dir != NULL)
        return remover_maior_abb(&(*arv)->dir);
    else
    {
        int info = (*arv)->info;
        remover_no_abb(arv);
        return info;
    }
}