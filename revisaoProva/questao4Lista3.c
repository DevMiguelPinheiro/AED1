/*(1,0) Faça uma função que recebe um vetor X(15) de inteiros , por parâmetro, e retorna
a quantidade de valores pares em X.*/



#include<stdio.h>

#define N 5

int quantidadeDePares(int *vet){
    int pares;
    pares = 0;
    for(int i = 0;i<N;i++){
        if(vet[i]%2 == 0){
            pares++;
        }
    }
    

    return pares;
}

int main(){
    int vetX[N];

    printf("Digite os itens do vetor : ");
    for (int  i = 0; i < N; i++)
    {
    printf("Digite o  %d  item do vetor :",i );
    scanf("%d",&vetX[i]);
    }
    
    printf("Quantidade de valores pares: %d\n", quantidadeDePares(vetX));

    return 0;


}