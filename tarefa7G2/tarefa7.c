#include <stdio.h>
#include <string.h>

int eh_palindromo(char str[], int inicio, int fim) {
    if (inicio >= fim) {
        return 1;
    }
    if (str[inicio] == str[fim]) {
        return eh_palindromo(str, inicio + 1, fim - 1);
    } else {
        return 0;
    }
}

void inverte(char str[], int inicio, int fim) {
    if (inicio >= fim ) {
        return;
    }
    char temp = str[inicio];
    str[inicio] = str[fim];
    str[fim] = temp;
    inicio ++;
    fim --;
    inverte(str, inicio, fim);
}

int main (void) {
    int resultado = eh_palindromo("maam", 0, 3);
    printf("%d\n", resultado);


    printf("\n");

    char antonio[] = "antonio";
    printf("%s\n", antonio);
    inverte(antonio, 0, 6);
    printf("%s", antonio);

    return 0;
}
