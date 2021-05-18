import java.util.Scanner;

public class POWER2 {
    static class MulString {
        private String mulSingle(String a, char b) {
            int memNum = 0;
            int bNum = Character.getNumericValue(b);
            char aChars[] = a.toCharArray();
            
            for (int i = aChars.length - 1; i >= 0; i--) {
                int mul = Character.getNumericValue(aChars[i])*bNum;
                aChars[i] = Character.forDigit((mul + memNum) % 10, 10 /*is radix*/);
                memNum = (mul + memNum) / 10;
            }
            
            return memNum != 0 ? Integer.toString(memNum) + String.valueOf(aChars) : String.valueOf(aChars);
        }
    
        private String mulString(String a, String b) {
            if (a.length() == 0) return b;
            String res = new String();
            char bChars[] = b.toCharArray();
    
            String aMulB[] = new String[b.length()];
            for (int i = 0; i < aMulB.length; i++)
                aMulB[i] = mulSingle(a, bChars[i]);
            
            // format mul String
            String add = "0";
            for (int i = 1; i < aMulB.length; i++)
                aMulB[0] += add;
            for (int i = 1; i < aMulB.length; i++) {
                for (int j = i + 1; j < aMulB.length; j++)
                    aMulB[i] += add;
                while (aMulB[i].length() != aMulB[0].length())
                    aMulB[i] = add + aMulB[i];
            }
    
            // calculate sum of aMulB
            int memNum = 0;
            for (int i = aMulB[0].length() - 1; i >= 0; i--) {
                int sumDigit = 0;
                for (int j = 0; j < aMulB.length; j++) {
                    sumDigit += Character.getNumericValue(aMulB[j].charAt(i));
                }
                res = Integer.toString((sumDigit + memNum) % 10) + res;
                    memNum = (sumDigit + memNum) / 10;
            }
            return memNum == 0 ? res : Integer.toString(memNum) + res;
        }
        
        public void add(String s) {
            result = mulString(result, s);
        }
        
        public void sqr() {
            result = mulString(result, result);
        }

        public String result;
        MulString() {
            result = new String();
        }
        MulString(String s) {
            result = new String(s);
        }
    }

    // Power return String
    static String pow(int a, int b) {
        MulString powStr = new MulString();
        MulString aSrt = new MulString(Integer.toString(a));
        for (; b > 0; aSrt.sqr(), b /= 2)
            if (b % 2 == 1) powStr.add(aSrt.result);
        return powStr.result;
    }

    static String superPow(int a, int b) {
        MulString strPow = new MulString();

        for (int i = 2; i <= Math.sqrt(a) || a > 1; i++) {
            if (a % i == 0) {
                String powI = pow(i, b);
                while (a % i == 0) {
                    a /= i;
                    strPow.add(powI);
                }
            }
        }
        return strPow.result;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int n = sc.nextInt();
        sc.close();
        System.out.print(superPow(a, n));
    }
}
