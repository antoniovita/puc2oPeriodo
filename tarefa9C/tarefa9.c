#include <stdio.h>
#include <string.h>

int conta_ocorrencias(char* s, char c) {
    int cont = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == c) {
            cont = cont + 1;
        }
    }
    return cont;
}

int main(void) {
    char palavra[] = "antonio";
    printf("Quantidade de 'n' em \"%s\": %d\n", palavra, conta_ocorrencias(palavra, 'n'));
    return 0;
}
