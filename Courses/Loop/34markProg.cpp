#include <iostream>
#include <cstdio>
using namespace std;

class Mark
{
    int amount;
    double* mark;
    double* factor;
    double sumFactor;
    double average;
    bool isLegalMark(double n);
    bool isLegalFactor(double n);
public:
    Mark()
    {
        factor = mark = NULL;
        amount = sumFactor = average = 0;
    }
    string input();
    void output();
};

int main()
{
    Mark p;
    p.output();
}

bool Mark::isLegalMark(double n)
{
    if (n < 0 || n > 10) return false;
    return true;
}

bool Mark::isLegalFactor(double n)
{
    if (n < 1 || n > 3) return false;
    double n_int = (n / 5) * 10;
    if (n_int == (int) n_int) return true;
    return false;
}

string Mark::input()
{
    cin >> amount;
    mark = new double[amount];
    factor = new double[amount];

    for (int i = 0; i < amount; i++)
    {
        cin >> mark[i];
        if (!isLegalMark(mark[i])) return "Sai diem so";
        cin >> factor[i];
        if (!isLegalFactor(factor[i])) return "Sai he so";
    }
    return "success";
}

void Mark::output()
{
    string log = input();
    if (log != "success") 
    {
        cout << log;
        return ;
    }

    cout << "Tong so mon hoc can tinh DTB: " << amount << endl;
    for (int i = 0; i < amount; i++)
    {
        average += mark[i]*factor[i];
        sumFactor += factor[i];
        printf("Diem mon hoc %d: %.1lf\n", i, mark[i]);
        printf("He so mon hoc %d: %.1lf\n", i, factor[i]);
    }

    printf("Tong so he so: %.1lf\n", sumFactor);
    printf("Diem trung binh cua %d mon hoc: %.1lf", amount, average / sumFactor);
}