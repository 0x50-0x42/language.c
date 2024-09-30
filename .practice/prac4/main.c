/*
 */

#include<stdio.h>
#include "def.h"

int main(void) {
	char string[SIZE];

	puts("enter some text:");

	int len = _getline(string, SIZE);
	puts("Entabbed string:");
	entab(string);
	printf("\n");
	return 0;
}
