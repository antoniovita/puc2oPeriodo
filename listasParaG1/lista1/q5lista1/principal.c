#include <stdio.h>
#include "area.h"
#include "volume.h"

int main(void) {
    int opcao;        // -1 para sair, 1 = área, 2 = volume
    int forma;        // subopção de forma
    float l, b, h, r; // dimensões
    float resultado;

    do {
        printf("\n=== CALCULADORA DE AREA E VOLUME ===\n");
        printf("1) Calcular AREA\n");
        printf("2) Calcular VOLUME\n");
        printf("-1) Sair\n");
        printf("Escolha: ");
        if (scanf("%d", &opcao) != 1) return 0;

        switch (opcao) {
            case 1: // Áreas
                printf("\n-- AREAS --\n");
                printf("1) Quadrado (lado)\n");
                printf("2) Triangulo (base e altura)\n");
                printf("3) Circulo (raio)\n");
                printf("Escolha a forma: ");
                if (scanf("%d", &forma) != 1) return 0;

                switch (forma) {
                    case 1:
                        printf("Lado l: ");
                        scanf("%f", &l);
                        resultado = area_quadrado(l);
                        printf("Area do quadrado = %.4f\n", resultado);
                        break;
                    case 2:
                        printf("Base b: ");
                        scanf("%f", &b);
                        printf("Altura h: ");
                        scanf("%f", &h);
                        resultado = area_triangulo(b, h);
                        printf("Area do triangulo = %.4f\n", resultado);
                        break;
                    case 3:
                        printf("Raio r: ");
                        scanf("%f", &r);
                        resultado = area_circulo(r);
                        printf("Area do circulo = %.4f\n", resultado);
                        break;
                    default:
                        printf("Forma invalida.\n");
                }
                break;

            case 2: // Volumes
                printf("\n-- VOLUMES --\n");
                printf("1) Cubo (lado)\n");
                printf("2) Cone (raio e altura)\n");
                printf("3) Esfera (raio)\n");
                printf("Escolha a forma: ");
                if (scanf("%d", &forma) != 1) return 0;

                switch (forma) {
                    case 1:
                        printf("Lado l: ");
                        scanf("%f", &l);
                        resultado = volume_cubo(l);
                        printf("Volume do cubo = %.4f\n", resultado);
                        break;
                    case 2:
                        printf("Raio r: ");
                        scanf("%f", &r);
                        printf("Altura h: ");
                        scanf("%f", &h);
                        resultado = volume_cone(r, h);
                        printf("Volume do cone = %.4f\n", resultado);
                        break;
                    case 3:
                        printf("Raio r: ");
                        scanf("%f", &r);
                        resultado = volume_esfera(r);
                        printf("Volume da esfera = %.4f\n", resultado);
                        break;
                    default:
                        printf("Forma invalida.\n");
                }
                break;

            case -1:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != -1);

    return 0;
}
