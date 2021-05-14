#include <iostream>
using namespace std;

string text(int n)
{
    switch (n)
    {
    case 0:
        return "khong";
    case 1:
        return "mot";
    case 2:
        return "hai";
    case 3:
        return "ba";
    case 4:
        return "bon";
    case 5:
        return "nam";
    case 6:
        return "sau";
    case 7:
        return "bay";
    case 8:
        return "tam";
    case 9:
        return "chin";
    default:
        break;
    }
    return "";
}
int main()
{
    int n;  cin >> n;
    cout << text(n);
}