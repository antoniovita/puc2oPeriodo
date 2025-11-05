#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char conteudo[100];
    struct Node *next;
} Node;

Node *criarNode(const char *palavra) {
    Node *novoNode = (Node *)malloc(sizeof(Node));
    if (novoNode == NULL) { return NULL; }
    strcpy(novoNode->conteudo, palavra);
    novoNode->next = NULL;
    return novoNode;
}

void inserirNoInicio(const char *palavra, Node **head) {
    Node *novoNode = criarNode(palavra);
    if (novoNode == NULL) return;
    novoNode->next = *head;
    *head = novoNode;
}

void inserirNoFinal(const char *palavra, Node **head) {
    Node *novoNode = criarNode(palavra);
    if (novoNode == NULL) return;
    if (*head == NULL) {
        *head = novoNode;
        return;
    }
    Node *atual = *head;
    while (atual->next != NULL) {
        atual = atual->next;
    }
    atual->next = novoNode;
}

void printLinkedList(Node *head) {
    Node *atual = head;
    while (atual != NULL) {
        printf("%s\n", atual->conteudo);
        atual = atual->next;
    }
}

int contaNodesTexto(Node *head) {
    int contador = 0;
    Node *atual = head;
    while (atual != NULL) {
        if (strcmp(atual->conteudo, "texto") == 0){
            contador++;
        }
        atual = atual->next;
    }
    return contador;
}

void removeNodeTexto(Node **head) {
    if (head == NULL || *head == NULL) return;

    if (strcmp((*head)->conteudo, "texto") == 0) {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    
    Node *atual = *head;
    while (atual->next != NULL && strcmp(atual->next->conteudo, "texto") != 0) {
        atual = atual->next;
    }

    if (atual->next != NULL) {
        Node *temp = atual->next;
        atual->next = temp->next;
        free(temp);
    }
    return;
}

void liberarLista(Node *head) {
    Node *atual = head;
    while (atual != NULL) {
        Node *prox = atual->next;
        free(atual);
        atual = prox;
    }
}

int main(void) {
    Node *head = NULL;

    inserirNoInicio("texto", &head);
    inserirNoInicio("Bruna", &head);
    inserirNoFinal("Carlos", &head);
    inserirNoFinal("texto", &head);

    printLinkedList(head);

    int quantidade = contaNodesTexto(head);
    printf("Quantidade de ocorrencia da palavra texto: %d\n", quantidade);

    removeNodeTexto(&head);   /* corrigido: passa &head */
    printLinkedList(head);

    liberarLista(head);
    return 0;
}
