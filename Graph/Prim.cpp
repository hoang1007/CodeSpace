#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge
{
    int from, to, dist;
    Edge() 
    {
        from = to = 0;
        dist = INT8_MAX;
    }
    Edge(int _from, int _to, int _dist)
    {
        from = _from;
        to = _to;
        dist = _dist;
    }
    bool operator==(const Edge& src)
    {
        return from == src.from & to == src.to & dist == src.dist;
    }
    friend ostream& operator<<(ostream& out, Edge& e)
    {
        out << e.from << " => " << e.to << " : " << e.dist << endl;
        return out; 
    }
};

vector<Edge> Prim(vector<vector<int>> link, int vertex)
{
    vector<Edge> res;
    vector<bool> visited(vertex + 1, false);
    int currentNode = 1;

    vector<Edge> edges;
    while (res.size() < vertex - 1)
    {
        visited[currentNode] = true;
        for (int i = 1; i <= vertex; i++)
        {
            int distance_currentNode_i = link[currentNode][i];
            if (distance_currentNode_i && !visited[i])
            {
                if (edges.empty())
                    edges.push_back(Edge(currentNode, i, distance_currentNode_i));
                else
                {
                    if (distance_currentNode_i < edges.back().dist)
                        edges.push_back(Edge(currentNode, i, distance_currentNode_i));
                    else for (int j = 0; j < edges.size(); j++)
                        if (edges[j].dist < distance_currentNode_i)
                        {
                            edges.insert(edges.begin() + j, Edge(currentNode, i, distance_currentNode_i));
                            break;
                        }
                }
            }
        }
        currentNode = edges.back().to;
        res.push_back(edges.back());
        edges.pop_back();
    }
    return res;
}

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;

    vector<vector<int>> link(vertex + 1, vector<int> (vertex + 1, 0));

    for (int i = 0; i < edges; i++)
    {
        int vertex1, vertex2, dist;
        cin >> vertex1 >> vertex2 >> dist;

        link[vertex1][vertex2] = link[vertex2][vertex1] = dist;
    }
    vector<Edge> res = Prim(link, vertex);
    for (int i = 0; i < res.size(); i++)
        cout << res[i];
}