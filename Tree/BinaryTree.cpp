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

class BinaryTree
{
    void insert(int value, Node* &parent);
    void preOrder(Node* parent);
    void postOrder(Node* node);
    Node* find_min_value(Node* &node);
public:
    Node* root;
    BinaryTree() {root = nullptr;}
    int depth(Node* node);
    void insert(int value);
    void erase(int value, Node* &node);
    bool find(int value);
    void preOrder();
    void postOrder();   
    //void inOrder();     void inOrder(Node* node);
};

//overload insert function
void BinaryTree::insert(int value)
{
    return insert(value, root);
}

void BinaryTree::insert(int value, Node* &parent)
{
    Node *newNode = new Node(value);

    if (parent == nullptr)
        parent = newNode;
    else
    {
        if (value < parent->data)
            insert(value, parent->left);
        if (value > parent->data)
            insert(value, parent->right);
    }
}


int BinaryTree::depth(Node* node)
{
    if (node == nullptr)
        return 0;
    
    int lDepth = depth(node->left),
        rDepth = depth(node->right);
    
    if (lDepth > rDepth)
        return lDepth + 1;
    else return rDepth + 1;
}
Node* BinaryTree::find_min_value(Node* &node)
{
    if (node->left == nullptr) return node;
    find_min_value(node->left);
    return node;
}
void BinaryTree::erase(int value, Node* &node)
{
    if (node == nullptr) return ;
    if (node->data > value) 
        erase(value, node->left);
    else if (node->data < value)
        erase(value, node->right);
    else
    {
        //th node khong co nhanh nao
        if (node->left == nullptr && node->right == nullptr)
        {
            node = nullptr; delete node;
        }
        //th node co mot nhanh
        else if (node->right == nullptr)
        {
            Node* &temp = node->left;
            node = temp;
            temp = nullptr;
            delete temp;
        }
        else if (node->left == nullptr)
        {
            Node* &temp = node->right;
            node = temp;
            temp = nullptr;
            delete temp;
        }
        //node co ca hai nhanh
        else
        {
            Node* temp = find_min_value(node->right);
            node->data = temp->data;
            erase(temp->data, node->right);
        }
    }
}

bool BinaryTree::find(int value)
{
    Node *f = root;
    if (f == nullptr) cerr << "invalid!!\n";
    while (f != nullptr)
    {
        if (f->data == value) return true;
        else if (f->data > value)
            f = f->left;
        else   
            f = f->right;
    }
    return false;
}

void BinaryTree::preOrder()
{
    preOrder(root);
    cout << endl;
}

void BinaryTree::preOrder(Node* parent)
{
    if (parent == nullptr) return ;
    cout << parent->data << " ";
    preOrder(parent->left);
    preOrder(parent->right);
}

void BinaryTree::postOrder()
{
    postOrder(root);
    cout << endl;
}

void BinaryTree::postOrder(Node* node)
{
    if (node == nullptr) return ;
    preOrder(node->left);
    cout << node->data << " ";
    preOrder(node->right);
}
int main()
{
    BinaryTree tree;
    int arr[] = {10, 1, 6, 5, 8, 12, 3, 15, 9, 7, 13, 20};
    int n = sizeof(arr) / sizeof(*arr);
    for (int i = 0; i < n; i++) 
        tree.insert(arr[i]);
    cout << "PREORDER: " << endl;
    tree.preOrder();
}