#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    int from;
    int to;
    int dist;
};

vector<Edge> sort(vector<Edge> arr)
{
    for (int i = 0; i < arr.size(); i++)
        for (int j = i + 1; j < arr.size(); j++)
            if (arr[i].dist < arr[j].dist)
                swap(arr[i], arr[j]);
    return arr;
}

bool canUnion(vector<int> treeType, Edge k)
{
    if (treeType[k.from] == treeType[k.to]) return false;
    return true;
}

vector<int> Union(vector<int> tree, Edge k)
{
    int root_from = tree[k.from],   root_to = tree[k.to];
    int from_freq = 0, to_freq = 0;
    for (int i = 0; i < tree.size(); i++)
        if (tree[i] == root_from) from_freq++;
        else if (tree[i] == root_to) to_freq++;
    
    if (from_freq >= to_freq)
    {
        for (int i = 0; i < tree.size(); i++)
            if (tree[i] == root_to) tree[i] = root_from;
    }
    else for (int i = 0; i < tree.size(); i++)
            if (tree[i] == root_from) tree[i] = root_to;
    return tree;
}

vector<Edge> Kruskal(int vertex, vector<Edge> link)
{
    vector<Edge> spaningTree;
    vector<int> tree(vertex + 1);

    link = sort(link);
    for (int i = 0; i < tree.size(); i++)
        tree[i] = i;
    while (spaningTree.size() < vertex - 1)
    {
        if (canUnion(tree, link.back()))
        {
            spaningTree.push_back(link.back());
            tree = Union(tree, link.back());
        }
        link.pop_back();
    }

    return spaningTree;
}

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;

    vector<Edge> link(edges);

    for (int i = 0; i < edges; i++)
        cin >> link[i].from >> link[i].to >> link[i].dist;
    
    vector<Edge> spaningTree = Kruskal(vertex, link);
    
    // for (int i = 0; i < spaningTree.size(); i++)
    //     cout << spaningTree[i].from << " => " << spaningTree[i].to << " : " << spaningTree[i].dist << endl;
    int k = 0;
    for (int i = 0; i < spaningTree.size(); i++)
        k += spaningTree[i].dist;
    cout << k;
}