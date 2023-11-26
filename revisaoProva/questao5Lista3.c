/*(1,0) Escreva um procedimento que recebe as 3 notas de um aluno por
parâmetro e uma letra. Se a letra for A o procedimento calcula a média
aritmética das notas do aluno, se for P, a sua média ponderada (pesos: 5, 3 e 2).
A média calculada também deve ser impressa na tela.*/

#include<stdio.h>


void procedimento(float nota1,float nota2,float nota3,char escolha){
    float media = 0, mediaPonderada = 0;
    
    switch (escolha) {
        case 'A':
            media = (nota1+nota2+nota3)/3;
            printf("A media eh : %0.2f\n",media);
            break;
        
        case 'P':
            mediaPonderada = ((nota1*5)+(nota2*3)+(nota3*2))/(5+3+2);
            printf("A media ponderada eh : %0.2f\n",mediaPonderada);
            break;
        
    }

}

int main(){ 
    float n1,n2,n3;
    char escolha;

    printf("Digite a nota 1: ");
    scanf("%f", &n1);
    printf("Digite a nota 2: ");
    scanf("%f", &n2);
    printf("Digite a nota 3: ");
    scanf("%f", &n3);

    printf("Digite o que deseja fazer : A para media e P para Media Ponderada\n");
    scanf("%s",&escolha);

    procedimento(n1,n2,n3,escolha);

    return 0;
}