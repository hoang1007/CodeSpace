#include <iostream>
#include <cstdio>
using namespace std;

long long decimal(string bin) {
    long long res = 0,
                a = 1;
    
    for (int i = bin.length() - 1; i >= 0; i--, a *= 2)
        if (bin[i] == '1') res += a;
    return res;
}

int main() {
    int t;  scanf("%d", &t);
    while (t--) {
        string bin;
        cin >> bin;
        printf("%lld\n", decimal(bin));
    }
}