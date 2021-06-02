using System;

namespace test {
    class List {
        public class Node {
            public int data;
            public Node next;
        
            public Node(int value = 0) {
                data = value;
                next = null;
            }
        }

        public Node head, tail;
        int length;
        public List() {
            head = tail = null;
            length = 0;
        }
        public int Length {
            get {return length;}
        }
        public void push_back(int value) {
            Node node = new Node(value);
            if (head == null)
                head = node;
            else tail.next = node;
            tail = node;
            length++;
        }
        public void push_front(int value) {
            Node node = new Node(value);
            if (tail == null)
                tail = node;
            else node.next = head;
            head = node;
            length++;
        }

        public void pop_back() {
            if (head == null) return ;
            Node temp = head;
            for (; temp != tail; temp = temp.next);
            temp.next = null;
            tail = temp;
            length--;
        }
        public void pop_front() {
            if (head == null) return ;
            Node temp = head;
            head = head.next;
            temp = null;
            length--;
        }

        public void print() {
            for (Node temp = head; temp != null; temp = temp.next)
                Console.Write(temp.data + " ");
            Console.WriteLine();
        }

        public bool empty() {
            return head == null;
        }

    }
    class Program {
        static void Main(string[] args) {
            List l = new List();

            string[] tokens = Console.ReadLine().Split();
            foreach (var i in tokens)
                l.push_back(int.Parse(i));
            l.print();
            Console.WriteLine(l.Length);
        }
    }
}
