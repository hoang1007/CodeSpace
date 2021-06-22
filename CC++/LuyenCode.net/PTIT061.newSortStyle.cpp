#include <bits/stdc++.h>
#include <string.h>
using namespace std;

template <typename T>
void swap(T arr[], int i, int j) {
    T temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

template <typename T>
int partition(T arr[], int left, int right, bool reverse) {
    T pivot = arr[right];
    int i = left, j = right - 1;

    while (true) {
        while (i <= j && (reverse ? arr[i] > pivot : arr[i] < pivot)) i++;
        while (i <= j && (reverse ? arr[j] < pivot : arr[j] > pivot)) j--;

        if (i >= j) break;
        swap(arr, i, j);
        i++, j--;
    }
    swap(arr, i, right);
    return i;
}

template <typename T>
void quickSort(T arr[], int left, int right, bool reverse = true) {
    if (left < right) {
        int pivot = partition(arr, left, right, reverse);

        quickSort(arr, left, pivot - 1, reverse);
        quickSort(arr, pivot + 1, right, reverse);
    }
}

int convertInt(char sc[]) {
    int res = 0;
    int i = sc[0] == '-' ? 1 : 0;
    for (; sc[i] != '\0'; i++)
        res = 10*res + sc[i] - '0';
    return sc[0] == '-' ? -res : res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;  cin >> n;
    int arr[n];
    for (auto &item : arr)
        cin >> item;
    
    for (auto &item : arr) {
        stringstream ss; ss << item;
        string k; ss >> k;
        char* sc = strcpy(new char[5], k.c_str());
        bool reverse = true;
        if (sc[0] == '-') reverse = false;
        quickSort(sc, reverse ? 0 : 1, strlen(sc) - 1, reverse);
        if (sc[0] == '-' && sc[1] == '0') {
            int i = 1;
            for (; sc[i] == '0'; i++);
            swap(sc, 1, i);
        }
        item = convertInt(sc);
    }

    quickSort(arr, 0, n - 1);
    for (auto item : arr)
        cout << item << " ";
}