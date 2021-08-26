public class BinaryTree {
    public class Node {
        public int value;
        public Node left, right;

        public Node(int value) {
            this.value = value;
            left = right = null;
        }
    }

    Node root = null;

    private Node insert(Node root, Node node) {
        if (root == null)
            return node;

        if (node.value < root.value)
            root.left = insert(root.left, node);
        else if (node.value > root.value)
            root.right = insert(root.right, node);

        return root;
    }

    public void insert(int value) {
        root = insert(root, new Node(value));
    }

    private boolean find(Node node, int value) {
        if (node == null)
            return false;
        if (value < node.value)
            return find(node.left, value);
        else if (value > node.value)
            return find(node.right, value);

        return true;
    }

    public boolean find(int value) {
        return find(root, value);
    }

    private Node remove(Node node, int value) {
        if (node == null)
            return node;
        if (value < node.value)
            node.left = remove(node.left, value);
        else if (value > node.value)
            node.right = remove(node.right, value);
        else {
            // if node found
            // if node is leaf (has no child node)
            if (node.left == null && node.right == null)
                return null;
            // if node has one child node
            else if (node.right == null)
                return node.left;
            else if (node.left == null)
                return node.right;
            // if node has two child node
            else {
                // find most left of right subtree
                Node mostLeft = node.right;
                for (; mostLeft.left != null; mostLeft = mostLeft.left)
                    ;
                Utilities.swapData(node, mostLeft);
                node.right = remove(node.right, mostLeft.value);
            }
        }

        return node;
    }

    public void remove(int value) {
        root = remove(root, value);
    }

    private void preOrder(Node node) {
        if (node == null)
            return;
        System.out.print(node.value + " ");
        preOrder(node.left);
        preOrder(node.right);
    }

    public void preOrder() {
        preOrder(root);
        System.out.println();
    }

    private void inOrder(Node node) {
        if (node == null)
            return;
        inOrder(node.left);
        System.out.print(node.value + " ");
        inOrder(node.right);
    }

    public void inOrder() {
        inOrder(root);
        System.out.println();
    }

    private void postOrder(Node node) {
        if (node == null)
            return;
        postOrder(node.left);
        postOrder(node.right);
        System.out.print(node.value + " ");
    }

    public void postOrder() {
        postOrder(root);
        System.out.println();
    }
}

class Utilities {
    public static void swapData(BinaryTree.Node a, BinaryTree.Node b) {
        var temp = a.value;
        a.value = b.value;
        b.value = temp;
    }
}