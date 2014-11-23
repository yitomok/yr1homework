#include <stdio.h>

int main() {
	int a, b;

	scanf("%d%d", &a, &b);

	if (b == 0) {
		printf("IMPOSSIBLE");
	} else {
		printf("%d", a / b);
	}

	return 0;
}