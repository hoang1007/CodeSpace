#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF -1

struct dest {
    int vertex;
    int cost;
    dest(int _vertex, int _cost) {
        vertex = _vertex;
        cost = _cost;
    }
    bool operator>(const dest& src) const {
        return cost > src.cost;
    }
};

vector<int> dijkstra(int vertices, const vector<vector<dest>> &adj, int start) {
    vector<int> dist(vertices + 1, INF);
    //vector<bool> known(vertices + 1, false);
    priority_queue<dest, vector<dest>, greater<dest>> q;
    dist[start] = 0;
    q.push(dest(start, 0));
    //known[start] = true;
    while (!q.empty()) {
        int minVertex = q.top().vertex;
        int minDist = q.top().cost;
        q.pop();
        if (dist[minVertex] != minDist)
            continue;
        //known[minVertex] = true;
        for (auto i = adj[minVertex].begin(); i != adj[minVertex].end(); i++) {
            if (dist[i->vertex] == INF || dist[i->vertex] > dist[minVertex] + i->cost) {
                dist[i->vertex] = dist[minVertex] + i->cost;
                //if (!known[i->vertex]) {
                    q.push(dest(i->vertex, dist[i->vertex]));
                //}
            }
        }
    }
    dist.erase(dist.begin() + start);
    dist.erase(dist.begin());
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;  cin >> t;
    while (t--) {
            
        int vertices, edges;
        cin >> vertices >> edges;

        vector<vector<dest>> adj(vertices + 1);

        while (edges--) {
            int v1, v2, dist;
            cin >> v1 >> v2 >> dist;
            adj[v1].push_back(dest(v2, dist));
            adj[v2].push_back(dest(v1, dist));
        }

        int start; cin >> start;
        vector<int> result = dijkstra(vertices, adj, start);
        
        for (size_t i = 0; i < result.size(); i++) {
            cout << result[i];

            if (i != result.size() - 1) {
                cout << " ";
            }
        }

        cout << "\n";
    }
}