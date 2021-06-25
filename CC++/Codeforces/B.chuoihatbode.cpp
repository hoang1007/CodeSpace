#include <iostream>
#include <vector>
using namespace std;

struct str : string {
    int step;
    str() : string() {step = 0;}
    str(string value) : string(value) {step = 0;}
};

int countStep(const vector<str> list, int i) {
    int carry = list[i].step;
    int size = list[0].length();

    int step = 0;
    for (int j = 0; j < list.size(); j++) {
        step += list[i++].step - carry;

        if (i >= list.size()) {
            i %= list.size();
            step += size - carry;
        }
    }

    return step;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;  cin >> n;
    string arr[n];

    for (auto &item : arr)
        cin >> item;
    vector<str> list;

    int count = 0;
    for (string temp = arr[0]; ; count++) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == temp) {
                list.push_back(str(arr[i]));
                list.back().step = count;
                break;
            }
        }

        temp = temp.substr(1) + temp[0];
        if (temp == arr[0]) break;
    }

    int minStep = 1e9;
    for (int i = 0; i < list.size(); i++) {
        int step = countStep(list, i);
        if (minStep > step) minStep = step;
    }

    cout << minStep;
}