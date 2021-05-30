#include <iostream>
#define limit n - (k - 1)
using namespace std;

int avrg;

int Count(int prevNum, int i, int k, int leftSum) {
    if (i == k) {
        if (leftSum == 0) return 1;
        return 0;
    }

    if (leftSum == 0) return 0;

    int a = 0;

    if (i > k/2 + 1) {
        for (int p = min(avrg, prevNum - 1); p >= 0; p--)
            a += Count(p, i + 1, k, leftSum - p);
    }
    else 
        for (int p = prevNum - 1; p >= 0; p--)
            a += Count(p, i + 1, k, leftSum - p);
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, k, s;
    while (cin >> n >> k >> s) {
        if (n == 0 && k == 0 && s == 0) break;
        int res = 0;
        avrg = s/k;
        cout << Count(n + 1, 0, k, s) << endl;
    }
}