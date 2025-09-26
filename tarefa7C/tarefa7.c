#include <stdio.h>

float harmonica(int n, float *v) {
    float soma_baixo = 0.0f;
    for (int i = 0; i < n; i++) {
        soma_baixo += 1.0f / v[i];
    }
    return (float)n / soma_baixo;
}

int main(void) {
    float valores[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(valores) / sizeof(valores[0]);

    float res = harmonica(n, valores);
    printf("Média harmônica = %f\n", res);

    return 0;
}
