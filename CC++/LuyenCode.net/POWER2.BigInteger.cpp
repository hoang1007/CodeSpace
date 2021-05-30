#include <iostream>
using namespace std;

string operator+(const string &a, const string &b) {
    if (a.size() == 0 || a == "0") return b;
    if (b.size() == 0 || b == "0") return a;
    
    string res;
    res.resize(b.size() > a.size() ? b.size() : a.size());

    int carry = 0;

    int i_b = b.size() - 1;
    int i_a = a.size() - 1;
    int i_res = res.size() - 1;
    for (; i_a >= 0 || i_b >= 0; i_a--, i_b--, i_res--) {
        int digita = 0, digitb = 0;
        if (i_a >= 0) digita = a[i_a] - '0';
        if (i_b >= 0) digitb = b[i_b] - '0';
        char sumDigit = (digita + digitb + carry) % 10 + '0';
        res[i_res] = sumDigit;
        carry = (digita + digitb + carry) / 10;
    }

    return string(carry > 0 ? char(carry + 48) + res : res);
}

string mulSingle(const string &a, const char& b) {
    if (a.size() == 0 || a == "0" || b == '0') return "0";
    string res;
    res.resize(a.size());
    int bInt = b - '0';

    int carry = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        int mul = bInt*(a[i] - '0');
        char digitRes = (carry + mul) % 10 + '0';
        res[i] = digitRes;
        carry = (mul + carry)/10;
    }

    return carry > 0 ? char (carry + '0') + res : res;
}

string operator*(const string &a, const string &b) {
    if (a == "0" || b == "0") return string("0");

    string res("0");
    string carry = "";
    for (int i = a.size() - 1; i >= 0; i--, carry += "0") {
        string mul = string(mulSingle(b, a[i]) + carry);
        res = res + mul;
    }
    return res;
}

string operator^(string a, int n) {
    string res = "1";
    
    for (; n; n /= 2, a = a*a)
        if (n % 2) res = res * a;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string a;
    int n;
    cin >> a >> n;
    cout << (a^n);
}