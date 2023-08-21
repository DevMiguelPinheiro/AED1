#include <stdio.h>

int main() {
    float divida, juros_divida, aplicacao, rendimento_aplicacao, saldo_divida;
    int meses = 0;

    divida = 10000;
    juros_divida = 0.025;
    aplicacao = 1500;
    rendimento_aplicacao = 0.04;
    saldo_divida = divida;

    while (saldo_divida > 0) {
        saldo_divida = saldo_divida + saldo_divida * juros_divida;  
        saldo_divida = saldo_divida - aplicacao;  
        aplicacao = aplicacao + aplicacao * rendimento_aplicacao;  
        meses = meses + 1;
    }

    printf("Divida quitada em %d meses\n", meses);

    return 0;
}
