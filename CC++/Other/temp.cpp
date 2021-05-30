#include <stdio.h>

int main() {
    int n;	scanf("%d", &n);
    while (n--) {
        char a[1001];
        scanf("%*[\n]%[^\n]", a);
        int count = 0;
        for (int i = 0; a[i] != '\0'; i++)
            if (a[i] == ' ' && a[i + 1] != ' ') count++;
        printf("%d\n", count);
    }
}