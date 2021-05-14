#include <iostream>
#include <string>
using namespace std;

int countRepeat(string s, int left, int right)
{
    int size_substr = right - left + 1;
    string c = s.substr(left - 1, size_substr);
    
    int count = 1;
    for (; right < s.size(); right += size_substr)
    {
        string temp = s.substr(right, size_substr);
        if (c == temp) count++;
        else break;
    }
    return count;
}

int main()
{
    int size, t;
    string s;   cin >> s;
    while (t--)
    {
        int left, right;
        cin >> left >> right;
        cout << countRepeat(s, left, right) << endl;
    }
}