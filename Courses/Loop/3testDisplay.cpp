#include <iostream>
#include "font.h"
#include <map>
using namespace std;

void setup(map<char, vector<string>> &sentence)
{
    sentence['a'] = a;
    sentence['k'] = k;
    sentence['e'] = e;
}

int main()
{
    map<char, vector<string>> sentence;
    setup(sentence);
    vector<vector<string>> res;

    string inp = "ake";
    for (int i = 0; i < inp.size(); i++)
        res.push_back(sentence[inp[i]]);
    
    for (int i = 0; i < res[0].size(); i++)
    {
        for (int j = 0; j < res.size(); j++)
            cout << res[j][i];
        cout << endl;
    }
}