#include <iostream>
using namespace std;

int A = 10;
int B = 10000010;
int arr[10000];

int main(int argc, char** argv)
{
    int i;
    while (cin >> i)
        arr[i - A]++;
    
    for (int i = 0; i < 10000; i++)
        cout << i + A << " " << arr[i] << endl;
}