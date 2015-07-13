using System;
using CodEx;

namespace ConsoleApplication10
{
    class Task10
    {
        static void Main(string[] args)
        {
            int K = Reader.Console().Int();
            int[] s = new int[K];
            int[] a = new int[K];
            int[] b = new int[K];
            int l;

            for (int i = 0; i < K; i++)
                s[i] = Reader.Console().Int();

            for (int i = 0; i < K; i++)
            {
                l = 0;
                for (int j = 0; j < i; j++)
                    if (s[i] >= s[j] && a[j] > l)
                        l = a[j];
                a[i] = l + 1;
            }

            for (int i = K - 1; i >= 0; i--)
            {
                l = 0;
                for (int j = K - 1; j >= i; j--)
                    if (s[i] <= s[j] && b[j] > l)
                        l = b[j];
                b[i] = l + 1;
            }

            l = a[K - 1];
            for (int i = 0; i < K - 1; i++)
                for (int j = i + 1; j < K; j++)
                    if (a[i] + b[j] > l)
                        l = a[i] + b[j];
            Console.WriteLine(l);
        }
    }
}
