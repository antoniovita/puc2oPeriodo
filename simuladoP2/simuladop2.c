#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum sit_ac Situacao_academica;

typedef struct aluno Aluno;

enum sit_ac {
    AT /* TRANCAMENTO */,
    AP /* APROVADO */,
    RF /* RECUPERAÇÃO */
};

struct aluno {
    char* nome;
    int matricula;
    float notas[3];
    Situacao_academica situacao;
    float media;
    Aluno* proximo;
};


/*
1) Implemente a função carregar
dados. Ela deve ler todos os N alunos. Para cada aluno
lido, deve-se inseri-lo na lista da turma, onde a ordem não importa. Todos os alunos utilizam
o tamanho exato de seus nomes na memória alocada.
Aluno* carregar_dados(FILE* arquivo);

//Lucas Almeida: 2411018 8.5 7.9 9.0
*/

Aluno* carregar_dados(FILE* arquivo){
    char nome_buffer[121];
    int matricula;
    float p1;
    float p2;
    float p3;

    Aluno *head = NULL;
    while( fscanf(arquivo, " %120[^:]: %d %f %f %f", nome_buffer, &matricula, &p1, &p2, &p3) == 5) {
        Aluno *novo_no = (Aluno *)malloc(sizeof(Aluno));
        if (novo_no == NULL) {exit(1);}
        novo_no->proximo = head;
        
        novo_no->matricula = matricula;
                
        novo_no->nome = malloc(sizeof(char) * (strlen(nome_buffer) + 1));
        strcpy(novo_no->nome, nome_buffer);

        novo_no->notas[0] = p1;
        novo_no->notas[1] = p2;
        novo_no->notas[2] = p3;
    
        head = novo_no;
    }

    return head;
}

/*
3) Implemente a função calcular_final. Calcule com essa função a nota necessária para a
G4 das pessoas que estiverem com a situação como RF e a chame dentro da função
avaliar
situacao.*/


float calcular_final(Aluno* aluno){
    float vet[3] = {aluno->notas[0], aluno->notas[1], aluno->notas[2]};


    for (int i = 1; i < 3; i++) {
        if (vet[i-1] < vet[i]){
            float buffer = vet[i];
            vet[i] = vet[i - 1];
            vet[i - 1] = buffer;
        }
    }

    return (25.0f - (vet[0] + vet[1]))/3.0f;
}



/*
2) Implemente a função avaliar_situacao. Essa função deve percorrer toda a lista e, para
cada aluno, deve preencher os campos situacao e média de acordo com os critérios:

1. Trancamento de matéria: situação (AT) e média = 0.0
Se qualquer aluno trancar uma matéria, suas notas dos graus não concluídos serão
preenchidos no entrada.txt com -1.0.
Se G1, G2 e G3 >= 3.0 e (G1+G2+G3) / 3 >= 5.0
Caso contrário, média = (G1+2*G2+3*G3) / 6 >= 6.0
Se média < 6.0, haverá G4:
Gm e Gn, dado as 2 maiores notas dos 3 graus:
(Gm + Gn + 3*G4) / 5 >= 5.0

2. Aprovado: situação (AP)
Calcule a média do aluno e preencha o nó da lista referente ao aluno.

3. Recuperação final: (RF)
Não sendo capaz de cumprir sua média sem G4, chame a função calcular_final e a preencha no campo média.
*/


void avaliar_situacao (Aluno *head) {
    Aluno *atual = head;

    while( atual != NULL){
        
        if (atual->notas[0] < 0.0f || atual->notas[1] < 0.0f || atual->notas[2] < 0.0f) {
            atual->situacao = AT;
            atual->media = 0.0f;
            atual = atual->proximo;
            continue;
        } else if (atual->notas[0] >= 3 && atual->notas[1] >= 3 && atual->notas[2] >= 3 && (atual->notas[0] + atual->notas[1] + atual->notas[2])/3 >= 5) {
            atual->media = (atual->notas[0] + atual->notas[1] + atual->notas[2])/3; 
            atual->situacao = AP;
        } else {
            atual->media = (atual->notas[0] + 2.0f*atual->notas[1] + 3.0f*atual->notas[2])/6; 
            if (atual->media >= 6){
                atual->situacao = AP;
            } else {
                atual->situacao = RF;
                atual->media = calcular_final(atual);
            }
        }
        atual = atual->proximo;
    }

    return;
}


/*
4) Implemente a função liberar
turma
_
_
rec recursivamente. Atenção, toda memória utilizada
pelos Alunos deve ser liberada, incluindo seus nomes.
*/

void liberar_turma_rec (Aluno *head) {
    if (head == NULL) {return;}
    liberar_turma_rec(head->proximo);
    free(head->nome);
    free(head);
}
1
/*
5) Implemente a função salvar_relatório. Essa função deve escrever os dados da turma em
dois arquivos, relatorio.bin e saida.txt, no formato abaixo. Ela deve retornar 0 para erro e 1
para sucesso.
*/

int salvar_relatório (Aluno *head) {
    FILE *arquivo_binario = fopen("relatorio.bin", "wb");
    if (arquivo_binario == NULL) {
        return 0;
    }

    FILE *arquivo_texto = fopen("saida.txt", "w");
    if (arquivo_texto == NULL) {
        fclose(arquivo_binario);
        return 0;
    }

    char f1[] = "--Relatorio turma antes da G4--\n";
    fprintf(arquivo_texto, f1);
    fwrite(f1, 1, (strlen(f1) + 1), arquivo_binario);

    char f2[] = "Trancamento da Materia:\n";
    fprintf(arquivo_texto, f2);
    fwrite(f2, 1, (strlen(f2) + 1), arquivo_binario);

    Aluno *atual = head;
    while (atual != NULL) {
        if (atual->situacao == AT) {
            char f3[] = 
            fprintf(arquivo_texto, "- %s: (%d)\n", atual->nome, atual->matricula);
            fprintf(arquivo_binario, "- %s: (%d)\n", atual->nome, atual->matricula);
        }
        atual = atual->proximo;
    }

    fprintf(arquivo_texto, "Aprovados:\n");
    fprintf(arquivo_binario, "Aprovados:\n");

    atual = head;
    while (atual != NULL) {
        if (atual->situacao == AP) {
            fprintf(arquivo_texto, "- %s: (%d)\n", atual->nome, atual->matricula);
            fprintf(arquivo_binario, "- %s: (%d)\n", atual->nome, atual->matricula);
        }
        atual = atual->proximo;
    }

    fprintf(arquivo_texto, "Recuperacao:\n");
    fprintf(arquivo_binario, "Recuperacao:\n");

    atual = head;
    while (atual != NULL) {
        if (atual->situacao == RF) {
            fprintf(arquivo_texto, "- %s: (%d)\n", atual->nome, atual->matricula);
            fprintf(arquivo_binario, "- %s: (%d)\n", atual->nome, atual->matricula);
        }
        atual = atual->proximo;
    }

    fclose(arquivo_texto);
    fclose(arquivo_binario);

    return 1;
}
