using System;
using System.Collections.Generic;

namespace priorityqueue
{
    class PriorityQueue {
        List<int> data;
        public PriorityQueue() {
            data = new List<int>();
        }
        public PriorityQueue(int[] arr) {
            data = new List<int>();
            foreach (int i in arr)
                data.Add(i);
            for (int i = arr.Length/2 - 1; i >= 0; i--)
                heapify(i);
        }
        void swap(int a, int b) {
            int temp = data[a];
            data[a] = data[b];
            data[b] = temp;
        }
        void heapify(int node) {
            int left = 2*node + 1,
                right = 2*node + 2,
                largest = node;
            while (left < data.Count && data[left] > data[largest])
                largest = left;
            while (right < data.Count && data[right] > data[largest])
                largest = right;
            
            if (largest != node) {
                swap(largest, node);
                heapify(largest);
            }
        }
        public int pop() {
            int temp = data[0];
            swap(0, data.Count - 1);
            data.RemoveAt(data.Count - 1);
            heapify(0);
            return temp;
        }
        public void push(int value) {
            data.Add(value);
            for (int i = data.Count/2 - 1; i >= 0; i--)
                heapify(i);
        }
        public bool empty() {
            return data.Count == 0;
        }
    }
    class Program {
        static void Main(string[] args) {
            int[] arr = {2, 1, 4, 5, 3, 6, 7, 9, 0};
            PriorityQueue q = new PriorityQueue(arr);
            while (!q.empty())
                Console.Write(q.pop() + " ");
        }
    }
}
