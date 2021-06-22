#include <iostream>
#include <cstdio>
using namespace std;

int count = 0;

void enumBrackets(string brackets, int i, int open, int close, int code) {
    if (code < 0) return ;
    if (code == 0 && open == 0 && close == 0) {
        cout<< brackets << endl;
        count++;
        return ;
    }

    if (code != 0 && open == 0 && close == 0) return ;

    if (open > 0) {
        brackets += '(';
        enumBrackets(brackets, i + 1, open - 1, close, code + 1);
    }

    if (close > 0) {
        brackets[brackets.length() - 1] = ')';
        enumBrackets(brackets, i + 1, open, close - 1, code - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;  cin >> n;
    string brackets;
    enumBrackets(brackets, 0, n/2, n/2, 0);

    cout << count;
}