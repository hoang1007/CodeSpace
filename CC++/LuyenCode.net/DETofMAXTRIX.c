#include <stdio.h>

int det2x2(int matrix[3][3], int col) {
    if (col == 0) return matrix[1][1]*matrix[2][2] - matrix[1][2]*matrix[2][1];

    if (col == 1) return matrix[1][0]*matrix[2][2] - matrix[1][2]*matrix[2][0];

    if (col == 2) return matrix[1][0]*matrix[2][1] - matrix[1][1]*matrix[2][0];
    return 0;
}

int det3x3(int matrix[3][3]) {
    return matrix[0][0]*det2x2(matrix, 0) - matrix[0][1]*det2x2(matrix, 1) + matrix[0][2]*det2x2(matrix, 2);
}

int main() {
    int matrix[3][3];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &matrix[i][j]);
    
    printf("%d", det3x3(matrix));
}