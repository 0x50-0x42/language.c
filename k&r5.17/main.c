// understood what I have to do from here: https://stackoverflow.com/a/6135979

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#include "def.h"

int main(int argc, char**argv) {

	if(argc > 1) {
		argc--;
		argv++;
	}

	unsigned numeric = 0, rev = 0, fold = 0, dir = 0, fieldno = 1;

	// naive argument handling
	if(argc >= 1) {
		while(argc >= 1) {
			if(strcmp(*argv, "-d") == 0)
				dir = 1;
			if(strcmp(*argv, "-f") == 0)
				fold = 1;
			if(strcmp(*argv, "-n") == 0)
				numeric = 1;
			if(strcmp(*argv, "-r") == 0)
				rev = 1;

			if(isdigit(*(*argv + 1)))
				fieldno = atoi(*argv + 1);

			argv++;
			argc--;
		}
	}

	if(fold && numeric) {
		puts("can't use \'-f\' with \'-n\'");
		return 1;
	}

	if(dir && numeric) {
		puts("can\'t use \'-d\' with \'-n\'");
		return 1;
	}

	char *lines[MAXLINES][MAXFIELDS];

	int nlines = readlines(MAXFIELDS, lines, MAXLINES);

	puts("Original lines:");

	writelines(MAXFIELDS, lines, nlines);

	int (*comp)(void*, void*);
	void (*Sort)(int, int, char* (*)[MAXFIELDS], int, int, int (*)(void*, void*));

	comp = numeric ? numcmp : strCmp;
	comp = fold ? ic_strCmp : comp;
	comp = dir ? strdircmp : comp;
	comp = dir && fold ? ic_strdircmp : comp;

	if(comp == strCmp)
		puts("strcmp");
	if(comp == strdircmp)
		puts("strdircmp");

	Sort = rev ? QsortR : Qsort;

	Sort(MAXFIELDS, fieldno - 1, lines, 0, nlines - 1, comp);

	puts("\nSorted lines:");

	writelines(MAXFIELDS, lines, nlines);

	return 0;
}
