#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct No{
    int dado;
    struct No *prox;
}No;

typedef struct Pilha
{
    No *topo;
}Pilha;

void inicializaPilha(Pilha *p){
    p->topo =NULL;
}

void empilha(Pilha*p,int dado){
    No *ptr = (No*)malloc(sizeof(No));
    if(ptr == NULL){
        printf("Erro de alocacao\n");
    }else{
        ptr->dado = dado;
        ptr->prox = p->topo ;
        p->topo = ptr;
    }
}

void desempilha(Pilha*p){
    No *ptraux = p->topo;
    int dadoGuardado;
    if (ptraux == NULL)
    {
        printf("Pilha vazia\n");
    }else{
        p->topo = ptraux->prox;
        ptraux->prox = NULL;
        dadoGuardado = ptraux->dado ;
        free(ptraux);
        printf("Livro retirado: %d\n", dadoGuardado);
    }
}

void imprimePilha(Pilha *p){
    No *ptraux = p->topo;
    if (ptraux != NULL) {
        printf("Conteudo da pilha:\n");
        while (ptraux != NULL) {
            printf("%d ", ptraux->dado);
            ptraux = ptraux->prox;
        }
        printf("\n");
    } else {
        printf("Pilha vazia\n");
    }
}

int main (){
    setlocale(LC_ALL, "Portuguese");
    Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
    if(pilha == NULL){
        printf("Erro de alocacao\n");

    }
    int escolha,dado;
    inicializaPilha(pilha);
    do
    {
        printf("\n");
        printf("\n");
        printf("\n1. Adicionar livro a pilha.\n");
        printf("\n2.Tirar livro da pilha.\n");
        printf("\n3. Mostrar livros na pilha.\n");
        printf("\n4. Sair do programa.\n");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            printf("\nDigite o id do livro: ");
            scanf("%d",&dado);
            empilha(pilha,dado);            
            break;
        
        
        case 2:
            printf("\nLivro retirado :");
            desempilha(pilha);            
            break;
        
        
        case 3:
            printf("\nImprimindo pilha ... \n");
            imprimePilha(pilha);            
            break;
        
        default:
            break;
        }
    } while (escolha!=4);
        printf("Limpando pilha e encerrando programa:");
        free(pilha); 

    return 0;
}