#include<stdio.h>
#include<float.h>
#include<stdlib.h>
#include<string.h>

#define __MAIN__
#include "def.h"
#undef __MAIN__

int main(void) {

	char *expr = calloc(MAXLEN, sizeof(char));

	printf("enter a postfix expression: ");
	scanf("%[^\n]%*c", expr);

	// evaluate the postfix expression
	while() {
	}

	if(result != FLT_MAX)
		printf("Result: %lf\n", result);
	else
		puts("Invalid expression!");


	// free memory
	free(expr);
	return 0;
}
