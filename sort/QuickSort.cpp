#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int partition(int arr[], int n, int lo, int hi);
void QuickSort(int arr[], int n);


int main()
{
    vector<int> data;
    ifstream input;
    input.open("D:/Algorithms/sort/data", ios::in);

    while (!input.eof())
    {
        int n;  
        input >> n;
        data.push_back(n);
    }
    
    int n = data.size();
    int *arr = new int[n];

    for (int i = 0; i < data.size(); i++)
        arr[i] = data[i];
    QuickSort(arr, n);
    
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int partition(int arr[], int n, int lo, int hi)
{
    int pivot = arr[hi];
    int left = lo,
        right = hi - 1;
    
    while (true)
    {
        while (left < right && arr[left] < pivot)   left++;
        while (left < right && arr[right] > pivot)  right--;
        if (left >= right) break;

        swap(arr[left], arr[right]);  
        left++; right--;
    }
    swap(arr[left], arr[hi]);
    return left;
}
void QuickSort(int arr[], int n, int lo, int hi)
{
    if (lo < hi)
    {
        int pivot = partition(arr, n, lo, hi);

        QuickSort(arr, n, lo, pivot - 1);
        QuickSort(arr, n, pivot + 1, hi);
    }
}
void QuickSort(int arr[], int n)
{
    QuickSort(arr, n, 0, n- 1);
}