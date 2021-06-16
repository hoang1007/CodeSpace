#include <iostream>
using namespace std;

long long solve(long long m, long long n) {
    long long arr[m][n];

    // for (int i = 0; i < m; i++)
    //     for (int j = 0; j < n; j++)
    //         cin >> arr[i][j];

    for (int i = 0; i < m; i++)
        arr[i][0] = 1;
    for (int i = 0; i < n; i++)
        arr[0][i] = 1;
    
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
    return arr[m - 1][n - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;  cin >> t;
    while (t--) {
        long long m, n;   cin >> m >> n;
        cout << solve(m, n) << endl;
    }
}