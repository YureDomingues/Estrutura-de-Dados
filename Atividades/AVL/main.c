#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int main(void){
    FILE *arq = NULL;
    arvore *arv = NULL;
    int terminou = 0;

    while(!terminou){
        menu(&arv, &arq, &terminou);
    }

    fclose(arq);
    return 0;
}
