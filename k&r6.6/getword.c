#include<stdio.h>
#include<ctype.h>

#define __GETWD__
#include "def.h"
#undef __GETWD__

int isscore(int val) { return val == '_' ? 1 : 0; }
int ishash(int val) { return val == '#' ? 1 : 0; }

int getword(char*string, int maxch) {
	int c;

	while(isspace(c = getch()))
		;

	if(ishash(c)) {
		*string++ = c;
		while(isalnum(c = getch()) || isscore(c))
			*string++ = c;
		if(c != EOF)
			ungetch(c);
	}

	else {
		*string++ = c;
		while(isalnum(c = getch()) || isscore(c))
			*string++ = c;
		if(c != EOF)
			ungetch(c);
	}

	*string = '\0';
	return c;
}
