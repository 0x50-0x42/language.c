#include<stdio.h>
#include<ctype.h>

#define __GETWD__
#include "def.h"
#undef __GETWD__

int isscore(int val) {return val == '_' ? 1 : 0;}

int getword(char *string, int max) {

	int c;

	while(isspace(c = getch()))
		;

	if(isalnum(c)) {
		*string++ = c;
		while(isalnum(c = getch()) || isscore(c))
			*string++ = c;
		ungetch(c);
	}

	*string = '\0';
	return c == EOF ? EOF : c;
}
