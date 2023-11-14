#include<stdio.h>

#define N 3
#define M N*2
void formaVetorZ(int vetX[],int vetY[]){
    int vetZ[M];
    //forma
    for(int i = 0; i < N; i++) {
        vetZ[i * 2] = vetX[i];
        vetZ[i * 2 + 1] = vetY[i];
    }

    // Imprime o vetor Z
    printf("Vetor Z:\n");
    for (int i = 0; i < M; i++) {
        printf("%d ", vetZ[i]);
    }
    printf("\n");
    
}

int main(){

    int vetX[N],vetY[N];

    printf("Digite %d numeros:\n", N);

    //ler vetor X
    for(int i = 0; i < N; i++) {
        printf("Digite o %d item do vetor X : ",i+1);
        scanf("%d", &vetX[i]);
    }
    //ler vetor Y
    for(int i = 0; i < N; i++) {
        printf("Digite o %d item do vetor Y: ",i+1);
        scanf("%d", &vetY[i]);
    }

    formaVetorZ(vetX,vetY);

    return 0;
}