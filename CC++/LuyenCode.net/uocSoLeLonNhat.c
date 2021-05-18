#include <stdio.h>
#include <malloc.h>

int* prime;

void sieve(int n) {
    for (int i = 2; i*i <= n; i++) {
        for (int j = i; j*i <= n; j++) {
            int pos = i*j;
            if (j % 2 && prime[pos] < j) prime[pos] = j;
            else if (i % 2 && prime[pos] < i) prime[pos] = i;
        }
    }
}

int main() {
    int t;  scanf("%d", &t);

    int arr[t];
    int max = 0;
    for (int i = 0; i < t; i++) {
        scanf("%d", &arr[i]);
        if (max < arr[i]) max = arr[i];
    }
    
    prime = (int*)malloc((max + 1)*sizeof(int));
    for (int i = 0; i <= max; i++)
        prime[i] = 1;
    
    sieve(max);

    for (int i = 0; i < t; i++)
        printf("%d\n", prime[ arr[i] ]);
}