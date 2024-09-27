#include<stdio.h>
#include<ctype.h>

void printWord(char *text) {
	while(*text != '\0') {
		if(*text != ' ' && *text != '\t' && *text != '\n')
			printf("%c", *text++);
		else {
			while(isspace(*text))
				text++;
			printf("\n");
		}

	}
}
