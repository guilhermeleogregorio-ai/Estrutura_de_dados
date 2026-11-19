#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

int main(int argc, char const *argv[]) {
    t_stack *pilha;
    pilha = create_stack(10);

    push(pilha, 3);
    push(pilha, 8);
    push(pilha, 9);
    push(pilha, 4);

    int x;

    pop(pilha, &x);

    printf("%d\n", x);

    destroy(pilha);
    return 0;
}
