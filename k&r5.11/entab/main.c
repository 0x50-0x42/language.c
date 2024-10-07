#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define DFLT_TBSTP 8   // the default tabstop

#include "def.h"

unsigned tabs = 0; // flag

int main(int argc, char *argv[]) {

	char **base = argv;

	if(argc == 1) {
		puts("Convert spaces to tabs");
		puts("entab [OPTION] tab1,[tab2, ...tabn] [text] [-]");
		return 1;
	}

	argv++;
	argc--;

	unsigned tabstops[100]; // array for storing tabstops
	unsigned *tbstp = tabstops;

	// handle the arguments
	handleArgs(&argc, &argv);

	int nums = 0;

	// store the tabstops
	if(tabs == 1) {
		while(argc != 0 && isdigit(**argv)) {
			while(**argv != '\0')  {
				if(isdigit(**argv))
					nums = nums * 10 + (**argv - '0');

				if(**argv == ' ' || **argv == ',') {
					*tbstp++ = nums;
					nums = 0;
				}

				if(**argv != ' ' && **argv != ',' && !isdigit(**argv)) {
					printf("Invalid option: %c\n", **argv);
					return 1;
				}

				(*argv)++;
			}

			if(nums)
				*tbstp++ = nums;
			nums = 0;
			argv++;
			argc--;
		}
	}

	int len = tbstp - tabstops; // length of the array

	// check if tabs are in ascending order
	if(sorted(tabstops, len) < 0) {
		puts("Tabs must be in ascending order!");
		return 1;
	}

	if(tbstp - tabstops == 0) { // no tabstop values were passed by the user
		if(tabs == 1) {
			puts("-t option requires an integer argument");
			return 1;
		}

		else {
			tabstops[0] = DFLT_TBSTP;  // default to 8 spaces
			len = 1;
		}
	}


	char string[SIZE];

	if(argc == 0 || **argv == '-') // if argc is zero, then take input from stdin
		_getline(string, SIZE);
	else
		strcpy(string, *argv);

	entab(string, tabstops, len);

	return 0;
}
