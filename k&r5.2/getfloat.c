#include<stdio.h>
#include<limits.h>
#include<ctype.h>

#define _DEF_
#include "def.h"
#undef _DEF_

int getfloat(double *val) {
	int c, sign;

	// escape the whitespaces
	while(isspace(c = getch()))
		;

	if(!isdigit(c) && c != '-' && c != '+' && c != EOF) {
		return INT_MAX;
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

	if(c == '.') {
		c = getch();

		double multiplier = 1;
		int num = 0;

		while(isdigit(c)) {
			num = 10 * num + (c - '0');
			multiplier *= 0.1;
			c = getch();
		}

		*val = *val + multiplier * (double)num;
	}

	*val *= sign;

	if(c != EOF)
		ungetch(c);
	return c;
}
