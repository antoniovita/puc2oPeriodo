// 250102
#include <stdio.h>

int main (void) {
    int matricula, ano, posicao, semestre;
    printf("Insira sua matrícula: ");
    scanf("%d", &matricula);

    ano = matricula / 10000;
    posicao = matricula % 100;
    semestre = (matricula / 100) % 10;

    printf("O aluno entrou na posição %d, no semestre %d e no ano de %d", posicao, semestre, ano);

    return 0;
}