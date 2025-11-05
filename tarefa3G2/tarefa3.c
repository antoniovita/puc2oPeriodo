#include <stdio.h>

typedef struct aluno {
    char nome[81];
    char matricula[8];
    char turma;
    float p1;
    float p2;
    float p3;
} Aluno;

float media_turma(int n, Aluno alunos[], char turma) {
    float soma_media = 0.0;
    int contador = 0;

    for (int i = 0; i < n; i++) {
        if (alunos[i].turma == turma) {
            float media_aluno = (alunos[i].p1 + alunos[i].p2 + alunos[i].p3) / 3.0;
            soma_media += media_aluno;
            contador++;
        }
    }

    if (contador == 0) return 0.0;
    return soma_media / contador;
}

int main(void) {
    int n = 5;
    Aluno alunos[n];
    char turma_desejada;

    for (int i = 0; i < n; i++) {
        printf("\nCadastrando aluno %d:\n", i + 1);

        printf("Nome: ");
        scanf(" %80s", alunos[i].nome);

        printf("Matricula: ");
        scanf(" %7s", alunos[i].matricula);

        printf("Turma (uma letra): ");
        scanf(" %c", &alunos[i].turma);

        printf("Nota da P1: ");
        scanf("%f", &alunos[i].p1);

        printf("Nota da P2: ");
        scanf("%f", &alunos[i].p2);

        printf("Nota da P3: ");
        scanf("%f", &alunos[i].p3);
    }

    printf("\nDigite a turma desejada para calcular a média: ");
    scanf(" %c", &turma_desejada);

    float media_final = media_turma(n, alunos, turma_desejada);
    printf("\nMédia final da turma %c: %.2f\n", turma_desejada, media_final);

    return 0;
}
