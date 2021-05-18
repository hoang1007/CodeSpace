#include <iostream>
using namespace std;

int partition(int arr[], int k, int left, int right) {
    while (left <= right) {
        while (left <= right && arr[left] < k) left++;
        while (left <= right && arr[right] > k) right--;
        if (left >= right) break;
        if (arr[left] + arr[right] == k) cout << arr[left] << " " << arr[right] << endl;
        swap(arr[left], arr[right]);
    }
    return left;
}
void search (int arr[], int k, int left, int right) {
    if (left < right) {
        int pivot = partition(arr, k, left, right);
        search(arr, k, left, pivot - 1);
        search(arr, k, pivot + 1, right);
    }
}

int main() {
    int arr[] = {1, 10, 5, 6, 4, 1};
    int k = 11;

    int pivot = k / 2;

    partition(arr, pivot, 0, sizeof(arr) / sizeof(*arr) - 1);
}