#include<stdio.h>
#include<ctype.h>

int getch();
void ungetch(int);

int getword(char*string, int lim) {
	int c;

	char *w = string;

	while(isspace(c = getch())) // skip the whitespaces, tabs and newlines
		;

	if(c != EOF) // c is any alphabet, digit, or special character
		*w++ = c;

	if(!isalpha(c)) { // c is either a whitespace or digit or special character
		*w = '\0';
		return c;
	}

	for(; --lim > 0; w++) {
		if(!isalnum(*w = getch())) { // the character is either a blank or a special character
			ungetch(*w);
			break;
		}
	}

	*w = '\0';

	return string[0];
}
