#include <stdio.h>
#include <stdlib.h>   
#include <string.h> 

char** split(char* codigo) {
    if (codigo == NULL) {
        printf("Erro: codigo nulo.\n");
        exit(1);
    }

    int len_total = strlen(codigo);
    if (len_total < 12) {
        printf("Erro: codigo muito curto (%d caracteres, precisa de >= 12).\n", (int)len_total);
        exit(1);
    }

    char **ret = malloc(4 * sizeof(char*));
    if (ret == NULL) {
        printf("Erro ao alocar vetor de strings.\n");
        exit(1);
    }

    int partes[4] = {3, 4, 2, 3};
    int pos = 0;

    for (int i = 0; i < 4; i++) {
        int tam = partes[i];

        ret[i] = malloc((tam + 1) * sizeof(char));
        if (ret[i] == NULL) {
            printf("Erro ao alocar parte %d.\n", i);
            exit(1);
        }

        memcpy(ret[i], codigo + pos, tam);
        ret[i][tam] = '\0'; 

        pos += tam;
    }

    return ret;
}

void libera_partes(char **partes) {
    for (int i = 0; i < 4; i++) {
        free(partes[i]);
    }
    free(partes);
}

int main(void) {
    char codigo[256];

    printf("Digite o codigo do produto (ex.: NIKMOCHUNPRE): ");
    scanf("%255s", codigo);

    char **partes = split(codigo);

    printf("\nCodigo: %s\n", codigo);
    printf("Fabricante: %s\n", partes[0]);
    printf("Produto:    %s\n", partes[1]);
    printf("Tamanho:    %s\n", partes[2]);
    printf("Cor:        %s\n", partes[3]);

    libera_partes(partes);

    return 0;
}
