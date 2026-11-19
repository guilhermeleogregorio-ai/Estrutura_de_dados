#include<stdio.h>
#include<stdlib.h>

typedef struct _node {
    int item;
    struct _node *left;
    struct _node *right;
} t_node;

typedef struct {
    t_node *root;
    int n; // opcional
} t_binary_tree;

t_binary_tree* create_tree() {
    t_binary_tree *tree = malloc(sizeof(t_binary_tree));
    tree->root = NULL;
    tree->n = 0;
    return tree;
}

t_node* create_node(char item) {
    t_node *node = malloc(sizeof(t_node));
    node->item = item;
    node->left = NULL;
    node->right = NULL;
    return node;
}


void print_tree_rec(t_node *node, int x) {
    int i = 0;
    if (node == NULL) {
        return;
    } else {
        print_tree_rec(node->right, x + 2);
        i = 0;
        while (i < x) {
            printf("  ");
            i++;
        }
        printf("%d\n", node->item);
        print_tree_rec(node->left, x + 2);
    }
}

void print_tree(t_binary_tree *tree) {
    print_tree_rec(tree->root, 0);
}

void pre_order(t_node *node) {
    if (node != NULL) {
        printf("%d\t", node->item);
        pre_order(node->left);
        pre_order(node->right);
    } 
}

void in_order(t_node *node) {
    if (node != NULL) {
        in_order(node->left);
        printf("%d\t", node->item);
        in_order(node->right);
    }
}

void post_order(t_node *node) {
    if (node != NULL) {
        post_order(node->left);
        post_order(node->right);
        printf("%d\t", node->item);
    }
}

void destroy_tree(t_node *node) {
    if (node != NULL) {
        post_order(node->left);
        post_order(node->right);
        free(node);
    }
}

void insert(t_binary_tree *tree, int item) {
    t_node *new_node = create_node(item);

    if (tree->n == 0) {
        tree->root = new_node;
        tree->n++;
        return;
    }

    t_node *p = tree->root;
    t_node *parent = NULL;
    while (p != NULL) {
        parent = p;
        if (item < p->item) {
            p = p->left;    
        } else if (item > p->item) {
            p = p->right;
        } else {
            free(new_node);
            return;
        }
    }

    if (item < parent->item) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }
    tree->n++;
}

t_node* search_iterative(t_binary_tree *tree, int item) {
    t_node *p = tree->root;
    
    while (p != NULL) {
        if (item < p->item) {
            p = p->left;    
        } else if (item > p->item) {
            p = p->right;
        } else {
            return p;
        }
    }

    return NULL;
}

t_node* search_rec(t_node *node, int item) {
    if (node == NULL || item == node->item) {
        return node;
    } else if (item < node->item) {
        return search_rec(node->left, item);
    } else {
        return search_rec(node->right, item);
    }
}

t_node* search(t_binary_tree *tree, int item) {
    return search_rec(tree->root, item);
}


int main(int argc, char const *argv[]) {
    t_binary_tree *tree = create_tree();

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

    pre_order(tree->root);
    printf("\n---------\n");
    in_order(tree->root);
    printf("\n---------\n");
    post_order(tree->root);
    printf("\n---------\n");
    
    print_tree(tree);

    t_node *p;

    p = search_iterative(tree, 10);
    printf("%d\n", p->item);
    p = search_iterative(tree, 3);
    printf("%d\n", p->item);
    p = search_iterative(tree, 18);
    printf("%d\n", p->item);
    p = search_iterative(tree, 2);
    printf("%p\n------\n", p);

    p = search(tree, 10);
    printf("%d\n", p->item);
    p = search(tree, 3);
    printf("%d\n", p->item);
    p = search(tree, 18);
    printf("%d\n", p->item);
    p = search(tree, 2);
    printf("%p\n", p);




    return 0;
}
