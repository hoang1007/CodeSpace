#include <stdio.h>

int main()
{
    char s[10];
    scanf("%s", s);

    int sum = 0;
    for (int i = 0; s[i] != '\0'; i++)
        sum += s[i] - 48;
    printf("%d", sum);
}