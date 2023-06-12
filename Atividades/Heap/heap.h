#ifndef __HEAP_
#define __HEAP_

#include <stdio.h>
#define N 10

int indiceFilhoEsq(int x);
int indiceFilhoDir(int x);
int indicePai(int x);
void Inserir(int *heap, int x);
void ajustarSubindo(int *heap, int pos);
int remover(int *heap);
void ajustarDescendo(int *heap, int pos);
void imprimir(int *heap);
#endif