#include <stdio.h>

int mediaValores(void);

int main (void) {
    mediaValores();
}

int mediaValores (void) {
    int quantidade;
    float valor = 0;

    printf("Insira a quantidade de valores: ");
    scanf("%d", &quantidade);

    for (int a = 1; a <= quantidade; a ++) {
        float numero;
        printf("Insira o %d valor:", a);
        scanf("%f", &numero);
        valor += numero;
    }

    float media = valor/quantidade;

    printf("Média dos valores: %f\n", media);
    return 0;
}

