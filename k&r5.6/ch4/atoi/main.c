#include<stdio.h>

#include "def.h"

int main(void) {

	char *s = "12.0";

	int val = _atoi(s);

	printf("integer: %d\n", val);

	return 0;
}
