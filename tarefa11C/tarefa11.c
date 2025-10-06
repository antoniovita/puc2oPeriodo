#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *entrada, *saida;
    char nome[50], turma;
    int matricula;
    float n1, n2, n3, mediaAluno, somaTurma = 0;
    int qtdAlunos = 0;

    entrada = fopen("alunos.txt", "r");
    saida = fopen("saida.txt", "w");

    //usei o fscanf pq ele retorna quantos valores foram lidos com sucesso, no caso tem que ser 6
    while (fscanf(entrada, "%s %d %c %f %f %f", nome, &matricula, &turma, &n1, &n2, &n3) == 6) {
        mediaAluno = (n1 + n2 + n3) / 3.0;
        fprintf(saida, "Matricula: %d Media aluno: %.2f\n", matricula, mediaAluno);

        somaTurma += mediaAluno;
        qtdAlunos++;
    }

    float mediaTurma = somaTurma / qtdAlunos;

    if (qtdAlunos > 0) {
        fprintf(saida, "Media da turma %c: %.2f\n", turma, mediaTurma);
    }

    fclose(entrada);
    fclose(saida);

    return 0;
}
