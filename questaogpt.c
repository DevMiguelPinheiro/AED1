#include<stdio.h>
#include<string.h>

/*Considere uma lista encadeada que armazena informações sobre livros em uma biblioteca. Cada nó da lista possui os seguintes campos:

Título do livro (string)
Autor do livro (string)
Ano de publicação (inteiro)
Ponteiro para o próximo nó
Questão:
Desenvolva uma função em C para buscar e imprimir os detalhes de um livro a partir do título fornecido pelo usuário. Se o livro for encontrado na lista, imprima o título, autor e ano de publicação. Se não for encontrado, exiba uma mensagem informando que o livro não está na lista.

Dica: Você pode utilizar a função strcmp() da biblioteca string.h para comparar strings.

Fique à vontade para criar a estrutura da lista encadeada e implementar a função de busca!*/
typedef struct livro {
    char titulo[20];
    char autor[20];
    int ano;
    struct livro *prox;
} LIVRO;

void inicializaLista(LIVRO **livro) {
    *livro = NULL; // Inicializa o ponteiro para o início da lista como NULL
}

void retornaLivro(LIVRO *head, char *recebido) {
    while (head != NULL) {
        if (strcmp(head->titulo, recebido) == 0) {
            printf("Livro encontrado!\n");
            printf("Titulo : %s\n",head->titulo);
            printf("Autor : %s\n",head->autor);
            printf("Ano : %s\n",head->ano);
            return; // Encerra a função após encontrar o livro
        }
        head = head->prox;
    }
    printf("Livro não encontrado.\n");
}

int main() {
    LIVRO *head; // Ponteiro para o início da lista encadeada
    int escolha;
    // Inicializar a lista encadeada
    inicializaLista(&head);

    printf("digite o que deseja fazer:");
    scanf("%d",escolha);

    return 0;
}
