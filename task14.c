#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node *next;
} node;

void sort(node **book) {
	node *prev, *curr, *next, *tmp;
	int swapped;
	if (*book != NULL && (*book)->next != NULL) {
		do {
			swapped = 0;
			for (prev = NULL, curr = *book; curr != NULL && curr->next != NULL; prev = curr, curr = curr->next) {
				if (curr->val < curr->next->val) {
					tmp = curr->next->next;
					curr->next->next = curr;
					if (curr == *book) {
						*book = curr->next;
					}
					if (prev != NULL) {
						prev->next = curr->next;
					}
					curr->next = tmp;
					swapped = 1;
				}
			}
		} while (swapped);
	}
}

int main() {
	node *book = NULL, *curr, *prev;
	int i, arg;

	do {
		scanf("%d", &i);

		switch(i) {
		case 1:
			scanf("%d", &arg);
			curr = book;
			book = malloc(sizeof(node));
			book->val = arg;
			book->next = curr;

			break;
		case 2:
			scanf("%d", &arg);
			for (prev = NULL, curr = book; curr != NULL; prev = curr, curr = curr->next) {
				if (arg == curr->val) {
					if (prev != NULL) {
						prev->next = curr->next;
					} else {
						book = curr->next;
					}
					free(curr);

					break;
				}
			}
			break;
		case 4:
			sort(&book);

			break;
		case 5:
			for (curr = book; curr != NULL; curr = curr->next) {
				printf("%d\n", curr->val);
			}

			break;
		default:
			break;
		}
	} while (i != 6);

	return 0;
}
