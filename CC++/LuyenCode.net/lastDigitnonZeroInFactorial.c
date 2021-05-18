#include<stdio.h>

int dig[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};

int lastNon0Digit(int n)
{
	if (n < 10)
		return dig[n];

	if (((n/10)%10)%2 == 0)
		return (6*lastNon0Digit(n/5)*dig[n%10]) % 10;
	else
		return (4*lastNon0Digit(n/5)*dig[n%10]) % 10;
}

// Driver code
int main()
{
	int n;  scanf("%d", &n);
    printf("%d", lastNon0Digit(n));
	return 0;
}
