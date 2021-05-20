#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int low, int high) {
    int pivot = arr[high],
        left = low,
        right = high - 1;
    
    while (1) {
        while (left <= right && arr[left] < pivot)  left++;
        while (left <= right && arr[right] > pivot) right--;

        if (left >= right) break;
        swap(&arr[left], &arr[right]);
        left++; right--;
    }

    swap(&arr[left], &arr[high]);
    return left;
}

void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);

        quickSort(arr, pivot + 1, high);
        quickSort(arr, low, pivot - 1);
    }
}

int main() {
    int n;  scanf("%d", &n);
    
    int odd[n/2 + 1], even[n/2 + 1];

    int oddSize = 0, evenSize = 0;
    
    for (int i = 0; i < n; i++)
        if (i % 2) {
            scanf("%d", &odd[oddSize]);
            oddSize++;
        }
        else {
            scanf("%d", &even[evenSize]);
            evenSize++;
        }
    
    quickSort(odd, 0, oddSize - 1);
    quickSort(even, 0, evenSize - 1);

    for (int i = 0; ; ) {
        if (i < evenSize) {
            printf("%d ", even[i]);
            i++;
        }
        if (oddSize > 0) {
            printf("%d ", odd[oddSize - 1]);
            oddSize--;
        }
        if (i == evenSize && oddSize == 0) break;
    }
}