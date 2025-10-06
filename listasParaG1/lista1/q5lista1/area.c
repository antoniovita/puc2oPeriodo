#include "area.h"
#define PI 3.14

float area_quadrado(float l) {
    return l * l;
}

float area_triangulo(float b, float h) {
    return (b * h) / 2.0f;
}

float area_circulo(float r) {
    return PI * r * r;
}

