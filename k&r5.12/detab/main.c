// NAIVE ARGUMENT HANDLING

#include<stdio.h>
#include<stdlib.h>

#include "def.h"

int main(int argc, char *argv[]) {

	if(argc == 1) {
		Help();
		return 1;
	}

	argc--;
	argv++;

	int colM = 0, tabstop = 0;

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

	char string[SIZE];

	_getline(string, SIZE);

	detab(string + colM, tabstop);

	return 0;
}
