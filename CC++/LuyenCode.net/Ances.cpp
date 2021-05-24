#include <cstdio>
#include <vector>
using namespace std;

struct Info {
    int parent;
    bool isNull;
    bool rootLeaf;
    int depth;
    vector<int> child;
    Info() {
        parent = 0;
        isNull = true;
        rootLeaf = false;
        depth = 0;
    }
    
    void Alloc(const int &_parent, const Info &_parentInfo) {
        parent = _parent;
        isNull = false;
        rootLeaf = _parentInfo.rootLeaf;
        depth = _parentInfo.depth + 1;
    }
};

void update(Info node[], int _parent) {
    if (node[_parent].child.empty()) return ;
    for (int i = 0; i < node[_parent].child.size(); i++) {
        node[node[_parent].child[i]].Alloc(_parent, node[_parent]);
        update(node, node[_parent].child[i]);
    }
}

void reverse(Info node[], int k) {
    if (node[node[k].parent].isNull || node[node[k].parent].rootLeaf) return ;
    reverse(node, node[k].parent);

    Info &_parent = node[node[k].parent];
    for (int i = 0; i < _parent.child.size(); i++)
        if (_parent.child[i] == k) _parent.child.erase(_parent.child.begin() + i);
    _parent.Alloc(k, node[k]);
    node[k].child.push_back(node[k].parent);
}

void Union(Info node[], int k1, int k2) {
    if (node[k2].isNull) {
        node[k2].Alloc(k1, node[k1]);
        node[k1].isNull = false;
        node[k1].child.push_back(k2);
    }
    else if (node[k1].isNull) {
        node[k1].Alloc(k2, node[k2]);
        node[k2].isNull = false;
        node[k2].child.push_back(k1);
    }
    else {
        if (node[k2].rootLeaf) {
            if (!node[node[k1].parent].isNull)
                reverse(node, k1);
            node[k1].Alloc(k2, node[k2]);
            node[k2].child.push_back(k1);
            update(node, k1);
        }
        else {
            if (!node[node[k2].parent].isNull)
                reverse(node, k2);
            node[k2].Alloc(k1, node[k1]);
            node[k1].child.push_back(k2);
            update(node, k2);
        }
    }
}

int main() {
    int n, root;
    scanf("%d%d", &n, &root);

    Info node[n + 1];
    node[root].isNull = false;
    node[root].rootLeaf = true;

    for (int i = 0; i < n - 1; i++) {
        int k1, k2;
        scanf("%d%d", &k1, &k2);
        Union(node, k1, k2);
    }

    int k1, k2; scanf("%d%d", &k1, &k2);
    
    while (node[k1].depth < node[k2].depth) k2 = node[k2].parent;
    while (node[k2].depth < node[k1].depth) k1 = node[k1].parent;
    while (k1 != k2) {
        k1 = node[k1].parent;
        k2 = node[k2].parent;
    }
    printf("%d", k2);
    // for (int i = 1; i <= n; i++) {
    //     printf("Node %d:  depth: %d  parent: %d\n", i, node[i].depth, node[i].parent);
    // }
}