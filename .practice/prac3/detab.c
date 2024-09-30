#include<stdio.h>

#define TABSTOP 8

/*
	Formula:

	number of spaces = TABSTOP * ((numberOfCharsCounted / TABSTOP) + 1) - numberOfCharsCounted
 */

void detab(char* string) {
	int count = 0;
	while(*string != '\0') {
		if(*string == '\t') {
			for(int i = 0; i < TABSTOP * (count / TABSTOP + 1) - count; i++)
				printf(" ");
			count += (TABSTOP * (count / TABSTOP + 1) - count);
		}

		else {
			printf("%c", *string);
			count++;
		}

		string++;
	}
}
