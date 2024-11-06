#include<stdio.h>

#include "def.h"

int main(void) {

	puts("enter some strings:");

	int numLines;

	char *lines[MAXLINES][MAXFIELDS];

	numLines = readlines(MAXFIELDS, lines, MAXLINES);

	puts("Original order of strings:");

	writelines(MAXFIELDS, lines, numLines);

	puts("Sorted order of strings:");

	qsort(MAXFIELDS, lines, 0, numLines - 1, 0);

	writelines(MAXFIELDS, lines, numLines);

	return 0;
}
