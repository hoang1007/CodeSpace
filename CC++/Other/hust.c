#include <stdio.h>
#include <string.h>
#include <malloc.h>

char text[61][81];
int line = 0;

void read() {
    for (; fgets(text[line], 80, stdin); line++);
}

int countWord() {
    int count = 0;
    for (int i = 0; i < line; i++) {
        for (int j = 0; text[i][j] != '\0'; j++)
            if (text[i][j] == '\n' || (text[i][j] == ' ' && text[i][j + 1] != ' ')) count++;
    }
    return count;
}

void replace() {
    const char hanoi[] = {'h', 'a', 'n', 'o', 'i'};
    
    for (int i = 0; i < line; i++) {
        for (int j = 0; j <= 80 || text[i][j] != '\0'; j++) {
            int found = 1;
            for (int a = 0; a < 5; a++) {
                if (text[i][j + a] != hanoi[a]) {
                    found = 0;
                    break;
                }
            }
            if (found) {
                for (int a = 0; a < 5; a++)
                    text[i][j + a] = hanoi[a] - 32;
                j += 5;
            }
        }
    }
}

void find() {
    char s[100];
    scanf("%s", s);
    int len = (int) strlen(s);

    for (int i = 0; i < line; i++) {
        for (int j = 0; j <= 80 || text[i][j] != '\0'; j++) {
            int found = 1;
            for (int a = 0; a < len; a++) {
                if (text[i][j + a] != s[a]) {
                    found = 0;
                    break;
                }
            }
            if (found) {
                printf("Xuat hien o dong %d ki thu thu %d\n", i, j);
                return ;
            }
        }
    }
    printf("Not found\n");
}

void substr(char* dst, char* src, int begin) {
    if (src != NULL) {
        int i = 0;
        for (; src[begin + i] != ' ' && src[begin + i] != '\0' && src[begin + i] != '\n'; i++)
            dst[i] = src[begin + i];
        dst[i] = '\0';
    }
}

int main() {
    read();
    replace();
    for (int i = 0; i < line; i++)
        printf("%s", text[i]);
    printf("\n\nSo dong: %d\n", line);
    printf("So tu: %d\n", countWord());
    find();

    char s[] = {'e', 'm', '\0'};
    char find[100];

    int count = 0;
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < 80 && text[i][j] != '\0'; j++)
            if (text[i][j] == ' ' && text[i][j + 1] != ' ') {
                substr(find, text[i], j + 1);
                if (strcmp(s, find) == 0) count++;
            }
    }
    printf("\nSo lan xuat hien cua %s la %d", s, count);
}