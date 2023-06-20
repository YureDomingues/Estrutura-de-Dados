#include <stdio.h>
#include "fila.h"


int main(){

    Fila *fila;

    inicializar(&fila, 5);

    push(fila, 1);
    push(fila, 2);
    push(fila, 3);
    push(fila, 1);
    push(fila, 7);
    push(fila, 6);

    imprimirFila(fila);

    pop(fila);

    push(fila, 7);
    push(fila, 6);

    pop(fila);
    pop(fila);

    push(fila, 4);
    push(fila, 15);

    imprimirFila(fila);

    destruir(fila);

    return 0;
}