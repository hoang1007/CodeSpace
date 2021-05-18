#include <stdio.h>

int binarySearch(int* arr, int n, int k) {
    int left = 0,
        right = n - 1;
    
    while (left <= right) {
        int mid = (left + right)/2;

        if (arr[mid] == k) return 1;
        if (arr[mid] > k) right--;
        else left++;
    }
    return 0;
}

int main() {
    int n1, n2; scanf("%d%d", &n1, &n2);
    int arr1[n1];

    for (int i = 0; i < n1; i++)
        scanf("%d", &arr1[i]);
    
    while (n2--) {
        int n;  scanf("%d", &n);
        printf("%d", binarySearch(arr1, n1, n));
    }
}