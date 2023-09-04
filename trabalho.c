#include <stdlib.h>
#include <stdio.h>


void imprimir(int *conj, int tamanho){
    int i;
        printf("{ ");
        for (i=0;i<tamanho;i++){
            if(i > 0){
                printf(", %d",conj[i]);
            }
            else{
                printf("%d",conj[i]);    
            }
        }
        printf(" }");
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
void diferenca(int *vetA,int *vetB,int qtdA,int qtdB){
    int qtdX,i,c,e,v;
    qtdX = repetcao(vetA,vetB,qtdA,qtdB);
    qtdX = qtdA + qtdB - (qtdX * 2);
    int *vetX = malloc(qtdX * sizeof(int));
    i=0;
        for(c=0;c<qtdA;c++){
            v = 0;
            for(e=0;e<qtdB;e++){
                if(vetA[c]==vetB[e]){
                    v = 1;
                }
            }
            if(v==0){
                vetX[i]=vetA[c];
            i++;
            }

        }

        for(c=0;c<qtdB;c++){
            v = 0;
            for(e=0;e<qtdA;e++){
                if(vetB[c]==vetA[e]){
                    v = 1;
                }
            }
            if(v==0){
                vetX[i]=vetB[c];
            i++;
            }

        }
        imprimir(vetX,qtdX);
}

void multiplicacao(int *vetA,int *vetB,int qtdA,int qtdB){
    int qtdX,i,c,e;
    qtdX = qtdA*qtdB;
    int *vetX = malloc(qtdX * sizeof(int));
    i=0;
    for(c=0;c<qtdA;c++){
        for(e=0;e<qtdB;e++){
            vetX[i] = ((vetA[c]) * (vetB[e]));
            i++;
        }
    }
    imprimir(vetX,qtdX);
}

int menu(){
    int resp;
    printf("\n**************************");
    printf("\n* 1. UNIAO               *");
    printf("\n* 2. INTERSECAO          *");
    printf("\n* 3. A - B               *");            
    printf("\n* 4. B - A               *");  
    printf("\n* 5. DIFERENCA SIMETRICA *"); 
    printf("\n* 6. A x B               *");
    printf("\n* 7. SAIR                *");   
    printf("\n**************************");
    printf("\nDIGITE UMA OPCAO ACIMA: ");
    scanf("%d",&resp); 
    printf("**************************\n");
    return resp;
}

int selecionar(int*conjA,int *conjB,int quantA,int quantB){
    int resp = menu();
    switch (resp)
    {
    case 1:
        printf("*          UNIAO         *\n");
        uniao(conjA,conjB,quantA,quantB);
        return 1;
        break;
    case 2:
        printf("*        INTERSECAO      *\n");
        interseccao(conjA,conjB,quantA,quantB);
        return 1;
        break;
    case 3:
        printf("*          A - B         *\n");
        subtracao(conjA,conjB,quantA,quantB);
        return 1;
        break;
    case 4:
        printf("*          B - A         *\n");
        subtracao(conjB,conjA,quantB,quantA);
        return 1;
        break;
    case 5:
        printf("*  DIFERENCA SIMETRICA   *\n");
        diferenca(conjA,conjB,quantA,quantB);
        return 1;
        break;
    case 6:
        printf("*         A x B          *\n");
        multiplicacao(conjA,conjB,quantA,quantB);
        return 1;
        break;
    case 7:
        return -1;
        break;
    
    default:
        printf("OPCAO INVALIDA");
        printf("\n***************************\n");
        return 1;
        break;
    }
}


int main()
{
    int quantA,quantB,validacao;
    definirconjunto(&quantA,&quantB);
    int *conjA = malloc(quantA * sizeof(int));
    int *conjB = malloc(quantB * sizeof(int));

    printf("\n*CONJUNTO A*");
    inserirConj(conjA,quantA);
    
    printf("\n*CONJUNTO B*");
    inserirConj(conjB,quantB);
    do
    {   
        printf("\n**************************\n");
        printf("*  NUMEROS DO CONJUNTO A *\n");
        imprimir(conjA,quantA);
        printf("\n*  NUMEROS DO CONJUNTO B *\n");
        imprimir(conjB,quantB);
        validacao = selecionar(conjA,conjB,quantA,quantB);
    } while (validacao > 0);
    return 0;
} 
