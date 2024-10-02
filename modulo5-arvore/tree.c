// avl_tree.c

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// Função para obter a altura de um nó
int height(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Função para criar um novo nó
Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;  // Nó novo é inserido como folha
    return node;
}

// Função para obter o valor máximo entre dois inteiros
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Rotação à direita
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Realizando rotação
    x->right = y;
    y->left = T2;

    // Atualizando alturas
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;  // Nova raiz
}

// Rotação à esquerda
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Realizando rotação
    y->left = x;
    x->right = T2;

    // Atualizando alturas
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;  // Nova raiz
}

// Função para obter o fator de balanceamento de um nó
int getBalance(Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Função para inserir um nó na árvore AVL e balancear a árvore
Node* insert(Node* node, int key) {
    // Passo 1: Inserção normal na árvore binária de busca
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else  // Chaves duplicadas não são permitidas
        return node;

    // Passo 2: Atualizar a altura do nó ancestral
    node->height = 1 + max(height(node->left), height(node->right));

    // Passo 3: Obter o fator de balanceamento do nó ancestral
    int balance = getBalance(node);

    // Se o nó estiver desbalanceado, realizar as rotações apropriadas

    // Caso 1: Rotação à direita (Left-Left)
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Caso 2: Rotação à esquerda (Right-Right)
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Caso 3: Rotação à esquerda-direita (Left-Right)
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Caso 4: Rotação à direita-esquerda (Right-Left)
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;  // Retorna o nó inalterado se estiver balanceado
}

// Função para imprimir a árvore em pré-ordem (PreOrder Traversal)
void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
