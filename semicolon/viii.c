#include <stdio.h>

int main() {
	int n, m, i, j;
	int si = 1, sj = 1;
	int v = 1;
	int k;

	scanf("%d%d%d%d", &n, &m, &j, &i);

	while (si <= n && sj <= m) {
		for (k = sj; k <= m; k++) {
			if (si == i && k == j) {
				printf("%d", v);
				return 0;
			}
			v++;
		}
		si++;
		for (k = si; k <= n; k++) {
			if (k == i && m == j) {
				printf("%d", v);
				return 0;
			}
			v++;
		}
		m--;
		for (k = m; k >= sj; k--) {
			if (n == i && k == j) {
				printf("%d", v);
				return 0;
			}
			v++;
		}
		n--;
		for (k = n; k >= si; k--) {
			if (k == i && sj == j) {
				printf("%d", v);
				return 0;
			}
			v++;
		}
		sj++;
	}

	return 0;
}
