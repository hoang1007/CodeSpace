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

void Dijkstra(vector<vector<int>> Map, int start, int end)
{
    vector<int> pre(vertex + 1),    // lưu lại đỉnh trước đó
                dist(vertex + 1, MAX);  // lưu lại khoảng cách (được khởi tạo ban đầu là vô cùng)
    vector<bool> known(vertex + 1, false);  // lưu lại các đỉnh đã đi qua 

    dist[start] = 0;    // khởi tạo khoảng cách đến điểm xuất phát là 0
    queue<int> qVertex; // hàng đợi lưu các đỉnh để xét 
    qVertex.push(start);
    known[start] = true;

    while (!qVertex.empty())
    {
        int currentVertex = qVertex.front();    // cập nhật đỉnh đang xét hiện tại 
        qVertex.pop();

        for (int i = 0; i < Map[currentVertex].size(); i++)
        {
            if (Map[currentVertex][i])  // nếu có đường đi từ đỉnh hiện tại đến đỉnh đang tìm 
            {
                if (!known[i])  // nếu chưa xét 
                {
                    qVertex.push(i);
                    known[i] = true;
                }
                // tính khoảng cách từ đỉnh xuất phát đến đỉnh đang xét qua đỉnh hiện tại 
                int distFromStart = dist[currentVertex] + Map[currentVertex][i];
                if (distFromStart < dist[i])    // nếu nhỏ hơn khoảng cách cũ của đỉnh đang xét 
                {                               // cập nhật đỉnh đi và khoảng cách 
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
    Dijkstra(Map, start, end);
}