#include <iostream>
#include <vector>
using namespace std;

int n;

bool check(vector<int> queens, int k)
{
    if (k == 1) return true;
    int row1 = k, col1 = queens[row1];

    for (int row2 = 1; row2 < k; row2++)
    {
        int col2 = queens[row2];
        if (col1 == col2 || row1 == row2 || col1 + row1 == col2 + row2 || col1 - row1 == col2 - row2)
            return false;
    }
    return true;
}

int solve(vector<int> queens, int i)
{
    if (i == n + 1) return 1;

    int count = 0;
    for (int k = 1; k <= n; k++)
    {
        queens[i] = k;
        if (check(queens, i)) 
           count += solve(queens, i + 1);
    }

    return count;
}

int main()
{
    cin >> n;
    vector<int> queens(n + 1);

    cout << solve(queens, 1);
}