#include<stdio.h>


unsigned _getline(char *string, int lim) {

	int c;

	char *base = string;

	while((c = getchar()) != '\n' && c != EOF && (string - base) < lim - 1)
		*string++ = c;

	*string = '\0';

	if(c == EOF && string - base > 0)
		return (string - base);
	if(c == EOF)
		return c;

	return (string - base);
}
