#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void printPath(vector<int> pre, int end)
{
    if (pre[end] == end)
    {
        cout << end << " => ";
        return ;
    }
    printPath(pre, pre[end]);
    cout << end << " => ";
}

void dijkstra(vector<vector<int>> Distance, int from, int to)
{
    vector<int> pre(Distance.size(), 0);
    vector<bool> known(Distance.size(), false);
    vector<int> dist(Distance.size(), INT8_MAX);
    queue<int> qVertex;
    // khoi tao
    pre[from] = from;
    known[from] = true;
    dist[from] = 0;
    qVertex.push(from);

    while (!qVertex.empty())
    {
        int currentVertex = qVertex.front();
        qVertex.pop();

        for (int i = 0; i < Distance[currentVertex].size(); i++)
        {
            int distance_currentVertex_i = Distance[currentVertex][i];
            if (distance_currentVertex_i)
            {
                if (!known[i])
                {
                    qVertex.push(i);
                    known[i] = true;
                }

                if (distance_currentVertex_i + dist[currentVertex] < dist[i])
                {
                    dist[i] = distance_currentVertex_i + dist[currentVertex];
                    pre[i] = currentVertex;
                }
            }
        }
    }

    printPath(pre, to);
}

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;
    vector<vector<int>> Distance(vertex + 1, vector<int> (vertex + 1, 0));

    for (int i = 0; i < edges; i++)
    {
        int v1, v2, dist;
        cin >> v1 >> v2 >> dist;
        Distance[v1][v2] = Distance[v2][v1] = dist;
    }
    int from, to;
    cin >> from >> to;
    dijkstra(Distance, from, to);
}