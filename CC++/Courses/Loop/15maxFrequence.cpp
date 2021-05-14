#include <iostream>
using namespace std;

int main()
{
    int freq[5] = {0};

    int n;  cin >> n;
    while (n--)
    {
        int x;  cin >> x;
        freq[x - 1]++;
    }

    int max = 0;
    int max_type = 1;
    for (int i = 0; i < 5; i++)
        if (max < freq[i])
        {
            max = freq[i];
            max_type = i + 1;
        }
    cout << max_type;
}