#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;
const int _max = 1e9;

int main()
{
    int t;  cin >> t;
    int* test = new int[t];
    int max_el = 0;
    for (int i = 0; i < t; i++)
    {
        int a; cin >> a;
        test[i] = a;
        if (max_el < a) max_el = a;
    }

    int prev_2 = 0, prev_1 = 1, fibo;
    for (int i = 2; i <= max_el; i++)
    {
        fibo = (prev_1 + prev_2) % MOD;
        prev_2 = prev_1;
        prev_1 = fibo;
        for (int j = 0; j < t; j++)
            if (test[j] == i) cout << fibo << endl;
    }
}