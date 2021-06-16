#include <bits/stdc++.h>
using namespace std;

#define null 0

vector<bool> findPrime(int n) {
    vector<bool> mark(n + 1, true);
    mark[0] = mark[1] = false;

    for (int i = 2; i*i <= n; i++)
        for (int j = i*i; j <= n; j += i)
            mark[j] = false;
    return mark;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;  cin >> n;
    int arr[n + 1];
    int max = 0;
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    
    sort(arr, arr + n);

    vector<int> distinct;

    for (int i = 0; i < n; i++)
        if (arr[i] != arr[i + 1])
            distinct.push_back(arr[i]);
    
    vector<bool> mark = findPrime(max);
    for (auto item : distinct)
        if (mark[item]) cout << item << " ";
}