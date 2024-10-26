// RUDIMENTARY (or rather NAIVE) ARGUMENT HANDLING

#include<stdio.h>
#include<stdlib.h>

#define __MAIN__

#include "def.h"

#undef __MAIN__

int main(int argc, char *argv[]) {

	if(argc == 1) {
		Help();
		return 1;
	}

	argc--;
	argv++;

	unsigned tabstop = 0;

	int colM = 0;


	char string[SIZE];

	// handle arguments
	while(argc > 0 && (**argv == '-' || **argv == '+')) {
		++*argv;

		if(isNum(*argv)) {
			if(*(*argv - 1) == '-') {
				colM = atoi(*argv);
			}

			if(*(*argv - 1) == '+') {
				tabstop = atoi(*argv);
			}
		}

		argc--;
		if(argc == 0)
			continue;
		argv++;
	}

	_getline(string, SIZE);

	if(tabstop = 0) // tabstop was not provided in the argument
		tabstop = 8; // set to default tabstop

	entab(string + colM, tabstop);

	return 0;
}
