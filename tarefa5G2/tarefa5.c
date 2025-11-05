#include <stdio.h>

int main(void) {
    char nome[81];
    float notas[3];

    FILE *f = fopen("alunos.dat", "wb");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        printf("Nome do aluno %d: ", i + 1);
        scanf(" %80[^\n]", nome);

        printf("Digite as 3 notas: ");
        for (int j = 0; j < 3; j++) {
            scanf("%f", &notas[j]);
        }

        fwrite(nome, sizeof(char), 81, f);
        fwrite(notas, sizeof(float), 3, f);
    }

    fclose(f);
    printf("Arquivo 'alunos.dat' criado com sucesso!\n");
    return 0;
}
