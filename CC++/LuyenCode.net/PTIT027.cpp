#include <stdio.h>

int main() {
    int t;  scanf("%d", &t);
    char s[100001];
    while (t--) {
        scanf("%*[\n]%[^\n]", s);
        int brackets = 0;
        int count = 0;
        int max = 0;
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '(') brackets++;
            else if (s[i] == ')') {
                if (brackets) {
                    brackets--;
                    count++;
                }
                else {
                    if (max < count) max = count;
                    count = 0;
                }
            }
        }
        if (max < count) max = count;
        printf("%d\n", 2*max);
    }
}