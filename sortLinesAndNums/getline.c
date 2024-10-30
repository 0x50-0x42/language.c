#include<stdio.h>

unsigned _getline(char*line, int lim) {
	int c;

	char *base = line;

	while((c = getchar()) != '\n' && c != EOF && (base - line) < lim - 1)
		*line++ = c;

	*line = '\0';

	return (line - base);
}
