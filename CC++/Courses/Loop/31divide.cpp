#include <iostream>
using namespace std;

int countNumber(int n)
{
    int count = 0;
    for (int i = n; i; i /= 10)
        if (i % 10 != 0 && n % (i % 10) == 0)
            count++;
    return count;
}

int main()
{
    int t;  cin >> t;
    while (t--)
    {
        int n;  cin >> n;
        cout << countNumber(n) << endl;
    }
}