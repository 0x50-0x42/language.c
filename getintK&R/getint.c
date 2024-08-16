#include<stdio.h>
#include<ctype.h>

#define _DEF_
#include "def.h"
#undef _DEF_

int getint(int *val) {
	int c, sign;

	// skip whitespaces
	while(isspace(c = getch()))
		;

	if(!isdigit(c) && c != '+' && c != '-' && c != EOF) {
		ungetch(c);
		return 0;
	}

	sign = c == '-' ? -1 : 1;

	if(c == '+' || c == '-')
		c = getch();

	for(*val = 0; isdigit(c); c = getch())
		*val = 10 * *val + (c - '0');

	*val *= sign;

	if(c != EOF)
		ungetch(c);
	return c;
}
