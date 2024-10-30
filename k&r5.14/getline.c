#include<stdio.h>

unsigned _getline(char *line, int lim) {
	char *base = line;

	int c;

	while((c = getchar()) != '\n' && c != EOF && (line - base) < lim - 1)
		*line++ = c;
	*line = '\0';

	return (line - base);
}
