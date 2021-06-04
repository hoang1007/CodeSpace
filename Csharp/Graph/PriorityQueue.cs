using System.Collections.Generic;

namespace Graph
{
    public class PriorityQueue<T>
    {
        List<T> data;
        public PriorityQueue()
        {
            data = new List<T>();
        }
        public PriorityQueue(List<T> input)
        {
            data = input;
            for (int i = input.Count/2 - 1; i >= 0; i--)
                heapify(i);
        }
        void swap(int i, int j) 
        {
            T temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
        void heapify(int nodeIndex)
        {
            int left = 2*nodeIndex + 1,
                right = 2*nodeIndex + 2,
                smallest = nodeIndex;
            
            if (left < data.Count && Comparer<T>.Default.Compare(data[left], data[smallest]) < 0)
                smallest = left;
            if (right < data.Count && Comparer<T>.Default.Compare(data[right], data[smallest]) < 0)
                smallest = right;
            
            if (smallest != nodeIndex)
            {
                swap(smallest, nodeIndex);
                heapify(smallest);
            }
        }

        public void push(T value)
        {
            data.Add(value);
            for (int i = data.Count/2 - 1; i >= 0; i--)
                heapify(i);
        }

        public T pop()
        {
            T temp = data[0];
            swap(0, data.Count - 1);
            data.RemoveAt(data.Count - 1);
            heapify(0);
            return temp;
        }

        public bool empty
        {
            get {return data.Count == 0;}
        }
    }
}