#include<stdio.h>
#include<ctype.h>
#include<errno.h>

#define __PARSE__
#include "def.h"
#undef __PARSE__

char *exr;

#include "constants.h"

int parse(char *expr, char *parsed) {

	static int beg = 0;
	if(!beg) {
		exr = expr;
		beg = 1;
	}

	int status = -1;

	// skip whitespaces
	while(isspace(*exr))
		exr++;

	// FOR NUMBERS (ints or doubles)
	if(isdigit(*exr)) {

		// parse the number
		while(isdigit(*exr)) {
			*parsed++ = *exr;
			exr++;
		}

		// if the number is floating point number
		if(*exr == '.') {
			*parsed++ = *exr++;

			// if the number has a fractional part, then parse it as well
			while(isdigit(*exr)) {
				*parsed++ = *exr;
				exr++;
			}
		}

		status = NUM;
	}

	// FOR OPERATORS
	else if(*exr == ADD || *exr == SUB || *exr == DIV || *exr == MUL) {
		
		// if the operator is a minus
		if(*exr == SUB) {
			// then check if the element after it is a digit or not
			if(isdigit(*(exr + 1))) {
				*parsed++ = *exr++;
				// continue parsing the number
				while(isdigit(*exr)) {
					*parsed++ = *exr;
					exr++;
				}

				status = NUM;

			}

			// the element is not a digit
			else {
				*parsed++ = *exr++;
				status = OP;
			}
		}

		// if the operator is a plus
		else if(*exr == ADD) {
			// again check if the element after it is a digit
			if(isdigit(*(exr + 1))) {
				*parsed++ = *exr++;
				// continue parsing the number
				while(isdigit(*exr)) {
					*parsed++ = *exr;
					exr++;
				}

				status = NUM;

			}

			else {
				*parsed++ = *exr++;
				status = OP;
			}
		}

		else if(*exr == DIV) {
			// again check if the element after it is a digit
			if(isdigit(*(exr + 1)))
				return ERR;
			else {
				*parsed++ = *exr++;
				status = OP;
			}
		}

		else if(*exr == MUL) {
			// again check if the element after it is a digit
			if(isdigit(*(exr + 1)))
				return ERR;
			else {
				*parsed++ = *exr++;
				status = OP;
			}
		}
	}

	// MATHEMATICAL FUNCTIONS
	else if(*exr == 's' || *exr == 'c' || *exr == 't' || *exr == 'l') {
		// sin
		if(*exr == 's') {
			if(*(exr + 1) == 'i') {
				exr++;
				if(*(exr + 1) == 'n') {
					status = SIN;
					exr += 2;
					return status;
				}

				return ERR;
			}

			return ERR;
		}

		else if(*exr == 'c') {
			if(*(exr + 1) == 'o') {
				exr++;
				if(*(exr + 1) == 's') {
					status = COS;
					exr += 2;
					return status;
				}

				return ERR;
			}

			return ERR;
		}

		else if(*exr == 't') {
			if(*(exr + 1) == 'a') {
				exr++;
				if(*(exr + 1) == 'n') {
					status = TAN;
					exr += 2;
					return status;
				}

				return ERR;
			}
		}

		else if(*exr == 'l') {
			if(*(exr + 1) == 'o') {
				exr++;
				if(*(exr + 1) == 'g') {
					status = LOG;
					exr += 2;
					return status;
				}

				return ERR;
			}
		}

		else if(*exr == 'e') {
			if(*(exr + 1) == 'x') {
				exr++;
				if(*(exr + 1) == 'p') {
					status = EXP;
					exr += 2;
					return status;
				}

				return ERR;
			}
		}
	}

	*parsed = '\0';

	return status;
}
