#include<stdio.h>
#include<string.h>

#include "def.h"

int main(int argc, char *argv[]) {

	if(argc > 1)
		argv++;

	unsigned numeric = 0;

	char *lines[MAXLINES];

	puts("provide your input:");

	if(argc > 1)
		if(strcmp(*argv, "-n") == 0)
			numeric = 1;

	int numLines = readlines(lines, MAXLINES);

	printf("Input lines: %d\n", numLines);

	puts("User input:");

	writelines(lines, numLines);

	qsort(lines, 0, numLines - 1, numeric ? numcmp : strCmp);

	puts("\nSorted output:");

	writelines(lines, numLines);

	for(int i = 0; i < numLines; i++)
		freeMem((void**)(lines + i));

	return 0;
}
