#include<stdio.h>
#include<stdlib.h>

typedef struct _node {
    char item;
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

void insert_right(t_node *node, t_node *parent_node) {
    parent_node->right = node;
}

void insert_left(t_node *node, t_node *parent_node) {
    parent_node->left = node;
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
        printf("%c\n", node->item);
        print_tree_rec(node->left, x + 2);
    }
}

void print_tree(t_binary_tree *tree) {
    print_tree_rec(tree->root, 0);
}

void pre_order(t_node *node) {
    if (node != NULL) {
        printf("%c\t", node->item);
        pre_order(node->left);
        pre_order(node->right);
    } 
}

void in_order(t_node *node) {
    if (node != NULL) {
        in_order(node->left);
        printf("%c\t", node->item);
        in_order(node->right);
    }
}

void post_order(t_node *node) {
    if (node != NULL) {
        post_order(node->left);
        post_order(node->right);
        printf("%c\t", node->item);
    }
}

void destroy_tree(t_node *node) {
    if (node != NULL) {
        post_order(node->left);
        post_order(node->right);
        free(node);
    }
}


int main(int argc, char const *argv[]) {
    t_binary_tree *tree = create_tree();

    t_node *node_a = create_node('A');
    t_node *node_b = create_node('B');
    t_node *node_c = create_node('C');
    t_node *node_d = create_node('D');
    t_node *node_e = create_node('E');
    t_node *node_f = create_node('F');
    t_node *node_g = create_node('G');
    t_node *node_h = create_node('H');
    t_node *node_i = create_node('I');
    t_node *node_j = create_node('J');

    tree->root = node_a;
    insert_left(node_b, node_a);
    insert_right(node_c, node_a);
    insert_left(node_d, node_b);
    insert_right(node_e, node_b);
    insert_left(node_h, node_d);
    insert_left(node_f, node_c);
    insert_right(node_g, node_c);
    insert_left(node_i, node_g);
    insert_right(node_j, node_g);

    pre_order(tree->root);
    printf("\n---------\n");
    in_order(tree->root);
    printf("\n---------\n");
    post_order(tree->root);
    printf("\n---------\n");
    
    print_tree(tree);


    return 0;
}
