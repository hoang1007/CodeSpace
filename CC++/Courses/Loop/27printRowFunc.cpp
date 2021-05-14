#include <iostream>
using namespace std;

void printRow(int m, int n)
{
    for (; m; m--)  cout << ' ';
    for (; n; n--)  cout << '*';
    cout << endl;
}

int main()
{
    int n;  cin >> n;
    for (int i = 1; i <= n; i++)
        printRow(n - i, 2*i - 1);
}