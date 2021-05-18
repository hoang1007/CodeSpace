#include <bits/stdc++.h>
using namespace std;

int main()
{
/*    string s;
    getline(cin, s);
    s += ',';
    stringstream ss(s);
    int x; char y;
    vector <int> arr;
    while(ss >> x >> y) arr.push_back(x); */
    int x; char y;
    vector <int> arr;
    cin >> x;
    arr.push_back(x);

    while (cin >> y >> x)
    {
        arr.push_back(x);
    }
    // for (int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
    // cout << endl;
    double average = 0, variance = 0;
    for (int i = 0; i < arr.size(); i++) average += (double) arr[i]/arr.size();
    for (int i = 0; i < arr.size(); i++) variance += (double) pow((arr[i] - average),2)/arr.size();
    cout << average << endl
         << variance;
    return 0;
}