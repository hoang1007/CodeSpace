using System;
namespace CalendarDemo
{
    public enum Day {Sat, Sun, Mon, Tue, Wed, Thur, Fri};

    static class Extensions
    {
        public static string getString(this Day day) 
        {
            switch(day)
            {
                case Day.Sat: return "Sat";
                case Day.Sun: return "Sun";
                case Day.Mon: return "Mon";
                case Day.Tue: return "Tue";
                case Day.Wed: return "Wed";
                case Day.Thur: return "Thu";
                case Day.Fri: return "Fri";
            }
            return day.ToString();
        }
    }
    public class Calendar
    {
        int month, year;
        bool leapYear;
        int countDayOfMonth;

        public Calendar(int month, int year)
        {
            this.month = month;
            this.year = year;
            leapYear = isLeapYear();

            if (month == 2)
                countDayOfMonth = leapYear ? 29 : 28;
            else if (month < 8)
                countDayOfMonth = month % 2 == 0 ? 30 : 31;
            else
                countDayOfMonth = month % 2 == 0 ? 31 : 30;
        }

        public bool LeapYear 
        {
            get => leapYear;
        }

        bool isLeapYear()
        {
            if (year % 400 == 0) return true;
            if (year % 4 == 0 && year % 100 != 0) return true;
            return false;
        }

        int findFirstDayofMonth()
        {
            // follow Zeller's algorithms
            // https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week
            int Y = month == 1 || month == 2 ? year - 1 : year,
                y = Y % 100,    // first two digits of Y
                c = Y / 100,    // last two digits of Y
                d = 1,          // day of the month (= 1 since we finding the first day)
                m = month == 1 || month == 2 ? month + 12 : month;  // is the shifted month (March=3,...January = 13, February=14)
            
            return ((13*(m + 1)/5 + y/4 + c/4 + d + y - 2*c) % 7);
        }

        public void callCalendar()
        {
            int begin = findFirstDayofMonth();
            int countDay = 1;
            
            for (int i = 0; i < 7; i++)
                Console.Write(Extensions.getString((Day) i) + "\t");
            Console.WriteLine();

            for (int i = 0; i < 7; i++)
                if (i < begin) Console.Write("     \t");
                else
                    Console.Write(countDay++ + "     \t");
            Console.WriteLine();

            for (int endline = 1; countDay <= countDayOfMonth; endline++)
            {
                Console.Write(countDay++ + "     \t");
                if (endline % 7 == 0) Console.WriteLine();
            }
        }
    }
}