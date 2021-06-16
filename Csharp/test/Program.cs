using System;
using System.Collections.Generic;

namespace test
{
    class Program
    {
        public static void Main(string[] args)
        {
            var res = Kata.FindAll(35, 6);
            foreach (var item in res) 
                Console.WriteLine(item);
        }
    }

    public class Kata
    {
        private static List<long> res = new List<long>();
        public static List<long> FindAll(int sumDigits, int numDigits)
        {
            FindAll(sumDigits, numDigits, 0);
            return res.Count == 0 ? res : new List<long>() {res.Count, res[0], res[res.Count - 1]};
        }
        private static void FindAll(int sumDigits, int numDigits, long k)
        {
            if (numDigits == 0)
            {
                if (sumDigits == 0)
                    res.Add(k);
                return;
            }
            if (sumDigits <= 0) return;
            for (int i = 1 > k % 10 ? 1 : (int)k % 10; i <= 9; i++)
                FindAll(sumDigits - i, numDigits - 1, 10*k + i);
        }
    }
}