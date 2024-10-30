#include<stdio.h>
#include<string.h>

#include "def.h"

int main(int argc, char *argv[]) {
	if(argc > 1)
		argc--;
		argv++;

	int numeric = 0, reverse = 0;

	// check for the '-n' option

	if(argc >= 1) {
		if(strcmp(*argv, "-n") == 0 || strcmp(*argv, "-r") == 0) {
			if(strcmp(*argv, "-n") == 0) {
				numeric = 1;
				argv++;
				argc--;
			}

			else if(strcmp(*argv, "-r") == 0) {
				reverse = 1;
				argv++;
				argc--;
			}

			if(argc >= 1) {
				if(strcmp(*argv, "-n") == 0) {
					numeric = 1;
					argv++;
					argc--;
				}

				else if(strcmp(*argv, "-r") == 0) {
					reverse = 1;
					argv++;
					argc--;
				}
			}

		}
	}

	puts("provide your input:");

	char *lines[MAXLINES];

	unsigned numLines = readlines(lines, MAXLINES);

	reverse ? qsortR(lines, 0, numLines - 1, numeric ? numcmp : strCmp) : qsort(lines, 0, numLines - 1, numeric ? numcmp : strCmp);

	puts("sorted lines:");

	writelines(lines, numLines);

	for(int i = 0; i < numLines; i++)
		freeMem((void**)lines + i);

	return 0;
}
