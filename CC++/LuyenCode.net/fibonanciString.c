#include <stdio.h>

int main() {
    int t;  scanf("%d", &t);
    while (t--) {
        int n,  i;  scanf("%d%d", &n, &i);
        if (n % 2) {
            if (i % 2) printf("A\n");
            else printf("B\n");
        }
        else {
            if (i % 2) printf("B\n");
            else printf("A\n");
        }
    }
}