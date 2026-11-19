#include <stdio.h>
#include "list.h"

int main() {
    t_list list;
    create(&list);

    /* ===== Bloco 1 ===== */
    printf("== Bloco 1 ==\n");
    printf("is_empty (esperado 1): %d\n", is_empty(&list));

    append(&list, 5);
    append(&list, 10);
    append(&list, 15);
    printf("Lista esperada: 5 10 15\n");
    printf("Lista obtida:   ");
    print_list(&list);

    printf("is_empty (esperado 0): %d\n", is_empty(&list));

    // ===== Bloco 2 (descomente quando terminar o Bloco 1) =====
    printf("\n== Bloco 2 ==\n");
    insert(&list, 7, 1);
    printf("Esperado: 5 7 10 15\n");
    printf("Obtido:   ");
    print_list(&list);

    update(&list, 99, 0);
    printf("Esperado: 99 7 10 15\n");
    printf("Obtido:   ");
    print_list(&list);
    

    // ===== Bloco 3 =====
    printf("\n== Bloco 3 ==\n");
    t_list l2;
    create(&l2);
    append(&l2, 3); append(&l2, 7); append(&l2, 3); append(&l2, 9); append(&l2, 3);
    printf("count(3) esperado 3, obtido: %d\n", count(&l2, 3));

    remove_by_element(&l2, 3);
    printf("Esperado: 7 3 9 3\n");
    printf("Obtido:   ");
    print_list(&l2);
    t_list l2b;
    create(&l2b);
    append(&l2b, 3); append(&l2b, 7); append(&l2b, 3); append(&l2b, 9); append(&l2b, 3);
    remove_by_element_2(&l2b, 3);
    printf("Esperado (v2): 7 3 9 3\n");
    printf("Obtido (v2):   ");
    print_list(&l2b);

    //===== Bloco 4 =====
    printf("\n== Bloco 4 ==\n");
    t_list l3;
    create(&l3);
    append(&l3, 1); append(&l3, 2); append(&l3, 2); append(&l3, 3); append(&l3, 2);
    remove_all(&l3, 2);
    printf("Esperado: 1 3\n");
    printf("Obtido:   ");
    print_list(&l3);
    

    // ===== Bloco 5 =====
    printf("\n== Bloco 5 ==\n");
    t_list a, b, c;
    create(&a); create(&b); create(&c);
    append(&a, 1); append(&a, 3); append(&a, 5);
    append(&b, 2); append(&b, 4); append(&b, 6);
    merge_sorted(&a, &b, &c);
    printf("Esperado: 1 2 3 4 5 6\n");
    printf("Obtido:   ");
    print_list(&c);
    

    // ===== Bloco 6 =====
    printf("\n== Bloco 6 ==\n");
    t_list ordered;
    create(&ordered);
    int valores[] = {4, 8, 5, 3, 7, 9};
    for (int i = 0; i < 6; i++) insert_ordered(&ordered, valores[i]);
    printf("Esperado: 3 4 5 7 8 9\n");
    printf("Obtido:   ");
    print_list(&ordered);
    printf("search_binary(7) esperado indice 3, obtido: %d\n", search_binary(&ordered, 7));


    return 0;
}