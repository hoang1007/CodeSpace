using System;

namespace queuestack
{
    abstract class List {
        public class Node {
            public int data;
            public Node next;
            public Node (int value = 0) {
                data = value;
                next = null;
            }
        }

        protected Node head, tail;
        protected int length;

        public List() {
            head = tail = null;
            length = 0;
        }
        public abstract void push(int value);
        public abstract int pop();
        public int Length {
            get {return length;}
        }
        public bool Empty {
            get {return length == 0;}
        }
    }

    class Queue : List {
        public override void push(int value) {
            Node node = new Node(value);
            if (head == null)
                head = node;
            else tail.next = node;
            tail = node;
            length++;
        }
        public override int pop() {
            if (!Empty) {
                int temp = head.data;
                head = head.next;
                length--;
                return temp;
            }
            throw new NullReferenceException();
        }
    }

    class Stack : List {
        public override void push(int value) {
            Node node = new Node(value);
            if (tail == null)
                tail = node;
            else node.next = head;
            head = node;
            length++;
        }
        public override int pop() {
            if (!Empty) {
                int temp = head.data;
                head = head.next;
                length--;
                return temp;
            }
            throw new NullReferenceException();
        }
    }
    class Program {
        static void Main(string[] args) {
            int[] arr = {1, 2, 3, 4, 5};
            Stack stack = new Stack();
            Queue queue = new Queue();
            foreach (int i in arr) {
                stack.push(i);
                queue.push(i);
            }

            while (!stack.Empty)
                Console.Write(stack.pop() + " ");
            Console.WriteLine();
            while(!queue.Empty)
                Console.Write(queue.pop() + " ");
        }
    }
}
