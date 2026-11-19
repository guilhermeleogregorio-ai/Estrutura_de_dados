#include <stdio.h>
#include <stdlib.h>


void reverse_in_place(t_list *list){
    if(is_empty(list)) return ;

    int aux = 0;
    for(int i = 0; i < list->size / 2; i++){
            aux = list->items[i];
            list->items[i] = list->items[list->size -1 -i];
            list->items[list->size -1 -i] = aux;
        }
}