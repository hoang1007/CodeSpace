#include <iostream>
#include <vector>
using namespace std;


int solve(vector<int> arr, int i, int k) {
    if (k == 0 && i < arr.size()) return arr[i];

    if (i >= arr.size()) return 0;

    int s1 = solve(arr, i + 1, k - 1) + arr[i],
        s2 = solve(arr, i + 2, k - 1) + arr[i];
    return s1 < s2 ? s2 : s1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    
    int s1 = solve(arr, 0, k);
    cout << s1;
}