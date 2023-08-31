#include <stdlib.h>
#include <stdio.h>

int repetcao(int *vetA, int *vetB,int qtdA,int qtdB){
    int i,c,e;
    e = 0;
    for (i = 0; i < qtdA; i++){
        for(c = 0; c<qtdB;c++ ){
            if (vetA[i]==vetB[c]){
                e++;

            }
        }

        
    }
 return e;

}





void definirconjunto(int(*quantA),int(*quantB)){
    printf("Quantidade de numeros no conjunto A: ");
    scanf("%d",quantA);
    printf("Quantidade de numeros no conjunto B: ");
    scanf("%d",quantB);
}

int validarNumero(int *conj,int tamanho, int i){
    int c;
    for (c=0;c<tamanho;c++){
        if (c != i){
            if(conj[c]==conj[i]){
                printf("O NUMERO JA EXISTE !!!");
                return 1;
            }
        }
    }
    return 0;
}

void inserirConj(int *conj,int tamanho){
    int i, validacao;
    for (i=0;i<tamanho;i++){
        do{
            printf("\nEscreva o numero: ");
            scanf("%d",&conj[i]);
            validacao = validarNumero(conj,tamanho,i);
        }while (validacao == 1);
    }
}

void imprimir(int *conj, int tamanho){
    int i;
        for (i=0;i<tamanho;i++){
            printf(" %d",conj[i]);
     
        }
}


int main()
{
    int quantA,quantB,quantX;
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
    quantX = repetcao(conjA,conjB,quantA,quantB);
    printf("\n%d",quantX);
    
    

    return 0;
} 
