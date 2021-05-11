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
    for (int i = n; i; i--)
        printRow(n - i, i);
}