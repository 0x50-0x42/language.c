#include<stdio.h>
#include<ctype.h>

#define __GETINT__
#include "def.h"
#undef __GETINT__

int getint() {
	int c, num = 0;

	// ignore whitespaces
	while(isspace(c = getch()))
		;

	if(isdigit(c)) {
		num = num * 10 + (c - '0');
		while(isdigit(c = getch()))
			num = num * 10 + (c - '0');
		ungetch(c);
	}

	return c == EOF ? EOF : num;
}
