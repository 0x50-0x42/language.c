/*
   KEY POINTS:

   ~ after every tab, reset counter to 0
   ~ leave the spaces as they are
   ~ only replace the tabs by (tabstops - no. of printed character) number of spaces.
 */


#include<stdio.h>

void detab(char *string, int *tabstops, int len) {

	unsigned idx = 0, chars = 0;

	while(*string != '\0') {

		if(*string == '\t') { // if tab, then
			for(int i = 0; i < tabstops[idx] - chars; i++) // replace it by appropriate number of spaces
				printf(" ");
			chars = 0; // reset counter to zero
			string++; // move to the next character

			if(len > 1) {
				idx++;
				for(int i = idx; i < len; i++)
					tabstops[i] -= tabstops[idx - 1];  // relative tabstops
			}
		}

		else {

			printf("%c", *string);
			chars++;
			string++;
		}
	}
}
