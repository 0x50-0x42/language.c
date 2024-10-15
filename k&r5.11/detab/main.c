// RUDIMENTARY ARGUMENT PARSING

#include<stdio.h>
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
	while(argc > 1 && **argv == '-') {
		++*argv;
		while(**argv != '\0') {
			switch(**argv) {
				case 'h':

					if(help == 1 || tabs == 1) {
						puts("invalid option");
						return 1;
					}

					help = 1;
					break;

				case 't':
					
					if(help == 1 || tabs == 1) {
						puts("invalid option");
						return 1;
					}

					tabs = 1;
					break;

				case '-':
					if(help == 1 || stin == 1) {
						Help();
					}

					stin = 1;
					break;

				default:
					Help();
			}

			++*argv;
		}

		argc--;
		argv++;
	}


	// store the tabstops
	
	return 0;
}
