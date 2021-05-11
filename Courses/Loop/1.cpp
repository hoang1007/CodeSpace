#include <iostream>
#include <vector>
using namespace std;

#define ERASE 0

vector<int> snt;
vector<int> chinhphuong;
vector<int> hoanhao;
vector<vector<int>> uoc;

void threeInOne(int n)
{
    for (int i = 2; i*i <= n; i++)
    {
        chinhphuong.push_back(i*i);
        for (int j = i*i; j <= n; j += i)
        {
            hoanhao.push_back(j);
            snt[j] = ERASE;
        }
    }
}

int main()
{
    int n;  cin >> n;
    uoc.resize(n + 1);

    for (int i = 0; i <= n; i++)
        snt.push_back(i);
    threeInOne(n);

    for (int i = 2; i < snt.size(); i++)
        if (snt[i]) cout << snt[i] << " ";
    cout << endl;

    for (int i = 0; i < hoanhao.size(); i++)
        cout << hoanhao[i] << " ";
    cout << endl;

    for (int i = 0; i < chinhphuong.size(); i++)
        cout << chinhphuong[i] << " ";
    cout << endl;
}