/*
Questão 1) Implemente um programa para criar um arquivo binário para armazenar o cadastro de 5
alunos. Cada registro no arquivo deve ter:
Nome representado por uma cadeia de caracteres de 80 caracteres (ocupando 81 bytes no
arquivo para armazenar também o ‘\0’)
Notas representadas por 3 valores do tipo float.
Você pode assumir a estão .dat para seu arquivo binário de saída.
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
    char nome[81];
    float notas[3];
} Aluno;
/*
int main(void) {
    FILE *arquivo;
    Aluno alunos[5];

    arquivo = fopen("alunos.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        printf("Aluno %d\n", i + 1);
        printf("Nome: ");
        scanf("%s", alunos[i].nome);

        for (int j = 0; j < 3; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &alunos[i].notas[j]);
        }
        printf("\n");
    }

    fwrite(alunos, sizeof(Aluno), 5, arquivo);

    fclose(arquivo);

    printf("Arquivo 'alunos.dat' criado com sucesso!\n");

    return 0;
}
*/

/*
Questão 2) Implemente um outro programa para capturar um valor inteiro fornecido pelo usuário (de
0 a 4), representando o registro. Lendo o arquivo binário criado na questão anterior, exiba o nome do
aluno e sua média, correspondente ao número do registro.
*/

int main (void) {
    FILE * arquivo = fopen("alunos.dat", "rb");
    Aluno lista_alunos[5];
    fread(&lista_alunos, sizeof(Aluno), 5, arquivo);
    for (int i = 0; i < 4; i ++) {
        printf("Nome: %s\n", lista_alunos[i].nome);
        float media = (lista_alunos[i].notas[0] + lista_alunos[i].notas[1] + lista_alunos[i].notas[2])/3;
        printf("Média: %f\n", media);
    }

    return 0;
}