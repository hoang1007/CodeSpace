public class Edge implements Comparable<Edge> {
    public int v1;
    public int v2;
    public int distance;

    public Edge(int v1, int v2, int distance) {
        this.v1 = v1;
        this.v2 = v2;
        this.distance = distance;
    }

    public int getOther(int k) {
        if (v1 == k)
            return v2;
        if (v2 == k)
            return v1;
        throw new IllegalArgumentException("Not found");
    }

    @Override
    public String toString() {
        return "(" + v1 + ", " + v2 +") -> " + distance;
    }

    @Override
    public int compareTo(Edge o) {
        return Integer.compare(this.distance, o.distance);
    }
}