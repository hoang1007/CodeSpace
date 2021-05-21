#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    bool picked;
    int depth;
    int parent;
    Node(int _depth, int _parent) {
        depth = _depth;
        parent = _parent;
        picked = true;
    }
    Node() {
        depth = 0;
        parent = 0;
        picked = false;
    }
};

Node* node = NULL;

void constructTree(const vector<vector<bool>>& adjacency, int n, int root) {
    queue<int> q;
    Node nRoot;
    q.push(root);
    nRoot.picked = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (adjacency[current][i] && !node[i].picked) {
                node[i] = Node(node[current].depth + 1, current);
                q.push(i);
            }
        }
    }
}

int main() {
    int n, root;
    scanf("%d%d", &n, &root);
    
    node = new Node[n + 1];
    vector<vector<bool>> adjacency(n + 1, vector<bool>(n + 1, false));
    for (int i = 0; i < n - 1; i++) {
        int node1, node2;
        scanf("%d%d", &node1, &node2);
        adjacency[node1][node2] = adjacency[node2][node1] = true;
    }

    constructTree(adjacency, n, root);
    int node1, node2;
    scanf("%d %d", &node1, &node2);
    
    while (node[node1].depth < node[node2].depth)
        node1 = node[node1].parent;
    while (node[node2].depth < node[node1].depth)
        node2 = node[node2].parent;
    
    while (node1 != node2) {
        node1 = node[node1].parent;
        node2 = node[node2].parent;
    }

    printf("%d", node1);
}