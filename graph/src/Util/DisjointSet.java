package Util;

public class DisjointSet {
    /**
     * Phep gop cay 
     * @param parent mang luu lai parents cua cac node
     * @param node1
     * @param node2
     * @throws Exception neu hai node trong cung mot cay
     */
    public static void union(int[] parent, int node1, int node2) throws Exception {
        int height1 = 0, height2 = 0;
        int p1 = node1, p2 = node2;
        for (; parent[p1] != p1; p1 = parent[p1])   // tim root cua node1
            height1++;
        for (; parent[p2] != p2; p2 = parent[p2]) // tim root cua node2
            height2++;
        
        if (p1 == p2)
            throw new Exception("Two nodes is in the same tree");
        if (height1 > height2)
            parent[p2] = node1;
        else 
            parent[p1] = node2;
    }
}
