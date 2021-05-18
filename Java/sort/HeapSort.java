public class HeapSort {
    private static void swap(int arr[], int i, int j) {
        arr[i] += arr[j];
        arr[j] = arr[i] - arr[j];
        arr[i] -= arr[j];
    }

    public static void heapify(int arr[], int size, int rootIndex) {
        int largest = rootIndex, left = 2 * rootIndex + 1, right = 2 * rootIndex + 2;

        if (left < size && arr[left] > arr[largest])
            largest = left;
        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != rootIndex) {
            swap(arr, largest, rootIndex);

            heapify(arr, size, largest);
        }
    }

    public static void heapSort(int arr[]) {
        for (int i = arr.length / 2 - 1; i >= 0; i--)
            heapify(arr, arr.length, i);

        for (int i = arr.length - 1; i > 0; i--) {
            swap(arr, i, 0);
            heapify(arr, i, 0);
        }
    }

    public static void main(String[] args) {
        int arr[] = {3, 1, 5, 4, 7, 8, 4, 8};

        heapSort(arr);

        for (int i : arr)
            System.out.print(i + " ");
    }
}
