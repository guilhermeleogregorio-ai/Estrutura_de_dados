#ifndef STACK_H
#define STACK_H


#define MAX 100

typedef struct {
    int items[MAX];
    int top;   // índice do topo; -1 quando vazia
} t_stack;

void create(t_stack *stack);
int is_empty(t_stack *stack);
int is_full(t_stack *stack);
int push(t_stack  *stack , int element);
int pop(t_stack *stack, int *out);
int top_value(t_stack *stack, int *out);
int size(t_stack *stack);
void clear(t_stack *stack);

#endif