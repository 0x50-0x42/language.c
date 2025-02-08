#include<stdio.h>
#include<float.h>
#include<stdlib.h>
#include<string.h>

#define __MAIN__
#include "def.h"
#undef __MAIN__
#include "constants.h"

int main(void) {

	char *expr = calloc(MAXLEN, sizeof(char));
	char *parsed = calloc(MAXLEN, sizeof(char));

	printf("enter a postfix expression: ");
	scanf("%[^\n]%*c", expr);

	// evaluate the postfix expression
	int returned;
	while((returned = parse(expr, parsed)) != EOF && returned != ERR) {
		switch(returned) {
			case NUM: // a number is returned
				break;

			case VAR: // a variable is returned
				break;

			// a mathematical function is returned
			case SIN:
				break;

			case COS:
				break;

			case TAN:
				break;

			case LOG:
				break;

			case OP:
				break;

		}
	}

	/*
	if(result != FLT_MAX)
		printf("Result: %lf\n", result);
	else
		puts("Invalid expression!");
	 */


	// free memory
	free(expr);
	free(parsed);

	return 0;
}
