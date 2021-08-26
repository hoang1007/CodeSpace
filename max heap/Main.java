public class Main {
    public static void main(String[] args) {
        HeapTree tree = new HeapTree();
        int[] arr = new int[] { 5, 1, 2, 3, 6, 4 };

        for (int item : arr)
            tree.add(item);
        tree.preOrder();

        tree.removeRoot();
        tree.preOrder();
    }
}
