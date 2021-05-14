#include <iostream>
#include <map>
#include <vector>
using namespace std;

int countDiffOne(vector<int> nums)
{
    map<int, int> freq;
    for (size_t i = 0; i < nums.size(); i++)
        freq[nums[i]]++;
    
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
        if (freq[nums[i] + 1] || freq[nums[i] - 1])
            count += freq[nums[i]];
    return count;
}

int main()
{
    int n;  cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    cout << countDiffOne(nums);
}