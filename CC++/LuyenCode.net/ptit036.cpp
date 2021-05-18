#include <map>
#include <iostream>
#include <cstdio>
using namespace std;

const int mod = 30;

unsigned long long pow(int n) {
    unsigned long long res = 1, a = 2;
    for (; n; n /= 2, a *= a)
        if (n % 2) res *= a;
    return res;
}

int main() {
    map<int, int> arr;
    int n;  scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;  scanf("%d", &x);
        if (!arr[x]) arr[x] = i + 1;
    }

    int m;  scanf("%d", &m);
    int sum = 0;
    while (m--) {
        int x;  scanf("%d", &x);
        int k = arr[x];
        if (k) sum = (sum + k) % mod;
        else sum--;
    }

    printf("%llu", pow(sum));
}