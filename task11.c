#include <stdio.h>
#include <stdlib.h>

#define YES "YES"
#define NO "NO"

// xy coordinate for knight movement on board
int move_x[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int move_y[] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int ** alloc_board(int m, int n) {
	int i;
	int **board = NULL;

	board = calloc(m, sizeof(int *));

	if (board == NULL) {
		printf("NO");
		exit(1);
	}

	for (i = 0; i < m; i++) {
		*(board + i) = calloc(n, sizeof(int));

		if (*(board + i) == NULL) {
			printf("NO");
			exit(1);
		}
	}

	return board;
}

void free_board(int **board, int n) {
	int i;

	for (i = 0; i < n; i++) {
		free(*(board + i));
	}
	free(board);
}

int move(int **board, int m, int n, int sx, int sy) {
	int i, j;
	int next_x, next_y;
	int stack_x[m * n], stack_y[m * n], stack_move[m * n];

	for (i = 0; i < m * n; i++) {
		stack_move[i] = 0;
	}

	stack_x[0] = sx;
	stack_y[0] = sy;

	i = 1;

	while (i < m * n && stack_move[0] < ((int) (sizeof(move_x) / sizeof(int)))) {
		j = stack_move[i - 1]++;

		while (j < sizeof(move_x) / sizeof(int)) {
			next_x = stack_x[i - 1] + move_x[j];
			next_y = stack_y[i - 1] + move_y[j];

			if (next_x < m && next_y < n && next_x >= 0 && next_y >= 0 && board[next_x][next_y] == 0) {
				stack_x[i] = next_x;
				stack_y[i] = next_y;
				board[next_x][next_y] = i + 1;

				break;
			}

			j = stack_move[i - 1]++;
		}

		if (j < sizeof(move_x) / sizeof(int)) {
			i++;
		} else if (i > 1) {
			board[stack_x[i - 1]][stack_y[i - 1]] = 0;
			stack_move[i - 1] = 0;
			i--;
		}
	}

	return (i == m * n) ? 1 : 0;
}

void print_board(int **board, int m, int n) {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%3d ", board[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int **board;
	int m, n, sx, sy;

	scanf("%d%d%d%d", &m, &n, &sx, &sy);

	if (m < 1 || n < 1 || m >= 20 || n >= 20 || sx < 1 || sy < 1 || sx > m || sy > n) {
		printf(NO);
		exit(1);
	}

	board = alloc_board(m, n);
	board[sx - 1][sy - 1] = 1;

	printf(move(board, m, n, sx - 1, sy - 1) ? YES : NO);

	free_board(board, n);

	return 0;
}
