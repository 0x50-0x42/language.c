#include<stdio.h>
#include<ctype.h>

#define _DEF_
#include "def.h"
#undef _DEF_

int getint(int *val) {
	int c;

	// skip whitespaces
	while(isspace(c = getch()) || c == '\t' || c == '\n')
		;

	int sign = c == '-' ? -1 : 1;

	if(c != '-' && c != '+' && !isdigit(c) && c != EOF)
		return 0;

	if(isdigit(c)) {
		for(*val = 0; isdigit(c); c = getch()) // for loop used in a very interesting way!! AMAZING!!(taken from K&R2)
			*val = 10 * *val + (c - '0');

		*val *= sign;

		if(c != EOF)
			ungetch(c);
		return c;
	}

	if(c == '-' || c == '+') {
		if(isdigit(c = getch())) {
			for(*val = 0; isdigit(c); c = getch())
				*val = 10 * *val + (c - '0');

			*val *= sign;
		}
	}

	if(c != EOF)
		ungetch(c);

	return c;
}
