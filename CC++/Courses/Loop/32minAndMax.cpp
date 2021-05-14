#include <iostream>
using namespace std;

int main()
{
    double min = INT16_MAX,
        max = INT16_MIN;

    int t;  cin >> t;
    while (t--)
    {
        double x;
        cin >> x;

        if (max < x) max = x;
        else if (min > x) min = x;
    }

    cout << max << endl << min;
}