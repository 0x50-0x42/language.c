#include<stdio.h>

unsigned _getline(char *string, int lim) {

	char *base = string;

	int c;

	while((c = getchar()) != '\n' && c != EOF && (string - base) < lim - 1)
		*string++ = c;
	*string = '\0';

	return (string - base);
}
