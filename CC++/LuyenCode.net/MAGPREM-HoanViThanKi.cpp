#include <iostream>
using namespace std;

int* res = nullptr;
bool timHoanVi(int n, int k, bool* isPresent)
{
    for (int i = 1; i <= n; i++)
    {
        int lo = i - k, hi = i + k;

        if (lo >= 1 && lo <= n && !isPresent[lo])
        {
            res[i] = lo;
            isPresent[lo] = true;
        }
        
        else if (hi >= 1 && hi <= n && !isPresent[hi])
        {
            res[i] = hi;
            isPresent[hi] = true;
        }
        else return false;
    }
    return true;
}
int main()
{
    int n, k;
    cin >> n >> k;

    bool *isPresent = new bool[n + 1];
    for (int i = 1; i <= n; i++)
        isPresent[i] = false;
    res = new int[n + 1];
    if (timHoanVi(n, k, isPresent))
        for (int i = 1; i <= n; i++)
            cout << res[i] << " ";
    else cout << -1;
    delete isPresent;
    delete res;
}