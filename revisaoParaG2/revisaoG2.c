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
*/

#include <stdio.h>

typedef struct aluno {
    char nome_completo[81];
    int matricula;
    float p1;
    float p2;
    float p3;
} Aluno;


typedef struct lista {
    Aluno aluno;
    struct lista *proximo;
} Lista;

Aluno* leia_arquivo (char* nome_arquivo, int* pn){
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {exit(1);}
    fscanf(arquivo, " %d\n", pn);
    Aluno *vetor_alunos = (Aluno *)malloc(sizeof(Aluno) * (*pn));
    if (vetor_alunos == NULL) {exit(1);}
    for (int i = 0; i < *pn; i ++) {
        fscanf(arquivo, "%80[^:] %d %f %f %f", vetor_alunos[i].nome_completo, &vetor_alunos[i].matricula, &vetor_alunos[i].p1, &vetor_alunos[i].p2, &vetor_alunos[i].p3);
    }
    fclose(arquivo);
    return vetor_alunos;
}

/*
Questão 02) Escreva uma função para salvar o vetor de alunos retornado na função anterior em um arquivo
binário. O arquivo salvo deve ter um número inteiro inicial indicando a dimensão do vetor e então o vetor de
alunos, seguindo o protótipo:
*/

void salva_binario (int n, Aluno* vet, char* nome_arquivo){
    FILE *arquivo = fopen(nome_arquivo, "wb");
    if (arquivo == NULL){exit(1);}
    fwrite(&n, sizeof(int),1, arquivo);
    fwrite(vet, sizeof(Aluno), n, arquivo);
    fclose();
    return;
}


/*
Questão 03) Escreva uma função que recebe o nome do arquivo binário e um índice n. A função deve
retornar o ponteiro de uma estrutura de um aluno, alocada dinamicamente, com a informação do n-ésimo
aluno existente no arquivo. Isto é, se for passado n=0, deve-se retornar a informação do primeiro aluno, se
n=1, do segundo, e assim por diante. A função deve ter o seguinte protótipo:
*/

//TEM QUE CORRIGIR ESSA QUESTAO AQUI 
Aluno* leia_aluno (char* nome_arquivo, int n){
    FILE *arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL) {exit(1);}
    int qtd;
    fread(&qtd, sizeof(int), 1, arquivo);
    Aluno *vetor_alunos = (Aluno *) malloc(sizeof(Aluno) * qtd);
    fread(vetor_alunos, sizeof(Aluno), qtd, arquivo);
    fclose();
    return vetor_alunos[n];
}

/*
Questão 04) Escreva uma função que recebe o vetor de alunos retornado pela primeira função e retorne
uma lista encadeada com o nome e média dos alunos. A ordem dos elementos na lista deve ser a mesma
do vetor. A função deve ter o seguinte protótipo:
*/


Lista* cria_lista (int n, Aluno* vet) {
    Lista *head = NULL;
    for (int i = 0; i < n; i++) {
        Lista *noLista = (Lista *)malloc(sizeof(Lista));
        noLista->proximo = head;
        noLista->aluno = vet[n - 1 - i];
        head = noLista;
    }
    return head;
}

/*
Questão 05) Escreva uma função para exibir os nomes e médias dos alunos na lista, com o seguinte
protótipo:
*/

void exibe (Lista* lst){
    Lista *atual = lst;
    while (atual != NULL) {
        printf("%s\n", atual->aluno.nome_completo);
        float media = (atual->aluno.p1 + atual->aluno.p2 + atual->aluno.p3)/3;
        printf("%.2f\n", media);
        atual = atual->proximo;
    }
    return;
}

/*
Questão 06) Usando recursão, escreva uma função para exibir os nomes e médias dos alunos da lista em
ordem reversa, seguindo o protótipo:
*/

void exibe_rev (Lista* lst){
    if (lst == NULL){return;}

    exibe_rev(lst->proximo);

    printf("%s\n", lst->aluno.nome_completo);
    printf("%d\n", lst->aluno.matricula);
    float media = (lst->aluno.p1 + lst->aluno.p2 + lst->aluno.p3)/3;
    printf("%.2f", media);
}


/*
Questão 07) Escreva uma função para, dado o nome de um aluno, removê-lo da lista, com o seguinte
protótipo:
*/

void retira_aluno (Lista* lst, char* nome){
    Lista *atual = lst;
    while( atual != NULL) {
        if (atual->proximo.aluno.nome_completo == nome){
            atual->proximo = atual->proximo->proximo;
            free(atual->proximo);
            return;
        }
    }
}


/*
Questão 08) Escreva uma função com a mesma funcionalidade para remover um aluno usando recursão.
*/

void retira_aluno (Lista* lst, char* nome){
    if (lst == NULL) {return;}
    if (lst->proximo->aluno.nome_completo == nome) {
        lst->proximo = lst->proximo->proximo; 
        free(lst->proximo);
        return;
    }

    retira_aluno(lst->proximo);
}

/*
Questão 09) Escreva uma função para liberar a memória da lista.
*/

void libera_memoria (Lista *head){
    Lista *atual = head;

    while (atual != NULL) {
        Lista* proximo = atual->proximo;
        free(atual);
        atual = proximo;   
    }
    return;
}

/*
Questão 10) Considere agora uma lista de valores inteiros. Pede-se:
a) Escreva uma função para criar uma lista vazia.
b) Escreva uma função não recursiva para inserir um novo valor na lista, em ordem crescente.
c) Escreva uma segunda versão da função acima usando recursão.
d) Escreva uma função para exibir os valores armazenados na lista.
e) Escreva uma função para remover todos os valores pares da lista.
f) Escreva uma segunda versão da função acima usando recursão.
g) Escreva uma função para remover o n-ésimo elemento da lista a partir do final. Isto é, se n=0,
deve-se remover o último; se n=1, deve-se remover o penúltimo, e assim por diante.
h) Numa lista circular, o último elemento tem como próximo um ponteiro para o primeiro elemento.
Escreva uma função que recebe uma lista e a transforme numa lista circular.
i) Escreva uma função para exibir as informações em uma lista circular.
*/

Lista *cria_nova_lista(int valor){
    Lista *novo_no = (Lista *) malloc(sizeof(Lista));
    novo_no->proximo = NULL;
    novo_no->valor = valor;
    return novo_no;
}


Lista *inserir_ordem_crescente(Lista *head, int valor) {

    Lista *novo_no = cria_nova_lista(valor);

    if (head == NULL) {
        return novo_no;
    }

    if (valor < head->valor) {
        novo_no->proximo = head;
        return novo_no;
    }

    Lista *atual = head;
    while (atual->proximo != NULL && atual->proximo->valor < valor) {
        atual = atual->proximo;
    }

    //vai parar justamente no primeiro que o valor é maior

    novo_no->proximo = atual->proximo;
    atual->proximo = novo_no;

    return head;
}

Lista *inserir_ordem_crescente_recursiva(Lista *head, int valor) {

    if (head == NULL || valor < head->valor) {
        Lista *novo_no = cria_nova_lista(valor);
        novo_no->proximo = head;
        return novo_no;
    }

    head->proximo = inserir_ordem_crescente_recursiva(head->proximo, valor);
    return head;
}

void exibe_lista (Lista *head) {
    Lista *atual = head;
    while (atual != NULL) {
        printf("%d", atual->valor);
        atual = atual->proximo;
    }
}

/*
Questão 11) Considere um cadastro de nome e telefone de pessoas, composto por 26 listas. A primeira
lista tem as informações de pessoas cujo nome começa com ‘A’
, a segunda com ‘B’
, e assim por diante.
Pede-se:
a) b) c) d) e) f) Defina tipos apropriados para representar o cadastro e os elementos da lista.
Escreva uma função que cria um cadastro (alocado dinamicamente) inicialmente vazio.
Escreva uma função para inserir uma nova informação nome/telefone no cadastro.
Escreva uma função para, dado um nome, exibir o número do telefone, se presente no cadastro.
Escreva uma função para remover um nome do cadastro.
Escreva uma função para liberar a memória do cadastro e suas listas.
*/