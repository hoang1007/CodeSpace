namespace sort
{
    public class Sort
    {
        void swap(int[] arr, int i, int j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        public int[] bubble(int[] arr)
        {
            for (int i = 0; i < arr.Length - 1; i++)
                for (int j = i + 1; j < arr.Length; j++)
                    if (arr[i] > arr[j])
                        swap(arr, i, j);
            return arr;
        }

        public int[] selection(int[] arr)
        {
            for (int i = 0; i < arr.Length - 1; i++)
            {
                int minIndex = i;
                for (int j = i + 1; j < arr.Length; j++)
                    if (arr[minIndex] > arr[j])
                        minIndex = j;
                swap(arr, i, minIndex);
            }
            return arr;
        }

        public int[] insertion(int[] arr)
        {
            for (int i = 1; i < arr.Length; i++)
            {
                int key = arr[i];
                int j = i - 1;
                for ( ;j >= 0 && arr[j] > key; j--)
                    arr[j + 1] = arr[j];
                arr[j + 1] = key;
            }
            return arr;
        }

        int parition(int[] arr, int low, int high) 
        {
            int left = low,
                right = high - 1,
                pivot = arr[high];
            
            while (true)
            {
                while (left <= right && arr[left] < pivot) left++;
                while (left <= right && arr[right] > pivot) right--;

                if (left >= right) break;
                swap(arr, left, right);
                left++; right--;
            }
            swap(arr, left, high);
            return left;
        }
        void quick(int[] arr, int low, int high) 
        {
            if (low < high) 
            {
                int pivot = parition(arr, low, high);
                quick(arr, low, pivot - 1);
                quick(arr, pivot + 1, high);
            }
        }
        public int[] quick(int[] arr) 
        {
            quick(arr, 0, arr.Length - 1);
            return arr;
        }

        void heapify(int[] arr, int n, int nodeIndex) 
        {
            int left = 2*nodeIndex + 1,
                right = 2*nodeIndex + 2,
                largest = nodeIndex;
            
            if (left < n && arr[left] > arr[largest])
                largest = left;
            if (right < n && arr[right] > arr[largest])
                largest = right;
            
            if (largest != nodeIndex)
            {
                swap(arr, largest, nodeIndex);
                heapify(arr, n, largest);
            }
        }
        public int[] heap(int[] arr) 
        {
            for (int i = arr.Length/2 - 1; i >= 0; i--)
                heapify(arr, arr.Length, i);
            for (int i = arr.Length - 1; i >= 0; i--) 
            {
                swap(arr, 0, i);
                heapify(arr, i, 0);
            }
            return arr;
        }

        int[] union(int[] left, int[] right) 
        {
            int[] res = new int[left.Length + right.Length];
            int k = 0, lIndex = 0, rIndex = 0;
            for ( ; lIndex < left.Length && rIndex < right.Length; k++)
                if (left[lIndex] < right[rIndex])
                {
                    res[k] = left[lIndex];
                    lIndex++;
                }
                else 
                {
                    res[k] = right[rIndex];
                    rIndex++;
                }
            for (; lIndex < left.Length; lIndex++, k++)
                res[k] = left[lIndex];
            for (; rIndex < right.Length; rIndex++, k++)
                res[k] = right[rIndex];
            return res;
        }

        public int[] merge(int[] arr)
        {
            if (arr.Length < 2) return arr;
            int mid = arr.Length/2;
            int[] left = new int[mid], right = new int[arr.Length - mid];
            for (int i = 0; i < left.Length; i++)
                left[i] = arr[i];
            for (int i = 0; i < right.Length; i++)
                right[i] = arr[mid + i];
            left = merge(left);
            right = merge(right);

            return union(left, right);
        }
    }
}