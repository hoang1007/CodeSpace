#ifndef _B_TREE_HPP
#define _B_TREE_HPP
#include <iostream>
class binaryTree {
    struct Node {
        int data;
        Node* left, * right;
        Node() {
            data = 0;
            left = right = nullptr;
        }
        Node(int value) : data(value) {
            left = right = nullptr;
        }
    };

    Node* root;

    void preOrder(Node* node);
    void inOrder(Node* node);
    void postOrder(Node* node);
    Node *insert(Node *node, int value);
    Node *erase(Node* node, int value);
public:
    binaryTree() : root(nullptr) {}
    void insert(int value);
    void erase(int value);
    bool find(int value);
    void preOrder();
    void inOrder();
    void postOrder();
};

binaryTree::Node *binaryTree::insert(Node *node, int value) {
    if (node == nullptr) return new Node(value);
    if (value < node->data) node->left = insert(node->left, value);
    else if (value > node->data) node->right = insert(node->right, value);

    return node;
}

binaryTree::Node *binaryTree::erase(Node* node, int value) {
    if (node == nullptr) return nullptr;
    if (value < node->data) node->left = erase(node->left, value);
    else if (value > node->data) node->right = erase(node->right, value);
    else {
        if (node->left && node->right) {
            Node *leftOfRight = node->right;
            for (; leftOfRight->left; leftOfRight = leftOfRight->left);

            node->data = leftOfRight->data;
            node->right = erase(node->right, leftOfRight->data);
        }
        else if (node->left)
            return node->left;
        else if (node->right)
            return node->right;
        else {
            delete node;
            return nullptr;
        }
    }
    return node;
}

void binaryTree::insert(int value) {
    root = insert(root, value);
}

void binaryTree::erase(int value) {
    root = erase(root, value);
}

void binaryTree::preOrder(Node* node) {
    if (node == nullptr) return ;
    std::cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void binaryTree::inOrder(Node *node) {
    if (node == nullptr) return ;
    preOrder(node->left);
    std::cout << node->data << " ";
    preOrder(node->right);
}

void binaryTree::postOrder(Node *node) {
    if (node == nullptr) return ;
    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->data << " ";
}

void binaryTree::preOrder() {
    preOrder(root);
    std::cout << std::endl;
}

void binaryTree::inOrder() {
    inOrder(root);
    std::cout << std::endl;
}

void binaryTree::postOrder() {
    postOrder(root);
    std::cout << std::endl;
}

bool binaryTree::find(int value) {
    Node *i = root;
    while (i) {
        if (value == i->data) return true;
        else if (value < i->data) i = i->left;
        else i = i->right;
    }
    return false;
}

#endif