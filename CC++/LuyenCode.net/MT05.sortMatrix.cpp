#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    int m, n, k;
    cin >> m >> n >> k;
    int arr[n][m];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[j][i];
    
    sort(arr[k - 1], arr[k - 1] + m);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << arr[j][i] << " ";
        cout << endl;
    }
}