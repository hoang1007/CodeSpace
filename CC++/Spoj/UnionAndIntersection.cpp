#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;  cin >> t;
    while (t--)
    {
        int n, m;   cin >> n >> m;

        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        
        vector<int> Intersection;
        vector<int> freq(1e4 + 1, 0);

        int max = 0;
        for (int i = 0; i < n; i++)
        {
            freq[ a[i] ]++;
            if (max < a[i]) max = a[i];
        }
        for (int i = 0; i < m; i++)
        {
            freq[ b[i] ]++;
            if (max < b[i]) max = b[i];
        }
        
        for (int i = 0; i <= max; i++)
            if (freq[i])
            {
                cout << i << " ";
                if (freq[i] > 1) Intersection.push_back(i);
            }
        cout << endl;
        for (int i = 0; i < Intersection.size(); i++)
            cout << Intersection[i] << " ";
    }
}