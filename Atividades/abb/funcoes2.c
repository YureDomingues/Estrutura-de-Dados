#include "funcoes2.h"

/*--------------------------Funções Atividade 2--------------------------*/

int verifica_existencia_abb(arvore **arv, int elemento){
    if(*arv == NULL){
        return 0;
    }
    else{ 
        if(elemento == (*arv)->info){
            return 1;
        }
        else if(elemento < (*arv)->info){
            return verifica_existencia_abb(&(*arv)->esq, elemento);
        }else{
            return verifica_existencia_abb(&(*arv)->dir, elemento);
        }

    }
}

void imprimir_folhas_menores(arvore **arv, int elemento){
    if(*arv != NULL){
        if((*arv)->info >= elemento){
            imprimir_folhas_menores(&(*arv)->esq, elemento);
            imprimir_folhas_menores(&(*arv)->dir, elemento);
        }else{
            if((*arv)->esq == NULL && (*arv)->dir == NULL){
                printf("[%d] ", (*arv)->info);
            }else{
                imprimir_folhas_menores(&(*arv)->esq, elemento);
                imprimir_folhas_menores(&(*arv)->dir, elemento);
            }

        }
    }
}

void limpar_memoria(arvore **arv){
    if(*arv != NULL){
        limpar_memoria(&(*arv)->esq);
        limpar_memoria(&(*arv)->dir);
        free(*arv);
    }

    arv = NULL;
}