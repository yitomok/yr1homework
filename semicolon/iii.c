#include <stdio.h>

int main() {
	int i;
	int day, month, year, days;
	int d_o_m[] = {31,28,31,30,31,30,31,31,30,31,30,31};

	scanf("%d%d%d%d", &day, &month, &year, &days);

	for (i = 1; i <= days; i++) {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			d_o_m[1] = 29;
		} else {
			d_o_m[1] = 28;
		}
		if (++day > d_o_m[month - 1]) {
			if (month == 12) {
				day = 1;
				month = 1;
				year++;
			} else {
				day = 1;
				month++;
			}
		}
	}
	printf("%d %d %d", day, month, year);
}
