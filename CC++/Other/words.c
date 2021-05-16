#include <stdio.h>

int main() {
    int t;  scanf("%d", &t);
    while(t--) {
        char s[200];
        char x = ' ';
        int count = 0;
        while (x == ' ') {
            scanf("%s%c", s, &x);
            count++;
        }
        printf("%d\n", count);
    }
}