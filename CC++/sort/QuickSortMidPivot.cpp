#include <iostream>
using namespace std;

int partition(int arr[], int left, int right) {
    int pivot = (left + right) / 2;

    while (left < right) {
        while (left <= right && arr[left] < arr[pivot]) left++;
        while (left <= right && arr[right] > arr[pivot]) right--;

        if (left >= right) break;
        swap(arr[left], arr[right]);
    }
}

void quickSort(int arr[], int left, int right) {

}

int main() {
    int arr[] = {3, 2, 5, 7, 4, 8, 10, 5};

    quickSort(arr, 0, sizeof(arr) / sizeof(*arr) - 1);

    for (int i : arr)
        cout << i << " ";
}