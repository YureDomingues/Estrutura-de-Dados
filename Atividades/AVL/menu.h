#ifndef _MENU_H
#define _MENU_H

#include <stdio.h>
#include <stdlib.h>
#include "funcoesAB.h"
#include "funcoesABB.h"
#include "funcoesAVL.h"

void menu(arvore **arv, FILE **arq, int *terminou);
void imprimir(arvore *arv);

#endif
