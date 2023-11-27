/*
Em um estabelecimento de atendimento ao cliente, é necessário organizar a fila de espera. Crie um programa em C para gerenciar essa fila utilizando conceitos de filas encadeadas.

O programa deve oferecer as seguintes opções:

Adicionar cliente à fila de espera.
Atender o próximo cliente da fila.
Mostrar o número de clientes na fila.
Sair do programa.
Para isso, você precisa implementar as seguintes funções:

inicializaFila: Inicializa a fila.
adicionaCliente: Adiciona um novo cliente à fila.
atendeCliente: Remove e atende o próximo cliente da fila.
mostraClientes: Mostra a quantidade de clientes na fila.
Ao executar o programa, o usuário deve ser capaz de escolher as opções e realizar as operações na fila de atendimento.

Lembre-se de utilizar alocação dinâmica para a criação dos nós da fila.

Teste o programa realizando operações de adição, atendimento e verificação de clientes na fila.


*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição das estruturas
typedef struct Cliente {
    int idCliente;
    char nomeCliente[50];
    struct Cliente *prox;
} Cliente;

typedef struct Fila {
    Cliente *inicioFila;
    Cliente *fimFila;
} Fila;

// Inicialização da fila
void inicializaFila(Fila *f) {
    f->inicioFila = NULL;
    f->fimFila = NULL;
}
// Função para adicionar um cliente à fila
void enfileira(Fila *f, int idCliente, char nome[50]) {
    Cliente *cliente = (Cliente *)malloc(sizeof(Cliente));
    if (cliente == NULL) {
        printf("Erro de alocação.\n");
    } else {
        cliente->idCliente = idCliente;
        strcpy(cliente->nomeCliente, nome);
        cliente->prox = NULL;
        if (f->inicioFila == NULL) {
            f->inicioFila = cliente;
        } else {
            f->fimFila->prox = cliente;
        }
        f->fimFila = cliente;
        printf("Cliente de id %d e nome %s inserido na fila\n", idCliente, nome);
    }
}
// Função para atender o próximo cliente da fila
void atendeCliente(Fila *f) {
    Cliente *clienteaux = f->inicioFila;
    
    if (clienteaux != NULL) {
        f->inicioFila = clienteaux->prox;
        printf("\nO cliente atendido foi o id = %d e o nome dele é %s\n", clienteaux->idCliente, clienteaux->nomeCliente);
        free(clienteaux);
        if (f->inicioFila != NULL) {
            printf("\nO próximo cliente a ser atendido é o id = %d e o nome dele é %s\n", f->inicioFila->idCliente, f->inicioFila->nomeCliente);
        } else {
            printf("Não há próximo cliente na fila.\n");
        }
    } else {
        printf("Fila Vazia!\n");
    }
}
// Função para mostrar a fila de clientes
void imprimeFila(Fila *f) {
    Cliente *clienteaux = f->inicioFila;
    if (clienteaux != NULL) {
        while (clienteaux != NULL) {
            printf("id = %d, nome = %s\n", clienteaux->idCliente, clienteaux->nomeCliente);
            clienteaux = clienteaux->prox;
        }
    } else {
        printf("Fila vazia\n");
    }
}
// Função para liberar memória e fechar o sistema
void fechaSistema(Fila *f) {
    Cliente *clienteaux = f->inicioFila;
    Cliente *proximoCliente;

    while (clienteaux != NULL) {
        proximoCliente = clienteaux->prox;
        free(clienteaux);
        clienteaux = proximoCliente;
    }

    f->inicioFila = NULL;
    printf("\nFila limpa!\n");
}

int main() {
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    if (fila == NULL) {
        printf("Erro de alocação na memória!\n");
    }
    inicializaFila(fila);
    int escolha, idCliente;
    char nomeCliente[50];

    do {
        printf("\n1. Adicionar cliente à fila de espera.\n");
        printf("2. Atender o próximo cliente da fila.\n");
        printf("3. Mostrar o número de clientes na fila.\n");
        printf("4. Sair do programa.\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o id do cliente: ");
                scanf("%d", &idCliente);
                printf("Digite o nome do cliente: ");
                scanf("%s", nomeCliente);

                enfileira(fila, idCliente, nomeCliente);
                break;
            case 2:
                atendeCliente(fila);
                break;
            case 3:
                imprimeFila(fila);
                break;
            default:
                break;
        }

    } while (escolha != 4);

    fechaSistema(fila);
    free(fila);
    return 0;
}
