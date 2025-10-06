#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* NIKMOCHUNPRE */
char** split (char* codigo) {
    int len[] = {3, 4, 2, 3};
    int index[] = {0, 3, 7, 9};

    char **retorno = malloc( 4 * sizeof(char*));

    for (int i = 0; i < 4; i++){
        retorno[i] = malloc( (len[i] + 1) * sizeof(char)); //toda string = len + 1 pq o final dela é sempre \0
        
        strncpy(retorno[i], codigo + index[i], len[i]);
        retorno[i][len[i]] = '\0';
    }

    return retorno;
}


int main (void) {
    char codigo[] = "NIKMOCHUNPRE";
    char** retorno = split(codigo);

    printf("%s \n", retorno[0]);
    printf("%s \n", retorno[1]);
    printf("%s \n", retorno[2]);
    printf("%s \n", retorno[3]);
}