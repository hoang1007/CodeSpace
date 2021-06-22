#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve(vector<int> arr, int i, int k) {
    cout << arr[i] << " ";
    
    int left = i - 1, right = i + 1;
    while (k--) {
        int leftDist = arr[i] - arr[left],
            rightDist = arr[right] - arr[i];
        
        if (left >= 0 && leftDist < rightDist) {
            cout << arr[left] << " ";
            left--;
        }
        else if (right < arr.size() && rightDist >= leftDist) {
            cout << arr[right] << " ";
            right++;
        }
    }
}

int binarySearch(const vector<int> &arr, int x) {
    int left = 0, right = arr.size() - 1;
    int mindist = 1e9 +10;
    int res = -1;

    while (left <= right) {
        int mid = (left + right)/2;

        if (x == arr[mid]) return mid;
        else if (x < arr[mid]) {
            int dist = arr[mid] - x;
            if (mindist > dist) {
                mindist = dist;
                res = mid;
            }

            right = mid - 1;
        }
        else {
            int dist = x - arr[mid];
            if (mindist > dist) {
                mindist = dist;
                res = mid;
            }

            left = mid + 1;
        }
    }

    return res;
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;
    
    sort(arr.begin(), arr.end());

    while (q--) {
        int x, k;
        cin >> x >> k;
        
        solve(arr, binarySearch(arr, x), k - 1);
    }
}