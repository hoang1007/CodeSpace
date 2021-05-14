#include <iostream>
using namespace std;

int main()
{
    int n;  cin >> n;
    const int size = n,
                mid = n / 2 - 1,
                center = n*n / 2 + 1;
    int arr[size][size];

    arr[mid][mid] = center;

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            arr
}