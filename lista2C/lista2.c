#include <stdio.h>

float questao1 (int farenheit) {
    return (farenheit - 32)/9;
}


int main (void) {
    printf("%.2f" , questao1(95));
    return 0;
}

