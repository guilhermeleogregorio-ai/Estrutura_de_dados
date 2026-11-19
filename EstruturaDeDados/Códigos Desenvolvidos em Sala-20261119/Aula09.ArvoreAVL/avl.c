
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int item;
    int height;
    struct _node *left;
    struct _node *right;
} t_node;

typedef struct {
    t_node *root;
    int n;
} t_binary_tree;

/* Retorna a altura de um nó */
int height(t_node *node) {
    if (node == NULL)
        return 0;

    return node->height;
}

/* Retorna o maior de dois valores */
int max(int a, int b) {
    return (a > b) ? a : b;
}

/* Cria uma árvore vazia */
t_binary_tree* create_tree() {
    t_binary_tree *tree = malloc(sizeof(t_binary_tree));

    tree->root = NULL;
    tree->n = 0;

    return tree;
}

/* Cria um novo nó */
t_node* create_node(int item) {
    t_node *node = malloc(sizeof(t_node));

    node->item = item;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;

    return node;
}

/* Fator de balanceamento */
int balance_factor(t_node *node) {
    if (node == NULL)
        return 0;

    return height(node->left) - height(node->right);
}

/* Rotação simples à direita */
t_node* rotate_right(t_node *y) {
    t_node *x = y->left;
    t_node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

/* Rotação simples à esquerda */
t_node* rotate_left(t_node *x) {
    t_node *y = x->right;
    t_node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

/* Inserção AVL recursiva */
t_node* insert_avl(t_node *node, int item, int *inserted) {
    /* Inserção normal de uma árvore binária de busca */
    if (node == NULL) {
        t_node *new_node = create_node(item);
        return new_node;
    }

    if (item < node->item) {
        node->left = insert_avl(node->left, item, inserted);
    } else if (item > node->item) {
        node->right = insert_avl(node->right, item, inserted);
    } else {
        /* Não permite valores duplicados */
        return node;
    }

    /* Atualiza a altura do nó atual */
    node->height = 1 + max(height(node->left), height(node->right));

    /* Calcula o fator de balanceamento */
    int balance = balance_factor(node);

    /* Caso LL: desbalanceamento à esquerda */
    if (balance > 1 && item < node->left->item) {
        return rotate_right(node);
    }

    /* Caso RR: desbalanceamento à direita */
    if (balance < -1 && item > node->right->item) {
        return rotate_left(node);
    }

    /* Caso LR: esquerda e depois direita */
    if (balance > 1 && item > node->left->item) {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    /* Caso RL: direita e depois esquerda */
    if (balance < -1 && item < node->right->item) {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }

    return node;
}

void insert(t_binary_tree *tree, int item) {
    if (tree == NULL)
        return;

    int inserted = 0;
    tree->root = insert_avl(tree->root, item, &inserted);

    if (inserted)
        tree->n++;
}

/* Imprime a árvore de lado */
void print_tree_rec(t_node *node, int x) {
    if (node == NULL)
        return;

    print_tree_rec(node->right, x + 2);

    for (int i = 0; i < x; i++)
        printf("  ");

    printf("%d (h=%d, fb=%d)\n",
           node->item,
           node->height,
           balance_factor(node));

    print_tree_rec(node->left, x + 2);
}

void print_tree(t_binary_tree *tree) {
    if (tree != NULL)
        print_tree_rec(tree->root, 0);
}

/* Percurso pré-ordem */
void pre_order(t_node *node) {
    if (node != NULL) {
        printf("%d\t", node->item);
        pre_order(node->left);
        pre_order(node->right);
    }
}

/* Percurso em ordem */
void in_order(t_node *node) {
    if (node != NULL) {
        in_order(node->left);
        printf("%d\t", node->item);
        in_order(node->right);
    }
}

/* Percurso pós-ordem */
void post_order(t_node *node) {
    if (node != NULL) {
        post_order(node->left);
        post_order(node->right);
        printf("%d\t", node->item);
    }
}

/* Busca iterativa */
t_node* search_iterative(t_binary_tree *tree, int item) {
    if (tree == NULL)
        return NULL;

    t_node *p = tree->root;

    while (p != NULL) {
        if (item < p->item)
            p = p->left;
        else if (item > p->item)
            p = p->right;
        else
            return p;
    }

    return NULL;
}

/* Busca recursiva */
t_node* search_rec(t_node *node, int item) {
    if (node == NULL || item == node->item)
        return node;

    if (item < node->item)
        return search_rec(node->left, item);

    return search_rec(node->right, item);
}

t_node* search(t_binary_tree *tree, int item) {
    if (tree == NULL)
        return NULL;

    return search_rec(tree->root, item);
}

/* Libera todos os nós */
void destroy_tree(t_node *node) {
    if (node != NULL) {
        destroy_tree(node->left);
        destroy_tree(node->right);
        free(node);
    }
}

/* Libera a árvore e sua estrutura */
void free_tree(t_binary_tree *tree) {
    if (tree != NULL) {
        destroy_tree(tree->root);
        free(tree);
    }
}

int main(void) {
    t_binary_tree *tree = create_tree();

    if (tree == NULL) {
        fprintf(stderr, "Erro ao criar a arvore.\n");
        return 1;
    }

    insert(tree, 10);
    insert(tree, 5);
    insert(tree, 15);
    insert(tree, 3);
    insert(tree, 1);
    insert(tree, 7);
    insert(tree, 13);
    insert(tree, 20);
    insert(tree, 25);
    insert(tree, 18);
    insert(tree, 6);

    printf("Pre-ordem:\n");
    pre_order(tree->root);

    printf("\n\nEm ordem:\n");
    in_order(tree->root);

    printf("\n\nPos-ordem:\n");
    post_order(tree->root);

    printf("\n\nArvore AVL:\n");
    print_tree(tree);

    printf("\nBusca iterativa:\n");

    int values[] = {10, 3, 18, 2};

    for (int i = 0; i < 4; i++) {
        t_node *p = search_iterative(tree, values[i]);

        if (p != NULL)
            printf("%d encontrado.\n", p->item);
        else
            printf("%d nao encontrado.\n", values[i]);
    }

    printf("\nBusca recursiva:\n");

    for (int i = 0; i < 4; i++) {
        t_node *p = search(tree, values[i]);

        if (p != NULL)
            printf("%d encontrado.\n", p->item);
        else
            printf("%d nao encontrado.\n", values[i]);
    }

    printf("\nQuantidade de nos: %d\n", tree->n);

    free_tree(tree);

    return 0;
}
