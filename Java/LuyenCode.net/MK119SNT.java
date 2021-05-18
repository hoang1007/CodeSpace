import java.util.Arrays;
import java.util.Scanner;

public class MK119SNT {
    static final int MAX = (int) (1e6 + 5);
    static int countPrime[] = new int[MAX];
    static void sieve(int n) {
        countPrime[0] = countPrime[1] = 0;
        for (int i = 2; i <= Math.sqrt(n); i++)
            for (int j = i*i ; j <= n; j += i)
                countPrime[j] = 0;
        for (int i = 2; i < countPrime.l - 1; i++)
            countPrime[i] += countPrime[i - 1];
    }
    public static void main(String[] args) {
        Arrays.fill(countPrime, 1);

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        int maxValue = 0;
        int test[][] = new int[t][2];
        for (int i = 0; i < t; i++) {
            test[i][0] = sc.nextInt();
            test[i][1] = sc.nextInt();
            if (test[i][1] > maxValue) maxValue = test[i][1];
        }

        sieve(maxValue);

        for (int i = 0; i < t; i++)
            System.out.println(countPrime[test[i][1]] - countPrime[test[i][0] - 1]);
        sc.close();
    }
}
