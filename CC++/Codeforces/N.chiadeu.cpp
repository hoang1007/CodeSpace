#include <iostream>
using namespace std;

int gSum = 0;

int Count(int arr[], int i, int n, int k) {
    if (k == 0) return 1;
    int sum = 0;
    int count = 0;
    for ( ; i < n; i++) {
        sum += arr[i];
        if (sum == gSum)
            count += Count(arr, i + 1, n, k - 1);
    }
    return count;
}

int main() {
    int n, k;   cin >> n >> k;
    int arr[n];

    for (int &i : arr)
        cin >> i;
    
    for (int i : arr)
        gSum += i;
    
    if (gSum % k == 0) {
        gSum /= k;
        cout << Count(arr, 0, n, k);
    }
    else cout << 0;
}