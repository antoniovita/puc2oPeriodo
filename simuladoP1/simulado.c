/*
Questão 1: (2.0)
Implemente a função carregar_dados. Ela deve ler a primeira linha do arquivo para
determinar o número de alunos (N) e, em seguida, ler os dados de cada aluno. Os dados
lidos devem ser retornados através dos ponteiros de argumento.
void carregar_dados(FILE* arquivo, int* n_alunos, char** *nomes, float* *medias);
Critérios:
(1.0) Usar malloc para alocar os vetores nomes e médias, e para cada nome individual.
(0.3) Verificar se ocorreu erro em todas as alocações dinâmicas.
(0.7) Retornar os 3 dados através dos ponteiros de argumento
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void carregar_dados(FILE* arquivo, int* n_alunos, char*** nomes, float** medias) {
    fscanf(arquivo, "%d\n", n_alunos);

    *nomes = (char **) malloc(sizeof(char *) * (*n_alunos));
    *medias = (float *) malloc(sizeof(float) * (*n_alunos));

    for (int i = 0; i < *n_alunos; i++) {
        char nome_temp[256];
        fscanf(arquivo, "%255s %f\n", nome_temp, &(*medias)[i]);

        (*nomes)[i] = malloc(strlen(nome_temp) + 1);
        strcpy((*nomes)[i], nome_temp);
    }
}

int main(void) {
    FILE *arquivo = fopen("dados.txt", "r");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int n_alunos = 0;
    char **nomes = NULL;
    float *medias = NULL;

    carregar_dados(arquivo, &n_alunos, &nomes, &medias);
    fclose(arquivo);

    for (int i = 0; i < n_alunos; i++) {
        printf("%s %.2f\n", nomes[i], medias[i]);
        free(nomes[i]);
    }

    free(nomes);
    free(medias);

    return 0;
}
