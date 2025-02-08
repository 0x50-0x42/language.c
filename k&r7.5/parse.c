#include<stdio.h>
#include<ctype.h>
#include<errno.h>

#define __PARSE__
#include "def.h"
#undef __PARSE__

#include "constants.h"

int parse(char *expr, char *parsed) {
	int status = -1;
	static char *exp = expr;

	// skip whitespaces
	while(isspace(*exp))
		Expr++;

	// FOR NUMBERS (ints or otherwise)
	if(isdigit(*exp)) {

		// parse the number
		while(isdigit(*exp)) {
			*parsed++ = *exp;
			exp++;
		}

		// if the number is floating point number
		if(*exp == '.') {
			*parsed++ = *exp++;

			// if the number has a fractional part, then parse it as well
			while(isdigit(*exp)) {
				*parsed++ = *exp;
				exp++;
			}
		}

		status = NUM;
	}

	// FOR OPERATORS
	else if(*exp == ADD || *exp == SUB || *exp == DIV || *exp == MUL || *exp == POW) {
		
		// if the operator is a minus
		if(*exp == SUB) {
			// then check if the element after it is a digit or not
			if(isdigit(*(exp + 1))) {
				*parsed++ = *exp++;
				// continue parsing the number
				while(isdigit(*exp)) {
					*parsed++ = *exp;
					exp++;
				}

				status = NUM;

			}

			// the element is not a digit
			else {
			}
		}

		// if the operator is a plus
		else if(*exp == ADD) {
			// again check if the element after it is a digit
			if(isdigit(*(exp + 1))) {
				*parsed++ = *exp++;
				// continue parsing the number
				while(isdigit(*exp)) {
					*parsed++ = *exp;
					exp++;
				}

				status = NUM;

			}

			else {
			}
		}

		else if(*exp == DIV) {
			// again check if the element after it is a digit
			if(isdigit(*(exp + 1)))
				return ERR;
		}

		else if(*exp == MUL) {
			// again check if the element after it is a digit
			if(isdigit(*(exp + 1)))
				return ERR;
		}

		else if(*exp == POW) {
			// again check if the element after it is a digit
			if(isdigit(*(exp + 1)))
				return ERR;
		}
	}

	*parse = '\0';

	return status;
}
