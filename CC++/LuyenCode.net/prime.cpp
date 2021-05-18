#include <stdio.h>
#include <math.h>

int main() {
    int left, right;
    scanf("%lld %lld", &left, &right);
    
    int leftBound = sqrt(left),
    	rightBound = sqrt(right);
    int carry = 0;
    if (leftBound*leftBound == left) carry = 1;
    printf("%d", rightBound - leftBound + carry);
}