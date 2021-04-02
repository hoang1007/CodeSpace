#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    InsertionSort(arr, n);
    output(arr, n);
}