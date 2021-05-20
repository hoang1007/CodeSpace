#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;  scanf("%d", &t);

    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);

        int arr[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        sort(arr, arr + n);

        vector<vector<int>> low, high;
        int pivot = k/2;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= pivot) {
                if (!low.empty() && low.back()[0] == arr[i])
                    low.back()[1]++;
                else low.push_back({arr[i], 1});
            }
            else {
                if (!high.empty() && high.back()[0] == arr[i])
                    high.back()[1]++;
                else high.push_back({arr[i], 1});
            }
        }
        
        int left = 0, right = high.size() - 1;
        int count = 0;

        if (low.back()[0]*2 == k) {
            int freq = low.back()[1];
            int factorial = 1;
            for (int i = 2; i < freq; i++)
                factorial *= i;
            count += factorial;
            low.pop_back();
        }

        while (left < low.size() && right >= 0) {
            int sum = low[left][0] + high[right][0];
            if (sum == k) {
                count += low[left][1]*high[right][1];
                left++; right--;
            }
            else if (sum > k) right--;
            else left++;
        }

        printf("%d\n", count);
    }
}