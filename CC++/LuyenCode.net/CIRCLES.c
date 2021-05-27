#include <stdio.h>

int main() {
    int n;	scanf("%d", &n);
    printf("%lld", (long long) n*(n - 1) + 2);
}