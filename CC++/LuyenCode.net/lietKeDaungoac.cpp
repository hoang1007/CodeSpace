#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> open;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') open.push_back(i);
        if (s[i] == ')') {
            printf("%d %d\n", open.back() + 1, i + 1);
            open.pop_back();
        }
    }
}