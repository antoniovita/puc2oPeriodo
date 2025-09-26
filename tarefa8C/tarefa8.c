#include <stdio.h>
#include <stdlib.h>

float* reverso(int n, float* v) {
    float* novo_v = (float*)malloc(n * sizeof(float));

    for (int i = 0; i < n; i++) {
        novo_v[i] = v[n - 1 - i];
    }
    return novo_v;
}

int main() {
    int n = 5;
    float vetor[] = {1, 2, 3, 4, 5};

    float* vetor_reverso = reverso(n, vetor);

    printf("Vetor reverso: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", vetor_reverso[i]);
    }
    printf("\n");

    free(vetor_reverso);
    return 0;
}
