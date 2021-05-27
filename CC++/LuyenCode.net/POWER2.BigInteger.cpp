#include <iostream>
using namespace std;

struct bInt {
    string data;
    bInt(string value) : data(value) {}
    bInt operator+(const bInt &src);

    bInt operator*(const bInt &src);
    bInt operator^(int pow);
    friend ostream& operator<<(ostream &out, const bInt& src) {
        out << src.data;
        return out;
    }
private:
    string mulSingle(const char &src);
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    bInt a("1000000000");

    cout << (a^1000);
}

bInt bInt::operator+(const bInt &_src) {
    string src = _src.data;
    if (data.size() == 0 || src.size() == 0) return bInt("0");
    if (data == "0") return _src;
    if (src == "0") return bInt(data);
    string res;
    res.resize(data.size() > src.size() ? data.size() : src.size());

    int carry = 0;

    int i_data = data.size() - 1;
    int i_src = src.size() - 1;
    int i_res = res.size() - 1;
    for (; i_src >= 0 || i_data >= 0; i_src--, i_data--, i_res--) {
        int digitSrc = 0, digitData = 0;
        if (i_src >= 0) digitSrc = src[i_src] - '0';
        if (i_data >= 0) digitData = data[i_data] - '0';
        char sumDigit = (digitSrc + digitData + carry) % 10 + '0';
        res[i_res] = sumDigit;
        carry = (digitSrc + digitData + carry) / 10;
    }

    return bInt(carry > 0 ? char(carry + 48) + res : res);
}

bInt bInt::operator*(const bInt &_src) {
    string src = _src.data;
    if (src == "0" || data == "0") return bInt("0");

    bInt res("0");
    string carry = "";
    for (int i = src.size() - 1; i >= 0; i--, carry += "0") {
        bInt mul = bInt(mulSingle(src[i]) + carry);
        res = res + mul;
    }
    return res;
}

string bInt::mulSingle(const char& src) {
    if (data.size() == 0 || src == '0') return "0";
    string res;
    res.resize(data.size());

    int carry = 0;
    for (int i = data.size() - 1; i >= 0; i--) {
        int mul = (src - '0')*(data[i] - '0');
        char digitRes = (carry + mul) % 10 + '0';
        res[i] = digitRes;
        carry = (mul + carry)/10;
    }

    return carry > 0 ? char (carry + '0') + res : res;
}

bInt bInt::operator^(int pow) {
    bInt res("1");
    bInt a = bInt(data);
    for (; pow; pow /= 2, a = a*a)
        if (pow % 2) res = res * a;
    return bInt(res);
}