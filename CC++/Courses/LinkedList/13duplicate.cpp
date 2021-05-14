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

Node* deleteDuplicates(Node* head)
{
    if (head == NULL) return NULL;
    for (Node* i = head; i && i->next; i = i->next)
        for (Node* j = i; j->next; )
            if (i->value == j->next->value)
                j->next = j->next->next;
            else j = j->next;
    return head;
}

int main()
{
    int arr[] = {4, 3, 2, 3, 1, 4, 5, 6, 4, 5};
    int n = sizeof(arr) / sizeof(*arr);

    List l(arr, n);
    l.head = deleteDuplicates(l.head);
    l.print();
}