
#include <stdlib.h>
#include <stdio.h>


void definirconjunto(int(*quantA),int(*quantB)){
    printf("Quantidade de numeros no conjunto A: ");
    scanf("%d",quantA);
    printf("Quantidade de numeros no conjunto B: ");
    scanf("%d",quantB);
}


void main()
{
    int quantA,quantB,tamanho;
    definirconjunto(&quantA,&quantB);
    int *conjA = malloc(quantA * sizeof(int));
    int *conjB = malloc(quantB * sizeof(int));
    tamanho = sizeof(conjA)/sizeof(int);
    printf("A quantidade e: %d, %d, %d", quantA,quantB,tamanho);
}




