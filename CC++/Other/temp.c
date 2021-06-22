#include <stdio.h>

const int N = 100;

int sum_of_odd_divisible_by_three(int n, int arr[][N]);
double average_of_subdiagonal(int n, int arr[][N]);
void show_2nd_column(int n, int arr[][N]);

int main() {
    int n;
    scanf("%d", &n);

    int arr[n][N];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    
    printf("Tong cac so le duong chia het cho 3 la: %d\n", sum_of_odd_divisible_by_three(n, arr));
    printf("Trung binh cong cac so tren duong cheo phu la: %.2lf\n", average_of_subdiagonal(n, arr));
    printf("Cac phan tu o cot 2 la:\n"); show_2nd_column(n, arr);
}

int sum_of_odd_divisible_by_three(int n, int arr[][N]) {
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (arr[i][j] > 0 && arr[i][j] % 3 == 0)
                res += arr[i][j];
    return res;
}

double average_of_subdiagonal(int n, int arr[][N]) {
    int size = n*n - 4;
   
    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            sum += arr[i][j];
    sum -= arr[0][0] + arr[0][n - 1] + arr[n - 1][0] + arr[n - 1][n - 1];

    if (n % 2) {
        sum -= arr[n/2][n/2];
        size--;
    }

    return (double) sum / size;
}

void show_2nd_column(int n, int arr[][N]) {
    if (n < 2) {
        printf("invalid");
        return ;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i][1]);
}