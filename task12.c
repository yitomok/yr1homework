#include <stdio.h>
#include <stdlib.h>

int main() {
	int *a = NULL, size = 10, curr_size = 0, i;

	a = malloc(size * sizeof(int));

	if (a != NULL) {
		scanf("%d", a + curr_size++);
		while (!feof(stdin)) {
			scanf("%d", a + curr_size);

			if (!feof(stdin) && ++curr_size >= size) {
				size *= 2;
				a = (int *) realloc(a, size * sizeof(int));
			}
		}

		for (i = 0; i < curr_size; i++) {
			printf("%d\n", a[i]);
		}
		for (i = 0; i < curr_size; i++) {
			printf("%d\n", a[i]);
		}

		free(a);
	}

	return 0;
}
