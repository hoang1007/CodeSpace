#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high],
        left = low,
        right = high - 1;
    
    while (true) {
        while (left <= right && arr[left] > pivot) left++;
        while (left <= right && arr[right] < pivot) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++; right--;
    }

    swap(arr[left], arr[high]);
    return left;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    quickSort(arr, 0, sizeof(arr)/sizeof(*arr) - 1);

    for (int i : arr)
        cout << i << " ";
}