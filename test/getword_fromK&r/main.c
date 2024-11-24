#include<stdio.h>

#include "def.h"

int main(void) {

	char string[MAXCHAR];

	while(getword(string, MAXCHAR) != EOF)
		printf("String: %s\n", string);
	return 0;
}
