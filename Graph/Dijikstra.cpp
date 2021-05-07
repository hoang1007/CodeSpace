#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    int from, to, dist;
    friend istream& operator >>(istream& is, Edge& e)
    {
        is >> e.from >> e.to >> e.dist;
        return is;
    }
};

void Dijikstra()
{

}

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;

    vector<Edge> Edges(edges);

    for (int i = 0; i < Edges.size(); i++)
        cin >> Edges[i];
    
}