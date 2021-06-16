using System;

namespace basic
{
    class Program
    {
        static void change(Node node)
        {
            node.data += 2;
        }
        static void Main(string[] args)
        {
            Node node = new Node(3);
            change(node);
            Console.WriteLine(node.data);
        }
    }

    public class Node
    {
        public int data;
        public Node next;
        public Node(int value = 0)
        {
            data = value;
            next = null;
        }
    }
}
