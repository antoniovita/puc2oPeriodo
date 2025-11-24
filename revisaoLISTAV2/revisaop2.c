/*
Questão 2) Implemente uma função que receba como parâmetros dois números inteiros n e k, e calcule o
coeficiente binomial C(n, k) correspondente, definido pela seguinte relação recursiva:
C(n, 0) = C(n, n) = 1 para n ≥ 0
C(n, k) = C(n − 1, k) + C(n − 1, k − 1) para n > k > 0
O protótipo dessa função deve ser:
int coeficiente (int n, int k);
*/


/*
Questão 3) Escreva uma função recursiva que receba um número inteiro (n) e um algarismo (a), e "elimine"
o algarismo a do número n.
Exemplos:
Número 12342 e algarismo 2, o retorno da função é 134
Número 12342 e algarismo 5, o retorno da função é 12342
Número 2 e algarismo 2, o retorno da função é 0
*/

#include <stdio.h>

int elimina_algarismos(int numero, int algarismo) {
    if (numero == 0) {return numero;}

    int ultimo_algarismo = numero % 10;
    int resto = elimina_algarismos(numero/10, algarismo);

    if (ultimo_algarismo != algarismo) {return ultimo_algarismo + resto*10;}
    return resto;
}

int main (void) {
    printf("%d", elimina_algarismos(12342, 2));
    return 0;
}


typedef struct no_lista {
    int valor;
    struct no_lista *proximo;
} NoLista;


NoLista *cria_lista (int valor) {
    NoLista *novo_no = (NoLista *) malloc(sizeof(NoLista));
    if (novo_no == NULL) {exit(1);}
    novo_no->proximo = NULL;
    novo_no->valor = valor;
    return novo_no;
}

void inserir_valor (int valor, NoLista *head) {
    NoLista *novo_no = cria_lista(valor);
    if(novo_no == NULL) {exit(1);}
    novo_no->valor = valor;

    if (head == NULL) {
        head = novo_no;
        return;
    }

    if (valor < head->valor) {
        novo_no->proximo = head;
        head = novo_no;
        return;
    }

    NoLista *atual = head;
    while(valor > atual->proximo->valor) {
        atual = atual->valor;
    }
    //vai parar em um antes do que é maior que o numero

    novo_no->proximo = atual->proximo;
    atual->proximo = novo_no;
    return;
}