#include <stdio.h>

int main()
{
    int n;  scanf("%d", &n);
    const int size = n;

    int arr[size][size];
    int max = -1e5;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &arr[i][j]);
            if (max < arr[i][j]) max = arr[i][j];   // tim max
        }
    
    // hai duong cheo chinh co phuong trinh la x + y = size - 1 & x - y = 0
    int sumEvenCross = 0, sumOddLine = 0;

    for (int i = 0; i < size; i++)  // tinh tong chan tren duong cheo
        for (int j = 0; j < size; j++)
            if (i + j == size - 1 || i == j)
                if (arr[i][j] % 2 == 0)
                {
                    sumEvenCross += arr[i][j];
                    printf("%d ", arr[i][j]);
                }
    for (int i = 0; i < size; i++)  // tinh tong le tren dong 2
        if (arr[1][i] % 2)  sumOddLine += arr[1][i];
    
    printf("\nTong cac phan tu chan tren duong cheo chinh la: %d\n", sumEvenCross);
    printf("Tong cac so le tren dong hai la: %d\n", sumOddLine);
    printf("Phan tu lon nhat cua mang: %d", max);
}