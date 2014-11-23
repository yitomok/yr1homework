#include <stdio.h>
#include <stdlib.h>

#define BUY "buy it!"
#define FEED "feed the crocodiles!"

int ** alloc_grille(int blk) {
	int i;
	int **grille = NULL;

	grille = calloc(blk, sizeof(int *));

	if (grille == NULL) {
		printf("NO");
		exit(1);
	}

	for (i = 0; i < blk; i++) {
		*(grille + i) = calloc(blk, sizeof(int));

		if (*(grille + i) == NULL) {
			printf("NO");
			exit(1);
		}
	}

	return grille;
}

void init_grille(int **grille, int blk, int row, char *line) {
	int i;

	for (i = 0; i < blk; i++) {
		if (line[i] == '@') {
			grille[row][i] = 1;
		}
	}
}

void free_grille(int **grille, int blk) {
	int i;

	for (i = 0; i < blk; i++) {
		free(*(grille + i));
	}
	free(grille);
}

void rotate90(int **grille, int **papyrus, int blk) {
	int i, j;
	int tmp;

	for (i = 0; i < blk; i++) {
		for (j = i + 1; j < blk; j++) {
			tmp = grille[i][j];
			grille[i][j] = grille[j][i];
			grille[j][i] = tmp;
		}
	}

	for (i = 0; i < blk; i++) {
		for (j = 0; j < blk / 2; j++) {
			tmp = grille[i][j];
			grille[i][j] = grille[i][blk - j - 1];
			grille[i][blk - j - 1] = tmp;
		}
	}

	for (i = 0; i < blk; i++) {
		for (j = 0; j < blk; j++) {
			papyrus[i][j] += grille[i][j];
		}
	}
}

int is_func_grille(int **grille, int blk) {
	int i, j;	

	for (i = 0; i < blk; i++) {
		for (j = 0; j < blk; j++) {
			if (grille[i][j] != 1) {
				return 0;
			}
		}
	}

	return 1;
}

void check_grille(char *filename1, char *filename2) {
	int g, blk;
	int i, j, k;
	FILE *f1, *f2;
	int **grille = NULL, **papyrus = NULL;
	char *line;
	int more_than_1, empty;
	char *result = BUY;

	f1 = fopen(filename1, "r");
	f2 = fopen(filename2, "w");

	if (f1 == NULL || f2 == NULL) {
		printf("NO");
		exit(1);
	}

	fscanf(f1, "%d", &g);

	for (i = 0; i < g; i++) {
		fscanf(f1, "%d", &blk);

		grille = alloc_grille(blk);
		papyrus = alloc_grille(blk);

		line = malloc(blk + 1);

		if (line == NULL) {
			free_grille(grille, blk);
			free_grille(papyrus, blk);

			printf("NO");
			exit(1);
		}

		for (j = 0; j < blk; j++) {
			fscanf(f1, "%s", line);

			init_grille(grille, blk, j, line);
			init_grille(papyrus, blk, j, line);
		}

		/* start to do some serious work here */
		rotate90(grille, papyrus, blk);
		rotate90(grille, papyrus, blk);
		rotate90(grille, papyrus, blk);

		if (is_func_grille(papyrus, blk)) {
			fprintf(f2, "grid\n");
		} else {
			result = FEED;
			more_than_1 = 0;
			empty = 0;
			for (j = 0; j < blk; j++) {
				for (k = 0; k < blk; k++) {
					if (papyrus[j][k] == 0) {
						empty++;
					}
					if (papyrus[j][k] > 1) {
						more_than_1++;
					}
				}
			}
			fprintf(f2, "%d %d\n", more_than_1, empty);
		}

		free(line);
		free_grille(grille, blk);
		free_grille(papyrus, blk);
	}
	fprintf(f2, "%s\n", result);

	fclose(f1);
	fclose(f2);
}

int main() {
	check_grille("delivery.in", "croco.out");

	return 0;
}
