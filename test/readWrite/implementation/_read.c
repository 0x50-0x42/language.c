#include<stdio.h>

#include "def.h"

int _read(char *string, unsigned int length) {
	int c;

	char *base = string;
	while((c = getchar()) != EOF && c != '\n')
		*string++ = c;
	if(c == '\n')
		*string++ = c;

	*string = '\0';


	return (string - base);
}
