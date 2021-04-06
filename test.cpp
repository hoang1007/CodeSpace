#include <iostream>
#include <vector>
using namespace std;

// void sievePrime(vector<int>& flags, const int& r)
// {
//     for (int i = 2; i * i <= r; i++)
//         for (int j = i * i; j <= r; j += i)
//             flags[j] = false;
// }

int count_factor(int n)
{
    int count = 0;
    int factor = 2;
    while (n != 1)
    {
        if (n % factor == 0)
        {
            count++;
            while (n % factor == 0)
                n /= factor;
        }
        factor++;
    }
    return count;
}

int main()
{
    int t;  cin >> t;
    for (; t; t--)
    {
        int l, r;
        cin >> l >> r;

        if (l == 1) l++;

        //vector<int> flags(r, 0);

        //sievePrime(flags, r);
        int count = 0;
        for (; l <= r; l++)
        {
            count += count_factor(l);
        }
        cout << count << endl;
    }
}