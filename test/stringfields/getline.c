#include<stdio.h>

unsigned _getline(char*string, int lim) {
	char*base = string;

	int c;

	while((c = getchar()) != '\n'  && c != EOF && (string - base) < lim - 1)
		*string++ = c;

	if(c == '\n')
		*string = '\0';
	if(c == EOF && (string - base) > 0) { // if EOF was entered while inputting a string -- (CTRL+D+D)
		*string = '\0';
		return (string - base);
	}

	if(c == EOF) {
		*string = '\0';
		return EOF;
	}


	return (string - base);
}
