#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
    int v1, v2, cost;
    Edge(int _v1, int _v2, int _cost) {
        v1 = _v1;
        v2 = _v2;
        cost = _cost;
    }

    bool operator>(const Edge& src) const {
        return cost > src.cost;
    }
};

priority_queue<Edge, vector<Edge>, greater<Edge>> q;

bool Union(int root[], Edge e) {
    int rootV1 = e.v1, rootV2 = e.v2;
    while (rootV1 != root[rootV1]) rootV1 = root[rootV1];
    while (rootV2 != root[rootV2]) rootV2 = root[rootV2];
    if (rootV1 == rootV2) return false;
    
    root[rootV2] = e.v1;
    return true;
}

int kruskal(int vertices) {
    int minCost = 0;
    int root[vertices + 1];
    for (int i = 0; i <= vertices; i++)
        root[i] = i;
    
    for (int i = 1; i < vertices; ) {
        Edge min = q.top();
        q.pop();

        if (Union(root, min)) {
            minCost += min.cost;
            i++;
        }
    }
    return minCost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int vertices, edges;
    cin >> vertices >> edges;
    
    while (edges--) {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        q.push(Edge(v1, v2, cost));
    }

    cout << kruskal(vertices);
}