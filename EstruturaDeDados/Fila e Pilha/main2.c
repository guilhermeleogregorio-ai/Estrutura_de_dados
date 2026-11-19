#include <stdio.h>
//#include "stack.h"
#include "queue.h"

/*
 * Este main.c pressupõe que você vai criar:
 *
 * stack.h / stack.c com:
 *   typedef struct { int items[MAX]; int top; } t_stack;
 *   void create(t_stack *stack);
 *   int  is_empty(t_stack *stack);
 *   int  is_full(t_stack *stack);
 *   int  push(t_stack *stack, int element);
 *   int  pop(t_stack *stack, int *out);
 *   int  top_value(t_stack *stack, int *out);
 *   int  size(t_stack *stack);
 *   void clear(t_stack *stack);
 *
 * queue.h / queue.c com:
 *   typedef struct { int items[MAX]; int front; int rear; int size; } t_queue;
 *   void create(t_queue *queue);
 *   int  is_empty(t_queue *queue);
 *   int  is_full(t_queue *queue);
 *   int  in(t_queue *queue, int element);
 *   int  out(t_queue *queue, int *element);
 *   int  size(t_queue *queue);
 *   void clear(t_queue *queue);
 *
 * OBS: como "size" e "create" existem em ambos, os nomes vão colidir no
 * linker se stack.c e queue.c forem compilados juntos com esses nomes
 * exatos. Duas saídas comuns:
 *   1) prefixar (stack_create, stack_size, queue_create, queue_size...)
 *   2) compilar/testar stack e queue em main.c separados (mais fácil agora)
 * Ajuste os nomes abaixo conforme a escolha que você fizer.
 */

int main() {
   /* printf("== PILHA ==\n");
    t_stack stack;
    create(&stack);

    printf("is_empty (esperado 1): %d\n", is_empty(&stack));

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printf("size (esperado 3): %d\n", size(&stack));

    int valor;
    top_value(&stack, &valor);
    printf("top_value (esperado 30, sem remover): %d\n", valor);

    pop(&stack, &valor);
    printf("pop (esperado 30): %d\n", valor);
    printf("size apos pop (esperado 2): %d\n", size(&stack));

    pop(&stack, &valor);
    printf("pop (esperado 20): %d\n", valor);

    pop(&stack, &valor);
    printf("pop (esperado 10): %d\n", valor);

    printf("is_empty (esperado 1): %d\n", is_empty(&stack));
    printf("pop em pilha vazia (esperado retorno 0): %d\n", pop(&stack, &valor));

    */
    printf("\n== FILA ==\n");
    t_queue queue;
    create(&queue);

    printf("is_empty (esperado 1): %d\n", is_empty(&queue));

    in(&queue, 1);
    in(&queue, 2);
    in(&queue, 3);
    printf("size (esperado 3): %d\n", size(&queue));

    out(&queue, &valor);
    printf("out (esperado 1, o primeiro que entrou): %d\n", valor);

    out(&queue, &valor);
    printf("out (esperado 2): %d\n", valor);

    in(&queue, 4);
    printf("size apos mais um in (esperado 2): %d\n", size(&queue));

    out(&queue, &valor);
    printf("out (esperado 3): %d\n", valor);

    out(&queue, &valor);
    printf("out (esperado 4): %d\n", valor);

    printf("is_empty (esperado 1): %d\n", is_empty(&queue));
    printf("out em fila vazia (esperado retorno 0): %d\n", out(&queue, &valor));

    
    return 0;
}