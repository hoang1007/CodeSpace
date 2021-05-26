using System;

class Calculator {
    public int power(int n, int p) {
        if (n < 0 || p < 0) {
            throw new Exception("vai lon");
        }
        int res = 1;
        for (; p > 0; p /= 2, n *= n)
            if (p % 2 == 1) res *= n;
        return res;
    }
}

class Solution{
    static void Main(String[] args){
        Calculator myCalculator=new  Calculator();
        int T=Int32.Parse(Console.ReadLine());
        while(T-->0){
            string[] num = Console.ReadLine().Split();
            int n = int.Parse(num[0]);
            int p = int.Parse(num[1]); 
            try{
                int ans=myCalculator.power(n,p);
                Console.WriteLine(ans);
            }
            catch(Exception e){
               Console.WriteLine(e.Message);

            }
        }
        
        
        
    }
}