// Funções Atividade 2

#ifndef _FUNCOES2_H
#define _FUNCOES2_H

#include <stdio.h>
#include <stdlib.h>
#include "funcoes1.h"

int verifica_existencia_abb(arvore **arv, int elemento);
void imprimir_folhas_menores(arvore **arv, int elemento);
void limpar_memoria(arvore **arv);
int nivel_abb(arvore *arv, int elemento, int nivel);
void inserir_abb(arvore **arv, int elemento);
void remover_abb(arvore **arv, int elemento);

#endif