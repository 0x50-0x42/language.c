// RUDIMENTARY ARGUMENT PARSING

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#include "def.h"

int main(int argc, char*argv[]) {

	if(argc == 1) {
		Help();
		return 1;
	}

	argc--;
	argv++; // moving to the next pointer

	int tabs = 0, help = 0, stin = 0;


	// handle the options(rudimentary)
	while(argc >= 1 && **argv == '-') {

		++*argv;

		while(**argv != '\0') {
			switch(**argv) {
				case 'h':
					if(help == 1 || tabs == 1) {
						puts("invalid option!");
						return 1;
					}

					Help();

				case 't':
					if(help == 1 || tabs == 1) {
						puts("invalid option!");
						return 1;
					}

					tabs = 1;

					break;

				default:
					Help();
			}

			if(help == 0 && tabs == 0)
				stin = 1;

			++*argv;
		}

		argv++; // move to the next pointer
		argc--;
	}

	// store the tabstops
	unsigned tabstops[100];
	unsigned *tbstp = tabstops;
	unsigned num = 0;

	if(tabs == 1) { // there are tabs

		while(argc > 0 && isdigit(**argv)) {

			while(**argv != '\0') {
				if(isdigit(**argv))
					num = num * 10 + (**argv) - '0';
				else {
					*tbstp++ = num;
					num = 0;
				}

				++*argv;
			}

			if(num)
				*tbstp++ = num;

			num = 0;
			argv++;
			argc--;
		}

		if(tbstp - tabstops == 0) {
			puts("\'-t\' requires arguments");
			return 1;
		}
	}


	char string[SIZE];

	if(argc == 1 && stin != 1)
		strcpy(string, *argv);

	else
		_getline(string, SIZE);

	detab(string, tabstops, tbstp - tabstops);
	
	return 0;
}
