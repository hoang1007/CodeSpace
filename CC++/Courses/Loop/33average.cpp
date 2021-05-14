#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    const int amount = 5;
    double average = 0.0;
    for (int i = 0; i < amount; i++)
    {
        int x;  cin >> x;
        average += (double) x / amount;
    }

    printf("%.2lf", average);
}