#include<stdio.h>
#include<stdlib.h>

/*Implemente um programa em C que insira elementos no inicio de uma lista encadeada.*/
typedef struct LISTA{
        int dado;
        struct LISTA *prox;
}LISTA;


void inicializaLista(LISTA **lista){
     *lista = NULL;
     printf("LISTA INICIADA!!!!");
}

void insereNoInicio(LISTA **lista,int dado){
    LISTA *ptr = (LISTA*)malloc(sizeof(LISTA));
    if(ptr == NULL){
        printf("Erro de alocacao");
    }else{
        ptr->dado = dado;
        ptr->prox = *lista;
        *lista = ptr;
        printf("\no item inserido foi %d\n",dado);
    }

}

void imprimeLista(LISTA **lista){
    LISTA *ptr = *lista; //atribui o endereço do primeiro nó da lista ao ponteiro
    if(ptr == NULL){ //verifica se a lista está vazia
        printf("Lista VAZIA");
    }else{
        while(ptr != NULL){ //percorre a lista até o final
            printf(" %d ,", ptr->dado); //imprime o dado do nó atual
            ptr = ptr->prox; //move o ponteiro para o próximo nó
        }
        printf("\n");
    }
}

void limpaLista(LISTA **lista) {
    LISTA *aux; // declara um ponteiro auxiliar
    while (*lista != NULL) { // repete enquanto a lista não está vazia
        aux = *lista; // guarda o endereço do primeiro nó da lista
        *lista = (*lista)->prox; // atualiza o ponteiro da lista para o próximo nó
        printf("\n LISTA LIMPA ");
        free(aux); // libera a memória do nó removido
    }
}

     


int main(){
    
    LISTA *lista;
    inicializaLista(&lista);
    int escolha,dado;
    printf("\nFuncionando"); 
    
    do { // inicia o laço do-while
        printf("\n Digite o que deseja fazer : \n");
        printf("\n 1-inserir um elemento \n");
        printf("\n 2-imprimir a lista \n");
        printf("\n 3-terminar o programa \n");
        printf("\n\n");
        printf("\n DIGITE A OPCAO AQUI : ");

        scanf("%d",&escolha);
        switch (escolha)
        {
        case 1:
            printf("\n Digite o que deseja inserir :\n");
            scanf("%d",&dado);
            insereNoInicio(&lista,dado);
            break;

        case 2:
            printf("\n Imprimindo Lista .... \n");
            imprimeLista(&lista);
            break;

        case 3:
            printf("\n Terminando programa\n");
            limpaLista(&lista);
            break;
        
        default:
            printf("\nOpção inválida\n");
            break;
        }
    } while (escolha != 3); // verifica a condição de saída do laço
    
    return 0;    
}
