#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void MergeSort(int arr[], int n);

int main()
{
    vector<int> data;
    ifstream input;
    input.open("D:/Algorithms/sort/data", ios::in);

    if (input.fail())
        cerr << "Can't open file\n";
    while (!input.eof())
    {
        //cout << "Reading...";
        int n;
        input >> n;
        data.push_back(n);
    }
    int n = data.size();
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = data[i];

    MergeSort(arr, n);
    
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void MergeSort(int arr[], int n)
{
    if (n == 1) return ;

    int leftSize = n / 2,
        rightSize = n - n / 2;
    int *left = new int[leftSize],
        *right = new int[rightSize];

    //tach mang arr thanh hai phan left va right
    for (int i = 0; i < leftSize; i++)
        left[i] = arr[i];
    for (int i = 0; i < rightSize; i++)
        right[i] = arr[n / 2 + i];

    //de quy de tach left va right cho den khi con 1 phan tu
    MergeSort(left, leftSize);
    MergeSort(right, rightSize);

    //ghep hai mang left va right thanh arr
    int left_iter = 0,
        right_iter = 0,
        arr_iter = 0;
    while (arr_iter < n)
    {
        if (left_iter == leftSize)
        {
            for (right_iter; right_iter < rightSize; right_iter++)
            {
                arr[arr_iter] = right[right_iter];
                arr_iter++;
            }
            break;
        }
        if (right_iter == rightSize)
        {
            for (left_iter; left_iter < leftSize; left_iter++)
            {
                arr[arr_iter] = left[left_iter];
                arr_iter++;
            }
        }
        
        if (left[left_iter] < right[right_iter])
        {
            arr[arr_iter] = left[left_iter];
            arr_iter++;
            left_iter++;
        }
        else
        {
            arr[arr_iter] = right[right_iter];
            arr_iter++;
            right_iter++;
        }
    }
}