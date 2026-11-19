#ifndef NODE_H
#define NODE_H


typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct {
    node *head;
    node *tail;
    int size;
} t_list;

#endif