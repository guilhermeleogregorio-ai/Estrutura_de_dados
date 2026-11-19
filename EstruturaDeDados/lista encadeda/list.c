#include <stdio.h>
#include <stdlib.h>
#include "list.h"


void create_list(t_list *list){
    list->tail = NULL;
    list->head = NULL;
    list->size = 0;
}

int is_empty(t_list *list){
    if(list->tail == NULL && list->size ==0) return 1;
    return 0;
}

void print_list(t_list *list){
    if(is_empty(list))  return;
    node *current;
    current = list->head;
    
    while(current != NULL){
        printf(" %d" , current->data);
        current = current->next;
        }
    
}

int insert_front(t_list *list, int valor){
    node *novo_no = (node*)malloc(sizeof(node));

    if(novo_no == NULL) return 0;

    novo_no->data = valor;
    novo_no->next = list->head;
    list->head = novo_no;
    list->size++;
    return 1;

}

int insert_back(t_list *list, int valor){
    node *novo_no = (node*)malloc(sizeof(node));

    if(novo_no == NULL) return 0;

    novo_no->data = valor;
    novo_no->next = list->tail;
    list->tail = novo_no;
    list->size++;
    return 1;
}

int insert(t_list *list, int index, int valor){
    if (index < 0 || index > list->size) return 0;
    
    if(index == 0) insert_front(list,valor);
    if(index == list->tail) insert_back(list, valor);
    
    node *novo_no = (node*)malloc(sizeof(node));
    if(novo_no == NULL) return 0;
    novo_no->data = valor;
    node *anterior =list->head;

    for(int i = 0; i< index - 1; i++){
        anterior = anterior->next;
    }
    novo_no->next = anterior->next;
    anterior->next = novo_no;
    list->size++;
    return 1; 
}

int get(t_list *list, int out){
    if(out < 0 || out >= list->size) return -1;

    if(out == list->size -1){
        return list->tail->data;
    }

    node *atual = list->head;
    for(int i = 0; i < out ; i++){
        atual = atual->next;
    }

    return atual->data;
}

void update(t_list *list,int out, int valor){
    if(out < 0 || out >= list->size) return;

    if(out == list->size -1){
        list->tail->data = valor;
        return;
    }

    node *atual = list->head;
    for(int i = 0 ; i < out; i++){
        atual = atual->next;
    }
    atual->data = valor;
}

int remove_front(t_list *list){
    if(is_empty(list)) return 0;

    node *remover = list->head;

    list->head = list->head->next;
    free(remover);
    list->size--;

    if(list->size == 0){
        list->tail = NULL;
    }
    return 1;
}
 
int remove_back(t_list *list){
    if(is_empty(list)) return 0;
    if(list->size == 1){
        remove_front(list);
        return 1;
    }
    node *remover = list->tail;
    node *anterior = list->head;
    for(int i = 0 ; i < list->size - 2; i++){
        anterior = anterior->next;
    }
    list->tail = anterior;
    anterior->next = NULL;
    free(remover);
    list->size--;
    return 1;
}

int remove(t_list *list, int out){
    if(is_empty(list)) return 0;

    if(out < 0 || out >= list->size) return 0;

    if(out == 0) remove_front(list);
    if(out == list->size - 1) remove_back(list);

    node *anterior = list->head;
    for(int i = 0; i < out-1; i++){
        anterior = anterior->next;
    }
    node *remover = anterior->next;
    anterior->next = remover->next;
    free(remover);
    list->size--;
    return 1;
}

int contains(t_list *list, int valor){
    if(is_empty(list)) return 0;

    node *atual = list->head;
    for(int i = 0; i < list->size; i++){
        if(atual->data == valor){
            return 1;
        }
        atual = atual->next;
    }
    return 0;
}

int index_of(t_list *list, int out){
    if(is_empty(list)) return -1;

    node *atual = list->head;
    for(int i = 0; i < list->size; i++){
        if(atual->data == out){
            return i;
        }
        atual= atual->next;
    }
    return -1;
}

int size(t_list *list){
    if(list == NULL) return 0;
    return list->size;
}

void clear(t_list *list){
    if(is_empty(list)) return;


    node *atual = list->head;
    node *proximo;
    while(atual != NULL){
        proximo = atual->next;
        free(proximo);
        atual = proximo;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void reverse(t_list *list){
    if(is_empty(list) || list == NULL) return;

    node *anterior = NULL;
    node *atual = list->head;
    node *proximo = NULL;

    list->tail = list->head;

    while (atual != NULL){
        proximo = atual->next;
        atual->next = anterior;

        anterior = atual;
        atual = proximo;
    }
    list->head = anterior;
}