#include <stdio.h>
#include <stdlib.h>

typedef struct Aviao {
    int numero;
    char cor;
} Aviao;

typedef struct FilaEspera {
    Aviao avioes[100]; // Supondo uma fila de espera com no máximo 100 aviões
    int tamanho;
} FilaEspera;

void listarAvioesEspera(FilaEspera *fila) {
    printf("Aviões na fila de espera:\n");
    for (int i = 0; i < fila->tamanho; i++) {
        printf("Avião %d\n", fila->avioes[i].numero);
    }
}

void listarCaracteristicasPrimeiroAviao(FilaEspera *fila) {
    if (fila->tamanho > 0) {
        printf("Características do primeiro avião:\n");
        printf("Número: %d\n", fila->avioes[0].numero);
        // Listar outras características do primeiro avião, se houverem
    } else {
        printf("Não há aviões na fila de espera.\n");
    }
}

void adicionarAviao(FilaEspera *fila, int numeroAviao) {
    if (fila->tamanho < 100) {
        Aviao novoAviao;
        novoAviao.numero = numeroAviao;
        fila->avioes[fila->tamanho++] = novoAviao;
        printf("Avião adicionado à fila de espera.\n");
    } else {
        printf("A fila de espera está cheia.\n");
    }
}

void autorizarDecolagem(FilaEspera *fila) {
    if (fila->tamanho > 0) {
        printf("Avião %d autorizado para decolagem.\n", fila->avioes[0].numero);
        for (int i = 1; i < fila->tamanho; i++) {
            fila->avioes[i - 1] = fila->avioes[i];
        }
        fila->tamanho--;
    } else {
        printf("Não há aviões na fila de espera para decolagem.\n");
    }
}

int main() {
    FilaEspera fila;
    fila.tamanho = 0;

    int opcao, numeroAviao;

    do {
        printf("\nOpções:\n");
        printf("1 - Listar número de aviões aguardando na fila de decolagem\n");
        printf("2 - Autorizar decolagem do primeiro avião\n");
        printf("3 - Adicionar um avião à fila de espera\n");
        printf("4 - Listar todos os aviões na fila de espera\n");
        printf("5 - Listar as características do primeiro avião na fila\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Número de aviões aguardando na fila de decolagem: %d\n", fila.tamanho);
                break;
            case 2:
                autorizarDecolagem(&fila);
                break;
            case 3:
                printf("Digite o número do avião a ser adicionado à fila de espera: ");
                scanf("%d", &numeroAviao);
                adicionarAviao(&fila, numeroAviao);
                break;
            case 4:
                listarAvioesEspera(&fila);
                break;
            case 5:
                listarCaracteristicasPrimeiroAviao(&fila);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Escolha novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
