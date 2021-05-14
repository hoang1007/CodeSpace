#include <iostream>
using namespace std;

string isPalindrome(string s)
{
    for (int i = 0; i < s.size(); i++)
        if (s[i] != s[s.size() - i - 1]) return "No";
    return "Yes";
}

int main()
{
    string s;   cin >> s;
    cout << isPalindrome(s);
}