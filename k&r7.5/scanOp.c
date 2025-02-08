#include<stdio.h>
#include<ctype.h>

#include "stack.h"

double eval(char *expr) {

	int intgl = 0, decl = 0;

	// parse the expression
	while(expr != '\0') {
		if(isdigit(*expr)) {
			// taking in the integral part
			while(isdigit(*expr)) {
				intgl = intgl * 10 + (*expr - '0');
				expr++;
			}

			// if there is a dot
			if(*expr == '.') {
				expr++;

				// take in the decimal part
				while(isdigit(*expr)) {
					decl = decl * 10 + (*expr - '0');
					expr++;
				}
			}
		}
	}
}
