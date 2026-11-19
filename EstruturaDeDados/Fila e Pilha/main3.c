#include <stdio.h>
#include "queue.h"
#include "deque.h"



/*

 * Pressupõe as assinaturas:
 *   void create(t_deque *deque);
 *   int  is_empty(t_deque *deque);
 *   int  is_full(t_deque *deque);
 *   int  in_begin(t_deque *deque, int element);
 *   int  in_end(t_deque *deque, int element);
 *   int  out_begin(t_deque *deque, int *element);
 *   int  out_end(t_deque *deque, int *element);
 *   int  size(t_deque *deque);
 *
 * Se compilar junto com stack.c/queue.c no mesmo programa, lembre do
 * aviso de nomes repetidos (create, size, is_empty, is_full, clear) —
 * teste o deque separado por enquanto, se ainda não resolveu isso.
 */

printf("\n== DEQUE ==\n");
t_deque deque;
create(&deque);

printf("is_empty (esperado 1): %d\n", is_empty(&deque));

int valor;

/* Monta [10, 20, 30] inserindo primeiro no fim, depois no início */
in_end(&deque, 20);
in_end(&deque, 30);
in_begin(&deque, 10);
printf("size apos montar [10,20,30] (esperado 3): %d\n", size(&deque));

out_begin(&deque, &valor);
printf("out_begin (esperado 10, tira do inicio): %d\n", valor);

out_end(&deque, &valor);
printf("out_end (esperado 30, tira do fim): %d\n", valor);

printf("size apos as duas remocoes (esperado 1): %d\n", size(&deque));

out_begin(&deque, &valor);
printf("out_begin (esperado 20, ultimo restante): %d\n", valor);

printf("is_empty (esperado 1): %d\n", is_empty(&deque));
printf("out_begin em deque vazio (esperado retorno 0): %d\n", out_begin(&deque, &valor));

/* Teste de estresse: circular precisa dar a volta sem estourar */
for (int i = 0; i < 150; i++) {
    in_end(&deque, i);
    out_begin(&deque, &valor);
}
printf("apos 150 ciclos in_end/out_begin, size (esperado 0): %d\n", size(&deque));