#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int m, n, i;
    cin >> m >> n >> i;
    int arr[m][n];
    for (auto &i : arr)
        for (auto &j : i)
            cin >> j;
    sort(arr[i - 1], arr[i - 1] + n);

    for (auto &i : arr) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}