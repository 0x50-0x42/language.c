#include<stdio.h>
#include<ctype.h>

#include "constants.h"

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
				idx++;
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

		// check if EXP
		else if(expr[idx] == 'e') {
			if(expr[idx + 1] != '\0' && expr[idx + 1] == 'x') {
				if(expr[idx + 2] != '\0' && expr[idx + 2] == 'p') {
					idx += 3;
					return EXP;
				}
				else {
					return INV;
				}
			}

			else {
				return INV;
			}
		}

		// check if SIN
		else if(expr[idx] == 's') {
			if(expr[idx + 1] != '\0' && expr[idx + 1] == 'i') {
				if(expr[idx + 2] != '\0' && expr[idx + 2] == 'n') {
					idx += 3;
					return SIN;
				}

				else {
					return INV;
				}
			}

			else {
				return INV;
			}
		}

		// check COS
		else if(expr[idx] == 'c') {
			if(expr[idx + 1] != '\0' && expr[idx + 1] == 'o') {
				if(expr[idx + 2] != '\0' && expr[idx + 2] == 's') {
					idx += 3;
					return COS;
				}

				else {
					return INV;
				}
			}

			else {
				return INV;
			}
		}

		// check TAN
		else if(expr[idx] == 't') {
			if(expr[idx + 1] != '\0' && expr[idx + 1] == 'a') {
				if(expr[idx + 2] != '\0' && expr[idx + 2] == 'n') {
					idx += 3;
					return TAN;
				}

				else {
					return INV;
				}
			}

			else {
				return INV;
			}
		}

	}

	return expr[idx++];
}
