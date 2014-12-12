#include <stdio.h>
#include <string.h>

int main() {
	char *a;
	char what[255], by[255], where[255];

	scanf("%s%s%s", what, by, where);

	while (strcmp(what, by) != 0 && (a = strstr(where, what)) != NULL) {
		strncpy(a, by, strlen(by));
	}

	printf("%s", where);
}
