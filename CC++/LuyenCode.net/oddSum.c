#include <stdio.h>

int main() {
    int l, r;
    scanf("%d%d", &l, &r);
    if (l % 2 == 0) l++;
    if (r % 2 == 0) r--;
    
    unsigned long long oddSum = (unsigned long long) ((r - l)/2 + 1)*(l + r)/2;
    printf("%llu", oddSum);
}