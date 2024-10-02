// main.c

#include <stdio.h>
#include "tree.h"

int main() {
    Node* root = NULL;

    // Inserir elementos na árvore AVL
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // Imprimir a árvore em pré-ordem
    printf("Pre-order traversal of the constructed AVL tree is:\n");
    preOrder(root);
    printf("\n");

    return 0;
}
