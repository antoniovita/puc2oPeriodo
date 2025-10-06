#include <stdio.h>

/*
1)
int main (void) {
    int codigo;
    printf("Insira o codigo do aluno:");
    scanf("%d", &codigo);

    int ano = codigo/10000;
    int periodo = (codigo/1000) % 10;
    int posicao = codigo % 1000;

    printf("O período é o %do, o ano é %d e a posicao foi %d", periodo, ano, posicao);
    return 0;
}
*/

/*
2)

int somaDivisores (int num) {
    int sum = 0;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            sum = sum + i;
        }
    }

    return sum;
}

int numAmigaveis (int numInicio, int numFinal) {
    for (int i = numInicio; i < numFinal; i++) {
        int amigavel = somaDivisores(i);
        printf("Par amigavel: (%d, %d) \n", i, amigavel);
    }
    return 0;
}


int main (void) {
    // letra a) printf("%d", somaDivisores(10));
    // letra b) numAmigaveis(1, 5);
    int numInicio;
    int numFinal;

    printf("Insira o numero inicial: ");
    scanf("%d", &numInicio);

    printf("Insira o numero final: ");
    scanf("%d", &numFinal);

    numAmigaveis(numInicio, numFinal);

    return 0;
}

*/

/*
3)
int main (void) {
    float km;
    float L;
    printf("Insira os km rodados: ");
    scanf(" %f", &km);
    printf("Insira os litos consumidos: ");
    scanf(" %f", &L);

    float consumo = km/L;
    printf("Consumo medio foi de %.2f km/L", consumo);

    return 0;
}

*/

/*
4)
int main (void) {
    int codigo, quantidade;
    float total;
    
    // em C o 1 eh o true, nao tem tipos booleanos
    while (1) {
        printf("Insira o codigo do produto: ");
        scanf("%d", &codigo);

        if (codigo > 5 || codigo < 0) {
            break; // esse break aqui encerra o while
        }

        printf("Insira a quantidade do produto: ");
        scanf("%d", &quantidade);

        switch (codigo) {
            case 1:
                total += quantidade * 2.98;
                break;
            case 2:
                total += quantidade * 4.50;
                break;
            case 3:
                total += quantidade * 9.98;
                break;
            case 4:
                total += quantidade * 4.49;
                break;
            case 5:
                total += quantidade * 6.87;
                break;
        }
    }

    printf("O total foi de: %.2f \n", total);

    return 0;
}
*/

