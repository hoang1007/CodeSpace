#include <stdio.h>

int main()
{
    int rect1[4], rect2[4];

    for (int i = 0; i < 4; i++)
        scanf("%d", &rect1[i]);

    for (int i = 0; i < 4; i++)
        scanf("%d", &rect2[i]);
    
    int spanningSquare[4];
    for (int i = 0; i < 2; i++)
        spanningSquare[i] = rect1[i] < rect2[i] ? rect1[i] : rect2[i];
    
    for (int i = 2; i < 4; i++)
        spanningSquare[i] = rect1[i] > rect2[i] ? rect1[i] : rect2[i];

    int xSize = spanningSquare[0] - spanningSquare[2],
        ySize = spanningSquare[1] - spanningSquare[3];
    
    printf("%d", xSize*xSize > ySize*ySize ? xSize*xSize : ySize*ySize);
}