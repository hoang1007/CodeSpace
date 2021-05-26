#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int from, to, cost;
    Edge(int _from, int _to, int _cost) {
        from = _from;
        to = _to;
        cost = _cost;
    }
    bool operator > (const Edge &src) const {
        return cost > src.cost;
    }
};

int main() {
    priority_queue<Edge, vector<Edge>, greater<Edge>> q;
    q.push(Edge(1, 2, 5));
    q.push(Edge(2, 3, 1));
    q.push(Edge(3, 4, 7));
    q.push(Edge(4, 4, 0));

    while (!q.empty()) {
        q.top().print();
        q.pop();
    }
}