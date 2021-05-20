#include <stdio.h>

int binarySearch(long long* arr, int n, long long k) {
    int left = 0, right = n;
    while (left <= right) {
        int mid = (left + right)/2;
        if (arr[mid] == k) return mid;
        if (arr[mid] < k) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int t;  scanf("%d", &t);
    while (t--) {
        int n;
        long long k;
        scanf("%d %lld", &n, &k);
        long long arr[n + 2];
        arr[0] = 0;
        for (int i = 1; i <= n; i++) 
            scanf("%lld", &arr[i]);

        // calculate prefix sum
        for (int i = 2; i <= n; i++)
            arr[i] += arr[i - 1];
        
        // if sum arr[i] -> arr[j] = k
        // with prefix sum: arr[j] - arr[i] = k
        // use binary search to find i and j
        int found = 0;
        for (int i = 0; i < n; i++) {
            int j = binarySearch(arr, n, arr[i] + k);
            if (j != -1) {
                found = 1;  // found
                for (int a = j; a >= i; a--)
                    arr[a] -= arr[a - 1];
                for (i++; i <= j; i++)
                    printf("%lld ", arr[i]);
                printf("\n");
                break;
            }
        }
        if (!found) printf("NOT FOUND\n");
    }
}
