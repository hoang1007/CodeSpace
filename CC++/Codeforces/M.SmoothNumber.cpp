#include <iostream>
#include <vector>
using namespace std;

int jump(int length) {
    int res = 0;
    for (int i = 0, k = 1; i <= length; i++, k++)
        if (k < 10) res = 10*res + k;
        else return -1;
    return res;
}

int ceil(string low) {
    int res = 0;
    for (int i = 0, begin = low[0] - '0'; i < low.length(); i++, begin++) {
        if (begin > 9)
            return jump(low.length());
        res = 10*res + begin;
    }

    return res;
}

int main() {
    int low, high;
    cin >> low >> high;

    string lowStr = to_string(low);
    int len = lowStr.length();

    int unit = 0;
    for (int i = 0; i < lowStr.length(); i++)
        unit = 10*unit + 1;
    
    vector<int> list;
    for (int i = ceil(lowStr); i <= high; ) {
        list.push_back(i);

        if (i % 10 == 9) {
            i = jump(len++);
            unit = 10*unit + 1;
        }
        else i += unit;
    }

    cout << list.size() << endl;
    for (auto i : list)
        cout << i << " ";
}