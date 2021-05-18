import java.util.Scanner;

public class FH_07_06 {
    static void rectangleLine(int n) {
        int dist = 4;
        int k = n;
        for (; n > 0; n--, dist--) {
            System.out.print(k + " ");
            k += dist;
        }
        System.out.print("\n");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 1; i <= n; i++)
            rectangleLine(i);
        sc.close();
    }
}
