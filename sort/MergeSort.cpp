#include <iostream>
#include <vector>
using namespace std;

vector<int> Merge(vector<int> a, vector<int> b)
{
    vector<int> res;

    while (!a.empty() && !b.empty())
    {
        if (a.empty())
            for (int i = 0; i < b.size(); i++)
                res.push_back(b[i]);
        else if (b.empty())
            for (int i = 0; i < a.size(); i++)
                res.push_back(a[i]);
        else if (a.back() > b.back())
        {
            res.push_back(b.back());
            b.pop_back();
        }
        else
        {
            res.push_back(a.back());
            a.pop_back();
        }
    }

    return res;
}

vector<int> MergeSort(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
    if (arr.size() == 1) return arr;
    int pivot = arr.size() / 2;
    vector<int> left, right;

    for (int i = 0; i < pivot; i++)
        left.push_back(arr[i]);
    for (int i = pivot; i < arr.size(); i++)
        right.push_back(arr[i]);

    left = MergeSort(left);
    right = MergeSort(right);

    return Merge(left, right);
}

int main()
{
    // int arr[] = {1, 4, 3, 6, 7, 4, 9};
    // vector<int> input;
    // for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++)
    //     input.push_back(arr[i]);

    // vector<int> res = MergeSort(input);

    // for (int i = 0; i < res.size(); i++)
    //     cout << res[i] << " ";

    int inpA[] = {1, 3, 5};
    vector<int> a;
}