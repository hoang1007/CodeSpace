#include <iostream>
#include <math.h>
using namespace std;

typedef long long ll;

ll foo(ll mid, ll k) {
    if (k == mid) return 1;
    else if (k > mid) return foo(mid/2, 2*mid - k);
    return foo(mid/2, k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    ll n; cin >> n;
    ll arr[n];
    ll max = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (max < arr[i]) max = arr[i];
    }
    ll p = sqrt(max + 1) + 1;
    for (int i = 0; i < n; i++)
        cout << foo(p, arr[i]) << " ";
}