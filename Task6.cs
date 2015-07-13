using System;
using CodEx;

namespace ConsoleApplication6
{
    class Task6
    {
        static void Main(string[] args)
        {
            int sign = 0;
            int l = 0;
            int a = 0;
            int b = 1;
            char[] buf = { '0', '0', '0' };

            while ((buf[0] != '\r' && buf[0] != '\n') || (buf[1] != '\r' && buf[1] != '\n') || (buf[2] != '\r' && buf[2] != '\n'))
            {
                buf[0] = Reader.Console().Char();
                if (buf[0] == '-')
                {
                    sign = -1;
                    l--;
                }
                if (buf[0] == '\r' || buf[0] == '\n')
                {
                    a = Int32.Parse(buf[1] + "" + buf[2]);
                    break;
                }
                l++;
                buf[1] = Reader.Console().Char();
                if (buf[1] == '\r' || buf[1] == '\n')
                {
                    a = Int32.Parse(buf[2] + "" + buf[0]);
                    break;
                }
                l++;
                buf[2] = Reader.Console().Char();
                if (buf[2] == '\r' || buf[2] == '\n')
                {
                    a = Int32.Parse(buf[0] + "" + buf[1]);
                    break;
                }
                l++;
            }

            if (sign < 0)
                a = -a;

            while (!Reader.Console().EOF())
            {
                char tmp = Reader.Console().Char();
                if (tmp == '1')
                    b = (a * b * b) % 100;
                else if (tmp == '0')
                    b = (b * b) % 100;
            }

            Console.Write("{0:D2}", Math.Abs(b));
        }
    }
}
