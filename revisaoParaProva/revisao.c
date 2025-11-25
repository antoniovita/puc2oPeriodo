/*
Questão 01) Crie um tipo estruturado para representar um aluno com as seguintes informações:
Nome completo (string com até 80 caracteres)
Número de matrícula (valor inteiro)
Notas P1, P2 e P3 (valores float)
Crie uma função que recebe um nome de um arquivo texto onde a lista de alunos está armazenada. O
arquivo tem um número inteiro inicial que indica quantos alunos são listados. Em seguida, cada linha do
arquivo tem as informações:
Nome completo: matricula P1 P2 P3
Sua função deve retornar um vetor de alunos criado dinamicamente, com as informações do arquivo,
seguindo o protótipo:

onde pn deve ser preenchido com o número de alunos existentes no vetor.
*/

#include <stdio.h>

typedef struct aluno Aluno;
struct aluno {
    char nome_completo[81];
    int matricula;
    float notas[3];
};

// Nome completo: matricula P1 P2 P3
Aluno* leia_arquivo (char* nome_arquivo, int* pn){
    FILE *arquivo = fopen(nome_arquivo, "r");
    fscanf(arquivo, " %d", pn);
    Aluno *vet = (Aluno*) malloc(sizeof(Aluno) * (*pn));

    char nome_buffer[81];
    int matricula_buffer;
    float p1;
    float p2;
    float p3;
    for (int i = 0; i < *pn; i++){
        fscanf(arquivo, " %81[^:]: %d %f %f %f", nome_buffer, &matricula_buffer, &p1, &p2, &p3);
        vet[i].matricula = matricula_buffer;
        strcpy(vet[i].nome_completo, nome_buffer);
        vet[i].notas[0] = p1;
        vet[i].notas[1] = p2;
        vet[i].notas[2] = p3;
    }
    return vet;
}

