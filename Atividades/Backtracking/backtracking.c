#include <stdio.h>
#include <stdlib.h>

void atividade1(int *vet,char valores[3], int tamanho, int pos){
    int i;

    if(pos == tamanho){
        for(i=0; i<tamanho; i++)
            printf("[%c]", vet[i]);
        printf("\n");
    }else{
        for(i=0; i<3; i++){
            vet[pos] = valores[i];
            atividade1(vet, valores, tamanho, pos+1);
        }
    }
    
}

int main(void){
    int n;
    char string[] = {'a','e','i'};

    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &n);

    int *vetor = (int*) malloc(sizeof(int)*n);


    atividade1(vetor, string, n, 0);


    return 0;
}