/*
Fila:

Título: Controle de Atendimento em um Hospital

Descrição:

Em um hospital, a triagem de pacientes é essencial para garantir que todos sejam atendidos conforme a ordem de chegada. Implemente um sistema utilizando uma fila para controlar o atendimento dos pacientes. O sistema deve permitir:

Adicionar Paciente: Adiciona um novo paciente à fila de espera. OK
Atender Próximo Paciente: Remove e exibe os detalhes do próximo paciente a ser atendido. atender == remover OK
Consultar Número de Pacientes: Mostra a quantidade de pacientes na fila de espera.
Listar Pacientes: Exibe os detalhes de todos os pacientes na fila de espera. OK
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct No{
    int dado;
    struct No*prox;
}No;

typedef struct Fila{
    No *inicio;
    No * fim;

}Fila;


void inicializaFila(Fila *f){
        f->fim =  NULL;
        f->inicio = NULL;
}


void imprimeFila(Fila *f){
    No *ptrAux = f->inicio;
    if(ptrAux != NULL){
        while (ptrAux!=NULL)
        {
            printf("%d ,", ptrAux->dado);
            ptrAux = ptrAux->prox;

        }
        
    }else{
        printf("Lista vazia\n");
    }
} 

void inserePaciente(Fila *f,int dado){
    No *ptrAux = (No*)malloc(sizeof(No));
    if(ptrAux == NULL){
        printf("Erro de alocacao\n");
    }else{
        ptrAux->dado = dado;
        ptrAux->prox = NULL;
        if(f->inicio == NULL){
            f->inicio = ptrAux;
        }else{
            f->fim->prox = ptrAux;
        }
        f->fim = ptrAux;
    }
}

int atenderPaciente(Fila *f){
    No *ptrAux = f->inicio;
    int dado;
    if(ptrAux!=NULL){
        f->inicio = ptrAux->prox;
        dado = ptrAux->dado;
        free(ptrAux);
        return dado;
    }else{
        printf("Nenhum paciente para ser atendido.\n");
        return 0;
    }

}

int contadorDePaciente(Fila*f){
    No *ptrAux = f->inicio;
    int contador = 0;
    if(ptrAux != NULL){
        while (ptrAux!=NULL)
        {
            contador++;
            ptrAux = ptrAux->prox;
        }
    return contador;
    }else{
        printf("Lista vazia\n");
        return 0;
    }
}

void limpaFila(Fila *f) {
    No *ptrAux = f->inicio;
    No *temp;

    while (ptrAux != NULL) {
        temp = ptrAux->prox;
        free(ptrAux);
        ptrAux = temp;
    }

    f->inicio = NULL;
    f->fim = NULL;
}


int main(){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    if(f == NULL){
        printf("Erro de alocacao\n");
        return 1; // Encerra o programa indicando erro de alocação
    }

    int dado, escolha;

    inicializaFila(f);

    do {
        printf("\n1. Adicionar Paciente a fila de espera.\n");
        printf("\n2. Atender o proximo Paciente da fila.\n");
        printf("\n3. Mostrar o numero de Pacientes na fila.\n");
        printf("\n4. Sair do programa.\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o cartão SUS do paciente: ");
                scanf("%d", &dado);
                inserePaciente(f, dado);
                break;
            
            case 2:
                dado = atenderPaciente(f);
                if (dado != -1) {
                    printf("O paciente atendido foi: %d\n", dado);
                }
                break;
            
            case 3:
                printf("Existem %d pacientes na fila.\n", contadorDePaciente(f));
                break;
            
            default:
                break;
        }

    } while (escolha != 4);

    printf("Encerrando programa.\n");
    limpaFila(f);
    free(f);
    return 0;
}
