#include <iostream>
#include <vector>
using namespace std;

vector<int> snt;
vector<int> chinhphuong;
vector<int> hoanhao;

void threeInOne(int n)
{
    for (int i = 2; i*i <= n; i++)
    {
        chinhphuong.push_back(i*i);
        for (int j = i; j * i <= n; j++)
            snt[j*i] += j + i;
    }

    for (int i = 2; i < snt.size(); i++)
        if (snt[i] + 1 == i)
            hoanhao.push_back(i);
}

int main()
{
    int n;  cin >> n;
    snt.resize(n + 1);

    threeInOne(n);
    cout << "nguyen to: ";
    for (int i = 2; i < snt.size(); i++)
        if(!snt[i]) cout << i << " ";
    cout << endl;
    cout << "hoan hao: ";
    for (int i = 0; i < hoanhao.size(); i++)
        cout << hoanhao[i] << " ";
    cout << endl;
    cout << "chinh phuong: ";
    for (int i = 0; i < chinhphuong.size(); i++)
        cout << chinhphuong[i] << " ";
    cout << endl;
}