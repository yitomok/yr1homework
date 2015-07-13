using System;
using CodEx;

namespace ConsoleApplication2
{
    class Task2
    {
        static void Main(string[] args)
        {
            int max = Int32.MinValue;
            int[] inputs = new int[Reader.Console().Int()];
            for (int i = 0; i < inputs.Length; i++)
            {
                inputs[i] = Reader.Console().Int();
                if (inputs[i] >= max) max = inputs[i];
            }
            Console.WriteLine(max);
            for (int i = 0; i < inputs.Length; i++)
            {
                if (inputs[i] == max) Console.Write((i + 1) + " ");
            }
        }
    }
}
