#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node()
    {
        next = nullptr;
    }
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class List
{
    void free(Node* &node);
protected:
    size_t _size;
    Node *head, *tail;
public:
    List();
    inline size_t size();
    inline Node* begin();
    inline Node* end();
    int at(int pos);
    void pop_back();
    void push_back(int value);
    void push_front(int value);
    void pop_front();
    void print();
    int operator [] (int pos);
    bool empty();
    void append(List &_l);
};

List::List()
{
    head = tail = nullptr;
    _size = 0;
}

inline size_t List::size()
{
    return _size;
}

inline Node* List::begin()
{
    return head;
}

inline Node* List::end()
{
    return tail;
}

int List::at(int pos)
{
    if (pos < 0 && pos >= _size)
    {
        cerr << "Out of bound" << endl;
        return -1;
    }
    
    Node* temp = head;
    for (; pos && temp != nullptr; --pos)
        temp = temp->next;

    return temp->data;
}

int List::operator[] (int pos)
{
    return at(pos);
}

void List::push_back(int value)
{
    Node* newNode = new Node(value);
    
    // if list is null
    if (head == nullptr)
        head = tail = newNode;
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    _size++;
}

void List::push_front(int value)
{
    Node* newNode = new Node(value);

    if (head == nullptr)
        head = tail = newNode;
    else
    {
        newNode->next = head;
        head = newNode;
    }
    _size++;
}

void List::free(Node* &node)
{
    node = nullptr;
    delete node;
}

void List::pop_back()
{
    //if list is hollow
    if (head == nullptr)
    {
        cerr << "Hollow list!" << endl;
        return ;
    }
    // if list has one element
    if (head == tail)
        free(head);
    else
    {
        Node* temp = head;
        while (temp->next != tail)
            temp = temp->next;
        tail = temp;

        free(tail->next);
    }
    _size--;
}

void List::pop_front()
{
    if (!head)
    {
        cerr << "Hollow list!" << endl;
        return ;
    }
    
    if (head == tail)
        free(head);
    else
    {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    _size--;
}

void List::print()
{
    Node* temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool List::empty()
{
    return head == nullptr;
}

void List::append(List &_l)
{
    tail->next = _l.head;
    tail = _l.tail;
    _l.head = head;
}

int main()
{
    List l;
    int arr[] = {5, 6, 3, 8, 9, 2};

    int n = sizeof(arr) / sizeof(*arr);

    for (int i = 0; i < n; i++)
        l.push_back(arr[i]);
    l.push_front(10);
    cout << l[4] << endl;
    
    l.print();

    List l2;
    l2.push_back(1);
    l2.push_back(2);

    l.append(l2);
    l.print();
    cout << l2.begin()->data;
}