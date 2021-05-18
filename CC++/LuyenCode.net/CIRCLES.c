#include <stdio.h>

long long pow(int n) {
    long long a = 2;
    long long res = 1;
    for (; n; n /= 2, a *= a)
        if (n % 2) res *= a;
    return res;
}
int main() {
    int n;	scanf("%d", &n);
    printf("%lld", pow(n));
}