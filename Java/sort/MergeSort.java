public class MergeSort {
    // to store 2 value a, b in one position in array 
    // use arr[i] = a + b*max   // max is greater than both of a and b
    // => a = arr[i] % max & b = arr[i] / max
    static void merge(int arr[], int begin, int end, int mid, int max) {
        int i = begin,
            j = mid + 1,
            k = begin;
            
        for (; i <= mid && j <= end; k++) {
            if (arr[i] % max < arr[j] % max) {
                arr[k] += (arr[i] % max)*max;
                i++;
            }
            else {
                arr[k] += (arr[j] % max)*max;
                j++;
            }
        }

        for (; i <= mid; i++, k++)
            arr[k] += (arr[i] % max)*max;
        
        for (; j <= end; j++, k++)
            arr[k] += (arr[j] % max)*max;
        
        for (i = begin; i <= end; i++)
            arr[i] /= max;
    }

    static void mergeSort(int arr[], int begin, int end, int max) {
        if (begin < end) {
            int mid = (begin + end)/2;

            mergeSort(arr, begin, mid, max);
            mergeSort(arr, mid + 1, end, max);

            merge(arr, begin, end, mid, max);
        }
    }

    static void mergeSort(int arr[]) {
        int max = arr[0];
            for (int i : arr)
                if (max < i) max = i;

        mergeSort(arr, 0, arr.length - 1, max + 1);
    }
    public static void main(String[] args) {
        int arr[] = {4, 5, 6, 2, 38, 0, 3, 2, 8};
        mergeSort(arr);

        for (int i : arr) {
            System.out.print(i + " ");
        }
    }
}
