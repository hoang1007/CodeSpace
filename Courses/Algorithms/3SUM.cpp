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
int main()
{
    int n;  cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    heapSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0) break;
        int left = i + 1,
            right = n - 1;
        while (left < right)
        {
            int sum = arr[i] + arr[left] + arr[right];
            if (sum == 0)
            {
                cout << arr[i] << " " << arr[left] << " " << arr[right] << endl;
                while (left < right && arr[left] == arr[left + 1]) left++;
                while (left < right && arr[right] == arr[right + 1]) right--;
                left++; right--;
            }
            else if (sum < 0)
            {
                while (left < right && arr[left] == arr[left + 1]) left++;
                left++;
            }
            else 
            {
                while (left < right && arr[right] == arr[right - 1]) right--;
                right--;
            }

            while (i < n && arr[i] == arr[i + 1]) i++;
        }
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