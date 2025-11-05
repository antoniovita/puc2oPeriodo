/*
Questão 01) Escreva uma única função que recebe um vetor de inteiros e calcula duas somas: a soma dos
valores pares e a soma dos valores ímpares. Além do vetor e da quantidade inteiros no vetor, a função deve
receber ponteiros de variáveis onde as somas serão armazenadas.

#include <stdio.h>

void soma(int *vetor_inteiros, int len, int *soma_par, int *soma_impar){
    for (int i = 0; i < len; i++){
        if ( vetor_inteiros[i] % 2 == 0) {
            *soma_par += vetor_inteiros[i];
        } else {*soma_impar += vetor_inteiros[i];}
    }
    return;
}

int main (void) {
    int soma_par = 0;
    int soma_impar = 0;

    int vetor_inteiros[] = {1, 2, 3, 4, 5};
    int len = sizeof(vetor_inteiros)/sizeof(vetor_inteiros[1]);
    
    soma(vetor_inteiros, len, &soma_par, &soma_impar);

    printf("Soma par: %d \n Soma impar: %d", soma_par, soma_impar);

    return 0;
}
*/


/*
Questão 02) Escreva uma única função que aceita como parâmetros um vetor de inteiros v com n valores,
onde v e n são parâmetros da função, e determina o menor elemento do vetor e o número de vezes que este
elemento ocorreu no vetor. Por exemplo, para um vetor com os seguintes elementos: 5, 2, 15, 3, 7, 2, 15, 8,
6, 15, a função terá como resultado o número 2 e o valor 2 (indicando que 2 é o menor número do vetor e que
o mesmo ocorreu 2 vezes). O valor mínimo e a quantidade de vezes devem ser informados em ponteiros
também recebidos como parâmetros na função.

#include <stdio.h>

void menor_valor (int *v, int n, int *valor_minimo, int *quantidade_vezes) {
    *valor_minimo = v[0];
    for (int i = 1; i < n; i ++) {
        if (*valor_minimo > v[i]){
            *valor_minimo = v[i];
            *quantidade_vezes = 1;
        } else if ( *valor_minimo == v[i]) {
            (*quantidade_vezes)++;
        }
    }

    return;
}

int main (void) {
    int v[] = {5, 2, 15, 3, 7, 2, 15, 8, 6, 15};
    int n = sizeof(v)/sizeof(v[1]);
    int valor_minimo, quantidade_vezes;

    menor_valor(v, n, &valor_minimo, &quantidade_vezes);

    printf("O valor mínimo é %d e a quantidade de vezes que apareceu é %d.", valor_minimo, quantidade_vezes);
    return 0;
}
*/

/*
Questão 03) Escreva uma única função que calcula a média aritmética e a média ponderada de um vetor de
float de tamanho qualquer. Além do vetor com os valores, a função recebe um segundo vetor com os pesos
da média ponderada. Ambas as médias devem ser passadas como parâmetros da função a serem
preenchidos.

#include <stdio.h>

void medias (float *vetor, int tamanho, float *pesos, float *media_ponderada, float *media_aritmetica){
    float soma = 0;
    float soma_ponderada = 0;
    float soma_pesos = 0;

    for (int i = 0; i < tamanho; i++){
        soma_ponderada += pesos[i] * vetor[i];
        soma += vetor[i];
        soma_pesos += pesos[i];
    }

    *media_ponderada = soma_ponderada/soma_pesos;
    *media_aritmetica = soma/tamanho;
    return;
}

int main (void) {
    float vetor[] = {9, 8, 10};
    float pesos[] = {1, 2, 3};
    float media_ponderada, media_aritmetica;
    int tamanho = sizeof(vetor)/sizeof(vetor[0]);

    medias(vetor, tamanho, pesos, &media_ponderada, &media_aritmetica);

    printf("A media ponderada eh %.2f e a media aritmetica eh %.2f", media_ponderada, media_aritmetica);
}
*/

/*
Questão 04) Escreva uma função que recebe um vetor de inteiros e retorna um novo vetor, alocado
dinamicamente, eliminando os elementos repetidos em sequência. Por exemplo, dado {1,2,2,1,4,5,6,6,5} , a
função deve criar o vetor {1,2,1,4,5,6,5}. A função deve retornar o novo vetor e receber um parâmetro para
preencher a quantidade de elementos inseridos no novo vetor.

#include <stdio.h>
#include <stdlib.h>

int *vetor_sem_rep (int *vetor_inteiros, int len){

    int *novo_vetor = malloc(sizeof(int) * len);
    if (!novo_vetor) {printf("Erro na alocação de memoria."); exit(1);}

    int j = 1;
    novo_vetor[0] = vetor_inteiros[0];
    for (int i = 1; i < len; i++){
        if (vetor_inteiros[i] != vetor_inteiros[i - 1]){
            novo_vetor[j++] = vetor_inteiros[i];
        } 
    }

    return novo_vetor;
}

int main (void) {
    int vetor[] = {1,2,2,1,4,5,6,6,5};
    int len = sizeof(vetor)/sizeof(vetor[0]);

    int *novo_vetor = vetor_sem_rep(vetor, len);
    printf("{");

    for (int i = 0; i < len; i++){
        printf("%d,", novo_vetor[i]);
    }
    printf("}");
    free(novo_vetor);

    return 0;
    
}
*/

/*
Questão 05) Escreva uma função para criar uma nova cadeia de caracteres sem repetição em sequência dos
caracteres de uma cadeia fornecida. Por exemplo, dado "AAnnnaa", a função cria e retorna a cadeia "Ana".


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *sem_rep(char *original){
    int len = (int) strlen(original);
    char *retorno = (char *) malloc(sizeof(char) * len);

    int j = 1;
    retorno[0] = original[0];
    for (int i = 1; i < len; i++) {
        if (original[i] != original[i - 1]){
            retorno[j++] = original[i];
        }
    }

    return retorno;
}

int main (void) {
    char original[] = "AAnnnaa";
    char *novo = sem_rep(original);

    printf("%s", novo);
    return 0;
}
*/

/*
Questão 06) Escreva uma função que recebe duas strings e retorna se a segunda é prefixo da primeira.
Retorne 1 se for prefixo e 0 caso contrário. Considere que uma string vazia é prefixo da outra. Considere
também que duas strings iguais são prefixo uma da outra.

#include <stdio.h>
#include <string.h>

int prefixo(char *string1, char *string2){
    int len2 = (int) strlen(string2);
    if (strncmp(string1, string2, len2) == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main (void) {
    char string1[] = "Antonio";
    char string2[] = "Ant";
    int resultado = prefixo(string1, string2);
    printf("%d", resultado);
    return 0;
}
*/

/*
Questão 07) Escreva uma função que dado um nome, retorna uma nova cadeia com o último sobrenome.
Por exemplo, dado "Carlos Drumond de Andrade", a nova cadeia deve ser "Andrade".
*/




/*
Questão 08) Escreva uma função que recebe um vetor de strings com nomes de pessoas e retorne um novo
vetor de strings, alocado dinamicamente, onde cada elemento, também alocado dinamicamente, é o primeiro
nome de cada pessoa. Por exemplo, se for passado para a função o vetor {"Alberto Einsten", "Leonardo da
Vinci", "Alan Turing"}, sua função deve retornar o vetor {"Alberto", "Leonardo", "Alan"}.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **nome_simples (char **original, int n) {
    char **retorno = (char **) malloc(n * sizeof(char *));
    for (int i = 0; i < n; i ++) {
        int j = 0;
        while(original[i][j] != ' ') {
            j++;
        }

        retorno[i] = malloc((j - i) * sizeof(char));

        strncpy(retorno[i], original[i], j);
    }


    return retorno;
}

void libera_vetor_primeiro_nome(char **vetor, int len) {
    for (int i = 0; i < len; i++) {
        free(vetor[i]);
    }

    free(vetor);
}


int main(void) {
    char *vetor[] = {"Alberto Einstein", "Leonardo da Vinci", "Alan Turing"};
    int len = sizeof(vetor) / sizeof(vetor[0]);
    char **resultado = nome_simples(vetor, len);

    for (int i = 0; i < len; i++) {
        printf("%s\n", resultado[i]);
    }

    libera_vetor_primeiro_nome(resultado, len);

    return 0;
}
*/

/*
Questão 10) Escreva uma função que recebe um vetor de inteiros v e a quantidade de elementos n nesse
vetor e cria um vetor de ponteiros para char, contendo strings com a seguinte regra de formação. Se v[i] for
par, a string deverá conter v[i] vezes a letra ‘A’. Por outro lado, se v[i] for ímpar, a string deverá conter v[i]
1
vezes a letra ‘a’. Como exemplo, para um vetor de entrada v = { 2, 4, 3, 1 }, é esperado que seja criado
dinamicamente um vetor de char* contendo as strings “AA”, “AAAA”, “aaa” e “a”.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** converte (int * v , int n){
    char ** retorno = malloc(n * sizeof(char *));
    if (!retorno) { printf("Erro."); exit(1);}
    char letra;

    for (int i = 0; i < n; i++) {

        if (v[i] % 2 == 0) {
            letra = 'A';
        } else { 
            letra = 'a';
        }

        retorno[i] = malloc( (v[i] + 1) * sizeof(char));
        int j = 0;
        while (j < v[i]) {
            retorno[i][j++] = letra;
        }
        retorno[i][v[i]] = '\0';
    }

    return retorno;
}

int main (void) {
    int vetor[] = { 2, 4, 3, 1 };
    int len = sizeof(vetor)/sizeof(vetor[0]);

    char ** convertido = converte(vetor, len);

    for (int i = 0; i < len; i++){
        printf("%s, ", convertido[i]);
        free(convertido[i]);
    }

    free(convertido);
    return 0;
}
*/

/*
Questão 11) Implemente uma função que recebe como parâmetros dois vetores de inteiros, v1 e v2, e as
suas respectivas quantidades de elementos, n1 e n2. A função também deve receber um terceiro vetor v3,
com capacidade para (n1 + n2) elementos. Sua função deverá inserir os elementos de v1 e v2 em v3 de modo
intercalado. Por exemplo, se v1 = {1, 3, 5, 7} e v2 = {2, 4, 6, 8, 10, 12}, v3 irá conter {1, 2, 3, 4, 5, 6, 7, 8, 10,
12}. Observe que dependendo do número de elementos, os últimos valores podem não ficar intercalados.

#include <stdio.h>

void intercala(int* v1, int n1, int* v2, int n2, int* v3){
    int i1 = 0;
    int i2 = 0;
    int idx = 0;

    while (i1 < n1 || i2 < n2) {

        if (i1 < n1 && i2 < n2) {
            v3[idx++] = v1[i1++];
            v3[idx++] = v2[i2++];
        } else if ( i1 < n1) {
             v3[idx++] = v1[i1++];
        } else {
            v3[idx++] = v2[i2++];
        }
    }

    return;
}

int main(void) {
    int v1[] = {1, 3, 5, 7};
    int v2[] = {2, 4, 6, 8, 10, 12};
    int n1 = sizeof(v1) / sizeof(v1[0]);
    int n2 = sizeof(v2) / sizeof(v2[0]);
    int v3[n1 + n2];

    intercala(v1, n1, v2, n2, v3);

    for (int i = 0; i < n1 + n2; i++) {
        printf("%d%c", v3[i], (i + 1 == n1 + n2) ? '\n' : ' ');
    }
    return 0;
}
*/


/*
Questão 13) Escreva uma função que verifica se uma string é um palíndromo e retorna 1 se for ou 0, caso
não seja. Uma palavra palíndroma é aquela cuja sequência de letras é simétrica, permitindo uma leitura
idêntica da esquerda para a direita ou da direita para a esquerda: ovo, osso, reler, anilina
int palindromo(char* texto);

#include <stdio.h>
#include <string.h>

int palindromo(char* texto){
    int i = 0;
    int f = (int) strlen(texto) - 1;
    while (i != f){
        if (texto[i] != texto[f]){
            return 0;
        }
        i++;
        f--;
    }
    return 1;
}

int main (void) {
    char ovo[] = "ovo";
    int resultado = palindromo(ovo);
    printf("\n%d\n", resultado);
    return 0;
}
*/

/*
Questão 14) Escreva uma função que recebe um vetor de palavras (strings) e uma palavra (string) e retorna
o índice do vetor em que a palavra esteja. Se a palavra não for encontrada, a função deve retornar -1.

#include <stdio.h>
#include <string.h>

int acha_palavra(char** vetor_palavras, char* palavra, int n){
    int len_palavra = (int) strlen(palavra);
    for (int i = 0; i < n; i++) {
        int len_atual = (int) strlen(vetor_palavras[i]);
        if (len_palavra != len_atual){
            continue;
        } else {
            for (int j = 0; j < len_palavra; j++){
                if (vetor_palavras[i][j] != palavra[j]) {
                    break;
                }
            }
            return i;
        }
    }
    return -1;
}

int main (void) {
    char *vetor[] = {"ovo", "antonio", "bola"};
    int n = sizeof(vetor)/sizeof(vetor[0]);
    char *palavra = "bola";
    int resultado = acha_palavra(vetor, palavra, n);
    printf("%d", resultado);
    return 0;
}
*/

/*
Questão 15) Escreva uma função que inverte uma string sem criar uma cópia da string original. Se sua função
receber a string “pontificia”, a string original deve ser alterada para passar a ser “aicifitnop”.

#include <string.h>
#include <stdio.h>

void inverte_string (char *string) {
    int i = 0;
    int f = (int) strlen(string) - 1;

    while (i < f) {
        char temp = string[i];
        string[i] = string[f];
        string[f] = temp;
        i++;
        f--;
    }

    return;
}

int main(void) {
    char str[] = "Antonio";
    inverte_string(str);
    printf("%s\n", str);
    return 0;
}
*/

/*
Questão 16) Considere strings que contém o nome completo e a data de nascimento de uma pessoa,
separadas por dois pontos. Exemplos dessas strings são mostradas abaixo:
“Leonardo da Vinci: 15/04/1452”
“Albert Einstein: 14/03/1879”
Escreva uma função que recebe uma string nesse formato e retorne uma nova string, alocada dinamicamente,
que representa um login de usuário. O login deve ser formado pelas iniciais do nome (em letras minúsculas),
seguido de dois pontos, seguido do ano de nascimento. Por exemplo, para as strings acima, sua função deve
retornar “ldv:1452” e “ae:1879”, respectivamente.

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *cria_login(char *string) {
    int len = (int) strlen(string);

    char *barra = strrchr(string, '/');
    char ano[5];
    strncpy(ano, barra + 1, 4);
    ano[4] = '\0';

    int qtd_palavras = 1;
    for (int i = 0; i < len; i++) {
        if (isspace(string[i])) {
            qtd_palavras++;
        }
    }

    char *iniciais = malloc(sizeof(char) * (qtd_palavras + 1 + 4 + 1));
    if (!iniciais) return NULL;

    iniciais[0] = tolower(string[0]);
    int idx_atual = 1;
    for (int i = 0; i < len; i++) {
        if (isspace(string[i])) {
            iniciais[idx_atual++] = tolower(string[i + 1]);
        }
    }

    iniciais[idx_atual++] = ':';
    strcpy(iniciais + idx_atual, ano);

    return iniciais;
}

int main() {
    char nome1[] = "Leonardo da Vinci: 15/04/1452";
    char nome2[] = "Albert Einstein: 14/03/1879";

    char *login1 = cria_login(nome1);
    char *login2 = cria_login(nome2);

    printf("%s\n", login1);  // ldv:1452
    printf("%s\n", login2);  // ae:1879

    free(login1);
    free(login2);
    return 0;
}
*/

/*
Questão 17) Escreva uma função que recebe uma string com palavras separadas por espaços em branco e
retorne um novo vetor de strings, alocado dinamicamente, onde cada elemento é uma palavra da string
original, também alocada dinamicamente. Por exemplo, se a função receber a string “Este foi um teste”, a
função deve retornar um vetor com 4 strings:
Sua função deve retornar o endereço do vetor de strings e preencher o endereço recebido com o número de
elementos do vetor, seguindo o protótipo:
char** split (char* original, int* pNumElem);

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char** split (char* original, int* pNumElem){
    int len = (int) strlen(original);

    int qtd_palavras = 0;
    int dentro_palavra = 0;

    for (int i = 0; i < len; i++) {
        if(isspace(original[i])){
            dentro_palavra = 0;
        } else if (!dentro_palavra) {
            dentro_palavra = 1;
            qtd_palavras++;
        }
    }

    *pNumElem = qtd_palavras;

    char ** retorno = malloc( qtd_palavras * sizeof(char *));

    int i_retorno = 0;

    int i = 0;

    while (i < len) {
        
        while(isspace(original[i])) i++;

        int inicio = i;
        while(!isspace(original[i])) i++;
        int tamanho = i - inicio;

        retorno[i_retorno] = malloc((tamanho + 1) * sizeof(char));

        strncpy(retorno[i_retorno], original + inicio, tamanho);
        retorno[i_retorno][tamanho] = '\0';
        i_retorno++;
    }

    return retorno;
}

int main(void) {
    char frase[] = "Este foi um teste.";
    int n = 0;
    char **v = split(frase, &n);

    if (v) {
        for (int i = 0; i < n; i++) {
            printf("%s\n", v[i]);
            free(v[i]);
        }
        free(v);
    }
    return 0;
}
*/

/*
Questão 18) Escreva a função char* concatenarInicioNovo(char* s1, char* s2) que concatena
a string s2 no início da string s1 e em uma nova área de memória alocada dinamicamente do tamanho exato.
A função retorna a nova string.
INF 1037 - Programação em C - 01/10/2025 - Revisão P1 2
Por exemplo, para s1 = “galera!” e s2 = “Isto eh tudo, “, a função retorna “Isto eh tudo, galera!”.
O código desta função deve atender às seguintes especificações:
● não usar funções da biblioteca de strings, exceto a strlen;
● não usar a notação de índice (ou seja, use obrigatoriamente aritmética de ponteiros);
● a função retorna NULL se ocorrer problema de alocação de memória;
● se ocorrer problema de memória, exibe mensagem e interrompa o processamento na main; e
● libere a memória após os testes.
Desenvolva a main para testar sua função e, como teste, use os exemplos apresentados. Atenção para as
interrupções por problemas de memória e para as ocasiões de liberar memória.

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* concatenarInicioNovo(char* s1, char* s2){
    int len1 = (int) strlen(s1);
    int len2 = (int) strlen(s2);
    int len3 = len1 + len2 + 1;

    char *retorno = malloc(sizeof(char) * len3);
    
    int idx3 = 0;
    for (int i = 0; i < len1; i++){
        retorno[idx3] = s1[i];
        idx3++;
    }

    for (int i = 0; i < len2; i++) {
        retorno[idx3] = s2[i];
        idx3++;
    }

    retorno[len3] = '\0';

    return retorno;
}


int main (void) {
    char s1[] = "Eu sou o ";
    char s2[] = "Antonio.";
    char *s3 = concatenarInicioNovo(s1, s2);
    printf("%s\n", s3);
    return 0;
}
*/


/*
Questão 19) Considere um arquivo texto cuja primeira informação é o número total de registros, um por linha.
Cada registro tem duas informações: uma data (que pode ser dia/mês/ano ou mês/ano ou apenas ano, com
no máximo 10 caracteres) e um nome de pessoa (com no máximo 80 caracteres).
Por exemplo:

4
25/01/1927 Antonio Carlos Jobim
1946 Mario Prata
03/1887 Heitor Villa-Lobos
14/03/38 Glauber Pedro de Andrade Rocha

Escreva a função char** vetorNomes(const char* nomeArq, int* nreg), onde nomeArq é o
nome do arquivo e nreg é um endereço de variável que deve armazenar o número de registros. A função
deve retornar um vetor de ponteiros para strings que são os nomes extraídos da leitura do arquivo texto. Este
vetor deve ser alocado dinamicamente do tamanho exato (tanto para o vetor como para cada string).
O código desta função deve atender às seguintes especificações:
● No caso de memória insuficiente, a função deve retornar NULL.
● No caso de problemas de abertura de arquivo, a mensagem de erro e a interrupção devem ser
tratadas localmente e tão logo ocorram. O caso de problemas de alocação de memória deve ser
tratado na main.
● No caso de sucesso, com o exemplo de arquivo acima, o número de registros é 4 e o vetor tem
Antonio Carlos Jobim na posição 0, Mario Prata na posição 1, … .
● Não se esqueça de fechar o arquivo tão logo não precise mais dele. E, na main, imprima o vetor e
depois libere toda a memória (do vetor e das strings).
Desenvolva a main para testar sua função e, como teste, use os exemplos apresentados. Atenção para as
interrupções por problemas de memória e para as ocasiões de liberar memória.

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char** vetorNomes(const char* nomeArq, int* nreg){
    FILE *arquivo = fopen(nomeArq, "r");
    fscanf(arquivo, "%d\n", nreg);
    char **vetor = malloc(sizeof(char *) * (*nreg));

    if (!vetor) { printf("Erro ao alocar memória."); exit(1);}

    for (int i = 0; i < *nreg; i++){
        char data[11];
        char *nome = malloc(sizeof(char) * 81);
        fscanf(arquivo, "%s %[^\n]\n", data, nome);
        vetor[i] = nome;
    }

    fclose(arquivo);

    return vetor;
}


int main (void) {
    const char nome_arquivo[] = "entradas.txt";
    int nreg = 0;

    char **vetor_resultado = vetorNomes(nome_arquivo, &nreg);

    for (int i = 0; i < nreg; i++) {
        printf("%s\n", vetor_resultado[i]);
        free(vetor_resultado[i]);
    }

    free(vetor_resultado);
    return 0;
}
*/


/*
Questão 20) Escreva um programa que:
● Crie/abra um arquivo texto de nome “arq.txt”.
● Permita que o usuário grave diversos caracteres nesse arquivo, até que o usuário entre com o
caractere ‘0’.
● Feche o arquivo.

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *arquivo = fopen("arq.txt", "w");
    if (!arquivo) {
        printf("Erro ao abrir arq.txt");
        return 1;
    }

    printf("Insira caracteres (digite 0 para encerrar):\n");

    int ch;
    while ((ch = getchar()) != EOF) {
        if (ch == '0') break;   

        if (fputc(ch, arquivo) == EOF) {
            printf("Erro ao escrever no arquivo");
            fclose(arquivo);
            return 1;
        }
    }

    if (fclose(arquivo) == EOF) {
        printf("Erro ao fechar o arquivo");
        return 1;
    }

    return 0;
}
*/

/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float media (char * mat, char * nome_arquivo ){
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {exit(1);};

    float media;
    int encontrada = 0;
    char matricula[10];
    float nota1, nota2, nota3;
    
    while (!encontrada) {
        int resultado_scan = fscanf(arquivo, "%s %f %f %f", matricula, &nota1, &nota2, &nota3);

        if (resultado_scan == EOF) break;

        if (resultado_scan != 4) {
            int c;
            while ((c = fgetc(arquivo)) != '\n') {}
            continue;
        }

        if (strcmp(mat, matricula) == 0) {
            media = (nota1 + nota2 + nota3)/3.0f;
            encontrada = 1;
            fclose(arquivo);
            return media;
        }
    }

    fclose(arquivo);
    return -1;
}

int main (void) {
    char nome_arquivo[] = "dados.txt";
    char matricula[] = "9010087-2";
    float resultado = media(matricula, nome_arquivo);
    printf("%f", resultado);
    return 0;
}

#include <stdio.h>

int main (void) {
    FILE *ler = fopen("entradas.txt", "r");
    if (!ler) {printf("Erro ao abrir o arquivo de ler."); return 0;}
    FILE *escrever = fopen("aprovados.txt", "w");
    if (!escrever) {printf("Erro ao abrir o arquivo de escrever."); return 0;}

        char nome[100];
        float nota1;
        float nota2;
        float media;

        while(fscanf(ler, " %[^\n]\n", nome) == 1){
            fscanf(ler, "%f %f\n", &nota1, &nota2);
            media = (nota1 + nota2)/2;
            if (media >= 5.0 ){
                fprintf(escrever, "%s %.2f\n", nome, media);
            }
        }

        fclose(ler);
        fclose(escrever);

    return 0;
}
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    FILE *arquivo_leitura = fopen("entradas.txt", "r");
    FILE *arquivo_escrever = fopen("livros.txt", "w");

    if (!arquivo_leitura || !arquivo_escrever) {
        perror("Erro ao abrir arquivos");
        return 1;
    }

    char nomes_e_autores[200][2][200];
    char iniciais[200];
    int qtd = 0;

    // Lê linhas no formato: Título/Autor
    while (qtd < 200 &&
           fscanf(arquivo_leitura, " %199[^/]/%199[^\n]",
                  nomes_e_autores[qtd][0], nomes_e_autores[qtd][1]) == 2) {

        // Pega a primeira letra não-em-branco do título e coloca em maiúscula
        char *t = nomes_e_autores[qtd][0];
        while (*t == ' ' || *t == '\t') t++;
        if (*t) iniciais[qtd] = (char)toupper((unsigned char)*t);
        else    iniciais[qtd] = '?';

        // Opcional: “trim” do início do título (mantém seu layout)
        if (t != nomes_e_autores[qtd][0]) {
            memmove(nomes_e_autores[qtd][0], t, strlen(t) + 1);
        }

        qtd++;
    }

    for (int pass = 0; pass < qtd - 1; pass++) {
        for (int i = 0; i < qtd - 1 - pass; i++) {
            if (iniciais[i] > iniciais[i + 1]) {
                char tmpIni = iniciais[i];
                iniciais[i] = iniciais[i + 1];
                iniciais[i + 1] = tmpIni;

                char tmp[2][200];
                memcpy(tmp, nomes_e_autores[i], sizeof tmp);
                memcpy(nomes_e_autores[i], nomes_e_autores[i + 1], sizeof tmp);
                memcpy(nomes_e_autores[i + 1], tmp, sizeof tmp);
            }
        }
    }

    for (int i = 0; i < qtd; ) {
        fprintf(arquivo_escrever, "Titulos iniciados com %c:\n", iniciais[i]);

        int j = i;
        do {
            fprintf(arquivo_escrever, "%s. Autor: %s\n",
                    nomes_e_autores[j][0], nomes_e_autores[j][1]);
            j++;
        } while (j < qtd && iniciais[j] == iniciais[i]);

        fputc('\n', arquivo_escrever);
        i = j;
    }

    fclose(arquivo_escrever);
    fclose(arquivo_leitura);
    return 0;
}
