/*
Questão 1) Usando uma função recursiva, escreva um programa que leia uma sequência de valores
inteiros fornecidos pelo usuário via teclado e imprima a sequência em ordem inversa. Para sinalizar o final
da sequência de valores, o usuário entra com uma letra, forçando um erro de leitura de um valor inteiro.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void imprimeOrdemInversa (void) {
    int valor;
    printf("Insira um numero: ");
    int resultado = scanf("%d", &valor);

    if (resultado != 1) { 
        return;
    }

    imprimeOrdemInversa();
    printf("%d", valor);
}


/*
Questão 2) Implemente uma função que receba como parâmetros dois números inteiros n e k, e calcule o
coeficiente binomial C(n, k) correspondente, definido pela seguinte relação recursiva:
C(n, 0) = C(n, n) = 1 para n ≥ 0
C(n, k) = C(n − 1, k) + C(n − 1, k − 1) para n > k > 0
O protótipo dessa função deve ser:
int coeficiente (int n, int k);
*/

int coeficiente(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    return coeficiente(n - 1, k) + coeficiente(n - 1, k - 1);
}

/*
Questão 3) Escreva uma função recursiva que receba um número inteiro (n) e um algarismo (a), e "elimine"
o algarismo a do número n.
Exemplos:
Número 12342 e algarismo 2, o retorno da função é 134
Número 12342 e algarismo 5, o retorno da função é 12342
Número 2 e algarismo 2, o retorno da função é 0
*/

//12342
int eliminaAlgarismo(int num, int target) {
    int ultimo = num % 10;
    int resto = eliminaAlgarismo(num/10, target);
    if (ultimo == target){
        return resto;
    }
    return resto*10 + ultimo;
}


/*
Questão 4) Escreva uma função recursiva que recebe uma string (s) e um caractere (a), e retorne 1, se a
está presente em s, ou 0, caso contrário.
*/

//antonio
//o
int localizaEmString (char *string, char letra){
    if (string[0] == letra) {
        return 1;
    }

    if (string[0] == '\0'){
        return 0;
    }

    return localizaEmString(string + 1, letra);
}


/*
Questão 5) Escreva uma função recursiva que recebe uma string (s) e retorne o número de palavras
existentes nessa string. Considere que as palavras estão separadas por um espaço ou por uma vírgula.
*/

// carlos,o maior jogador
int contaPalavras (char *s) {
    if (s[0] == '\0'){
        return 0;
    }

    if (s[0] == ' ' || s[0] == ','){
        return contaPalavras(s + 1);
    }

    if (s[0] != ' ' && s[0] != ',' && (s[1] == ' ' || s[1] == ',' || s[1] == '\0')){
        return 1 + contaPalavras(s + 1);
    }

    return contaPalavras(s + 1);
}


/*
Questão 6) Escreva uma função recursiva que receba uma cadeia de caracteres como parâmetro e retorne
a cadeia invertida.
Exemplo:
Parâmetro recebido: 'Teste'
String retornada: 'etseT'
*/


char *retornaInvertida(char *string, char *ultimo, char *stringInicial){

    if (string >= ultimo) {
        return stringInicial;
    }

    char temp = *string;
    *string = *ultimo;
    *ultimo = temp;

    return retornaInvertida(string + 1, ultimo - 1, stringInicial);
}


typedef struct nolista NoLista;

struct nolista {
    int conteudo;
    NoLista *proximo;
};

NoLista *criaNo (int valor) {
    NoLista *novoNo = (NoLista *) malloc(sizeof(NoLista));
    if (novoNo == NULL) { return NULL;}
    novoNo->conteudo = valor;
    novoNo->proximo = NULL;
    return novoNo;
}

void insereNoFim (int valor, NoLista **head) {
    NoLista *novoNo = criaNo(valor);
    if (novoNo == NULL) {exit(1);}
    novoNo->proximo = *head;
    *head = novoNo;
    return;
}

int soma_lista(NoLista* no_atual){
    if (no_atual == NULL) {
        return 0;
    }
    return no_atua->conteudo + somaTodosOsNos(&no_atual->proximo);
}
int conta_pares(NoLista* no_atual){
    if (no_atual == NULL){
        return 0;
    }

    if (no->conteudo % 2 == 0) {
        return 1 + contaPares(&no_atual->proximo);
    }
    
    return contaPares(&no_atual->proximo);
}
int produto_lista(NoLista* no_atual){
    if (no_atual == NULL) {
        return 1;
    }
    return no_atual->conteudo * produtoLista(&no_atual->proximo);   
}

NoLista* copia_lista(NoLista* no_atual){
    NoLista novoNo = criaNo(no_atual->conteudo);
}

int main(void) {
    // imprimeOrdemInversa();
    // coeficiente(1, 2);
    // char antonio[] = "antonio";
    // printf("%d", localizaEmString(antonio, 'l'));
    // char frase[] = "antonio vive bem feliz, agradavel e contente";
    // int resultado = contaPalavras(frase);
    // printf("%d", resultado);

    // char *invertida = retornaInvertida(antonio, antonio + 6, antonio);
    // printf("%s", invertida);


    NoLista *head = criaNo(2);
    insereNoFim(3, &head);
    insereNoFim(4, &head);
    insereNoFim(5, &head);

    int soma = produtoLista(&head);
    printf("%d", soma);
    return 0;
}

