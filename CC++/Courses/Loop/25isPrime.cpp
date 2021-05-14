#include <iostream>
using namespace std;

string isPrime(int n)
{
    if (n == 1 || n == 0) return "no";
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return "no";
    return "yes";
}

int main()
{
    int n;  cin >> n;
    cout << isPrime(n);
}