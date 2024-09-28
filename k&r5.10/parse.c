#include<stdio.h>
#include<cypte.h>

#include "constants.h"

int getch();
void ungetch(int);

extern int sign;

int parse(char *expr, char* number) {
	while(isspace(*expr)) // ignore any whitespaces
		expr++;
	if(isdigit(*expr)) {
		while(isdigit(*expr))
			*number++ = *expr++;
		if(*expr == '.') {
			*number++ = *expr++;
			while(isdigit(*expr))
				*number++ = *expr++;
			*number = '\0';

			ungetch(*expr); // storing it to input buffer
			
		}

		else {
			ungetch(*expr);
		}

		return NUM;
	}

	else {
		if(*expr == '-') {
			// check if a digits follows it
			if(isdigit(*(expr + 1))) {
				sign *= -1;
				expr++;

				while(isdigit(*expr))
					*number++ = *expr++;
				
				if(*expr == '.') {
					*number++ = *expr++;
					while(isdigit(*expr))
						*number++ = *expr++;

					ungetch(*expr);
				}

				else {
				}
			}
		}
	}
}
