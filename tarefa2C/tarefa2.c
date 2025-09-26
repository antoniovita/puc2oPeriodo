#include <stdio.h>

int main(void) {

    int a, b, c;

    printf("Insira o a: ");
    scanf("%d", &a);
    printf("Insira o b: ");
    scanf("%d", &b);
    printf("Insira o c: ");
    scanf("%d", &c);

    int maior = a;
    if (b > maior) {
        maior = b;
    }
    if (c > maior) {
        maior = c;
    }

    printf("O maior número é %d\n", maior);
    return 0;
}
