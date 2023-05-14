#ifndef _FUNCOESAVL_H
#define _FUNCOESAVL_H

#include <stdio.h>
#include <stdlib.h>
#include "funcoesAB.h"
#include "funcoesABB.h"

arvore* ler_arvore_avl(FILE *arq);
void ajustarFB(arvore *arv);
arvore *rotacao_esq(arvore *r);
arvore *rotacao_esq_simples(arvore *r);
arvore *rotacao_esq_dupla(arvore *r);
arvore *rotacao_dir (arvore *r);
arvore *rotacao_dir_dupla(arvore *r);
arvore *rotacao_dir_simples (arvore *r);
arvore *inserir_avl(arvore *r, int x, int *hMudou);
arvore *remover_avl(arvore *r, int x, int *hMudou);



#endif