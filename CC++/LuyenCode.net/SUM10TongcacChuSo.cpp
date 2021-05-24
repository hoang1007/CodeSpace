#include <cstdio>
#include <string.h>

int count = 0;

void countSumDigitsEqualS(int totalDigits, int sum) {
    if (totalDigits == 0 && sum == 0) {
        count++;
        return ;
    }
    else if (sum < 0) return ;
    else if (sum && totalDigits == 0)   return ;
    else {
        for (int i = 0; i < 10; i++)
            countSumDigitsEqualS(totalDigits - 1, sum - i);
    }
}

int main() {
    int totalDigits = 5;
    int sum = 21;
    for (int i = 1; i < 10; i++)
        countSumDigitsEqualS(totalDigits - 1, sum - i);
    printf("%d", count);
}