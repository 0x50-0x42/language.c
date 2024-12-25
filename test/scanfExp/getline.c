#include<stdio.h>

int _getline(char *string, int maxchar) {

	int c;

	char *base = string;

	while((c = getchar()) != EOF && c != '\n') // take one line
		*string++ = c;
	*string = '\0';

	return (string - base);
}
