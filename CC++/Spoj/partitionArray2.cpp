#include <iostream>
#include <vector>
using namespace std;

bool find(vector<int> arr, vector<bool> &picked, int sum, int i) {
    if (sum == 0) return true;
    if (sum < 0) return false;

    for (; i < arr.size(); i++)
        if (!picked[i]) {
            picked[i] = true;
            if (find(arr, picked, sum - arr[i], i)) return true;
            picked[i] = false;
        }

    return false;
}

int solve(vector<int> arr, vector<bool> &picked, int sum, int k) {
    bool f = true;
    while (k--)
        f &= find(arr, picked, sum, 0);
    return (int) f;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;  cin >> t;
    while (t--) {
        int n, k;   cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
            sum += arr[i];
        
        if (sum % k == 0) {
            sum /= k;
            vector<bool> picked(arr.size());

            cout << solve(arr, picked, sum, k) << endl;
        }
        else cout << 0 << endl;
    }
}