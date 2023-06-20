#ifndef __FILA_H
#define __FILA_H

typedef struct fila Fila;

void inicializar(Fila **f, unsigned int tamanho);
void destruir(Fila *f);

/*Insere um elemento na fila. Retorna -1 se ocorreu algum problema na inserção e 1 se deu certo.*/
int push(Fila *f, int valor); 

/*Remove um elemento da fila. Imprime o valor do elemento removido.*/
void pop(Fila *f);

/*Imprime toda a fila.*/
void imprimirFila(Fila *f);


#endif