#include <stdio.h>

int search(int *arr, int n, int k) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == k) {
            while (mid > 0 && arr[mid - 1] == k) mid--;
            return mid + 1;
        }
        if (arr[mid] > k) right = mid - 1;
        else left = mid + 1; 
    }
    return 0;
}

int main() {
    int n, m;   scanf("%d%d", &n, &m);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    
    while (m--) {
        int k;  scanf("%d", &k);
        printf("%d ", search(arr, n, k));
    }
}