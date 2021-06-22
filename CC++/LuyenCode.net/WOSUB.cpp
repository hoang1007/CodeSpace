#include <iostream>
using namespace std;

int binarySearch(int arr[], int i, int n, int value) {
    int left = i + 1, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (value == arr[mid]) return mid;
        else if (value < arr[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;  cin >> n;
    int arr[n];
    for (auto &i : arr)
        cin >> i;
    for (int i = 0; i < n - 1; i++)
        arr[i + 1] += arr[i];
    
    int value; cin >> value;
    int max = -1;
    for (int i = 0; i < n && arr[i] <= arr[n - 1] - value; i++) {
        int k = binarySearch(arr, i, n, arr[i] + value);
        if (k == -1) continue;
        if (max < k - i) max = k - i;
    }

    cout << max;
}