
#include <stdlib.h>
#include <stdio.h>


void definirconjunto(int(*quantA),int(*quantB)){
    printf("Quantidade de numeros no conjunto A: ");
    scanf("%d",quantA);
    printf("Quantidade de numeros no conjunto B: ");
    scanf("%d",quantB);
}

void inserirConj(int conj[],int tamanho){
    int i,c;
    for (i=0;i<tamanho;i++){
        do{
        printf("\nEscreva o numero: ");
        scanf("%d",&conj[i]);
        for (c=0;c<tamanho;c++){
            if(conj[i]=conj[c]);
        }
        
        }
    }
}

void imprimir(int conj[], int tamanho){
    int i;
        for (i=0;i<tamanho;i++){
            printf(" %d",conj[i]);
     
        }
}


int main()
{
    int quantA,quantB;
    definirconjunto(&quantA,&quantB);
    int *conjA = malloc(quantA * sizeof(int));
    int *conjB = malloc(quantB * sizeof(int));
    printf("\nCONJUNTO A----------------------");
    inserirConj(conjA,quantA);
    printf("\nCONJUNTO B----------------------");
    inserirConj(conjB,quantB);
    printf("\nIMPRIMIR CONJUNTO A----------------------");
    imprimir(conjA,quantA);
    printf("\nIMPRIMIR CONJUNTO B----------------------");
    imprimir(conjB,quantB);
    
    

    return 0;
} 




