#include <iostream>
#include <string>
using namespace std;
int main()
{
    std::string p = "vai lon";
    std::string s = "You are young.You are young.";

    for (int i = 0; i < s.length(); i++)
        if (s[i] == '\n' )
            std::cout << i << " ";
}