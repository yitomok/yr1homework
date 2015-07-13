using System;
using System.Collections.Generic;
using CodEx;

namespace ConsoleApplication5
{
    class Task5
    {
        static void Main(string[] args)
        {
            List<string> p = new List<string>();
            List<string> s = new List<string>();

            p.InsertRange(0, Reader.Console().Line().Trim().Split());
            p.Reverse();

            int o1, o2;
            foreach (string e in p)
                switch (e)
                {
                    case "+":
                    case "-":
                    case "*":
                    case "/":
                        if (Int32.TryParse(s[s.Count - 1], out o1) && Int32.TryParse(s[s.Count - 2], out o2))
                        {
                            s.RemoveAt(s.Count - 1);
                            s.RemoveAt(s.Count - 1);
                            if (e.Equals("+"))
                                s.Add(o1 + o2 + "");
                            if (e.Equals("-"))
                                s.Add(o1 - o2 + "");
                            if (e.Equals("*"))
                                s.Add(o1 * o2 + "");
                            if (e.Equals("/"))
                                s.Add(o1 / o2 + "");
                        }
                        else
                        {
                            Console.Write("ERROR");
                            return;
                        }
                        break;
                    default:
                        s.Add(e);
                        break;
                }

            Console.Write(s[0]);
        }
    }
}
