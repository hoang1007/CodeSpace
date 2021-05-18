#include <stdio.h>

int lastDigitPower(int a, int b) {
    int res = 1;
    for (; b; b /= 2, a = a*a % 10)
        if (b % 2) res *= a;
    return res % 10;
}

int main() {
    int a, n;   scanf("%d %d", &a, &n);
    printf("%d", lastDigitPower(a, n));
}