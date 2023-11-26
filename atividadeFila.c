#include<stdio.h>
#include<stdlib.h>

// pra filas cria uma estrutura NO com o dado
typedef struct NO
{
    int dado;
    struct NO *prox;
}NO;


//e uma pra fila contendo o inicio e o fim da fila com Ponteiros
typedef struct Fila
{
    NO *ini;
    NO *fim;
}Fila;

//inicializar a fila
void inicializaFila(Fila*f){
    f->ini = NULL;
    f->fim = NULL;
}

// dentro do enfileiramento eh feita a inicializacao da lista para garantir 
void enfileiramento(int dado, Fila *f){
    NO *ptr = (NO*) malloc(sizeof(NO));
    if(ptr ==NULL){
        printf("Erro de alocação\n");
        return;
    }else{
        //inicializar a lista
        ptr->dado = dado;
        ptr->prox = NULL;
        //checar se eh o primeiro
        if(f->ini == NULL){
            // fazer o ponteiro inicial da lista apontar para o primeiro item
            f->ini = ptr;
        }else{
            // fazer sempre o fim apontar para o proximo ponteiro do NO
            f->fim->prox  = ptr;

        }
            f->fim = ptr;
        // por ultimo atualizar o fim apontar para o proximo no
        printf("O item alocado foi %d\n\n",dado);
    }
}

// em filas sempre removemos do inicio da fila
int desenfileira(Fila *f){
    NO *ptraux = f->ini;
    //criar auxiliar pra poder de fato limpar a memoria
    int aux ;
    if(ptraux != NULL){
        f->ini = ptraux->prox;// o inicio da fila apontar para o proximo ponteiro
        ptraux->prox = NULL;// desliga o NO
        aux = ptraux->dado;// pegar o dado do pnteiro e atribuir a variavel 
        free(ptraux);// limpa a memoria do ponteiro
        if(f->ini == NULL){
            f->fim = NULL;
        }
        return aux;
    }else{
        printf("Fila VAZIA!!!\n");
        return -1;
    }

}

void imprimeFila(Fila *f){
    NO *ptraux = f->ini;

    if(ptraux != NULL){
        printf("Elementos da fila: ");
        while (ptraux != NULL) {
            printf("%d ", ptraux->dado);
            ptraux = ptraux->prox;
        }
        printf("\n");
    } else {
        printf("Fila Vazia!\n");
    }
}


int main(){
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    if(fila == NULL){
        printf("Erro de alocacacao\n");
        exit(-1);
    }else{
    inicializaFila(fila);
    int escolha,dado;
    do
    {

    printf("\nOpcoes\n");
    printf("\n1 Inserir item\n");
    printf("\n2 Desinfileirar item\n");
    printf("\n3 Imprimir fila\n");
    printf("\n4 Sair e encerrar programa\n");
    printf("\nDigite sua opcao :");
    scanf("%d",&escolha);



    switch (escolha)
        {
    case 1:
        printf("Digite o dado que deseja inserir : ");
        scanf("%d",&dado);
        enfileiramento(dado,fila);
        break;
    case 2:
        dado = desenfileira(fila);
        if (dado != -1) {
        printf("Item desenfileirado: %d\n", dado);
        }
        break;
    case 3:
        imprimeFila(fila);
        break;
    default:
        break;
    }
    } while (escolha!=4);
    
    printf("Programa Finalizado");      

    }
}