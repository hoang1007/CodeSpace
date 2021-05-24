#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node() {
        data = 0;
        left = right = nullptr;
    }
    Node(int _data) {
        data = _data;
        left = right = nullptr;
    }
};

struct BTree {
    Node* root;
    BTree() {
        root = nullptr;
    }

    void insert(int value) {
        if (root == nullptr)
            root = new Node(value);
        else {
            Node* itr = root;
            while (itr) {
                if (itr->data > value) {
                    if (itr->left) itr = itr->left;
                    else {
                        itr->left = new Node(value);
                        break;
                    }
                }
                else if (itr->data < value) {
                    if (itr->right) itr = itr->right;
                    else {
                        itr->right = new Node(value);
                        break;
                    }
                }
                else break;
            }
        }
    }

    void inOrder(Node* node) {
        if (node == nullptr) return ;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    void preOrder(Node* node) {
        if (node == nullptr) return ;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    Node* remove(Node* root, int k) {
        if (root == nullptr) return root;
        if (k < root->data) root->left = remove(root->left, k);
        else if (k > root->data) root->right = remove(root->right, k);
        else {
            if (root->left && root->right) {
                Node* replace = root->right;
                while (replace->left) replace = replace->left;
                root->data = replace->data;
                root->right = remove(root->right, root->data);
            }
            else if (root->left) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            else if (root->right) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else {
                delete root;
                return nullptr;
            }
        }
        return root;
    }
};

int main() {
    int arr[] = {3, 2, 6, 2, 1, 5, 8};
    BTree t;
    for (int i : arr)
        t.insert(i);
    cout << "\nPre Order: \n";
    t.preOrder(t.root);
    cout << "\nIn Order: \n";
    t.inOrder(t.root);
    t.root = t.remove(t.root, 3);
    cout << "\nPre Order: \n";
    t.preOrder(t.root);
    cout << "\nIn Order: \n";
    t.inOrder(t.root);
}