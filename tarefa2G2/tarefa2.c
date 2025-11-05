#include <math.h>
#include <stdio.h>

typedef struct ponto {
    float x;
    float y;
} Ponto;

typedef struct circulo {
    Ponto p;
    float r;
} Circulo;

/*
1. Implemente uma função que determina se dois círculos se interceptam. A função deve receber os
ponteiros para os dois círculos e retornar 1, se houver interseção, ou 0, caso contrário.
*/

int intersecta(const Circulo *circulo1, const Circulo *circulo2) {
    float dx = circulo1->p.x - circulo2->p.x; 
    float dy = circulo1->p.y - circulo2->p.y;
    float dist = dx*dx + dy*dy;
    float soma_raios = circulo1->r + circulo2->r;

    if (sqrt(dist) > soma_raios) {
        return 0;
    }

    return 1;
}

int main() {
    Circulo c1, c2;

    c1.p.x = 3.0f;
    c1.p.y = 5.0f;
    c1.r = 4.0f;

    c2.p.x = 3.0f;
    c2.p.y = 5.0f;
    c2.r = 4.0f;

    printf("%d", intersecta(&c1, &c2));
    return 0;
}
