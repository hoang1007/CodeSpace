#include <iostream>

class List {
    struct Node {
        int data;
        Node* next;
        Node() {
            data = 0;
            next = nullptr;
        }
        Node(int value) : data(value) {
            next = nullptr;
        } 
    };

    Node *head, *tail;
    int _size;
    int error_code = -1;
public:
    List() {
        head = tail = nullptr;
        _size = 0;
    }

    List(int arr[], int n) {
        _size = 0;
        head = tail = nullptr;
        for (int i = 0; i < n; i++)
            push_back(arr[i]);
    }

    void push_back(int value);
    void push_front(int value);
    void insert(int pos, int value);
    void pop_back();
    void pop_front();
    void erase(int pos);
    bool empty();
    int &at(int pos);
    int &operator[](int pos);
    int size();

    friend std::ostream& operator<<(std::ostream& out, List& list) {
        if (list.empty())
            out << "List is empty!!!";
        else
            for (List::Node* i = list.head; i; i = i->next)
                out << i->data << " ";
        out << std::endl;
        return out;
    }
};

void List::push_back(int value) {
    Node *node = new Node(value);
    if (head == nullptr)
        head = node;
    else tail->next = node;
    tail = node;

    _size++;
}

void List::push_front(int value) {
    Node *node = new Node(value);
    if (head == nullptr)
        tail = node;
    else node->next = head;
    head = node;

    _size++;
}

void List::pop_back() {
    if (head == nullptr) return ;
    Node *i = head;
    for (; i->next != tail; i = i->next);
    delete i->next;
    i->next = nullptr;
    _size--;
}

void List::pop_front() {
    if (head == nullptr) return ;

    Node *temp = head;
    head = head->next;
    delete temp;
    _size--;
}

bool List::empty() {
    return head == nullptr;
}

int& List::at(int pos) {
    if (pos < 1 || pos > _size) {
        std::cerr << "Out of bound while get value at " << pos << " position\nReturned error code -1\n";
        return error_code;
    }

    Node *i = head;
    for (; pos; pos--, i = i->next);
    return i->data;
}

int& List::operator[](int pos) {
    return at(pos);
}

int List::size() {
    return _size;
}

void List::insert(int pos, int value) {
    if (pos < 1 || pos > _size)
        std::cerr << "Out of bound while insert to " << pos << " position!\n";
    else {
        if (pos == 1)
            push_front(value);
        else if (pos == _size)
            push_back(value);
        else {
            Node* node = new Node(value);
            Node* i = head;
            for (pos--; pos; pos--, i = i->next);

            node->next = i->next;
            i->next = node;
        }
    }
}

void List::erase(int pos) {
    if (pos < 1 || pos > _size) 
        std::cerr << "Out of bound while try to erase element at " << pos << std::endl;
    else {
        Node* i = head;
        for (pos--; pos; pos--, i = i->next);

        Node* temp = i->next;
        i->next = i->next->next;
        delete temp;
    }
}