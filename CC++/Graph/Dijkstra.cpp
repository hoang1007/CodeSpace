#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 999999999

struct dest {
    int vertex;
    int distance;
    dest(int _vertex, int _distance) {
        vertex = _vertex;
        distance = _distance;
    }
};

void print(vector<int> pre, int start, int end) {
    if (start == end) {
        cout << start << " ";
        return ;
    }
    print(pre, start, pre[end]);
    cout << end << " ";
}

void dijkstra(int vertices, const vector<vector<dest>> &adjacency, int start, int end) {
    vector<int> pre(vertices + 1);
    for (int i = 0; i < pre.size(); i++)
        pre[i] = i;

    vector<int> dist(vertices + 1, INF);
    vector<bool> known(vertices + 1, false);

    dist[start] = 0;
    for (int c = 0; c < vertices; c++) {
        int minDist = INF, minVertex = 0;
        for (int i = 0; i < vertices; i++) {
            if (dist[i] < minDist && !known[i]) {
                minDist = dist[i];
                minVertex = i;
            }
        }

        known[minVertex] = true;

        for (int i = 0; i < adjacency[minVertex].size(); i++) {
            if (dist[ adjacency[minVertex][i].vertex ] > dist[minVertex] + adjacency[minVertex][i].distance) {
                dist[ adjacency[minVertex][i].vertex ] = dist[minVertex] + adjacency[minVertex][i].distance;
                pre[ adjacency[minVertex][i].vertex ] = minVertex;
            }
        }
    }

    print(pre, start, end);
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<dest>> adjacency(vertices + 1);
    for (int i = 0; i < edges; i++) {
        int v1, v2, dist;
        cin >> v1 >> v2 >> dist;
        adjacency[v1].push_back(dest(v2, dist));
        adjacency[v2].push_back(dest(v1, dist));
    }

    int start, end;
    cin >> start >> end;

    dijkstra(vertices, adjacency, start, end);
}