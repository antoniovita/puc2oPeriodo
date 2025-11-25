#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto Produto;

struct produto {
    int codigo;
    char nome[51];
    float preco;
    int quantidade;
};

typedef struct no_lista NoLista;

struct no_lista {
    Produto produto;
    struct no_lista *proximo;
};

void libera_memoria(NoLista *head){
    NoLista *liberado;
    while(head != NULL) {
        liberado = head;
        head = head->proximo;
        free(liberado);
    }
    return;
}

NoLista* carrega_estoque_binario(const char* nome_arquivo){
    FILE *arquivo_binario = fopen(nome_arquivo, "rb");
    if(arquivo_binario == NULL){printf("Erro ao abrir o binario."); exit(1);}
    NoLista *head = NULL;
    Produto buffer;

    while (fread(&buffer, sizeof(Produto), 1, arquivo_binario) == 1) {
        NoLista *novo_no = (NoLista *) malloc(sizeof(NoLista));
        if (novo_no == NULL) {libera_memoria(head); fclose(arquivo_binario); exit(1);}
        novo_no->proximo = NULL;
        
        if (head == NULL) {head = novo_no;} 
        else { NoLista* atual = head; while (atual->proximo != NULL) { atual = atual->proximo;} atual->proximo = novo_no;}

        novo_no->produto.codigo = buffer.codigo;
        strcpy(novo_no->produto.nome, buffer.nome);
        novo_no->produto.preco = buffer.preco;
        novo_no->produto.quantidade = buffer.quantidade;
    }

    fclose(arquivo_binario);
    return head;
}

void imprimir_lista_produtos_recursivo(NoLista *head) {

    if (head == NULL) {return;}

    printf("- Nome %s\n", head->produto.nome);
    printf("- Quantidade: %d\n", head->produto.quantidade);
    printf("- Produto: %.2f\n", head->produto.preco);
    printf("- Codigo: %d\n", head->produto.codigo);
    printf("\n");

    imprimir_lista_produtos_recursivo(head->proximo);
}


void imprimir_inverso_lista_produtos_recursivo(NoLista *head){
    if (head == NULL) {return;}
    imprimir_inverso_lista_produtos_recursivo(head->proximo);

    printf("- Nome %s\n", head->produto.nome);
    printf("- Quantidade: %d\n", head->produto.quantidade);
    printf("- Produto: %.2f\n", head->produto.preco);
    printf("- Codigo: %d\n", head->produto.codigo);
    printf("\n");
}

int comprimento_lista_recursivo(NoLista *head){
    if (head == NULL) {return 0;}
    return 1 + comprimento_lista_recursivo(head->proximo);
}


int atualiza_preco_produto(NoLista *head, int codigo, float preco){
    NoLista *atual = head;
    while(atual != NULL){
        if (atual->produto.codigo == codigo) {
            atual->produto.preco = preco;
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

int buscar_produto_por_titulo_recursivo(NoLista *head, char titulo_usuario[51]){
    if (head == NULL) {return 0;}

    if(strcmp(head->produto.nome, titulo_usuario) == 0){
        printf("- Nome %s\n", head->produto.nome);
        printf("- Quantidade: %d\n", head->produto.quantidade);
        printf("- Produto: %.2f\n", head->produto.preco);
        printf("- Codigo: %d\n", head->produto.codigo);
        return 1;
    }

    return buscar_produto_por_titulo_recursivo(head->proximo, titulo_usuario);
}


void liberar_lista_produtos_recursivo(NoLista *head){
    if (head == NULL) {return;}
    liberar_lista_produtos_recursivo(head->proximo);
    free(head);
}




int main(void) {
    NoLista *lista_estoque;
    lista_estoque = carrega_estoque_binario("estoque.bin");

    if (lista_estoque == NULL) {
        printf("Nao ha produtos cadastrados no estoque.\n");
        return 0;
    }

    int escolha = 0;

    do {
        printf("Escolha a operacao a ser feita no estoque de produto: \n");
        printf("\t1. Ver em ordem de inclusao os produtos que estao cadastrados.\n");
        printf("\t2. Ver na ordem inversa os produtos que estao cadastrados.\n");
        printf("\t3. Saber quantos produtos estao cadastrados.\n");
        printf("\t4. Atualizar o valor de um produto.\n");
        printf("\t5. Buscar por algum produto especifico.\n");
        printf("\t6. Liberar os produtos da lista.\n");
        printf("\t7. Sair do sistema.\n");

        printf("\nDigite um valor entre 1 e 7: ");
        scanf("%d", &escolha);

        if (escolha == 1) {
            imprimir_lista_produtos_recursivo(lista_estoque);
        }
        else if (escolha == 2) {
            imprimir_inverso_lista_produtos_recursivo(lista_estoque);
        }
        else if (escolha == 3) {
            int tam = comprimento_lista_recursivo(lista_estoque);
            printf("O estoque esta atualmente com %d produtos.\n", tam);
        }
        else if (escolha == 4) {
            int codigo, result;
            float novo_preco;

            printf("Entre com codigo do produto que se deseja atualizar o preco:\n");
            scanf("%d", &codigo);

            printf("Entre com o novo valor do produto:\n");
            scanf("%f", &novo_preco);

            result = atualiza_preco_produto(lista_estoque, codigo, novo_preco);

            if (result)
                printf("Preco atualizado com sucesso.\n");
            else
                printf("Nao foi possivel atualizar o preco do produto desejado.\n");
        }
        else if (escolha == 5) {
            char titulo_usuario[51];
            int result;

            printf("\nDigite o titulo do livro que deseja procurar: ");
            scanf(" %[^\n]", titulo_usuario);


            result = buscar_produto_por_titulo_recursivo(lista_estoque, titulo_usuario);

            if (result)
                printf("Livro encontrado com sucesso.\n");
            else
                printf("Nao foi possivel encontrar o produto desejado.\n");
        }
        else if (escolha == 6) {
            liberar_lista_produtos_recursivo(lista_estoque);
            lista_estoque = NULL;
            printf("Lista liberada.\n");
        }
        else if (escolha != 7) {
            printf("Valor digitado nao eh uma opcao valida do menu. Tente novamente!\n");
        }

        printf("\n------------------------------------------------------\n");

    } while (escolha != 7);

    printf("Encerrando o sistema de estoque...\n");

    return 0;
}
