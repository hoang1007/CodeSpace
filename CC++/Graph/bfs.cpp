#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int vertices, vector<vector<bool>> &adjacency, int start) {
    bool visited[vertices + 1] = {false};
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int current = q.front();
        cout << current << " ";
        q.pop();

        for (int i = 0; i < adjacency[current].size(); i++)
            if (adjacency[current][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
    }
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<bool>> adjacency(vertices + 1, vector<bool> (vertices + 1, false));
    while (edges--) {
        int v1, v2;
        cin >> v1 >> v2;
        adjacency[v1][v2] = adjacency[v2][v1] = true;
    }

    int start;  cin >> start;
    bfs(vertices, adjacency, start);
}