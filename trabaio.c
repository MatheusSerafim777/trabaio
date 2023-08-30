
#import <stdlib.h>
#import <stdio.h>


void definirconjunto(int(*conjA),int(*conjB)){
    printf("Quantidade de numeros no conjunto A: ");
    scanf("%d",conjA);
    printf("Quantidade de numeros no conjunto B: ");
    scanf("%d",conjB);
}


void main()
{
    int quantA,quantB,tamanho;
    definirconjunto(&quantA,&quantB);
    int conjA[quantA],conjB[quantB];
    tamanho = sizeof(conjA)/sizeof(int);
    printf("A quantidade e: %d, %d, %d", quantA,quantB,tamanho);
}




