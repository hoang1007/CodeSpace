#include <iostream>
using namespace std;

void heapify(int *arr, int n, int root);

void heapSort(int *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    //sort
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

void heapify(int *arr, int n, int root)
{
    int left = 2 * root + 1,
        right = 2 * root + 2,
        largest = root;
    
    if (left < n && arr[left] > arr[largest]) 
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    
    if (largest != root)
    {
        swap(arr[largest], arr[root]);
        heapify(arr, n, largest);
    }
}

int main()
{
    int n;  cin >> n;
    int* arr = new int[n];
    int minDiff = INT16_MAX;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    heapSort(arr, n);
    for (int i = 0; i < n - 1; i++)
        if (minDiff > arr[i + 1] - arr[i])
            minDiff = arr[i + 1] - arr[i];
    cout << minDiff;
}