#ifndef __HASHING_
#define __HASHING_

typedef struct aluno Aluno;

void inserir(char *nomeArq, int matricula, char *nomeAluno, char *nomeCurso);
void inicializar(char *nomeArq, int numeroAlunos);
void imprimirBusca(char *nomeArq, int matricula);
void imprimirTabela(char *nomeArq);

#endif