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

string operator-(const string &a, const string &b) {
    if (b == "0") return a;
    int i_a = a.size() - 1,
        i_b = b.size() - 1;
    string res;
    res.resize(a.size());
    int i_res = res.size() - 1;
    int carry = 0;
    for (; i_res >= 0; i_a--, i_b--, i_res--) {
        int subtract = 0;
        if (i_a >= 0) subtract += a[i_a] - '0' - carry;
        if (i_b >= 0) subtract -= b[i_b] - '0';

        if (subtract < 0) {
            subtract += 10;
            carry = 1;
        }
        else carry = 0;

        res[i_res] = char(subtract + '0');
    }
    
    if (res[0] == '0' && res.size() > 1) return string(res.substr(1, res.size() - 1));
    return string(res);
}

string operator*(const string &ab, const string &cd) {
    if (ab == "0" || cd == "0") return "0";
    if (ab.size() == 0 || cd.size() == 0) return "0";
    if (ab.size() == 1 && cd.size() == 1) 
      return to_string( (ab[0] - '0')*(cd[0] - '0') );

    int length = max(ab.size(), cd.size());
    int z = (length + 1)/2;

    string a, b, c, d;
    if (ab.size() <= z) {
        b = ab;
    }
    else {
        b = ab.substr(ab.size() - z, z);
        a = ab.substr(0, ab.size() - z);
    }
    
    if (cd.size() <= z) {
        d = cd;
    }
    else {
        d = cd.substr(cd.size() - z, z);
        c = cd.substr(0, cd.size() - z);
    }

    string ac = a*c,
        bd = b*d,
        bc_ad = (a + b)*(c + d) - (ac + bd);
    if (ac != "0")
        for (int i = 0; i < 2*z; i++)
            ac.append("0");
    ac = ac + bd;
    if (bc_ad != "0")
        for (int i = 0; i < z; i++)
            bc_ad.append("0");
    return ac + bc_ad;
}

string operator^(string a, int n) {
    string res("1");
    for (; n; n /= 2, a = a*a)
        if (n % 2) res = res * a;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string a;
    int b;
    cin >> a >> b;
    cout << (a^b);

}