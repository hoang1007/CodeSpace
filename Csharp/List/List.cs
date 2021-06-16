using System;

namespace test
{
    public class List<T>
    {
        class Node
        {
            public T data;
            public Node next;
            public Node(T value)
            {
                data = value;
                next = null;
            }
        }

        Node head, tail;
        int count = 0;
        public List()
        {
            head = tail = null;
        }
        public List(T[] input)
        {
            head = tail = null;
            foreach (var item in input)
                push_back(item);
        }
        public int Count
        {
            get => count;
        }
        public bool empty
        {
            get => count == 0;
        }
        public void push_back(T value)
        {
            Node node = new Node(value);
            if (head == null)
                head = node;
            else tail.next = node;
            tail = node;
            count++;
        }

        public void push_front(T value)
        {
            Node node = new Node(value);
            if (tail == null)
                tail = node;
            else node.next = head;
            head = node;
            count++;
        }

        public void pop_back()
        {
            if (empty)
                throw new NullReferenceException("List is empty!");
            Node i = head;

            for (; i.next != tail; i = i.next) ;
            tail = i;
            count--;
        }

        public void pop_front()
        {
            if (empty)
                throw new NullReferenceException("List is empty!");
            head = head.next;
            count--;
        }

        public void print()
        {
            for (Node i = head; i != null; i = i.next)
                Console.Write(i.data + " ");
            Console.WriteLine();
        }

        public List<T> append(List<T> second)
        {
            if (!second.empty)
            {
                this.tail.next = second.head;
                this.tail = second.tail;
                count += second.Count;
            }
            return this;
        }

        void swap(Node first, Node second)
        {
            T temp = first.data;
            first.data = second.data;
            second.data = temp;
        }
    
        void reverse(ref Node low, Node high)
        {
            if (high == null) return ;
            reverse(ref low, high.next);
            swap(low, high);
            low = low.next;
        }

        public void reverse()
        {
            Node mid = head;
            for (int i = 0; i < count/2; i++, mid = mid.next);
            Node low = head;
            reverse(ref low, mid);
        }
    }
}