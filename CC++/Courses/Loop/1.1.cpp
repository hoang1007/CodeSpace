#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

bool snt(int n)
{
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return true; 
}

bool cp(int n)
{
    int p = sqrt(n);
    return p*p == n;
}

bool hh(int n)
{
    int sum = 0;
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) sum += n / i + i;
    return sum + 1 == n;
}

void print(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;  cin >> n;
    vector<int> vSnt, vCp, vHh;

    for (int i = 2; i <= n; i++)
        if (snt(i)) vSnt.push_back(i);
        else if (cp(i)) vCp.push_back(i);
        else if (hh(i)) vHh.push_back(i);
    

    cout << "Nguyen to: "; print(vSnt);
    cout << "Hoan hao: "; print(vHh);
    cout << "Chinh phuong: "; print(vCp);
}