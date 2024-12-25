#include<stdio.h>

#define __MAIN__
#include "def.h"
#undef __MAIN__

int main(void) {

	char string[MAXCHAR];

	int val;

	int result = minscanf("%d%s", &val, string);

	printf("%d\n%s\n", val, string);

	printf("Result: %d\n", result);

	int a = 100;

	result = minscanf("%*d %d", &a, &val);
	printf("Result: %d\n", result);

	return 0;
}
