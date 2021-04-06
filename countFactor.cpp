#include <iostream>
#include <vector>

using namespace std;

void countFactor(vector<int>& factorCount, const int& n)
{
    for (int i = 2; i <= n; i++)
        if (factorCount[i] == 0)
            for (int j = i; j <= n; j += i)
                factorCount[j] ++;
}

int main()
{
    int T; cin >> T;
    vector<int> factorCount(1e7, 0);
    countFactor(factorCount, 1e7);

    int l, r;
    for (; T; T--)
    {
        cin >> l >> r;
        
        // vector<int> factorCount(r + 1, 0);
        // countFactor(factorCount, r);

        int count = 0;
        for ( ; l <= r; l++)
            count += factorCount[l];

        cout << count << endl;
    }
}