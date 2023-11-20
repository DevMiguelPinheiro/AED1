#include<stdio.h>

#define N 10

int fatorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    } else {
        return num * fatorial(num - 1);//
    }
}

void formaB(int *vetA, int *vetB){
    for (int i = 0; i < N; i++) {
        vetB[i] = fatorial(vetA[i]);
    }
}

int main() {
    int vetA[N];
    int vetB[N];

    printf("Digite os itens do vetor A abaixo\n");

    //Ler vetor A
    for (int i = 0; i < N; i++) {
        printf("Item %d do vetor A: ", i + 1);
        scanf("%d", &vetA[i]);
    }
    
    formaB(vetA, vetB);
    
    //Imprime A
    printf("O vetor A eh :\n");
    for(int i = 0; i < N; i++){
        printf("%d ", vetA[i]);
    }
    printf("\n");
    //Imprime B
    printf("O vetor B eh :\n");
    for(int i = 0; i < N; i++){
        printf("%d ", vetB[i]);
    }
    printf("\n");

    return 0;
}
