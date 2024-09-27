#include<stdio.h>
#include<ctype.h>

int wc(char *text) {
	int words = 0;
	char *base = text;

	while(*text != '\0') {
		if(*text == ' ' || *text == '\n' || *text == '\t' && (text - base) != 0) {
			words++;
			while(isspace(*text)) // newlines also considered as whitespaces
				text++;
		}

		if(*text != '\0')
			text++;
	}

	if(*(text - 1) != '\n')
		words++;

	return words;
}
