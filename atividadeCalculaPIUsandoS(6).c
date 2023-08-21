#include <stdio.h>
#include <math.h>

int main() {
    double S = 0.0;
    double termo = 1.0;
    int sinal = 1;
    int n = 0;

    while (fabs(termo) >= 0.001) {
        S += sinal * (1.0 / pow((2 * n + 1), 3));
        n++;
        sinal *= -1;
        termo = 1.0 / pow((2 * n + 1), 3);
    }

    double pi_estimado = cbrt(S * 32.0);

    printf("Valor calculado de pi: %.15lf\n", pi_estimado);

    return 0;
}