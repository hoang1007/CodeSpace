#include <iostream>
using namespace std;

int main() {
    int n;  cin >> n;
    int arr[n];
    for (auto &i : arr)
        cin >> i;
    
    int left[n] = {0}, right[n] = {0};
    
    for (int i = 1; i < n; i++)
        if (arr[i] > arr[i - 1])
            left[i] += left[ i -1] + 1;

    for (int i = n - 2; i >= 0; i--)
        if (arr[i] > arr[i + 1])
            right[i] += right[i + 1] + 1;

    for (int i = 0; i < n; i++)
        cout << left[i] + right[i] + 1 << " ";
}