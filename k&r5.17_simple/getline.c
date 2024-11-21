#include<stdio.h>

int _getline(char*string, int lim) {
	int c;
	int len = 0;

	char *base = string;

	while((c = getchar()) != '\n' && c != EOF && (string - base) < lim - 1)
		*string++ = c;
	*string = '\0';

	if(string - base == 0)
		return EOF;

	if(c == EOF && string - base > 0)
		return string - base;
	if(c == EOF)
		return EOF;

	return string - base;
}
