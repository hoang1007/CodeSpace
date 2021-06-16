using System;

namespace sortList
{
    public class List
    {
        class Node
        {
            public int data;
            public Node next;
            public Node(int value = 0)
            {
                data = value;
                next = null;
            }
        }

        Node head, tail;
        int count;
        public List()
        {
            head = tail = null;
            count = 0;
        }

        public List(int[] input)
        {
            head = tail = null;
            count = 0;

            foreach (var item in input)
                push_back(item);
        }

        public int Count
        {
            get => count;
        }
        // public Node Head
        // {
        //     get => head;
        // }
        // public Node Tail
        // {
        //     get => tail;
        // }
        public void push_back(int value)
        {
            Node node = new Node(value);
            if (head == null)
                head = node;
            else tail.next = node;

            tail = node;
            count++;
        }

        public void push_front(int value)
        {
            Node node = new Node(value);
            if (head == null)
                tail = node;
            else node.next = head;
            head = node;
            count++;
        }
        public void insert(int value, int position) 
        {
            if (position < 0 || position > count)
                throw new ArgumentOutOfRangeException();
            if (position == 0)
                push_front(value);
            else if (position == count)
                push_back(value);
            else 
            {
                Node node = new Node(value);
                Node pre = head;
                for (; position > 1; pre = pre.next, position--);

                node.next = pre.next;
                pre.next = node;
                count++;
            }
        }
        public int pop_front()
        {
            if (count == 0) throw new NullReferenceException();
            int temp = head.data;
            head = head.next;
            count--;
            return temp;
        }

        public void print()
        {
            for (Node itr = head; itr != null; itr = itr.next)
                Console.Write(itr.data + " ");
            
            Console.WriteLine();
        }

        public static class Sort
        {
            static void swap(Node first, Node second)
            {
                int temp = first.data;
                first.data = second.data;
                second.data = temp;
            }
            public static List insertion(List list)
            {
                List sorted = new List();
                for (Node i = list.head; i != null; i = i.next)
                {
                    if (sorted.count == 0) sorted.push_back(i.data);
                    else 
                    {
                        int pos = 0;
                        for (Node j = sorted.head; j != null && j.data < i.data; j = j.next, pos++);

                        sorted.insert(i.data, pos);
                    }
                }
                return sorted;
            }

            public static List bubble(List list)
            {
                for (Node i = list.head; i.next != null; i = i.next)
                    for (Node j = i.next; j != null; j = j.next)
                        if (i.data > j.data)
                            swap(i, j);
                return list;
            }

            public static List selection(List list)
            {
                for (Node i = list.head; i.next != null; i = i.next)
                {
                    Node min = i;
                    for (Node j = i.next; j != null; j = j.next)
                        if (j.data < min.data) min = j;
                    swap(min, i);
                }
                return list;
            }

            // === Heap Sort ===
            static void heapify(List list, Node node, int idx) 
            {
                Node largest = node, left = node;
                
                int i = 0;
                for ( ; left != null && i < idx; i++, left = left.next);

                Node right = left == null ? null : left.next;
                if (left != null && left.data > largest.data)
                    largest = left;
                if (right != null && right.data > largest.data)
                {
                    largest = right;
                    i++;
                }
                
                if (largest != node) 
                {
                    swap(largest, node);
                    heapify(list, largest, idx + i);
                }
            }

            static void buildHeap(List list, Node node, int idx)
            {
                if (idx > list.count/2 - 1) return ;
                buildHeap(list, node.next, idx + 1);

                heapify(list, node, idx);
            }
            public static List heap(List list)
            {
                buildHeap(list, list.head, 0);
                
                List sorted = new List();
                while (list.count != 0)
                {
                    sorted.push_back(list.pop_front());
                    heapify(list, list.head, 0);
                }

                return sorted;
            }
        }
    }
}