#include <stdio.h>

int main() {
    char cargo;
    float atual, novo;
    printf("t para Tecnico, g para Gerente, ou d para Demais");
    printf("Digite o cargo do funcionario : ");
    scanf(" %c", &cargo);  
    
    printf("Digite o salario atual: ");
    scanf("%f", &atual);

    switch (cargo) {
        case 't':
            novo = atual * 1.5;  
            break;
        case 'g':
            novo = atual * 1.3;  
            break;
        case 'd':
            novo = atual * 1.2;  
            break;
        default:
            printf("Esse cargo nao eh valido!\n");
            return 1;  
    }

    printf("O salario antigo era: %.2f\n",atual);
    printf("Novo salario: %.2f\n", novo);

    return 0;
}
