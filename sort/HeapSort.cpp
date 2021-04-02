#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void heapify(int arr[], int n, int root);
void HeapSort(int arr[], int n);

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

    HeapSort(arr, n);
    
    ofstream output("D:/Algorithms/sort/output", ios::out);

    for (int i = 0; i < n; i++)
        output << arr[i] << " ";
}

void heapify(int arr[], int n, int root)
{
    int largest = root;
    int left = 2 * root + 1,
        right = 2 * root + 2;
    
    //find the largest node in heap tree
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

void HeapSort(int arr[], int n)
{
    //build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    //sort
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}