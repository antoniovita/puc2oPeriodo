/*
Questão única) Vamos criar um programa para gerenciar as notas de um número fixo de alunos. O
programa deve calcular a média de cada aluno usando uma função e identificar qual aluno obteve o melhor
desempenho (maior média). Para tal vamos criar uma estrutura chamada Aluno que deve conter os
seguintes campos: matricula (inteiro), nome (string com até 50 caracteres), nota1 (float), nota2 (float)
e nota3 (float).
Adicionalmente, vamos ter, por exemplo, um vetor de alunos, por exemplo, Aluno turma[5];
Sua função que calcula média tem a seguinte assinatura: float calcula
media(struct Aluno a);
_
Seu programa deve popular o vetor de alunos lendo do teclado as informações de matricula, nome e as
nota de cada aluno. Para cada aluno, deve ser exibido como saída o nome e a media. Por fim, seu
programa deve exibir as informações do aluno que teve o melhor desempenho: nome, matricula e media
final.
*/

#include <stdio.h>

struct Aluno {
    int matricula;
    char nome[51];
    float nota1;
    float nota2;
    float nota3;
};

float calcula_media(struct Aluno aluno){
    return (aluno.nota1 + aluno.nota2 + aluno.nota3)/3.0f;
}


int main (void) {

    int num_alunos;
    printf("Insira a quantidade de alunos:");
    scanf("%d", &num_alunos);

    struct Aluno turma[num_alunos];


    for (int i = 0; i < num_alunos; i++) {
        printf("Insira a matricula do aluno:");
        scanf("%d", &turma[i].matricula);

        printf("Insira o nome do aluno:");
        scanf(" %[^\n]", turma[i].nome);

        printf("Insira a primeira nota do aluno:");
        scanf("%f", &turma[i].nota1);

        printf("Insira a segunda nota do aluno:");
        scanf("%f", &turma[i].nota2);

        printf("Insira a terceira nota do aluno:");
        scanf("%f", &turma[i].nota3); 
        
        printf("\n");
    }
    
    float medias[num_alunos];

    for (int i = 0; i < num_alunos; i++) {
        medias[i] = calcula_media(turma[i]);
    }

    int indice_maior = 0;
    for (int i = 0; i < num_alunos; i++){
        if (medias[i] > medias[indice_maior]){
            indice_maior = medias[i];
        }
    }

    printf("O aluno com a maior media eh o %s e a sua media eh %f", turma[indice_maior].nome, medias[indice_maior]);
}