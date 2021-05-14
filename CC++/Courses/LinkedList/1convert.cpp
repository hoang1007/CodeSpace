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


Node* convert(Node* head)
{
    Node* temp = head;
    int length = 0;
    if (head == NULL || head->next == NULL)
        return head;
    for (; temp; temp = temp->next, length++);

    Node *pa = head, *pb = head;
    for (int i = 0; i < length / 2; i++, pb = pb->next);

    while (pb->next != NULL)
    {
        Node* ta = pa;
        pa = pa->next;
        ta->next = pb;

        Node* tb = pb;
        pb = pb->next;
        tb->next = pa;
    }

    pa->next = pb;
    return head;
}

int main()
{
    int arr[] = {1, 3, 5, 2, 4, 6};
    int n = sizeof(arr) / sizeof(*arr);

    List l(arr, n);
    l.head = convert(l.head);
    l.print();
}