import java.util.List;

class Main {
    public static void main(String[] args) {
        Graph graph = init();
        // List<Integer> distances = graph.dijkstra(0);
        
        // for (int i = 0; i < distances.size(); i++) {
        //     System.out.println("0 -> " + i + " : " + distances.get(i));
        // }
            
        List<Edge> minSpanning = graph.kruskal();
        for (var edge : minSpanning) {
            System.out.println(edge.toString());
        }
    }

    static Graph init() {
        Graph g = new Graph(9);
        g.add(new Edge(0, 1, 4));
        g.add(new Edge(0, 7, 8));
        g.add(new Edge(1, 2, 8));
        g.add(new Edge(1, 7, 11));
        g.add(new Edge(2, 3, 7));
        g.add(new Edge(2, 8, 2));
        g.add(new Edge(2, 5, 4));
        g.add(new Edge(3, 4, 9));
        g.add(new Edge(3, 5, 14));
        g.add(new Edge(4, 5, 10));
        g.add(new Edge(5, 6, 2));
        g.add(new Edge(6, 8, 6));
        g.add(new Edge(6, 7, 1));
        g.add(new Edge(7, 8, 7));
        return g;
    }

}