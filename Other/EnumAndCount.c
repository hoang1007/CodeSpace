#include <stdio.h>
#include <string.h>

char arr[100001][10];

int read()
{
    int size = 0;
    for (; scanf("%s", arr[size]) != EOF; size++);
    return size;
}

int notDecrease(char s[10])
{
    for (int i = 0; s[i + 1] != '\0'; s++)
        if (s[i] > s[i + 1]) return 0;
    return 1;
}

int isNumber(char s[10])
{
    if (s[0] < '0' || s[0] > '9') return 0;
    return 1;
}

int main()
{
    const int size = read();
    printf("size %d", size);
    char freq[size][size][10];

    int max_freq = 0;
    for (int i = 0; i < size - 1; i++)
    {
        if (notDecrease(arr[i]))
        {
            int count = 1;
            for (int j = i + 1; j < size; j++)
                if (strcmp(arr[i], arr[j]) == 0)
                {
                    count++;
                    strcpy(arr[j], "erase");
                }
            
            if (max_freq < count) max_freq = count;

            for (int j = 0; ; j++)
                if (!isNumber(freq[count][j]))
                {
                    strcpy(freq[count][j], arr[i]);
                    break;
                }
        }
    }

    for (; max_freq >= 0; max_freq--)
        for (int i = 0; isNumber(freq[max_freq][i]); i++)
            printf("%s %d\n", freq[max_freq][i], max_freq);
    return 0;
}