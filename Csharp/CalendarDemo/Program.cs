using System;

namespace CalendarDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Nhap thang, nam (MM/YYYY): ");
            string[] tokens = Console.ReadLine().Split();

            int month = int.Parse(tokens[0]),
                year = int.Parse(tokens[1]);
            
            Calendar calendar = new Calendar(month, year);
            calendar.callCalendar();
        }
    }
}
