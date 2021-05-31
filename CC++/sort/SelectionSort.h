#pragma once

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_itr = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_itr])
                min_itr = j;
        int temp = arr[i];
        arr[i] = arr[min_itr];
        arr[min_itr] = temp;
    }
}