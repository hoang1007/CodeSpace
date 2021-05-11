#include<stdio.h>

void drawRectangle(int row, int col)
{
    for (int i = 1; i <= row; i++)
    {
        int copy = i;
        if (i > col && i <= row)
        {
            printf("%d ", i);
            i = col;
        }
        else for (int j = i; j <= col; j++)
            printf("%d ", j);
        for (int j = i - 1; j > 0 && j <= col; j--)
            printf("%d ", j);
        printf("\n");
        i = copy;
    }
}

int main()
{
    int row, col;
    //scanf("%d %D", &row, &col);
    drawRectangle(6, 4);
}