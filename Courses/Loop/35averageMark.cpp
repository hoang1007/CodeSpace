#include <stdio.h>

int main()
{
    double sum = 0.0;
    int size = 0;
    while (true)
    {
        double mark;
        scanf("%lf", &mark);
        if (mark > 10) continue;
        else if (mark < 0) break;
        else
        {
            sum += mark;
            size++;
        }
    }

    printf("%.2lf", sum/size);
}