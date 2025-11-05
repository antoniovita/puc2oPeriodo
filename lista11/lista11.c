#include <stdio.h>
#include <stdlib.h>

typedef struct livro Livro;
struct livro {
    char titulo[201];
    char autor[121];
    float preco;
};

typedef struct no_lista NoLista;
struct no_lista {
    Livro dadosLivro;
    NoLista* proximo;
};

/*
1)
*/

NoLista* cria_lista_de_arquivo(const char* nome_arquivo){
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) return NULL;
    Livro dadosTemp;
    NoLista *head = NULL;
    while (fscanf(arquivo, " %200[^:]:%120[^:]:$%f",dadosTemp.titulo, dadosTemp.autor, &dadosTemp.preco) == 3) {        
        NoLista *novoNo = (NoLista *) malloc(sizeof(NoLista));
        if (novoNo == NULL) return NULL;
        novoNo->dadosLivro = dadosTemp;
        novoNo->proximo = head;
        head = novoNo;
    }
    fclose(arquivo);
    return head;
}


void libera_lista(NoLista* head){
        while (head != NULL) {
        NoLista *next = head->proximo;
        free(head);
        head = next;
    }
    return;
}

Livro* livros_por_preco_menor(NoLista* head, float preco_limite, int *n){
    int count = 0;
    for (NoLista *a = head; a != NULL; a = a->proximo)
        if (a->dadosLivro.preco <= preco_limite) count++;

    *n = count;
    if (count == 0) return NULL;

    Livro *vet = malloc(sizeof(Livro) * count);
    if (!vet) return NULL;

    int j = 0;
    for (NoLista *a = head; a != NULL; a = a->proximo)
        if (a->dadosLivro.preco <= preco_limite) vet[j++] = a->dadosLivro;

    for (int i = 0; i < count - 1; i++) {
        for (int k = 0; k < count - 1 - i; k++) {
            if (vet[k].preco > vet[k+1].preco) {
                Livro tmp = vet[k];
                vet[k] = vet[k+1];
                vet[k+1] = tmp;
            }
        }
    }
    return vet;
}


int main(void) {
    NoLista *head = cria_lista_de_arquivo("livros.txt");
    if (head == NULL) {
        printf("Erro ao abrir ou ler o arquivo.\n");
        return 1;
    }

    printf(" Lista original de livros \n");
    NoLista *atual = head;
    while (atual != NULL) {
        printf("Título: %-30s Autor: %-20s Preço: $%.2f\n",
               atual->dadosLivro.titulo,
               atual->dadosLivro.autor,
               atual->dadosLivro.preco);
        atual = atual->proximo;
    }

    float limite = 12.00;
    int n = 0;
    Livro *vetor = livros_por_preco_menor(head, limite, &n);

    if (vetor == NULL || n == 0) {
        printf("\nNenhum livro com preço menor ou igual a $%.2f.\n", limite);
    } else {
        printf("\n Livros com preço até $%.2f (ordenados) \n", limite);
        for (int i = 0; i < n; i++) {
            printf("[%2d] %-30s Autor: %-20s Preço: $%.2f\n",
                   i + 1, vetor[i].titulo, vetor[i].autor, vetor[i].preco);
        }
    }

    free(vetor);
    libera_lista(head);
    return 0;
}

