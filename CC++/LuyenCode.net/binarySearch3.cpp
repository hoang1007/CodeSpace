#include <cstdio>
#include <unordered_map>
using namespace std;

#define null 0
unordered_map<int, int> query;

struct Node {
    int index;
    int data;
    Node *left, *right;
    Node() {
        index = data = 0;
        left = right = nullptr;
    }
    Node(int _data, int _index) {
        index = _index;
        data = _data;
        left = right = nullptr;
    }
};

struct Tree {
    Node* root;
    Tree() {
        root = nullptr;
    }

    void insert(int value, int index) {
        if (root == nullptr)
            root = new Node(value, index);
        else {
            Node* node = root;
            while (node) {
                if (value < node->data) {
                    if (node->left) node = node->left;
                    else {
                        node->left = new Node(value, index);
                        break;
                    }
                }
                else if (value > node->data) {
                    if (node->right) node = node->right;
                    else {
                        node->right = new Node(value, index);
                        break;
                    }
                }
                else break;
            }
        }
    }

    void find(int value) {
        Node* itr = root;
        while (itr) {
            if (value == itr->data) {
                query[value] = itr->index;
                return ;
            }
            else if (value < itr->data) {
                if (query[itr->data] == null) query[itr->data] = itr->index;
                itr = itr->left;
            }
            else {
                if (query[itr->data] == null) query[itr->data] = itr->index;
                itr = itr->right;
            }
        }
    }
};

int main() {
    int n, m;   scanf("%d%d", &n, &m);
    Tree t;
    for (int i = 1; i <= n; i++) {
        int k;  scanf("%d", &k);
        t.insert(k, i);
    }

    int q[m];
    for (int i = 0; i < m; i++) {
        int k;  scanf("%d", &k);
        query[k] = null;
        q[i] = k;
    }

    for (auto i = query.begin(); i != query.end(); i++)
        if (i->second == null) t.find(i->first);
    
    for (int i = 0; i < m; i++)
        printf("%d ", query[q[i]]);
}