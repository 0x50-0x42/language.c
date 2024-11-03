#include<stdio.h>

#include "def.h"

int main(void) {

	char *line[MAXLINES][3];

	puts("enter strings:");

	unsigned numLines = 0;

	numLines = readlines(line, MAXLINES, 3);

	writelines(line, numLines, 3);

	return 0;
}
