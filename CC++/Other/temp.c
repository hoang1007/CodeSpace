#include <stdio.h>

int main()
{
    int max[] = {-100000, -100000, -100000};
    int min[] = {100000, 100000, 100000};

    int n;
    scanf("%d", &n);
    while (n--)
    {
        int x;
        scanf("%d", &x);
        // -> max <-
        for (int i = 0; i < 3; i++)
            if (max[i] < x)
            {
                for (int j = 1; j >= i; j--)
                    max[j + 1] = max[j];
                max[i] = x;
                break;
            }

        // -> min <-
        for (int i = 0; i < 3; i++)
            if (min[i] > x)
            {
                for (int j = 1; j >= i; j--)
                    min[j + 1] = min[j];
                min[i] = x;
                break;
            }
    }

    int p1 = max[0] * max[1] * max[2], p2 = min[0] * min[1] * max[0];
    printf("%d", p1 > p2 ? p1 : p2);
}