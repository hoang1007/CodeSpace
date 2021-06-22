#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int left, int right) {
    int pivot = arr[right],
        i = left,
        j = right - 1;
    while (true) {
        while (i <= j && arr[i] < pivot) i++;
        while (i <= j && arr[j] > pivot) j--;

        if (i >= j) break;
        swap(arr[i], arr[j]);
        i++, j--;
    }
    swap(arr[i], arr[right]);
    return i;
}

void quicksort(int *arr, int left, int right) {
    if (left < right) {
        int pivot = partition(arr, left, right);
        quicksort(arr, left, pivot - 1);
        quicksort(arr, pivot + 1, right);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;  cin >> n;
    int *arr = new int[n];
    int *copy = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        copy[i] = arr[i];
    }
    
    quicksort(copy, 0, n - 1);


    unordered_map<int, int> m;
    for (int i = 0, k = 0; i < n; i++) {
        if (m[copy[i]] == 0) m[copy[i]] = k++;
    }
    
    for (int i = 0; i < n; i++)
        cout << m[arr[i]] << " ";
}