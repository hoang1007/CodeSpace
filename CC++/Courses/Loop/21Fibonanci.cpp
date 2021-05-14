#include <iostream>
#include <vector>
using namespace std;

vector<int> fibo = {1, 1};

string isFibonanci(int n)
{
    for (; fibo.back() < n; fibo.push_back(fibo.back() + fibo[fibo.size() - 2]));

    if (fibo.back() == n) return "Thuoc day Fibonancci";
    return "Khong thuoc day Fibonancci";
}

int main()
{
    int n;  cin >> n;
    cout << isFibonanci(n) << endl;
    for (int i = 0; i < fibo.size(); i++)
        cout << fibo[i] << " ";
}