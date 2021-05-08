#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int arr[] = {14, 3, 5, 6, 3};
    vector<int> v;
    for (auto i : arr)
        v.push_back(i);
    
    v.insert(v.begin() + v.size(), 100);

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}