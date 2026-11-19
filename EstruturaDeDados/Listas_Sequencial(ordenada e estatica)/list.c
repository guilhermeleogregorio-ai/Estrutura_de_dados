#include <stdio.h>
#include <stdlib.h>
#include "list.h"



void create(t_list *list){
    list->size = 0;
}

int is_empty(t_list *list){
    if(list->size == 0){
        return 1;
    }else {
        return 0;
    }
}

int is_full(t_list *list){
    if(list->size == MAX){
        return 1;
    }else{
        return 0;
    }
}

int append(t_list *list, int element){
    if(is_full(list)){
        return 0;
    }

    list->items[list->size] = element;
    list->size++;
    return 1;
}

void print_list(t_list *list){
    if(is_empty(list)) return;

    for(int i = 0 ; i < list->size; i++){
        int element = list->items[i];
        printf("%d ", element);
    }
    printf("\n");
}

int insert(t_list *list, int element, int index){
    if(is_full(list)) return 0;

    if(index < 0 || index > list->size) return 0;

    if(index >= 0 && index < list->size){
        for(int i = list->size - 1 ; i >= index ; i--){
            list->items[i + 1] = list->items[i];
        }
        list->items[index] = element;
    }

    if(index == list->size){
        list->items[list->size] = element;
    }
    list->size++; 
    return 1;
    
}  

int get(t_list *list, int index, int *out){
    if(is_empty(list)) return 0;

    if(index >=0 && index < list->size){    
        *out = list->items[index];
        return 1;
    } else {
        return 0;
    }
}

int update(t_list *list, int element, int index){
    if(index >= 0 && index < list->size){
        list->items[index] = element;
        return 1;
    } 
    return 0;
}

int remove_by_index(t_list *list, int index){
    if(index >= 0 && index < list->size){
        for(int i = index; i <list->size -1 ; i++){
            list->items[i] = list->items[i+1];
        }
        list->size--;
        return 1;
    }
    return 0;
}

int index_of(t_list * list, int element){
    for(int i = 0; i < list->size ; i++){
        if(list->items[i] == element){
            return i;
        } 
    }
    return -1;
}

int remove_by_element(t_list *list, int element){
    int index = index_of(list, element);
    if(index < 0){
         return 0;
    } else {
        remove_by_index(list,index);
        return 1;
    }
}

int remove_by_element_2(t_list *list, int element){
    for(int i = 0 ; i < list->size ; i++){
        if(list->items[i] == element){
            int index = i;
            for(int j = index; j < list->size -1 ; j++){
                list->items[j] = list->items[j + 1];
            }
            list->size--;
            return 1;
        }
    }
    return 0;
}

int count(t_list *list, int element){
    int contador = 0;
    for(int i = 0 ; i < list->size;i++){
        if(list->items[i] == element){
            contador++;
        }
    }
    return contador;
}

int is_sorted(t_list *list){
    for(int i = 0 ; i < list->size - 1 ; i++){
        if(list->items[i] > list->items[i + 1]){
            return 0;    
        } 
    }
    return 1;
}

void copy(t_list *src, t_list *dest){
    if(is_full(dest)) return;
    for(int i = 0 ; i < src->size; i++){
        dest->items[i] = src->items[i];
        dest->size++;
    }
}

void copy_no_duplicates(t_list *src, t_list *dest){
    if(is_full(dest)) return;
    for(int i = 0; i < src->size; i++){
        if(index_of(dest, src->items[i])== -1 ){
             dest->items[dest->size] = src->items[i];
            dest->size++;
        }
    }
}

void reverse_to(t_list *src, t_list *dest){
    dest->size = 0;
    int j = 0;
    for(int i = src->size -1 ; i >= 0; i--){
        dest->items[j] = src->items[i];
        j++;
        dest->size++;
    }
}

void reverse_in_place(t_list *list){
    int aux= 0;
    for(int i = 0 ; i < list->size/2 ; i++){
            aux = list->items[i];
            list->items[i] = list->items[list->size -1 -i];
            list->items[list->size -1 -i] = aux;
    }
}

void remove_all(t_list *list, int element){
            while(count(list,element) != 0){
            remove_by_element(list,element);
            }
}

void merge_sorted(t_list *l1, t_list *l2, t_list *l3){
    if(is_sorted(l1) == 0 || is_sorted(l2) == 0) return;
    int i = 0;
    int j = 0;

    while(i < l1->size && j < l2->size){
    if(l1->items[i]<l2->items[j]){
        l3->items[l3->size] = l1->items[i];
        i++;
    } else{
        l3->items[l3->size] = l2->items[j];
        j++;
    }
    l3->size++;
 }
    while(i < l1->size){
    l3->items[l3->size] = l1->items[i];
    i++;
    l3->size++;
    }

    while(j < l2->size){
    l3->items[l3->size] = l2->items[j];
    j++;
    l3->size++;
    }
}

int insert_ordered(t_list *list, int element){
    if(is_full(list)) return 0;
    int index =0;

    for(int i = 0; i < list->size ; i++){
        if(list->items[i] > element){
            index = i;
            for(int j = list->size - 1 ; j >= index; j--){
            list->items[j + 1] =  list->items[j];
            }
            list->items[index] = element;
            list->size++;
            return 1;
        }
    }
    return append(list,element);
}

int search_binary(t_list *list, int element){
    int inicio = 0;
    int fim = list->size -1;
    int meio ;

    while(inicio <= fim){
    meio = (inicio + fim) / 2 ;
    if(element == list->items[meio]) return meio;

    if(element > list->items[meio]){
        inicio = meio + 1;
    }
    if(element < list->items[meio]){
        fim = meio - 1;
    }
}
    return -1;
}

int equals(t_list *l1, t_list *l2){
    if(l1->size != l2->size) return 0;
    int i = 0;
    while(i < l1->size){
        if(l1->items[i] == l2->items[i]){
            i++;
    } else {
        return 0;
    }
}
return 1;
}
