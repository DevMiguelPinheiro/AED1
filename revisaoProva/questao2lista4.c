#include <stdio.h>
#include <stdlib.h>

// Lista encadeada
typedef struct no {
    int elemento;
    struct no* prox;
} tipoNo;

void imprimeLista(tipoNo* lista) {
    while (lista != NULL) {
        printf("%d -> ", lista->elemento);
        lista = lista->prox;
    }
    printf("NULL\n");
}

// Função para criar um novo nó
struct no* criaNoh(int elemento) {
    struct no* novoNoh = (struct no*)malloc(sizeof(struct no));
    if (novoNoh == NULL) {
        printf("Nao eh possivel realizar a alocação saindo...\n");
        exit(1);
    }
    novoNoh->elemento = elemento;
    novoNoh->prox = NULL;
    return novoNoh;
}

int main() {
    int escolha = 0;
    tipoNo* lista = NULL; // Inicializa a lista como vazia

    while (1) {
        printf("\nMenu:\n");
        printf("1 - Inserir um elemento\n");
        printf("2 - Imprimir lista\n");
        printf("3 - Encerrar programa\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: {
                int valor;
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);

                struct no* novoNo = criaNoh(valor);
                if (lista == NULL) {
                    lista = novoNo; // Se a lista estiver vazia, o novo nó se torna a cabeça da lista
                } else {
                    struct no* atual = lista;
                    while (atual->prox != NULL) {
                        atual = atual->prox;
                    }
                    atual->prox = novoNo; // Insere o novo nó no final da lista
                }
                break;
            }
            case 2:
                imprimeLista(lista);
                break;
            case 3:
                printf("Encerrando o programa...\n");
                exit(0);
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}
