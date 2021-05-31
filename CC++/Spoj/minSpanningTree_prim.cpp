#include <iostream>
#include <queue>
using namespace std;

struct dest {
    int v, cost;
    dest(int _v, int _cost) {
        v = _v;
        cost = _cost;
    }

    bool operator>(const dest &src) const {
        return cost > src.cost;
    }
};

vector< vector<dest> > adj;

int prim(int vertices) {
    int minCost = 0;
    priority_queue< dest, vector<dest>, greater<dest> > q;
    q.push(dest(1, 0));
    vector<bool> picked(vertices + 1, false);

    while (!q.empty()) {
        int minVertex = q.top().v;
        int cost = q.top().cost;
        q.pop();

        if (picked[minVertex])
            continue;
        minCost += cost;
        picked[minVertex] = true;
        for (auto i = adj[minVertex].begin(); i != adj[minVertex].end(); i++) {
            if (!picked[i->v]) {
                q.push(dest(i->v, i->cost));
            }
        }
    }

    return minCost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int vertices, edges;
    cin >> vertices >> edges;
    adj.resize(vertices + 1);
    while (edges--) {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        adj[v1].push_back(dest(v2, cost));
        adj[v2].push_back(dest(v1, cost));
    }

    cout << prim(vertices);
}