#include<stdio.h>
#include<string.h>

#include "def.h"

int main(int argc, char *argv[]) {
	if(argc > 1) {
		argv++;
		argc--;
	}

	int reverse = 0, numeric = 0, ignoreCase = 0;

	// naive argument handling
	while(argc != 0) {
		if(strcmp(*argv, "-n") == 0)
			numeric = 1;
		if(strcmp(*argv, "-r") == 0)
			reverse = 1;
		if(strcmp(*argv, "-f") == 0)
			ignoreCase = 1;
		argv++;
		argc--;
	}

	if(ignoreCase && numeric) {
		puts("cannot sort numbers with \'-f\' flag!");
		return 1;
	}

	puts("provide your input:");

	char *lines[MAXLINES];

	unsigned numLines = readlines(lines, MAXLINES);

	void (*srt)(char**, int, int, int(*)(void*, void*));

	int (*strcomp)(void*, void*);

	strcomp = ignoreCase ? strCasecmp : strCmp;

	srt = reverse ? qsortR : qsort;

	srt(lines, 0, numLines - 1, numeric ? numcmp : strcomp);

	writelines(lines, numLines);

	for(int i = 0; i < numLines; i++)
		freeMem((void**)lines + i);

	return 0;
}
