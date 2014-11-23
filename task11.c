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

int move(int **board, int m, int n, int sx, int sy, int moves) {
	int i;
	int next_x, next_y;

	if (moves == m * n - 1) {
		return 1;
	}

	for (i = 0; i < sizeof(move_x) / sizeof(int); i++) {
		next_x = sx + move_x[i];
		next_y = sy + move_y[i];

		if (next_x < m && next_y < n && next_x >= 0 && next_y >= 0 && board[next_x][next_y] == 0) {
			board[next_x][next_y] = 1;
			if (move(board, m, n, next_x, next_y, moves + 1)) {
				return 1;
			} else {
				board[next_x][next_y] = 0;
			}
		}
	}

	return 0;
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

	printf(move(board, m, n, sx - 1, sy - 1, 0) ? YES : NO);

	free_board(board, n);

	return 0;
}
