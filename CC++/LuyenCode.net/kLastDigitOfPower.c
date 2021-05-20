#include <stdio.h>
#include <math.h>
#define ll long long

ll power(ll a, ll b, ll k) {
    ll res = 1;
    a %= k;

    for (; b; b /= 2, a = a*a % k)
        if (b % 2) res = res*a % k;
    return res;
}

int numberOfDigits(int n) {
    int count = 0;
    for (; n; n /= 10, count++);
    return count;
}

void kLastDigit(int m, int n, int k) {
    int temp = pow(10, k);

    temp = power(m, n, temp);

    for (int i = 0; i < k - numberOfDigits(temp); i++)
        printf("0");
    if (temp) printf("%d", temp);
}

int main() {
    int m, n, k;
    scanf("%d%d%d", &k, &m, &n);
    kLastDigit(m, n, k);
}