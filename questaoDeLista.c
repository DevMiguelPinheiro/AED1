/*
Claro, aqui estão três questões distintas, cada uma envolvendo um tipo de estrutura de dados: lista encadeada, fila e pilha.

Lista Encadeada:

Título: Cadastro Dinâmico de Alunos

Descrição:

Uma escola deseja gerenciar dinamicamente o cadastro de alunos matriculados em cada disciplina. Crie um sistema que utilize uma lista encadeada para armazenar os alunos matriculados em uma disciplina. O programa deve permitir:

Adicionar Aluno: Adiciona um novo aluno ao final da lista encadeada da disciplina. OK
Remover Aluno: Remove um aluno da lista encadeada com base no número de matrícula. OK
Listar Alunos: Mostra todos os alunos matriculados na disciplina. OK
*/

#include<stdio.h>
#include<stdlib.h>

// lembrando que esse eh so um nome opcional

typedef struct Lista{
    int matricula;
    struct Lista *prox;
    
}Lista;


void adicionaNaLista(Lista **l,int matricula){
    Lista *ptr = (Lista*)malloc(sizeof(Lista));
    if(ptr == NULL){
        printf("Erro de alocação\n");
    }else{
        ptr->matricula = matricula;
        ptr->prox = *l;
        *l = ptr;

    }

}

void removeAluno(Lista **l, int matricula) {
    Lista *atual = *l;
    Lista *anterior = NULL;

    if (atual == NULL) {
        printf("Lista vazia, nada a remover.\n");
        return;
    }

    // Caso especial: aluno a ser removido é o primeiro da lista
    if (atual->matricula == matricula) {
        *l = atual->prox;
        free(atual);
        printf("Aluno removido.\n");
        return;
    }

    // Percorre a lista até encontrar o aluno ou o fim da lista
    while (atual != NULL && atual->matricula != matricula) {
        anterior = atual;
        atual = atual->prox;
    }

    // Verifica se o aluno foi encontrado na lista
    if (atual == NULL) {
        printf("Aluno com matrícula %d não encontrado na lista.\n", matricula);
        return;
    }

    // Remove o aluno da lista
    anterior->prox = atual->prox;
    free(atual);
    printf("Aluno removido.\n");
}

void imprimeLista(Lista *l){
    Lista *ptraux = l;
    if (ptraux != NULL)
    {
        while (ptraux!=NULL)
        {
            printf("Aluno matricula : %d ,",ptraux->matricula);
            ptraux = ptraux->prox;
        }
        
    }else{
        printf("Lista Vazia. \n");
    }
    
}


int main(){

    Lista *lista = (Lista*)malloc(sizeof(Lista));
    if(lista == NULL){
        printf("Erro de alocacao\n");
    }
    lista = NULL;

    int matricula,escolha,matriculaExcluida;

    do
    {
        printf("\nMenu:\n");
        printf("\n1 - Inserir um Aluno\n");
        printf("\n2 - Imprimir lista de Alunos\n");
        printf("\n3 - Remover da lista\n");
        printf("\n4 - Encerrar programa\n");
        printf("\nDigite sua escolha: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            printf("Digite a matricula do aluno que deseja inserir:");
            scanf("%d",&matricula);
            adicionaNaLista(&lista,matricula);
            break;
        
        case 2:
            imprimeLista(lista);
            break;
        
        case 3:
            printf("Digite a matricula do aluno que deseja remover:");
            scanf("%d",&matriculaExcluida);
            removeAluno(&lista,matriculaExcluida);
        default:
            break;
        }
    } while (escolha!= 4);
    


    return 0;
}









