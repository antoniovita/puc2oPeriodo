#include <stdio.h>
#include <math.h>

double volumeEsfera (int raio) {
    double pi = M_PI;
    return  (4.0/3.0) * pi * pow(raio, 3);
}

double volumeCilindro (int raio, int h) {
    double pi = M_PI;
    return pi * pow(raio, 2) * h; 
}

double volumeCalota (int raio, int h) {
    double pi = M_PI;
    return (1.0/3.0) * pi * pow(h, 2) * (3 * raio - h ); 
}

double volumePeca (int raio, int h) {
    double pi = M_PI;
    return (1.0/3.0) * pi * pow(h, 2) * (3 * raio - h);
}


double volumePecaDiametro (int diametroEsfera, int diametroCilindro) {
    double raioEsfera = diametroEsfera/2.0;
    double raioCilindro = diametroCilindro/2.0;

    double hCilindro = 2 * sqrt(pow(raioEsfera, 2) - pow(raioCilindro, 2));

    double volCilindro = volumeCilindro(raioCilindro, hCilindro);
    double volEsfera = volumeEsfera(raioEsfera);

    return volEsfera - volCilindro;
}

int main (void) {
    int raio = 5;
    int h = 8;
    int diametroEsfera = 10;
    int diametroCilindro = 6;

    printf("volumeEsfera(%d) = %lf\n", raio, volumeEsfera(raio));
    printf("volumeCilindro(%d, %d) = %lf\n", raio, h, volumeCilindro(raio, h));
    printf("volumeCalota(%d, %d) = %lf\n", raio, h, volumeCalota(raio, h));
    printf("volumePeca(%d, %d) = %lf\n", raio, h, volumePeca(raio, h));
    printf("volumePecaDiametro(%d, %d) = %lf\n", diametroEsfera, diametroCilindro, volumePecaDiametro(diametroEsfera, diametroCilindro));
    return 0;
}
