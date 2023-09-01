#include <stdlib.h>
#include <stdio.h>

void imprimir(int *conj, int tamanho){
    int i;
        for (i=0;i<tamanho;i++){
            printf("\n%d",conj[i]);
     
        }
}

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





void uniao(int *vetA,int *vetB,int qtdA,int qtdB){
int qtdX;
qtdX = repetcao(vetA,vetB,qtdA,qtdB);
qtdX = qtdA + qtdB - qtdX;
int *vetX = malloc(qtdX * sizeof(int));
int i,c,e,v;
for(i=0; i < qtdA; i++ ){
    vetX[i] = vetA[i];
}
 i = qtdA;
    for(c=0;c<qtdB;c++){
        v = 0;
        for (e=0;e<qtdX;e++){
            if (vetX[e]==vetB[c]) {
                v = 1;
            }
                 
        }
        if (v==0){
            vetX[i]=vetB[c];
            i++;
        }
    
    }
    imprimir(vetX,qtdX);
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

void interseccao(int *conjA, int *conjB, int quantA, int quantB){
    int quantX,i,c,e;
    quantX = repetcao(conjA,conjB,quantA,quantB);
    int *conjX = malloc(quantX * sizeof(int));
    e=0; 
    for (i = 0; i < quantA; i++){
        for(c = 0; c<quantB;c++ ){
            if (conjA[i]==conjB[c]){
                conjX[e] = conjA[i];
                e++;
            }
        }           
    }
    printf("\nNumeros da interseccao:");
    imprimir(conjX,quantX);
}

void subtracao(int *vet1,int *vet2,int qtd1,int qtd2){
    int qtdX,i,c,e,v;

    qtdX = repetcao(vet1,vet2,qtd1,qtd2);
    qtdX = qtd1-qtdX;
    int *vetX = malloc(qtdX * sizeof(int));
    i=0;
        for(c=0;c<qtd1;c++){
            v = 0;
            for(e=0;e<qtd2;e++){
                if(vet1[c]==vet2[e]){
                    v = 1;
                }
            }
            if(v==0){
                vetX[i]=vet1[c];
            i++;
            }

        }
        imprimir(vetX,qtdX);



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
    
    printf("\nIMPRIMIR União----------------------");
    uniao(conjA,conjB,quantA,quantB);

    interseccao( conjA,  conjB,  quantA,  quantB);

    printf("\nSAUBTRAÇÃO(A-B)---------------- ");

    subtracao(conjA,conjB,quantA,quantB);
    
    

    return 0;
} 
