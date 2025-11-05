#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
char* concatenarInicioNovo(char* s1, char* s2) {
    int len1 = (int) strlen(s1);
    int len2 = (int) strlen(s2);
    int len3 = len1 + len2 + 1;

    char *retorno = malloc(sizeof(char) * len3);
    if(!retorno) { printf("Deu merda rapaz"); exit(1);}

    int i;
    for (i = 0; i < len1; i++) {
        *(retorno + i) = *(s1 + i);
    }

    for (int j = 0; j < len2; j++) {
        *(retorno + i) = *(s2 + j);
        i++;
    }

    *(retorno + len1 + len2) = '\0';

    return retorno;
}

int main (void) {
    char s1[] = "Os judeus são ";
    char s2[] = "os verdadeiros donos do Levante.";
    char *resposta = concatenarInicioNovo(s1, s2);
    printf("%s", resposta);
    free(resposta);
    return 0;
}   
*/

/*
*/

char** vetorNomes(const char* nomeArq, int* nreg) {
    FILE *arquivo = fopen(nomeArq, "r");
    if (!arquivo) {printf("Arquivo nao encontrado.");exit(1);}

    fscanf(arquivo, "%d\n", nreg);

    char **vetor = malloc(sizeof(char *) * (*nreg));
    if(!vetor) { printf("Erro ao alocar memoria."); exit(1);}

    for (int i = 0; i < *nreg; i++){
        char data[11];

        char *nome = malloc(sizeof(char) * 81);
        if (!nome) {printf("Erro ao alocar memoria."); free(vetor); exit(1);}

        fscanf(arquivo, "%s %[^\n]\n", data, nome);
        vetor[i] = nome;
    }

    return vetor;
}

int main(void) {
    char nomeArq[] = "entradas.txt";
    int nreg;
    char **vetor_resposta = vetorNomes(nomeArq, &nreg);
    
    for (int i = 0; i < nreg; i++) {
        printf("[");
        printf("%s, ", vetor_resposta[i]);
        printf("]");
        free(vetor_resposta[i]);
    }
    free(vetor_resposta);
    return 0;
}

/*
float** criaMatrizQuadrada(int dim) {
    float **matriz = malloc(sizeof(float *) * dim);
    if(!matriz) return NULL;

    for (int i = 0; i < dim; i++) {
        matriz[i] = malloc(sizeof(float) * dim);
        if(!matriz[i]) {free(matriz); return NULL;}
    }

    return matriz;
}

float** diagonal(float** matriz, int dim, float valor){
    for (int i = 0; i < dim; i++){
        matriz[i][i] = valor;
    }

    return matriz;
}

void imprimeMatriz(float** matriz, int dim){
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++){
            printf("%.0f  ", matriz[i][j]);
        }
        printf("\n");
    }
    return;
}

int main (void) {
    int dim = 4;
    int valor = 1;
    float **matriz = criaMatrizQuadrada(dim);
    if (matriz == NULL) {
        printf("Erro na alocação da memória.");
        exit(1);
    }
    float **matriz_digonal = diagonal(matriz, dim, valor);
    imprimeMatriz(matriz_digonal, dim);
    return 0;
}
*/
