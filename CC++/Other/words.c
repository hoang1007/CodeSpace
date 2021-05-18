#include <stdio.h>

int pow(int n) {
    int res = 1;
    int a = 10;
    for (; n; a *= a, n /= 2)
        if (n % 2) res *= a;
    return res;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", 9*pow( (n - 1)/2 ));
    }
}