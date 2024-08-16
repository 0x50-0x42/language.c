#include<stdio.h>
#include<ctype.h>
#include<limits.h>

#define _DEF_
#include "def.h"
#undef _DEF_

int getint(int *val) {
	int c, sign;

	// escape the whitespaces
	while(isspace(c = getch()))
		;

	if(!isdigit(c) && c != '-' && c != '+' && c != EOF) {
		ungetch(c);
		return 0;
	}

	sign = c == '-' ? -1 : 1;

	if(c == '-' || c == '+') {
		int temp;
		if(!isdigit(temp = getch())) {
			ungetch(c); // if there is no digit after '-' or '+' then push c back on the input
			return INT_MAX;
		}

		c = temp; // if there is a digit after '-' or '+', then store it in c
	}

	for(*val = 0; isdigit(c); c = getch())
		*val = 10 * *val + (c - '0');
	*val *= sign;

	if(c != EOF)
		ungetch(c);
	return c;
}
