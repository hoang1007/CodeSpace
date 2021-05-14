#include<iostream>
#include<math.h>
#include<string>
using namespace std;

int ucln(int a, int b)
{
    a = a > 0 ? a : -a;
    b = b > 0 ? b : -b;
    if (a % b == 0) return b;
    return ucln(b, a % b);
}
struct PhanSo
{
    int tu, mau;
    PhanSo() {}
    PhanSo(int tu, int mau)
    {
        this->tu = tu;
        this->mau = mau;
    }
    void rutGon();
    void print();
};

void PhanSo::rutGon()
{
    int u = ucln(tu, mau);
    tu /= u;
    mau /= u;
}
void PhanSo::print()
{
    if (mau == 1)
    {
        cout << tu;
        return ;
    }
    else if (mau == -1)
    {
        cout << -tu;
        return ;
    }
    if (tu < 0 && mau < 0) cout << -tu << "/" << -mau;
    else if (tu < 0 || mau < 0)
    {
        tu = tu < 0 ? -tu : tu;
        mau = mau < 0 ? -mau : mau;
        cout << "-" << tu << "/" << mau;
    }
    else cout << tu << "/" << mau;
}

int main()
{
    int tu, mau;    cin >> tu >> mau;
    PhanSo p = PhanSo(tu, mau);
    p.rutGon();
    p.print();
}