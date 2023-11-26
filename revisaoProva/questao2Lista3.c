#include<stdio.h>

#define N 10
#define M N * 2

/*2,0) Faça um programa que leia 2 vetores X e Y de 10 elementos, cada um. 
Intercale os elementos desses 2 vetores formando assim um novo vetor Z de 20 
elementos, onde, nas posições ímpares de Z, estejam os elementos de X e, nas 
posições pares, os elementos de Y. Exemplo: Se X = 3,5,2,8,4 e Y = 1,7,6,5,2 então 
Z = 3,1,5,7,2,6,8,5,4,2. Imprimir o vetor Z.*/

void formaVetorZ(int *vetX, int *vetY) {
    int vetZ[M];

    //vetor x = (1,3,5) finalizado todos os itens devidamente inseridos
    //vetor y = (2,4,6) finalizado todos ------------------------------
    //vetor z = ( 1 , 2 , 3 , 4 , 5 , 6 )

    //forma
    for (int i = 0; i < N; i++) {
        vetZ[i * 2] = vetY[i];
        vetZ[i * 2 + 1] = vetX[i];
    }

    // Imprime o vetor Z
    printf("Vetor Z:\n");
    for (int i = 0; i < M; i++) {
        printf("%d ", vetZ[i]);
    }
    printf("\n");
}

int main() {
    int vetX[N], vetY[N];

    printf("Digite %d numeros para o vetor X:\n", N);

    // ler vetor X
    for (int i = 0; i < N; i++) {
        printf("Digite o %d item do vetor X : ", i + 1);
        scanf("%d", &vetX[i]);
    }

    printf("Digite %d numeros para o vetor Y:\n", N);

    // ler vetor Y
    for (int i = 0; i < N; i++) {
        printf("Digite o %d item do vetor Y: ", i + 1);
        scanf("%d", &vetY[i]);
    }

    formaVetorZ(vetX, vetY);

    return 0;
}
