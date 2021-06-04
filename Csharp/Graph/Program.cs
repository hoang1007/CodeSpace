using System.Collections.Generic;
using System;

namespace Graph
{
    public partial class Program
    {
        public class Edge : IComparable<Edge>
        {
            public int v;
            public int cost;
            public Edge(int v, int cost) 
            {
                this.v = v;
                this.cost = cost;
            }
            public Edge()
            {
                v = cost = 0;
            }
            public Edge(int v)  // for unWeight graph
            {
                this.v = v;
                cost = 0;
            }
            
            public override string ToString()
            {
                return "to " + v + " | cost " + cost;
            }
            public int CompareTo(Edge other) 
            {
                return this.cost.CompareTo(other.cost);
            }
        }

        static void Main(string[] args)
        {
            string[] tokens = Console.ReadLine().Split();

            int vertices = int.Parse(tokens[0]),
                edges = int.Parse(tokens[1]);
            
            List<List<Edge>> adj = new List<List<Edge>>(vertices + 1);
            for (int i = 0; i <= vertices; i++)
                adj.Add(new List<Edge>());
            while (edges-- > 0)
            {
                tokens = Console.ReadLine().Split();
                int v1 = int.Parse(tokens[0]),
                    v2 = int.Parse(tokens[1]),
                    cost = int.Parse(tokens[2]);
                
                adj[v1].Add(new Edge(v2, cost));
                adj[v2].Add(new Edge(v1, cost));
            }

            PriorityQueue<Edge> q = new PriorityQueue<Edge>();
            foreach (var item in adj)
                foreach(var edge in item)
                    q.push(edge);
            
            Algorithms a = new Algorithms();

            tokens = Console.ReadLine().Split();
            int start = int.Parse(tokens[0]),
                end = int.Parse(tokens[1]);

            a.printPath(a.dijkstra(vertices, adj, start), start, end);
        }
    }
}

/*
9 14
0 1 4
1 2 8
7 0 8
1 7 11
2 3 7
7 6 1
5 6 2
7 8 7
2 8 2
8 6 6
2 5 4
3 4 9
4 5 10
3 5 14

*/