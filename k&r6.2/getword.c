#include<stdio.h>
#include<ctype.h>

#define __GTWD__
#include "def.h"
#undef __GTWD__

int ishash(int val) {
	return val == '#' ? 1 : 0;
}

int isquote(int val) {
	return val == '\'' || val == '\"' ? 1 : 0;
}

int isdotexclamQ(int val) {
	return val == '!' || val == '.' || val == '?' ? 1 : 0;
}

int isfslash(int val) {
	return val == '/' ? 1 : 0;
}

int isscore(int val) {
	return val == '_' ? 1 : 0;
}

int getword(char*string, int maxchar) {
	int c;
	while(isspace(c = getch())) // ignore whitespaces
		;

	// if preprocessor
	if(ishash(c)) {
		*string++ = c;
		while((c = getch()) != '\n' && c != EOF)
			*string++ = c;
		ungetch(c);
	}

	// if comment
	else if(isfslash(c)) {
		*string++ = c;
		if(isfslash(c = getch())) { // single-line comment
			while((c = getch()) != '\n' && c != EOF) // ignore!
				;
			*--string = '\0';
		}

		else if(c == '*') { // multi-line comment
			while((c = getch()) != EOF) { // ignore!
				if(c == '*') {
					if(isfslash(c = getch())) // closing of multi-line comment
						break;
				}
			}
			*--string = '\0';
		}

		else { // neither single-line nor multi-line comment
			ungetch(c);
		}
	}

	// if string starting with a single or a double quote
	else if(isquote(c)) {
		while(!isquote(c = getch()) && c != EOF) // ignore!
			;
	}

	else if(isscore(c)) {
		*string++ = c;
		while(isalnum(c = getch()) || isscore(c))
			*string++ = c;
		ungetch(c);
	}

	else if(isalnum(c)){
		*string++ = c;
		while(isalnum(c = getch()) || isscore(c))
			*string++ = c;
		ungetch(c);
	}

	*string = '\0';
	return c == EOF ? EOF : c;
}
