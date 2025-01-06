#include<stdio.h>

#define __MAIN__
#include "def.h"
#undef __MAIN__

int main(void) {

	char string[MAXCHAR];

	int val;

	int result = minscanf("%d%s", &val, string);

<<<<<<< HEAD
	fflush(stdin);

=======
>>>>>>> 6c02cc4d037ec211014e0a4b95526b4425f76c7a
	printf("val = %d\nstring = %s\n", val, string);

	printf("Result: %d\n", result);

	int a = 100;

	result = minscanf("%*d %d", &a, &val);
	printf("Result: %d\n", result);
	printf("a = %d\nval = %d\n", a, val);

<<<<<<< HEAD
	fflush(stdin);

	int b, c;

	result = minscanf("%d/%d", &b, &c);
	printf("Result: %d\n", result);
=======
	int b, c;

	result = minscanf("%d/%d", &b, &c);
>>>>>>> 6c02cc4d037ec211014e0a4b95526b4425f76c7a
	printf("b = %d\nc = %d\n", b, c);

	return 0;
}
