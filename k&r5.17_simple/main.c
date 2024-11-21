#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

#include "def.h"

int main(int argc, char *argv[]) {
	if(argc > 1) {
		argc--;
		argv++;
	}

	int rev = 0, fold = 0, dir = 0, field = 1, numeric = 0;

	// naive argument handling
	while(argc >= 1) {
		if(strcmp(*argv, "-d") == 0)
			dir = 1;
		if(strcmp(*argv, "-n") == 0)
			numeric = 1;
		if(strcmp(*argv, "-r") == 0)
			rev = 1;
		if(strcmp(*argv, "-f") == 0)
			fold = 1;
		if(isdigit(*(*argv + 1)))
			field = atoi(*argv + 1);

		argv++;
		argc--;
	}

	if(fold &&  numeric) {
		puts("Can't use \'-f\' with \'-n\'");
		return 1;
	}

	if(dir && numeric) {
		puts("Can't use \'-d\' with \'-n\'");
		return 1;
	}

	int (*comp)(void*, void*);

	comp = numeric ? numcmp : _strcmp;
	comp = fold ? _icstrcmp : comp;
	comp = dir ? _strdircmp : comp;
	comp = fold && dir ? _icstrdircmp : comp;

	int nlines = 0, result = 0;
	char *strings[MAXLINES], string[MAXCHAR];

	while(result != EOF && nlines < MAXLINES) {
		result = readlines(string, MAXCHAR);
		if(result == EOF)
			break;
		strings[nlines] = alloc(result);
		strcpy(strings[nlines], string);
		nlines++;
	}

	void (*sort)(char**, int, int, int, int (*)(void*, void*));

	sort = rev ? _qsortR : _qsort;

	sort(strings, field, 0, nlines - 1, comp);

	// display the lines
	writelines(strings, nlines);

	return 0;
}
