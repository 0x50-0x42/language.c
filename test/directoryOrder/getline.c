#include<stdio.h>

unsigned _getline(char*s, int lim) {
	char *base = s;

	int c;

	while((c = getchar()) != '\n' && c != EOF && (base - s) < lim - 1)
		*s++ = c;

	*s = '\0';

	return (s - base);
}
