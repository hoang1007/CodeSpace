#include <iostream>
using namespace std;

int compare(string a, string b) {
    int minSize = a.length() <= b.length() ? a.length() : b.length();

    for (int i = 0; i < minSize; i++) {
        if (a[i] < b[i]) return -1;
        if (a[i] > b[i]) return 1;
    }

    if (a.length() > b.length()) return 1;
    if (a.length() < b.length()) return -1;
    return 0;
}

int partition(string arr[], int low, int high) {
    string pivot = arr[high];
    int left = low,
        right = high - 1;
    
    while (true) {
        while (left <= right && compare(arr[left], pivot) == -1) left++;
        while (left <= right && compare(arr[right], pivot) == 1) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++; right--;
    }

    swap(arr[left], arr[high]);
    return left;
}

void quickSort(string arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main() {
    string arr[] = {"1", "5", "4", "3", "9", "7", "2", "6", "8"};
    int size = sizeof(arr)/sizeof(*arr) - 1;
    quickSort(arr, 0, size);

    for (int i = size; i >= 0; i--)
        cout << arr[i];

}