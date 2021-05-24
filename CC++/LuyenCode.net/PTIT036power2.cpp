#include <cstdio>
#include <vector>
#include <math.h>
using namespace std;

#define mod 30

int search(const vector<int> &arr, int k) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == k) {
            while (mid > 0 && arr[mid - 1] == k) mid--;
            return mid + 1;
        }
        if (arr[mid] > k) right = mid - 1;
        else left = mid + 1; 
    }
    return -1;
}

int main() {
    int n;  scanf("%d", &n);
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    int m;  scanf("%d", &m);
    int x = 0;
    for (int i = 0; i < m; i++) {
        int k;  scanf("%d", &k);
        x = (x + search(arr, k)) % mod;
    }

    printf("%.lf", pow(2, x));
}