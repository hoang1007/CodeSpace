#include <stdio.h>

#define LIMIT 1e9

int count(int n) {
    int count2 = 0, count5 = 0;
    for (; n % 2 == 0; n /= 2, count2++);
    for (; n % 5 == 0; n /= 5, count5++);
    
    if (n == 1) return count2 > count5 ? count2 : count5;
    return -1;
}

int main() {
    int n;  scanf("%d", &n);
    
    int res = count(n);
    res == -1 ? printf("NO") : printf("%d", res);
}