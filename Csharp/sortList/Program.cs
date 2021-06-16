using System;

namespace sortList
{
    class Program
    {
        static void Main(string[] args)
        {
            List l = new List(new int[] {3, 1, 4, 6, 5, 9, 10, 7});
            List.Sort.heap(l).print();
        }
    }
}
