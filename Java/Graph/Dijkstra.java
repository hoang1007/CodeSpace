import java.util.Arrays;
import java.util.Scanner;

public class Dijkstra {
    static int[] dijkstra(int start, int vertexes, int dist[][]) {
        int pre[] = new int[vertexes + 1];
        pre[start] = start;

        boolean picked[] = new boolean[vertexes + 1];
        picked[start] = true;

        int distanceFromStart[] = new int[vertexes + 1];
        Arrays.fill(distanceFromStart, Integer.MAX_VALUE);
        distanceFromStart[start] = 0;
        for (int i = 1; i <= vertexes; i++)
            if (dist[start][i] != 0) {
                distanceFromStart[i] = dist[start][i];
                pre[i] = start;
            }
        
        for (int k = 0; k < vertexes; k++) {
            int minVertex = 0;
            for (int i = 1; i < distanceFromStart.length; i++)
                if (!picked[i] && distanceFromStart[i] < distanceFromStart[minVertex])
                    minVertex = i;

            picked[minVertex] = true;

            for (int i = 1; i < distanceFromStart.length; i++)
                if (dist[minVertex][i] != 0 && distanceFromStart[i] > distanceFromStart[minVertex] + dist[minVertex][i]) {
                    distanceFromStart[i] = distanceFromStart[minVertex] + dist[minVertex][i];
                    pre[i] = minVertex;
                }
        }
        return pre;
    }

    static void printPath(int path[], int start, int end) {
        if (end == start) {
            System.out.print(start);
            return ;
        }
        printPath(path, start, path[end]);
        System.out.print(" => " + end);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int vertexes = sc.nextInt();
        int numOfEdges = sc.nextInt();

        int dist[][] = new int[vertexes + 1][vertexes + 1];

        for (int i = 0; i < numOfEdges; i++) {
            int from = sc.nextInt(),
                to = sc.nextInt(),
                distance = sc.nextInt();
            
            dist[from][to] = dist[to][from] = distance;
        }
        int start = sc.nextInt(),
            end = sc.nextInt();

        printPath(dijkstra(start, vertexes, dist), start, end);

        sc.close();
    }
}

/*
6 9
1 3 2
3 6 1
1 4 5
4 5 3
1 2 3
2 4 1
2 5 4
5 6 2
4 3 2

*/