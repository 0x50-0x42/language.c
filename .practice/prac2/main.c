// print input one word per line

#include<stdio.h>

#include "def.h"

int main(void) {
	char text[SIZE];

	puts("enter some text:");

	int len = _getline(text, SIZE);

	printWord(text);
	
	printf("\n");

	return 0;
}
