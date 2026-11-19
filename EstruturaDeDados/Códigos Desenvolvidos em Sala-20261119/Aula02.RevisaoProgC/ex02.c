#include<stdio.h>

int swap_errado(int a, int b) {
    int aux = a;
    a = b;
    b = aux;
}

int swap(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main(int argc, char const *argv[]) {
    int x = 5;
    int y = 10;

    printf("antes: %d %d\n", x, y);
    swap(&x, &y);
    printf("depois: %d %d\n", x, y);

    return 0;
}
