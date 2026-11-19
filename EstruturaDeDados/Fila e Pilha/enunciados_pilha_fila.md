# Enunciado das Operações — Pilha e Fila

Mesmo formato de antes: **O que faz** / **Pré-condição** / **Pós-condição**.

Struct base sugerida (pilha):
```c
#define MAX 100

typedef struct {
    int items[MAX];
    int top;   // índice do topo; -1 quando vazia
} t_stack;
```

Struct base sugerida (fila simples):
```c
typedef struct {
    int items[MAX];
    int front;  // índice do início
    int rear;   // índice do fim (próxima posição livre)
    int size;   // quantidade de elementos
} t_queue;
```

---

# PILHA (Stack) — LIFO

### `void create(t_stack *stack);`
- **O que faz:** inicializa a pilha, deixando-a vazia.
- **Pré-condição:** nenhuma.
- **Pós-condição:** `stack->top` fica igual a -1 (convenção comum: -1 significa "nenhum elemento", já que o topo aponta pra última posição ocupada).

### `int is_empty(t_stack *stack);`
- **O que faz:** verifica se a pilha não tem nenhum elemento.
- **Pré-condição:** nenhuma.
- **Pós-condição:** retorna 1 se `top == -1`; retorna 0 caso contrário. Não modifica a pilha.

### `int is_full(t_stack *stack);`
- **O que faz:** verifica se a pilha atingiu a capacidade máxima.
- **Pré-condição:** nenhuma.
- **Pós-condição:** retorna 1 se `top == MAX - 1` (a última posição válida do vetor); retorna 0 caso contrário.

### `int push(t_stack *stack, int element);`
- **O que faz:** insere `element` no topo da pilha.
- **Pré-condição:** a pilha não está cheia.
- **Pós-condição:** `top` é incrementado em 1, e `element` é colocado em `items[top]` (nessa ordem: primeiro incrementa, depois escreve — pense em por que essa ordem importa quando `top` começa em -1). Retorna 1 se sucesso, 0 se cheia.

### `int pop(t_stack *stack, int *out);`
- **O que faz:** remove o elemento do topo e devolve o valor removido.
- **Pré-condição:** a pilha não está vazia.
- **Pós-condição:** `*out` recebe o valor de `items[top]`; `top` é decrementado em 1 (o elemento "some" logicamente, mesmo que o valor continue fisicamente no vetor). Retorna 1 se sucesso, 0 se vazia.

### `int top_value(t_stack *stack, int *out);`
*(chamado só de `top` nos slides, mas cuidado pra não confundir com o campo `stack->top` — por isso sugiro outro nome na implementação, tipo `peek` ou `top_value`)*
- **O que faz:** consulta o valor do topo **sem remover**.
- **Pré-condição:** a pilha não está vazia.
- **Pós-condição:** `*out` recebe o valor de `items[top]`. Nada é alterado na pilha (nem `top`, nem o vetor). Retorna 1 se sucesso, 0 se vazia.

### `int size(t_stack *stack);`
- **O que faz:** informa quantos elementos existem na pilha.
- **Pré-condição:** nenhuma.
- **Pós-condição:** retorna `top + 1` (se `top == -1`, retorna 0). Não modifica a pilha.

### `void clear(t_stack *stack);`
- **O que faz:** remove todos os elementos de uma vez.
- **Pré-condição:** nenhuma.
- **Pós-condição:** equivalente a chamar `create` de novo — `top` volta a -1.

---

# FILA (Queue) — FIFO

### `void create(t_queue *queue);`
- **O que faz:** inicializa a fila vazia.
- **Pré-condição:** nenhuma.
- **Pós-condição:** `front = 0`, `rear = 0`, `size = 0` (convenção comum — pode variar dependendo de como o professor definiu nos slides; o importante é que represente "vazia" de forma consistente com as outras operações).

### `int is_empty(t_queue *queue);`
- **Pós-condição:** retorna 1 se `size == 0`, senão 0. Não modifica a fila.

### `int is_full(t_queue *queue);`
- **Pós-condição:** retorna 1 se `size == MAX`, senão 0. Não modifica a fila.

### `int in(t_queue *queue, int element);` *(enqueue — entra pelo fim)*
- **O que faz:** insere `element` no final da fila.
- **Pré-condição:** a fila não está cheia.
- **Pós-condição:** `element` é colocado em `items[rear]`; `rear` avança uma posição; `size` incrementa. Retorna 1 se sucesso, 0 se cheia.

### `int out(t_queue *queue, int *element);` *(dequeue — sai pelo início)*
- **O que faz:** remove o elemento da frente da fila e devolve o valor removido.
- **Pré-condição:** a fila não está vazia.
- **Pós-condição:** `*element` recebe o valor de `items[front]`; `front` avança uma posição; `size` decrementa. Retorna 1 se sucesso, 0 se vazia.

### `int size(t_queue *queue);`
- **Pós-condição:** retorna o valor de `size` diretamente (já é mantido como campo — diferente da pilha, onde tinha que calcular `top + 1`).

### `void clear(t_queue *queue);`
- **Pós-condição:** equivalente a `create` de novo.

---

## Fila circular — por que existe

Numa fila **simples** (a acima, sem "dar a volta"), depois de muitos `in`/`out`, o `front` e o `rear` só andam pra frente e nunca voltam — mesmo já tendo espaço livre nas primeiras posições do vetor (que já foram lidas e removidas), a fila reporta "cheia" quando `rear` chega no fim do vetor, mesmo com espaço vazio no início. É desperdício de memória.

Na fila **circular**, quando `front` ou `rear` chegam ao final do vetor (`MAX - 1`), eles "dão a volta" e retornam pra posição `0` (geralmente calculado com o operador `%`, módulo: `rear = (rear + 1) % MAX`). Isso permite reaproveitar os espaços liberados no início do vetor sem precisar deslocar nenhum elemento.

**A lógica de `in`, `out`, `is_empty`, `is_full` muda só na forma de avançar os índices** (usando `% MAX` em vez de `+ 1` puro) — o `size` continua sendo a forma mais simples e segura de saber se está vazia/cheia (comparar só `front == rear` fica ambíguo entre "vazia" e "cheia" quando é circular, por isso manter um contador de `size` separado resolve esse problema clássico).

---

## Deque (fila de duas pontas) — operações extras

O deque permite inserir e remover tanto no início quanto no fim:

### `int in_begin(t_deque *deque, int element);`
- **Pós-condição:** insere `element` no início do deque (equivalente a um "push" na frente).

### `int in_end(t_deque *deque, int element);`
- **Pós-condição:** insere `element` no fim (igual o `in` da fila normal).

### `int out_begin(t_deque *deque, int *element);`
- **Pós-condição:** remove e devolve o elemento do início (igual o `out` da fila normal).

### `int out_end(t_deque *deque, int *element);`
- **Pós-condição:** remove e devolve o elemento do fim.

Todas seguem a mesma pré-condição (não pode estar vazia pra remover, não pode estar cheia pra inserir) e a mesma ideia de "avançar/recuar índice com wraparound" da fila circular.

---

## Dica de estudo

Pilha e Fila são estruturalmente **mais simples** que Lista Sequencial (menos casos, sem deslocamento de elementos) — a "pegadinha" de prova aqui costuma ser mais conceitual: confundir a ordem de incrementar/decrementar `top` no `push`/`pop`, ou esquecer que fila circular precisa de `% MAX`. Vale a pena treinar primeiro no papel a sequência de operações (ex: `push(1), push(2), pop(), push(3), top()`) e desenhar o vetor mudando a cada passo, antes de codar.
