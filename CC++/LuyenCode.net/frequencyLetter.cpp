#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);	cout.tie(0);
    
    string s;	getline(cin, s);
    map<char, int> freq;
    for (int i = 0; i < s.size(); i++) {
        if ('a' <= s[i] && s[i] <= 'z') freq[s[i]]++;
        else if ('A' <= s[i] && s[i] <= 'Z') freq[s[i] + 32]++;
        else if 
    }
    for (auto i = freq.begin(); i != freq.end(); i++)
        cout << i->first << " " << i->second << endl;
}