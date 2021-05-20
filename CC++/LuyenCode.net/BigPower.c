#include <stdio.h>

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

ll powerStr(char sa[], char sb[])
{
    //convert string to long long
    //string a -> a % MOD
    ll a = 0, b = 0;
    for (int i = 0; sa[i] != '\0'; i++)
        a = (a * 10 + (int) sa[i] - '0') % MOD;
    
    
    //reduce b using Fermat's theorem
    //https://www.geeksforgeeks.org/find-abm-where-b-is-very-large/
    //string b -> b & MOD - 1
    for (int i = 0; sb[i] != '\0'; i++)
        b = (b * 10 + (int) sb[i] - '0') % (MOD - 1);
    
    return power(a, b);
}

int main()
{
    char a[100001], b[100001];
    scanf("%s%s%d", a, b, &MOD);
    
    printf("%lld", powerStr(a, b));
}