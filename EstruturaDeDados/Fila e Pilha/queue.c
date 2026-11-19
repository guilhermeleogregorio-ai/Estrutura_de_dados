#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


void create(t_queue *queue){
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
}

int is_empty(t_queue *queue){
    if(queue->size == 0)return 1;
    return 0;

}

int is_full(t_queue *queue){
    if(queue->size == MAX) return 1;
    return 0;
}

int in(t_queue *queue, int element){
    if(is_full(queue)) return 0;

    queue->items[queue->rear] = element;
    // queue->rear++; //FILA SIMPLES 
    queue->rear = (queue->rear + 1) % MAX; //FILA CIRCULAR
    queue->size++;
    return 1;
}

int out(t_queue *queue, int *element){
    if(is_empty(queue)) return 0;

    *element = queue->items[queue->front];
    // queue->front++;  FILA SIMPLES 
    queue->front = (queue->front + 1 ) % MAX; // FILA CIRCULAR
    queue->size--;
    return 1;
}

int size(t_queue *queue){
    return queue->size;
}

void clear(t_queue *queue){
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
}

