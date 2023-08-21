#include <stdio.h>
#include <math.h>

int main() {
    double S = 0.0;
	int i = 0;
    for(i = 0; i <= 25; ++i) {
        S += pow(2, i) / 50.0;
    }

    printf("O valor de S = %.15lf\n", S);

    return 0;
}