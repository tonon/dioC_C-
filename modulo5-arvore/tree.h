// avl_tree.h

#ifndef AVL_TREE_H
#define AVL_TREE_H

// Definição da estrutura de um nó da árvore AVL
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

// Funções públicas
Node* insert(Node* node, int key);
void preOrder(Node* root);

#endif // AVL_TREE_H
