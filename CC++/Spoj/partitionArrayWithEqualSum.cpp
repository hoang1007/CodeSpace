#include <iostream>
#include <vector>
using namespace std;

int gSum;

int solve(vector<int> arr, vector<bool> picked, int i, int k, int sum)
{
    if (k == 0) return sum == gSum ? 1 : 0;

    if (sum < 0) return 0;
    if (sum == 0)
        return solve(arr, picked, 0, k - 1, gSum);
    
    for (; i < arr.size(); i++)
        if (!picked[i]) {
            picked[i] = true;
            if (solve(arr, picked, i, k, sum - arr[i]))
                return 1;
            picked[i] = false;
        }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        gSum = 0;
        int n, k;   cin >> n >> k;
        vector<int> arr;
        int p = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x) arr.push_back(x);
            else p++;
        }
        
        for (int i = 0; i < arr.size(); i++)
            gSum += arr[i];

        if (gSum % k == 0)
        {
            gSum /= k;
            vector<bool> picked(arr.size(), false);
            cout << solve(arr, picked, 0, k, gSum) << endl;
        }
        else cout << 0 << endl;
    }
}