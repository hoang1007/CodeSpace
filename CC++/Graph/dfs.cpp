#include <iostream>
#include <vector>
using namespace std;

void dfs(int vertices, vector<vector<bool>> &adjacency, int start) {
    static vector<bool> visited(vertices + 1, false);
    visited[start] = true;
    cout << start << " ";
    for (int i = 0; i <= vertices; i++) {
        if (adjacency[start][i] && !visited[i]) 
            dfs(vertices, adjacency, i);
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
    dfs(vertices, adjacency, start);
}