#include "funcoesAVL.h"

arvore* ler_arvore_arvore(FILE *arq){
    arvore *arv = ler_arvore(arq);
    ajustarFB(arv);
    return arv;
}

void ajustarFB(arvore *arv){
    if (arv != NULL){
        int he = contar_niveis(arv->esq);
        int hd = contar_niveis(arv->dir);
        arv->FB = hd - he;
        ajustarFB(arv->esq);
        ajustarFB(arv->dir);
    }
}

//Rotação esquerda

arvore *rotacao_esq(arvore *r){
    if (r->dir->FB == -1)
        r = rotacao_esq_dupla(r);
    else
        r = rotacao_esq_simples(r);
    return r;
}

arvore *rotacao_esq_simples(arvore *r){
    // Os nós a e b serão aqueles com FB modificados.
    arvore *a = r;
    arvore *b = a->dir;
    a->dir = b->esq;
    b->esq = a;

    if (b->FB == 1){
        a->FB = 0;
        b->FB = 0;
    }
    else{
        a->FB = 1;
        b->FB = -1;
    }
    
    r = b;
    return r;
}

arvore *rotacao_esq_dupla(arvore *r){
    // Os nós a, b, c serão aqueles com FBs modificados
    arvore *a = r;
    arvore *c = a->dir;
    arvore *b = c->esq; // O nó b será a nova raiz

    c->esq = b->dir;
    a->dir = b->esq;
    b->esq = a;
    b->dir = c;

    // Setando os valores dos FBs de acordo
    // com FB da nova raiz.

    switch (b->FB)
    {
    case -1:
        a->FB = 0;
        c->FB = 1;
        break;
    case 0:
        a->FB = 0;
        c->FB = 0;
        break;
    case +1:
        a->FB = -1;
        c->FB = 0;
        break;
    }
    b->FB = 0;
    r = b;
    return r;
}

//Rotação direita

arvore *rotacao_dir (arvore *r){
    if (r->esq->FB == 1)
        r = rotacao_dir_dupla(r);
    else
        r = rotacao_dir_simples(r);
    return r;
}

arvore *rotacao_dir_simples (arvore *r){
    // Os nós a e b serão aqueles com FB modificados.
    arvore *a = r->esq;
    arvore *b = r;
    b->esq = a->dir;
    a->dir = b;

    if (a->FB == -1){
        a->FB = 0;
        b->FB = 0;

    }else{
        a->FB = 1;
        b->FB = -1;
    }

    r = a;
    return r;
}

arvore *rotacao_dir_dupla(arvore *r)
{
    // Os nós a, b, c serão aqueles com FBs modificados
    arvore *c = r;
    arvore *a = c->esq;
    arvore *b = a->dir;

    c->esq = b->dir;
    a->dir = b->esq;
    b->esq = a;
    b->dir = c;

    // Setando os valores dos FBs de acordo
    // com FB da nova raiz.

    switch (b->FB)
    {
    case -1:
        a->FB = 0;
        c->FB = 1;
        break;
    case 0:
        a->FB = 0;
        c->FB = 0;
        break;
    case +1:
        a->FB = -1;
        c->FB = 0;
        break;
    }

    b->FB = 0;
    r = b;
    return r;
}

//Inserir avl

arvore* inserir_avl(arvore *r, int x, int *hMudou){
    if (r == NULL) // Momento de inserir
    {
        r = (arvore *)malloc(sizeof(arvore));
        r->info = x;
        r->esq = NULL;
        r->dir = NULL;
        r->FB = 0;
        *hMudou = 1;
    }
    else
    {
        if (x <= r->info)

        {
            r->esq = inserir_avl(r->esq, x, hMudou);
            if (*hMudou == 1)
            {

                switch (r->FB)

                {
                case -1:
                    r = rotacao_dir(r);
                    *hMudou = 0;
                    break;
                case 0:
                    r->FB = -1;
                    *hMudou = 1;
                    break;
                case +1:
                    r->FB = 0;
                    *hMudou = 0;
                    break;
                }
            }
        }
        else
        {
            r->dir = inserir_avl(r->dir, x, hMudou);
            if (*hMudou == 1)

            {
                switch (r->FB)
                {
                case -1:

                    r->FB = 0;
                    *hMudou = 0;
                    break;
                case 0:
                    r->FB = +1;
                    *hMudou = 1;
                    break;
                case +1:
                    r = rotacao_esq(r);
                    *hMudou = 0;
                    break;
                }
            }
        }
    }
    return r;
}

// Remover de uma árvore AVL

arvore* remover_avl(arvore *r, int x, int *hMudou){
    if (r != NULL)
    {
        if (r->info == x)

        {
            // Verificar se é folha
            if (r->esq == NULL && r->dir == NULL)
            {
                free(r);
                *hMudou = 1;
                return NULL;
            }
            // Verificar se um dos filhos é nulo
            else if (r->esq == NULL || r->dir == NULL)
            {
                arvore *aux;
                if (r->esq == NULL)
                    aux = r->dir;
                else
                    aux = r->esq;
                free(r);
                *hMudou = 1;
                return aux;
            }
            // Nenhum filho nulo
            else
            {
                arvore *maiorEsq = r->esq;
                while (maiorEsq->dir != NULL)
                    maiorEsq = maiorEsq->dir;
                r->info = maiorEsq->info;
                r->esq = remover_avl(r->esq, r->info, hMudou);
                if (*hMudou == 1)
                {
                    switch (r->FB)
                    {
                    case -1:
                        r->FB = 0;
                        *hMudou = 1;
                        break;
                    case 0:

                        r->FB = 1;
                        *hMudou = 0;
                        break;
                    case +1:
                    {
                        int aux = r->dir->FB;
                        r = rotacao_esq(r);
                        if (aux == 0)
                            *hMudou = 0;
                        else
                            *hMudou = 1;
                        break;
                    }
                    }
                }
            }
        }
        else if (x < r->info)
        {
            r->esq = remover_avl(r->esq, x, hMudou);
            if (*hMudou == 1)
            {
                switch (r->FB)
                {
                case -1:
                    r->FB = 0;
                    *hMudou = 1;
                    break;
                case 0:
                    r->FB = 1;
                    *hMudou = 0;
                    break;
                case +1:
                {
                    int aux = r->dir->FB;
                    r = rotacao_esq(r);
                    if (aux == 0)
                        *hMudou = 0;
                    else
                        *hMudou = 1;
                    break;
                }
                }
            }
        }
        else
        {
            r->dir = remover_avl(r->dir, x, hMudou);
            if (*hMudou == 1)
            {
                switch (r->FB)
                {
                case +1:
                    r->FB = 0;
                    *hMudou = 1;
                    break;
                case 0:
                    r->FB = -1;
                    *hMudou = 0;
                    break;
                case -1:
                {
                    int aux = r->esq->FB;
                    r = rotacao_dir(r);
                    if (aux == 0)
                        *hMudou = 0;
                    else
                        *hMudou = 1;
                    break;
                }
                }
            }
        }
        return r;
    }
}