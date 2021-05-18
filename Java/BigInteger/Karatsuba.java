public class Karatsuba {
    static class stringCal {
        public String str;
        stringCal() {
            str = new String();
        }
        stringCal(String src) {
            str = new String(src);
        }

        void add(String a) {
            if (str.length() == 0)
                str = a;
            if (a.length() == 0 || a == "0") return ;

            char strArray[] = str.toCharArray(),
                aArray[] = a.toCharArray();
            
            int minLength = Integer.min(str.length(), a.length());
            int carry = 0;

            for (int i = 1; i <= minLength; i++) {
                int sum = Character.getNumericValue(strArray[strArray.length - i]) + Character.getNumericValue(aArray[aArray.length - i]);
                strArray[strArray.length - i] = Character.forDigit((sum + carry) % 10, 10 /*is radix*/);
                carry = (sum + carry) / 10;
            }
            
            str = carry == 0 ? String.valueOf(strArray) : Integer.toString(carry) + String.valueOf(strArray);
        }

        private String mulLower100(String a, String b) {
            return Integer.toString(Integer.valueOf(a)*Integer.valueOf(b));
        }

        String karatsuba(String s) {
            // https://en.wikipedia.org/wiki/Karatsuba_algorithm
            // suppose str = ab, s = cd
            // we divided str = a*B^m + b, s = c*B^m + d (ex: 1234 => 12 and 34)
            // => ab*cd = a*c*B^2m + b*d + (b*c + a*d)*B^m
            
        }
    }
    public static void main(String[] args) {
        stringCal s = new stringCal("7234");
        s.str = s.karatsuba("5678");

        System.out.println(s.str);
    }
}
