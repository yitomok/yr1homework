using System;
using CodEx;

namespace ConsoleApplication3
{
    class Task3
    {
        static int[] move_x = { -1, 1, -2, 2, -2, 2, -1, 1 };
        static int[] move_y = { -2, -2, -1, -1, 1, 1, 2, 2 };
        static int size = 8;

        static bool move(int[,] board, int m, int n, int sx, int sy, int moves)
        {
            int next_x, next_y;

            if (moves == m * n)
                return true;

            for (int i = 0; i < size; i++)
            {
                next_x = sx + move_x[i];
                next_y = sy + move_y[i];

                if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && board[next_x, next_y] == 0) {
                    board[next_x, next_y] = 1;
                    if (move(board, m, n, next_x, next_y, moves + 1))
                    {
                        return true;
                    }
                    else
                    {
                        board[next_x, next_y] = 0;
                    }
                }
            }
            return false;
        }

        static void Main(string[] args)
        {
            int m = Reader.Console().Int();
            int n = Reader.Console().Int();
            int sx = Reader.Console().Int();
            int sy = Reader.Console().Int();
            if (m >= 20 || n >= 20 || sx > m || sy > n)
            {
                Console.WriteLine("NO");
                return;
            }
            int[,] board = new int[m, n];
            board[sx - 1, sy - 1] = 1;
            if (move(board, m, n, sx - 1, sy - 1, 1))
            {
                Console.WriteLine("YES");
            }
            else
            {
                Console.WriteLine("NO");
            }
        }
    }
}
