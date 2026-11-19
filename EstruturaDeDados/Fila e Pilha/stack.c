#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


void create(t_stack *stack){
    stack->top = -1;
}

int is_empty(t_stack *stack){
    if(stack->top == -1){
        return 1;
    } else {
    return 0;
    }
}

int is_full(t_stack *stack){
    if(stack->top == MAX - 1){
        return 1;
    } else {
        return 0;
    }
}

int push(t_stack  *stack , int element){
    if(is_full(stack)) return 0;
    stack->top++;
    stack->items[stack->top] = element;
    return 1;
}

int pop(t_stack *stack, int *out){
    if(is_empty(stack)) return 0;

    *out = stack->items[stack->top];
    stack->top--;
    return 1;
}

int top_value(t_stack *stack, int *out){
    if(is_empty(stack)) return 0;

    *out = stack->items[stack->top];
    return 1;
}

int size(t_stack *stack){
    if(stack->top == -1) return 0;
    return stack->top + 1;
}

void clear(t_stack *stack){
    stack->top = -1;

}