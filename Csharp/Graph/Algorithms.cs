using System.Collections.Generic;

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

            public Edge[] kruskal(int vertices, List<List<Edge>> adj)
            {
                Edge[] spanningTree = new Edge[vertices];

                return spanningTree;
            }
        }
    }
}