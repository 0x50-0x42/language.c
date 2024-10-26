#include<stdio.h>

#define __ENTAB__

#include "def.h"

#undef __ENTAB__


#define TAB '\t'

void entab(char* string, unsigned tabstop) {

	char *base = string;
	char *spaces = NULL; // allocate memory to it using your own version of malloc()
	unsigned idx = 0, alloced = 0;

	while(*string != '\0') {
		if(string - base == tabstop - 1) {
			if(*string == ' ') { // if *string is a space then
				if(strLen(spaces) == 0) { // if there are no previously stored spaces
					if(*(string + 1) == ' ') // check if the character next to *string is also a whitespace
						printf("%c", TAB); // if it is, then print a tab
					else
						printf("%c", *string); // otherwise print a single whitespace
				}

				else { // if there were previously stored spaces

					printf("%c", TAB);
					freeMem(&spaces); // free up spaces
					alloced = 0;
					idx = 0;
				}

				string++;

				base = string;

				continue;

			}


		}

		if(*string == ' ') {
			if(!alloced) { // check if spaces has been allocated memory
				spaces = alloc(1000);
				alloced = 1;
				idx = 0;
			}

			spaces[idx++] = *string; // don't print the spaces, instead, store them
		}

		else {
			if(strLen(spaces) > 0) { // if *string is a non-space character and the tabstop hasn't been fulfilled then
				while(idx > 0) // print the previously stored spaces
					printf("%c", spaces[--idx]);
				freeMem(&spaces);
				alloced = 0; // reset the flag
				idx = 0;
			}

			printf("%c", *string); // after that print the character

			if(string - base == tabstop - 1)
				base = string + 1;
		}

		string++;
	}
}
