#include<stdlib.h>
#include<stdio.h>
void teste(int vetor[]){
    vetor[0] = 1;
    vetor[1] = 2;
}

int main(){
    int vetor[2];
    teste(vetor);
    printf("%d,%d",vetor[0],vetor[1]);


return 0;
}