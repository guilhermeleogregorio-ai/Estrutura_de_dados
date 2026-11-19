# Exercícios — Lista Sequencial (Estática) e Lista Ordenada

Baseado nos slides Aula04_ESDD_ListaEstatica e Aula06_ESD_ListaEstaticaOrdenada.

Struct base (use a mesma em todos os exercícios):

```c
#define MAX 100

typedef struct {
    int items[MAX];
    int size;
} t_list;
```

Dica de treino: implemente sem consultar nada primeiro. Depois compare com os slides/testes. Escreva um `main()` de teste para cada bloco antes de seguir para o próximo.

---

## Bloco 1 — Operações básicas (aquecimento)

1. `void create(t_list *list);` — inicializa a lista (`size = 0`).
2. `int is_empty(t_list *list);` — retorna 1 se vazia, 0 caso contrário.
3. `int is_full(t_list *list);` — retorna 1 se `size == MAX`.
4. `int append(t_list *list, int element);` — insere no final. Retorna 1 se sucesso, 0 se lista cheia.
5. `void print_list(t_list *list);` — imprime os elementos separados por espaço.

**Teste:** crie a lista, dê append de 5, 10, 15 e imprima. Esperado: `5 10 15`.

---

## Bloco 2 — Inserção, atualização e acesso por posição

6. `int insert(t_list *list, int element, int index);` — insere `element` na posição `index`, deslocando os elementos seguintes para a direita. Retorna 0 se `index` inválido ou lista cheia.
7. `int get(t_list *list, int index, int *out);` — coloca em `*out` o elemento da posição `index`. Retorna 0 se posição inválida.
8. `int update(t_list *list, int element, int index);` — substitui o elemento da posição `index` por `element`.

**Teste:** lista `[5, 10, 15]`, `insert(&list, 7, 1)` → esperado `[5, 7, 10, 15]`. Depois `update(&list, 99, 0)` → esperado `[99, 7, 10, 15]`.

---

## Bloco 3 — Remoção e busca

9. `int remove_by_index(t_list *list, int index);` — remove o elemento da posição `index`, deslocando os seguintes para a esquerda.
10. `int index_of(t_list *list, int element);` — retorna o primeiro índice onde `element` aparece, ou -1 se não encontrado.
11. `int remove_by_element(t_list *list, int element);` — remove a primeira ocorrência de `element` (dica: reusar `index_of` + `remove_by_index`).
12. `int count(t_list *list, int element);` — conta quantas vezes `element` aparece na lista.

**Teste:** lista `[3, 7, 3, 9, 3]`. `count(&list, 3)` → 3. `remove_by_element(&list, 3)` → `[7, 3, 9, 3]` (removeu só a primeira ocorrência).

---

## Bloco 4 — Operações "adicionais" (as que mais caem em prova)

13. `int is_sorted(t_list *list);` — verifica se a lista está ordenada (crescente). Bônus: também detectar decrescente.
14. `void copy(t_list *src, t_list *dest);` — copia todos os elementos de `src` para `dest`.
15. `void copy_no_duplicates(t_list *src, t_list *dest);` — copia de `src` para `dest` sem repetir elementos.
16. `void reverse_to(t_list *src, t_list *dest);` — inverte `src` colocando o resultado em `dest` (sem alterar `src`).
17. `void reverse_in_place(t_list *list);` — inverte a própria lista, sem usar uma segunda lista auxiliar (dica: troque `items[i]` com `items[size-1-i]`).
18. `void remove_all(t_list *list, int element);` — remove TODAS as ocorrências de `element` (não só a primeira).

**Teste:** lista `[1, 2, 2, 3, 2]`. `remove_all(&list, 2)` → `[1, 3]`.

---

## Bloco 5 — Intercalação (a pegadinha clássica de prova)

19. `void merge_sorted(t_list *l1, t_list *l2, t_list *l3);` — considerando que `l1` e `l2` já estão ordenadas, gera `l3` ordenada com todos os elementos de `l1` e `l2` (é o merge do merge sort — mantém O(n+m), sem ordenar de novo no final).

**Teste:** `l1 = [1, 3, 5]`, `l2 = [2, 4, 6]` → `l3 = [1, 2, 3, 4, 5, 6]`.

---

## Bloco 6 — Lista Ordenada (TAD separado)

Agora a regra muda: a inserção **sempre** mantém a lista ordenada — não existe mais `insert(element, index)` nem `append` livre.

20. `int insert_ordered(t_list *list, int element);` — insere `element` na posição correta para manter a ordem crescente. Retorna 0 se cheia.
21. `int search_binary(t_list *list, int element);` — busca binária: retorna o índice de `element`, ou -1. (Como a lista está ordenada, não precisa de busca linear.)
22. `int equals(t_list *l1, t_list *l2);` — retorna 1 se as duas listas têm exatamente os mesmos elementos, na mesma ordem.

**Teste:** insira nessa ordem: 4, 8, 5, 3, 7, 9 usando `insert_ordered`. Esperado ao final: `[3, 4, 5, 7, 8, 9]` (é exatamente a sequência do exemplo do slide da Aula06).

---

## Como usar esta lista até domingo

- Sexta: Bloco 1 e 2.
- Sábado: Bloco 3 e 4.
- Domingo: Bloco 5 e 6, e depois **refaça o Bloco 1 do zero sem olhar** pra testar retenção.

Se travar em algum exercício ou quiser que eu revise seu código, é só colar aqui.
