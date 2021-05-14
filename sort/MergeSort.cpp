#include <iostream>
using namespace std;

void merge(int* arr, int begin, int mid, int end, int maxE)
{
    int i = begin, j = mid + 1,
        k = begin;
    
    while (i <= mid && j <= end)
    {
        if (arr[i] % maxE < arr[j] % maxE)
        {
            arr[k] += (arr[i] % maxE)*maxE;
            i++;
        }
        else
        {
            arr[k] += (arr[j] % maxE)*maxE;
            j++;
        }
        k++;
    }

    for (; i <= mid; i++, k++)
        arr[k] += (arr[i] % maxE)*maxE;
    for (; j <= end; j++, k++)
        arr[k] += (arr[j] % maxE)*maxE;
    
    for (int i = begin; i <= end; i++)
        arr[i] /= maxE;
}

// Recursive merge sort with extra parameter, naxele
void mergeSortRec(int arr[], int beg, int end, int maxele)
{
    if (beg < end)
    {
        int mid = (beg + end) / 2;
        mergeSortRec(arr, beg, mid, maxele);
        mergeSortRec(arr, mid + 1, end, maxele);
        merge(arr, beg, mid, end, maxele);
    }
}

// This functions finds max element and calls recursive
// merge sort.
void mergeSort(int arr[], int n)
{
    int maxE = arr[0];
    for (int i = 1; i < n; i++)
        if (maxE < arr[i]) maxE = arr[i];
    mergeSortRec(arr, 0, n - 1, maxE + 1);
}

int main()
{
    int arr[] = {999, 612, 589, 856, 56, 945, 243};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, n);

    cout << "Sorted array \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
