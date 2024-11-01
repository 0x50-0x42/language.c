#include<stdio.h>
#include<string.h>

#include "def.h"

int main(int argc, char**argv) {

	if(argc > 1) {
		argv++;
		argc--;
	}

	unsigned numeric = 0, reverse = 0, ignoreCase = 0, dirOrd = 0;

	// naive argument handling
	while(argc != 0) {
		if(strcmp(*argv, "-n") == 0)
			numeric = 1;

		if(strcmp(*argv, "-r") == 0)
			reverse = 1;
		
		if(strcmp(*argv, "-f") == 0)
			ignoreCase = 1;

		if(strcmp(*argv, "-d") == 0)
			dirOrd = 1;

		argv++;
		argc--;
	}

	if(numeric && (ignoreCase || dirOrd)) {
		puts("\'-n\' can only be used with \'-r\'!");
		return 1;
	}

	unsigned numLines = 0;

	char *lines[MAXLINES];

	numLines = readlines(lines, MAXLINES);

	void (*srt)(char**, int, int, int(*)(void*, void*));
	int (*scmp)(void*, void*);

	scmp = ignoreCase ? str_case_cmp : str_cmp;
	scmp = dirOrd ? strdircmp : scmp;

	scmp = ignoreCase && dirOrd ? strdir_case_cmp : scmp;

	srt = reverse ? qsortR : qsort;

	srt(lines, 0, numLines - 1, numeric ? numcmp : scmp);

	puts("Sorted lines:");

	writelines(lines, numLines);

	return 0;
}
