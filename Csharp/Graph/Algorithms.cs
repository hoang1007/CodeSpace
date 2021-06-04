using System.Collections.Generic;
using System;

namespace Graph
{
    public partial class Program
    {
        public class Algorithms
        {
            public int[] bfsTraversal(int vertices, List<List<Edge>> adj, int start) 
            {
                bool[] visited = new bool[vertices + 1];
                int[] order = new int[vertices];
                int itr = 0;
                Queue<int> q = new Queue<int>();
                q.Enqueue(start);
                visited[start] = true;
                
                while (q.Count != 0) 
                {
                    int current = q.Dequeue();
                    order[itr++] = current;

                    foreach (var item in adj[current])
                        if (!visited[item.v])
                        {
                            q.Enqueue(item.v);
                            visited[item.v] = true;
                        }
                }
                return order;
            }

            public int[] dfsTraversal(int vertices, List<List<Edge>> adj, int start) 
            {
                int[] order = new int[vertices];
                int itr = 0;

                bool[] visited = new bool[vertices + 1];
                visited[start] = true;
                int current = start;
        stack:  // replace for recursion dfs (or stack)
                order[itr++] = current;
                foreach (var edge in adj[current])
                    if (!visited[edge.v]) 
                    {
                        visited[edge.v] = true;
                        current = edge.v;
                        goto stack;
                    }
                return order;
            }
            
            bool Union(int[] parent, int v1, int v2)
            {
                int parentV1 = parent[v1], parentV2 = parent[v2];
                while (parent[parentV1] != parentV1) parentV1 = parent[parentV1];
                while (parent[parentV2] != parentV2) parentV2 = parent[parentV2];

                if (parentV1 == parentV2) return false;
                parent[parentV2] = v1;
                return true;
            }
            public string[] kruskal(int vertices, List<List<Edge>> adj)
            {
                string[] spanningTree = new string[vertices];
                int itr = 0;
                Dictionary<Edge, int> from = new Dictionary<Edge, int>();
                PriorityQueue<Edge> queue = new PriorityQueue<Edge>();
                for (int i = 0; i <= vertices; i++)
                    foreach (var edge in adj[i])
                    {
                        queue.push(edge);
                        from[edge] = i;
                    }
                
                int[] parent = new int[vertices + 1];
                for (int i = 1; i <= vertices; i++)
                    parent[i] = i;
                
                while (!queue.empty)
                {
                    Edge current = queue.pop();
                    if (Union(parent, from[current], current.v))
                        spanningTree[itr++] = from[current] + " " + current.ToString();
                }

                return spanningTree;
            }

            public string[] prim(int vertices, List<List<Edge>> adj)
            {
                string[] spanningTree = new string[vertices];
                int itr = 0;
                bool[] picked = new bool[vertices + 1];
                int start = 1;
                picked[start] = true;

                PriorityQueue<Edge> queue = new PriorityQueue<Edge>();
                Dictionary<Edge, int> from = new Dictionary<Edge, int>();

                foreach (var edge in adj[start])
                {
                    queue.push(edge);
                    from[edge] = start;
                }

                while (!queue.empty)
                {
                    Edge current = queue.pop();
                    if (picked[current.v]) continue;
                    picked[current.v] = true;
                    spanningTree[itr++] = from[current] + " " + current.ToString();

                    foreach (var edge in adj[current.v])
                        if (!picked[edge.v])
                        {
                            queue.push(edge);
                            from[edge] = current.v;
                        }
                }

                return spanningTree;
            }

            public int[] dijkstra(int vertices, List<List<Edge>> adj, int start)
            {
                const int INF = int.MaxValue;
                int[] pre = new int[vertices + 1];
                int[] dist = new int[vertices + 1];
                for (int i = 0; i < dist.Length; i++)
                    dist[i] = INF;
                
                PriorityQueue<Edge> queue = new PriorityQueue<Edge>();
                dist[start] = 0;
                pre[start] = start;
                queue.push(new Edge(start, 0));

                while (!queue.empty)
                {
                    Edge current = queue.pop();
                    if (dist[current.v] != current.cost) continue;

                    foreach (var edge in adj[current.v])
                        if (dist[edge.v] > dist[current.v] + edge.cost)
                        {
                            dist[edge.v] = dist[current.v] + edge.cost;
                            pre[edge.v] = current.v;
                            queue.push(new Edge(edge.v, dist[edge.v]));
                        }
                }
                return pre;
            }

            public void printPath(int[] pre, int start, int end)
            {
                if (start == end)
                {
                    Console.Write(start + " => ");
                    return ;
                }
                printPath(pre, start, pre[end]);
                Console.Write(end + " ");
            }
        }
    }
}