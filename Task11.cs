using System;
using CodEx;

namespace ConsoleApplication11
{
    class Task11
    {
        static void Main(string[] args)
        {
            int K = Reader.Console().Int();
            int L = Reader.Console().Int();
            int[] a = new int[L];
            int[] b = new int[L];

            if (K == 1 || L == 1)
                Console.WriteLine(L);
            else
            {
                for (int i = 0; i < L; i++)
                    a[i] = b[i] = 1;

                for (int i = 0; i < K - 1; i++)
                {
                    for (int j = 0; j < L; j++)
                    {
                        if (j - 1 >= 0)
                            b[j] += a[j - 1];
                        if (j + 1 < L)
                            b[j] += a[j + 1];
                    }
                    for (int j = 0; j < L; j++)
                        a[j] = b[j];
                }
                int s = 0;
                for (int i = 0; i < L; i++)
                    s += a[i];
                Console.Write(s);
            }
        }
    }
}
