#include<stdio.h>
#include<stdlib.h>

typedef struct NO{
    int dado;
    struct NO*prox;
}NO;

typedef struct FILA{
    int tamanho[100];
    NO *inicio;
    NO *fim;
}FILA;

void inicializaFila(FILA *f){
    f->inicio = NULL;
    f->fim = NULL;
}

void enfileirar(int dado,FILA *f){
    NO *ptr = (NO*)malloc((sizeof(NO)));//criando um novo ponteiro
    if(ptr == NULL){
        printf("Erro de alocação");

    }else {
        ptr->dado = dado;
        ptr->prox = NULL;
        if(f->inicio == NULL){

            printf("Você está digitando o primeiro item da fila");
            f->inicio = ptr;
        }else{
            f->fim->prox = ptr;// fim da fila sempre apontando pro ultimo no
        }
            f->fim=ptr;
    }

}

//inicio aponta para o proximo 
int desinfileirar(FILA *f){
    NO *ptr = f->inicio;
    int dado;
    if(ptr!= NULL){
        f->inicio = ptr->prox;//remove o primeiro da fila
        ptr->prox = NULL;// no removido da fila
        dado = ptr->dado;
        free(ptr);
        if(f->inicio == NULL){
            f->fim = NULL;// consequentemente se o primeiro foi removido o ultimo tambem sera nulo
        }
    }else{
        printf("fila vazia");
    }
}

void imprimeFila(FILA *f){
    NO *ptr = f->inicio;
    if(ptr!=NULL){//lista n estando vazia
    while(ptr !=NULL){
    printf("%d",ptr->dado);
    ptr = ptr->prox;
    }
    }else{
        printf("Fila vazia");
        return;
    }


}

void imprimeDado(NO *inicio) {
    NO *ptr = inicio;
    while (ptr != NULL) {
        printf("%d ", ptr->dado);
        ptr = ptr->prox;
    }
    printf("\n");
}

int main(){
    FILA *f1 = (FILA*)malloc(sizeof(FILA));
    if(f1 == NULL){
    printf("Erro de alocação");
    exit(-1);
    }
    inicializaFila(f1);
    int escolha;
        printf("\nOpções:\n");
        printf("1 - Listar número de aviões aguardando na fila de decolagem\n");
        printf("2 - Autorizar decolagem do primeiro avião\n");
        printf("3 - Adicionar um avião à fila de espera\n");
        printf("4 - Listar todos os aviões na fila de espera\n");
        printf("5 - Listar as características do primeiro avião na fila\n");
        printf("0 - Sair\n");
        scanf("%d", &escolha);    

    
    switch (escolha) {
            case 1:
                printf("Número de aviões aguardando na fila de decolagem: %d\n", f1->tamanho);
                break;
            case 2:
                autorizarDecolagem(&f1);
                break;
            case 3:
                printf("Digite o número do avião a ser adicionado à fila de espera: ");
                scanf("%d", &numeroAviao);
                adicionarAviao(&f1, numeroAviao);
                break;
            case 4:
                listarAvioesEspera(&f1);
                break;
            case 5:
                listarCaracteristicasPrimeiroAviao(&f);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Escolha novamente.\n");
        }









 }