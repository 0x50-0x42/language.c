#include<stdio.h>

#define __MAIN__
#include "def.h"
#undef __MAIN__

int main(void) {

	char *string = "hello world";

	minprintf("%s\n", string);

	minprintf("I am a C programmer\n");

	int a = 10, b = a + 10;

	minprintf("%d-%d\n", a, b);

	return 0;
}
