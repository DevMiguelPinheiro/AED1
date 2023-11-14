#include <stdio.h>

void determinarQuadrante(float x, float y) {
    if (x > 0 && y > 0) {
        printf("O ponto esta no primeiro quadrante\n");
    } else if (x < 0 && y > 0) {
        printf("O ponto esta no segundo quadrante\n");
    } else if (x < 0 && y < 0) {
        printf("O ponto esta no terceiro quadrante\n");
    } else if (x > 0 && y < 0) {
        printf("O ponto esta no quarto quadrante\n");
    } else if (x == 0 && y != 0) {
        printf("O ponto esta sobre o eixo Y\n");
    } else if (y == 0 && x != 0) {
        printf("O ponto esta sobre o eixo X\n");
    } else {
        printf("O ponto esta sobre a Origem (0, 0)\n");
    }
}

int main() {
    float ponto_x, ponto_y;
    printf("Digite o ponto X : ");
    scanf("%f", &ponto_x);
    printf("Digite o ponto Y : ");
    scanf("%f", &ponto_y);


    determinar_quadrante_ou_eixo(ponto_x, ponto_y);

    return 0;
}
