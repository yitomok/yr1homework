#include <stdio.h>
#include <stdlib.h>

#define YES "YES"
#define NO "NO"

// xy coordinate for knight movement on board
int move_x[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int move_y[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int size = sizeof(move_x) / sizeof(int);

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

void free_board(int **board, int m) {
	int i;

	for (i = 0; i < m; i++) {
		free(*(board + i));
	}
	free(board);
}

int kth_smallest(int *a, int size, int k) {
	int i;
	int tmp;
	int swapped = 0;
	int c[size];
	int b[size];

	for (i = 0; i < size; i++) {
		c[i] = a[i];
		b[i] = i;
	}

	if (k < 1) {
		k = 1;
	}
	if (k > size) {
		k = size;
	}

	while (swapped++ < k) {
		for (i = size - 1; i > 0; i--) {
			if (c[i - 1] > c[i]) {
				tmp = c[i];
				c[i] = c[i - 1];
				c[i - 1] = tmp;

				tmp = b[i];
				b[i] = b[i - 1];
				b[i - 1] = tmp;
			}
		}
	}

	return b[k - 1];
}

int move(int **board, int m, int n, int sx, int sy) {
	int i, j, k;
	int next_x, next_y;
	int stack_x[m * n], stack_y[m * n], stack_dir[m * n], stack_move[m * n][size];

	for (i = 0; i < m * n; i++) {
		stack_dir[i] = 0;
	}

	stack_x[0] = sx;
	stack_y[0] = sy;

	i = 1;

	while (i < m * n && stack_dir[i - 1] < size) {
		for (j = 0; j < size; j++) {
			stack_move[i - 1][j] = 0;
		}

		// Warnsdorff's rule preparation
		for (j = 0; j < size; j++) {
			next_x = stack_x[i - 1] + move_x[j];
			next_y = stack_y[i - 1] + move_y[j];

			if (next_x < m && next_y < n && next_x >= 0 && next_y >= 0 && board[next_x][next_y] == 0) {
				for (k = 0; k < size; k++) {
					next_x += move_x[k];
					next_y += move_y[k];

					if (next_x < m && next_y < n && next_x >= 0 && next_y >= 0 && board[next_x][next_y] == 0) {
						stack_move[i - 1][j]++;
					}

					next_x -= move_x[k];
					next_y -= move_y[k];
				}
			} else {
				stack_move[i - 1][j] = -1;
			}
		}

		j = stack_dir[i - 1]++;

		// Apply Warnsdorff's rule, and find a possible tour
		while (j < size) {
			j = kth_smallest(stack_move[i - 1], size, stack_dir[i - 1]);

			if (stack_move[i - 1][j] >= 0) {
				stack_x[i] = stack_x[i - 1] + move_x[j];
				stack_y[i] = stack_y[i - 1] + move_y[j];
				board[stack_x[i]][stack_y[i]] = i + 1;

				j = stack_dir[i - 1] - 1;

				break;
			}

			j = stack_dir[i - 1]++;
		}

		// Check valid movement criteria
		if (j < size) {
			i++;
		}
	}

	return (i == m * n) ? 1 : 0;
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

	free_board(board, m);

	return 0;
}
