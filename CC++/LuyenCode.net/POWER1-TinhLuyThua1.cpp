#include <iostream>

using namespace std;
#define ll long long
int MOD;

ll power(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b % 2) res = res * a % MOD;
        b /= 2;
        a = a * a % MOD;
    }
    return res;
}

ll powerStr(string sa, string sb)
{
    //convert string to long long
    //string a -> a % MOD
    ll a = 0, b = 0;
    for (int i = 0; i < sa.length(); i++)
        a = (a * 10 + (int) sa[i] - '0') % MOD;
    
    
    //reduce b using Fermat's theorem
    //https://www.geeksforgeeks.org/find-abm-where-b-is-very-large/
    //string b -> b & MOD - 1
    for (int i = 0; i < sb.length(); i++)
        b = (b * 10 + (int) sb[i] - '0') % (MOD - 1);
    
    return power(a, b);
}

int main()
{
    string a, b;
    cin >> a >> b >> MOD;
    cout << powerStr(a, b);
}