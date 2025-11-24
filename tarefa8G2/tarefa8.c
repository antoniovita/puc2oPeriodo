/*
Exercício 1:
a) Implemente uma função não recursiva para retornar o ponteiro do i-
ésimo elemento da lista, onde i é passado como parâmetro. Considere
que o valor i = 0 retorna o ponteiro do primeiro elemento. Assuma que o
valor de i é sempre válido (i < n, onde n é o número de elementos na
lista).
b) Implemente a função do item anterior usando recursão.

Exercício 2:
a) b) Implemente uma função não recursiva para criar uma cópia de (duplicar)
uma lista, retornando o ponteiro para o primeiro elemento da nova lista.
Implemente a função do item anterior usando recursão.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *next;
} Node;

Node *criarNode (int valor){
    Node *novoNode = (Node *) malloc(sizeof(Node));
    if (novoNode == NULL) {return NULL;}
    novoNode->next = NULL;
    novoNode->valor = valor;
    return novoNode;
}

void inserirNoInicio(Node **head, int valor){
    Node *novoNode = criarNode(valor);
    if (novoNode == NULL) {return;}
    novoNode->valor = valor;
    novoNode->next = *head;
    *head = novoNode;
    return;
}

void inserirNoFinal(Node **head, int valor){
    Node *novoNode = criarNode(valor);
    if (novoNode == NULL) {return;}
    if (*head == NULL) { *head = novoNode; return; }
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = novoNode;
    return;
}

//Questao 1:
Node *retornaElementoI(Node *head, int i) {
    Node *temp = head;
    int k = 0;
    while (k < i && temp != NULL) {
        temp = temp->next;
        k++;
    }
    return temp;
}


Node *retornaElementoIcomRecursao(Node *head, int i) {
    if (head == NULL) return NULL;
    if (i == 0) return head;
    return retornaElementoIcomRecursao(head->next, i - 1);
}


// Questao 2:
Node *duplicarLista(Node *head) {
    if (head == NULL) return NULL;

    Node *novaLista = NULL;
    Node *temp = head;

    while (temp != NULL) {
        inserirNoFinal(&novaLista, temp->valor);
        temp = temp->next;
    }

    return novaLista;
}

Node *duplicarListaComRecursao(Node *head) {
    if (head == NULL) {
        return NULL;
    }

    Node *novoNode = criarNode(head->valor);
    novoNode->next = duplicarListaComRecursao(head->next);
    return novoNode;
}
