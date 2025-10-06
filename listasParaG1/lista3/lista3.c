/*
Questão 1) 
Escreva um programa que declare:
  - um inteiro, um real e um char,
  - ponteiros para inteiro, real e char.

Inicialize as variáveis com valores válidos.
Associe as variáveis aos ponteiros (usando &).
Modifique os valores das variáveis usando os ponteiros.
Imprima os valores das variáveis antes e após a modificação.
*/

#include <stdio.h>

int main(void) {
    // Declaração e inicialização de variáveis normais
    int a = 2;
    float b = 3.4;
    char c = 'a';

    // Declaração de ponteiros e associação aos endereços das variáveis
    int *d = &a;     // d guarda o endereço de a
    float *e = &b;   // e guarda o endereço de b
    char *f = &c;    // f guarda o endereço de c

    // Impressão dos valores originais
    printf("a antes: %d\n", a);
    printf("b antes: %f\n", b);
    printf("c antes: %c\n", c);

    // Explicando a diferença entre usar o ponteiro e desreferenciá-lo
    printf("\n--- Demonstração com ponteiro d (inteiro) ---\n");
    printf("Conteúdo de d (endereço de a): %p\n", d);     // imprime o endereço armazenado em d (endereço de a)
    printf("Valor armazenado nesse endereço (*d): %d\n", *d); // imprime o valor que está no endereço apontado por d (valor de a)

    /*
      IMPORTANTE:
      - d    → armazena o endereço de a
      - *d   → acessa/modifica o valor de a diretamente, pois segue o endereço guardado em d
    */

    // Alterando os valores das variáveis por meio dos ponteiros
    *d = 25;   // altera o valor de a (que era 2) para 25
    *e = 9.5;  // altera o valor de b (que era 3.4) para 9.5
    *f = 'j';  // altera o valor de c (que era 'a') para 'j'

    // Impressão dos valores após a modificação
    printf("\n--- Valores depois da modificação via ponteiros ---\n");
    printf("a depois: %d\n", a);
    printf("b depois: %f\n", b);
    printf("c depois: %c\n", c);

    return 0;
}
