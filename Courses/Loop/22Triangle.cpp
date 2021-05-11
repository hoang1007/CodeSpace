#include <iostream>
using namespace std;

int main()
{
    int n = 4;
    const int row = 2*n - 1,
              col = n,
              mid = n - 1;

    char triangle[col][row];

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            triangle[i][j] = ' ';

            for (int k = 0; k <= i; k++)
                triangle[i][mid + k] = triangle[i][mid - k] = '*';
        }
    }

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
            cout << triangle[i][j] << " ";
        cout << endl;
    }
}