#include <stdio.h>
#include <math.h>

int main() {
	int i, j, a;
	int p[16];

	scanf("%d", &a);

	for (i = a, j = 0; i >= 1 && j < 16; i /= 2, j++) {
		p[j] = i % 2;
	}

	a = 0;
	for (i = 0; i < j; i++) {
		a += p[i] == 1 ? pow(2, j - 1 - i) : 0;
	}
	printf("%d", a);

	return 0;
}
