#include <iostream>
using namespace std;

int main()
{
    int n;  cin >> n;
    const int col = 2*n - 1,
            row = n,
            mid = n - 1;
    
    char triangle[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = i; j <= 2*mid - i; j++)
            triangle[i][j] = '*';
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            triangle[i][j] == '*' ? cout << '*' : cout << ' ';
        cout << endl;
    }
}