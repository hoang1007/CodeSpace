#include <iostream>
using namespace std;

string hasEqual(int n)
{
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if (arr[x]) return "Yes";
        arr[x] = 1;
    }
    delete[] arr;
    return "No";
}

int main()
{
    int n;  cin >> n;
    cout << hasEqual(n);
}