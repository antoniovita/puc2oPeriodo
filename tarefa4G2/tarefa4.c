#include <stdio.h>

union Valor {
    int i;
    float f;
    char c;
};

int main() {
    union Valor v;
    int opcao;

    printf("Qual tipo de valor deseja inserir?\n");
    printf("1 - Inteiro\n");
    printf("2 - Real (float)\n");
    printf("3 - Caractere\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Digite um valor inteiro: ");
            scanf("%d", &v.i);
            printf("Valor armazenado: %d\n", v.i);
            break;
        case 2:
            printf("Digite um valor real: ");
            scanf("%f", &v.f);
            printf("Valor armazenado: %.2f\n", v.f);
            break;
        case 3:
            printf("Digite um caractere: ");
            scanf(" %c", &v.c);
            printf("Valor armazenado: %c\n", v.c);
            break;
        default:
            printf("Opcao invalida!\n");
    }

    return 0;
}
