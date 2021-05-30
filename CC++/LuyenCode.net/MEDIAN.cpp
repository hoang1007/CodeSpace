#include <stdio.h>
#define null -1

int main() {
    int n, m;   scanf("%d%d", &n, &m);
    
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    int left = (n - 1)/2, right = n/2;
    
    while (m--) {
        if (left == right) {
            printf("%d ", arr[left]);
            left--, right++;
            n--;
            m--;
        }

        if (n % 2) {
            printf("%d ", arr[right]);
            right++;
        }
        else {
            printf("%d ", arr[left]);
            left--;
        }
        n--;
    }
}