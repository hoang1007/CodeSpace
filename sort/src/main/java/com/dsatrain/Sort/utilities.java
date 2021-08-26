package com.dsatrain.Sort;

public class utilities {
    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void heapify(int arr[], int n, int i) {
        int left = 2 * i + 1, 
            right = 2 * i + 2, 
            largest = i;
        
        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;
        
        if (largest != i) {
            swap(arr, i, largest);
            heapify(arr, n, largest);
        }
    }

    public static int partition(int[] arr, int low, int high) {
        int pivot = arr[high], 
            left = low,
            right = high - 1;
        
        while (left < right) {
            while (left <= right && arr[left] < pivot) left++;
            while (left <= right && arr[right] > pivot) right--;

            if (left >= right) break;
            swap(arr, left, right);
            left++; right--;
        }

        swap(arr, left, high);
        return left;
    }

    public static int[] merge(int[] a, int b[]) {
        int[] res = new int[a.length + b.length];
        int aItr = 0, bItr = 0, resItr = 0;

        for (; aItr < a.length && bItr < b.length; resItr++) {
            if (a[aItr] < b[bItr]) {
                res[resItr] = a[aItr++];
            }
            else {
                res[resItr] = b[bItr++];
            }
        }

        for (; aItr < a.length; resItr++, aItr++)
            res[resItr] = a[aItr];
        
        for (; bItr < b.length; resItr++, bItr++)
            res[resItr] = b[bItr];
        
        return res;
    }
}
