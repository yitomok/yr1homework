using System;
using System.Collections.Generic;
using CodEx;

// hint: system continuously changing the base, i.e. factorial number system
namespace ConsoleApplication4
{
    class Task4
    {
        static void Main(string[] args)
        {
            int n = Reader.Console().Int();
            int k = Reader.Console().Int();
            int[] p = new int[n];

            int[] f = new int[n];

            int[] m = new int[n];
            List<int> s = new List<int>(n);

            m[n - 1] = 1;
            for (int i = 1; i < n; i++)
                m[n - i - 1] = m[n - i] * i;

            for (int i = 0; i < n; i++)
            {
                p[i] = Reader.Console().Int();
                f[i] = 0;
                s.Add(i + 1);
            }

            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++)
                    if (p[i] > p[j])
                        f[i]++;

            for (int i = 0; i < n; i++)
                k += f[i] * m[i];

            for (int i = 0; i < n; i++)
            {
                f[n - i - 1] = k % (i + 1);
                k /= i + 1;
            }

            foreach (int e in f)
            {
                Console.Write(s[e] + " ");
                s.RemoveAt(e);
            }
        }
    }
}
