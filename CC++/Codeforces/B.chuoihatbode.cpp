#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int countStep(string input[], int n, int i, map<string, int> arr) {
    int count = 0;
    int c = i;
    int carry = 0;
    for (int j = 0; j < n; j++) {
        count += arr[ input[i] ] + carry - c;
        i++;
        if (i >= n) {
            carry = input->length() + 1;
            i %= n;
        }
    }
    return count;
}

int main() {
    int n;  cin >> n;
    string input[n];

    for (string &i : input)
        cin >> i;

    sort(input, input + n);

    map<string, int> arr;
    string s = input[0];
    int k = 0;
    for (int i = 0; ; i++) {
        if (input[k] == s) {
            arr[s] = i;
            k++;
        } 
        
        char temp = s[0];
        s = s.substr(1) + temp;
        if (s == input[0]) break;
    }

    if (k < n) {
        cout << -1;
        return 0;
    }

    int minStep = 1e9;
    for (int i = 0; i < n; i++) {
        int step = countStep(input, n, i, arr);
        if (minStep > step) minStep = step;
    }

    cout << minStep;
}