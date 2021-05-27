#include <stdio.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void reverse(int arr[], int begin, int end) {
    while (begin < end) {
        swap(arr, begin, end);
        begin++, end--;
    }
}

void print(int arr[], int n) {
    for (int i = 1; i < n; i++)
        printf("%d ", arr[i]);
    printf("%d\n", arr[n]);
}

int main() {
    int n;  scanf("%d", &n);
    int arr[n + 1];
    for (int i = 0; i <= n; i++)
        arr[i] = i;
    print(arr, n);

    while (1) {
        int low = n - 1;
        for (; arr[low] > arr[low + 1]; low--);
        if (low == 0) break;

        int high = n;
        for (; arr[high] < arr[low]; high--);
        
        swap(arr, low, high);
        reverse(arr, low + 1, n);
        print(arr, n);
    }
}