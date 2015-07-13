using System;
using System.Collections.Generic;
using CodEx;

namespace ConsoleApplication8
{
    class Task8
    {
        static int suicide(int n, int kill)
        {
            return n == 1 ? 1 : (suicide(n - 1, kill) + kill - 1) % n + 1;
        }
        static int suicide(int n)
        {
            return 2 * (n - (int) Math.Pow(2.0, Math.Floor(Math.Log(n, 2)))) + 1;
        }
        static void Main(string[] args)
        {
            int n = Reader.Console().Int();
            if (n <= 0)
                Console.Write("ERROR");
            else
                //Console.Write(suicide(n, 2));
                Console.Write(suicide(n));
        }
    }
}
