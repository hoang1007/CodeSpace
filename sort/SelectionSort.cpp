#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int max_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[max_idx] < arr[j])
                max_idx = j;
        swap(arr[max_idx], arr[i]);
    }
}

vector<int> input()
{
    fstream f("D:/Algorithms/sort/data");
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
    fstream f("D:/Algorithms/sort/output");
    if (f.fail()) cerr << "Can't open file!\n";
    f.clear();
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
    SelectionSort(arr, n);
    output(arr, n);
}