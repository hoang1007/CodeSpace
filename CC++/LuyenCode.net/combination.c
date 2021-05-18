#include <stdio.h>

long long factorial(int left, int right) {
    long long res = 1;
    for (; left <= right; left++)
        res *= left;
    return res;
}

long long C(int k, int n) {
    if (k == 0 || k == n) return 1;
    if (k == 1 || k == n - 1) return n;

    long long a, b;
    if (k < n/2) {
        a = factorial(n - k + 1, n);
        b = factorial(2, k);
    }
    else {
        a = factorial(k + 1, n);
        b = factorial(2, n - k);
    }
    return a / b;
}

int main() {
    int n, k;
    scanf("%d%d", &k, &n);
    printf("%lld", C(k, n));
}