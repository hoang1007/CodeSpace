#include <iostream>
using namespace std;

long long* fibo = nullptr;

char find(long long n, long long k) {
    if (k == 1 && n == 1) return 'A';
    if (k == 1 && n == 2) return 'B';

    if (k <= fibo[n - 2]) return find(n - 2, k);
    return find(n - 1, k - fibo[n - 2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    int t;  cin >> t;
    long long query[t][2];
    long long max = 0;
    for (int i = 0; i < t; i++) {
        cin >> query[i][0] >> query[i][1];
        if (max < query[i][0]) max = query[i][0];
    }

    fibo = new long long[max + 1];
    fibo[0] = 0;
    fibo[1] = fibo[2] = 1;
    for (int i = 3; i <= max; i++)
        fibo[i] = fibo[i - 2] + fibo[i - 1];
    
    for (int i = 0; i < t; i++)
        cout << find(query[i][0], query[i][1]) << endl;
}