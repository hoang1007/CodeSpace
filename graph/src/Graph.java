import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import Util.DisjointSet;

public class Graph {
    static final int INF = (int) 1e9;
    List<Edge> edges;
    int vertices;

    public Graph(int vertices) {
        edges = new ArrayList<Edge>();
        this.vertices = vertices;
    }

    public void add(Edge edge) {
        edges.add(edge);
    }

    public List<Integer> dijkstra(int start) {
        List<Integer> distances = new ArrayList<>();
        // khoi tao gia tri cua cac dinh la vo cung
        for (int i = 0; i < vertices; i++)
            distances.add(INF);
        // mang danh dau cac dinh da chon
        boolean[] picked = new boolean[vertices];

        distances.set(start, 0); // khoang cach tu start -> start la 0

        for (int i = 0, current = start; i < vertices; i++) {
            picked[current] = true; // danh dau dinh da chon

            // tim cac dinh ke cua dinh <current>
            for (var edge : edges) {
                try {
                    int otherVertex = edge.getOther(current);

                    if (!picked[otherVertex] && edge.distance + distances.get(current) < distances.get(otherVertex)) {
                        // cap nhat khoang cach
                        distances.set(otherVertex, edge.distance + distances.get(current));
                    }
                } catch (Exception e) {
                }
            }

            // tim dinh co khoang cach gan nhat voi current
            int minDistance = INF;
            for (int j = 0; j < vertices; j++) {
                if (!picked[j] && j != current && distances.get(j) < minDistance) {
                    minDistance = distances.get(j);
                    current = j;
                }
            }
        }
        return distances;
    }

    public List<Edge> prim() {
        // list chua cac canh cua minimum spanning tree
        List<Edge> minSpanning = new ArrayList<Edge>();
        // khoi tao gia tri ban dau cua list
        for (int i = 0; i < vertices; i++)
            minSpanning.add(new Edge(i, -1, INF));
        // mang danh dau nhung dinh da duoc chon
        boolean[] picked = new boolean[vertices];
        int current = edges.get(0).v1; // chon dinh bat ki lam dinh ban dau
        minSpanning.set(current, new Edge(current, current, 0)); // dat canh ban dau co distance = 0

        for (int i = 0; i < vertices; i++) {
            picked[current] = true; // danh dau dinh current da duoc chon
            // cap nhat cac canh
            for (var edge : edges) {
                try {
                    int otherVertex = edge.getOther(current);
                    if (!picked[otherVertex] && edge.distance < minSpanning.get(otherVertex).distance)
                        minSpanning.set(otherVertex, edge);
                } catch (Exception e) {
                }
            }

            // tim canh nho nhat de chon current tiep theo
            int minDistance = INF;
            for (int j = 0; j < vertices; j++) {
                if (!picked[j] && j != current && minSpanning.get(j).distance < minDistance) {
                    minDistance = minSpanning.get(j).distance;
                    current = j;
                }
            }
        }

        return minSpanning;
    }

    public List<Edge> kruskal() {
        // list chua cac canh cua minimum spanning tree
        List<Edge> minSpanning = new ArrayList<>();
        // mang luu lai parent cua cac dinh
        int[] parent = new int[vertices];
        // khoi tao mang parent
        for (int i = 0; i < vertices; i++) {
            parent[i] = i;
        }

        // list chua cac canh da duoc sap xep tang dan
        List<Edge> sortedEdges = new ArrayList<>(edges);
        Collections.sort(sortedEdges);

        for (int i = 0; minSpanning.size() < vertices && i < sortedEdges.size(); i++) {
            Edge edge = sortedEdges.get(i);
            try {
                DisjointSet.union(parent, edge.v1, edge.v2);
                minSpanning.add(edge);
            } catch (Exception e) {
            }
        }

        return minSpanning;
    }

    public void floyd() {
        
    }
}