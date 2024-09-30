#include<stdio.h>

#include "def.h"

int main(void) {
	char string[SIZE];

	puts("enter a string:");

	int len = _getline(string, SIZE);

	puts("detabbed string:");

	detab(string);

	printf("\n");

	return 0;
}
