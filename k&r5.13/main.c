#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "def.h"

#define MAXLINES 5000

int main(int argc, char *argv[]) {

	if(argc == 1) {
		Help();
		return 1;
	}

	argc--;
	argv++;

	int n = 0;

	// naive argument handling
	while(argc > 0 && **argv == '-') {
		++*argv;
		if(isNum(*argv)) {
			n = atoi(*argv);
		}

		argc--;
		if(argc == 0)
			continue;
		argv++;
	}

	if(n == 0) // n was not provided in the argument
		n = 10; // set n to default value


	char *string[SIZE], str[SIZE];

	int lines = 0;
	unsigned len = 0;

	// take each line of input
	while((len = _getline(str, SIZE)) != 0 && lines < MAXLINES) {
		string[lines] = alloc(len);
		strcpy(string[lines], str);
		lines++;
	}

	puts("----------------------------------------------------------------------------");
	tail(string, lines, n);

	freeMem();

	return 0;
}
