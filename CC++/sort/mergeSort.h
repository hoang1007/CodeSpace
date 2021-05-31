#pragma once

void merge(int arr[], int begin, int mid, int end, int maxAll) {
    int i = begin, j = mid + 1, k = begin;
    while (i <= mid && j <= end) {
        if (arr[i] % maxAll < arr[j] % maxAll)
        {
            arr[k] += (arr[i] % maxAll)*maxAll;
            i++;
        }
        else
        {
            arr[k] += (arr[j] % maxAll)*maxAll;
            j++;
        }
        k++;
    }

    for (; i <= mid; i++, k++)
        arr[k] += (arr[i] % maxAll)*maxAll;
    for (; j <= end; j++, k++)
        arr[k] += (arr[j] % maxAll)*maxAll;
    
    for (int i = begin; i <= end; i++)
        arr[i] /= maxAll;
}

void mergeSort(int arr[], int beg, int end, int maxAll)
{
    if (beg < end)
    {
        int mid = (beg + end) / 2;
        mergeSort(arr, beg, mid, maxAll);
        mergeSort(arr, mid + 1, end, maxAll);
        merge(arr, beg, mid, end, maxAll);
    }
}

void mergeSort(int arr[], int n)
{
    int maxAll = arr[0];
    for (int i = 1; i < n; i++)
        if (maxAll < arr[i]) maxAll = arr[i];
    mergeSort(arr, 0, n - 1, maxAll + 1);
}
