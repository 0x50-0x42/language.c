/*
Facilities:
	>-> basic printf conversions like `i' and `d', `o', `x' and `X', `u', `c', `s', `f', `p'..
	>-> fields
 */

#include "def.h"

int main(void) {

	char *string = "hello world";

	minprintf("hello world\n");

	int np = 16;

	minprintf("%10d\n", np);

	minprintf("%15s\n", string);

	return 0;
}
