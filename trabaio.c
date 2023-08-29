
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
    int quantA,quantB,conjA[0],conjB[0];
    definirconjunto(&quantA,&quantB);
    printf("A quantidade e: %d, %d", quantA,quantB);

}




