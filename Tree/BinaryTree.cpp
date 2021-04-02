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
    ~Node()
    {
        delete left;
        delete right;
        cerr << "Destructor~~\n";
    }
};

class BinaryTree
{
    Node* root;
    void insert(int value, Node* &parent);
    void preOrder(Node* parent);
    void postOrder(Node* node);
    int depth(Node* node);
public:
    BinaryTree() {root = nullptr;}
    int depth();
    void insert(int value);
    void erase(int value);
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

int BinaryTree::depth()
{
    return depth(root);
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
void BinaryTree::erase(int value)
{
    Node *p = root;
    while (p != nullptr)
    {
        if (p->data == value) break;
        else if (p->data > value)
            p = p->left;
        else 
            p = p->right;
    }
    if (p == nullptr)
    {
        cerr << "Can't find the value!\n";
        return ;
    }
    else
    {
        if (p->left == nullptr && p->right == nullptr)
        {
            p = nullptr;
            delete p;
        }
        else if (p->left == nullptr)
        {
            p->data = p->right->data;
            p->right = nullptr;
            delete p->right;
        }
        else if (p->right == nullptr)
        {
            p = p->left;
            p->left = nullptr;
            delete p->left;
        }
        else
        {

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
    int arr[] = {4, 3, 6, 8, 2, 0, 7, 2};
    int n = sizeof(arr) / sizeof(*arr);
    for (int i = 0; i < n; i++) 
        tree.insert(arr[i]);
    tree.preOrder();
    tree.erase(7);
    tree.preOrder();
}