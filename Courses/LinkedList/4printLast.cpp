#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;
};

struct List
{
    Node* head, * tail;
    List();
    List(int*, int);
    void push_back(int);
    void print();
};
List::List()
{
    head = tail = nullptr;
}
List::List(int* arr, int n)
{
    head = tail = nullptr;
    for (int i = 0; i < n; i++)
        push_back(arr[i]);
}

void List::push_back(int value)
{
    Node* node = new Node();
    node->value = value;
    node->next = nullptr;

    if (head)
        tail->next = node;
    else
        head = node;
    tail = node;
}
void List::print()
{
    for (Node* i = head; i; i = i->next)
        cout << i->value << " ";
    cout << endl;
}

// ***************** 4 *********************
void printLast(Node* head, int k)
{
    if (k == 0) return ;
    Node* node = head;
    for (; node && k > 1; k--, node = node->next);

    if (node)
    {
        for (; node->next; node = node->next, head = head->next);

        for (; head; head = head->next)
            cout << head->value << " ";
    }
    else cout << head->value << " ";
}


// ****************** 6 **********************
void printReverse(Node* head, int k)
{
    if (k == 0) return ;
    printReverse(head->next, k-1);
    cout << head->value << " ";
}

int main()
{
    int arr[] = {4, 5, 6, 7, 8, 9, 0};
    int n = sizeof(arr) / sizeof(*arr);

    List l(arr, n);
    printLast(l.head, 7);
}