#include <iostream>
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "quickSort.h"
#include "InsertionSort.h"
#include "heapSort.h"
#include "mergeSort.h"
using namespace std;

int main() {
    int arr[] = {3, 1, 5, 4, 7, 6, 9, 6, 4, 6, 0};

    int n = sizeof(arr)/sizeof(*arr);
    mergeSort(arr, n);

    for (int i : arr)
        cout << i << " ";
}