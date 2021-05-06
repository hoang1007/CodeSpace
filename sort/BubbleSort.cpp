#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
}

vector<int> input()
{
    fstream f("/home/hoang/Documents/DSA/sort/data");
    if (f.fail()) cerr << "Can't open file!\n";

    vector<int> res;
    cerr << "Reading...\n";
    while (!f.eof())
    {
        int n;  f >> n;
        res.push_back(n);
    }
    cerr << "Complete!\n";
    f.close();
    return res;
}

void output(int *arr, int n)
{
    fstream f("/home/hoang/Documents/DSA/sort/ouput");
    if (f.fail()) cerr << "Can't open file!\n";
    for (int i = 0; i < n; i++)
        f << arr[i] << " ";
    f.close();
}
int main()
{
    vector<int> in = input();
    int n = in.size();
    cerr << "Size of arr is: " << n << endl;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = in[i];
    BubbleSort(arr, n);
    output(arr, n);
}