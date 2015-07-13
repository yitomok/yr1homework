using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;
using CodEx;

namespace ConsoleApplication7
{
    class Task7
    {
        static void Main(string[] args)
        {
            List<string> p = new List<string>();
            List<string> s = new List<string>();

            string buf;
            while (!Reader.Console().EOF())
            {
                buf = Regex.Replace(Reader.Console().Line().Trim(), "[\\+\\-\\*\\/]", delegate(Match match)
                {
                    return " " + match + " ";
                }).Trim();
                buf = Regex.Replace(buf, "[^0-9^\\+^\\-^\\*^\\/]+", " ").Trim();
                p.InsertRange(p.Count, buf.Split());
            }

            int o1, o2;
            foreach (string e in p)
                switch (e)
                {
                    case "+":
                    case "-":
                    case "*":
                    case "/":
                        if (s.Count >= 2 && Int32.TryParse(s[s.Count - 2], out o1) && Int32.TryParse(s[s.Count - 1], out o2))
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
                            Console.Write("Error!");
                            return;
                        }
                        break;
                    default:
                        s.Add(e);
                        break;
                }

                Console.Write(s.Count == 1 ? s[0] : "Error!");
        }
    }
}
