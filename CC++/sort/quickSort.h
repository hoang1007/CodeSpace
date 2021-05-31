#pragma once

int partition(int arr[], int low, int high) {
    int left = low,
        right = high - 1,
        pivot = arr[high];
    
    while (true) {
        while (left <= right && arr[left] < pivot) left++;
        while (left <= right && arr[right] > pivot) right--;
        if (left >= right) break;
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++, right--;
    }
    int temp = arr[left];
    arr[left] = arr[high];
    arr[high] = temp;

    return left;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void quickSort(int arr[], int n) {
    quickSort(arr, 0, n - 1);
}