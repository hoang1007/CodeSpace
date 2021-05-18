#include <stdio.h>

int main() {
    unsigned long long n, a, b;
    scanf("%llu %llu %llu", &n, &a, &b);

    if (n % a && n % b)
        printf("Khong chia het cho so nao ca.");
    else if (n % b)
        printf("Chi chia het cho %llu,", a);
    else if (n % a)
        printf("Chi chia het cho %llu.", b);
    else printf("Co, tat ca!");
}