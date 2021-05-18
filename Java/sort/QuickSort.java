class QuickSort {
    static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j < high; j++)
            if (arr[j] < pivot) {
                i++;
                swap(arr, i, j);
            }

        swap(arr, i + 1, high);
        return i + 1;
    }

    static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);

            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    static void quickSort(int arr[]) {
        quickSort(arr, 0, arr.length - 1);
    }
    // Driver Code
    public static void main(String[] args) {
        int[] arr = { 10, 7, 8, 9, 1, 5, 6, 3, 8, 9, 34, 5 };

        quickSort(arr);
        
        for (int i : arr)
            System.out.print(i + " ");
    }
}