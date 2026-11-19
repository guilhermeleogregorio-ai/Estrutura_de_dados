#include <stdio.h>
#include <stdlib.h>
#include "deque.h"


void create(t_deque *deque){
    deque->front = 0;
    deque->rear = 0;
    deque->size = 0;
}

int is_empty(t_deque *deque){
    if(deque->size == 0) return 1;
    return 0;
}

int is_full(t_deque *deque){
    if(deque->size == MAX) return 1;
    return 0;
}

int size(t_deque *deque){
    return deque->size;
}

int in_begin(t_deque *deque, int element){
    if(is_full(deque)) return 0;

    deque->front= (deque->front - 1 + MAX) % MAX;
    deque->items[deque->front] = element;
    deque->size++;
    return 1;
}

int in_end(t_deque *deque, int element){
    if(is_full(deque)) return 0;

    deque->items[deque->rear] = element;
    deque->rear = (deque->rear + 1 ) % MAX;
    deque->size++;
    return 1;
}

int out_begin(t_deque *deque, int *element){
    if(is_empty(deque)) return 0;

    *element = deque->items[deque->front];
    deque->front = (deque->front + 1 ) % MAX;
    deque->size --;
    return 1;
}

int out_end(t_deque *deque, int *element){
    if(is_empty(deque)) return 0;

    *element = deque->items[deque->rear - 1];
    deque->rear = (deque->rear -1 + MAX ) % MAX;
    deque->size--;
    return 1;
}