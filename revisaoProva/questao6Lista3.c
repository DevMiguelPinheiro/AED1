/*a)(1,0) Faça um programa para preencher uma matriz m x n com números
aleatórios entre 1 e k. Os valores de m, n e k devem ser lidos do teclado. (crie
uma matriz estaticamente com os limites superiores de m e n. Considere que
m e n não podem ser maiores que 100). Não permita que o usuário entre
com valores inválidos para m, n e k.


b)(2,0) Procure por sequências com pelo menos três números consecutivos
iguais tanto nas linhas quanto nas colunas da matriz. Substitua todos os
números que estão nessas sequências por 0.
*/

#include <stdio.h>
#include <stdbool.h>

bool verificaK(int inserido, int K) {
    if (inserido > K) {
        return false;
    } else {
        return true;
    }
}

void mostra_matriz(int m,int n,int mat[m][n])
{
	int i, j;         

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++)
			printf("%2d ", mat[i][j]);
		printf("\n");
	}
}


/*void verificaSequencia(int m,int n,int *matriz[m][n]){
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <n; j++)
        {
            if (*matriz[i][j] == *matriz[i][j])
            {
                *matriz[i][j] = 0;
            }
            
        }
        
    }
    



}*/

void verificaSequenciaLinha(int m, int n, int matriz[m][n]) {
    for (int i = 0; i < m; i++) { // Percorre as linhas
        for (int j = 0; j < n - 2; j++) { // Verifica apenas até o penúltimo elemento
            if (matriz[i][j] == matriz[i][j + 1] && matriz[i][j] == matriz[i][j + 2]) {
                matriz[i][j] = matriz[i][j + 1] = matriz[i][j + 2] = 0; // Substitui por zero na linha
            }
        }
    }
}

void verificaSequenciaColuna(int m, int n, int matriz[m][n]) {
    for (int j = 0; j < n; j++) { // Percorre as colunas
        for (int i = 0; i < m - 2; i++) { // Verifica apenas até o penúltimo elemento
            if (matriz[i][j] == matriz[i + 1][j] && matriz[i][j] == matriz[i + 2][j]) {
                matriz[i][j] = matriz[i + 1][j] = matriz[i + 2][j] = 0; // Substitui por zero na coluna
            }
        }
    }
}

int main() {
    int m, n, k, inserido;
    printf("Digite M : ");
    scanf("%d", &m);
    printf("Digite N : ");
    scanf("%d", &n);
    printf("Digite K : ");
    scanf("%d", &k);

    // Verifica se m e n não ultrapassam o limite
    if (m > 100 || n > 100) {
        printf("M ou N não podem ser maiores que 100.\n");
        return 1;
    }

    int matriz[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Digite o item na posicao M = %d N = %d: ", i+1, j+1);
            scanf("%d", &inserido);
            
            if (verificaK(inserido, k) == true) {
                matriz[i][j] = inserido;
            } else {
                printf("O valor inserido nao eh permitido, saindo do preenchimento da matriz...\n");
                return 1; // Sai do programa se um valor inválido for inserido
            }
        }
    }
    
    printf("\nLetra a)Matriz antes da subisituicao:\n");
    mostra_matriz(m, n, matriz); 
    
    verificaSequenciaLinha(m, n, matriz);
    verificaSequenciaColuna(m,n,matriz); 
    
    printf("\nletra b)Matriz com sequencias substituidas:\n");
    mostra_matriz(m, n, matriz); 

    
    




}