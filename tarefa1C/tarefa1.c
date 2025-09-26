#include <stdio.h>
#include <math.h>

int main () {
    int lado = 6;
    int perimetro = lado * 3;
    float area = (pow(lado, 2) * pow(3, 0.5))/4;

    printf("Área: %.2f \n", area);
    printf("Perímetro: %d", perimetro);


    return 0;
}