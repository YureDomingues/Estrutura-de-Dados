#include <stdio.h>
#include <stdlib.h>

struct arv{
    char info;
    struct arv *esq;
    struct arv *dir;
};

typedef struct arv Arv;

Arv* arv_criar_vazia(void){
    return NULL;
}

Arv* arv_criar(char dado, Arv* sae, Arv* sad){
    Arv* p = (Arv*) malloc(sizeof(Arv));
    p->info = dado;
    p->esq = sae;
    p->dir = sad;
    return p;
}

int arv_vazia(Arv* v){
    return v == NULL;
}

void arv_imprimir(Arv* v){
    if(!arv_vazia(v)){
        printf("%c ", v->info); //imprime o nó da pos atual
        arv_imprimir(v->esq); //imprime o sae
        arv_imprimir(v->dir); //imprime o sad
    }else{
        return;
    }
}

Arv* arv_libera(Arv* v){
    if(!arv_vazia(v)){
        arv_libera(v->esq);
        arv_libera(v->dir);
        free(v);
    }
    return NULL;
}

int arv_buscar(Arv* v, char dado){
    if(arv_vazia(v)) return 0;
    return v->info == dado || arv_buscar(v->esq, dado) || arv_buscar(v->dir, dado);
}

void preOrdem(Arv* v){
    if(!arv_vazia(v)){
        printf("%c ", v->info);
        preOrdem(v->esq);
        preOrdem(v->dir);
    }
}

void simetrica(Arv *v){
    if(!arv_vazia(v)){
        preOrdem(v->esq);
        printf("%c ", v->info);
        preOrdem(v->dir);
    }

}

//Colocar altura

void posOrdem(Arv *v){
    if(!arv_vazia(v)){
        preOrdem(v->esq);
        preOrdem(v->dir);
        printf("%c ", v->info);
    }

}


int main(void){
    
    /*
    Arv* d = arv_criar('d', arv_criar_vazia(), arv_criar_vazia());
    Arv* b = arv_criar('b', arv_criar_vazia(), d);
    Arv* e = arv_criar('e', arv_criar_vazia(), arv_criar_vazia());
    Arv* f = arv_criar('f', arv_criar_vazia(), arv_criar_vazia());
    Arv* c = arv_criar('c', e, f);
    Arv* a = arv_criar('a', b, c); 
    */

    Arv* a = arv_criar('a', 
                        arv_criar('b',
                            arv_criar_vazia(),
                            arv_criar('d', arv_criar_vazia(),arv_criar_vazia())
                        ),
                        arv_criar('c',
                            arv_criar('e', arv_criar_vazia(), arv_criar_vazia()),
                            arv_criar('f', arv_criar_vazia(), arv_criar_vazia())
                        )
                      );
    printf("Pre-Ordem: \n");
    preOrdem(a);
    printf("\n");
    printf("Pos-Ordem: \n");
    simetrica(a);
    printf("\n");
    
    return 0;
}
