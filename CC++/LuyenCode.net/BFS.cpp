#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

void BFS(vector<vector<bool>>& adjacency, int vertexes) {
    queue<int> q;
    bool visited[vertexes + 1];
    
    for (int i = 1; i <= vertexes; i++) {
        if (!visited[i]) {
            visited[i] = true;
            q.push(i);

            while (!q.empty()) {
                int current = q.front();
                q.pop();
                printf("%d\n", current);
                for (int j = 1; j <= vertexes; j++)
                    if (adjacency[current][j] && !visited[j]) {
                        visited[j] = true;
                        q.push(j);
                    }
            }
        }
    }
}

int main() {
    int vertexes, edges;
    scanf("%d%d", &vertexes, &edges);

    vector<vector<bool>> adjacency(vertexes + 1, vector<bool> (vertexes + 1, false));
    int start = vertexes;
    for (int i = 0; i < edges; i++) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        adjacency[v1][v2] = adjacency[v2][v1] = true;
    }

    BFS(adjacency, vertexes);
}