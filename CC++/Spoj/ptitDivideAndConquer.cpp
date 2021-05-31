#include <iostream>
using namespace std;

long pow2(int n) {
    if (n == 0) return 1;
    long a = 2, res = 1;
    for (; n; n /= 2, a *= a)
        if (n % 2) res *= a;
    return res;
}

int foo(int n, long k) {
    long mid = pow2(n - 1);
    if (k == mid) return n;
    else if (k > mid) return foo(n - 1, k - mid);
    return foo(n - 1, k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;  cin >> t;
    while (t--) {
        int n;
        long k;
        cin >> n >> k;
        cout << foo(n, k) << endl;
    }
}