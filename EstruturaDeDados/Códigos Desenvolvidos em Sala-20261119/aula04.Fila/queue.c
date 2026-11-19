#include<stdio.h>
#include<stdlib.h>
#include"queue.h"


t_queue* create_queue(int max) {
    t_queue *fila = malloc(sizeof(t_queue));
    fila->max = max;
    fila->items = malloc(sizeof(int) * max);
    fila->size = 0;
    fila->begin = 0;
    fila->end = 0;
    return fila;
}

int in(t_queue *fila, int x) {
    if (is_full(fila)) {
        return 0;
    }
    fila->items[fila->end] = x;
    fila->end = (fila->end + 1) % fila->max;
    fila->size++;
    return 1;
}

int out(t_queue *fila, int *x) {
    if (is_empty(fila)) {
        return 0;
    }
    *x = fila->items[fila->begin];
    fila->begin = (fila->begin + 1) % fila->max;
    fila->size--;
    return 1;
}