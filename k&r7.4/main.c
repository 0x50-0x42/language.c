#include<stdio.h>

#define __MAIN__
#include "def.h"
#undef __MAIN__

int main(void) {

	char string[MAXCHAR];

	int val;

	int result = minscanf("%d%s", &val, string);

	fflush(stdin);

	printf("val = %d\nstring = %s\n", val, string);

	printf("Result: %d\n", result);

	int a = 100;

	result = minscanf("%*d %d", &a, &val);
	printf("Result: %d\n", result);
	printf("a = %d\nval = %d\n", a, val);

	fflush(stdin);

	int b, c;

	result = minscanf("%d/%d", &b, &c);
	printf("Result: %d\n", result);
	printf("b = %d\nc = %d\n", b, c);

	return 0;
}
