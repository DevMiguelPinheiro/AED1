#include<stdio.h>

#define MAX_SIZE 50
#define TOTAL_MAX_SIZE 80

struct duasListas
{
    int topoPrimeira;
    int topoSegunda;
    int vetTotal[TOTAL_MAX_SIZE];
};

void inicializarDuasPilhas(struct duasListas *duasListas){
    //inicializar o topo 
    duasListas->topoPrimeira=-1;
    //inicializar a segunda lista
    duasListas->topoSegunda = TOTAL_MAX_SIZE;
    printf("Pilha iniciada no vetor!\n\n");    
}

// o metodo de empilhar sempre vai receber a pilha como parametro para poder incrementar e o valor para ser incrementado
void empilhaNaPrimeira(struct duasListas *duasListas,int valor){
    if(duasListas->topoPrimeira+1 == duasListas->topoSegunda){
        printf("Pilha 1 cheia");
        return;
    }
    //caso contrario ele coloca na primeira lista, no caso sendo que a primeira lista esta no vetor para juntar as duas por isso o incremento DENTRO DO VETOR da estrutura!
    duasListas->vetTotal[++duasListas->topoPrimeira] = valor;
    printf("O item empilhado na primeira pilha foi %d\n",valor);
}

void empilhaNaSegunda(struct duasListas *duasListas,int valor){
    if(duasListas->topoSegunda-1 == duasListas->topoPrimeira){
        printf("Pilha 2 cheia");
        return;
    }
    //caso contrario ele coloca na Segunda lista, no caso sendo que a primeira lista esta no vetor para juntar as duas por isso o incremento DENTRO DO VETOR da estrutura!
    duasListas->vetTotal[--duasListas->topoSegunda] = valor;
    printf("O item empilhado na segunda pilha foi %d\n",valor);
}

int desempilhaNaPrimeira(struct duasListas *duasListas){
    //verifica se a pilha está vazia
    if(duasListas->topoPrimeira == -1){
        printf("Pilha vazia\n");
        return -1; // ou outro valor de erro
    }
    //pega o último valor, vulgo topo da pilha, do vetor e topo da primeira pilha e em seguida o retira
    return duasListas->vetTotal[duasListas->topoPrimeira--];
}


int desempilhaNaSegunda(struct duasListas *duasListas){
    //verifica se a pilha está vazia
    if(duasListas->topoSegunda == TOTAL_MAX_SIZE){
        printf("Pilha vazia\n");
        return -1; // ou outro valor de erro
    }
    //pega o último valor, vulgo topo da pilha, do vetor e topo da segunda pilha e em seguida o retira
    return duasListas->vetTotal[duasListas->topoSegunda++];
    //incrementamos o topo da pilha para termos uma forma de parada de adição na pilha sendo esse limite a variavel TOTA_MAX_SIZE = 80
}

int main(){
    // pilhas sao basicamente pseducodigos porque nao acontece de fato a retirada dos itens da pilha apenas a passagem de um item para o proximo TOPO
    // para problemas de pilhas sempre criar a struct da pilha antes
    struct duasListas duasListas;

    inicializarDuasPilhas(&duasListas);

    empilhaNaPrimeira(&duasListas,10);
    empilhaNaPrimeira(&duasListas,20);

    empilhaNaSegunda(&duasListas,30);
    empilhaNaSegunda(&duasListas,40);

    printf("O item desempilhado foi %d\n",desempilhaNaPrimeira(&duasListas));
    printf("O item desempilhado foi %d\n",desempilhaNaPrimeira(&duasListas));
    desempilhaNaPrimeira(&duasListas);

    printf("O item desempilhado foi %d\n",desempilhaNaSegunda(&duasListas));
    printf("O item desempilhado foi %d\n",desempilhaNaSegunda(&duasListas));
    desempilhaNaSegunda(&duasListas);



    return 0;
}