#include <iostream>
using namespace std;

int main()
{
    int old = -1;
    int current = 0;
    while (cin >> current)
    {
        if (current != old) cout << current << " ";
        old = current;
        if (current < 0) break;
    }
}