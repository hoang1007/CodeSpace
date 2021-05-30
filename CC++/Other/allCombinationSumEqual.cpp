#include <iostream>
using namespace std;

int main() {
    int n, k, s;
    n = 9, k = 3, s = 22;

    int sum = s;
    int res[k];
    bool fixed[k] = {false};
    for (int i = 0; i < k; i++) {
        res[i] = sum/(k - i);
        sum -= res[i];
    }
    
    int left = 0, right = k - 1;
    
    while (left < right) {
        while (res[right] == n - (k - 1 - right))
            right--;
        while (res[left] <= left)
            left++;
        
        if (left >= right) break;
        res[right]++;
        res[left]--;

        for (int i = 0; i < k; i++)
        cout << res[i] << " ";
        cout << endl;
    }
}