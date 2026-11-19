#ifndef LIST_H
#define LIST_H

#define MAX 100

typedef struct 
{
    int items[MAX];
    int size;
}t_list;

void create(t_list *list);
int is_empty(t_list *list);
int is_full(t_list *list);
int append(t_list *list, int element);
void print_list(t_list *list);
int insert(t_list *list, int element, int index);
int get(t_list *list, int index, int *out);
int update(t_list *list, int element, int index);
int remove_by_index(t_list *list, int index);
int index_of(t_list * list, int element);
int remove_by_element(t_list *list, int element);
int remove_by_element_2(t_list *list, int element);
int count(t_list *list, int element);
void copy(t_list *src, t_list *dest);
void copy_no_duplicates(t_list *src, t_list *dest);
void reverse_to(t_list *src, t_list *dest);
void reverse_in_place(t_list *list);
void remove_all(t_list *list, int element);
void merge_sorted(t_list *l1, t_list *l2, t_list *l3);
int insert_ordered(t_list *list, int element);
int search_binary(t_list *list, int element);
int equals(t_list *l1, t_list *l2);
#endif