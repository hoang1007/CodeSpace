public class BubbleSort {
    public static void bubbleSort(int arr[]) {
        for (int i = 0; i < arr.length - 1; i++)
            for (int j = i + 1; j < arr.length; j++)
                if (arr[i] > arr[j])
                {
                    arr[i] = arr[i] + arr[j];
                    arr[j] = arr[i] - arr[j];
                    arr[i] -= arr[j];
                }
    }
    public static void main(String[] args) {
        int arr[] = {4, 3, 6, 2, 8, 9};
        bubbleSort(arr);

        for (int i = 0; i < arr.length; i++)
            System.out.print(arr[i] + " ");
    }
}
