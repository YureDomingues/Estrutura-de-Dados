#ifndef _FUNCOES_H
#define _FUNCOES_H

#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
    int info;
    struct arvore *esq;
    struct arvore *dir;
}arvore;

arvore *ler_arvore(FILE *arq);
void imprimir_pre_ordem(arvore *arv);
void imprimir_pos_ordem(arvore *arv);
void imprimir_em_ordem(arvore *arv);
void imprimir_em_largura(arvore *arv); 
void imprimir_nivel(arvore* arv, int nivelDesejado, int nivelInicial);
void imprimir_no_folha(arvore *arv);
int verifica_existencia(arvore *arv, int x);
int contar_niveis(arvore *arv);
int contar_elementos(arvore *arv); 
int esta_balanceada(arvore *arv); 
int esta_cheia(arvore *arv);
void nivel_elemento(arvore *arv, int elemento, int nivelAtual);

#endif
