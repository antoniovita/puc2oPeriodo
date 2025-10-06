/*
Questão 01) Escreva uma única função que recebe um vetor de inteiros e calcula duas somas: a soma dos
valores pares e a soma dos valores ímpares. Além do vetor e da quantidade inteiros no vetor, a função deve
receber ponteiros de variáveis onde as somas serão armazenadas.

#include <stdio.h>
#include <stdlib.h>

int calcula_soma (int *valores, int quantidade_valores, int *soma_par, int *soma_impar) {
    for (int i = 0; i < quantidade_valores ; i ++) {
        if ( valores[i] % 2 == 0) {
            *soma_par += valores[i];
        }
        else {
            *soma_impar += valores[i];       
        }
    }
    return 0;
}

int main (void) {
    int valores[] = {1, 2 , 3 , 4 , 5};
    int soma_impar = 0;
    int soma_par = 0;
    int quantidade_valores = sizeof(valores)/sizeof(int);

    calcula_soma(valores, quantidade_valores, &soma_par, &soma_impar);
    printf(" A soma dos valores pares é %d e a dos valores ímpares é %d", soma_par, soma_impar);
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

int acha_menor (int *v, int n, int *valor, int *quantidade_vezes) {
    int menor = v[0];
    for (int i = 0; i < n; i++) {
        if (menor > v[i]) {
            menor = v[i];
            *quantidade_vezes = 1;
        } else if (menor == v[i]) {
            *quantidade_vezes += 1;
        }
    }
    *valor = menor;
    return 0;
}

int main (void) {
    int v[] = {5, 2, 2, 2, 15, 3, 7, 2, 15, 8, 6, 15};
    int n = sizeof(v)/sizeof(int);
    int valor;
    int quantidade_vezes = 0;

    acha_menor(v, n, &valor, &quantidade_vezes);
    printf("O menor valor é %d e ele apareceu %d vezes.", valor, quantidade_vezes);
    return 0;
}
*/

/*
Questão 03) Escreva uma única função que calcula a média aritmética e a média ponderada de um vetor de
float de tamanho qualquer. Além do vetor com os valores, a função recebe um segundo vetor com os pesos
da média ponderada. Ambas as médias devem ser passadas como parâmetros da função a serem
preenchidos.

#include <stdio.h> 

int calcula_medias (int *valores, int n, int *pesos, float *aritmetica, float *ponderada) {
    int soma_aritmetica = 0;
    int soma_ponderada = 0;
    int soma_pesos = 0;
    for (int i = 0; i < n; i++) {
        soma_aritmetica += valores[i];
        soma_pesos += pesos[i];
        soma_ponderada += valores[i]*pesos[i];
    }

    *aritmetica = (float)(soma_aritmetica/n);
    *ponderada = (float)(soma_ponderada)/(float)(soma_pesos);

    return 0;
}

int main (void) {
    int valores[] = {8 , 9 , 10};
    int pesos[] = {1, 2, 3};
    int n = sizeof(valores)/sizeof(int);
    float aritmetica;
    float ponderada;

    calcula_medias(valores, n, pesos, &aritmetica, &ponderada);
    printf("A média ponderada é %.2f e a média aritmética é %.2f.\n", ponderada, aritmetica);
    return 0;
}
*/

/*
Questão 04) Escreva uma função que recebe um vetor de inteiros e retorna um novo vetor, alocado
dinamicamente, eliminando os elementos repetidos em sequência. Por exemplo, dado {1,2,2,1,4,5,6,6,5} , a
função deve criar o vetor {1,2,1,4,5,6,5}. A função deve retornar o novo vetor e receber um parâmetro para
preencher a quantidade de elementos inseridos no novo vetor.

#include <stdio.h>
#include <stdlib.h>

int* novo_vetor (int *vetor, int n, int *quantidade_novo) {
    int *novo = (int*) malloc( n * sizeof(int));

    if (novo == NULL) {
        printf("ERRO NA ALOCAÇÃO DO VETOR novo.");
        return 0;
    }

    int j = 0;
    novo[j] = vetor[0];
    j++;

    for (int i = 1; i < n; i ++) {
        if (vetor[i] != vetor[i - 1]){
            novo[j] = vetor[i];
            j++;
        }
    }

    *quantidade_novo = j;
    return novo;
}

int main () {
    int vetor[] = {1,2,1,4,5,6,5};
    int n = sizeof(vetor)/sizeof(int);
    int quantidade_novo = 0;

    int *novo = novo_vetor(vetor, n, &quantidade_novo);

    printf("A quantidade do novo vetor é %d \n", quantidade_novo);

    printf("[");
    for (int i = 0; i < quantidade_novo; i++) {
        printf("%d, ", novo[i]);
    }
    printf("]");


    return 0;
}
*/


/*
Questão 05) Escreva uma função para criar uma nova cadeia de caracteres sem repetição em sequência dos
caracteres de uma cadeia fornecida. Por exemplo, dado "AAnnnaa", a função cria e retorna a cadeia "Ana".

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* cria_sem_rep(char *cadeia) {
    int len = strlen(cadeia);
    char *nova_cadeia = malloc(sizeof(char)*len);

    int j = 1;
    nova_cadeia[0] = cadeia[0];
    for (int i = 1; i < len; i ++) {
        if (cadeia[i] != cadeia[i - 1]) {
            nova_cadeia[j] = cadeia[i];
            j++;
        }
    }

    return nova_cadeia;
}

int main (void) {
    char *resposta = cria_sem_rep("AAnnnaa");
    printf("%s", resposta);
    return 0;
}
*/

/*
Questão 06) Escreva uma função que recebe duas strings e retorna se a segunda é prefixo da primeira.
Retorne 1 se for prefixo e 0 caso contrário. Considere que uma string vazia é prefixo da outra. Considere
também que duas strings iguais são prefixo uma da outra.

#include <stdio.h>
#include <string.h>

int prefixo(const char *palavra, const char *possivel_prefixo) {
    int len_palavra = strlen(palavra);
    int len_prefixo = strlen(possivel_prefixo);

    if (len_prefixo > len_palavra) {
        return 0;
    }

    // essa strncmp retorna 0 se forem iguais
    int resultado = strncmp(palavra, possivel_prefixo, len_prefixo) == 0;

    return resultado;
}

int main(void) {
    printf("%d\n", prefixo("antonio", ""));
    printf("%d\n", prefixo("antonio", "an"));
    printf("%d\n", prefixo("antonio", "anton"));
    printf("%d\n", prefixo("antonio", "antoX"));
    printf("%d\n", prefixo("antonio", "antonios"));
    return 0;
}
*/

/*
Questão 07) Escreva uma função que dado um nome, retorna uma nova cadeia com o último sobrenome.
Por exemplo, dado "Carlos Drumond de Andrade", a nova cadeia deve ser "Andrade".

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* sobrenome(const char *nome_completo) {
    const char *inicio_sobrenome;
    const char *ultimo_espaco = strrchr(nome_completo, ' ');

    // se encontrou espaço, o sobrenome começa logo após o último espaço
    if (ultimo_espaco != NULL) {
        inicio_sobrenome = ultimo_espaco + 1;
    } else {
        // se não encontrou espaço, o sobrenome é o nome completo
        inicio_sobrenome = nome_completo;
    }

    // aloca memória para o sobrenome (+1 para o '\0')
    char *sobrenome = malloc(strlen(inicio_sobrenome) + 1);
    if (sobrenome == NULL) {
        printf("Falha na alocação de memória\n");
    }

    strcpy(sobrenome, inicio_sobrenome);
    return sobrenome;
}

int main(void) {
    char *resposta = sobrenome("Carlos Drumond de Andrade");
    printf("%s\n", resposta);

    free(resposta);
    return 0;
}
*/

/*
Questão 08 e 9) Escreva uma função que recebe um vetor de strings com nomes de pessoas e retorne um novo
vetor de strings, alocado dinamicamente, onde cada elemento, também alocado dinamicamente, é o primeiro
nome de cada pessoa. Por exemplo, se for passado para a função o vetor {"Alberto Einsten", "Leonardo da
Vinci", "Alan Turing"}, sua função deve retornar o vetor {"Alberto", "Leonardo", "Alan"}.
Dica: Escreva uma função auxiliar que recebe uma string representando o nome completo de uma pessoa e
retorne uma nova string, alocada dinamicamente, com o primeiro nome da pessoa.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** gera_vetor_primeiro_nome (char **vetor_de_strings, int len) {
    char **vetor_resultado = malloc(sizeof(char *)*len);

    for (int i = 0; i < len; i++) {
        char *cada_string = vetor_de_strings[i];
        char *espaco = strchr(cada_string, ' ');
        int tamanho = espaco - cada_string;

        char *primeiro_nome = malloc(tamanho + 1);
        strncpy(primeiro_nome, cada_string, tamanho);
        primeiro_nome[tamanho] = '\0';
        vetor_resultado[i] = primeiro_nome;
    }

    return vetor_resultado;
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
    char **resultado = gera_vetor_primeiro_nome(vetor, len);

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

char **converte(int *v, int n) {
    char **vetor_resultado = malloc(n * sizeof(char *));

    if (vetor_resultado == NULL) {
        fprintf(stderr, "ERRO: falha ao alocar vetor de ponteiros.\n");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        int k = v[i];

        char letra;
        
        if (k % 2 == 0) {
            letra = 'A';
        } else {
            letra = 'a';
        }
        
        char *string_nova = malloc(k + 1);

        if (string_nova == NULL) {
            for (int t = 0; t < i; t++) free(vetor_resultado[t]);
            free(vetor_resultado);
            return NULL;
        }

        for (int j = 0; j < k; j++) {
            string_nova[j] = letra;
        }

        string_nova[k] = '\0';

        vetor_resultado[i] = string_nova;
    }

    return vetor_resultado;
}

int main(void) {
    int vetor_inicial[] = { 2, 4, 3, 1 };
    int len = (int)(sizeof(vetor_inicial) / sizeof(vetor_inicial[0]));

    char **vetor = converte(vetor_inicial, len);
    if (vetor == NULL) return 1;

    for (int i = 0; i < len; i++) {
        printf("%s\n", vetor[i]);
        free(vetor[i]);
    }

    free(vetor);

    return 0;
}
*/


/*
Questão 11) Implemente uma função que recebe como parâmetros dois vetores de inteiros, v1 e v2, e as
suas respectivas quantidades de elementos, n1 e n2. A função também deve receber um terceiro vetor v3,
com capacidade para (n1 + n2) elementos. Sua função deverá inserir os elementos de v1 e v2 em v3 de modo
intercalado. Por exemplo, se v1 = {1, 3, 5, 7} e v2 = {2, 4, 6, 8, 10, 12}, v3 irá conter {1, 2, 3, 4, 5, 6, 7, 8, 10,
12}. Observe que dependendo do número de elementos, os últimos valores podem não ficar intercalados.
void intercala(int* v1, int n1, int* v2, int n2, int* v3);


#include <stdio.h>
#include <stdlib.h>

void intercala(int* v1, int n1, int* v2, int n2, int* v3) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n1 || j < n2) {
        if (i < n1 && j < n2) {
            v3[k++] = v1[i++];
            v3[k++] = v2[j++];
        } else if (i < n1) {
            v3[k++] = v1[i++];
        } else {
            v3[k++] = v2[j++];
        }
    }
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
Questão 12) Modifique a função da “questão 11” para criar o vetor de retorno dinamicamente. A assinatura
da função deve passar a ser:


#include <stdio.h>
#include <stdlib.h>

int *intercala2(int* v1, int n1, int* v2, int n2) {

    int *v3 = malloc(sizeof(int)* (n1 + n2));

    if (v3 == NULL) {
        printf("ERRO.");
        exit(1);
    }

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n1 || j < n2) {
        if (i < n1 && j < n2) {
            v3[k++] = v1[i++];
            v3[k++] = v2[j++];
        } else if (i < n1) {
            v3[k++] = v1[i++];
        } else {
            v3[k++] = v2[j++];
        }
    }

    return v3;
}


int main(void) {
    int v1[] = {1, 3, 5, 7};
    int v2[] = {2, 4, 6, 8, 10, 12};
    int n1 = sizeof(v1) / sizeof(v1[0]);
    int n2 = sizeof(v2) / sizeof(v2[0]);

    int *v3 = intercala2(v1, n1, v2, n2);

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindromo(char* texto){
    int len = strlen(texto);
    char *texto_inverso = malloc(sizeof(char) * len);

    for (int i = 0; i < len; i++){
        texto_inverso[i] = texto[len - i - 1];
    }

    if (strcmp(texto, texto_inverso) == 0) {
        free(texto_inverso);
        return 1;
    } else {
        free(texto_inverso);
        return 0;
    }
}

int main (void) {
    int resultado = palindromo("ovo");
    printf("%d", resultado);
    return resultado;
}

ou 

int palindromo(char* texto){
    int i, j = strlen(texto) - 1;
    while (i < j) {
        if (texto[i] != texto[j]) return 0;
        i ++;
        j --;
    }
    return 1;
    
}
*/


/*
Questão 14) Escreva uma função que recebe um vetor de palavras (strings) e uma palavra (string) e retorna
o índice do vetor em que a palavra esteja. Se a palavra não for encontrada, a função deve retornar -1.


#include <string.h>
#include <stdio.h>

int index_palavra(char **vetor_palavaras, char *palavra, int len) {
    for (int i = 0; i < len; i++) {
        if (strcmp(vetor_palavaras[i], palavra) == 0) {
            return i;
        }
    }
    return -1;
}

int main (void) {
    char *vetor[] = {"dawdawd", "ola", "ioio"};
    int resultado = index_palavra(vetor , "ola", 3);
    printf("%d", resultado);
}
*/


/*
Questão 15) Escreva uma função que inverte uma string sem criar uma cópia da string original. Se sua função
receber a string “pontificia”, a string original deve ser alterada para passar a ser “aicifitnop”.


#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void inverte(char *s) {
    char *i = s[0];
    char *j = s[0] + strlen(s) - 1;
        while (i < j) { 
            char tmp = *i; 
            *i = *j; 
            *j = tmp; 
            ++i;
            --j;
  }
}

int main(void) {
    char palavra[] = "pontificia";
    inverte_funcao(palavra);
    printf("%s", palavra);
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


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *cria_login(const char *string) {

    const char *ultima_barra = strrchr(string, '/');
    if (!ultima_barra) return NULL;

    char ano[5];                          
    strncpy(ano, ultima_barra + 1, 4);
    ano[4] = '\0';


    int indice_dois_pontos = 0;
    while (string[indice_dois_pontos] != ':') indice_dois_pontos++;

    // +1 pra primeira palavra +1 pro '\0' +1 pro ':'
    int tamanho_iniciais = 3;
    for (int i = 0; i < indice_dois_pontos; i ++) {
        if (string[i] == ' '){
            tamanho_iniciais++;
        }
    }

    char *iniciais = malloc(sizeof(char *) * tamanho_iniciais);


    iniciais[0] = string[0];

    int i_iniciais = 1;
    for (int i = 0; i < indice_dois_pontos; i ++) {
        if(string[i] == ' '){
            iniciais[i_iniciais++] = string[i + 1];
        }
    }
    
    iniciais[tamanho_iniciais - 2] = ':';
    iniciais[tamanho_iniciais - 1] = '\0';

    int len_iniciais = strlen(iniciais);

    for (int j = 0; j < len_iniciais; j++) {
        iniciais[j] = tolower(iniciais[j]);
    }

    strcat(iniciais, ano);

    return iniciais;
}

int main(void) {
    const char *s1 = "Leonardo da Vinci Costa Silva Martins: 15/04/1452";
    const char *s2 = "Albert Einstein: 14/03/1879";
    

    char *l1 = cria_login(s1);
    char *l2 = cria_login(s2);

    if (l1) { printf("%s\n", l1); free(l1); }
    if (l2) { printf("%s\n", l2); free(l2); }

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

char** split(char* original, int* pNumElem) {

    int len = (int)strlen(original);

    int count = 0;
    int dentro_palavra = 0;
    for (int i = 0; i < len; i++) {
        if (isspace(original[i])) {
            dentro_palavra = 0;
        } else if (!dentro_palavra) {
            count++;
            dentro_palavra = 1;
        }
    }

    *pNumElem = count;

    char **ret = (char**)malloc(count * sizeof(char*));

    if (!ret) return NULL;

    int idx_ret = 0;

    int i = 0;
    while (i < len) {

        //pula espaços (usa while para pular TODOS se fosse if pularia um só)
        while (isspace(original[i])) i++;

        int inicio = i;
        while (!isspace(original[i])) i++;
        int tamanho = i - inicio;

        ret[idx_ret] = (char*)malloc((char)tamanho + 1);

        if (!ret[idx_ret]) {
            for (int k = 0; k < idx_ret; k++) free(ret[k]);
            free(ret);
            return NULL;
        }

        strncpy(ret[idx_ret], original + inicio, tamanho);
        ret[idx_ret][tamanho] = '\0';
        idx_ret++;
    }

    return ret;
}

int main(void) {
    char frase[] = "  Este   foi\tum  teste\n";
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

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* concatenarInicioNovo(char* s1, char* s2){
    int len1 = (int) strlen(s1);
    int len2 = (int) strlen(s2);
    int len3 = len1 + len2 + 1;

    char *retorno = (char *) malloc(sizeof(char) * len3);
    if(!retorno) return NULL;

    int i;
    for (i = 0; i < len1; i++){
        retorno[i] = s1[i];
    }

    for (int j = 0; j < len2; j++) {
        retorno[j + i] = s2[j];
    }

    retorno[len3 - 1] = '\0';

    return retorno;
}

int main (void) {
    char string1[] = "Ola sou o ";
    char string2[] = "Antonio.";

    char* retorno = concatenarInicioNovo(string1, string2);
    if (retorno == NULL) { printf("Erro na alocação de memória."); return 0;}

    printf("%s", retorno);
    free(retorno);
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
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** vetorNomes(const char* nomeArq, int* nreg) {
    FILE* f = fopen(nomeArq, "r");
    if (!f) {
        printf("Erro ao abrir %s.\n", nomeArq);
        exit(1);
    }

    // consome o resto da linha do inteiro
    int ch; while ((ch = fgetc(f)) != EOF && ch != '\n');

    char** v = malloc((*nreg) * sizeof(char*));
    if (!v) { fclose(f); return NULL; }

    char linha[256];
    for (int i = 0; i < *nreg; i++) {

        if (!fgets(linha, sizeof(linha), f)) {
            fprintf(stderr, "Arquivo terminou antes do esperado.\n");
            for (int k = 0; k < i; k++) free(v[k]);
            free(v);
            fclose(f);
            exit(1);
        }

        linha[strcspn(linha, "\n")] = '\0';

        char* nome = strchr(linha, ' ');

        v[i] = malloc(strlen(nome) + 1);
        if (!v[i]) {
            for (int k = 0; k < i; k++) free(v[k]);
            free(v);
            fclose(f);
            *nreg = 0;
            return NULL;              // falta de memória -> main trata
        }
        strcpy(v[i], nome);
    }

    fclose(f);
    return v;
}

int main(void) {
    // Para testar de forma simples, vamos criar o arquivo do enunciado.
    // Se já tiver um arquivo pronto, pode remover este bloco de criação.
    {
        FILE* f = fopen("dados.txt", "w");
        if (!f) { perror("criar"); return 1; }
        fputs("4\n"
              "25/01/1927 Antonio Carlos Jobim\n"
              "1946 Mario Prata\n"
              "03/1887 Heitor Villa-Lobos\n"
              "14/03/38 Glauber Pedro de Andrade Rocha\n", f);
        fclose(f);
    }

    int n = 0;
    char** nomes = vetorNomes("dados.txt", &n);
    if (!nomes) {                     // trata falta de memória
        fprintf(stderr, "Memoria insuficiente.\n");
        return 1;
    }

    // imprime e libera
    for (int i = 0; i < n; i++) {
        printf("[%d] %s\n", i, nomes[i]);
        free(nomes[i]);
    }
    free(nomes);

    return 0;
}
