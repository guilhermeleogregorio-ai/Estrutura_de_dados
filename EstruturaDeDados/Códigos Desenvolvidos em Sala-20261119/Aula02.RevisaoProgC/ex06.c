#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int x;
    long a;
    char* z;
    int y;
} t_ponto;

int main(int argc, char const *argv[]) {
    t_ponto ponto_na_stack;
    t_ponto *ponto_na_heap;


    ponto_na_stack.x = 10;
    ponto_na_stack.y = 2;

    ponto_na_heap = malloc(sizeof(t_ponto));

    // linhas 20 e 21 sao equivalentes as 23 e 24
    (*ponto_na_heap).x = 20;
    (*ponto_na_heap).y = 15;

    ponto_na_heap->x = 20;
    ponto_na_heap->y = 15;

    printf("endereco na stack: %p\n", &ponto_na_heap);
    printf("endereco na heap: %p\n", ponto_na_heap);

    printf("endereco de x: %p\n", &(ponto_na_heap->x));
    printf("endereco de a: %p\n", &(ponto_na_heap->a));
    printf("endereco de y: %p\n", &(ponto_na_heap->y));

    printf("%ld %ld\n", sizeof(t_ponto), sizeof(long));

    free(ponto_na_heap);


    return 0;
}