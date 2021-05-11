#include <iostream>
using namespace std;

int main()
{
    int max = INT16_MIN, min = INT16_MAX,
        sumEven = 0,
        countOdd = 0;
    
    int n;  cin >> n;
    while (n--)
    {
        int x;  cin >> x;
        if (x > max) max = x;
        else if (x < min) min = x;

        if (x % 2) countOdd++;
        else sumEven += x;
    }

    cout << max << endl
        << min << endl
        << sumEven << endl
        << countOdd;
}