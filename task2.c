#include <stdio.h>
#include <limits.h>

int main() {
	int largest = INT_MIN, second_largest = INT_MIN, tmp = 0;

	while (tmp != -1) {
		scanf("%d", &tmp);

		if (tmp != -1) {
			if (tmp >= largest) {
				second_largest = largest;
				largest = tmp;
			} else if (tmp >= second_largest) {
				second_largest = tmp;
			}
		}
	}

	printf("%d", second_largest);

	return 0;
}
