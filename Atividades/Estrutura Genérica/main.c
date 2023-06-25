#include <stdio.h>
#include <stdlib.h>

enum TIPO{
    ALUNO, 
    PROFESSOR
};

typedef struct Aluno{
    int matricula;
    char nome[100];
    char curso[20];
    int anoIngresso;
}Aluno;

typedef struct Professor{
    int matricula;
    char nome[100];
    float salario;
}Professor;

typedef struct Pessoa{
    int tipo;
    void* item;
    struct Pessoa *prox;
    struct Pessoa *ant;
}Pessoa;

void inserir(Pessoa **p, int tipoPessoa, void* ItemPessoa){
    Pessoa *novaPessoa = (Pessoa*) malloc(sizeof(Pessoa));
    novaPessoa->tipo = tipoPessoa;
    novaPessoa->item = ItemPessoa;
    novaPessoa->prox = *p;
    novaPessoa->ant = NULL;

    (*p)->ant = novaPessoa;
    *p = novaPessoa;
}

void remove_auxiliar(Pessoa **p){
    if((*p)->prox != NULL){
        (*p)->prox->ant = (*p)->ant;
    }
    if((*p)->ant != NULL ){
        (*p)->ant->prox = (*p)->prox; 
    }
        
    free(*p);
}

int remover(Pessoa **p, int matricula){
    if(*p == NULL){
        return -1;
    }
    
    if((*p)->tipo == PROFESSOR){
        Professor *b = (Professor*) (*p)->item;
        if(b->matricula == matricula){
            remove_auxiliar(p);
            return 1;
        }
    }else{
        Aluno *b = (Aluno*) (*p)->item;
        if(b->matricula == matricula){
            remove_auxiliar(p);
            return 1;
        }
    }

    return remover(&(*p)->prox, matricula);
}

void buscar(Pessoa *p, int matricula){
    if(p!=NULL){
        if(p->tipo == PROFESSOR){
            Professor *b = (Professor*) p->item;
            if(b->matricula == matricula){
                printf("aCHEI!\n");
                return;
            }
        }else if(p->tipo == ALUNO){
            Aluno *b = (Aluno*) p->item;
            if(b->matricula == matricula){
                printf("aCHEI!\n");
                return;
            }
        }   
        
        buscar(p->prox, matricula);
    }
    
    printf("Aluno não encontrado\n");
}

int main(){


    return 0;
}