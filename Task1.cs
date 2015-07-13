using System;
using CodEx;

namespace ConsoleApplication1
{
    class Task1
    {
        static void Main(string[] args)
        {
            int a, b;
            a = Reader.Console().Int();
            b = Reader.Console().Int();
            if (b == 0)
                Console.WriteLine("IMPOSSIBLE");
            else
                Console.WriteLine(Convert.ToInt32(a) / Convert.ToInt32(b));
        }
    }
}
