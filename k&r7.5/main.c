#include<stdio.h>
#include<math.h>
#include<float.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>

#define PI 3.14159
#define STRTANG 180

#define __MAIN__
#include "def.h"
#undef __MAIN__
#include "constants.h"

int main(void) {

	char *expr = calloc(MAXLEN, sizeof(char));
	char *parsed = calloc(MAXLEN, sizeof(char));

	printf("enter a postfix expression:\n");
	scanf("%[^\n]%*c", expr);

	double num;

	// evaluate the postfix expression
	int returned;
	while((returned = parse(expr, parsed)) != EOF && returned != ERR) {
		switch(returned) {
			case NUM: // a number is returned
				num = atof(parsed);
				push(num);
				break;

			// a mathematical function is returned
			case SIN:
				push(sin(pop() * PI / STRTANG));
				break;

			case COS:
				push(cos(pop() * PI / STRTANG));
				break;

			case TAN:
				push(tan(pop() * PI / STRTANG));
				break;

			case LOG:
				push(log(pop()));
				break;

			case OP:
				if(strcmp(parsed, "+") == 0) {
					// do addition
					num = pop();
					push(num + pop());
				}

				else if(strcmp(parsed, "-") == 0) {
					// do subtraction
					num = pop();
					push(pop() - num);
				}

				else if(strcmp(parsed, "*") == 0) {
					// do multiplication
					push(pop() * pop());
				}

				else if(strcmp(parsed, "/") == 0) {
					// do division
					num = pop();
					push(pop() / num);
				}

				break;

		}
	}


	double result = peek();

	if(result != DBL_MAX)
		printf("Result: %lf\n", result);
	else
		puts("\nit seems that the stack is empty!");

	// free memory
	free(expr);
	free(parsed);

	return 0;
}
