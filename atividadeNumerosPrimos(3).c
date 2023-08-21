#include <stdio.h>

int main() {
    int numero, i, ehPrimo = 1;

    printf("Digite um numero:");
    scanf("%d", &numero);

    if (numero <= 1) {
        ehPrimo = 0;
    } else {
        for (i = 2; i <= numero / 2; ++i) {
            if (numero % i == 0) {
                ehPrimo = 0;
                break;
            }
        }
    }

    if (ehPrimo) {
        printf("%d Eh um numero primo.\n", numero);
    } else {
        printf("%d Nao eh um numero primo.\n", numero);
    }

    return 0;
}