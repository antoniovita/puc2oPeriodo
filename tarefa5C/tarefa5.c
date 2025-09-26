#include <stdio.h>
# include <math.h>

void calcular_volume_area (double raio, double altura, double *vol, double *area) {

    *vol = (1.0/3.0) * M_PI * pow(raio, 2) * altura;
    *area = M_PI * raio * (raio + sqrt(pow(raio, 2) + pow(altura, 2)));

}

int main (void) {

    double raio;
    double altura;

    double vol;
    double area;

    printf("Insira o raio e depois a altura:");
    scanf("%lf %lf", &raio, &altura);

    calcular_volume_area(raio, altura, &vol, &area);

    printf(" O volume é %.2lf e área é %.2lf.", vol, area);

    return 0;
}