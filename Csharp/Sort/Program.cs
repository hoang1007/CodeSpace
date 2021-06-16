using System;

namespace sort
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] arr = {2, 1, 3, 5, 7, 4, 10, 0, 8};
            Sort iSort = new Sort();
            arr = iSort.merge(arr);

            foreach (int item in arr) 
                Console.Write(item + " ");
        }
    }
}
