#include <iostream>
using namespace std;

bool isVowels[26] = {false};

int solve(string str, int i, int vowel, int consonant, bool hasL) {
    if (vowel == 3 || consonant == 3) return 0;

    for (; i < str.length() && str[i] != '_'; i++) {
        if (isVowels[str[i] - 'A']) ++vowel, consonant = 0;
        else vowel = 0, ++consonant;
        
        if (vowel == 3 || consonant == 3) return 0;
    }

    if (str[i] != '_') {
        if (hasL) {
            cout << str << " ";
            return 1;
        }
        return 0;
    }
    
    int count = 0;

    str[i] = 'A';
    count += solve(str, i + 1, vowel + 1, 0, hasL)*5;    //vowels
    str[i] = 'L';
    count += solve(str, i + 1, 0, consonant + 1, true);   // L
    str[i] = 'B';
    count += solve(str, i + 1, 0, consonant + 1, hasL)*20; // consonants except L

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    isVowels['U' - 'A'] = isVowels['E' - 'A'] = isVowels['O' - 'A'] = isVowels['A' - 'A'] = isVowels['I' - 'A'] = true;

    string str; cin >> str;
    bool hasL = false;
    for (char i : str)
        if (i == 'L') {
            hasL = true;
            break;
        }

    cout << solve(str, 0, 0, 0, hasL);
}