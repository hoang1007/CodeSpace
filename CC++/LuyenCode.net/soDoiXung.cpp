#include <iostream>
#include <math.h>
using namespace std;

string theNearestSymmetry(string n) {
    if (n.length() == 1) return n;

    for (int i = 0; i < n.length()/2; i++)
        n[n.length() - i - 1] = n[i];
    return n;
}

int order(string nSymmetry) {
    int size = (nSymmetry.length() - 1) / 2;
    int Order = (nSymmetry[0] - '0' - 1)*pow(10, size) + 1;
    for (int i = 1; i <= size; i++)
        Order += (nSymmetry[i] - '0')*pow(10, size - i);
    return Order;
}

int compare(string a, string b) {
    for (int i = a.length() / 2; i < a.length(); i++) {
        if (a[i] < b[i]) return -1;
        if (a[i] > b[i]) return 1;
    }
    return 0;
}

int countSymmetry(string left, string right) {
    string leftSymmetry = theNearestSymmetry(left),
            rightSymmetry = theNearestSymmetry(right);
    // calculate two symmetry number order
    int leftOrder = order(left),
        rightOrder = order(right);

    int carryLeft = compare(left, leftSymmetry) == 1 ? -1 : 0,
        carryRight = compare(right, rightSymmetry) == -1 ? -1 : 0;
    int count = 0;
    for (int i = leftSymmetry.length(); i < rightSymmetry.length(); i++)
        count += 9*pow(10, (i - 1)/2);
    return count - leftOrder + rightOrder + 1 + carryLeft + carryRight;
}

int main() {
    string left, right;
    //cin >> left >> right;

    //cout << theNearestSymmetry("123");
    cout << endl << countSymmetry("1", "10");
    cout << endl << countSymmetry("10001", "100000");
    cout << endl << countSymmetry("11", "30");
}