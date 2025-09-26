#include <stdio.h>

int main (void) {
    double tempC, tempF;
    printf("Digite a temperatura em graus Celsius: ");
    scanf("%lf", &tempC);
    tempF = 1.8 * tempC + 32;
    printf("%.2f graus Celsius equivale a %.2f graus Farenheit", tempC, tempF);
    return 0;
}

