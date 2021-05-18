#include <stdio.h>

int main() {
    char s[100];
    char hello[] = {'h', 'e', 'l', 'l', 'o'};

    scanf("%s", s);
    int needFind = 0;
    int i = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == hello[needFind]) {
            needFind++;
            continue;
        }
    }

    printf("%s", needFind == 5 ? "YES": "NO");
}