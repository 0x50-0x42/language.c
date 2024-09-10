#include<stdio.h>

#include "def.h"

int main(void) {

	char *s = "12.4509";

	double val = _atof(s);

	printf("Float value: %.5f\n", val);

	return 0;
}
