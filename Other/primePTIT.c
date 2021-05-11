#include <stdio.h>

int arr[10];

int check(int n)
{
    int n_copy = n;
    int sum = 0;
    while (n_copy)
    {
        int c = n_copy % 10;
        if (!arr[c]) return 0;
        n_copy /= 10;
        sum += c;
    }

    for (int i = 2; i * i <= sum; i++)
        if (sum % i == 0) return 0;
    
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int countPrime(int l, int r)
{
    int count = 0;
    for (; l <= r; l++)
        if (check(l)) count++;
    return count;
}
int main()
{
    for (int i = 0; i < 10; i++)
        arr[i] = 0;
    arr[2] = arr[3] = arr[5] = arr[7] = 1;

    int t;
    scanf("%d", &t);
    while (t--)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", countPrime(l, r));
    }
}