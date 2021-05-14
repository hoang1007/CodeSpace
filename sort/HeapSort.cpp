#include <iostream>
#include <vector>
using namespace std;

void heapify(int* arr, int n, int node_index)
{
    int largest = node_index,
        left = 2*node_index + 1,    // left child node of node parent
        right = 2*node_index + 2;   // right child node of node parent
    
    // find max value: parent, left node and right node
    if (left < n && arr[largest] < arr[left])
        largest = left;
    if (right < n && arr[largest] < arr[right])
        largest = right;
    
    if (largest != node_index)  // update heap and recursive to next node
    {
        swap(arr[node_index], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int* arr, int n)
{
    // build heap
    for (int i = n/2 - 1; i >= 0; i--)   // build heap from down to up, right to left
        heapify(arr, n, i);
    
    // sort
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[i], arr[0]);   // move max element to depthest and rightest
        heapify(arr, i, 0); // rebuild
    }
}

int main()
{
    vector<int> input;
    int x;
    while (cin >> x)
        input.push_back(x);
    
    int arr[input.size()];

    for (int i = 0; i < input.size(); i++)
        arr[i] = input[i];

    heapSort(arr, input.size());
    input.clear();
    for (int i: arr)
        cout << i << " ";
}