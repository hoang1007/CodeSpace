#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;
};

struct List
{
    Node* head;
    List();
    List(int*, int);
    void push_back(int);
    void print();
};
List::List()
{
    head = nullptr;
}
List::List(int* arr, int n)
{
    head = nullptr;
    for (int i = 0; i < n; i++)
        push_back(arr[i]);
}

void List::push_back(int value)
{
    Node* node = new Node();
    node->value = value;
    node->next = nullptr;

    if (head == nullptr)
    {
        head = node;
        return ;
    }

    Node* temp = head;
    for (; temp->next; temp = temp->next);
    temp->next = node;
}
void List::print()
{
    for (Node* i = head; i; i = i->next)
        cout << i->value << " ";
    cout << endl;
}

Node* deleteSingle(Node* head)
{
    // truong hop dau
    if (head->value != head->next->value)
    {
        Node* temp = head;
        head = head->next;
        temp = nullptr;
        delete temp;
        return head;
    }

    Node* node = head->next;
    Node* prevNode = head;
    Node* oldNode = head;

    for (; prevNode; oldNode = node, prevNode = node->next, node = node->next->next)
        if (prevNode && node == nullptr)
            break;
        else if (prevNode->value != node->value)
            break;
    
    oldNode->next = oldNode->next->next;
    return head;
}

Node* deleteNode(Node* head, int pos)
{
    if (pos == 0)
    {
        Node* temp = head->next;
        head = nullptr;
        delete head;
        return temp;
    }
    Node* i = head;
    for (; pos > 1; pos--, i = i->next);
    
    i->next = i->next->next;
    return head;
}

Node* rotate(Node* head, int k)
{
    Node* prev_head_rotate = head;
    Node* tail = head;

    if (k == 0) return head;;

    for (; tail->next; tail = tail->next, k--)
        if (k > 1) prev_head_rotate = prev_head_rotate->next;
    
    tail->next = head;
    head = prev_head_rotate->next;
    tail = prev_head_rotate;
    tail->next = nullptr;
    return head;
}

int main()
{
    int arr[] = {0, 1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(*arr);

    List l(arr, n);
    rotate(l.head, 3);
    l.print();
}