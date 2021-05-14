import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Kruskal {
    static class Edge {
        int from, to, distance;

        Edge(int _from, int _to, int _distance) {
            from = _from;
            to = _to;
            distance = _distance;
        }

        private void print() {
            System.out.println(from + " => " + to + " : " + distance);
        }
    };

    static void swap(Edge edges[], int i, int j) {
        Edge temp = edges[i];
        edges[i] = edges[j];
        edges[j] = temp;
    }

    static void sort(Edge edges[]) {
        for (int i = 0; i < edges.length - 1; i++)
            for (int j = i + 1; j < edges.length; j++)
                if (edges[i].distance > edges[j].distance)
                    swap(edges, i, j);
    }

    static boolean canUnion(int root[], Edge e) {
        return root[e.from] != root[e.to];
    }

    static void union(int root[], Edge e) {
        int rootOfNode1 = root[e.from],
            rootOfNode2 = root[e.to];

        int size1 = 0,  size2 = 0;
        
        for (int i : root) {
            if (i == rootOfNode1) size1++;
            else if (i == rootOfNode2) size2++;
        }
        if (size1 > size2) 
        {
            for (int i = 0; i < root.length; i++)
                if (root[i] == rootOfNode2) root[i] = rootOfNode1;
        }
        else
            for (int i = 0; i < root.length; i++)
                if (root[i] == rootOfNode1) root[i] = rootOfNode2;
    }

    static ArrayList<Edge> spanningTree(int vertexes, Edge edges[]) {
        ArrayList<Edge> tree = new ArrayList<Edge>(vertexes - 1);
        int root[] = new int[vertexes]; // stores root of nodes
        Arrays.setAll(root, i -> i);
        
        sort(edges); // sort edges;
        
        for (int i = 0; tree.size() < vertexes - 1; i++) {
            if (canUnion(root, edges[i])) {
                tree.add(edges[i]);
                union(root, edges[i]);
            }
        }
        return tree;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int vertexes = sc.nextInt();
        int numberOfEdges = sc.nextInt();
        Edge edges[] = new Edge[numberOfEdges];

        for (int i = 0; i < edges.length; i++)
            edges[i] = new Edge(sc.nextInt(), sc.nextInt(), sc.nextInt());

        ArrayList<Edge> tree = spanningTree(vertexes, edges);
        for (Edge i : tree) {
            i.print();
        }
        sc.close();
    }
}

/*
6 10
0 3 3
0 4 4
0 1 7
1 3 8
1 2 2
3 4 1
3 2 8
4 2 6
4 5 9
2 5 5
*/