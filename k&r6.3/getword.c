#include<stdio.h>
#include<ctype.h>

#define __GETWD__
#include "def.h"
#undef __GETWD__

extern int lineNum;

int getword(char *string, int maxchar) {

	int c;

	// ignore whitespaces
	while(isspace(c = getch()) && c != '\n')
		;
	if(c == '\n')
		lineNum++;

	if(isalnum(c)) {
		*string++ = c;

		while(isalnum(c = getch()))
			*string++ = c;

		ungetch(c);
	}

	*string = '\0';
	return c == EOF ? EOF : c;
}
