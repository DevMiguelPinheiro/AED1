/*1) Leia um vetor de 40 posições. Em seguida imprima:
a. (0,5) Quantos valores pares ele possui.
b. (0,5) Quantos valores ímpares ele possui.
c. (0,5) Qual o maior valor do vetor.
d. (0,5) Qual o menor valor do vetor.

*/
#include<stdio.h>

#define N 3

void verificaParOuImpar(int vet[]) {
    int impar = 0, par = 0;
    
    for(int i = 0; i < N; i++) {
        if(vet[i] % 2 == 0) {
            printf("%d eh par\n", vet[i]);
            par++;
        } else {
            printf("%d eh impar\n", vet[i]);
            impar++;
        }
    }
    
    printf("A) Quantidade de numeros pares eh: %d\n", par);
    printf("B) Quantidade de numeros impares eh: %d\n", impar);
}

void verificaMaiorOuMenor(int vet[]){
    int maior = vet[0];
    int menor = vet[0];

    for(int i = 0; i < N; i++) {
    if(vet[i] >maior) {
        maior = vet[i];
    }
    if(vet[i] <menor) {
        menor = vet[i];
    }

    }

    printf("C)o maior numero eh : %d\n",maior);
    printf("D)o menor numero eh : %d\n",menor);
}

int main() {
    int vet[N];
    
    printf("Digite %d numeros:\n", N);

    //ler vetor
    for(int i = 0; i < N; i++) {
        scanf("%d", &vet[i]);
    }

    verificaParOuImpar(vet);
    verificaMaiorOuMenor(vet);

    return 0;
}
