#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;  cin >> n;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        int x;  cin >> x;
        m[x]++;
    }

    int count = 0;
    for (auto i : m)
        if (i.second % 2) count++;
    cout << count;
}