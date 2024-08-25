#include<stdio.h>

#define __NTAB__
#include "def.h"
#undef __NTAB__

void entab(char *s) {

	/* number of tabs required:
	   
	   no. of whitespaces / a tab = no. of required tabs
	   no. of whitespaces % a tab = no. of whitespaces

	 */

	while(*s) {
		if(*s == ' ') {
			if(*(s + 1) == ' ') {
				if(*(s + 2) == ' ') {
					printf("\t");
					s += 2;
				}

				else
					printf("%c", *s);
			}

			else {
				printf("%c", *s);
			}
		}

		else {
			printf("%c", *s);
		}

		s++;
	}

	printf("\n");
}
