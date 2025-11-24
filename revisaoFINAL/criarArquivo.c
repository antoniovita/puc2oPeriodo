#include <stdio.h>
#include <string.h>

typedef struct {
	int codigo;
	char nome[100];
	float preco;
	int quantidade;
} Produto;

int main(void) {
	FILE *saida = fopen("estoque.bin", "wb");
	if (saida == NULL) {
		perror("Erro ao criar arquivo de teste");
		return 1;
	}

	Produto p1 = { 101, "C For Dummies", 450.41f, 50 };
	Produto p2 = { 102, "C Completo e Total", 472.22f, 30 };
	Produto p3 = { 103, "Curso Basico da Linguagem C", 62.30f, 100 };
	Produto p4 = { 104, "C como Programar?", 413.94f, 20 };
	Produto p5 = { 105, "Introducao a Estrutura de Dados", 199.00f, 80 };

	fwrite(&p1, sizeof(Produto), 1, saida);
	fwrite(&p2, sizeof(Produto), 1, saida);
	fwrite(&p3, sizeof(Produto), 1, saida);
	fwrite(&p4, sizeof(Produto), 1, saida);
	fwrite(&p5, sizeof(Produto), 1, saida);

	fclose(saida);

	printf("Arquivo 'estoque.bin' de teste criado com sucesso com 5 produtos.\n");
	return 0;
}