#include <iostream>
using namespace std;

int countLegal(string s) {
    if (s.length() == 0) return 0;
    int k = 0, count = 0;
    for (auto i : s) {
        if (i == '(') k++;
        else if (i == ')') {
            if (k > 0) {
                count++;
                k--;
            }
        }
    }

    return count;
}

int main() {
    string s;
    int n;  cin >> n;
    while (n--) {
        cin >> s;
        cout << 2*countLegal(s) << endl;
    }
}