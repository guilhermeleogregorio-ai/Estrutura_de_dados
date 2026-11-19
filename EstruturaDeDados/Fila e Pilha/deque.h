#ifndef DEQUE_H
#define DEQUE_H

#define MAX 100

typedef struct {
    int items[MAX];
    int front;
    int rear;
    int size;
} t_deque;

void create(t_deque *deque);
int  is_empty(t_deque *deque);
int  is_full(t_deque *deque);
int in_begin(t_deque *deque, int element);
int in_end(t_deque *deque, int element);
int out_begin(t_deque *deque, int *element);
int out_end(t_deque *deque, int *element);
int  size(t_deque *deque);

#endif