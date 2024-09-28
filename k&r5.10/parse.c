#include<stdio.h>
#include<ctype.h>

//#include "constants.h"

#define NUM '0'

int getch();
void ungetch(int);

extern int sign;
extern unsigned idx;

int parse(char *expr, char* number) {

	// ignore whitespaces, tabs and newlines
	while(isspace(expr[idx]))
		idx++;

	// check if digit
	if(isdigit(expr[idx])) {
		while(isdigit(expr[idx]))
			*number++ = expr[idx++];
		if(expr[idx] == '.') {
			*number++ = expr[idx++];
			while(isdigit(expr[idx]))
				*number++ = expr[idx++];
		}

		*number = '\0';

		return NUM;
	}

	// if not a digit, then check for other symbols and negative numbers
	else {
		if(expr[idx] == '-') {
			if(isdigit(expr[idx + 1])) {
				sign *= -1;
				while(isdigit(expr[idx]))
					*number++ = expr[idx++];
				if(expr[idx] == '.') {
					*number++ = expr[idx++];
					while(isdigit(expr[idx]))
						*number++ = expr[idx++];
				}

				*number = '\0';

				return NUM;
			}
		}

	}

	return expr[idx++];
}
