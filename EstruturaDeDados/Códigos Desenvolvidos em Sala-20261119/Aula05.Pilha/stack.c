#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

t_stack* create_stack(int max) {
    t_stack *pilha = malloc(sizeof(t_stack));
    pilha->max = max;
    pilha->top_index = -1;
    pilha->items = malloc(sizeof(int) * max);
    return pilha;
}

void destroy(t_stack* pilha) {
    free(pilha->items);
    free(pilha);
}

int is_empty(t_stack* pilha) {
    return pilha->top_index < 0;
}

int is_full(t_stack* pilha) {
    return pilha->top_index >= pilha->max - 1;
}

int push(t_stack* pilha, int x) {
    if (is_full(pilha)) {
        return 0;
    }
    pilha->top_index++;
    pilha->items[pilha->top_index] = x;
    return 1;
}

int pop(t_stack* pilha, int *x) {
    if (is_empty(pilha)) {
        return 0;
    }
    *x = pilha->items[pilha->top_index];
    pilha->top_index--;
    return 1;
}
int top(t_stack* pilha, int *x) {
    if (is_empty(pilha)) {
        return 0;
    }
    *x = pilha->items[pilha->top_index];
    return 1;
}
// void clear(t_stack*);
// int size(t_stack*);
// void print(t_stack*);