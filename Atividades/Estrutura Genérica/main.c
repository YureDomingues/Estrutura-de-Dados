#include <stdio.h>
#include <stdlib.h>

enum TIPO
{
    ALUNO,
    PROFESSOR
};

typedef struct Aluno
{
    int matricula;
    char nome[100];
    char curso[20];
    int anoIngresso;
} Aluno;

typedef struct Professor
{
    int matricula;
    char nome[100];
    float salario;
} Professor;

typedef struct Pessoa
{
    int tipo;
    void *item;
    struct Pessoa *prox;
    struct Pessoa *ant;
} Pessoa;

void inserir(Pessoa **p, int tipoPessoa, void *ItemPessoa)
{
    Pessoa *novaPessoa = (Pessoa *)malloc(sizeof(Pessoa));
    novaPessoa->tipo = tipoPessoa;
    novaPessoa->item = ItemPessoa;
    novaPessoa->prox = *p;
    novaPessoa->ant = NULL;
    if (*p != NULL)
        (*p)->ant = novaPessoa;
    *p = novaPessoa;
}

void inserir_aluno(Pessoa **p, int matricula, char *nome, char *curso, int anoIngresso)
{
    void *aluno = malloc(sizeof(Aluno));
    ((Aluno *)aluno)->matricula = matricula;
    for (int i = 0; i < sizeof(nome) / sizeof(char); i++)
        ((Aluno *)aluno)->nome[i] = nome[i];
    for (int i = 0; i < sizeof(curso) / sizeof(char); i++)
        ((Aluno *)aluno)->curso[i] = curso[i];
    ((Aluno *)aluno)->anoIngresso = anoIngresso;
    inserir(p, ALUNO, aluno);
}
void inserir_professor(Pessoa **p, int matricula, char *nome, float salario)
{
    void *professor = malloc(sizeof(Professor));
    ((Professor *)professor)->matricula = matricula;
    for (int i = 0; i < sizeof(nome) / sizeof(char); i++)
        ((Aluno *)professor)->nome[i] = nome[i];
    ((Professor *)professor)->salario = salario;
    inserir(p, PROFESSOR, professor);
}

void remove_auxiliar(Pessoa **p)
{
    if ((*p)->prox != NULL)
    {
        (*p)->prox->ant = (*p)->ant;
    }
    if ((*p)->ant != NULL)
    {
        (*p)->ant->prox = (*p)->prox;
    }

    free(*p);
}

int remover(Pessoa **p, int matricula)
{
    if (*p == NULL)
    {
        return -1;
    }

    if ((*p)->tipo == PROFESSOR)
    {
        Professor *b = (Professor *)(*p)->item;
        if (b->matricula == matricula)
        {
            remove_auxiliar(p);
            return 1;
        }
    }
    else
    {
        Aluno *b = (Aluno *)(*p)->item;
        if (b->matricula == matricula)
        {
            remove_auxiliar(p);
            return 1;
        }
    }

    return remover(&(*p)->prox, matricula);
}

void buscar(Pessoa *p, int matricula)
{
    if (p != NULL)
    {
        if (p->tipo == PROFESSOR)
        {
            Professor *b = (Professor *)p->item;
            if (b->matricula == matricula)
            {

                printf("Professor:\n");
                printf("nome %s\n", b->nome);
                printf("matricula: %d\n", b->matricula);
                printf("salario: %.2f\n", b->salario);
                return;
            }
        }
        else if (p->tipo == ALUNO)
        {
            Aluno *b = (Aluno *)p->item;
            if (b->matricula == matricula)
            {
                printf("Aluno:\n");
                printf("matricula: %d\n", b->matricula);
                printf("curso: %s\n", b->curso);
                printf("nome %s\n", b->nome);
                printf("ingresso %d\n", b->anoIngresso);
                return;
            }
        }

        buscar(p->prox, matricula);
    }
    else
    {
        printf("não encontrado\n");
    }
}

int comparar_string(char *a, char *b)
{
    if (sizeof(a) != sizeof(b))
        return 0;
    for (int i = 0; i < sizeof(a) / sizeof(char); i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}

int contar_curso(Pessoa *p, char *curso)
{
    int cont = 0;
    while (p != NULL)
    {
        if (p->tipo == ALUNO)
        {
            Aluno *a = (Aluno *)p->item;
            if (comparar_string(a->curso, curso))
                cont++;
        }
        p = p->prox;
    }
    return cont;
}

float maior_salario(Pessoa *p)
{
    float maior_salario = 0;
    while (p != NULL)
    {
        if (p->tipo == PROFESSOR)
        {
            Professor *a = (Professor *)p->item;
            if (a->salario > maior_salario)
                maior_salario = a->salario;
        }
        p = p->prox;
    }
    return maior_salario;
}

void imprimir_maior_salario(Pessoa *p)
{
    float maior_sal = maior_salario(p);
    while (p != NULL)
    {
        if (p->tipo == PROFESSOR)
        {
            Professor *b = (Professor *)p->item;
            if (b->salario == maior_sal)
            {
                printf("Professor:\n");
                printf("- nome: %s\n", b->nome);
                printf("- matricula: %d\n", b->matricula);
                printf("- salario: %.2f\n", b->salario);
            }
        }
        p = p->prox;
    }
}

int main()
{
    Pessoa *lista = NULL;
    int sair = 0;
    int opcao;
    while (!sair)
    {
        printf("\n\n1 - Inserir uma pessoa na lista\n");
        printf("2 - Remover uma pessoa pela matricula\n");
        printf("3 - Buscar uma pessoa pela matricula\n");
        printf("4 - Contar o numero de alunos em um determinado curso\n");
        printf("5 - imprimir os professores de maior salario\n");
        printf("6 - Sair\n\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("1 - Aluno\n");
            printf("2 - Professor\n\n");
            int opcao_pessoa;
            scanf("%d", &opcao_pessoa);
            switch (opcao_pessoa)
            {
            case 1:
            {
                Aluno *a = (Aluno*) malloc(sizeof(Aluno));

                printf("Digite a matrícula: ");
                scanf("%d", &a->matricula);
                setbuf(stdin, NULL);
                printf("Digite o nome do aluno: ");
                scanf("%[^\n]", a->nome);
                setbuf(stdin, NULL);
                printf("Digite o curso: ");
                scanf("%[^\n]", a->curso);
                setbuf(stdin, NULL);
                printf("Digite o ano de ingresso: ");
                scanf("%d", &a->anoIngresso);
                setbuf(stdin, NULL);
                inserir_aluno(&lista, a->matricula, a->nome, a->curso, a->anoIngresso);
                break;
            }
            case 2:
            {  
                Professor *p = (Professor*) malloc(sizeof(Professor));

                printf("Digite a matricula: ");
                scanf("%d", &p->matricula);
                setbuf(stdin, NULL);
                printf("Digite o nome do Professor: ");
                scanf("%[^\n]", p->nome);
                setbuf(stdin, NULL);
                printf("Digite o salário: ");
                scanf("%f", &p->salario);
                setbuf(stdin, NULL);
                inserir_professor(&lista, p->matricula, p->nome, p->salario);
                break;
            }
            default:
                printf("Digite um valor válido\n");
                break;
            }

            break;
        case 2:
        {
            int matricula;
            scanf("%d", &matricula);
            remover(&lista, matricula);
            break;
        }
        case 3:
        {
            int matricula;
            scanf("%d", &matricula);
            buscar(lista, matricula);
            break;
        }

        case 4:
        {
            char *curso;
            scanf("%s", curso);
            printf("%d", contar_curso(lista, curso));
            break;
        }
        case 5:
        {
            imprimir_maior_salario(lista);
            break;
        }
        case 6:
        {
            sair = 1;
            break;
        }
        default:
            break;
        }
    }
    return 0;
}