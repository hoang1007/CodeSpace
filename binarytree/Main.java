public class Main {
    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();

        int[] tokens = new int[]{3, 1, 2, 5, 4, 6};

        for (int i : tokens)
            tree.insert(i);
        
        tree.preOrder();
        tree.remove(3);
        tree.preOrder();
    }
}
