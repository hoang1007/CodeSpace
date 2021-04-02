#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node() {left = right = nullptr;}
    Node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};

class Heap
{
    void insert(int value, Node* &node);
    Node* find_floor(Node* &node);  //tim node co do cao thap nhat chua duoc insert
public:
    Node* root;
    Heap() {root = nullptr;}

    void insert(int value);
    void erase(int value);
    void preOrder();
};

void Heap::insert(int value)
{
    insert(value, root);
}

Node* Heap::find_floor(Node* &node)
{
    Node* temp = root;
    while (true)
    {
        if (temp == nullptr)
            return temp;
        else if (temp->left == nullptr)
            return temp->left;
        else if (temp->right == nullptr)
            return temp->right;
        else 
    }
}
void Heap::insert(int value, Node* &node)
{
    if (node == nullptr)
        node = new Node(value);
    
}