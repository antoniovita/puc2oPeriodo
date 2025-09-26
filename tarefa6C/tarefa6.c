#include <stdio.h>
#define QTD_RESPOSTAS 40

int main (void) {
    int respostas[QTD_RESPOSTAS] = {1, 2, 6, 4, 8, 5, 9, 7, 8, 10, 1, 6, 3, 8, 6, 3, 8, 6, 10, 3, 8, 2, 7, 6, 5, 7, 6, 8, 6, 7, 5, 6, 6, 5, 6, 7, 5,6, 4,8};    
    int avaliacoes_frequencia[10] = {0, 0, 0, 0, 0 , 0 , 0, 0 , 0 , 0};
    
    
    for (int i = 0; i < QTD_RESPOSTAS; i++) {
        avaliacoes_frequencia[respostas[i] - 1]++;
    }

    printf("Avaliações           Frequência\n");
    for (int elem = 0; elem < 10; elem++) {
        printf("%d                  %d\n", elem + 1, avaliacoes_frequencia[elem]);
    }

    return 0;

}