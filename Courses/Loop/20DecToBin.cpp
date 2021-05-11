#include <iostream>
using namespace std;

void DecToBin(long long n)
{
    if (n == 0) return ;

    DecToBin(n / 2);
    cout << n % 2;
}

int main()
{
    long long n;  cin >> n;
    DecToBin(n);
}