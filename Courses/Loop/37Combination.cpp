#include <iostream>
using namespace std;

long long C(int n, int k)
{
    if (k == 0 || k == n) return 1;
    if (k == 1 || k == n - 1) return n;

    long long a = 1;  // n! / k!
    long long b = 1;  // (n - k)!

    for (int i = k + 1; i <= n; i++)
        a *= i;
    for (int i = 2; i <= n - k; i++)
        b *= i;
    return a / b;
}

int main()
{
    int n, k;
    while (1)
    {
        cin >> n >> k;
        if (n == -1 && k == -1) break;
        cout << C(n, k) << endl;
    }
}