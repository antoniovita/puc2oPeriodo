/* 


INF 1037 - Programação em C - Turmas 33A - 22/09/2025
Profa. Paula Rodrigues
Tarefa 09 - Strings (Caracteres e Cadeia de Caracteres)
Escolha uma das questões abaixo para submeter como tarefa 09.
Questão 01) Implemente uma função que receba como parâmetros uma cadeia de caracteres (string) e um caractere
c, e retorne o número de ocorrências do caractere dentro da cadeia. Por exemplo, se forem passados para a função a
cadeia “Rio de Janeiro” e o caractere ‘i’
, a função deve retornar o valor 2. A função deve obedecer ao protótipo a
seguir:
int conta
ocorrencias (char* s, char c);
_
Faça uma main para testar a sua função, recebendo tanto a string como o caractere como parâmetros de leitura,
fornecidos pelo usuário.
Questão 02) Implemente uma função que receba uma string como parâmetro e retorno como resultado o número de
vogais nesta string. Essa função deve obedecer ao protótipo:
int conta
vogais (char* s);
_
Faça uma main para testar a sua função, recebendo a string como parâmetro de leitura, fornecido pelo usuário.

Questão 03) Implemente uma função que receba uma string como parâmetro e altere nesta string as ocorrências de
caracteres maiúsculos para minúsculos. Essa função deve obedecer ao protótipo:
void minusculo (char* s);
Faça uma main para testar a sua função, recebendo a string como parâmetro de leitura, fornecido pelo usuário.


*/


/*

Questão 1) 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//string usa aspas duplas, char aspas simples

int conta_ocorrencias (char* s, char c) {
    int cont = 0;
    int len = strlen(s);


    for (int i = 0; i < len; i++) {
        if (s[i] == c) {
            cont = cont + 1;
        }
    }

    return cont;
}

int main(void) {
    char rio[] = "Rio de Janeiro";
    int contagem = conta_ocorrencias(rio, 'o');
    printf("%d\n", contagem);
    return 0;
}

*/


/*
Questão 2)

#include <string.h>
#include <stdio.h>

int conta_vogais (char* s) {
    int cont = 0;
    char vogais[] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    int len = strlen(s);

    for (int i = 0; i < len; i ++) {
        for (int j = 0; j < 10; j++) {
            if (s[i] == vogais[j]) {
                cont++;
            }
        }
    }
    return cont;
}

int main (void) {
    char rio[] = "Rio de Janeiro";
    int num_vogais = conta_vogais(rio);
    printf("%d", num_vogais);
    return 0;
}
*/



/*
Questão 3)

#include <stdio.h>
#include <ctype.h>
#include <string.h>


void minusculo (char* s){
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        s[i] = tolower(s[i]);
    }
}

int main (void) {
    char rio[] = "Rio de Janeiro \n";
    printf("%s", rio);

    minusculo(rio);
    printf("%s", rio);

    return 0;
}
*/