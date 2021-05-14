#include <iostream>
using namespace std;

int bcm(int a, int b)
{
    if (b == 0) return a;
    return bcm(b, a % b);
}

int lcm(int a, int b)
{
    if (a == 0 || b == 0) return 0;
    return a*b / bcm(a, b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << lcm(a, b);
}