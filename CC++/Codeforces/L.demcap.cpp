#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k;   cin >> n >> k;
    int arr[n];

    for (auto &i : arr)
        cin >> i;

    sort(arr, arr + n);

    int count = 0;
    for (int i = 0; i < n; i++) {
        int val = arr[i] + k;
        auto pos = lower_bound(arr + i + 1, arr + n, val);
        if (pos != arr + n) count += pos - (arr + i);
        else count += n - i - 1;
        if (*pos == val) count--;
    }

    cout << count;
}