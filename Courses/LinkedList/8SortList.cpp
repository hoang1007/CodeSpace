#include <iostream>
using namespace std;

class List
{
    struct Node
    {
        int data;
        Node* next;
        Node* prev;
        Node()
        {
            data = 0;
            next = prev = nullptr;
        }
        Node(int value)
        {
            data = value;
            next = prev = nullptr;
        }
    };
public:
    Node* head , * tail;
    List();
    List(int arr[], int n);
    void print(bool);
    void swap(Node*, Node*);
    void push_back(int);
    void sort();
};

int main()
{
    int arr[] = {};
    int n = sizeof(arr) / sizeof(*arr);
    List l(arr, n);
    l.sort();
    l.print(false);
}

List::List()
{
    head = tail = nullptr;
}

List::List(int arr[], int n)
{
    head = tail = nullptr;
    for (int i = 0; i < n; i++)
        push_back(arr[i]);
}

void List::push_back(int value)
{
    Node* node = new Node(value);
    if (head == nullptr)
        head = tail = node;
    else
    {
        node->prev = tail;
        tail->next = node;
        tail = node;
    }
}

void List::print(bool reverse)
{
    if (reverse)
    {
        Node* temp = tail;
        for (; temp; temp = temp->prev)
            cout << temp->data << " ";
    }
    else
    {
        Node* temp = head;
        for (; temp; temp = temp->next)
            cout << temp->data << " ";
    }
    cout << endl;
}

void List::swap(Node* node1, Node* node2)
{
    Node* prev1 = node1->prev,
        * prev2 = node2->prev,
        * next1 = node1->next,
        * next2 = node2->next;
    
    if (node1->next == node2)   // if they're neighbor
    {
        node2->next = node1;
        node1->prev = node2;
    }
    else
    {
        node2->next = next1;
        next1->prev = node2;
        prev2->next = node1;
        node1->prev = prev2;
    }

    prev1 ? prev1->next = node2 : head = node2;
    node2->prev = prev1;

    next2 ? next2->prev = node1 : tail = node1;
    node1->next = next2;
}

void List::sort()
{
    for (Node* i = head; i->next; i = i->next)
        for (Node* j = i->next; j; j = j->next)
            if (i->data > j->data)
            {
                swap(i, j);
                Node* temp = i;
                i = j;
                j = temp;
            }
}