#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, char> digit;
    digit["0000"] = '0';
    digit["0001"] = '1';
    digit["0010"] = '2';
    digit["0011"] = '3';
    digit["0100"] = '4';
    digit["0101"] = '5';
    digit["0110"] = '6';
    digit["0111"] = '7';
    digit["1000"] = '8';
    digit["1001"] = '9';
    digit["1010"] = 'A';
    digit["1011"] = 'B';
    digit["1100"] = 'C';
    digit["1101"] = 'D';
    digit["1110"] = 'E';
    digit["1111"] = 'F';

    int t;  cin >> t;
    while (t--) {
        string hex;
        cin >> hex;
        
        while (hex.length() % 4) hex = '0' + hex;
        string res;
        for (int i = 0; i < hex.length(); i += 4)
            res += digit[ hex.substr(i, 4) ];
        cout << res << endl;
    }
}