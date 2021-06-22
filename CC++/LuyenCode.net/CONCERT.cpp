#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;  cin >> n;
    int arr[n];
    for (auto &i : arr)
        cin >> i;
    int count = 0;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i + 1] > arr[i]) {
            count++;
            continue;
        }
        int j = i + 1;
        for (; j < n && arr[j] <= arr[i]; j++, count++);
        if (j < n) count++;
    }

    cout << count;
}