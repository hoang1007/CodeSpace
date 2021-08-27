public class BinaryTree {
    public class Node {
        int value;
        Node left, right;

        public Node(int value) {
            this.value = value;
        }
    }

    Node root;
    public BinaryTree() {
        root = null;
    }

    private Node insert(Node node, int value) {
        if (node == null)
            return new Node(value);
        if (value < node.value)
            node.left = insert(node.left, value);
        else if (value > node.value)
            node.right = insert(node.right, value);
        
        return node;
    }
    public void insert(int value) {
        root = insert(root, value);
    }

    private Node remove(Node node, int value) {
        if (node == null)
            return node;
        if (value < node.value)
            node.left = remove(node.left, value);
        else if (value > node.value)
            node.right = remove(node.right, value);
        else {
            // neu node khong co node con
            if (node.left == null && node.right == null)
                return null;
            // neu node co mot node con
            if (node.left == null)
                return node.right;
            if (node.right == null)
                return node.left;
            // neu node co hai node con
            // tim node trai nhat cua cay con ben phai 
            Node mostLeft = node.right;
            for (; mostLeft.left != null; mostLeft = mostLeft.left)
                ;
            // swap value of two nodes
            Util.swap(mostLeft, node);
            // de quy xoa node mostLeft
            node.right = remove(node.right, mostLeft.value);
        }

        return node;
    }
    public void remove(int value) {
        root = remove(root, value);
    }

    private void preOrder(Node node) {
        if (node == null) return;
        System.out.print(node.value + " ");
        preOrder(node.left);
        preOrder(node.right);
    }
    private void inOrder(Node node) {
        if (node != null) {
            inOrder(node.left);
            System.out.print(node.value + " ");
            inOrder(node.right);
        }
    }
    private void postOrder(Node node) {
        if (node != null) {
            postOrder(node.left);
            postOrder(node.right);
            System.out.print(node.value + " ");
        }
    }

    public static enum TraversalType {
        PREORDER, INORDER, POSTORDER
    }
    public void traverse(TraversalType type) {
        switch (type) {
            case PREORDER:
                preOrder(root);
                break;
            case INORDER:
                inOrder(root);
                break;
            case POSTORDER:
                postOrder(root);
                break;
            default:
                break;
        }
        System.out.println();
    }
}

class Util {
    public static void swap(BinaryTree.Node node1, BinaryTree.Node node2) {
        var temp = node1.value;
        node1.value = node2.value;
        node2.value = temp;
    }
}