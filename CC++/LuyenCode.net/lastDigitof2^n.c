#include <stdio.h>

int main() {
    int n;	scanf("%d", &n);
    if (n == 0) {
        printf("1");
        return 0;
    }
    int arr[] = {2, 4, 8, 6};
    
    int last = n % 5;
    printf("%d", arr[last - 1]);
}