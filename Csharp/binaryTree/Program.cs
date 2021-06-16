using System;

namespace binaryTree
{
    class Tree {
        public class Node {
            public int data;
            public Node left, right;
            public Node(int value = 0) {
                data = value;
                left = right = null;
            }
        }

        Node root;
        public Tree() {
            root = null;
        }

        Node insert(Node parent, int value) {
            if (parent == null) 
                return new Node(value);
            
            if (value < parent.data)
                parent.left = insert(parent.left, value);
            else if (value > parent.data)
                parent.right = insert(parent.right, value);
            return parent;
        }
        public void insert(int value) {
            root = insert(root, value);
        }

        Node erase(Node node, int value) {
            if (node == null)
                throw new Exception("Can't find the value in tree");
            
            if (value < node.data)
                node.left = erase(node.left, value);
            else if (value > node.data)
                node.right = erase(node.right, value);
            else {
                if (node.left == null && node.right == null)
                    return null;
                else if (node.left == null)
                    return node.right;
                else if (node.right == null)
                    return node.left;
                else {
                    Node letfOfright = node.right;
                    while (letfOfright.left != null)
                        letfOfright = letfOfright.left;
                    node.data = letfOfright.data;
                    node.right = erase(node.right, node.data);
                }
            }
            return node;
        }
        public void erase(int value) {
            root = erase(root, value);
        }
        void preOrder(Node node) {
            if (node == null) return ;
            Console.Write(node.data + " ");
            preOrder(node.left);
            preOrder(node.right);
        }
        void inOrder(Node node) {
            if (node == null) return ;
            inOrder(node.left);
            Console.Write(node.data + " ");
            inOrder(node.right);
        }
        void postOrder(Node node) {
            if (node == null) return ;
            postOrder(node.left);
            postOrder(node.right);
            Console.Write(node.data + " ");
        }

        public void preOrder() {
            preOrder(root);
            Console.WriteLine();
        }
        public void inOrder() {
            inOrder(root);
            Console.WriteLine();
        }
        public void postOrder() {
            postOrder(root);
            Console.WriteLine();
        }
    }
    class Program {
        static void Main(string[] args) {
            int[] arr = {3, 1, 4, 2, 5, 6, 4, 8, 0, 10, 3};
            Tree b = new Tree();
            foreach (int i in arr) 
                b.insert(i);
            b.preOrder();
            b.erase(3);
            b.preOrder();
            b.inOrder();
        }
    }
}
