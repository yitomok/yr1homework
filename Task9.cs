using System;
using System.Collections.Generic;
using CodEx;

namespace ConsoleApplication9
{
    class Task9
    {
        static List<string> o = new List<string>(new string[] { "(", "[", "/*", "<!", "($", "<<" });
        static List<string> c = new List<string>(new string[] { ")", "]", "*/", "!>", "$)", ">>" });

        static bool eval(string expr)
        {
            if (expr.Equals(""))
                return true;

            List<string> s = new List<string>(expr.Split());

            if (s.Count % 2 == 1 || c.Contains(s[0]) || o.Contains(s[s.Count - 1]))
                return false;

            List<string> buf = new List<string>(s.Count);
            foreach (string e in s)
            {
                if (o.Contains(e))
                    buf.Add(e);
                else if (o[c.IndexOf(e)].Equals(buf[buf.Count - 1]))
                    buf.RemoveAt(buf.Count - 1);
                else
                    return false;                    
            }

            if (buf.Count > 0)
                return false;

            return true;
        }

        static void Main(string[] args)
        {
            Reader r = new Reader("zavorky.in");
            while (!r.EOF())
                Console.WriteLine(Task9.eval(r.Line().Trim()).ToString().ToLower());
            r.Close();
        }
    }
}
