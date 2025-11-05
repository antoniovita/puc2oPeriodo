#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

void carregar_dados(FILE* arquivo, int* n_alunos, char*** nomes, float** medias) {
    fscanf(arquivo, "%d", n_alunos);

    *nomes = malloc((*n_alunos) * sizeof(char *));
    *medias = malloc((*n_alunos) * sizeof(float));

    for (int i = 0; i < *n_alunos; i++) {
        (*nomes)[i] = malloc(50 * sizeof(char));
        fscanf(arquivo, "%[ˆ%f] %f", (*nomes)[i], medias[i]);
    }

    return;
}

int main(void) {
    FILE *arquivo = fopen("entrada.txt", "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    int n_alunos;
    char **nomes;
    float *medias;

    carregar_dados(arquivo, &n_alunos, &nomes, &medias);
    fclose(arquivo);

    for (int i = 0; i < n_alunos; i++) {
        printf("%s %.1f\n", nomes[i], medias[i]);
        free(nomes[i]);
    }

    free(nomes);
    free(medias);

    return 0;
}
