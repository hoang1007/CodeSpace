#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

vector<vector<long long>> mul(const vector<vector<long long>> &a, const vector<vector<long long>> &b) {
    const int size = a.size();
    vector<vector<long long>> res(size, vector<long long>(size, 0));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++)
                res[i][j] = (res[i][j] + a[i][k]*b[k][j]) % mod;
        }
    }
    return res;
}

vector<vector<long long>> pow(vector<vector<long long>> a, int n) {
    vector<vector<long long>> res = a;
    n--;

    for (; n; n /= 2, a = mul(a, a))
        if (n % 2) res = mul(res, a);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;  cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<long long>> mat(n, vector<long long>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> mat[i][j];
        
        vector<vector<long long>> res = pow(mat, k);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << res[i][j] << " ";
            cout << endl;
        }
    }   
}