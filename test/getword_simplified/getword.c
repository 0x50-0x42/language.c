#include<stdio.h>
#include<ctype.h>

// requirements
#define isscore(val) (val == '_' ? 1 : 0)
#define isquote(val) (val == '\'' || val == '\"' ? 1 : 0)
#define isdotexclamQ(val) (val == '.' || val == '!' || val == '?' ? 1 : 0)
#define isfslash(val) (val == '/' ? 1 : 0)

int getch();
void ungetch(int);

int getword(char *string, int maxchar) {
	/* ignore spaces, special symbols if delimited by spaces,
	   accept '.', '!'
	   comments (single/double) are one line, strings within ' or " are one line,
	   strings written in snake case convention are one line
	 */

	int c;

	while(isspace(c = getch())) // ignore whitespaces
		;

	// for comments
	if(isfslash(c)) {
		*string++ = c;
		c = getch();
		if(isfslash(c)) { // single-line comment
			*string++ = c;
			while((c = getch()) != '\n' && c != EOF)
				*string++ = c;
			if(c != EOF)
				ungetch(c);
		}

		else if(c == '*') { // multi-line comment
			*string++ = c;
			while((c = getch()) != EOF) {
				if(c == '*') {
					*string++ = c;
					if((c = getch()) == '/') { // end of multi-line comment
						*string++ = c;
						break;
					}
				}
				*string++ = c;
			}
		}

		else { // neither a single-line comment nor a multi-line comment
			while(isalnum(c = getch()) || isscore(c) || isdotexclamQ(c) || !isspace(c) && c != EOF)
				*string++ = c;
			if(c != EOF)
				ungetch(c);
		}
	}

	// for quoted strings
	else if(isquote(c)) {
		*string++ = c;
		c = getch();
		while(!isquote(c) && c != EOF) {
			*string++ = c;
			c = getch();
		}

		if(c != EOF)
			*string++ = c;
	}

	// for strings starting with underscore
	else if(isscore(c)) {
		*string++ = c;
		while(isalnum(c = getch()) || isscore(c) || isdotexclamQ(c) || !isspace(c) && c != EOF)
			*string++ = c;

		if(c != EOF)
			ungetch(c);
	}

	else if(isalnum(c)) { // either an alphabet or a number
		*string++ = c;
		while(isalnum(c = getch()) || isscore(c) || isdotexclamQ(c) || !isspace(c) && c != EOF)
			*string++ = c;

		if(c != EOF)
			ungetch(c);
	}

	*string = '\0';

	return c == EOF ? EOF : c;
}
