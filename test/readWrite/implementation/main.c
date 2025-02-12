#include<stdio.h>
#include<stdlib.h>

#define __MAIN__
#include "def.h"
#undef __MAIN__

int main(void) {

	char *string = calloc(MAXLEN, sizeof(char));

	int n = _read(string, MAXLEN);

	printf("\n%d\n\n", n);

	n = _write(string, n);

	printf("\n%d\n", n);


	// free
	free(string);

	return 0;
}
