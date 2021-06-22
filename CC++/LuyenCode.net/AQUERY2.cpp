#include <iostream>
#include <algorithm>
using namespace std;

struct Element {
    int value;
    int time;
    Element(int value, int time) : value(value), time(time) {}
    Element() {}
    bool operator<(const Element &other) {
        return value < other.value;
    }
    bool operator>(const Element &other) {
        return value > other.value;
    }
};

int main() {
    int n; cin >> n;
    Element arr[n];
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        arr[i] = Element(x, y);
    }

    int k; cin >> k;
    sort(arr, arr + n);
    for (auto item : arr)
        if (k <= item.time) {
            cout << item.value;
            break;
        }
        else k -= item.time;
}