#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX INT8_MAX

int vertex, edges;
void printPath(vector<int> pre, int start, int end)
{
    if (start == end)
    {
        cout << start << " => ";
        return ;
    }
    printPath(pre, start, pre[end]);
    cout << end << " => ";
}

void Dijikstra(vector<vector<int>> Map, int start, int end)
{
    vector<int> pre(vertex + 1), dist(vertex + 1, MAX);
    vector<bool> known(vertex + 1, false);

    dist[start] = 0;
    queue<int> qVertex;
    qVertex.push(start);
    known[start] = true;
    while (!qVertex.empty())
    {
        int currentVertex = qVertex.front();
        qVertex.pop();

        for (int i = 0; i < Map[currentVertex].size(); i++)
        {
            if (Map[currentVertex][i])
            {
                if (!known[i])
                {
                    qVertex.push(i);
                    known[i] = true;
                }
                int distFromStart = dist[currentVertex] + Map[currentVertex][i];
                if (dist[i] > distFromStart)
                {
                    pre[i] = currentVertex;
                    dist[i] = distFromStart;
                }
            }
        }
    }

    printPath(pre, start, end);
}

int main()
{
    cin >> vertex >> edges;
    
    vector<vector<int>> Map(vertex + 1, vector<int> (vertex + 1, 0));

    for (int i = 0; i < edges; i++)
    {
        int from, to, dist;
        cin >> from >> to >> dist;
        Map[from][to] = Map[to][from] = dist;
    }

    int start, end;
    cin >> start >> end;
    Dijikstra(Map, start, end);
}