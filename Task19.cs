using System;
using CodEx;

namespace ConsoleApplication19
{
    class Task19
    {
        static void Main(string[] args)
        {
            int[] dm = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
            int d1 = Reader.Console().Int();
            int m1 = Reader.Console().Int();
            int y1 = Reader.Console().Int();
            int d2 = Reader.Console().Int();
            int m2 = Reader.Console().Int();
            int y2 = Reader.Console().Int();

            int days = 0;
            for (int i = y1 + 1; i < y2; i++)
                if (i % 4 == 0 && (i % 400 == 0 || i % 100 != 0))
                    days += 366;
                else
                    days += 365;

            if (y1 != y2)
            {
                for (int i = m1 + 1; i <= 12; i++)
                    days += dm[i];
                if (m1 <= 2 && y1 % 4 == 0 && (y1 % 400 == 0 || y1 % 100 != 0))
                    days++;

                days += dm[m1] - d1;

                for (int i = 1; i < m2; i++)
                    days += dm[i];
                if (m2 >= 2 && y2 % 4 == 0 && (y2 % 400 == 0 || y2 % 100 != 0))
                    days++;

                days += d2;
            }
            else
            {
                if (m1 != m2)
                {
                    for (int i = m1 + 1; i < m2; i++)
                        days += dm[i];
                    days += dm[m1] - d1 + d2;
                    if (m1 <= 2 && m2 > 2 && dm[m1] <= d1 && y1 % 4 == 0 && (y1 % 400 == 0 || y1 % 100 != 0))
                        days++;
                }
                else
                    days += d2 - d1;
            }

            Console.Write(days);
        }
    }
}
