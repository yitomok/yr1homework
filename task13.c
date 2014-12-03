#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node *next;
} node;

int main() {
	node *tmp, *input, *root = malloc(sizeof(node));

	scanf("%d", &(root->val));
	root->next = NULL;

	while (!feof(stdin)) {
		input = malloc(sizeof(node));
		scanf("%d", &(input->val));

		if (!feof(stdin)) {
			if (input->val < root->val) {
				input->next = root;
				root = input;
			} else {
				for (tmp = root; tmp != NULL; tmp = tmp->next) {
					if (input->val >= tmp->val && (tmp->next == NULL || (tmp-> next != NULL && input->val < tmp->next->val))) {
						input->next = tmp->next;
						tmp->next = input;
						break;
					}
				}
			}
		}
	}

	while (root != NULL) {
		tmp = root;
		printf("%d ", tmp->val);
		root = tmp->next;
		free(tmp);
	}

	return 0;
}
