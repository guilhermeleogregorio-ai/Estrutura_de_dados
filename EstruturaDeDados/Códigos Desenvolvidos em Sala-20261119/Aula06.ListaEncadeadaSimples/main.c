#include<stdio.h>
#include<stdlib.h>

typedef struct _node {
    int item;
    struct _node *next;
} t_node;

typedef struct {
    t_node *head;
    t_node *tail;
    int size;
} t_list;

t_list* create_list() {
    t_list* list;
    list = malloc(sizeof(t_list));
    
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

int is_empty(t_list *list) {
    return list->size == 0;
}

int append(t_list *list, int item) {
    t_node *node;
    node = malloc(sizeof(t_node));
    node->next = NULL;
    node->item = item;

    if (is_empty(list)) {
        list->head = node;
    } else {
        list->tail->next = node;
    }
    list->tail = node;
    list->size++;
    return 1;
}

void print_list(t_list *list) {
    t_node *p;
    p = list->head;
    while (p != NULL) {
        printf("%d ", p->item);
        p = p->next;
    }
    printf("\n");
}

int remove_item(t_list *list, t_node *node_to_remove) {
    // se a lista possui apenas um
    if (list->size == 1) {
        list->head = NULL;
        list->tail = NULL;
    } else if (list->head == node_to_remove) { // se node_to_remove é o primeiro elemento
        list->head = list->head->next;
    } else {
        t_node *prev = list->head;
        while (prev->next != node_to_remove) {
            prev = prev->next;
        }
        prev->next = node_to_remove->next;
        // caso remocao do elemento tail
        if (node_to_remove == list->tail) {
            list->tail = prev;
        }
    }
    free(node_to_remove);
    list->size--;
}

t_node* get_node_item(t_list *list, int item) {
    t_node *node = list->head;

    while(node != NULL && node->item != item){
        node = node->next;
    }

    return node;
}

t_node* get_node_by_index(t_list *list, int index) {
    if (index >= list->size || index < 0) {
        return NULL;
    }
    t_node *node = list->head;
    int i = 0;
    while (i < index) {
        i++;
        node = node->next;
    }
    return node;
}



void clear(t_list *list) {
    t_node *p = list->head;
    while(p != NULL) {
        t_node *q = p;
        p = p->next;
        free(q);
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void destroy_list(t_list *list) {
    clear(list);
    free(list);
}

int main(int argc, char const *argv[]) {
    t_list *list;
    list = create_list();
    append(list, 7);
    append(list, 10);
    append(list, 5);
    append(list, 12);
    append(list, 3);
    append(list, 8);

    print_list(list);

    //destroy_list();
    return 0;
}
