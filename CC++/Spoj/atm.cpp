#include <iostream>
using namespace std;

#define INF -1

int solve(int arr[], int n, int s) {
    if (s == 0) return 0;

    int count = INF;
    for (int i = 0; i < n; i++)
        if (arr[i] <= s) {
            int k = solve(arr, n, s - arr[i]);
            if (k != INF && (k + 1 < count || count == INF))
                count = k + 1;
        }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    int t;  cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        int arr[n];
        for (int &item : arr)
            cin >> item;
        cout << solve(arr, n, s) << endl;
    }
}