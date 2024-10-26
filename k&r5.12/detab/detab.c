#include<stdio.h>

void detab(char *string, int tabstop) {
	int chars = 0;

	while(*string != '\0') {

		if(*string == '\t') {
			for(int i = 0; i < tabstop - chars; i++)
				printf(" ");
			chars = 0;
			string++;
		}

		if(chars == tabstop)
			chars = 0;

		printf("%c", *string);
		chars++;

		string++;
	}
}
