#include <bits/stdc++.h>

using namespace std;

int ucln(int a, int b) {
    if (b == 0) return a;
    return ucln(b, a % b);
}

int bcnn(int a, int b) {
    if (a == 0 || b == 0) return 0;
    a = a > 0 ? a : -a;
    b = b > 0 ? b : -b;

    return a*b/ucln(a, b);
}

int main() {
    int a, b;   cin >> a >> b;
    cout << bcnn(a, b);
}