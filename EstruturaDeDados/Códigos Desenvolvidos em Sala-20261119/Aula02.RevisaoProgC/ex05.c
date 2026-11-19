#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[]) {
    int linhas = 100000;
    int colunas = linhas;

    // int matriz[linhas][colunas];

    printf("alocando memoria...\n");
    int **matriz;
    matriz = calloc(linhas, sizeof(int *));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = calloc(colunas, sizeof(int));
    }
    getchar();
    // printf("liberando memoria...\n");
    // for (int i = 0; i < linhas; i++) {
    //     free(matriz[i]);
    // }
    // free(matriz);



    return 0;
}
