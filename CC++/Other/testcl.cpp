#include <bits/stdc++.h>
using namespace std;
long long pow2(long long n)
{
    if (n < 2)
        return n + 1;
    long long x = pow2(n / 2);
    if (n % 2 == 0)
        return x * x;
    return 2 * x * x;
}

int solve(long long n)
{
    long long x = floor(log2(n)) + 1;
    long long mid = pow2(x) / 2;
    while (x)
    {
        if (x == 1)
        {
            cout << 1;
            break;
        }
        if (mid == n)
        {
            cout << x;
            break;
        }
        if (n > mid)
        {
            n = 2 * mid - n;
        }
        x--;
        mid /= 2;
    }
    cout << " ";
}

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << solve(a[i]);
    }
}