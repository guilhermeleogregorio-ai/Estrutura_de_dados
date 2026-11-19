#ifndef QUEUE_H
#define QUEUE_H

#define MAX 100

typedef struct {
    int items[MAX];
    int front;  // índice do início
    int rear;   // índice do fim (próxima posição livre)
    int size;   // quantidade de elementos
} t_queue;

void create(t_queue *queue);
int is_empty(t_queue *queue);
int is_full(t_queue *queue);
int in(t_queue *queue, int element);
int out(t_queue *queue, int *element);
int size(t_queue *queue);
void clear(t_queue *queue);

#endif